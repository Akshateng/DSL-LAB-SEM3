/*
Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. If the operating system does not use priorities, then the jobs are processed in the order they enter the system. Write C++
program for simulating job queue. Write functions to add job and delete job from queue
*/

#include <iostream>
#define MAX 10
using namespace std;

struct queue {
    int data[MAX];
    int front, rear;
};

class Queue {
    struct queue q;

public:
    Queue() {
        q.front = q.rear = -1;
    }

    int isempty() {
        return (q.front == q.rear) ? 1 : 0;
    }

    int isfull() {
        return (q.rear == (MAX - 1)) ? 1 : 0;
    }

    void inqueue(int x) {
        if (!isfull()) {
            q.data[++q.rear] = x;
        }
    }

    int delqueue() {
        if (!isempty()) {
            return q.data[++q.front];
        }
        return -1;  // return -1 if the queue is empty
    }

    void display() {
        if (!isempty()) {
            cout << "Queue contents: ";
            for (int i = q.front + 1; i <= q.rear; i++) {
                cout << q.data[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Queue is empty!" << endl;
        }
    }
};

int main() {
    Queue obj;
    int ch, x, flag = 1;

    do {
        cout << "\n---- MENU ----\n";
        cout << "1. Check if the queue is full\n";
        cout << "2. Check if the queue is empty\n";
        cout << "3. Insert job into queue\n";
        cout << "4. Delete job from queue\n";
        cout << "5. Display queue contents\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                if (obj.isfull()) {
                    cout << "Queue is full (Overflow)!!\n";
                } else {
                    cout << "Queue is not full.\n";
                }
                break;

            case 2:
                if (obj.isempty()) {
                    cout << "Queue is empty (Underflow)!!\n";
                } else {
                    cout << "Queue is not empty.\n";
                }
                break;

            case 3:
                if (!obj.isfull()) {
                    cout << "Enter data for the job: ";
                    cin >> x;
                    obj.inqueue(x);
                    cout << "Job inserted.\n";
                } else {
                    cout << "Queue is full! Cannot insert job.\n";
                }
                break;

            case 4:
                if (!obj.isempty()) {
                    cout << "Deleted job: " << obj.delqueue() << endl;
                } else {
                    cout << "Queue is empty! Cannot delete job.\n";
                }
                break;

            case 5:
                obj.display();
                break;

            default:
                cout << "Invalid choice, please try again.\n";
        }

        cout << "\nEnter 1 to continue, 0 to exit: ";
        cin >> flag;
        cout << "=====================================\n";
    } while (flag);

    return 0;
}
