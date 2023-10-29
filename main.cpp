#include <iostream>

#include "lib/dates/dates.h"
#include "lib/logger/logger.h"

using namespace std;

int main(int argc, char *argv[]) {
    Log& log = Log::get();
    log.set_level(Log::DEBUG);
    log.debug("Hello, world!");

    return 0;
}
