#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// Use pins 2 and 3 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_RX = 11; // Connects to module's RX 
static const uint8_t PIN_MP3_TX = 10; // Connects to module's TX 
SoftwareSerial softwareSerial(PIN_MP3_TX, PIN_MP3_RX);

// Create the Player object
DFRobotDFPlayerMini player;



void setup() {

  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);

  // Init USB serial port for debugging
  Serial.begin(9600);
  // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);



  // Start communication with DFPlayer Mini
  if (player.begin(softwareSerial)) {
    Serial.println("OK");
    // Set volume to maximum (0 to 30).
    player.volume(30);
  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }
}

void loop() {

  int button2 = digitalRead(2);
  int button3 = digitalRead(3);
  int button4 = digitalRead(4);
  int button5 = digitalRead(5);
  int button6 = digitalRead(6);
  int button7 = digitalRead(7);

  if (button2 == LOW) {
    Serial.println("boop 2");
    //player.play(1);
    playTrack(1);
    delay(500);
  } else if (button3 == LOW) {
    Serial.println("boop 3");
    playTrack(2);
    delay(500);
  } else if (button4 == LOW) {
    Serial.println("boop 4");
    playTrack(3);
    delay(500);
  } else if (button5 == LOW) {
    Serial.println("boop 5");
    playTrack(4);
    delay(500);
  } else if (button6 == LOW) {
    Serial.println("boop 6");
    playTrack(5);
    delay(500);
  } else if (button7 == LOW) {
    Serial.println("boop 7");
    playTrack(6);
    delay(500);
  }  
}


void playTrack(uint8_t track) {
   player.stop();
   delay(200);
   player.play(track);
   delay(200);
   int file = player.readCurrentFileNumber();

   Serial.print("Track:");Serial.println(track);
   Serial.print("File:");Serial.println(file);
}
