#include "Ram.h"

namespace myname {
    void write(int* buf, int a, int pos) {
        *(buf + pos) = a;
    }

    int read(int* buf, int pos) {
        return *(buf + pos);
    }
}

