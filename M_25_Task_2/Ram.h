#pragma once


#include "Cpu.h"
#include "Kbd.h"
#include "Gpu.h"
#include "Disk.h"

namespace myname {
	void write(int* buf, int a, int pos);

	int read(int* buf, int pos);
}

