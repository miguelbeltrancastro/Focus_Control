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
  locked = digitalRead(SW_pin);
  if (!locked){
    Serial.print("\n");
    Serial.print("X-axis: ");
    Serial.print(analogRead(X_pin));
    Serial.print("\n");
    Serial.print("Y-axis: ");
    Serial.println(analogRead(Y_pin));
    Serial.print("\n\n");
  }
  delay(500);
}
