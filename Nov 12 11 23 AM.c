


//  Libraries
#include "Arduino.h"
#include "Keypad.h"
#include <DFRobot_HX711.h>

// Pin
Servo myservo1; 
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;

int pin_servo1 = 9;
int pin_servo2 = 10;
int pin_servo3 = 11;
int pin_servo4 = 12;
int pin_servo5 = 13;

int pos_ref=90;
int turn_right=0;
int turn_left=180;



const riles= ["Riles",'696969',1000]

const byte ROWS = 4; 
const byte COLS = 3; 
byte rowPins[ROWS] = {5, 6, 7, 8}; 
byte colPins[COLS] = {2, 3, 4}; 

#define Balance_1_SCK A3;
#define Balance_1_D_OUT A2


// VARIABLE DU PROGRAMME
//Tableau pour customiser le keypad
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

// Initialisation des differents objet


Keypad keypad_VRAKO = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
DFRobot_HX711 Balance_Vrako_1= DFRobot_HX711(A2, A3);
#define calibration_factor 2280 


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;
 String menu(){

    Serial.println(F("\nQuel distributeur souhaite tu tester?"));
    Serial.println(F("(1) Avoine"));
    Serial.println(F("(2) Amande"));
    Serial.println(F("(3) Poichiche"));
    Serial.println(F("(4) Riz"));
    Serial.println(F("(5) Lentille"));
    
  
	}
    

  


// Mettre en place le circuit,  il s'initialise à chaque fois que le circuit est allumé
void setup() 
{     
  Balance_Vrako_1.setCalibration(1992.f);
  // Setup Serial
  // On utilise la console pour afficher les messages 
  Serial.begin(9600);
  while (!Serial) ; // attendre que Serial soit connecter. USB needed

  menu();
  
  // Setup des servomoteurs
  pinMode(pin_servo1, INPUT);
  pinMode(pin_servo2, INPUT);
  pinMode(pin_servo3, INPUT);
  pinMode(pin_servo4, INPUT);
  pinMode(pin_servo5, INPUT);
   
  myservo1.attach(pin_servo1);
  myservo2.attach(pin_servo2);
  myservo3.attach(pin_servo3);
  myservo4.attach(pin_servo4);
  myservo5.attach(pin_servo5);
  
  myservo1.write(pos_ref);
  myservo2.write(pos_ref);
  myservo3.write(pos_ref);
  myservo4.write(pos_ref);
  myservo5.write(pos_ref);
  
  	
  
  
}

 
// La fonction principal du circuit, elle run en boucle et definie les interactions entre les differents codes.
void loop() {
  A;
  // Le mot de passe
	char key = keypad_VRAKO.getKey();
  if (isDigit(key)){
       Serial.println(key);
    switch(key)
    	{
      case '1' : 
        Serial.println("Vous avez choisi le silo 1, etes-vous sur ?");
        keypad_VRAKO.waitkey();
        
        if (keypad_VRAKO.isPressed('#')) {
          myservo1.write(turn_right);
        }
        else (keypad_VRAKO.isPressed('*')) {
          goto A; 
        }
        
        while (key=='1'){
        	Serial.print(Balance_Vrako_1.readWeight()*(-1), 3);
          Serial.println(" g");
          Serial.print("Prix: ");
          Serial.println(Balance_Vrako_1.readWeight()*(-1.5), 3);
          Serial.println("Appuyez sur # pour arreter la mesure");  
          delay(200);
            if(keypad_VRAKO.getKey()=='#'){

              // Activer le servo moteur pour bloquer
             
            	key = '#';
            	myservo1.write(pos_ref);
            	Serial.println("Transaction");
            }
        }
        break;
      case '2' :
        Serial.println("Vous avez choisi le silo 2, etes-vous sur ?");
        keypad_VRAKO.waitkey();
        
        if (keypad_VRAKO.isPressed('#')) {
          myservo1.write(turn_left);
        }
        else (keypad_VRAKO.isPressed('*')) {
          goto A; 
        }
        
        while (key=='2'){
        	Serial.print(Balance_Vrako_1.readWeight()*(-1), 3);
          Serial.println(" g");
          Serial.print("Prix: ");
          Serial.println(Balance_Vrako_1.readWeight()*(-1.5), 3);
          Serial.println("Appuyez sur # pour arreter la mesure");  
          delay(200);
            if(keypad_VRAKO.getKey()=='#'){

              // Activer le servo moteur pour bloquer
             
            	key = '#';
            	myservo1.write(pos_ref);
            	Serial.println("Transaction");
            }
        }
        break;
      case '3' :
                Serial.println("Vous avez choisi le silo 3, etes-vous sur ?");
        keypad_VRAKO.waitkey();
        
        if (keypad_VRAKO.isPressed('#')) {
          myservo1.write(turn_right);
        }
        else (keypad_VRAKO.isPressed('*')) {
          goto A; 
        }
        
        while (key=='3'){
        	Serial.print(Balance_Vrako_1.readWeight()*(-1), 3);
          Serial.println(" g");
          Serial.print("Prix: ");
          Serial.println(Balance_Vrako_1.readWeight()*(-1.5), 3);
          Serial.println("Appuyez sur # pour arreter la mesure");  
          delay(200);
            if(keypad_VRAKO.getKey()=='#'){

              // Activer le servo moteur pour bloquer
             
            	key = '#';
            	myservo1.write(pos_ref);
            	Serial.println("Transaction");
            }
        }
        break;
      case '4' : 
                Serial.println("Vous avez choisi le silo 4, etes-vous sur ?");
        keypad_VRAKO.waitkey();
        
        if (keypad_VRAKO.isPressed('#')) {
          myservo1.write(turn_left);
        }
        else (keypad_VRAKO.isPressed('*')) {
          goto A; 
        }
        
        while (key=='4'){
        	Serial.print(Balance_Vrako_1.readWeight()*(-1), 3);
          Serial.println(" g");
          Serial.print("Prix: ");
          Serial.println(Balance_Vrako_1.readWeight()*(-1.5), 3);
          Serial.println("Appuyez sur # pour arreter la mesure");  
          delay(200);
            if(keypad_VRAKO.getKey()=='#'){

              // Activer le servo moteur pour bloquer
             
            	key = '#';
            	myservo1.write(pos_ref);
            	Serial.println("Transaction");
            }
        }
        break;
      case '5' : 
                Serial.println("Vous avez choisi le silo 5, etes-vous sur ?");
        keypad_VRAKO.waitkey();
        
        if (keypad_VRAKO.isPressed('#')) {
          myservo1.write(turn_right);
        }
        else (keypad_VRAKO.isPressed('*')) {
          goto A; 
        }
        
        while (key=='5'){
        	Serial.print(Balance_Vrako_1.readWeight()*(-1), 3);
          Serial.println(" g");
          Serial.print("Prix: ");
          Serial.println(Balance_Vrako_1.readWeight()*(-1.5), 3);
          Serial.println("Appuyez sur # pour arreter la mesure");  
          delay(200);
            if(keypad_VRAKO.getKey()=='#'){

              // Activer le servo moteur pour bloquer
             
            	key = '#';
            	myservo1.write(pos_ref);
            	Serial.println("Transaction");
            }
        }
        break;
      case '6' : 
                Serial.println("Vous avez choisi le silo 6, etes-vous sur ?");
        keypad_VRAKO.waitkey();
        
        if (keypad_VRAKO.isPressed('#')) {
          myservo1.write(turn_left);
        }
        else (keypad_VRAKO.isPressed('*')) {
          goto A; 
        }
        
        while (key=='6'){
        	Serial.print(Balance_Vrako_1.readWeight()*(-1), 3);
          Serial.println(" g");
          Serial.print("Prix: ");
          Serial.println(Balance_Vrako_1.readWeight()*(-1.5), 3);
          Serial.println("Appuyez sur # pour arreter la mesure");  
          delay(200);
            if(keypad_VRAKO.getKey()=='#'){

              // Activer le servo moteur pour bloquer
             
            	key = '#';
            	myservo1.write(pos_ref);
            	Serial.println("Transaction");
            }
        }
        break;
      case '7' : 
                Serial.println("Vous avez choisi le silo 7, etes-vous sur ?");
        keypad_VRAKO.waitkey();
        
        if (keypad_VRAKO.isPressed('#')) {
          myservo1.write(turn_right);
        }
        else (keypad_VRAKO.isPressed('*')) {
          goto A; 
        }
        
        while (key=='7'){
        	Serial.print(Balance_Vrako_1.readWeight()*(-1), 3);
          Serial.println(" g");
          Serial.print("Prix: ");
          Serial.println(Balance_Vrako_1.readWeight()*(-1.5), 3);
          Serial.println("Appuyez sur # pour arreter la mesure");  
          delay(200);
            if(keypad_VRAKO.getKey()=='#'){

              // Activer le servo moteur pour bloquer
             
            	key = '#';
            	myservo1.write(pos_ref);
            	Serial.println("Transaction");
            }
        }
        break;
      case '8' : 
                Serial.println("Vous avez choisi le silo 8, etes-vous sur ?");
        keypad_VRAKO.waitkey();
        
        if (keypad_VRAKO.isPressed('#')) {
          myservo1.write(turn_left);
        }
        else (keypad_VRAKO.isPressed('*')) {
          goto A; 
        }
        
        while (key=='8'){
        	Serial.print(Balance_Vrako_1.readWeight()*(-1), 3);
          Serial.println(" g");
          Serial.print("Prix: ");
          Serial.println(Balance_Vrako_1.readWeight()*(-1.5), 3);
          Serial.println("Appuyez sur # pour arreter la mesure");  
          delay(200);
            if(keypad_VRAKO.getKey()=='#'){

              // Activer le servo moteur pour bloquer
             
            	key = '#';
            	myservo1.write(pos_ref);
            	Serial.println("Transaction");
            }
        }
        break;
      case '9' : 
                Serial.println("Vous avez choisi le silo 9, etes-vous sur ?");
        keypad_VRAKO.waitkey();
        
        if (keypad_VRAKO.isPressed('#')) {
          myservo1.write(turn_right);
        }
        else (keypad_VRAKO.isPressed('*')) {
          goto A; 
        }
        
        while (key=='9'){
        	Serial.print(Balance_Vrako_1.readWeight()*(-1), 3);
          Serial.println(" g");
          Serial.print("Prix: ");
          Serial.println(Balance_Vrako_1.readWeight()*(-1.5), 3);
          Serial.println("Appuyez sur # pour arreter la mesure");  
          delay(200);
            if(keypad_VRAKO.getKey()=='#'){

              // Activer le servo moteur pour bloquer
             
            	key = '#';
            	myservo1.write(pos_ref);
            	Serial.println("Transaction");
            }
        }
        break;
      case '10' : 
                Serial.println("Vous avez choisi le silo 10, etes-vous sur ?");
        keypad_VRAKO.waitkey();
        
        if (keypad_VRAKO.isPressed('#')) {
          myservo1.write(turn_left);
        }
        else (keypad_VRAKO.isPressed('*')) {
          goto A; 
        }
        
        while (key=='10'){
        	Serial.print(Balance_Vrako_1.readWeight()*(-1), 3);
          Serial.println(" g");
          Serial.print("Prix: ");
          Serial.println(Balance_Vrako_1.readWeight()*(-1.5), 3);
          Serial.println("Appuyez sur # pour arreter la mesure");  
          delay(200);
            if(keypad_VRAKO.getKey()=='#'){

              // Activer le servo moteur pour bloquer
             
            	key = '#';
            	myservo1.write(pos_ref);
            	Serial.println("Transaction");
            }
        }
        break;
      default : Serial.println("Erreur de numéro de silo")

        
              Serial.println("Ecrivez le numero de votre code");
              delay(60000);}
          
          }

        }
      }
      
    }  
    


    