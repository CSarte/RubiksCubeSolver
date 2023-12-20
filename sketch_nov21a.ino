

// yellow and white pins at the top since i wont be doing any shifting with them
const int yellowStepPin = 2;
const int yellowDirPin = 3;
const int whiteStepPin = 4;
const int whiteDirPin = 5;
// to reuse certain algorithm methods, i have these pins set up in ascending order
// so i can dynamically find pins to the left and right of the main pin im using
// as a center piece for the algorithm
int redStepPin = 6;
int redDirPin = 7;
int greenStepPin = 8;
int greenDirPin = 9;
int orangeStepPin = 10;
int orangeDirPin = 11;
int blueStepPin = 12;
int blueDirPin = 13;
const int stepsPerRevolution = 200;
void setup() {
  Serial.begin(9600);
  pinMode(yellowStepPin, OUTPUT);
  pinMode(yellowDirPin, OUTPUT);
  pinMode(whiteStepPin, OUTPUT);
  pinMode(whiteDirPin, OUTPUT);
  pinMode(redStepPin, OUTPUT);
  pinMode(redDirPin, OUTPUT);
  pinMode(greenStepPin, OUTPUT);
  pinMode(greenDirPin, OUTPUT);
  pinMode(orangeStepPin, OUTPUT);
  pinMode(orangeDirPin, OUTPUT);
  pinMode(blueStepPin, OUTPUT);
  pinMode(blueDirPin, OUTPUT);
}
void spin90CW(int motorPin, int DirPin) {
  digitalWrite(DirPin, HIGH);

  for(int x = 0; x < stepsPerRevolution/4; x++) {
    digitalWrite(motorPin,LOW);
    delayMicroseconds(750);
    digitalWrite(motorPin,HIGH);
    delayMicroseconds(750);
  }
}
void spin90CCW(int motorPin, int DirPin) {
  
  for(int x = 0; x < (90 * stepsPerRevolution / 360); x++) {
    digitalWrite(motorPin,HIGH);
    delayMicroseconds(750);
    digitalWrite(motorPin,LOW);
    delayMicroseconds(750);
  }
  
}
void spin180(int motorPin) {
  for(int x = 0; x < (90 * stepsPerRevolution / 360); x++) {
    digitalWrite(motorPin,LOW);
    delay(250);
    digitalWrite(motorPin,HIGH);
    delay(250);
  }
}


void loop() {
   if (Serial.available() > 0) {
    int index = 0; // Index to track position in the buffer
    // Read characters until newline '\n' or maximum length is reached
    while (true) {
      if (Serial.available()) {
        
        char incomingChar = Serial.read();
        if (incomingChar == '\n') {
          break; // Exit loop on newline
        }
        else if(incomingChar == 'B'){ //flip yellow
          spin90CCW(yellowStepPin, yellowDirPin);
          delay(250);
        }
        else if(incomingChar == 'F'){ //flip white
          spin90CCW(whiteStepPin, whiteDirPin);
          delay(250);
        }
        else if(incomingChar == 'R'){ //flip green
          spin90CCW(greenStepPin, greenDirPin);
          delay(250);
        }
        else if(incomingChar == 'L'){ //flip blue
          spin90CCW(blueStepPin, blueDirPin);
          delay(250);
        }
        else if(incomingChar == 'D'){ //flip orange
          spin90CCW(orangeStepPin, orangeDirPin);
          delay(250);
        }
        else if(incomingChar == 'U'){ //flip red
          spin90CCW(redStepPin, redDirPin);
          delay(250);
        }
        else if(incomingChar == 'b'){ //flip yellow
          spin90CW(yellowStepPin, yellowDirPin);
          delay(250);
        }
        else if(incomingChar == 'f'){ //flip white
          spin90CW(whiteStepPin, whiteDirPin);
          delay(250);
        }
        else if(incomingChar == 'r'){ //flip green
          spin90CW(greenStepPin, greenDirPin);
          delay(250);
        }
        else if(incomingChar == 'l'){ //flip blue
          spin90CW(blueStepPin, blueDirPin);
          delay(250);
        }
        else if(incomingChar == 'd'){ //flip orange
          spin90CW(orangeStepPin, orangeDirPin);
          delay(250);
        }
        else if(incomingChar == 'u'){ //flip red
          spin90CW(redStepPin, redDirPin);
          delay(250);
        }
      }
    }
    
    delay(1000);
 
  }


}


