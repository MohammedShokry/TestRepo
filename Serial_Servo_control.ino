#include"Servo.h"

#define TRUE 1
#define FALSE 0
#define SERVO_PIN 2
#define ASCII_ZERO 0x30
#define ASCII_NINE 0x39
#define MIN_ANGLE 0
#define MAX_ANGLE 180

Servo Finger;
char received_char;
int angle = MIN_ANGLE;
int flag= FALSE;

void setup() {
        Finger.attach(SERVO_PIN);      
        Serial.begin(9600);
}

void loop() {

        while (Serial.available() > 0) {
                received_char = Serial.read();
                if(received_char >= ASCII_ZERO && received_char <= ASCII_NINE){ 
                  angle = angle *10 + (received_char - ASCII_ZERO);
                }
                delay(20);
                flag= TRUE;
        }
        
        if ( (angle >= MIN_ANGLE) && (angle <= MAX_ANGLE) && (flag == TRUE)){
            Finger.write(angle);
            Serial.print("I am Setting an angle: ");
            Serial.print(angle);
            Serial.print("\n");
            angle= MIN_ANGLE;
            flag= FALSE;
            delay(500);
          }
}
