import numpy as np
import math

##A CREER : fonction qui enregistre sous fichier .txt les résultats de fusion du script arduino
def saveAsTxt():
    pass

##A CREER : fonction qui récupère le quaternion et son accélération associée d'un fichier .txt
def getQuaternionsAndAccelerations():
    pass


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
    G = np.array([[0],[0],[1]])
    Acc = Acc_R_feuille - G
    return Acc

def getAcceleration(Acc_R_pen, quaternion):
    '''Retourne l'accélération compensée dans le référentiel de la feuille'''
    T = createPassageMatrix(quaternion)
    A = accurateAccelerationVector(T, Acc_R_pen)
    return A

##A CREER : fonction qui boucle sur l'ensemble des couples quaternions/Accélérations obtenus pour un tracé et leur applique getAcceleration
def gatherAcceleration():
    pass