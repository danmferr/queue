  7/19/15
  Test Program
  */
 
#include <iostream>
#include "queueAsArray.h"
  
using namespace std;

int main()
{
	int userPosition;
	userPosition=5; // match the example .jpg
  
    cout << "Enter the position of the element to be moved to the front." << endl;
	cout <<"5"<<endl; //print variable of 5
    cout<<endl;
	cout << "queue: ";

	queueType<int> queue(10);
	//stored numbers
    queue.addQueue(23);
    queue.addQueue(45);
    queue.addQueue(38);
    queue.addQueue(22);
    queue.deleteQueue();  // deletes this due to the sample .jpg showed removal of 5
    queue.addQueue(18);
    queue.addQueue(42);
    queue.addQueue(10);
    queue.addQueue(27);
    queue.addQueue(5);

    queue.moveNthFront(userPosition);
    while (!queue.isEmptyQueue())
    {
        cout << queue.front() <<  " ";
        queue.deleteQueue();
    }
    cout << endl;
	cin.get();
	system("pause");
    return 0;
}

