#include <Servo.h>

Servo base,fArm,rArm,claw;  //建立4个电机对象
int dataIndex = 0;

void setup() {
  // put your setup code here, to run once:
  base.attach(11);
  rArm.attach(10);
  fArm.attach(9);
  claw.attach(6);
  Serial.begin(9600);
  Serial.println("Please input serial data.");
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available())
  {
    char servoName = Serial.read();//获取电机编号

    Serial.print("servoName = ");
    Serial.print(servoName);
    Serial.print("  ,  ");

    int data = Serial.parseInt(); //获取电机指令中电机角度信息

    switch (servoName)  // 根据编号对电机进行旋转
       {
        case 'b':       // b180  //电机指令b，设置base电机角度 
        base.write(data);
        Serial.print("Set base servo value: ");
        Serial.println(data);
        break;

        case 'r':       //电机指令f，设置base电机角度
        rArm.write(data);
        Serial.print("Set rArm servo value: ");
        Serial.println(data);
        break;

        case 'f':       //电机指令b，设置base电机角度
        fArm.write(data);
        Serial.print("Set rArm servo value: ");
        Serial.println(data);
        break;

        case 'c':       //电机指令b，设置base电机角度
        claw.write(data);
        Serial.print("Set claw servo value: ");
        Serial.println(data);
        break;
        }
    }
}
