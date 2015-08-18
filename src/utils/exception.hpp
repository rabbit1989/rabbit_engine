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
                a simple exception class
*************************************************************************/

#include<cstdio>
#include"utils.hpp"
#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP


#include "consts.hpp"
#include "logger.hpp"

namespace rabbit{

    class exception{
    public:
        exception(){
            _err_code = DEFAULT;
            _print();
        }

        exception(ERROR code) {
            _err_code = code;
            _print();
        }

    private:
        void _print(){
            switch(_err_code){
                case INDEX_OUT_OF_RANGE: logger::fatal("exception %d:   index out of range", _err_code); break;
                case FILE_IS_INVALID: logger::fatal("execption %d:  file pointer is invalid", _err_code); break;
                case QUEUE_IS_EMPTY: logger::fatal("exception %d:   queue is empty", _err_code); break;
                case QUEUE_IS_FULL: logger::fatal("exception %d: queue is full", _err_code); break;
                default: logger::fatal("exception: unknown error");
            }
            //print stack trace
            stack_trace();
        }
        ERROR _err_code;
    };
}
#endif // EXCEPTION_HPP
