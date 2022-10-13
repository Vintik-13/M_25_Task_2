#include "Kbd.h"

void input(int* buf, int size_buf) {
	int date;
	for (int i = 0; i < size_buf; i++) {
		std::cout << "Input date: ";
		std::cin >> date;
		std::cin.ignore(10, '\n');
		myname::write(buf, date, i);
	}
}

