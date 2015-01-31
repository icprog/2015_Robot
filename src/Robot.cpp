#include "WPILib.h"
#include "RobotMap.h"

class Robot: public IterativeRobot
{
	RobotDrive tank;	//normal drive wheels tank drive
	CANTalon lift;
	Victor fStrafe1, fStrafe2, bStrafe1, bStrafe2;	//lift and 4 strafe motors
	Joystick lStick, rStick, liftStick;
	Solenoid Cylinder;	//solenoids that control strafing wheel height
	Ultrasonic echo;
	//CameraServer camera;
	float frontVal = 0;
	float rearVal = 0;
	float leftJoyX = 0;
	float leftJoyY = 0;
	float rightJoyX = 0;
	float rightJoyY = 0;
	float liftJoy = 0;

public:
	Robot():
		tank(LEFT_MOTOR_1, LEFT_MOTOR_2, RIGHT_MOTOR_1, RIGHT_MOTOR_2),
		lift(0),
		fStrafe1(FRONT_STRAFE_MOTOR_1),
		fStrafe2(FRONT_STRAFE_MOTOR_2),
		bStrafe1(BACK_STRAFE_MOTOR_1),
		bStrafe2(BACK_STRAFE_MOTOR_2),
		lStick(LTANK_JOY_USB),
		rStick(RTANK_JOY_USB),
		liftStick(LIFT_JOY_USB),
		Cylinder(FRONT_CYLINDER),
		//camera()
		echo(0, 1, Ultrasonic::DistanceUnit::kInches)
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
	leftJoyX = lStick.GetX();
	leftJoyY = lStick.GetY();
	rightJoyX = rStick.GetX();
	rightJoyY = rStick.GetY();
	liftJoy = liftStick.GetY();

	if ((lStick.GetRawButton(1)) || (rStick.GetRawButton(1))) {
		frontVal = leftJoyX;
		rearVal = -rightJoyX;
		Cylinder.Set(true);
		tank.TankDrive(0.0 ,0.0 ,false);
	}
	else {
		Cylinder.Set(false);
		tank.TankDrive(leftJoyY, rightJoyY, false);
		frontVal = 0.0;
		rearVal = 0.0;
	}

	echo.Ping();
	printf("%f \n", echo.GetRangeInches());










/*
	//when strafing left
	if(lStick.GetRawButton(3))
	{
		frontVal = 1;
		rearVal = -1;
		Cylinder.Set(true);
	}
	//strafing right
	else if (rStick.GetRawButton(3))
	{
		frontVal = -1;
		rearVal = 1;
		Cylinder.Set(true);
	}
	//no strafing, normal tank drive
	else
	{
		frontVal = 0;
		rearVal = 0;
		Cylinder.Set(false);
		tank.TankDrive(-leftJoyY, -rightJoyY, true);

	}*/

	//motors are always "running", but only actually do anything when the values don't equal 0
	fStrafe1.Set(frontVal);
	fStrafe2.Set(frontVal);
	bStrafe1.Set(rearVal);
	bStrafe2.Set(rearVal);

	lift.Set(-liftJoy);
}

void TestPeriodic()
{

}
};

START_ROBOT_CLASS(Robot);
