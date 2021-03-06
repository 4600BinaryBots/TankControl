#pragma config(Hubs,  S4, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S4,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S4_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C2_1,     DrawerSlide1,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C2_2,     DrawerSlide2,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C3_1,     Left,          tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S4_C3_2,     Right,         tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S4_C4_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S4_C4_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S4_C4_3,    servo3,               tServoStandard)
#pragma config(Servo,  srvo_S4_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S4_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S4_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 _________  _______   ___       _______                  ________  ________
|\___   ___\\  ___ \ |\  \     |\  ___ \                |\   __  \|\   __  \
\|___ \  \_\ \   __/|\ \  \    \ \   __/|   ____________\ \  \|\  \ \  \|\  \
     \ \  \ \ \  \_|/_\ \  \    \ \  \_|/__|\____________\ \  \\\  \ \   ____\
      \ \  \ \ \  \_|\ \ \  \____\ \  \_|\ \|____________|\ \  \\\  \ \  \___|
       \ \__\ \ \_______\ \_______\ \_______\              \ \_______\ \__\
        \|__|  \|_______|\|_______|\|_______|               \|_______|\|__|

*/


#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

void drive();

void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.
	servoTarget[servo1] = 255;//240?
	servoTarget[servo2] = -50;
	servoTarget[servo3] = 100;
  return;
}



task main()
{
  initializeRobot();

  waitForStart();   // wait for start of tele-op phase

  while (true)
  {
	  drive();
  }
}

//Our main driving Function
void drive()
{

	getJoystickSettings(joystick); // update buttons and joysticks
	//motor values equal the joystick Y values
	motor[Left] = joystick.joy1_y1;
	motor[Right] = joystick.joy1_y2;


	if(joy1Btn(5) == 1)
	{
		// turn a motors power on or off
		servoTarget[servo1] = 255;
		servoTarget[servo2] = -50;
		wait1Msec(100);
	}
	else if(joy1Btn(7) == 1)
	{
		servoTarget[servo1] = -50;
		servoTarget[servo2] = 255;//-neg
		wait1Msec(100);
	}

		if(joy1Btn(8) == 1)
	{
		// turn a motors power on or off
		motor[DrawerSlide1] = -100;
		motor[DrawerSlide2] = -100;

	}
	else if(joy1Btn(6) == 1)
	{
		motor[DrawerSlide1] = 100;
		motor[DrawerSlide2] = 100;

	}
	else
	{
		motor[DrawerSlide1] = 0;
		motor[DrawerSlide2] = 0;
	}

	//servo drawer flap
	if(joy1Btn(1) == 1){
	 	servoTarget[servo3] = 150;
	}
	else if(joy1Btn(4) == 1){
		servoTarget[servo3] = 0;
	}
}
