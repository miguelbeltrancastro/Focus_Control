// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

bool locked = true;

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(SW_pin)==0){
    locked= !locked;
    if (!locked)
      Serial.print("Desbloqueo \n");    
    else
      Serial.print("Bloqueo \n");
      
  }
  if (locked==false){
    Serial.print("X-axis: ");
    Serial.print(analogRead(X_pin));
    Serial.print("\n");
    Serial.print("Y-axis: ");
    Serial.println(analogRead(Y_pin));
    Serial.print("\n");
 }
  delay(250);
}
