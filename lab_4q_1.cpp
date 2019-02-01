#include<iostream>
using namespace std;

class node{
  public:
  // data
  int data;
 // pointer of the next node
  node * next;
 // constructer
  node(){
   next =NULL;
      }
  };

class linkedlist{
// head and nodes 
  public:
 // node type pointer head and tail
  node* head;
  node* tail;
  
//constructer
  linkedlist(){
  head=NULL;
  tail=NULL;
   }
	//declear insert function
	void insert(int value){
		// temp has adderss of new node
		node* temp=new node;
		//data of temp is value
		temp->data=value;
		//1st node only
		if(head==NULL){
			head=temp;
		}
		//others
		else{
			tail->next=temp;
		}
		tail=temp;
        
	}
//declear insertat function
void insertat(int pos,int value){
// reaching in the place
     node* current=head;
     node*temp=new node;
     temp->data=value;
 if(pos==1) {
  if(head==NULL){
    head=temp;
    tail=temp;
      }
     
      
 else {
// connect new node with before and next node
     temp->next=current->next;
     current->next=temp;
         } 
      }
     }
//declear function to delete at last
void delet(){
// store tail in the temp
     node* temp=tail;
     node* current = head;
// except last node
     while(current->next->next!=NULL){
     current = current->next;
         }
     current->next=NULL;
      // update tail
     tail=current;
     delete temp; 
       }
// new function display
void display(){
     node * current=head;
// display of the value of all nodes
     while(current !=NULL){
     cout<<current->data<<"->";
     current = current->next;
         }
     cout<<endl;
       } 
void deletat(int pos){
   node* current= head;
   node* temp=head;
if(pos==1){
 head=head->next;
  }
else  {
  
  
  for(int i=1;i<pos-1;i++){
   current=current->next;}
  for(int i=1;i<pos+1;i++){
    temp=temp->next;}
         
      }
 current->next=temp;

     }
 void countitems(){
 node* current=head;
  int count=1;
 while(current->next!=NULL){
   
    count++;
  current=current->next;
   
      }
  cout<<"countitems"<<count<<endl;
   }
 };
   
 
   

/*int main(){
    linkedlist l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(7);
    l1.display();
    l1.deletat(3);
    l1.display();
    l1.delet();
    l1.display();
    l1.insertat(1,8);
    l1.display();
    l1.countitems();
    return 0;
}*/

