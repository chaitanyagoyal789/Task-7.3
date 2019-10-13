int buzzerPin = 1;
int triggerPin = 2;
int echoPin = 3;
int LEDPin = 4;

long duration;

float distance;

void setup() 
{                        
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(3, INPUT);
  
  Serial.begin(9600);                  
}

void loop() 
{
  digitalWrite(2, HIGH);            
  delayMicroseconds(10);
  
  digitalWrite(2, LOW);

  duration = pulseIn(3, HIGH);                

  distance = duration * 0.00034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distanceMeters);
  Serial.println("  Meters");

  if (distance <= 1 )    
  {
    digitalWrite(4,HIGH);
    
    tone(1, 1200); 
    delay(300);                                           
  }
  else    
  {
    digitalWrite(4, LOW);
    
    noTone(1);
  }
}
