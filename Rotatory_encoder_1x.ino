volatile int PositionKnob = 0;
volatile int NewPositionKnob = 0;
const byte OutA_Pin = 2; // interupt pin A
const byte OutB_Pin = 3; // interupt pin B

void setup()
{
  pinMode(OutA_Pin, INPUT_PULLUP);
  pinMode(OutB_Pin, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Basic Encoder Test 1X :");
  attachInterrupt(digitalPinToInterrupt(OutA_Pin), Knob, RISING);
}

void loop()
{
  if(PositionKnob != NewPositionKnob)
  {
    Serial.print("Knob = ");
    Serial.println(NewPositionKnob);
    PositionKnob = NewPositionKnob;
    // you could publish "PositionKnob" thru MQTT, serial port or take any other actions based on the result.
    // wait for a delay to avoid flooding the destination
    // Delay will have no effect on the reading of the rotatory because interrupts are prior to any other functions.
  }
}

void Knob(void)
{
  if (digitalRead(OutB_Pin) == 1)
  {
    NewPositionKnob++;
  }
  else
  {  
    NewPositionKnob--;
  }
}
