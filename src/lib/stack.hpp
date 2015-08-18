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
    The implementation of stack, for practice purpose
*************************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

namespace rabbit{

template<class T>
class stack{
public:
    void push(T&);
    void pop();
    T& top();
    bool empty();
    size_t size();
private:
    rabbit::vector<T> _data;
};

template<class T>
void stack<T>::push(T& value){
    _data.push_back(value);
}

template<class T>
bool stack<T>::empty(){
    return _data.size() <= 0;
}

template<class T>
void stack<T>::pop(){
    _data.pop_back();
}

template<class T>
T& stack<T>::top(){
    if (_data.size() <= 0) throw exception(INDEX_OUT_OF_RANGE);
    return _data.back();
}

template<class T>
size_t stack<T>::size(){
    return _data.size();
}

}

#endif // STACK_HPP
