
int MotorControl1 = 4;
int MotorControl2 = 5;
int MotorControl3 = 6;
int MotorControl4 = 7;
int incomingByte = 0;   // for incoming serial data
String input = ""; // for command message

void action (String cmd) {
  if(cmd == "off") {
    digitalWrite(MotorControl1, HIGH); // NO1 + COM1
    digitalWrite(MotorControl2, HIGH); // NO2 + COM2
    digitalWrite(MotorControl3, HIGH); // NO3 + COM3
    digitalWrite(MotorControl4, HIGH); // NO4 + COM4
    return;
  }

  if(cmd == "on") {
    digitalWrite(MotorControl1, LOW); // NC1 + COM1
    digitalWrite(MotorControl2, LOW); // NC2 + COM2
    digitalWrite(MotorControl3, LOW); // NC3 + COM3
    digitalWrite(MotorControl4, LOW); // NC4 + COM4
    return;
  }

  if(cmd == "reset") {
    action("off");
    delay(1000);
    action("on");
    return;
  }

  Serial.println("unknown action");
}

// the setup routine runs once when you press reset:
void setup()  {
  pinMode(MotorControl1, OUTPUT);
  pinMode(MotorControl2, OUTPUT);
  pinMode(MotorControl3, OUTPUT);
  pinMode(MotorControl4, OUTPUT);
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  Serial.println("relay controller v0.1 rmp@psyphi.net actions are on|off|reset");
  input = "";
} 

// the loop routine runs over and over again forever:
void loop()  {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();

    if(incomingByte == 0x0D) {
      Serial.println("action:" + input);
      action(input);
      input = "";
    } else {
      input.concat(char(incomingByte));
    }
  } else {
    delay(1000); // no need to go crazy
  }
}


