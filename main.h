#pragma once

// #ifndef _MAIN_H_
// #define _MAIN_H_

struct FOO
{
    char a;
    char b[];
};

#define debug(format, ...) fprintf(stderr, format, __VA_ARGS__)

// #endif