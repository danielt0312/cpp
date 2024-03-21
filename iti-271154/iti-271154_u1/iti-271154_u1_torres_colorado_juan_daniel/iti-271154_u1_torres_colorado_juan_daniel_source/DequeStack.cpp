#include "DequeStack.h"

DequeStack::DequeStack() // constructor
: D() { }

// number of elements
int DequeStack::size() const
{ return D.size(); }

// is the stack empty?
bool DequeStack::empty() const
{ return D.empty(); }

// the top element
const Elem& DequeStack::top() {
	if (empty())
		throw StackEmpty("top of empty stack");
	return D.front();
}

// push element onto stack
void DequeStack::push(const Elem& e)
{ D.insertFront(e); }

// pop the stack
void DequeStack::pop()
{
	if (empty())
		throw StackEmpty("pop of empty stack");
	D.removeFront();
}

