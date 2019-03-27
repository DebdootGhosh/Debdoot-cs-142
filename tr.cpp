  #include<iostream>
  using namespace std;
  class node{
  public:
  int data;
  node* right;
  node* left;
  node* parent;
  node(int val){
   data=val;
   right==NULL;
   left==NULL;
   parent==NULL;
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
           if(curr->left==NULL){ curr->left=new node(val);
            curr->left->parent=curr;}
           else inserthelper(curr->left,val);
               }
           else {
             // else move right and inserthelper
            if(curr->right==NULL) {curr->right=new node(val);
             curr->right->parent=curr;}
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
  
    node*find_min(node* curr) {
          if(curr!=NULL) {
         if(curr->left!=NULL){
           while(curr->left!=NULL){
            curr=curr->left;
                    }
               return curr;
                  }
           else {
           return curr;
               }
           }
         else {
          cout<<"invalid"<<endl;
                  }
              }
    void replace_at_parent(node*A,node*B){
         
       // B=A;
  if(A->parent->data>A->data) A->parent->left=B;
  else A->parent->right=B;
 // A->parent=NULL;
  A->right=NULL;
  A->left=NULL;
B=A;
A->parent=NULL;
               }
        void binary_delete(node * curr, int val){
        if(curr==NULL) cout<<"invalid"<<endl;
        else if(val>curr->data) binary_delete(curr->right,val);
        else if(val<curr->data) binary_delete(curr->left,val);
        else {
            if(curr->left==NULL && curr->right==NULL){
if(curr->parent->data>curr->data) curr->parent->left=NULL;
  else curr->parent->right=NULL;
curr->parent=NULL;
                  delete curr;
                         curr==NULL;
                         }
              else if(curr->left==NULL && curr->right!=NULL){
                    // node* temp=root;
                      //     root=root->right;
                           replace_at_parent(curr,curr->right);
                           delete curr;
                            //temp==NULL;
                    }
                    else if(curr->right==NULL&& curr->left!=NULL){
                         //   node* temp=root;
                         //         root=root->left;
                                  replace_at_parent(curr,curr->left);
                                  delete curr;
                                 // temp==NULL;
                          }
                          else{
                               node* temp=find_min(curr->right);
                               int z=curr->data;
                               curr->data=temp->data;
                                temp->data=z;
                              // binary_delete(root->right,temp->data);
                                 delete temp; }
              }
        //return root;
      }
  void print2DUtil(node *root, int space)  
    {  
        // Base case  
        if (root == NULL)  
            return;  
        // Increase distance between levels  
        space += 5;  
        // Process right child first  
        print2DUtil(root->right, space);  
    
        // Print current node after space  
        // count  
        cout<<endl;  
        for (int i = 5; i < space; i++)  
            cout<<" ";  
        cout<<root->data<<"\n";  
    
        // Process left child  
        print2DUtil(root->left, space);  
    }  
  
    // Wrapper over print2DUtil()  
    void print2D()  
    {  
        cout << "******************************" << endl;
        // Pass initial space count as 0  
        print2DUtil(root, 0);  
        cout << "******************************" << endl;
        
    }


       };
/*   BiST bist1;

    bist1. insert(10);
    bist1. insert(13);
    bist1. insert(5);
    bist1. insert(9);
    bist1. insert(11);

    bist1.display();
    int n;
    cout<<endl;
    cout<<"Enter n:"<<endl;
    cin>>n;
   if(bist1.search(bist1.root,n)!=NULL) cout<<"Present"<<endl;
   else cout<<"absent"<<endl;
   if(bist1.find_min(bist1.root)==NULL) cout<<"min absent"<<endl;
   //else if(bist1.find_min(bist1.root->left)==NULL) cout<<"min is"<<bist1.root->data<<endl;
   else cout<<"min is"<<bist1.find_min(bist1.root)->data<<endl;
 //bist1.find_min(bist1.root->left);
  // node* R;
   //R->data=15;
   bist1.replace_at_parent(bist1.search(bist1.root,13),bist1.search(bist1.root->right,11));
   bist1.display();
   cout<<endl;
   bist1.binary_delete(bist1.root,10);
   bist1.display();
     }*/
 int main(){
    
    BiST bst1;
    bst1.insert(4);
    bst1.insert(2);
    bst1.insert(3);
    bst1.insert(1);
    bst1.insert(6);
    bst1.insert(5);
    bst1.insert(7);
    bst1.insert(8);
   // bst1.insert(9);
    bst1.display();
   // if(bst1.search(3) != NULL){
      //  cout << endl << bst1.searchHelper(3)->data << endl;
   // }
      int n;
    cout<<endl;
    cout<<"Enter n:"<<endl;
    cin>>n;
     if(bst1.search(bst1.root,n)!=NULL) cout<<"Present"<<endl;
   else cout<<"absent"<<endl;
    bst1.print2D();
  bst1.replace_at_parent(bst1.search(bst1.root,13),bst1.search(bst1.root->right,11));
   // bst1.print2D();
    if(bst1.find_min(bst1.root)==NULL) cout<<"min absent"<<endl;
    else cout<<"min is"<<bst1.find_min(bst1.root)->data<<endl;
  // bst1.print2D();
    bst1.binary_delete(bst1.root,5);
    bst1.print2D();
    bst1.display();
    bst1.binary_delete(bst1.root,6);
    bst1.print2D();
      bst1.display();
    cout << "Deleting 2" << endl;
    bst1.binary_delete(bst1.root,2);
    bst1.print2D();
      bst1.display();
    bst1.binary_delete(bst1.root,4);
    bst1.print2D();
      bst1.display();
    bst1.binary_delete(bst1.root,7);
    bst1.print2D();
      bst1.display();
    bst1.binary_delete(bst1.root,8);
    bst1.print2D();
      bst1.display();
    bst1.binary_delete(bst1.root,3);
    bst1.print2D();
      bst1.display();
    bst1.binary_delete(bst1.root,1);
    bst1.print2D();
      bst1.display();
   // bst1.binary_delete(bst1.root,9);
    bst1.print2D();
      bst1.display();

}
        
   


