#include "Deque.h"
#include "Node.h"
#include "stdlib.h"
#include "stdio.h"
#include <memory>
#include <utility>
#include <string>
#include <iostream>
#include <stdexcept>


using std::unique_ptr;
using std::make_unique;
using std::string;
using std::move;
using std::cout;
using std::endl;


//Construct a deep copy of its constant Deque reference parameter.
Deque::Deque(const Deque &cp)
: tail(), head{}
{
	Node * list = cp.head.get();
	while (list) {
            insert_back(list->val);
            list = list->next.get();
    }
}

//Deallocate dynamic memory  in "constant space"
Deque::~Deque() {
	Node * list = head.get();
	while (list){
		remove_front();
		list = head.get();
	}
}

/*Deep copy the constant Deque reference parameter
into the target object and returns a reference to the
target after deallocating any dynamic memory associated
with the original contents of the target.*/
Deque& Deque::operator=(const Deque &cp) 
{
	Node * list = cp.head.get();
	while (list) {
            insert_back(list->val);
            list = list->next.get();
    }
    return *this;
}

/*Insert its parameter at the front of the deque;
must run in constant O(1) time.*/
void Deque::insert_front(int x) {
	auto newNode = make_unique<Node>(x);
	if (count == 0)
		tail = newNode.get();
	else 
		newNode->next = move(head);
	head = move(newNode);
	count++;
	return;
}

/*Insert its parameter at the back of the deque;
must run in constant O(1) time.*/
void Deque::insert_back(int x) {
	auto newNode = make_unique<Node>(x);
	if (count == 0) {
		tail = newNode.get();
		head = move(newNode);
		count++;
		return;
	}
	else {
		tail->next = move(newNode);
		tail = tail->next.get();
		count++;
		return;
	}
}

/*Remove and return the value at the front of the deque;
if the deque is empty throw a runtime_error;
must run in constant O(1) time.*/
int Deque::remove_front() {
	if (count==0)
		throw std::runtime_error("ERROR: head==NULL (remove_front)");
	else if (count == 1) {
		auto x = head->val;
		head = NULL;
		tail = NULL;
		count--;
		return x;
	}
	auto x = head->val;
	head = move(head->next);
	count--;
	return x;

}

/*Remove and return the value at the back of the deque;
if the deque is empty throw a runtime_error;
must run in linear O(n) time.*/
int Deque::remove_back() {
	if (count==0)
		throw std::runtime_error("ERROR: tail==NULL (remove_back)");
	else if (count == 1) {
		auto x = head->val;
		head = NULL;
		tail = NULL;
		count--;
		return x;
	}
	Node * prev = head.get();
	Node * end = head->next.get();
	while (end->next) {
		prev = prev->next.get();
		end = end->next.get();
	}
	auto x = tail->val;
	prev->next = NULL;
	tail =  prev;
	count--;
	return x;
}

/*Return the value at the front of the deque without removing it;
if the deque is empty throw a runtime_error;
must run in constant O(1) time.*/
int Deque::peek_front() const {
	if (head != NULL) 
		return head->val;
	throw std::runtime_error("ERROR: head==NULL (peek_front)");
}

/*Return the value at the back of the deque without removing it;
if the deque is empty throw a runtime_error;
must run in constant O(1) time.*/
int Deque::peek_back() const {
	if (tail != NULL)
		return tail->val;
	throw std::runtime_error("ERROR: tail==NULL (peek_back)");
}

/*Return true if the deque is empty, false otherwise.*/
bool Deque::empty() const {
	if (head == NULL)
		return true;
	return false;
}

/*Return the number of items stored in the deque;
must run in constant O(1) time.*/
int Deque::size() const {
	return count;
}

/*For debugging only, a routine that prints all the Nodes in
the queue, together with the pointers to the head and tail
and the size of the queue. This routine calls the Node
output function (provided below) to print a Node.*/
void Deque::print_queue(const std::string& label) const {
	cout << label;
	Node * list = head.get();
	while (list) {
		cout << list->val << " ";
		list = list->next.get();
	}
	cout << endl;
	return;
}