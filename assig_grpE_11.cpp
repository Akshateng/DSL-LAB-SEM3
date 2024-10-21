/*
Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. If the operating system does not use priorities, then the jobs are processed in the order they enter the system. Write C++
program for simulating job queue. Write functions to add job and delete job from queue
*/

#include <iostream> 
#define MAX 10 
using namespace std;

struct queue
{
int data[MAX]; int front, rear;
};
class Queue
{
struct queue q;

public:
Queue()
{
q.front = q.rear = -1;
}
int isempty()
{
return (q.front == q.rear) ? 1 : 0;
}
int isfull()
{
return (q.rear == (MAX - 1)) ? 1 : 0;
}
void inqueue(int x)
{
q.data[++q.rear] = x;
}
int delqueue()
{
return (q.data[++q.front]);
}
void display()
{
cout << endl;
for (int i = q.front + 1; i <= q.rear; i++) cout << q.data[i] << " ";
}
};

int main()
{

Queue obj;
int ch, x, flag = 1; do
{
cout << "\n 1.Check whether the queue is overflow(Full) or not\n 2.Check whether the queue is underflow(Empty) or not\n 3.Insert Job\n 4.Delete Job\n 5.Display\n Enter your choice : ";
cin >> ch; switch (ch)
{
case 1:
if(obj.isfull()){
cout<<"Queue is overflow(Full) !!"<<endl;
}
else{
cout<<"Queue is not full !!"<<endl;
}
break; case 2:
if(obj.isempty()){
cout<<"Queue is underflow(Empty) !!"<<endl;
}
else{
cout<<"Queue is not empty !!"<<endl;
}
break; case 3:
if (!obj.isfull())
{
cout << "\n Enter data for the job : "; cin >> x;
obj.inqueue(x); cout << endl;
}
else
{
cout << "Queue is overflow!!!\n\n";
}
break; case 4:
if (!obj.isempty())
{
cout << "\n Deleted jobs are : " << obj.delqueue() << endl;
}
else
{
cout << "\nQueue is underflow!!!\n\n";
}
cout << "\nRemaining Jobs are : "; obj.display();
break; case 5:
if (!obj.isempty())
{
cout << "\nThe job data contained by queue :"; obj.display();
}
else
{
cout << "\n Queue is empty!!!\n\n";
}
}
cout << "\nEnter 1 to continue 0 to exit: "; cin >> flag;
cout << "=====================================================" << endl;
} while (flag);

return 0;
}
