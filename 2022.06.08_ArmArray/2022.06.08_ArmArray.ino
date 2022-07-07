#include <Servo.h>

Servo base,fArm,rArm,claw;
/*
int data1 = 0;
int data2 = 45;
int data3 = 90;
int data4 = 135;
int data5 = 180;
*/


/*
int data1[5] = {0,45,90,135,180};
int data2[5] = {45,0,90,180,135};
int data3[5] = {0,40,500,175,180};
int data4[5] = {0,55,10,125,170};
*/

int data2dArray[4][5] = {
    {0,45,90,135,180},         //逗号结尾
    {45,0,90,180,135},
    {0,40,500,175,180},
    {0,55,10,125,170}
  };                   //分号不可少

void setup() {
  // put your setup code here, to run once:
  base.attach(11);
  rArm.attach(10);
  fArm.attach(9);
  claw.attach(6);

}

void loop() {
  // put your main code here, to run repeatedly:
for (int i=0;i<=4;i++)

  {
    base.write(data2dArray[0][i]);
    delay(500);
    rArm.write(data2dArray[1][i]);
    delay(500);
    fArm.write(data2dArray[2][i]);
    delay(500);
    claw.write(data2dArray[3][i]);
    delay(500);
    }

    for (int i=4;i>=0;i--)
  {
     base.write(data2dArray[0][i]);
    delay(500);
    rArm.write(data2dArray[1][i]);
    delay(500);
    fArm.write(data2dArray[2][i]);
    delay(500);
    claw.write(data2dArray[3][i]);
    delay(500);
    }


/*
 for (int i=0;i<=4;i++)

  {
    base.write(data1[i]);
    delay(500);
    rArm.write(data2[i]);
    delay(500);
    fArm.write(data3[i]);
    delay(500);
    claw.write(data4[i]);
    delay(500);
    }
    
 for (int i=4;i>=0;i--)
  {
    base.write(data1[i]);
    delay(500);
    rArm.write(data2[i]);
    delay(500);
    fArm.write(data3[i]);
    delay(500);
    claw.write(data4[i]);  
    delay(500);
    }

*/
    
  /*
for (int i=0;i<=4;i++)

  {
    base.write(data[i]);
    rArm.write(data[i]);
    fArm.write(data[i]);
    claw.write(data[i]);
    delay(500);
    }
for (int i=4;i>=0;i--)

  {
    base.write(data[i]);
    rArm.write(data[i]);
    fArm.write(data[i]);
    claw.write(data[i]);  
    delay(500);
    }
    */
    
/*
 base.write(data[0]);
 delay(500);
 base.write(data[1]);
 delay(500);
 base.write(data[2]);
 delay(500);
 base.write(data[3]);
 delay(500);
 base.write(data[4]);
 delay(500);


 base.write(data[4]);
 delay(500);
 base.write(data[3]);
 delay(500);
 base.write(data[2]);
 delay(500);
 base.write(data[1]);
 delay(500);
 base.write(data[1]);
 delay(500);
 */
}
