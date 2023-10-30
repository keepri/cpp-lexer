#ifndef LOGGER_H
#define LOGGER_H

#include "../dates/dates.h"
#include <iostream>

using namespace std;

class Log {
    public:
        typedef uint8_t Level;
        typedef const char *Separator;
        typedef const char *Header;

        static Log& get() {
            static Log log;
            return log;
        }

        static const Level EMERGENCY = 0;
        static const Level ALERT = 1;
        static const Level CRITICAL = 2;
        static const Level ERROR = 3;
        static const Level WARNING = 4;
        static const Level NOTICE = 5;
        static const Level INFO = 6;
        static const Level DEBUG = 7;
        static const Level SILLY = 8;

        Log& set_level(const Level level);
        void emerg(const char *message);
        void alert(const char *message);
        void crit(const char *message);
        void error(const char *message);
        void warn(const char *message);
        void notice(const char *message);
        void info(const char *message);
        void debug(const char *message);
        void silly(const char *message);

    private:
        Log(const Level level = INFO) : m_log_level(level) {}
        Log(const Log&) = delete;
        void operator=(const Log&) = delete;

        Level m_log_level;
        static Separator m_sep;
        static Header m_emerg_icon;
        static Header m_emerg_header;
        static Header m_alert_icon;
        static Header m_alert_header;
        static Header m_crit_icon;
        static Header m_crit_header;
        static Header m_error_icon;
        static Header m_error_header;
        static Header m_warning_icon;
        static Header m_warning_header;
        static Header m_notice_icon;
        static Header m_notice_header;
        static Header m_info_icon;
        static Header m_info_header;
        static Header m_debug_icon;
        static Header m_debug_header;
        static Header m_silly_icon;
        static Header m_silly_header;

        static const char *get_time_str() {
            tm *now = date_now();
            const char *time = parse_time_str(now);
            return time;
        }

        static void print(const char *icon, const char *header, const char *message) {
            const char *time = get_time_str();
            uint len = 5 + strlen(icon) + strlen(time) + strlen(header) + strlen(m_sep) + strlen(message);
            char out[len];
            snprintf(out, len, "%s %s %s %s %s", icon, time, header, m_sep,  message);
            clog << out << endl;
        }
};

#endif
