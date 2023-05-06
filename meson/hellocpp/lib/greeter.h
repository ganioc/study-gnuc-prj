#pragma once

void print_greeting();
void print_trace(const char *function_name,
    const char *file_name,
    const int line_num);

#ifdef GREETING_TRACE
#define TRACE() print_trace(__PRETTY_FUNCTION__, \
    __FILE__, __LINE__)
#else
#define TRACE()

#endif