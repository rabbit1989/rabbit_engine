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
    The implementation of queue, for practice purpose
*************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "exception.hpp"
#include <cstring>

namespace rabbit{

template<class T, size_t SIZE = 20>
class queue{
public:
    queue();
    queue(size_t);
    queue(queue<T, SIZE>&);
    queue<T, SIZE>& operator=(queue<T, SIZE>&);
    ~queue();
    void push(T&);
    void pop();
    T& front();
    bool empty();
    bool full();

private:
    //init private members
    void _init(size_t);
    int _get_size(){ return _size; };
    //copy queue data
    void _copy(queue<T, SIZE>&);

private:
    T* _data;
    int _front, _rear;
    size_t _size;
};

template<class T, size_t SIZE>
queue<T, SIZE>::queue(){
    _init(SIZE);
}

template<class T, size_t SIZE>
queue<T, SIZE>::queue(size_t size){
    _init(size);
}

template<class T, size_t SIZE>
queue<T, SIZE>::queue(queue<T, SIZE>& q){
    _init(q._get_size());
    _copy(q);
}

template<class T, size_t SIZE>
queue<T, SIZE>& queue<T, SIZE>::operator=(queue<T, SIZE>& q){
    _init(q._get_size());
    _copy(q);
    return *this;
}

template<class T, size_t SIZE>
queue<T, SIZE>::~queue() {

    delete [] _data;
}

template<class T, size_t SIZE>
void queue<T, SIZE>::_init(size_t size){
    _data = new int[size];
    _front = 0;
    _rear = 0;
    _size = size;
}

template<class T, size_t SIZE>
void queue<T, SIZE>::_copy(queue<T, SIZE> &q) {
    size_t q_size = q._get_size();
    memcpy(_data, q._data, sizeof(T)*q_size);
    _size = q_size;
    _front = q._front;
    _rear = q._rear;
}

template<class T, size_t SIZE>
void queue<T, SIZE>::pop(){
    if (empty() == true)throw exception(QUEUE_IS_EMPTY);
    _rear = (_rear + 1) % _size;
}

template<class T, size_t SIZE>
T& queue<T, SIZE>::front() {
    if (empty() == true)throw exception(QUEUE_IS_EMPTY);
    return _data[_rear];
}

template<class T, size_t SIZE>
void queue<T, SIZE>::push(T& val){
    if (full() == true)throw exception(QUEUE_IS_FULL);
    _data[_front] = val;
    _front = (_front + 1) % _size;
}

template<class T, size_t SIZE>
bool queue<T, SIZE>::empty() {
   return _front == _rear;
}

template<class T, size_t SIZE>
bool queue<T, SIZE>::full() {

    return (_front + 1) % SIZE == _rear;
}

}

#endif // QUEUE_HPP
