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
    The implementation of vector, for practice purpose
*************************************************************************/
#ifndef VECTOR_HPP
#define VECTOR_HPP


#include <cstdio>

namespace rabbit{

template<class T>
class vector {
public:
    vector<T>();
    vector<T>(int);
    vector<T>(vector<T> &);
    vector<T>& operator =(vector<T>&);
    void push_back(T&);
    unsigned int size(){return _size;}
    unsigned int capacity(){return _capacity;}
    T& at(int);
    void clear();
    ~vector<T>();

private:
    T* _data;
    unsigned _size;
    unsigned _capacity;
};

template<class T>
vector<T>::vector<T>(): _size(0),_capacity(4) {
    _data = new T[4];
}

template<class T>
vector<T>::vector<T>(int size): _size(0), _capacity(size) {
    _data = new T[size];
}

template<class T>
vector<T>::~vector<T>(){
    delete [] _data;
}

}

#endif // VECTOR_HPP
