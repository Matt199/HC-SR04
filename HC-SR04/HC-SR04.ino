#define ECHO 2
#define TRIG 3 

int Time;
int distanceInCm;

void setup()
{
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  Serial.begin(9600);
  
}

void counting_The_Distance()
{
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  Time = pulseIn(ECHO, HIGH);
  distanceInCm = Time/58;
  
}

void loop()
{
  counting_The_Distance();
  Serial.print("Distance: ");
  Serial.print(distanceInCm);
  Serial.println(" cm");
  delay(500);
}
