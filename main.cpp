#include <algorithm>
#include <iostream>

#include "lib/dates/dates.h"
#include "lib/logger/logger.h"

using namespace std;

int main(int argc, char *argv[]) {
    Log &log = Log::get().set_level(Log::SILLY);
    log.silly("Ok, we good!");
    return 0;
}
