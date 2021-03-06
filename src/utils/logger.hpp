/***********************************************************************
Copyright (C) rabbit1989 2015

https://github.com/rabbit1989/rabbit_engine

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*************************************************************************
                   header file: logger class
*************************************************************************/

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <cstdio>
#include <cstring>

#include "consts.hpp"
#include "uncopyable.hpp"
#include <stdarg.h>

namespace rabbit{

    class logger: uncopyable{
    public:
        static void set_log_level(LEVEL level){ _level = level;}
        static void set_file(FILE* file){ _file = file; }
        static void info(const char* format_str, ...);
        static void warn(const char* format_str, ...);
        static void fatal(const char* format_str, ...);
        static void init();
    private:
        static void _print(LEVEL level, const char* format_str, va_list args);
        static LEVEL _level;
        static FILE *_file;
        logger();
    };
}

#endif // LOGGER_HPP
