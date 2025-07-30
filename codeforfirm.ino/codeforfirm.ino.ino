int SW1 = D1;
int SW2 = D2;
int SW3 = D3;
int SW4 = D4;
const int swPins[]={SW1,SW2,SW3,SW4};
int BUZ = D5;
int LED1 = D7;
int LED2 = D8;
int LED3 = D9;
int LED4 = D10;
const int ledPins[]={LED1,LED2,LED3,LED4};
int butSeq[20];
bool butPressMatch=true;
bool butStat=false;
bool seqStatus=false;
long startTime = millis();
long onCallsec = 0;
int inc;

void setup() {
  for(int i=0; i<4;i++){//PinModing the SWitched
    pinMode(swPins[i],INPUT_PULLUP);
  }
pinMode(BUZ,OUTPUT); //Buuz Buzz Bad Boi

for(int i=0;i<0;i++){ //PinModing the LED LAdies
  pinMode(ledPins[i],OUTPUT);
}


}

void loop() { // Main Loop Function of firmware
 randomSeed(analogRead(A0));
 long onCallsec;
 if (digitalRead(SW1)== LOW && digitalRead(SW4) == LOW){
    if(!butStat){
    onCallsec=millis();
    butStat=true;
    }
    else if(millis()-onCallsec > 5000){
      onCallsec=0;
      gameStart();
      butStat=false;
    }
    else{
      butStat=false;
    }
  }
  
  delay(500);
}

void gameStart(){
getrandobutseq();
playbutSeq();
if(!checkSequence()){
  inc = 0;
  digitalWrite(BUZ,HIGH);
  delay(5000);
  digitalWrite(BUZ,LOW);
  for (int i=1;i<0;i++){
  digitalWrite(ledPins[i],HIGH);
  }
}

}

bool checkSequence() {//This Function checks if the button pressed is in the right order
  bool match = true;

  for (int i = 0; i < 4+inc; i++) {
    int pressed = waitForButton();  //Gets the value of the pressed button

    if (pressed != butSeq[i]) {
      match = false;
      break; 
    }
  }
  inc=inc+1;
  return match;
}

int waitForButton() {//THis Function checks if a switch is pressed and returns the pressed buttons value
  unsigned long waitTimebut=millis();
  while (millis() - waitTimebut > 1000) {
    for (int i = 0; i < 4+inc; i++) {
      if (digitalRead(swPins[i]) == LOW) {
        digitalWrite(BUZ,HIGH);
        delay(200);
        digitalWrite(BUZ,LOW);
        delay(200);  
        while (digitalRead(swPins[i]) == LOW); //waits for switch release
        return i + 1;  // return 1-based switch number
      }
    }
  }
  return 0;
}

void playbutSeq(){ //This thing lights up the LED's in random order
  for(int i=0; i<4+inc; i++){
    switch (butSeq[i]){
      case 1:
      digitalWrite(LED1,HIGH);
      digitalWrite(BUZ,HIGH);
      delayMicroseconds(200);
      digitalWrite(BUZ,HIGH);
      digitalWrite(LED1,LOW);
      break;
      
      case 2:
      digitalWrite(LED1,HIGH);
      digitalWrite(BUZ,HIGH);
      delayMicroseconds(200);
      digitalWrite(BUZ,HIGH);
      digitalWrite(LED1,LOW);
      break;

      case 3:
      digitalWrite(LED1,HIGH);
      digitalWrite(BUZ,HIGH);
      delayMicroseconds(200);
      digitalWrite(BUZ,HIGH);
      digitalWrite(LED1,LOW);
      break;

      case 4:
      digitalWrite(LED1,HIGH);
      digitalWrite(BUZ,HIGH);
      delayMicroseconds(200);
      digitalWrite(BUZ,HIGH);
      digitalWrite(LED1,LOW);
      break;
    }
  }
}

void getrandobutseq() { //Gives me 4 numbers from 1 to 4 completely random and can have repition
for (int i = 0; i < 4+inc; i++) {
    butSeq[i] = random(1, 5);  
  }
}

