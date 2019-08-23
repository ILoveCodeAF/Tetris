#ifndef __QUEUE_H_INCLUDED__
#define __QUEUE_H_INCLUDED__

template <class T>
class Queue{
private:
	int _front;
	int _back;
	T* buffer;
	int max_size;
	int _size;
public:
	Queue(int);
	void free();
	bool empty();
	bool full();
	void push(T value);
	T front();
	void pop();
	int size();
};

#endif
