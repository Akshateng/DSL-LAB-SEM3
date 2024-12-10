/*
Pizza parlor accepting maximum M orders. Orders are served in first come first served basis. Order once placed cannot be cancelled. Write C++ program to simulate the system
using circular queue using array.
*/

#include <iostream>
using namespace std;

class PizzaParlor {
private:
    int* queue;
    int front, rear, capacity;

public:
    // Constructor to initialize the queue
    PizzaParlor(int M) {
        capacity = M;
        queue = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Destructor to clean up memory
    ~PizzaParlor() {
        delete[] queue;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to place an order
    void placeOrder(int orderNumber) {
        if (isFull()) {
            cout << "Sorry, the pizza parlor is full. Cannot accept more orders." << endl;
        } else {
            if (front == -1) {
                front = 0;  // If the queue is empty, front and rear are initialized
            }
            rear = (rear + 1) % capacity;
            queue[rear] = orderNumber;
            cout << "Order " << orderNumber << " placed successfully." << endl;
        }
    }

    // Function to serve an order (FIFO)
    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve." << endl;
        } else {
            cout << "Serving order " << queue[front] << endl;
            if (front == rear) {
                front = rear = -1;  // If there was only one order
            } else {
                front = (front + 1) % capacity;
            }
        }
    }

    // Function to display all orders
    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders to display." << endl;
        } else {
            cout << "Current orders in the pizza parlor: ";
            int i = front;
            while (true) {
                cout << queue[i] << " ";
                if (i == rear) break;
                i = (i + 1) % capacity;
            }
            cout << endl;
        }
    }
};

int main() {
    int M;
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> M;

    PizzaParlor parlor(M);
    int choice, orderNumber;

    do {
        cout << "\n1. Place an order\n2. Serve an order\n3. Display orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the order number: ";
                cin >> orderNumber;
                parlor.placeOrder(orderNumber);
                break;

            case 2:
                parlor.serveOrder();
                break;

            case 3:
                parlor.displayOrders();
                break;

            case 4:
                cout << "Exiting program. Thank you!" << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
