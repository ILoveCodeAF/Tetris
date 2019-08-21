#include "queue.h"

template <class T>
Queue::Queue(int size)
{
	this->front = 0;
	this->back = 1;
	this->max_size = size;
	this->size = 0;
	this->buffer = new T[this->max_size+2];
}

template <class T>
void Queue::free()
{
	if(q->buffer != NULL)
		free(q->buffer);
}

template <class T>
bool Queue::empty()
{
	return this->size == 0;
}

template <class T>
bool Queue::full()
{
	return this->size == q->max_size;
}

template <class T>
void Queue::push(T value)
{
	if(!this->full()){
		if(this->back == this->max_size+2){
			this->back = 0;
		}
		this->buffer[this->back] = value;
		this->back += 1;
		this->size += 1;
	}
}

template <class T>
T queue_pop()
{
	if(!this->empty()){
		if(this->front == this->max_size+1){
			this->front = 0;
		}
		else
			this->front += 1;
		this->size -= 1;
		return this->buffer[this->front];
	}
	return NULL;
}

template <class T>
int Queue::size()
{
	return this->size;
}
