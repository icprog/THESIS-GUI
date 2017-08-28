#ifndef PID_HPP
#define PID_HPP

#include <string>

// Input for pid is error(t) = x0 - x (difference beetwen required value (x0) and current value (x))
class PID
{
public:
	PID();
    void compute(double input);           // Computing the output signal
    double getOutput(double offset);                     // Get the output after computing
	void setPIDParam(double kp, double ki, double kd, double scale);
	void setPIDOutputLimit(double min, double max);
	void setPIDPeriod(double period);
private:
	double error_;
// P, I, D weights
    double kp_;                     
    double ki_;                     //
    double kd_;                     //
//initial for PID
	double lastInput_;              // Last input, given 1 period ago
    double output_;                 // Output after computing

	double proportional;
	double integral;
	double derivative;

    double period_;                 // Refreshing period in milliseconds
// limit output
    double minOutput_;              // Output is limited
    double maxOutput_;              //
};

#endif // PID_HPP