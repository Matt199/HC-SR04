#define ECHO 4 // define digital pin for Echo as 2
#define TRIG 5  // define digital pin for Trig as 3

int Time; 
int distanceInCm;
int distanceInInch;

void setup()
{
  pinMode(ECHO, INPUT); // echo as Input
  pinMode(TRIG, OUTPUT); // trig as Output
  Serial.begin(9600);
  Serial1.begin(9600);
  
}

void counting_The_Distance() // creating the function for couting the distance
{
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  Time = pulseIn(ECHO, HIGH); // pulseIn returns time in micro seconds
  distanceInCm = Time / 58; // calculating the distance in cm
  distanceInInch = Time / 148; // calculating the distance in Inch
}

void loop()
{
  counting_The_Distance(); // init func
  Serial.print("Distance: ");
  Serial.print(distanceInCm);
  Serial1.print("#");
  Serial1.print(distanceInCm);
  //Serial.print(distanceInInch);
  Serial.println(" cm");
  //Serial.println(" Inch");
  delay(500); 
}
