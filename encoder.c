const byte interruptPin = 2;
int c = 0;
long lastInterruptTime = 0;
unsigned long duration = 0;

void setup() {
  Serial.begin(9600);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(interruptPin-2, count, FALLING);
}

void loop() {
  Serial.println(duration);
  if (c>5)
  {
    c=0;
    duration = millis()-lastInterruptTime;
    lastInterruptTime = millis();
    
  }
 
  
}

void count() {
  c++;
   
}


 
