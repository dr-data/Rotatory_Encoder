volatile int PositionKnob = 0;
volatile int NewPositionKnob = 0;
const byte OutA_Pin = 2; // interupt pin A
const byte OutB_Pin = 3; // interupt pin B

void setup()
{
  pinMode(OutA_Pin, INPUT_PULLUP);
  pinMode(OutB_Pin, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Basic Encoder Test 4X :");
  attachInterrupt(digitalPinToInterrupt(OutA_Pin), KnobA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(OutB_Pin), KnobB, CHANGE);
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

void KnobA(void)
{
  if (digitalRead(OutA_Pin) == digitalRead(OutB_Pin))
  {
    NewPositionKnob++;
  }
  else
  {  
    NewPositionKnob--;
  }
}

void KnobB(void)
{
  if (digitalRead(OutA_Pin) != digitalRead(OutB_Pin))
  {
    NewPositionKnob++;
  }
  else
  {  
    NewPositionKnob--;
  }
}
