#include "DLinkedList.h"
#include "DequeEmpty.h"

typedef std::string Elem;// deque element type
class LinkedDeque { // deque as doubly linked list
	public:
		//LinkedDeque(); // constructor
		int size() const; // number of items in the deque
		bool empty() const; // is the deque empty?
		const Elem& front(); // the first element
		const Elem& back(); // the last element
		void insertFront(const Elem& e); // insert new first element
		void insertBack(const Elem& e); // insert new last element
		void removeFront(); // remove first element
		void removeBack(); // remove last element
	private: // member data
		DLinkedList D; // linked list of elements
		int n = 0; // number of elements
};

