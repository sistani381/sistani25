int enA = 9;
int in1 = 8;
int in2 = 7;
const int SW_pin = 10;
const int X_pin = 0;
const int Y_pin = 1;
void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);// put your setup code here, to run once:

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void loop() {
  int pinx = analogRead(X_pin);
  int piny = analogRead(Y_pin);
  Serial.print("Xpin: ");
  Serial.print(pinx);
  Serial.print("    Ypin: ");
  Serial.println(piny);
  //  analogWrite(enA, 255);
  if (piny > 1000 && pinx > 500 && pinx < 530) {
//    digitalWrite(enA, HIGH);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delay(20);
  }
  else if (piny < 30  && pinx > 500 && pinx < 530) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(20);
  }
  else if (pinx > 1000 && piny > 500 && piny < 530) {
    for (int i = 0; i < 256; i++) {
      analogWrite(enA, i);
      delay(20);
    }
//    digitalWrite(in1, LOW);
//    digitalWrite(in2, HIGH);
//    delay(20);
  }
  else if (pinx < 30 && piny > 500 && piny < 530) {
    for (int i = 255; i >= 0; --i) {
      analogWrite(enA, i);
      
      
  //  digitalWrite(in1, LOW);
  //digitalWrite(in2, LOW);
  // delay(20);
    }

//    digitalWrite(in1, LOW);
//    digitalWrite(in2, LOW);
//    delay(20);
  }

}
