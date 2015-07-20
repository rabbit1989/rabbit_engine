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

namespace rabbit{
    int const ERROR_DEFAULT = 100;
    int const ERROR_INDEX_OUT_OF_RANGE = 101;

    class exception{
    public:
        exception(){
            _err_code = ERROR_DEFAULT;
            _print();
        }

        exception(int const code) {
            _err_code = code;
            _print();
        }

    private:
        void _print(){
            switch(_err_code){
                case ERROR_INDEX_OUT_OF_RANGE: fprintf(stderr, "exception : index out of range"); break;
                default: fprintf(stderr, "exception: unknown error");
            }
        }
        unsigned int _err_code;
    };
}
