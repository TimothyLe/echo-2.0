/*

Displays digits 0-9 on the 7-segment display
    A
   ---
F |   | B
  | G | 
   ---
E |   | C
  |   | 
   ---
    D
Pins 2-8 connects to the 7 segments of the display
*/

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;

// Setup runs once when you press reset
void setup(){
    // initialize digital pins as outputs
    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pinC, OUTPUT);
    pinMode(pinD, OUTPUT);
    pinMode(pinE, OUTPUT);
    pinMode(pinF, OUTPUT);
    pinMode(pinG, OUTPUT);
    // Digital pins
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
}

// Continuous loop
void loop(){
    // 1st digit
    digitalWrite(D1, HIGH);
    digitalWrite(D1, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D1, LOW);
    // Set to 0
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);   
    // Prevents flickering
    delay(1);                // internal synchronous clock waits for 0.001 second
    
    // 2nd digit
    digitalWrite(D1, LOW);
    digitalWrite(D1, HIGH);
    digitalWrite(D1, LOW);
    digitalWrite(D1, LOW);
    // Set to 1
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);   
    // Prevents flickering
    delay(1);                // internal synchronous clock waits for 0.001 second
    
    // 3rd digit
    digitalWrite(D1, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D1, HIGH);
    digitalWrite(D1, LOW);
    // Set to 2
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);   
    // Prevents flickering
    delay(1);                // internal synchronous clock waits for 0.001 second
    
    // 4th digit
    digitalWrite(D1, LOW);
    digitalWrite(D1, HIGH);
    digitalWrite(D1, LOW);
    digitalWrite(D1, LOW);
    // Set to 3
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);   
    // Prevents flickering
    delay(1);                // internal synchronous clock waits for 0.001 second
}
