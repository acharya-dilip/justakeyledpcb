int SW1 = D1;
int SW2 = D2;
int SW3 = D3;
int SW4 = D4;
int BUZ = D5;
int LED1 = D7;
int LED2 = D8;
int LED3 = D9;
int LED4 = D10;
int butSeq[4];
void setup() {
pinmode(SW1,INPUT_PULLUP);
pinmode(SW2,INPUT_PULLUP);
pinmode(SW3,INPUT_PULLUP);
pinmode(SW4,INPUT_PULLUP);
pinmode(BUZ,OUTPUT); //Buuz Buzz Bad Boi
pinmode(LED1,Output); //The LED Ladies
pinmode(LED2,Output);
pinmode(LED3,Output);
pinmode(LED4,Output);
unsigned int delay=200;
bool butPressMatch=true;
bool butStat=false;
bool seqStatus=false;
long startTime = millis();

}

void loop() {
 randomSeed(analogRead(A0));
 long onCallsec;
 if (digitalRead(SW1)== LOW && digitalRead(SW4) == LOW){
    if(!butStat){
    onCallsec=millis();
    butStat=true;
    }
     elseif(millis()-onCallsec > 5000){
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
if(!checksequence()){
  digitalWrite(BUZ,HIGH);
  delay(5000);
  digitalWrite(BUZ,LOW);
}

}

bool checkSequence() {//This Function checks if the button pressed is in the right order
  bool match = true;

  for (int i = 0; i < 4; i++) {
    int pressed = waitForButton();  //Gets the value of the pressed button

    Serial.print("Pressed: ");
    Serial.print(pressed);
    Serial.print(" Expected: ");
    Serial.println(pattern[i]);

    if (pressed != butSeq[i]) {
      match = false;
      break;  // Wrong input — exit early
    }
  }

  return match;
}

int waitForButton() {//THis Function checks if a button is pressed and returns the pressed buttons value
  unsigned long waitTimebut=millis();
  while (millis() - startTime < 1000) {
    for (int i = 0; i < 4; i++) {
      if (digitalRead(swPins[i]) == LOW) {
        digitalWrite(BUZ,HIGHT);
        delay(delay);
        digitalWrite(BUZ,LOW);
        delay(200);  // debounce
        while (digitalRead(swPins[i]) == LOW);  // wait for release
        return i + 1;  // return 1-based button number
      }
    }
  }
  return 0;
}

void playbutSeq(){ //This thing lights up the buttons in random order
  for(int i=0; i<4; i++){
    switch (butSeq[i]){
      case 1:
      digitalWrite(LED1,HIGH);
      digitalWrite(BUZ,HIGH);
      delayMicroseconds(delay);
      digitalWrite(BUZ,HIGH);
      digitalWrite(LED1,LOW);
      break;
      
      case 2:
      digitalWrite(LED1,HIGH);
      digitalWrite(BUZ,HIGH);
      delayMicroseconds(delay);
      digitalWrite(BUZ,HIGH);
      digitalWrite(LED1,LOW);
      break;

      case 3:
      digitalWrite(LED1,HIGH);
      digitalWrite(BUZ,HIGH);
      delayMicroseconds(delay);
      digitalWrite(BUZ,HIGH);
      digitalWrite(LED1,LOW);
      break;

      case 4:
      digitalWrite(LED1,HIGH);
      digitalWrite(BUZ,HIGH);
      delayMicroseconds(delay);
      digitalWrite(BUZ,HIGH);
      digitalWrite(LED1,LOW);
      break;
    }
  }
}

void getrandobutseq() { //Gives me 4 numbers from 1 to 4 completely random with repetition
for (int i = 0; i < 4; i++) {
    butSeq[i] = random(1, 5);  
  }
}

