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
                            utils.cpp
*************************************************************************/


#include "utils.hpp"
#include <windows.h>
#include <winBase.h>

namespace rabbit{

//print stack trace info
void stack_trace(){
/*
    TODO: for linux
    void* call_stack[128];
    const int n_max_frames = sizeof(call_stack)/sizeof(callstack[0]);
    int n_frame  = backtrace(call_stack, n_max_frames);
    char** symbols = backtrace_symbols(call_stack, n_frame);
    for (int i = 0; i < n_frame; i++)
        fprintf(stderr, "%s", symbol[i]);

    void *call_stack[TRACE_MAX_STACK_FRAMES];
    WORD n_frames = CaptureStackBackTrace(0, TRACE_MAX_STACK_FRAMES, call_stack, NULL);
*/
}

}