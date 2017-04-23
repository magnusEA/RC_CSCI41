//CSCI 41 Lab 13 Palindrome
//Edgar Abundiz 


#ifndef PALINDROME_H
#define PALINDROME_H
#include <iostream>
using namespace std;

// Stack template
template <class T>
class Queue
{
private:
	T *queueArray;     // Points to the queue array
	int queueSize;    // The queue size
	int front;        // Subscript of the queue front
	int rear;         // Subscript of the queue rear
	int numItems;     // Number of items in the queue
public:
	// Constructor
	Queue(int);

	// Copy constructor
	Queue(const Queue &);

	// Destructor
	~Queue();

	// Queue operations
	void enqueue(T);
	void dequeue(T &);
	bool isEmpty() const;
	bool isFull() const;
	void clear();
};

#endif