/* Exercise_Chap05_KnightRider
  This is an exercise taken from the book:
  Beginning C for Arduino 2nd Ed (Jack Purdum)
  Knight Rider Kit car sweeping lights. This 
  version uses 'while' loops to count through
  an array of digital output pins. Notice that 
  the loop control variable is declared static 
  and initialized with a value of 0. It is shared
  between the loops in the main body of the 
  program like a game of hot potato. Also, the
  constant 'MAX_COUNT' is initialized in a way
  that scales to the index of the last array element.
  This works for different array sizes and variable types.
  Thnx Jack ;-)
  Written in Arduino C language
  @author Mike Tonge
  @date 11/26/2019
*/

// Initialize aray with Arduino digital pin numbers
int ledPins[] = {4, 5, 6, 7, 8, 9, 10};
const int DELAY_TIME = 100; // Time in milisedonds. Change to suit
const int MIN_COUNT = 0; // First aray element is index 0
// Scale value to index of last aray element // MAX_COUNT is 6
const int MAX_COUNT = (sizeof(ledPins) / sizeof(ledPins[0])) - 1; 


void setup() { 
  for (int pin = MIN_COUNT; pin <= MAX_COUNT; pin++) {
    pinMode(ledPins[pin], OUTPUT); // Initialize Arduino pins as output
    digitalWrite(ledPins[pin], LOW); // Turn digital outputs off
  }
}
void loop() {
	static int index = 0; // Initialize loop control variable.
  while (index < MAX_COUNT) { // Counts up from 0 to 5
    digitalWrite(ledPins[index], HIGH); // Turn on led
    delay(DELAY_TIME);                  // Wait a tick
    digitalWrite(ledPins[index], LOW);  // Turn off led
    index = index + 1;
  }
  while (index > MIN_COUNT) { // Counts down from 6 to 1
    digitalWrite(ledPins[index], HIGH); // Turn on led
    delay(DELAY_TIME);                  // Wait a tick
    digitalWrite(ledPins[index], LOW);  // Turn off led
    index = index - 1;
  }
}
