#include<iostream>
using namespace std;

class node{
  public:
 //data
 int data;
//node to point next and previous
 node* next;
 node* prev;
//constructure
 node(){
      next=NULL;
      prev=NULL;
      
        }
    };
 //class dll
class dll{
 public:
 node*head;
 dll(){
  head=NULL;
    }
void insert(int value){
      node*temp=new node;
      if(head==NULL){
        head=temp;
         }
      else{
     node* current=head;
     while(current->next!=NULL)
     current=current->next;
     current->next=temp;
     temp->prev=current;
              
            }
        }
void display(){
     node* current=head;
     node* last;
     cout<<"display till last:";
     while(current!=NULL){
      cout<<current->data<<"->";
      last=current;
      current=current->next;
          }
     cout<<endl;
     cout<<"display in rev order:";
     while(last!=NULL){
      cout<<last->data<<"->";
      last->prev=last;
         }
     cout<<endl;
       }
void insertat(int pos,int value){
     node* current=head;
     int i=1;
     while(i<pos-1){
        i++;
      current=current->next;
         }
     node* temp=new node;
     temp->data=value;
     
     temp->next=current->next;
     current->next->prev=temp;
     current->next=temp;
     temp->prev=current;
             }
       };
int main(){
      dll l1;
      l1.insert(1);
      l1.insert(2);
      l1.insert(6);
      l1.insert(5);
      l1.insert(8);
      l1.insert(10);
      l1.display();
      l1.insertat(2,9);
      l1.insertat(4,11);
      l1.display();
      return 0;
      }
     
     
     
     
     
      
     
      
 
