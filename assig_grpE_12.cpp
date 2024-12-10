/*
A double-ended queue (deque) is a linear list in which additions and deletions may be made at either end. Obtain a data
representation mapping a deque into a one-dimensional array. Write C++ program to simulate deque with functions to add 
and delete elements from either end of the deque. 
*/

#include <iostream>
using namespace std;

class Deque {
private:
    int *arr;
    int front, rear, size, capacity;

public:
    // Constructor to initialize deque with given capacity
    Deque(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Destructor to free allocated memory
    ~Deque() {
        delete[] arr;
    }

    // Check if the deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the deque is full
    bool isFull() {
        return size == capacity;
    }

    // Add an element to the front of the deque
    void addFront(int value) {
        if (isFull()) {
            cout << "Deque is full, cannot add to front!" << endl;
            return;
        }

        if (front == -1) { // If deque is empty, set both front and rear to 0
            front = rear = 0;
        } else {
            // Move front pointer to the previous position (circular)
            front = (front - 1 + capacity) % capacity;
        }

        arr[front] = value;
        size++;
    }

    // Add an element to the rear of the deque
    void addRear(int value) {
        if (isFull()) {
            cout << "Deque is full, cannot add to rear!" << endl;
            return;
        }

        if (rear == -1) { // If deque is empty, set both front and rear to 0
            front = rear = 0;
        } else {
            // Move rear pointer to the next position (circular)
            rear = (rear + 1) % capacity;
        }

        arr[rear] = value;
        size++;
    }

    // Remove an element from the front of the deque
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty, cannot delete from front!" << endl;
            return;
        }

        // Move front pointer to the next position (circular)
        front = (front + 1) % capacity;
        size--;

        if (size == 0) { // If deque becomes empty, reset front and rear
            front = rear = -1;
        }
    }

    // Remove an element from the rear of the deque
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty, cannot delete from rear!" << endl;
            return;
        }

        // Move rear pointer to the previous position (circular)
        rear = (rear - 1 + capacity) % capacity;
        size--;

        if (size == 0) { // If deque becomes empty, reset front and rear
            front = rear = -1;
        }
    }

    // Display elements of the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }

        int i = front;
        cout << "Deque elements: ";
        for (int j = 0; j < size; j++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity; // Move to the next index (circular)
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the deque: ";
    cin >> capacity;

    Deque dq(capacity);

    int choice, value;

    do {
        cout << "\nDeque Menu:\n";
        cout << "1. Add element to front\n";
        cout << "2. Add element to rear\n";
        cout << "3. Remove element from front\n";
        cout << "4. Remove element from rear\n";
        cout << "5. Display deque\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add to front: ";
                cin >> value;
                dq.addFront(value);
                break;
            case 2:
                cout << "Enter value to add to rear: ";
                cin >> value;
                dq.addRear(value);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                dq.display();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
