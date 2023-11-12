#include <iostream>

#include "logger.h"

using namespace std;

Log::Separator Log::m_sep = "~";
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
    return Log::get();
}

void Log::emerg(const char *message) {
    if (m_log_level >= EMERGENCY) {
        Log::print(get_time_str(), m_emerg_icon, m_emerg_header, m_sep, message);
    }
}

void Log::alert(const char *message) {
    if (m_log_level >= ALERT) {
        Log::print(get_time_str(), m_alert_icon, m_alert_header, m_sep, message);
    }
}

void Log::crit(const char *message) {
    if (m_log_level >= CRITICAL) {
        Log::print(get_time_str(), m_crit_icon, m_crit_header, m_sep, message);
    }
}

void Log::error(const char *message) {
    if (m_log_level >= ERROR) {
        Log::print(get_time_str(), m_error_icon, m_error_header, m_sep, message);
    }
}

void Log::warn(const char *message) {
    if (m_log_level >= WARNING) {
        Log::print(get_time_str(), m_warning_icon, m_warning_header, m_sep, message);
    }
}

void Log::notice(const char *message) {
    if (m_log_level >= NOTICE) {
        Log::print(get_time_str(), m_notice_icon, m_notice_header, m_sep, message);
    }
}

void Log::info(const char *message) {
    if (m_log_level >= INFO) {
        Log::print(get_time_str(), m_info_icon, m_info_header, m_sep, message);
    }
}

void Log::debug(const char *message) {
    if (m_log_level >= DEBUG) {
        Log::print(get_time_str(), m_debug_icon, m_debug_header, m_sep, message);
    }
}

void Log::silly(const char *message) {
    if (m_log_level >= SILLY) {
        Log::print(get_time_str(), m_silly_icon, m_silly_header, m_sep, message);
    }
}
