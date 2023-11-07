#include <iostream>

#include "dates.h"

using namespace std;

tm *date_now() {
    time_t t = time(0);
    tm *now = localtime(&t);
    return now;
}

void log_time(const char *time) {
    clog << "🚀 The time is " << time << endl;
}

char *parse_time_str(tm *date) {
    char *result = (char *)malloc(9);
    if (result == NULL) {
        snprintf(result, 9, "!NOTIME!");
        return result;
    }
    snprintf(result, 9, "%02d:%02d:%02d", date->tm_hour, date->tm_min, date->tm_sec);
    return result;
}

const char *get_time_str() {
    tm *now = date_now();
    const char *time = parse_time_str(now);
    return time;
}
