#include <Servo.h>

Servo base,fArm,rArm,claw;


int  basePos = 90; //初始角度为电机角度值
int  fArmPos = 90;
int  rArmPos = 90;
int  clawPos = 90;

const int baseMin = 0; //存储电机极限值，不变，只读状态
const int baseMax = 180; //角度可调

const int fArmMin = 35;
const int fArmMax = 120;

const int rArmMin = 45;
const int rArmMax = 180;

const int clawMin = 25;
const int clawMax = 100;

void setup() {
  // put your setup code here, to run once:
base.attach(11);
delay(200);
fArm.attach(10);
delay(200);
rArm.attach(9);
delay(200);
claw.attach(6);
delay(200);
Serial.begin(9600);
Serial.println("Welcome to Taichi-Maker Robot Arm Tutorial");
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available()>0)
  {
    char serialCmd = Serial.read();         //使用串口监视器输入电机指令控制机械臂电机
      armDataCmd(serialCmd);               //b45,底盘舵机转45度
    }
    base.write(basePos);
    delay(10);
     fArm.write(fArmPos);
    delay(10);
     rArm.write(rArmPos);
    delay(10);
     claw.write(clawPos);
    delay(10);
}

void  armDataCmd(char serialCmd)  //b45
  {
    Serial.print("serialCmd = ");
    Serial.print(serialCmd);
  //serialCmd:b
  //servoData:45
    int servoData = Serial.parseInt();
    switch(serialCmd)
      {
        case 'b':
        basePos = servoData;
        Serial.print("Set base servo value : ");
        Serial.println(servoData);
        break;

        case 'c':
        clawPos = servoData;
        Serial.print("Set claw servo value : ");
        Serial.println(servoData);
        break;
        
        case 'f':
        fArmPos = servoData;
        Serial.print("Set fArm servo value : ");
        Serial.println(servoData);
        break;

        case 'r':
        rArmPos = servoData;
        Serial.print("Set rArm servo value : ");
        Serial.println(servoData);
        break;

        case 'o':
        reportStatus();
        break;
        
        default:
        Serial.print(" Unknown Command. ");
        
        }
    }


 void reportStatus()
   {
    Serial.println("");
    Serial.println("");
    Serial.println(" +++++ Robot_Arm Status Report +++++");
    }
