#include "iofile.hpp"

System::String^ printer(System::String^ name, int value) {
	return name + " "+ value.ToString();
}