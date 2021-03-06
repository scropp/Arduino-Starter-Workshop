///////////////////////////////////////////////////////////////////////////
// Our Variables
int lives = 3;
int whichPin = 7;
int whichDirection = 1;
int delayTime = 100;

///////////////////////////////////////////////////////////////////////////
// Set up our pin modes
void setup()
{
  pinMode(6, INPUT_PULLUP);
  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

///////////////////////////////////////////////////////////////////////////
// Called when player wins a round
void Win()
{
  for(int i=0; i<5; ++i)
  {
    digitalWrite(10, HIGH);
    delay(20);
    digitalWrite(10, LOW);
    delay(100);
  }
}

///////////////////////////////////////////////////////////////////////////
// Called when player loses a round
void Lose()
{
  for(int i=0; i<5; ++i)
  {
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    delay(20);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    delay(100);
  }
}

///////////////////////////////////////////////////////////////////////////
// Called when the game is over
void GameOver()
{
  while(true)
  {
    digitalWrite(whichPin, HIGH);
    delay(100);
    digitalWrite(whichPin, LOW);
    delay(400);
  }
}

///////////////////////////////////////////////////////////////////////////
void loop()
{
  // is the button pressed?
  if(digitalRead(6) == LOW)
  {
    // is the middle LED lit?
    if(whichPin == 10)
    {
      // Win!!
      Win();  
  
      // Make the game get faster    
      delayTime = delayTime - 5;
    }
    else
    {
      // Lose
      Lose();
      
      // Lose a life 
      lives = lives - 1;
      if(lives < 0)
        GameOver();
    }
    delay(1000);
    while(digitalRead(6) == LOW)
    {
      // dont do anything.. we're just waiting for 
      // player to stop pressing the button
    }
  }
  else
  {
    // turn off the current pin
    digitalWrite(whichPin, LOW);
    
    // move to the next pin
    whichPin = whichPin + whichDirection;
  
    // if we reach the last pin, change direction
    // and come back again!
    if(whichPin >= 13)
      whichDirection = -1;
    else if(whichPin <= 7)
      whichDirection = 1;

    // turn on new pin
    digitalWrite(whichPin, HIGH);
    
    // and wait a bit!
    delay(delayTime);
  }
}

