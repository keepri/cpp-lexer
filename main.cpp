#include <iostream>

#include "lib/dates/dates.h"
#include "lib/logger/logger.h"

using namespace std;

int main(int argc, char *argv[]) {
    Log logger(Log::DEBUG);

    tm *date = date_now();
    const char *time = parse_time_str(date);
    log_time(time);

    logger.info("Hello, world!");

    return 0;
}
