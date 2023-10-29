#ifndef LOGGER_H
#define LOGGER_H

class Log {
    public:
        typedef int Level;
        typedef const char* Header;

        static Log& get(Level level = INFO) {
            static Log logger(level);
            return logger;
        }

        static const Level EMERG = 0;
        static const Level ALERT = 1;
        static const Level CRIT = 2;
        static const Level ERROR = 3;
        static const Level WARNING = 4;
        static const Level NOTICE = 5;
        static const Level INFO = 6;
        static const Level DEBUG = 7;
        static const Level SILLY = 8;

        const char *get_time_str();
        void set_level(const Level level);
        void print(const char* message, const char *header);
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
        Level m_log_level;
        static Header m_emerg_header;
        static Header m_alert_header;
        static Header m_crit_header;
        static Header m_error_header;
        static Header m_warning_header;
        static Header m_notice_header;
        static Header m_info_header;
        static Header m_debug_header;
        static Header m_silly_header;

        Log(const Level level = INFO) : m_log_level(level) {}
        Log(const Log&) = delete;
        void operator=(const Log&) = delete;
};

static Log& make_logger();

#endif
