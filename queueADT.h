 #pragma
 // this class was taken from Ch 18 Stacks 6th edition page 1201
template <class Type> 
class queueADT
{
public:
	virtual void initializeQueue() = 0;
      // method to initialize to empty state and post:q is empty
    virtual bool isEmptyQueue() const = 0;
      //Function to determine whether the queue is empty.
      //Postcondition: True=empty if not, false
    virtual bool isFullQueue() const = 0;
      //Function to determine whether the queue is full.
      //Postcondition: Returns true if the queue is full
    virtual Type front() const = 0;
      //Function to return the first element of the queue.
    virtual Type back() const = 0;
      //Function to return the last element of the queue.
    virtual void addQueue(const Type& queueElement) = 0;
      //Function to add queueElement to the queue.
    virtual void deleteQueue() = 0;
      //Function to remove the first element of the queue.
};

        
