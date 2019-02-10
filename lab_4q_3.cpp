
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
void inserthead(int value){
       node* temp=new node;
        temp->data=value;
       temp->next=head;
       head=temp;  
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


class queuell{
// top and nodes 
  public:
 // node type pointer top
  node* top;
  linkedlist l1;
  node* front,rear;
 queuell(){
   front=NULL;
   rear=NULL;
   top=l1.head;
     }
 
//declear insertat function
void enqueue(int value){

     l1.inserthead(value);
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
 int dequeue(){
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
      return true;
       }
    else{
     return false;
       }
     }
 bool isemp(){
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
/*int main(){
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
}*/
class stackll{
 public:
 queuell q1,q2;
 void push(int x){
      q1.enqueue(x);
         }
void pop(){
      int n=q1.size();
      int i;
      if(q1.isempty()==true){
       cout<<"stack is empty"<<endl;
             }
      else{
       while(i<n-1){
        q1.dequeue();
        q1.enqueue(q1.front->data);
           }
        q1.dequeue();
        }
      }
  void display(){
      q1.display();
       }
  int size(){
      q1.size();
        }
  bool isempty(){
       q1.isemp();
         }
  int topdisplay(){  
    int n=q1.size();
      int i;
      if(q1.isempty()==true){
       cout<<"stack is empty"<<endl;
             }
      else{
       while(i<n-1){
       
        q1.enqueue(q1.front->data);
        q1.dequeue();
           }
        q1.frontdisplay();
    //cout<<"top is:"<<x<<endl;
        }
      }
   };
int main(){
    stackll s1;
    for(int i=1;i<10;i++){
      s1.push(i);
        }
    s1.display();
    s1.pop();
    s1.display();
    s1.size();
    s1.topdisplay();
    s1.isempty();
    return 0;
      }
   
 
 
