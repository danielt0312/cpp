#include "StackEmpty.h"
#include "LinkedDeque.h"

typedef std::string Elem; // element type
class DequeStack { // stack as a deque
	public:
		DequeStack(); // constructor
		int size() const; // number of elements
		bool empty() const; // is the stack empty?
		const Elem& top(); // the top element
		void push(const Elem& e); // push element onto stack
		void pop(); // pop the stack
	private:
		LinkedDeque D; // deque of elements
};
