int leds[] = {4,5,6,7,8,9};

unsigned long prevMillis = 0;

int counter = 5;
int downButtonState = 0;         
int lastDownButtonState = 0;
int upButtonState = 0;         
int lastUpButtonState = 0;

const int PB_UP = 3;
const int PB_DOWN = 2;

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

  digitalWrite(leds[counter],1);

   downButtonState = digitalRead(PB_DOWN);

  if (downButtonState != lastDownButtonState) {
    if (downButtonState == 0) {
      
      digitalWrite(leds[counter],0);
      counter--;
      
    }
    
  }
  
   lastDownButtonState = downButtonState;
  
  
   upButtonState = digitalRead(PB_UP);

  if (upButtonState != lastUpButtonState) {
    
    if (upButtonState == 0) {
      
      digitalWrite(leds[counter],0);
      counter++;
      
    }
    
  }
  
   lastUpButtonState = upButtonState;
  
  if(counter == 6){
  
  counter--;
  }
  
  if(counter == -1){
  
  counter++;
  }


}
