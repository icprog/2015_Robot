#include "WPILib.h"

class Robot: public IterativeRobot
{
	RobotDrive tank; //normal drive wheels tank drive
	Joystick lStick, rStick, liftStick;
	//Talon fMiddle, bMiddle; //strafe motors
	Talon lift1, lift2;
	//int frontVal = 0;
	//int rearVal = 0;
	double leftJoy = 0;
	double rightJoy = 0;
	//Solenoid front, back;

public:
	Robot() :
			tank(0, 1, 8, 9),
			lStick(0),
			rStick(1),
			liftStick(2),
			lift1(6),
			lift2(7)
			//fMiddle(6),
			//bMiddle(7),
			//front(1),
			//back(2)
	{
		tank.SetExpiration(0.1);
	}

void RobotInit()
{

}

void AutonomousInit()
{

}

void AutonomousPeriodic()
{

}

void TeleopInit()
{

}

void TeleopPeriodic()
{
	leftJoy = lStick.GetY();
	rightJoy = rStick.GetY();
	tank.TankDrive(-leftJoy, -rightJoy, true);
	lift1.Set(liftStick.GetY());
	lift2.Set(liftStick.GetY());

/*
	if(lStick.GetRawButton(3))
	{
		frontVal = 1;
		rearVal = -1;
		front.Set(true);
		back.Set(true);
	}
	else if (rStick.GetRawButton(3))
	{
			frontVal = -1;
			rearVal = 1;
			front.Set(true);
			back.Set(true);
	}
	else
		{
			frontVal = 0;
			rearVal = 0;
			front.Set(false);
			back.Set(false);
			tank.TankDrive(-leftJoy, -rightJoy, true);

		}

	fMiddle.Set(frontVal);
	bMiddle.Set(rearVal);
*/

}

void TestPeriodic()
{

}
};

START_ROBOT_CLASS(Robot);
