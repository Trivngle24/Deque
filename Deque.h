#ifndef Deque_header
#define Deque_header

#include "Node.h"
#include "stdlib.h"
#include "stdio.h"
#include <memory>
#include <string>
#include <utility>

using std::unique_ptr;
using std::shared_ptr;
using std::make_unique;
using std::string;
using std::move;

class Deque
{
public:

	//default constructor
	Deque() = default; 

	//Construct a deep copy of its constant Deque reference parameter.
	Deque(const Deque&); 

	//Deallocate dynamic memory in "constant space"
	~Deque();

	/*Copy(deeply) the constant Deque reference parameter 
	into the target object and returns a reference to the 
	target after deallocating any dynamic memory associated 
	with the original contents of the target.*/
	Deque& operator=(const Deque&);

	/*Insert its parameter at the front of the deque; 
	must run in constant O(1) time.*/
	void insert_front(int);

	/*Insert its parameter at the back of the deque;
	must run in constant O(1) time.*/
	void insert_back(int);

	/*Remove and return the value at the front of the deque; 
	if the deque is empty throw a runtime_error(this error class 
	is defined in the stdexcept library file); 
	must run in constant O(1) time.*/
	int remove_front();

	/*Remove and return the value at the back of the deque; 
	if the deque is empty throw a runtime_error; 
	must run in linear O(n) time.*/
	int remove_back();

	/*Return the value at the front of the deque without removing it; 
	if the deque is empty throw a runtime_error; 
	must run in constant O(1) time.*/
	int peek_front() const;

	/*Return the value at the back of the deque without removing it; 
	if the deque is empty throw a runtime_error; 
	must run in constant O(1) time.*/
	int peek_back() const;

	/*Return true if the deque is empty, false otherwise.*/
	bool empty() const;

	/*Return the number of items stored in the deque; 
	must run in constant O(1) time.*/
	int size() const;

	/*For debugging only, a routine that prints all the Nodes in 
	the queue, together with the pointers to the head and tail 
	and the size of the queue. This routine calls the Node 
	output function (provided below) to print a Node.*/
	void print_queue(const std::string& label) const;


private:
	Node *tail;
	unique_ptr<Node> head;
	int count {0};
};

#endif

