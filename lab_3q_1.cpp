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

class csll{
// head and nodes 
  public:
 // node type pointer head 
  node* head;
 
  
//constructer
  csll(){
  head=NULL;
  
   }
	//declear insert function
	void insert(int value){
		// temp has adderss of new node
		node* temp=new node;
		//data of temp is value
		temp->data=value;
		//no node present
		if(head==NULL){
			head=temp;
		}
		//others
		else{
	     node * current = head;
            while(current->next != head)
                current = current->next;
            current->next = temp;
               
		}
	   temp->next=head;	
        
	}
//declear insertat function
void insertat(int pos,int value){
// reaching in the place
     node* current=head;
   
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
     current->next=temp;
         
     }
//declear function to delete at last
void delet(){
// store tail in the temp
     node* last;
     node* current = head;
// except last node
     while(current->next->next!=head){
     current = current->next;    
         }
     last=current->next;
     current->next=head;
    // last=current;
     delete last ; 
}
// new function display
void display(){ node *current = head;
        
        while(current==NULL){
           cout<<"no element present"<<endl;
            return;
                } 
        cout << "Print in  order : ";
        while(current->next!=head){
            cout <<current->data<< "->";
            current=current->next;
        }
        cout<<current->data;
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
   current=current->next;
    
     }
  for(int i=1;i<pos+1;i++){
    temp=temp->next;
    
       }
         
      }
 current->next=temp;
 

     }
 void countitems(){
 node* current=head;
  int count=1;
 while(current->next!=head){
   
    count++;
   current=current->next;
   
      }
  cout<<"countitems"<<count<<endl;
   }
 };
   
 
   

int main(){
    csll l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(7);
    l1.insertat(6,9);
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

     
     
     
     

   

