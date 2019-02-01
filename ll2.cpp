#include<iostream>
#include "ll1.cpp"
using namespace std;


class stackll{
// top and nodes 
  public:
 // node type pointer top
  node* top;
  linkedlist l1;
  
//constructer
  stackll(){
  top=l1.head;
  
   }
//declear insertat function
void push(int value){

     l1.insertat(1, value);
     top=l1.head;
         }
// new function display
void display(){
     node * current=top;
// display of the value of all nodes
     while(current !=NULL){
     cout<<current->data<<"->";
     current = current->next;
         }
     cout<<endl;
       } 
void pop(){
   l1.deletat(1);
   top=l1.head;
  }
 void size(){
 node* current=top;
  int count=1;
 while(current->next!=NULL){
   
    count++;
  current=current->next;
   
      }
  cout<<"size"<<count<<endl;
   }
 bool isempty(){
    if(top==NULL){
      cout<<"yes"<<endl;
       }
    else{
     cout<<"no"<<endl;
       }
     }
 void topdisplay(){
    if(l1.head==NULL){
      cout<<"stack has no element"<<endl;
            }
    else {
    cout<<"top is:"<<l1.head->data<<endl;
       }
  }
};
int main(){
stackll s1;
for(int i=0;i<5;i++){
 s1.push(i);
      }
s1.display();
s1.pop();
s1.display();
s1.size();
s1.isempty();
s1.topdisplay();
return 0;
   }
