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
  attachInterrupt(digitalPinToInterrupt(OutA_Pin), Knob, CHANGE);
}

void loop()
{
  if(PositionKnob != NewPositionKnob)
  {
    Serial.print("Knob = ");
    Serial.println(NewPositionKnob);
    PositionKnob = NewPositionKnob;
  }
}

void Knob(void)
{
  if (digitalRead(OutA_Pin) == 1 && digitalRead(OutB_Pin) == 1 || digitalRead(OutA_Pin) == 0 && digitalRead(OutB_Pin) == 0)
  {
    NewPositionKnob++;
  }
  else
  {  
    NewPositionKnob--;
  }
}
