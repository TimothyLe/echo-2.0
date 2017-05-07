// Represents A0 on UNO board
int analogPin= 0;
// The value from the analog pin A0 
int raw= 0;
// The input voltage
int Vin= 5;
// The output voltage
float Vout= 0;
// Resistor value
float R1= 10630;  
float R2= 0;
// Used to calculate R2
float buffer= 0;

void setup(){
  Serial.begin(9600); // baud rate
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
}
