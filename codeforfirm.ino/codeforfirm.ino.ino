int SW1 = D0;
int SW2 = D1;
int SW3 = D2;
int SW4 = D3;
int SWSTR = D5;

int BUZ = D4;

int LED1 = D7;
int LED2 = D8;
int LED3 = D9;
int LED4 = D10;
void setup() {
pinmode(SW1,INPUT); //Clicky Guys
pinmode(SW2,INPUT);
pinmode(SW3,INPUT);
pinmode(SW4,INPUT);

pinmode(BUZ,OUTPUT); //Buuz Buzz Bad Boi

pinmode(LED1,Output); //The LED Ladies
pinmode(LED2,Output);
pinmode(LED3,Output);
pinmode(LED4,Output);
long startTime = millis();

}

void loop() {
 long sw1timE;
if (digitalRead())

}
