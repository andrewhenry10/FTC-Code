#pragma config(StandardModel, "RANGER")
 //*!!Code automatically generated by 'ROBOTC' configuration wizard           	!!*//
#include "JoystickDriver.c" //Joystick is included in this program
int threshold = 15; //to avoid unnecessary movement
int j1y1;
int j1y2;
int j1x1;
int j1x2;
int mSpeed = 1; //motor speed
 task main()
 {
  int threshold = 15; //to avoid unnecessary movement
   while(true) //infinite loop
   {
 	getJoystickSettings(joystick); //retrieves data from the joystick

 	j1y1 = joystick.joy1_y1;
 	j1x1 = joystick.joy1_x1;
 	j1y2 = joystick.joy1_y2;
 	j1x2 = joystick.joy1_x2;
 	if(abs(joystick.joy1_y1) > threshold)
 	{
   	motor[motorD] = joystick.joy1_y1 * -1; //y1 controller moves motorD
 	}
 	else
 	{
   	motor[motorD] = 0;
 	}
 	if(abs(joystick.joy1_y2) > threshold)
 	{
   	motor[motorE] = joystick.joy1_y2 * -1; //y2 controller moves motorE
 	}
 	else
 	{
   	motor[motorE] = 0;
 	}
 	//Detection for buttons such as a, b, x, y
 	int dis_cm = 15;

 	if(joy1Btn(7) == 1){
 	while(SensorValue[S4] > dis_cm)
 	motor[motorD] = 50;
 	motor[motorE] = 50;
    }
  joystick.joy1_TopHat;
 	if(joy1_TopHat == 0){
 	wait1Msec(10);
      servo[servo2] = servo[servo2]-mSpeed;
    } else if(joy1_TopHat == 4){
      wait1Msec(10);
     servo[servo2] = servo[servo2]+mSpeed;
    } if(joy1_TopHat == 6){
 	 wait1Msec(10);
      servo[servo1] = servo[servo1]-mSpeed;
    } else if(joy1_TopHat == 2){
      wait1Msec(10);
     servo[servo1] = servo[servo1]+mSpeed;
    }
    getJoystickSettings(joystick); //retrieves data from the joystick
 	/*if(abs(joystick.joy1_y1) > threshold)
 	{
   	motor[motorD] = (joystick.joy1_y1 * -); //y1 controller moves motorD
 	}
 	else
 	{
   	motor[motorD] = 0;
 	}
 	if(abs(joystick.joy1_y2) > threshold)
 	{
 	 motor[motorE] = joystick.joy1_y2; //y2 controller moves motorE
 	}
 	else
 	{
   	motor[motorE] = 0;
 	}*/


 	//Reset ze motor

  }
 }
