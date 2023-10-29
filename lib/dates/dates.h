#ifndef DATES_H
#define DATES_H

#include <ctime>

std::tm *date_now();

void log_time(const char *time);

char *parse_time_str(tm *date);

#endif
