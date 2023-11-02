#include <iostream>

#include "lib/dates/dates.h"
#include "lib/logger/logger.h"

using namespace std;

int main(int argc, char *argv[]) {
    Log::get().set_level(Log::DEBUG).debug("Hello, world!");
    return 0;
}
