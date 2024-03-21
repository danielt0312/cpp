#include "LinkedDeque.h"

// insert new first element
void LinkedDeque::insertFront(const Elem& e) {
	D.addFront(e);
	n++;
}

// insert new last element
void LinkedDeque::insertBack(const Elem& e) {
	D.addBack(e);
	n++;
}

// remove first element
void LinkedDeque::removeFront() {
	if (empty())
		throw DequeEmpty("removeFront of empty deque");
	D.removeFront();
	n--;
}

// remove last element
void LinkedDeque::removeBack() {
	if (empty())
		throw DequeEmpty("removeBack of empty deque");
	D.removeBack();
	n--;
}


bool LinkedDeque::empty() const {
	return n == 0;
}

int LinkedDeque::size() const {
	return n;
}

const Elem& LinkedDeque::front() {
	return D.front();
}

const Elem& LinkedDeque::back() {
	return D.back();
}
