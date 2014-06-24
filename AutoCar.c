/*
This Project makes use of many different sensors and lights to make a functioning 2WD car.
Ping Sensor, 2 Motors, LED lights, 

*/
// Lists all the pins on board used
const int motorLeft = 9;
const int motorRight = 10;
const int trigPin = 12;
const int echoPin = 13;
const int ledPin1 = A5;
const int ledPin2 = A4;
const int photoSensor = A0;
const int frontLed = A3;

void setup()
{
  // Initializes the two motors as outputs
  pinMode(motorLeft, OUTPUT);
  pinMode(motorRight, OUTPUT); 
  // Initializes the Ping Sensor (trigPin as outout, echoPin as inout)
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // Initializes the LEDs as outputs
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(frontLed, OUTPUT);
  analogWrite(frontLed, 250);
  Serial.begin(9600);
  //Initializes the Photosensor
  pinMode(photoSensor, INPUT);
}

void loop()
{
  float cmDistance, averageValue, lights;
  
  cmDistance = pingReading();
  averageValue = distanceAverage(cmDistance);
  lights = motorControls(averageValue);
  // photoSensorFrontLED();
//  Serial.print(cmDistance);
//  Serial.println(" centimeters away!");
//  Serial.print(averageValue);
//  Serial.println(" Average value");
//  if(lights == 1)
//  {
//    Serial.println("Braking!");
//  }
//  else
//  {
//    analogWrite(frontLed, 255);
//  }
  delay(100);
}

// This function initiates the Ping sensor and converts the reading to CM
long pingReading()
{
  float microSecond, cm;
    // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  
  // The echo pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  microSecond = pulseIn(echoPin, HIGH);
  cm = microSecond / 29 / 2;
  
  return cm;
}

  int counter = 0;
  float distanceArray[5];
  int counterAverage = 0;
  float numberOfValues = 5;
  float averageValue;
  float sum;
  int MAX = 500;
  
// This function takes in the distance reading in Centimeters, and 
//     outputs the average of the last [numberOfValues] readings
long distanceAverage(float centipoop)
{
  distanceArray[counter] = 0;
  distanceArray[counter] = centipoop;
// Makes sure that the distance isnt more than the MAX. If it is,
//     then it puts the previous value in. If there is no previous value 
//     (i.e. first reading), then it keeps the value.
//  if (centipoop < MAX || (counter == 0 && distanceArray[4] == 0))
//  {
//  distanceArray[counter] = centipoop;
//  }
//  else
//  {
//    if (counter == 0)
//    {
//      distanceArray[counter] = distanceArray[4];
//    }
//    else
//    {
//      distanceArray[counter] = distanceArray[counter - 1];
//    }
//  }
// Averages the 5 previous values and outputs them as averageValue. 
//     If it is first iteration, it simply displays reading.
 if(counterAverage == 1)
  {
    for(int i = 0; i < numberOfValues; i++)
    {
      sum = distanceArray[i] + sum;
    }
    averageValue = sum / numberOfValues;
    sum = 0;
  }
  else 
  {
    averageValue = distanceArray[counter];
  }

// Increments the counter. If counter = numberOfValues, then the 
//     counter resets. After first iteration is complete, counterAverage = 1,
//     so the program can start averaging the previous [numberOfValues] 
//     readings.
  counter = counter + 1;
  if(counter == numberOfValues)
  {
   counter = 0; 
   counterAverage = 1;
  }
 
  return averageValue;    
}

// This function controls the speed of the two motors. Returns 1 if Motors stopped.
int motorControls(long distance)
{
   if(distance > 80)
  {
    int speed1 = 80; // Speed is from 0 (Low) to 255 (High)
    analogWrite(motorLeft, speed1);
    analogWrite(motorRight, speed1);
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, 0);
    return 0;
  }
  else
  {
    digitalWrite(motorLeft, LOW);
    digitalWrite(motorRight, LOW);
    analogWrite(ledPin1, 250);
    analogWrite(ledPin2, 250);
    return 1;
  } 
}
int lightLevel, high = 0, low = 1023;
void photoSensorFrontLED()
{
  lightLevel = analogRead(photoSensor);
  // As we mentioned above, the light-sensing circuit we built
  // won't have a range all the way from 0 to 1023. It will likely
  // be more like 300 (dark) to 800 (light).
  
  // In the manualTune() function above, you need to repeatedly
  // change the values and try the program again until it works.
  // But why should you have to do that work? You've got a
  // computer in your hands that can figure things out for itself!

  // In this function, the Arduino will keep track of the highest
  // and lowest values that we're reading from analogRead().

  // If you look at the top of the sketch, you'll see that we've
  // initialized "low" to be 1023. We'll save anything we read
  // that's lower than that:
  
  if (lightLevel < low)
  {
    low = lightLevel;
  }

  // We also initialized "high" to be 0. We'll save anything
  // we read that's higher than that:
  
  if (lightLevel > high)
  {
    high = lightLevel;
  }
  
  // Once we have the highest and lowest values, we can stick them
  // directly into the map() function. No manual tweaking needed!
  
  // One trick we'll do is to add a small offset to low and high,
  // to ensure that the LED is fully-off and fully-on at the limits
  // (otherwise it might flicker a little bit).
  
  lightLevel = map(lightLevel, low+30, high-30, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);
  
  analogWrite(frontLed ,lightLevel);
  // Now we'll return to the main loop(), and send lightLevel
  // to the LED.
}
