#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

#include "../dates/dates.h"

class Log {
    public:
        typedef uint8_t Level;
        typedef const char Separator;
        typedef const char *Icon;
        typedef const char *Header;

        enum LogLevel {
            EMERGENCY,
            ALERT,
            CRITICAL,
            ERROR,
            WARNING,
            NOTICE,
            INFO,
            DEBUG,
            SILLY,
        };

        static Log &get() {
            static Log log;
            return log;
        }

        Log &set_level(const Level level) {
            m_log_level = level;
            return get();
        }

        template <typename... Args> Log &toggle_print(Args... a) {
            const char *args[] = {a...};

            for (const char *component : args) {
                if (strcmp(component, "time") == 0) {
                    m_with_time = !m_with_time;
                    continue;
                }
                if (strcmp(component, "icon") == 0) {
                    m_with_icon = !m_with_icon;
                    continue;
                }
                if (strcmp(component, "header") == 0) {
                    m_with_header = !m_with_header;
                    continue;
                }
                if (strcmp(component, "separator") == 0) {
                    m_with_sep = !m_with_sep;
                }
            }

            return get();
        }

        template <typename... Args> void emerg(Args... args) {
            if (m_log_level >= EMERGENCY) {
                print(args...);
            }
        }

        template <typename... Args> void alert(Args... args) {
            if (m_log_level >= ALERT) {
                print(m_alert_icon, m_alert_header, args...);
            }
        }

        template <typename... Args> void crit(Args... args) {
            if (m_log_level >= CRITICAL) {
                print(m_crit_icon, m_crit_header, args...);
            }
        }

        template <typename... Args> void error(Args... args) {
            if (m_log_level >= ERROR) {
                print(m_error_icon, m_error_header, args...);
            }
        }

        template <typename... Args> void warn(Args... args) {
            if (m_log_level >= WARNING) {
                print(m_warning_icon, m_warning_header, args...);
            }
        }

        template <typename... Args> void notice(Args... args) {
            if (m_log_level >= NOTICE) {
                print(m_notice_icon, m_notice_header, args...);
            }
        }

        template <typename... Args> void info(Args... args) {
            if (m_log_level >= INFO) {
                print(m_info_icon, m_info_header, args...);
            }
        }

        template <typename... Args> void debug(Args... args) {
            if (m_log_level >= DEBUG) {
                print(m_debug_icon, m_debug_header, args...);
            }
        }

        template <typename... Args> void silly(Args... args) {
            if (m_log_level >= SILLY) {
                print(m_silly_icon, m_silly_header, args...);
            }
        }

    private:
        Log(const Level level = INFO) : m_log_level(level) {}
        Log(const Log &) = delete;
        void operator=(const Log &) = delete;

        Level m_log_level;
        Separator m_sep = '~';
        Icon m_emerg_icon = "🆘";
        Header m_emerg_header = "[EMERGENCY]";
        Icon m_alert_icon = "🚨";
        Header m_alert_header = "[ALERT]";
        Icon m_crit_icon = "❗️";
        Header m_crit_header = "[CRITICAL]";
        Icon m_error_icon = "🔴";
        Header m_error_header = "[ERROR]";
        Icon m_warning_icon = "🟡";
        Header m_warning_header = "[WARN]";
        Icon m_notice_icon = "✋";
        Header m_notice_header = "[NOTICE]";
        Icon m_info_icon = "🔵";
        Header m_info_header = "[INFO]";
        Icon m_debug_icon = "🐞";
        Header m_debug_header = "[DEBUG]";
        Icon m_silly_icon = "🤪";
        Header m_silly_header = "[SILLY]";
        bool m_with_time = true;
        bool m_with_icon = true;
        bool m_with_header = true;
        bool m_with_sep = true;

        template <typename... Args> void print(Icon icon, Header header, Args... a) {
            using std::clog, std::endl;

            const char *args[] = {a...};
            size_t num_args = sizeof...(a);

            size_t total_length = 0;
            for (size_t i = 0; i < num_args; i++) {
                total_length += strlen(args[i]);
            }
            char out[total_length + num_args];

            char *p_out = out;
            for (size_t i = 0; i < num_args; ++i) {
                const char *arg = args[i];
                size_t arg_len = strlen(arg);

                memcpy(p_out, arg, arg_len);
                p_out += arg_len;

                if (i < num_args - 1) {
                    *p_out++ = ' ';
                }
            }
            *p_out = '\0';

            if (m_with_icon)
                clog << icon << " ";
            if (m_with_time)
                clog << get_time_str() << " ";
            if (m_with_header)
                clog << header << " ";
            if (m_with_sep)
                clog << m_sep << " ";
            clog << out << endl;
        }
};

#endif
