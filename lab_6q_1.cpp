  #include<iostream>
  using namespace std;
  class node{
  public:
  int data;
  node* right;
  node* left;
  node(int val){
   data=val;
   right==NULL;
   left==NULL;
      }
    };
  class BiST{
  public:
     node* root;
     BiST(){
       root=NULL;
             }
      void insert(int val){
           inserthelper(root,val);
           
            }
      void inserthelper(node* curr,int val){
           // base case if curr is NULL,insert there.
           if(curr==NULL){
             curr= new node(val);
             if (root==NULL) root=curr;
              return;
                 }
   //else compare the curr data with value
            else if(val<curr->data){
   //if value<curr data->move left and call interhelper
           // if left is null insert it.
           if(curr->left==NULL) curr->left=new node(val);
          else inserthelper(curr->left,val);
               }
           else {
             // else move right and inserthelper
            if(curr->right==NULL) curr->right=new node(val);
             else inserthelper(curr->right,val);
                    }
              }
      void display(){display2(root);}
      void display2(node* curr){
       //base condition
       if(curr==NULL) 
	return;
       //display left
       	
         display2(curr->left);
	
       //display current
         cout<<curr->data<<",";
       //display right
        display2(curr->right);
         //cout<<curr->data<<",";
	
           }
              
      node* search(node*curr,int val){
            // if value found or reached end of tree
            if(curr == NULL|| curr->data==val) return curr;
            else if (val<curr->data) return search (curr->left,val);
            else return search(curr->right,val);
                     }
       };
int main(){
    BiST bist1;
//    for(int i=1;i<10;i++){
    bist1. insert(10);
    bist1. insert(13);
    bist1. insert(5);
    bist1. insert(9);
    bist1. insert(11);
//bist1. insert(i);


    bist1.display();
    int n;
    cout<<endl;
    cout<<"Enter n:"<<endl;
    cin>>n;
   if(bist1.search(bist1.root,n)!=NULL) cout<<"Present"<<endl;
  else cout<<"absent"<<endl;
        }
    


