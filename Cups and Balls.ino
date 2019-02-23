/*
 * Fall 2018 Midterm Assignment
 * Author: Hayk Mikayelyan (hm1973@nyu.edu)
 * Course: PComp
 * Instructor: Danny Rozin
 * 
 * Description:

	Sensor Description:
    This Linear Hall Effect Sensor produces an analog signal that varies given proximity to a magnet. 
    Useful for cases where you do not only want to detect if a magnet is nearby but also it's approximate distance. 
    
    Specifications:
    Hall Effect Sensor / Magnetism Sensor
    Analog Output
    Supply Voltage: 4.5V - 5.5V DC
    Max Supply Current: 9mA
    Output proportional to magnetic flux density
  
 * 
 */

#define hallPin A0
#define buzzPin 11
#define buttonPin 2


int hallState = 0;   // Value coming from sensor
boolean modeState;  

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzPin, OUTPUT);      
  pinMode(hallPin, INPUT);     
  Serial.begin(9600);
}

void loop(){

  int modeState = digitalRead(buttonPin);
  Serial.println(modeState);

  if (modeState == true) {
    
    hallState = analogRead(hallPin); 
  
    if ((500 >= hallState ) || (hallState >= 510)) {     
  
      Serial.print("YES : ");
      Serial.println(hallState);
      
      digitalWrite(buzzPin, HIGH);
    } 
    else {
      Serial.print("NO : ");
      Serial.println(hallState);
      
      digitalWrite(buzzPin, 0);    
    }

   
  }
  
  else {
    digitalWrite(buzzPin, 0);   
    Serial.print("DEVICE IS OFF");    
  }

}
