#include<iostream>
using namespace std;
int queuearr[5],n=5,front=-1,rear=-1;
void enqueue(int value){
     if(rear==n-1){
      cout<<"queue is overloaded"<<endl;
          }
     else{
     if(front==-1)
      front=0;
      rear++;
    queuearr[rear]=value;
      }
    }
void dequeue(){
     if(front==-1&&rear==-1){
     cout<<"queue is underloaded"<<endl;
         }
     else{
     // if(rear=front)
      // rear=front=-1;
      // else
       front++;
        }
      }
void display(){
    
     if(front==-1&&rear==-1){
     cout<<"queue is empty:"<<endl;
                  }
     else{
     cout<<"the elements of the queue are:"; 
     for(int i=front;i<=rear;i++)
     cout<<queuearr[i]<<" ";
     cout<<endl;
        }
       }
int size(){
  cout<<"size of the queue is:"<<rear-front+1<<endl;
        }
bool isempty(){
      if(front==-1&&rear==-1){
       cout<<"queue is  empty"<<endl;
               }
      else{
        cout<<"queue is not empty"<<endl;
            }
          }
void frontdisplay(){
     if(front==-1&&rear==-1){
      cout<<"end is not exist"<<endl;
               }
     else{
       cout<<"front is:"<<queuearr[front]<<endl;
               }
            }
int main(){
    // int stackarr[5]={1,2,6,7,8};
     //display();
     enqueue(2);
     enqueue(5);
     enqueue(6);
     enqueue(7);
     enqueue(9);
     display();
     size();
     dequeue();
     display();
     size();
     isempty();
     frontdisplay();
     return 0;
      }
