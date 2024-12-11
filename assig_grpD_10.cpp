/*
In any language program mostly syntax error occurs due to unbalancing delimiter such as 
(),{},[]. Write C++ program using stack to check whether given expression is well 
parenthesized or not.
*/


#include<iostream>
using namespace std;

class Stack{
    private:
    char *arr;
    int top;
    int capacity;
    public:
    Stack(int size){
        capacity=size;
        arr=new char[capacity];
        top=-1;
    }
    ~Stack(){
        delete[] arr;
    }
    bool isfull(){
        return top==capacity-1;
    }
    bool isempty(){
        return top==-1;
    }
    void push(char c){
        if(isfull()){
            cout<<"Stack overflow"<<endl;
            return;
        }
        arr[++top]=c;
    }
    char pop(){
        if(isempty()){
            cout<<"Stack underflow"<<endl;
            return '\0';
        }
        return arr[top--];
    }
    bool iswellparenthesised(const string &expression){
        Stack s(expression.length());

        for (int i=0;i<expression.length();i++){
            char ch=expression[i];
            if (ch=='(' || ch=='{' || ch=='['){
                s.push(ch);
            }
            else if (ch==')' || ch=='}' || ch==']'){
                if (s.isempty()){
                    return false;
                }
                char top=s.pop();
                if((ch==')' && top!='(') || (ch=='}' && top!='{') || (ch==']' && top!='[')){
                    return false;
                }
            } 
        }
        return s.isempty();
    }
};

int main(){
    string expression;
    cout<<"Enter the expression for checking if it is well parenthesised or not: ";
    getline(cin, expression);
    Stack s(expression.length());
    if(s.iswellparenthesised(expression)){
        cout<<"Well parenthesised expression"<<endl;
    }else{
        cout<<"Not well parenthesised expression"<<endl;
    }
    return 0;
}
