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
                   logger class
*************************************************************************/

#include "logger.hpp"

namespace rabbit{

    LEVEL logger::_level = INFO;
    FILE* logger::_file = 0;

    /**
        initialization of logger. Must be called!
    */
    void logger::init(){
        set_log_level(INFO);
        set_file(0);
    }

    void logger::info(const char *format_str, ...){
        va_list args;
        va_start(args, format_str);
        _print(INFO, format_str, args);
        va_end(args);
    }

    void logger::warn(const char *format_str, ...){
        va_list args;
        va_start(args, format_str);
        _print(WARN, format_str, args);
        va_end(args);
    }

    void logger::fatal(const char *format_str, ...){
        va_list args;
        va_start(args, format_str);
        _print(FATAL, format_str, args);
        va_end(args);
    }
    void logger::_print(LEVEL level, const char *format_str, va_list args){
        if(_level <= level) {
//          if (_file == 0) throw exception (FILE_IS_INVALID);
            if (_file == 0) {
                _file = stderr;
            }
            vfprintf(_file, format_str, args);
            fprintf(_file, "\n");
        }
    }
}

