int SW1 = D0;
int SW2 = D1;
int SW3 = D2;
int SW4 = D3;
int BUZ = D4;
int LED1 = D7;
int LED2 = D8;
int LED3 = D9;
int LED4 = D10;
void setup() {
pinmode(SW1,INPUT_PULLUP); //Clicky Guys
pinmode(SW2,INPU_PULLUPT);
pinmode(SW3,INPUT_PULLUP);
pinmode(SW4,INPUT_PULLUP);

pinmode(BUZ,OUTPUT); //Buuz Buzz Bad Boi

pinmode(LED1,Output); //The LED Ladies
pinmode(LED2,Output);
pinmode(LED3,Output);
pinmode(LED4,Output);

bool butStat=false;

long startTime = millis();

}

void loop() {
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
}

void gameStart(){
  
}

