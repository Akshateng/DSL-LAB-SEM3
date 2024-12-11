*/
Department of Computer Engineering has student's club named 'Pinnacle Club'. Students 
of second, third and final year of department can be granted membership on request. 
Similarly one may cancel the membership of club. First node is reserved for president of 
club and last node is reserved for secretary of club. Write C++ program to maintain club 
member‘s information using singly linked list. Store student PRN and Name. Write 
functions to:
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exists for two divisions. Concatenate two lists.
/*

#include<iostream>
using namespace std;

struct node{
    int prn;
    char name[20];
    struct node *next;
};

class Pinnacle{
public:
    struct node *start;
    Pinnacle(){
        start = NULL;
    }
    void insert();
    void del();
    void display();
    int total();
    void reverse(struct node*);
    void concat(Pinnacle&);
};

void Pinnacle::insert(){
    cout << "Press:\n1. to insert in beginning\n2. to insert in end\n3. to insert in middle\n";
    int ch;
    cin >> ch;
    struct node *temp = new node;
    struct node *ptr = start;

    switch(ch){
        case 1:
            cout << "Enter name of president:\n";
            cin >> temp->name;
            cout << "Enter PRN of President:\n";
            cin >> temp->prn;
            if(start == NULL)
                start = temp;
            else{
                temp->next = start;
                start = temp;
            }
            break;

        case 2:
            cout << "Enter name of secretary:\n";
            cin >> temp->name;
            cout << "Enter PRN of secretary:\n";
            cin >> temp->prn;
            while(ptr != NULL && ptr->next != NULL)
                ptr = ptr->next;
            if(ptr != NULL)
                ptr->next = temp;
            temp->next = NULL;
            break;

        case 3:
            cout << "Enter name of Member:\n";
            cin >> temp->name;
            cout << "Enter PRN of Member:\n";
            cin >> temp->prn;
            temp->next = start->next;
            start->next = temp;
            break;

        default:
            cout << "Wrong input\n";
    }
}

void Pinnacle::del(){
    struct node *ptr = start;
    struct node *temp = NULL;
    if(start == NULL){
        cout << "Empty list\n";
        return;
    }

    cout << "Enter the PRN number of the member whose entry is to be deleted:\n";
    int k;
    cin >> k;

    while(ptr != NULL){
        if(ptr->prn == k){
            if(ptr == start){
                start = ptr->next;
                delete ptr;
                cout << "Entry successfully deleted.\n";
                return;
            } else {
                temp->next = ptr->next;
                delete ptr;
                cout << "Entry successfully deleted.\n";
                return;
            }
        }
        temp = ptr;
        ptr = ptr->next;
    }
    cout << "No such PRN found.\n";
}

int Pinnacle::total(){
    int k = 0;
    struct node* ptr = start;
    while(ptr != NULL){
        k++;
        ptr = ptr->next;
    }
    return k;
}

void Pinnacle::reverse(struct node *ptr){
    if(ptr == NULL) return;
    reverse(ptr->next);
    cout << "Name: " << ptr->name << "\nPRN: " << ptr->prn << "\n";
}

void Pinnacle::concat(Pinnacle &q){
    if(start == NULL){
        start = q.start;
        return;
    }

    struct node* ptr = start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = q.start;
    q.start = NULL;  // Make sure the second list is emptied after concatenation
}

void Pinnacle::display(){
    struct node *ptr = start;
    if(ptr == NULL){
        cout << "No members to display.\n";
        return;
    }

    cout << "The Details of Students are:\n";
    int k = 1;
    while(ptr != NULL){
        cout << k << ". Name: " << ptr->name << "\nPRN: " << ptr->prn << "\n";
        k++;
        ptr = ptr->next;
    }
}

int main(){
    Pinnacle p, q;
    char in = 'y';
    while(in == 'y' || in == 'Y'){
        cout << "Press\n1) Add and delete the members as well as president or even secretary.\n2) Compute total number of members of club\n";
        cout << "3) Display members\n4) Display list in reverse order using recursion\n5) Two linked lists exist for two divisions. Concatenate two lists\n";
        int ch;
        cin >> ch;
        switch(ch){
            case 1:
                cout << "Press\n1. to insert\n2. to delete\n";
                int k, m;
                cin >> k;
                switch(k){
                    case 1:
                        cout << "Enter number of data to be entered:\n";
                        cin >> m;
                        for(int i = 1; i <= m; i++)
                            p.insert();
                        break;
                    case 2:
                        p.del();
                        break;
                    default:
                        cout << "Wrong input.\n";
                }
                break;
            case 2:
                cout << "Total number of entries are: " << p.total() << "\n";
                break;
            case 3:
                p.display();
                break;
            case 4:
                p.reverse(p.start);
                break;
            case 5:
                cout << "Enter number of entries in second list:\n";
                int f;
                cin >> f;
                for(int i = 1; i <= f; i++)
                    q.insert();
                p.concat(q);
                cout << "List successfully concatenated.\n";
                break;
            default:
                cout << "Wrong input.\n";
        }
        cout << "\nDo you want to continue? (y/n): ";
        cin >> in;
    }
    return 0;
}
