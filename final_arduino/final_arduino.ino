int i;

int toBlue, toRed, toGreen, toPurple, toYellow;

//bottle order:
// blue - green - purple - yellow - red 

int trayStep = 3;
int trayDirection = 2;
int mixerStep = 5;
int mixerDirection = 4;
int blueBottle = 8;
int greenBottle = 9;
int purpleBottle = 10;
int yellowBottle = 11;
int redBottle = 12;
int btIn = 13;
int previousState = HIGH;
int mixer = 53;

void setup() {
  pinMode(btIn, INPUT);
  pinMode(trayStep, OUTPUT); // Step
  pinMode(trayDirection, OUTPUT); // Direction
  pinMode(mixerStep, OUTPUT); // Step
  pinMode(mixerDirection, OUTPUT); // Direction
  Serial.begin(9600); // Initialize serial communication at 9600 baud
  pinMode(blueBottle, OUTPUT);
  pinMode(greenBottle, OUTPUT);
  pinMode(purpleBottle, OUTPUT);
  pinMode(yellowBottle, OUTPUT);
  pinMode(redBottle, OUTPUT);
  pinMode(mixer, OUTPUT);
  digitalWrite(mixer, HIGH);
  digitalWrite(blueBottle, HIGH);
  digitalWrite(greenBottle, HIGH);
  digitalWrite(purpleBottle, HIGH);
  digitalWrite(yellowBottle, HIGH);
  digitalWrite(redBottle, HIGH);
}

void loop() 
{
  if (Serial.available() > 0) 
  {
    char command = Serial.read();  // Read the incoming byte
    
    //Check for 'F' or 'R' to pour forward or backward for 3 seconds
    if (command == 'F') 
    {
      Serial.println("Rotating Forward 1");
      rotateForward(200);   // Call the forward rotation function
    }
    else if (command == 'B') 
    {
      Serial.println("Rotating Backward 1");
      rotateBackward(200);  // Call the backward rotation function
    }
    else if (command == 'M') 
    {
      Serial.println("Rotating Mixer");
      moveToMixerFromLast();  // Call the backward rotation function
    }
    else if (command == 'S') 
    {
      Serial.println("Rotating Serve");
      moveToServe();  // Call the backward rotation function
    }else if(command == 'T'){
      createSunsetBliss();
    }else if (command == 'U') 
    {
      Serial.println("Moving Up");
      moveUp();   // Call the forward rotation function
    }
    else if (command == 'D') 
    {
      Serial.println("Moving Down");
      moveDown();  // Call the backward rotation function
    }else if (command == 'N') 
    {
      Serial.println("BLUE BOTTLE");
      pour(blueBottle);
      pour(blueBottle);
    }else if(command == 'G'){
      pour(greenBottle);
      pour(greenBottle);
    }else if(command == 'P'){
      pour(purpleBottle);
      pour(purpleBottle);
    }else if(command == 'K'){
      pour(yellowBottle);
      pour(yellowBottle);
    }else if(command == 'R'){
      delay(100); // Short delay to allow stabilization
      pour(redBottle);
      delay(100);
      pour(redBottle);
    }else if(command == 'Z'){
      createBlueLagoon();
    }else if(command == 'Y'){
      createSunsetBliss();
    }else if(command == 'X'){
      createEmeraldMojito();
    }else if(command == 'W'){
      createRubyRoyal();
    }else if(command == 'V'){
      createGoldenGlow();
    }else if(command == 'T'){
      createPurpleParadise();
    }else if(command == 'L'){
      mix();
    }else if(command == 'u'){
      moveUpLittle();
    }
  }
  int currentState = digitalRead(btIn);

  if(previousState == HIGH && currentState == LOW){
    Serial.print("COIN ");
    Serial.print("\r");
    delay(200);
  }
  previousState = currentState;
  delay(20);

}

void pour(int bottlePin){
  digitalWrite(bottlePin, LOW);
  delay(750); 
  digitalWrite(bottlePin, HIGH);
  delay(2000);
}

// blue - purple - red -> z
void createBlueLagoon(){
  rotateForward(200);
  delay(500);
  pour(blueBottle);
  pour(blueBottle);
  pour(blueBottle);
  rotateForward(200);
  delay(500);
  pour(greenBottle);
  pour(greenBottle);
  pour(greenBottle);
  rotateForward(200);
  delay(500);
  pour(purpleBottle);
  pour(purpleBottle);
  pour(purpleBottle);
  rotateForward(200);
  delay(500);
  pour(yellowBottle);
  pour(yellowBottle);
  pour(yellowBottle);
  rotateForward(200);
  delay(500);
  pour(redBottle);
  pour(redBottle);
  pour(redBottle);
  moveToMixerFromLast();
  moveDown();
  mix();
  delay(500);
  moveUp();
  delay(1000);
  moveToServe();
}

// green - purple - red -> U
void createSunsetBliss(){
  rotateForward(400);
  delay(500);
  pour(greenBottle);
  pour(greenBottle);
  pour(greenBottle);
  rotateForward(200);
  delay(500);
  pour(purpleBottle);
  pour(purpleBottle);
  pour(purpleBottle);
  rotateForward(400);
  delay(500);
  pour(redBottle);
  pour(redBottle);
  pour(redBottle);
  moveToMixerFromLast();
  moveDown();
  mix();
  moveUp();
  delay(500);
  moveToServe();
}

void createEmeraldMojito(){
  rotateForward(200);
  delay(500);
  pour(blueBottle);
  pour(blueBottle);
  pour(blueBottle);
  rotateForward(200);
  delay(500);
  pour(greenBottle);
  pour(greenBottle);
  pour(greenBottle);
  rotateForward(600);
  delay(500);
  pour(redBottle);
  pour(redBottle);
  pour(redBottle);
  moveToMixerFromLast();
  moveDown();
  mix();
  moveUp();
  delay(500);
  moveToServe();
}

void createRubyRoyal(){
  rotateForward(200);
  delay(500);
  pour(blueBottle);
  pour(blueBottle);
  pour(blueBottle);
  rotateForward(400);
  delay(500);
  pour(purpleBottle);
  pour(purpleBottle);
  pour(purpleBottle);
  rotateForward(400);
  delay(500);
  pour(redBottle);
  pour(redBottle);
  pour(redBottle);
  moveToMixerFromLast();
  moveDown();
  mix();
  moveUp();
  delay(500);
  moveToServe();
}

void createGoldenGlow(){
  rotateForward(600);
  delay(500);
  pour(purpleBottle);
  pour(purpleBottle);
  pour(purpleBottle);
  rotateForward(200);
  delay(500);
  pour(yellowBottle);
  pour(yellowBottle);
  pour(yellowBottle);
  rotateForward(200);
  delay(500);
  pour(redBottle);
  pour(redBottle);
  pour(redBottle);
  moveToMixerFromLast();
  moveDown();
  mix();
  moveUp();
  delay(500);
  moveToServe();
}

void createPurpleParadise(){
  rotateForward(200);
  delay(500);
  pour(blueBottle);
  pour(blueBottle);
  pour(blueBottle);
  rotateForward(200);
  delay(500);
  pour(greenBottle);
  pour(greenBottle);
  pour(greenBottle);
  rotateForward(200);
  delay(500);
  pour(purpleBottle);
  pour(purpleBottle);
  pour(purpleBottle);
  rotateForward(640);
  moveDown();
  mix();
  moveUp();
  delay(500);
  moveToServe();
}



void rotateBackward(int steps) 
{
  digitalWrite(trayDirection, LOW);  // Set direction to forward

  // Rotate for 3 seconds (3000 milliseconds)
  
    for (i = 0; i < steps; i++) 
    {
      digitalWrite(trayStep, HIGH);
      delayMicroseconds(3000);
      digitalWrite(trayStep, LOW);
      delayMicroseconds(3000);
    }
  
}

void rotateForward(int steps) 
{
  digitalWrite(trayDirection, HIGH);  // Set direction to reverse

  // Rotate for 3 seconds (3000 milliseconds)
 
    for (i = 0; i < steps; i++) 
    {
      digitalWrite(trayStep, HIGH);
      delayMicroseconds(3000);
      digitalWrite(trayStep, LOW);
      delayMicroseconds(3000);
    }
  
}

void moveToMixerFromLast() 
{
  digitalWrite(trayDirection, HIGH);  // Set direction to reverse

  // Rotate for 3 seconds (3000 milliseconds)
 
    for (i = 0; i < 240; i++) 
    {
      digitalWrite(trayStep, HIGH);
      delayMicroseconds(3000);
      digitalWrite(trayStep, LOW);
      delayMicroseconds(3000);
    }
  
}

void moveToServe() 
{
  digitalWrite(trayDirection, LOW);  // Set direction to reverse

  // Rotate for 3 seconds (3000 milliseconds)
 
    for (i = 0; i < 1220; i++) 
    {
      digitalWrite(trayStep, HIGH);
      delayMicroseconds(3000);
      digitalWrite(trayStep, LOW);
      delayMicroseconds(3000);
    }
  
}

void moveUp() 
{
  digitalWrite(mixerDirection, LOW);  // Set direction to forward

  // Rotate for 3 seconds (3000 milliseconds)
  
    for (i = 0; i < 10000; i++) 
    {
      digitalWrite(mixerStep, HIGH);
      delayMicroseconds(500);
      digitalWrite(mixerStep, LOW);
      delayMicroseconds(500);
    }
  
}

void moveUpLittle() 
{
  digitalWrite(mixerDirection, LOW);  // Set direction to forward

  // Rotate for 3 seconds (3000 milliseconds)
  
    for (i = 0; i < 200; i++) 
    {
      digitalWrite(mixerStep, HIGH);
      delayMicroseconds(500);
      digitalWrite(mixerStep, LOW);
      delayMicroseconds(500);
    }
  
}
void moveDown() 
{
  digitalWrite(mixerDirection, HIGH);  // Set direction to reverse

  // Rotate for mixerStep seconds (3000 milliseconds)
 
    for (i = 0; i < 10000; i++) 
    {
      digitalWrite(mixerStep, HIGH);
      delayMicroseconds(500);
      digitalWrite(mixerStep, LOW);
      delayMicroseconds(500);
    }
  
}

void mix(){
  digitalWrite(mixer, LOW);
  delay(5000);
  digitalWrite(mixer, HIGH);
  delay(500);
}
