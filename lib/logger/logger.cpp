#include <iostream>

#include "logger.h"

using namespace std;

Log::Separator Log::m_sep = "-";
Log::Header Log::m_emerg_icon = "🆘";
Log::Header Log::m_emerg_header = "[EMERGENCY]";
Log::Header Log::m_alert_icon = "🚨";
Log::Header Log::m_alert_header = "[ALERT]";
Log::Header Log::m_crit_icon = "❗️";
Log::Header Log::m_crit_header = "[CRITICAL]";
Log::Header Log::m_error_icon = "🔴";
Log::Header Log::m_error_header = "[ERROR]";
Log::Header Log::m_warning_icon = "🟡";
Log::Header Log::m_warning_header = "[WARN]";
Log::Header Log::m_notice_icon = "✋";
Log::Header Log::m_notice_header = "[NOTICE]";
Log::Header Log::m_info_icon = "🔵";
Log::Header Log::m_info_header = "[INFO]";
Log::Header Log::m_debug_icon = "🐞";
Log::Header Log::m_debug_header = "[DEBUG]";
Log::Header Log::m_silly_icon = "🤪";
Log::Header Log::m_silly_header = "[SILLY]";

Log& Log::set_level(const Level level) {
    m_log_level = level;
    static Log& log = Log::get();
    return log;
}

void Log::emerg(const char *message) {
    if (m_log_level >= EMERGENCY) {
        Log::print(m_emerg_icon, m_emerg_header, message);
    }
}

void Log::alert(const char *message) {
    if (m_log_level >= ALERT) {
        Log::print(m_alert_icon, m_alert_header, message);
    }
}

void Log::crit(const char *message) {
    if (m_log_level >= CRITICAL) {
        Log::print(m_crit_icon, m_crit_header, message);
    }
}

void Log::error(const char *message) {
    if (m_log_level >= ERROR) {
        Log::print(m_error_icon, m_error_header, message);
    }
}

void Log::warn(const char *message) {
    if (m_log_level >= WARNING) {
        Log::print(m_warning_icon, m_warning_header, message);
    }
}

void Log::notice(const char *message) {
    if (m_log_level >= NOTICE) {
        Log::print(m_notice_icon, m_notice_header, message);
    }
}

void Log::info(const char *message) {
    if (m_log_level >= INFO) {
        Log::print(m_info_icon, m_info_header, message);
    }
}

void Log::debug(const char *message) {
    if (m_log_level >= DEBUG) {
        Log::print(m_debug_icon, m_debug_header, message);
    }
}

void Log::silly(const char *message) {
    if (m_log_level >= SILLY) {
        Log::print(m_silly_icon, m_silly_header, message);
    }
}
