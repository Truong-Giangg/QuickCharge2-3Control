int pin5 = 5; //chan 5 lam chan de handshake d-
int pin4 = 4; //chan 4 lam chan d+
void setup() {
  //D+ chua khai bao gi => D+ = 0.6V
  pinMode(pin5, OUTPUT); //output de cai dat muc logic low
  digitalWrite(pin5, LOW); //cho D- = 0 (D- = 0 sau 1.25s, D- = 0.6v thi handshake xong)
  delay(1000); // doi 1.25s de qua trinh handshake bat dau 
  pinMode(pin5, INPUT); // floating pin 5 => D- = 0.6v => handshake xong
  delay(10);

  volt12();
  delay(1000);
  volt5();
  delay(1000);
  volt9();
  delay(1000);
  continuous(); //vao che do continuous startpoint = 9v
  delay(1000);
  inc1v(); // tang tu 9v len 10v
  delay(3000);
  dec1v(); //giam tu 10v xuong 9v
  dec1v(); //giam tu 9v xuong 8v
}

void loop() {
  
  
}
void volt5(){
  pinMode(pin4, INPUT); //floating pin 4 =>D+ = 0.6V
  pinMode(pin5, OUTPUT); 
  digitalWrite(pin5, LOW); //D-=xap xi 0V => Vout = 5V
  }
void volt12(){
  pinMode(pin4, INPUT); //floating pin 4 =>D+ = 0.6V
  pinMode(pin5, INPUT); //floating pin 5 =>D- = 0.6V =>Vout = 12v
  }
void volt9(){
  pinMode(pin4, OUTPUT);
  digitalWrite(pin4, HIGH); //D+= 3v3 
  pinMode(pin5, INPUT); //floating pin 5 =>D- = 0.6V => Vout = 9V
  }
void continuous(){
  pinMode(pin5, OUTPUT);
  digitalWrite(pin5, HIGH); // D- = 3.3V
  pinMode(pin4, INPUT); // D+ =0.6V
  }
void inc1v(){
  //tang 1v => tang 5 lan 0.2v
  for(int i = 1; i<=5; i++){
    pinMode(pin4, OUTPUT);
  digitalWrite(pin4, HIGH); // D+ = 3.3V
  delay(10);
  pinMode(pin4, INPUT); // D+ = 0,6V
  delay(10);
    }
  }
void dec1v(){
  //giam 1v => giam 5 lan 0.2v
  for(int i = 1; i<=5; i++){
    pinMode(pin5, OUTPUT);
  digitalWrite(pin5, LOW); // D- = 0.6V
  delay(10);
  digitalWrite(pin5,HIGH); // D- = 3.3V
  delay(10);
    }
  }
