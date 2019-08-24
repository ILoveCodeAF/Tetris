#include "queue.h"
#include <stdexcept>
//#define NULL (void*)0

template <class T>
Queue<T>::Queue(int size)
{
	this->_front = 0;
	this->_back = 1;
	this->max_size = size;
	this->_size = 0;
	this->buffer = new T[this->max_size+2];
}

template <class T>
void Queue<T>::free()
{
	if(this->buffer != NULL)
		delete(this->buffer);
}

template <class T>
bool Queue<T>::empty()
{
	return this->_size == 0;
}

template <class T>
bool Queue<T>::full()
{
	return this->_size == this->max_size;
}

template <class T>
void Queue<T>::push(T value)
{
	if(!this->full()){
		if(this->_back == this->max_size+2){
			this->_back = 0;
		}
		this->buffer[this->_back] = value;
		this->_back += 1;
		this->_size += 1;
	}
	else
		throw "Queue<>::push(): queue is full";
}

template <class T>
T Queue<T>::front()
{
	if(this->empty())
		throw "Queue<>::front(): queue is empty";
	if(this->_front == this->max_size+1)
		return this->buffer[0];
	return this->buffer[this->_front+1];
}

template <class T>
void Queue<T>::pop()
{
	if(!this->empty()){
		if(this->_front == this->max_size+1){
			this->_front = 0;
		}
		else
			this->_front += 1;
		this->_size -= 1;
	}
	else
		throw "Queue<>::pop(): queue is empty";
}

template <class T>
int Queue<T>::size()
{
	return this->_size;
}

template <class T>
T* Queue<T>::get_queue()
{
	int n = this->_size;
	if(n == 0)
		return NULL;
//T* temp = new T[n];
//int i = 0;
//while(i < n){
//	temp[i] = this->front();
//	this->pop();
//	this->push(temp[i]);
//	++i;
//}
	int i = this->_front+1;
	int j = 0;
	T* temp = new T[n];
	while(j < n){
		if(i == this->max_size+2)
			i = 0;
		temp[j] = this->buffer[i];
		++i;
		++j;
	}
	return temp;
}

//explicit instantiations
template class Queue<int>;
#include "shape.h"
template class Queue<Shape>;
