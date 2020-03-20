#pragma once

#include <cstdlib>
#include <vector>
#include <cstdarg>

#define LogFuncDef(name, logLevel) \
    static void name(const char* tag, const char* text, ...) __attribute__ ((format (printf, 2, 3))) { \
        va_list args; \
        va_start(args, text); \
        mcpelauncher_vlog(logLevel, tag, text, args); \
        va_end(args); \
    }

enum class LogLevel {
    LOG_TRACE,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR
};

extern "C" void mcpelauncher_vlog(LogLevel level, const char* tag, const char* text, va_list args);
extern "C" void mcpelauncher_log(LogLevel level, const char* tag, const char* text, ...);

class Log {

public:
    LogFuncDef(trace, LogLevel::LOG_TRACE)
    LogFuncDef(debug, LogLevel::LOG_DEBUG)
    LogFuncDef(info, LogLevel::LOG_INFO)
    LogFuncDef(warn, LogLevel::LOG_WARN)
    LogFuncDef(error, LogLevel::LOG_ERROR)

};

#undef LogFuncDef
