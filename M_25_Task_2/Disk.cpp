#include "Disk.h"

bool save(int* buf, int size_buf, const char* path) {
	std::ofstream ofs(path, std::ios::binary);
	if (ofs.is_open()) {
		for (int i = 0; i < size_buf; i++) 
			ofs.write((char*)(myname::read(buf, i)), sizeof(int));				
		return true;
	}
	else
		return false;
}

bool load(int* buf, const char* path)
{
	std::ifstream ifs(path, std::ios::binary);
	if (ifs.is_open()) {
		int size_file;
		ifs.seekg(0, ifs.end);
		size_file = ifs.tellg();
		ifs.seekg(0, ifs.beg);
		for (int i = 0; i < (size_file / sizeof(int)); i++)
			ifs.read((char*)(buf + i), sizeof(int));
		return true;
	}
	else
		return false;
}
