#define comAnode1 2
#define comAnode2 3
#define pin1 4
#define pin2 5
#define pin3 6
#define pin4 7
#define pin5 8
#define pin6 9
#define pin7 10

void digit1(){
  //DISPLAY DIGIT 1
  digitalWrite(comAnode1, HIGH);
  digitalWrite(pin4, LOW);
  digitalWrite(pin7, LOW);
  
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin5, HIGH);
  digitalWrite(pin6, HIGH);
  
}

void digit2(){
  digitalWrite(comAnode1, HIGH);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin1, LOW);
  digitalWrite(pin6, LOW);
  digitalWrite(pin5, LOW);
  
  digitalWrite(pin7, HIGH);
  digitalWrite(pin2, HIGH);
  
}


void digit3(){
  digitalWrite(comAnode1, HIGH);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin1, LOW);
  digitalWrite(pin5, LOW);
  digitalWrite(pin7, LOW);
  
  digitalWrite(pin2, HIGH);
  digitalWrite(pin6, HIGH);
  
}

void digit4(){
  digitalWrite(comAnode1, HIGH);
  digitalWrite(pin2, LOW);
  digitalWrite(pin1, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin7, LOW);
  
  digitalWrite(pin3, HIGH);
  digitalWrite(pin5, HIGH);
  digitalWrite(pin6, HIGH);
  
}


void digit5(){
  digitalWrite(comAnode1, HIGH);
  digitalWrite(pin3, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin1, LOW);
  digitalWrite(pin7, LOW);
  digitalWrite(pin5, LOW);
  
  digitalWrite(pin4, HIGH);
  digitalWrite(pin6, HIGH);
  
}

void digit6(){
  digitalWrite(comAnode1, HIGH);
  digitalWrite(pin3, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin1, LOW);
  digitalWrite(pin7, LOW);
  digitalWrite(pin5, LOW);
  digitalWrite(pin6, LOW);
  
  digitalWrite(pin4, HIGH);
  
}

void digit7(){
  digitalWrite(comAnode1, HIGH);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin7, LOW);
  
  digitalWrite(pin1, HIGH);
  digitalWrite(pin6, HIGH);
  digitalWrite(pin5, HIGH);
  
}

void digit8(){
  digitalWrite(comAnode1, HIGH);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin7, LOW);
  digitalWrite(pin1, LOW);
  digitalWrite(pin6, LOW);
  digitalWrite(pin5, LOW);
  
}


void digit9(){
  digitalWrite(comAnode1, HIGH);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin7, LOW);
  digitalWrite(pin1, LOW);
  digitalWrite(pin5, LOW);
  
  digitalWrite(pin6, HIGH);

  
}


void setup() {
  // put your setup code here, to run once:
  pinMode(comAnode1, OUTPUT);
  int i = 4;
  for(i; i < 11; i++){
    pinMode(i, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  digit1();
  delay(1000);
  digit2();
  delay(1000);
  digit3();
  delay(1000);
  digit4();
  delay(1000);
  digit5();
  delay(1000);
  digit6();
  delay(1000);
  digit7();
  delay(1000);
  digit8();
  delay(1000);
  digit9();
  delay(1000);
  digitalWrite(comAnode1, LOW);
  delay(1000);

}
