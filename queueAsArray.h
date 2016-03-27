#pragma
// page 1207 
#include <iostream>
#include <vector>
#include <cassert> 
#include "queueADT.h"

using namespace std;

template <class Type>
class queueType: public queueADT<Type>
{
public:
    const queueType<Type>& operator=(const queueType<Type>&); 
      //Overload the assignment operator.

    bool isEmptyQueue() const;
      //Function to determine whether the queue is empty.
      //Postcondition: Returns true if the queue is empty,
      //               otherwise returns false.

    bool isFullQueue() const;
      //Function to determine whether the queue is full.
      //Postcondition: Returns true if the queue is full,
      //               otherwise returns false.

    void initializeQueue();
      //Function to initialize the queue to an empty state.
      //Postcondition: count = 0; queueFront = 0;
      //               queueRear = maxQueueSize – 1

    Type front() const;
      //Function to return the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program 
      //               terminates; otherwise, the first 
      //               element of the queue is returned.  
    Type back() const;
      //Function to return the last element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program 
      //               terminates; otherwise, the last 
      //               element of the queue is returned.

    void addQueue(const Type& queueElement);
      //Function to add queueElement to the queue.
      //Precondition: The queue exists and is not full.
      //Postcondition: The queue is changed and queueElement
      //               is added to the queue.

    void deleteQueue();
      //Function to remove the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: The queue is changed and the first 
      //               element is removed from the queue.

    queueType(int queueSize = 100); 
      //Constructor

    queueType(const queueType<Type>& otherQueue); 
      //Copy constructor

    ~queueType(); 
      //Destructor

    void moveNthFront(int n);

private:
    int maxQueueSize; //variable to store the maximum queue size
    int count;        //variable to store the number of
                      //elements in the queue
    int queueFront;   //variable to point to the first
                      //element of the queue
    int queueRear;    //variable to point to the last
                      //element of the queue
    Type *qList;       //pointer to the array that holds 
                      //the queue elements 
};

template <class Type>
bool queueType<Type>::isEmptyQueue() const
{
    return (count == 0);
} //end (pg 1208)

template <class Type>
bool queueType<Type>::isFullQueue() const
{
    return (count == maxQueueSize);
} //end (pg 1208)

template <class Type>
void queueType<Type>::initializeQueue()
{
    queueFront = 0;
    queueRear = maxQueueSize - 1;
    count = 0;
} //(pg 1209)

template <class Type>
Type queueType<Type>::front() const
{
    assert(!isEmptyQueue());
    return qList[queueFront]; 
} //end front

template <class Type>
Type queueType<Type>::back() const
{
    assert(!isEmptyQueue());
    return qList[queueRear];
} //end back

template <class Type>
void queueType<Type>::addQueue(const Type& newElement)
{
    if (!isFullQueue())
    {   
        queueRear = (queueRear + 1) % maxQueueSize; 
        count++;
        qList[queueRear] = newElement;
    }
    else
        cout << "Cannot add to a full queue." << endl; 
} // pg 1209 implementation of the addqueue

template <class Type>
void queueType<Type>::deleteQueue()
{
    if (!isEmptyQueue())
    {   
        count--;
        queueFront = (queueFront + 1) % maxQueueSize;  // mod bc it is circular
    }
    else
        cout << "Cannot remove from an empty queue." << endl;
} //pg 1210
template <class Type>
queueType<Type>::queueType(int queueSize)   
{
    if (queueSize <= 0)
    {
        cout << "Size of the array to hold the queue must "
             << "be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxQueueSize = 100;
    }
    else
        maxQueueSize = queueSize; 
		queueFront = 0;                 
		queueRear = maxQueueSize - 1;   
		count = 0;
		qList = new Type[maxQueueSize];  
} //pg 1210

template <class Type>
queueType<Type>::~queueType()   
{
    delete [] qList;
} //pg 1211

template <class Type>
const queueType<Type>& queueType<Type>::operator=
	                   (const queueType<Type>& otherQueue)
{
    cout << "Write the definition of the function "
         << "to overload the assignment operator." << endl;
} 

template <class Type>
void queueType<Type>::moveNthFront(int y)
{
	if (count == 0)
            cout << "The queue is empty." << endl;
        else
        {
			int x = (queueFront + y - 1) % maxQueueSize;
			Type temp = qList[x];
			if (queueFront <= x)
				for (int b = x; b > queueFront; b--)
                    qList[b] = qList[b - 1];
            else{
                while (x != maxQueueSize - 1)
                {
                    if (x == 0)
                    {
                        qList[x] = qList[maxQueueSize - 1];
                        x = maxQueueSize - 1;
                    }
                    else
                    {
                        qList[x] = qList[x - 1];
      x--;
      }
      }
     for (int b = x; b > queueFront; b--) qList[b] = qList[b - 1];
     }
     qList[queueFront] = temp;
	 }
}




