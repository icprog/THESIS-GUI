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
	proportional = kp_ * input;
	integral = integral + ki_ * input * period_;
	derivative = kd_ * (input - lastInput_) / period_;

	lastInput_ = input;

	output_ = proportional + integral + derivative;
}

double
PID::getOutput()
{
	if (output_ > maxOutput_)
		return maxOutput_;
	else if (output_ < minOutput_)
		return minOutput_;
	else
		return output_;
}
void
PID::setPIDParam(double kp, double ki, double kd)
{
	kp_ = kp;
	ki_ = ki;
	kd_ = ki;
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
