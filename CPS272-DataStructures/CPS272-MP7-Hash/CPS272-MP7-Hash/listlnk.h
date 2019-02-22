#pragma warning( disable : 4290 )
#include <stdexcept>
#include <new>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

template < class T >         // Forward declaration of the List class
class List;

template < class T >
class ListNode                // Facilitator class for the List class
{
private:

	ListNode(const T &nodeData, ListNode *nextPtr);
	T dataItem;      // List data item
	ListNode *next;   // Pointer to the next list node

	friend class List<T>;
};

//--------------------------------------------------------------------

template < class T >
class List
{
public:

	List(int ignored = 0);
	~List();
	void insert(const T &newData) throw (bad_alloc);        // Insert after cursor
	void remove() throw (logic_error);                      // Remove data item
	void replace(const T &newData)  throw (logic_error);    // Replace data item
	void clear();

	bool isEmpty() const;
	bool isFull() const;

	// List iteration operations
	void gotoBeginning()   throw (logic_error);
	void gotoEnd()  throw (logic_error);
	bool gotoNext();
	bool gotoPrior();
	T getCursor() const throw (logic_error);                   // Return item
	void showStructure() const;
	void moveToBeginning() throw (logic_error);                    // Move to beginning
	void insertBefore(const T &newElement)  throw (bad_alloc);  // Insert before cursor

private:
	ListNode<T> *head,     // Pointer to the beginning of the list
		*cursor;   // Cursor pointer
};

