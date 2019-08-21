#ifndef __QUEUE_H_INCLUDED__
#define __QUEUE_H_INCLUDED__

class Queue{
private:
	int front;
	int back;
	T* buffer;
	int max_size;
	int size;
public:
	Queue(int);
	void free();
	bool empty();
	bool full();
	void push(T value);
	T pop();
	void size();
}

#endif
