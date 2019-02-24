class Alarm
{
  // Variables In Program
  int lightPin;               // Output Pin (lights)
  int sirenPin;               // Output Pin (siren)
  int sensorPin;              // InputPin (sensor)
  
  // Constants In Program
  const long sirenTime = 5000;             // Siren Time (5 Seconds)
  const long amberLightTime = 30000;       // AmberLight Time (30 Seconds)
  
  // Class Variables (set by the program)
  int amberLightState;        // amberLightState
  int sirenState;             // sirenState
  unsigned long activationTimeStamp = 0;   // clock time when light/sirens where activated
  unsigned long currentClockTime;      // clock time when times are being checked
  
  public: Alarm(int lPin, int sPin, int inPin)
  {
    lightPin = lPin;
    pinMode(lightPin, OUTPUT); // declares that this pin is output
    
    sirenPin = sPin;
    pinMode(sirenPin, OUTPUT); // declares that this pin is output
    
    sensorPin = inPin;
    pinMode(sensorPin, INPUT); // declares that this is an input pin
  }
  
  void checkIfTriggered() // input variable is sensor
  {
    if(digitalRead(sensorPin) == HIGH) // if sensor has been hit
    {
      activationTimeStamp = millis();
      
      digitalWrite(sirenPin, HIGH); // turns the siren on         
      digitalWrite(lightPin, HIGH); // turns the amber light on
    }
    
    if(digitalRead(sensorPin) == LOW) // if sensor has NOT been hit
    {
      currentClockTime = millis();
      
      if((currentClockTime - activationTimeStamp) >= sirenTime)
      {
        digitalWrite(sirenPin, LOW);
      }
      
      if((currentClockTime - activationTimeStamp) >= amberLightTime)
      {
        digitalWrite(lightPin, LOW);
        // activationTimeStamp = 0; // resets value
      }
    }
  }
};

// Instantiation Block START

Alarm bar1 (31, 32, 2); // light, siren, sensor
Alarm bar2 (33, 34, 3); // light, siren, sensor

// Instantiation Block END

void setup()
{
  // nothing to set up
}

void loop()
{
  bar1.checkIfTriggered();
  bar2.checkIfTriggered();
}
