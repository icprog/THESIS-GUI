#include "pid.hpp"

#include <string>
#include <iostream>
#include <fstream>


PID::PID(): 
error_(0),
kp_(0),
ki_(0),
kd_(0),
							
lastInput_(0),
output_(0),

proportional(0),
integral(0),
derivative(0),

period_(0),
					
minOutput_(0),
maxOutput_(180)
{
}

void
PID::compute(double input)
{
	proportional = input;
	integral = integral +  input * period_ ;
	derivative = (input - lastInput_) / period_;

	output_ = kp_ * proportional + ki_ * integral + kd_ * derivative;

	lastInput_ = input;
}

double
PID::getOutput(double offset)
{
	if (output_ > maxOutput_)
		return maxOutput_ + offset;
	else if (output_ < minOutput_)
		return minOutput_ + offset;
	else
		return output_ + offset;
}
void
PID::setPIDParam(double kp, double ki, double kd, double scale)
{
	kp_ = kp * scale;
	ki_ = ki * scale;
	kd_ = ki * scale;
}
void
PID::setPIDOutputLimit(double min, double max)
{
	minOutput_ = min;
	maxOutput_ = max;
}
void
PID::setPIDPeriod(double period)
{
	period_ = period;
}
