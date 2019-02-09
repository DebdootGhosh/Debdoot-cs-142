#include<iostream>
using namespace std;
int stackarr[5],n=5,top=-1;
void push(int value){
     if(top>=n-1){
      cout<<"stack is overloaded"<<endl;
          }
     else{
      top++;
    stackarr[top]=value;
      }
    }
void pop(){
     if(top<=-1){
     cout<<"stack is underloaded"<<endl;
         }
     else{
       top--;
        }
      }
void display(){
     if(top>=0){
     cout<<"the elements of the stacks are:"; 
     for(int i=top;i>=0;i--)
     cout<<stackarr[i]<<" ";
     cout<<endl;
        }
     else{
     cout<<"stack is empty"<<endl;
         }
       }
int size(){
  cout<<"size of the stack is:"<<top+1<<endl;
        }
bool isempty(){
      if(top>=0){
       cout<<"stack is not empty"<<endl;
               }
      else{
        cout<<"stack is empty"<<endl;
            }
          }
void topdisplay(){
     if(top<=-1){
      cout<<"top is not exist"<<endl;
               }
     else{
       cout<<"top is:"<<stackarr[top]<<endl;
               }
            }
int main(){
    // int stackarr[5]={1,2,6,7,8};
     //display();
     push(2);
     push(5);
     push(6);
     push(7);
     push(9);
     size();
     pop();
     display();
     size();
     isempty();
     topdisplay();
     return 0;
        }
     
    

