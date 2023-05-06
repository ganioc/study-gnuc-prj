#include <iostream>

#include "greeter.h"

void print_greeting(){
    TRACE();
    std::cout << "Greeting ..." << std::endl;
    TRACE();
}

void print_trace(const char *function_name,
    const char *file_name,
    const int line_num)
{
    std::cout << "TRACE: "
            << function_name
            << ' '
            << file_name
            << " : "
            << line_num
            << '\n';
}