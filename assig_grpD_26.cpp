'''
In any language program mostly syntax error occurs due to unbalancing delimiter such as 
(),{},[]. Write C++ program using stack to check whether given expression is well 
parenthesized or not.
'''


  
#include <iostream>
#define max 10;
using namespace std;
class Stack
{
 public:.
 int top;
 char stack1[];

 Stack()
 {
 top=-1;
 }
 void push(char);
 char pop();
 int isfull();
 int isempty();
};
void Stack::push(char x)
{
 top=top+1;
 stack1[top]=x;
}
char Stack::pop()
{
 char s;
 s=stack1[top];
 top=top-1;
 return s;
}
int Stack::isfull()
{
 if(top==9)

 return 1;
 else
 return 0;
}
int Stack::isempty()
{
 if(top==-1)
 return 1;
 else
 return 0;
}
int main()
{
 Stack s1;
 char exp[20],ch;
 int i=0,ch1;
 cout<<"\n\nParentheses checker.....!!!!!"<<endl;
 cout<<"\nEnter the expression to check whether it is in well form or not: \n"<<endl;
 cin>>exp;
 for(i=0; i<20; i++)
 {
 if ((exp[i]=='(')||(exp[i]=='{')||(exp[i]=='['))
 {
 break;
 }

 else if ((exp[i]==')')||(exp[i]=='}')||(exp[i]==']'))
 {
 cout<<"\n\nInvalid expression !!!"<<endl;
 cout<<"No opening bracket found !!!"<<endl;
 //break;
 return 0;
 }
 }
 while(exp[i]!='\0')
 {
 ch=exp[i];
 switch(ch)
 {
 case '(':
 s1.push(ch);break;
 case '[':

 s1.push(ch);break;
 case '{':
 s1.push(ch);break;
 case ')':
 if(s1.stack1[s1.top]=='(')
 {
 s1.pop();
 }
 else
 {
 cout<<"The expression is invalid !!!"<<endl;
 cout<<"Reason: Wrong placement of the opening round bracket!!"<<endl;
 return 0;
 }
 break;
 case ']':
 if(s1.stack1[s1.top]=='[')
 {
 s1.pop();
 }
 else
 {
 cout<<"The expression is invalid !!!"<<endl;
 cout<<"Reason: Wrong placement of the opening square bracket!!"<<endl;
 return 0;
 }
 break;
 case '}':
 if(s1.stack1[s1.top]=='{')
 {
 s1.pop();
 }
 else
 {
 cout<<"The expression is invalid !!!"<<endl;
 cout<<"Reason: Wrong placement of the opening curly bracket!!"<<endl;
 return 0;
 }
 break;
 }
 i=i+1;
 }
 if (s1.isempty())
 {
 cout<<"\nThe expression is well parenthesised...\n";
 }

 else
 {
 cout<<"\nSorry! Invalid expression or not well parenthesised...\n";
 }
 return 0;

}
