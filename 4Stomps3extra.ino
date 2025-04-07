#define pin1 2
#define pin2 4
#define pin3 6
#define pin4 8
#define pin5 10 
#define pin6 12 
#define pin7 13

#define led1 A5
#define led2 A4
#define led3 A3
#define led4 A2

void setup() {
  Serial.begin(38400);
  pinMode(pin1, INPUT_PULLUP);
  pinMode(pin2, INPUT_PULLUP);
  pinMode(pin3, INPUT_PULLUP);
  pinMode(pin4, INPUT_PULLUP);
  pinMode(pin5, INPUT_PULLUP);
  pinMode(pin6, INPUT_PULLUP);
  pinMode(pin7, INPUT_PULLUP);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  static bool oldState1 = false;
  bool state1 = !digitalRead(pin1);
  if (oldState1 != state1) {
    if (state1)CC1();
    while (!digitalRead(pin1));
    oldState1 = state1;
    delay(100);
  }

  static bool oldState2 = false;
  bool state2 = !digitalRead(pin2);
  if (oldState2 != state2) {
    if (state2)CC2();
    while (!digitalRead(pin2));
    oldState2 = state2;
    delay(100);
  }

  static bool oldState3 = false;
  bool state3 = !digitalRead(pin3);
  if (oldState3 != state3) {
    if (state3)CC3();
    while (!digitalRead(pin3));
    oldState3 = state3;
    delay(100);
  }

  static bool oldState4 = false;
  bool state4 = !digitalRead(pin4);
  if (oldState4 != state4) {
    if (state4)CC4();
    while (!digitalRead(pin4));
    oldState4 = state4;
    delay(100);
  }

  static bool oldState5 = false;
  bool state5 = !digitalRead(pin5);
  if (oldState5 != state5) {
    if (state5)CC5();
    while (!digitalRead(pin5));
    oldState5 = state5;
    delay(100);
  }

  static bool oldState6 = false;
  bool state6 = !digitalRead(pin6);
  if (oldState6 != state6) {
    if (state6)CC6();
    while (!digitalRead(pin6));
    oldState6 = state6;
    delay(100);
  }

  static bool oldState7 = false;
  bool state7 = !digitalRead(pin7);
  if (oldState7 != state7) {
    if (state7)CC7();
    while (!digitalRead(pin7));
    oldState7 = state7;
    delay(100);
  }
  delay(10);
}

void CC1() {
  byte tipo = 1; // first byte, pick one in range 0-127
  static bool V = false;

  if (V == true) {
    digitalWrite(led1, LOW);
  } else if (V == false) {
    digitalWrite(led1, HIGH);
  }
  
  Serial.write(0xB0); // CC 1 channel
  Serial.write(tipo);
  Serial.write(V ? 0x00 : 0x7f);
  Serial.flush();
  V = !V;
  delay(300);
}

void CC2() {
  byte tipo = 2; // first byte, pick one in range 0-127
  static bool V = false;

  if (V == true) {
    digitalWrite(led2, LOW);
  } else if (V == false) {
    digitalWrite(led2, HIGH);
  }

  Serial.write(0xB0); // CC 1 channel
  Serial.write(tipo);
  Serial.write(V ? 0x00 : 0x7f); //value. if each time should be same value than buy me a coffee
  Serial.flush();
  V = !V;
  delay(300);
}

void CC3() {
  byte tipo = 3; // first byte, pick one in range 0-127
  static bool V = false;
  
  if (V == true) {
    digitalWrite(led3, LOW);
  } else if (V == false) {
    digitalWrite(led3, HIGH);
  }

  Serial.write(0xB0); // CC 1 channel
  Serial.write(tipo); 
  Serial.write(V ? 0x00 : 0x7f); //value. if each time should be same value than buy me a coffee
  Serial.flush();
  V = !V;
  delay(300);
}

void CC4() {
  byte tipo = 4; // first byte, pick one in range 0-127
  static bool V = false;
  
  if (V == true) {
    digitalWrite(led4, LOW);
  } else if (V == false) {
    digitalWrite(led4, HIGH);
  }


  Serial.write(0xB0); // CC 1 channel
  Serial.write(tipo);
  Serial.write(V ? 0x00 : 0x7f); //value. if each time should be same value than buy me a coffee
  Serial.flush();
  V = !V;
  delay(300);
}

void CC5() {
  byte tipo = 5; // first byte, pick one in range 0-127

  Serial.write(0xB0); // CC 1 channel
  Serial.write(tipo);
  Serial.write(0x7f); //value. if each time should be same value than buy me a coffee
  Serial.flush();
  delay(100);
}

void CC6() {
  byte tipo = 6; // first byte, pick one in range 0-127

  Serial.write(0xB0); // CC 1 channel
  Serial.write(tipo);
  Serial.write(0x7f); //value. if each time should be same value than buy me a coffee
  Serial.flush();
  delay(100);
}

void CC7() {
  byte tipo = 7; // first byte, pick one in range 0-127

  Serial.write(0xB0); // CC 1 channel
  Serial.write(tipo);
  Serial.write(0x7f); //value. if each time should be same value than buy me a coffee
  Serial.flush();
  delay(100);
}
