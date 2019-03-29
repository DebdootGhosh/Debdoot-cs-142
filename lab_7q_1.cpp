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
              
      node* search2(node*curr,int val){
            // if value found or reached end of tree
            if(curr == NULL|| curr->data==val) return curr;
            else if (val<curr->data) return search2 (curr->left,val);
            else return search2(curr->right,val);
                     }
      node* search(int val){
            return search2(root,val);
                    }
    node*find_min(node* curr) {
           	while(curr->left!=NULL)
            	curr=curr->left;
		return curr;             
              }
    void replace_at_parent(node*A,node*B){
         
		  if(A->parent->data>A->data) A->parent->left=B;
  		  else A->parent->right=B;
   		  B=A;
                  A->left==NULL;
                  A->right==NULL;
                  A->parent==NULL;
               }

       /*
        void binary_delete(node * curr, int val){
        if(curr==NULL) cout<<"invalid"<<endl;
        else if(val>curr->data) binary_delete(curr->right,val);
        else if(val<curr->data) binary_delete(curr->left,val);
        else {
	    //no child
            if(curr->left==NULL && curr->right==NULL){
		if(curr->parent->data > curr->data) curr->parent->left=NULL;
		  else curr->parent->right=NULL;
                  delete curr;
                         }
	   //single right child
            else if(curr->left==NULL && curr->right!=NULL){
                           replace_at_parent(curr,curr->right);
                           delete curr;
                   	}
	   //single left child
             else if(curr->right==NULL&& curr->left!=NULL){
                           replace_at_parent(curr,curr->left);
                                  delete curr;
                                
                          }
	   //two child swap with succesor
              else{            node* temp=find_min(curr->right);
                               int z=curr->data;
                               curr->data=temp->data;
                               temp->data=z;

                               if(temp->right==NULL and temp->left==NULL)//free child
				{
					//just right child
					if(curr->right==temp)
					{curr->right=NULL; delete temp;}
					else { temp->parent->left=NULL;
						delete temp;}					

				}
				else {replace_at_parent(temp,temp->right);delete temp;}
			}
              }
      }*/
void swap(node * A,node * B)
    {
        //Swapping using third variable (:P)
        int temp=A->data;
        A->data=B->data;
        B->data=temp;
    }
void binary_delete(int value)
    {
        if(search(value)!=NULL)//checks whether the value is present in the tree or not
        {
            if(root->data!=value)//if value is not equal to root's value
            {
                node * curr=search(value);//points to the node containing value
                if(curr->left==NULL && curr->right==NULL)//if curr is leaf
                {
                    if(curr->parent->data>curr->data)//checks curr postion with respect to its parent
                    {
                        curr->parent->left=NULL;
                    }
                    else
                    {
                        curr->parent->right=NULL;
                    }
                    curr->parent=NULL;
                    delete curr;
                }
                else if(curr->left==NULL && curr->right!=NULL)//if curr has only one child(i.e right)
                {
                    replace_at_parent(curr,curr->right);//replace curr with curr's right node
                    delete curr;
                }
                else if(curr->left!=NULL && curr->right==NULL)//if curr has only one child(i.e left)
                {
                    replace_at_parent(curr,curr->left);//replace curr with curr's left node
                    delete curr;
                }
                else //if curr has two children
                {
                    swap(curr,find_min(curr->right));//swap values of curr and min in its right subtree
                    curr=find_min(curr->right);//reach to the required deleted value after swapping
                    if(curr->right!=NULL)//if curr has right child
                    {
                        curr->parent->right=curr->right;
                        curr->right->parent=curr->parent;
                        curr->right=NULL;
                    }
                    else //otherwise
                    {
                        //if curr is leaf and present at its parent's right
                        if(curr->parent->right->data==curr->data)
                        {
                            curr->parent->right=NULL;
                        }
                        else //otherwise
                        {
                            curr->parent->left=NULL;
                        }
                    }
                    curr->parent=NULL;
                    delete curr;
                }
                    
            }
            else //if deleted node is root
            {
                node * curr=root;
                //checks all the conditions previously checked and modify root
                if(curr->left==NULL && curr->right==NULL)
                {
                    root=NULL;
                    delete curr;
                }
                else if(curr->left==NULL && curr->right!=NULL)
                {
                    root=curr->right;
                    delete curr;
                }
                else if(curr->left!=NULL && curr->right==NULL)
                {
                    root=curr->left;
                    delete curr;
                }
                else
                {
                    swap(curr,find_min(curr->right));
                    curr=find_min(curr->right);
                    if(curr->right!=NULL)
                    {
                        curr->parent->right=curr->right;
                        curr->right->parent=curr->parent;
                        curr->right=NULL;
                    }
                    else
                    {
                        curr->parent->left=NULL;
                    }
                    curr->parent=NULL;
                    delete curr;
                }
            }
        }
        else //if value is absent in the tree
        {
            cout<<"Invalid node for deletion"<<endl;
        }
        
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
    bst1.insert(1);
    bst1.insert(2);
    bst1.insert(3);
    bst1.insert(4);
    bst1.insert(5);
    bst1.insert(6);
    bst1.insert(7);
    bst1.insert(8);
    bst1.insert(9);
    bst1.display();
   // if(bst1.search(3) != NULL){
      //  cout << endl << bst1.searchHelper(3)->data << endl;
   // }
      int n;
    cout<<endl;
    cout<<"Enter n:"<<endl;
    cin>>n;
    if(bst1.search2(bst1.root,n)!=NULL) cout<<"Present"<<endl;
    else cout<<"absent"<<endl;
   // bst1.print2D();
//  bst1.replace_at_parent(bst1.search(bst1.root,13),bst1.search(bst1.root->right,11));
   // bst1.print2D();
   // if(bst1.find_min(bst1.root)==NULL) cout<<"min absent"<<endl;
   // else cout<<"min is"<<bst1.find_min(bst1.root)->data<<endl;
  // bst1.print2D();
    bst1.binary_delete(5);
    //bst1.print2D();
    bst1.display();cout<<endl;
    bst1.binary_delete(6);
    bst1.display();cout<<endl;


    cout << "Deleting 7" << endl;
    bst1.binary_delete(7);
    cout<<endl;
    bst1.display();
    bst1.binary_delete(4);
    bst1.display();cout<<endl;
    bst1.binary_delete(2);
    bst1.display();cout<<endl;
    bst1.binary_delete(8);
    bst1.display();cout<<endl;
    bst1.binary_delete(3);
    bst1.display();
    bst1.binary_delete(1);
    bst1.display();
    bst1.binary_delete(9);
    bst1.display();
    return 0;
    }
        
   


