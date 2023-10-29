#include <iostream>

#include "../dates/dates.h"
#include "logger.h"

using namespace std;

Log::Header Log::m_emerg_header = " 🆘 [EMERGENCY] - ";
Log::Header Log::m_alert_header = " 🚨 [ALERT] - ";
Log::Header Log::m_crit_header = " ❗️ [CRITICAL] - ";
Log::Header Log::m_error_header = " 🔴 [ERROR] - ";
Log::Header Log::m_warning_header = " 🟡 [WARN] - ";
Log::Header Log::m_notice_header = " ✋ [NOTICE] - ";
Log::Header Log::m_info_header = " 🔵 [INFO] - ";
Log::Header Log::m_debug_header = " 🐞 [DEBUG] - ";
Log::Header Log::m_silly_header = " 🤪 [SILLY] - ";

const char *Log::get_time_str() {
    tm *now = date_now();
    const char *time = parse_time_str(now);
    return time;
}

void Log::set_level(const Level level) {
    m_log_level = level;
}

void Log::print(const char *message, const char *header) {
    clog << Log::get_time_str() << header << message << endl;
}

void Log::emerg(const char *message) {
    if (m_log_level >= EMERG) {
        Log::print(message, m_emerg_header);
    }
}

void Log::alert(const char *message) {
    if (m_log_level >= ALERT) {
        Log::print(message, m_alert_header);
    }
}

void Log::crit(const char *message) {
    if (m_log_level >= CRIT) {
        Log::print(message, m_crit_header);
    }
}

void Log::error(const char *message) {
    if (m_log_level >= ERROR) {
        Log::print(message, m_error_header);
    }
}

void Log::warn(const char *message) {
    if (m_log_level >= WARNING) {
        Log::print(message, m_warning_header);
    }
}

void Log::notice(const char *message) {
    if (m_log_level >= NOTICE) {
        Log::print(message, m_notice_header);
    }
}

void Log::info(const char *message) {
    if (m_log_level >= INFO) {
        Log::print(message, m_info_header);
    }
}

void Log::debug(const char *message) {
    if (m_log_level >= DEBUG) {
        Log::print(message, m_debug_header);
    }
}

void Log::silly(const char *message) {
    if (m_log_level >= SILLY) {
        Log::print(message, m_silly_header);
    }
}
