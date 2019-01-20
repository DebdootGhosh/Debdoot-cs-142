#include<iostream>
using namespace std;

class node{
  public:
  // data
  int data;
 // pointer of the next node
  node * next;
  node* prev;
 // constructer
  node(){
   next =NULL;
   prev=NULL;
      }
  };

class dll{
// head and nodes 
  public:
 // node type pointer head and tail
  node* head;

  
//constructer
  dll(){
  head=NULL;
  
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
	     node * current = head;
            while(current->next != NULL)
                current = current->next;
            current->next = temp;
            temp->prev = current;    
		}
		
        
	}
//declear insertat function
void insertat(int pos,int value){
// reaching in the place
     node* current=head;
 
 if(current>=NULL) {
 cout<<"Linked List does not have that many elements"<<endl;
      }
 else {
     int i=1;
     while(i<pos-1){
     i++;
     current=current->next;
       }
// declear of new node 
     node* temp=new node;
     temp->data=value;
// connect new node with before and next node
     temp->next=current->next;
     current->next->prev=temp;
     current->next=temp;
     temp->prev=current;
         }
     }
//declear function to delete at last
void delet(){
// store tail in the temp
     node* last;
     node* current = head;
// except last node
     while(current->next!=NULL){
     current = current->next;    
         }
last=current->next;
     current->next=NULL;
    // last=current;
     delete last ; 
       }
// new function display
void display(){ node *current = head;
        node *last;
        cout << "Print in   order : ";
        while(current!=NULL){
            cout <<current->data<< "->"; 
            // Store the current in last (to catch the tail to print in reverse)
            last = current;
            // Move Forward
            current = current->next;
        }
        cout << endl;
        cout << "Print in R order : ";
        while(last!=NULL){
            cout <<last->data<< "->";
            // Move backwards 
            last = last->prev;
        }
        cout << endl;   
    
       } 
void deletat(int pos){
   node* current= head;
   node* temp=head;
if(pos==1){
 head=head->next;
  }
else  {
  
  
  for(int i=1;i<pos-1;i++){
   current=current->next;
   current->next->prev=current;
    
     }
  for(int i=1;i<pos+1;i++){
    temp=temp->next;
    temp->next->prev=temp;
       }
         
      }
 current->next=temp;
 temp->prev=current;

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
   
 
   

int main(){
    dll l1;
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
    l1.insertat(7,8);
    l1.display();
    l1.countitems();
    return 0;
}

     
     
     
     

   

