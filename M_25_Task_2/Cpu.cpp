#include "Cpu.h"

int sum(int* buf, int size_buf) {
	int tmp{ 0 };
	for (int i = 0; i < size_buf; i++)
		tmp += myname::read(buf, i);
	return tmp;
}
