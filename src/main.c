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

/*!< The Ohm Meter */
// Represents A0 on UNO board
int analogPin= 1;
// The value from the analog pin A0 
int raw= 0;
// The input voltage
int Vin= 5;
// The output voltage
float Vout= 0;
// Resistor value
float R1= 100000;   // 100k ohm  
float R2= 0;
// Used to calculate R2
float buffer= 0;

/*!< The Serial 7 Segment Display */
int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;

int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 13;

void setup(){
  Serial.begin(9600); // baud rate

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

void loop(){
  raw = analogRead(analogPin);  // 0 - 5v mapped to 0 - 1023 bits at a rate of 4.9mV/unit
  if(raw) { // Checks if analog pin has input
    buffer = raw * Vin;
    Vout = (buffer)/1024.0;  // 0 - 1023 bits 
    buffer = (Vin/Vout) -1;
    R2 = R1 * buffer;
    Serial.print("Vout: ");
    Serial.println(Vout);
    Serial.print("R2: ");
    Serial.println(R2);
    delay(1000);
  }

  //!< S7S display
  // 1st digit
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    // Set to 0
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);   
    // Prevents flickering
    delay(1);                // internal synchronous clock waits for 0.001 second

  // 2nd digit
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    // Set to 0
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);   
    // Prevents flickering
    delay(1);                // internal synchronous clock waits for 0.001 second

    // 3rd digit
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
    // Set to 0
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);   
    // Prevents flickering
    delay(1);                // internal synchronous clock waits for 0.001 second

    // 4th digit
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
    // Set to 0
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);   
    // Prevents flickering
    delay(1);                // internal synchronous clock waits for 0.001 second
}
