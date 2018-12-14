//CPSC 121 Lab 9

//Provided for testing. A different main (with same usage/assumptions) may be used to grade your submission.



#include <iostream>
#include <stdlib.h>


//This is where LinkedList.h starts. 
using namespace std;

template <class T>

struct Node {

	T data;

	Node * next;

};



template <class T>

class LinkedList {

private:

	//Points to the entry point for our linked list

	Node<T> * head;

	//Extra credit thing

	int recursiveSum(Node<T> * h = NULL);

public:

	//Constructor initializes values upon declaration

	LinkedList() 
	{

		head = NULL;

	}

	//Deconstructor frees up any dynamic memory space granted to this class

	~LinkedList();

	//Returns the number of nodes that are contained in the linked list. USEFUL IN OTHER MEMBER FUNCTIONS.

	int size();

	//Displays all values in the list in order, starting from the head

	void display();

	//Inserts a node containing the argument into the linked list, fulfilling ascending order

	void insertItemSorted(T);

	//Returns whether the linked list contains the provided value or not

	bool findValue(T);

	//If a node is found containing the value passed as an argument, it will be safely removed from the LL

	void remove(T);

	int startRecursiveFunction() {

		return recursiveSum(head);

	}

};

//THIS IS WHERE THE CODE FOR LINKEDLIST.CPP STARTS
template <class T>
int LinkedList<T>::recursiveSum(Node<T> * h)
{
if(h != NULL)
{
return h->data+recursiveSum(h->next);
} 
else 
{
return 0;
}
}

template <class T>
int LinkedList<T>::size()
{
int count = 0;
Node<T> * curr = head;
while(curr != NULL) 
{
count++;
curr= curr->next;
}
return count;
}

template <class T>
void LinkedList<T>::display()
{
Node<T> * curr = head;
if(curr == NULL) 
{
cout << "List is empty" << endl;
}
while(curr!=NULL) 
{
cout << curr->data << " ";
curr = curr->next;
}
cout << endl;
}
template <class T>
void LinkedList<T>::insertItemSorted(T item)
{
Node<T> *newNode = new Node<T>();
newNode->data = item;
newNode->next = NULL;
if(head==NULL) {
//its the first node inserted
head = newNode;
return;
}
if(item<head->data) {
//insert at first
newNode->next = head;
head = newNode;
return;
}
Node<T> *curr = head;
Node<T> *prev;
while(curr!=NULL && curr->data < item) {
prev = curr;
curr = curr->next;
}
if(curr == NULL) {
//insert at last
prev->next = newNode;
} else {
//now curr->data is larger than item, henc it is inserted between prev and curr.
prev->next = newNode;
newNode->next = curr;
}
}
template <class T>
bool LinkedList<T>::findValue(T item)
{
Node<T> *curr = head;
while(curr !=NULL) {
if(curr->data == item) {
return true;
}
curr = curr->next;
}
return false;
}
template <class T>
void LinkedList<T>::remove(T item)
{
if(head == NULL) {
cout << "List is empty" << endl;
return;
}
if(head->data == item) {
//if first item has to be removed
head = head->next;
return;
}
Node<T> *curr = head;
Node<T> *prev;

while(curr!=NULL && curr->data!=item) {
prev = curr;
curr=curr->next;
}
if(curr == NULL) {
cout << "Item not found" << endl;
} else {
prev->next = curr->next;
curr->next = NULL;
}
}
template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T> * ptr = head;
	ptr = head->next;
	delete head;

}


//THIS IS WHERE THE CODE FOR THE PROFESSOR'S MAIN FUNCTION STARTS

int main()

{

	LinkedList<int> mylist;

	cout << "Starting size: " << mylist.size() << endl;

	mylist.insertItemSorted(4);

	mylist.insertItemSorted(3);

	mylist.insertItemSorted(5);

	mylist.display();

	cout << "EXTRA CREDIT: " << mylist.startRecursiveFunction() << endl;

	cout << "Size after insertion: " << mylist.size() << endl;

	mylist.remove(4);

	cout << "Size after deletion: " << mylist.size() << endl;

	cout << "1 for item found: " << mylist.findValue(3) << endl;

	cout << "0 for item missing: " << mylist.findValue(4) << endl;

	return 0;

}

//If you aren't attempting extra credit, just include the function definition below to avoid errors

/*
template <class T>
int LinkedList::recursiveSum(Node<T> * n)
{
}
*/