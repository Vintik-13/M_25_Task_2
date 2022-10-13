#include "Gpu.h"
#include <iostream>

void display(int sum) {
	std::cout << myname::read(&sum, 0) << std::endl;;
}
