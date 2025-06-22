#define Vcc 5
#define R1 1 //in kOhms


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int Vin = analogRead(A1);
  float Rvoltage = Vin*(5/1023.0);
  Serial.println(Rvoltage);
  delay(1500);
  double calc_R = Resistance(Rvoltage);
  Serial.print("Rx = ");
  Serial.println(calc_R);
  double rounded_res = RoundUP(calc_R);
  Serial.print("Value from table is(in kOhms):");
  Serial.println(rounded_res);

}

double Resistance(float VtpPlus){
  return R1*(1/(Vcc/VtpPlus-1));
}

double RoundUP(double R){
  double common_resistor_values[] = {0.1,0.33,0.47,0.22,       //hundreds ohms
                   1.0, 1.1, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2, 2.4, 2.7, 3.0, 3.3, 3.6, 3.9, 4.3, 4.7, 5.1, 5.6, 6.2, 6.8, 7.5, 8.2, 9.1,  //kilo ohms
                   10,15,20,22,30,33,39,43,47,51,56,62,68,75,82,91,100,220,240,300,1000};   //kilo ohms
  int len = sizeof(common_resistor_values)/4;
  double tolerance = 10;
  double suggested = 1;
  //Serial.println(len);
  for(int i =0;i<=len;i++){
    if(abs(R - common_resistor_values[i]) <= tolerance ){
      suggested = common_resistor_values[i];
      tolerance = abs(R - common_resistor_values[i]);
    }
  }

  return suggested;
}