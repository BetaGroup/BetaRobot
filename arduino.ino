/*
  Betarobot
  The robot adventure of the #BetaVan at Campus Party London 2013
  Creative Commons http://creativecommons.org/licenses/by-sa/3.0/

  Sources available at https://github.com/BetaGroupBe/BetaRobot

  Authors:
    - Julie Foulon
    - Ramon Suarez
    - Cédric Donckels
    - Jean-Christophe Cuvelier
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int red = 9;
int yel = 10;
int gre = 11;
int bot = 7;
int buz = 6;
int apin = 0;

int speedo;
boolean left = true;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yel, OUTPUT);
  pinMode(gre, OUTPUT);
  pinMode(bot, INPUT);
  pinMode(buz, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  speedo = analogRead(apin);

  if(digitalRead(bot) == HIGH)
  {
    alarm();
  }
  else
  {
    kit(speedo);
  }
}

void alarm()
{
  for(int level = 0; level < 255; level+5)
  {
    analogWrite(buz, level);
    delay(10);
  }

  for(int level = 255; level > 0; level-5)
  {
    analogWrite(buz, level);
    delay(10);
  }

}

void kit(int speedo)
{

  if(left)
  {
    one(red);
    buzz(speedo);
    one(yel);
    buzz(speedo);
    one(gre);
    buzz(speedo);
    left = false;
  }
  else
  {
    one(gre);
    buzz(speedo);
    one(yel);
    buzz(speedo);
    one(red);
    buzz(speedo);
    left = true;
  }

}

void buzz(int speedo)
{
  delay(speedo);
}

void one(int nbr)
{
  digitalWrite(red, LOW);
  digitalWrite(yel, LOW);
  digitalWrite(gre, LOW);
  digitalWrite(buz, LOW);
  digitalWrite(nbr, HIGH);
}