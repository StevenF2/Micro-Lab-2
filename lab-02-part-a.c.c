int leds[] = {4,5,6,7,8,9};

unsigned long prevMillis = 0;

byte counter = 0;

const int PB_UP = 3;
const int PB_DOWN = 2;

int buttonPushCounter = 0;   
int buttonState = 0;         
int lastButtonState = 0;

void setup()
{
  for (int i =0;i<6;i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(PB_DOWN,INPUT);
  pinMode(PB_UP,INPUT);
  
  
}

void loop()
{

int Pushed = digitalRead(PB_DOWN);
  unsigned long currentMillis = millis();
  
  if(currentMillis - prevMillis >= 250){

    prevMillis = currentMillis;
    
  if(Pushed == 0){
  
   	counter++;
  
  }
  if(Pushed == 1){
  
  counter--;
  
  } 
    binaryCounter(counter);
    
  }

}
void binaryCounter(byte counter)
{
  for (int i=0;i<6;i++)
  {
    if (bitRead(counter, i)==1)
    {
      digitalWrite(leds[i], HIGH);
    }
    else
    {
      digitalWrite(leds[i], LOW);
    }
  }

}