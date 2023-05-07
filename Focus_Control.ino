#include <Stepper.h>

// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int rolePerMinute = 17;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

bool locked = true;

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {

  //Implement locked turning with joystick switch
  if (digitalRead(SW_pin)==0){
    locked= !locked;
    if (!locked)
      Serial.print("Desbloqueo \n");    
    else
      Serial.print("Bloqueo \n");
      
  }

  //Turn motor if not locked
  if (locked==false){
    //Serial.print("\n");
    //Serial.print("X-axis: ");
    //Serial.print(analogRead(X_pin));

    int motorSpeed = map(analogRead(X_pin), 512, 1023, 0, rolePerMinute);

    Serial.print("Motor speed: ");
    Serial.print(motorSpeed);
    Serial.print("\n");

    if (motorSpeed > 0) {
      myStepper.setSpeed(motorSpeed);
      myStepper.step(stepsPerRevolution/100);
    }
    else if (motorSpeed <0){
      myStepper.setSpeed(-1*motorSpeed);
      myStepper.step(-1*stepsPerRevolution/100);
    }
    // step 1/100 of a revolution:



    //Serial.print("\n");
    //Serial.print("Y-axis: ");
    //Serial.println(analogRead(Y_pin));
    //Serial.print("\n");
 }
  //delay(250);

}
