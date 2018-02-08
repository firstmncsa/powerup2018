// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ctre/Phoenix.h"


#include "Drivetrain.h"
#include "../RobotMap.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/DriveRobot.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Drivetrain::Drivetrain() : frc::Subsystem("Drivetrain") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    leftFront = RobotMap::drivetrainleftFront;
    leftRear = RobotMap::drivetrainleftRear;
    leftDrive = RobotMap::drivetrainleftDrive;
    rightFront = RobotMap::drivetrainrightFront;
    rightRear = RobotMap::drivetrainrightRear;
    rightDrive = RobotMap::drivetrainrightDrive;
    differentialDrive = RobotMap::drivetrainDifferentialDrive;
    frontUltrasonic = RobotMap::drivetrainfrontUltrasonic;
    rearUltrasonic = RobotMap::drivetrainRearUltrasonic;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	// Open up a NetworkTables connection to the powerup-gss server and grab the game data.
	// Note: This should probably be split into multiple parts or perhaps into it's own subsystem so we
	// re-use the same connection to NT vs building, grab and destroy every time.
	GSSinst = nt::NetworkTableInstance::Create();
	GSSinst.StartClient("10.0.100.5",1735);
	GSSinst.AddLogger({}, 0, 99);
}

void Drivetrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new DriveRobot());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Drivetrain::Periodic() {
    // Put code here to be run every loop

}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drivetrain::Drive(std::shared_ptr<frc::Joystick> joystick) {
	// For now we are just going to call arcadeDrive with squared inputs.
	// Eventually we will call curvatureDrive or arcadeDrive with and without squared input as needed or desired by the driver.
	differentialDrive->ArcadeDrive(joystick->GetY(), joystick->GetX(), true);
}

std::string Drivetrain::getGameSpecificMessage() {
	// Return the switch & scale data pulled from the NetworkTable entry.
	return GSSinst.GetTable("OffseasonFMSInfo")->GetEntry("GameData").GetString("defaultValue");
}
