#include<iostream>
#include "ll1.cpp"
using namespace std;


class queuell{
// top and nodes 
  public:
 // node type pointer top
  node* top;
  linkedlist l1;
  
//constructer
  queuell(){
  top=l1.head;
  
   }
//declear insertat function
void enqueue(int value){

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
void dequeue(){
   l1.delet();
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
      cout<<"queue has no element"<<endl;
            }
    else {
    cout<<"top is:"<<l1.head->data<<endl;
       }
  }
};
int main(){
queuell q1;
for(int i=0;i<5;i++){
 q1.enqueue(i);
      }
q1.display();
q1.dequeue();
q1.display();
q1.size();
q1.isempty();
q1.topdisplay();
return 0;
   }
