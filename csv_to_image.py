# -*- coding: utf-8 -*-
"""
Created on Mon Dec  7 20:45:42 2020

@author: Corentin Herman
"""

import csv
import numpy as np
import cv2
import scipy.integrate as sp
import matplotlib.pyplot as plt

def getQuaternionsAndAccelerations(fichier):
    f = open(fichier)    
    accelerations=[]
    quaternions=[]
    coordonnees=csv.reader(f)
    for ligne in coordonnees :
        x=int(float(ligne[0]))
        y=int(float(ligne[1]))
        z=int(float(ligne[2]))
        accelerations.append([x,y,z])
        q0=(float(ligne[3]))
        q1=(float(ligne[4]))
        q2=(float(ligne[5]))
        q3=(float(ligne[6]))
        quaternions.append([q0,q1,q2,q3])
    return accelerations,quaternions



def createPassageMatrix(quaternion):
    '''Prend un quaternion de la forme d'une liste [q0, q1, q2, q3] ou d'un tupple (q0,q1,q2,q3) et retourne la Matrice de passage T telle que ACCrefFeuille = T * ACCrefStylo'''
    q0 = quaternion[0]
    q1 = quaternion[1]
    q2 = quaternion[2]
    q3 = quaternion[3]
    T = np.zeros((3,3)) #initialise la matrice 3x3
    T[0][0] = q0**2 + q1**2 - q2**2 - q3**2
    T[0][1] = 2*(q1*q2 - q0*q3)
    T[0][2] = 2*(q1*q3 + q0*q2)
    T[1][0] = 2*(q1*q2 + q0*q3)
    T[1][1] = q0**2 - q1**2 + q2**2 - q3**2
    T[1][2] = 2*(q2*q3 - q0*q1)
    T[2][0] = 2*(q1*q3 - q0*q2)
    T[2][1] = 2*(q2*q3 + q0*q1)
    T[2][2] = q0**2 - q1**2 - q2**2 + q3**2
    return T

def accurateAccelerationVector(Matrix_T, Acc_R_pen):
    '''Prend la matrice de passage 3x3 associée et le vecteur 3x1 comportant les accélérations dans le ref du stylo et retourne le vecteur 3x1 comportant l'accélération dans le ref de la feuille, en compensant l'accélération gravitationnelle'''
    Acc_R_feuille = np.dot(Matrix_T, Acc_R_pen)
    G = np.array([0,0,1])
    Acc = Acc_R_feuille - G
    return Acc

def getAcceleration(Acc_R_pen, quaternion):
    '''Retourne l'accélération compensée dans le référentiel de la feuille'''
    T = createPassageMatrix(quaternion)
    A = accurateAccelerationVector(T, Acc_R_pen)
    return A


def gatherAcceleration(accelerations,quaternions):
    Aref=[]
    for i in range(0,len(quaternions)):
        T=createPassageMatrix(quaternions[i])
        Acc=accurateAccelerationVector(T,accelerations[i])
        A=getAcceleration(Acc,quaternions[i])
        Aref.append(list(A))
    return(Aref)
    


#Calcul de primitive avec la méthode des trapèzes

def f_Primitive(Temps,Liste):
    Taille = len(Temps)
    Sol = [0]
    for i in range(Taille - 1):
        dT = Temps[i+1] - Temps[i]
        Moy = (Liste[i] + Liste[i+1])/2
        Int_Loc = Moy * dT
        Int_Dt = Sol[i] + Int_Loc
        Sol.append(Int_Dt)
    return Sol        

#On intègre deux fois l'accéleration pour avoir la position

def accel_to_position(accelerations):
    Ax=[]
    Ay=[]
    Az=[]
    temps=[]
    for i in range(0,len(accelerations)):
        Ax.append(int(float(accelerations[i][0])))
        Ay.append(int(float(accelerations[i][1])))
        Az.append(int(float(accelerations[i][2])))
        temps.append(0.01*i)
    
        
    Vx=f_Primitive(temps,Ax)
    Vy=f_Primitive(temps,Ay)
    Vz=f_Primitive(temps,Az)
    
    x=f_Primitive(temps,Vx)
    y=f_Primitive(temps,Vy)
    z=f_Primitive(temps,Vz)
    
    
    positions=[]
    for i in range(0,len(x)):
        positions.append([y[i],z[i]])
    return(positions)
    

    
def enlever_z(positions):
    liste_coordonnees=[]
    for i in range (0,len(positions)):
        liste_coordonnees.append([positions[i][0],positions[i][1]])
    return liste_coordonnees
        


def coord_to_image(liste_coordonnees) :
    #On cherche la taille de l'image
    listeX=[]
    listeY=[]
    for i in range(0,len(liste_coordonnees)):
        listeX.append(int(liste_coordonnees[i][0]))
        listeY.append(int((liste_coordonnees[i][1])))
    maximumX=max(listeX)
    maximumY=max(listeY)
    tailleAbscisse = int(maximumY) + 20
    tailleOrdonnee = int(maximumX) + 20
    
    #On cree la matrice de 0 et de 1 (0 pour les pixels noirs et 1 pour les pixels blancs)
    
    trace=np.zeros((tailleAbscisse,tailleOrdonnee))
    for i in range(0,len(listeX)):
        trace[listeY[i] +10 ,listeX[i]+10]=1
    
    for i in range(0,tailleAbscisse) :
        for j in range (0,tailleOrdonnee) :
            if (trace[i,j]==0) :
                trace[i,j]=1 
            else :
                trace[i,j]=0
    
    print(trace)
    
    #On trace l'image à partir de la matrice
    
    cv2.imwrite("imageFinale.png",trace*255)
    
def main(fichier):
    accelerations=getQuaternionsAndAccelerations(fichier)[0]
    quaternions=getQuaternionsAndAccelerations(fichier)[1]
    Aref=gatherAcceleration(accelerations,quaternions)
    positions=accel_to_position(Aref)
    return coord_to_image(positions)
