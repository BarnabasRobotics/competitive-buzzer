int state;

int p1Light = 10;
int p2Light = 11;

int p1Button = 2;
int p2Button = 3;

int buzzerPin = 6;

void outOfTime() {
  tone(buzzerPin,1200);
  delay(500);
  noTone(buzzerPin);
}

void triggerMusic() {
  for (int i=0;i<4;i++) {
    tone(buzzerPin,1000);
    delay(50);
    noTone(buzzerPin);
    delay(50);
  }
  tone(buzzerPin,2000);
  delay(250);
  noTone(buzzerPin);  
}

void setup() {
  // put your setup code here, to run once:

  pinMode(p1Light,OUTPUT);
  pinMode(p2Light,OUTPUT);

  pinMode(p1Button, INPUT);
  pinMode(p2Button, INPUT);
  attachInterrupt(digitalPinToInterrupt(p1Button), blink1, FALLING);
  attachInterrupt(digitalPinToInterrupt(p2Button), blink2, FALLING);

  state = 0;
}

void blink1(){
  state = 1;
}

void blink2(){
  state = 2;
}

void buzzHelper(int pin) {
  for (int i = 0; i < 10;i++) {
      digitalWrite(pin,LOW);
      tone(buzzerPin,1000);
      delay(10);
      digitalWrite(pin,HIGH);
      noTone(buzzerPin);
      delay(10);
    }
  triggerMusic();
  for (int i = 0; i < 6;i++) {
      digitalWrite(pin,LOW);
      delay(100);
      digitalWrite(pin,HIGH);
      delay(750);
 } 
}

void loop() {
  // put your main code here, to run repeatedly:

  if (state==0) {
    
    digitalWrite(p2Light,LOW);
    digitalWrite(p1Light,LOW);
  }
  else if (state == 1) {
    buzzHelper(p1Light);
    outOfTime();
    state = 0;
  }
  else if (state == 2) {
    buzzHelper(p2Light);
    outOfTime();
    state = 0;
  }
  
}
