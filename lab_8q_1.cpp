 #include<iostream>
  using namespace std;
  int n=1;
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
            cout<<search2(root,val)<<endl;
            return search2(root,val);
                    }
    node*find_min(node* curr) {
           	while(curr->left!=NULL)
            	curr=curr->left;
		return curr;             
              }
     int CountNodes(node*curr)
     {  
	if(curr==NULL)
		return 0;
        else 
         return CountNodes(curr->left)+1+CountNodes(curr->right);
	/*if(curr->left!=NULL)
	{
		n=n+1;
		CountNodes(curr->left);
	}
	if(curr->right!=NULL)
	{
		n=n+1;
		CountNodes(curr->right);
	}
	//cout<<"countnode is:"<<n<<endl;
	return n;*/
        }
    void rangesearch(node *curr, int k1, int k2)  
   {  
    /* base case */
    if ( NULL == curr )  
       // return 0;  
      
    /* Since the desired o/p is sorted,  
        recurse for left subtree first  
        If root->data is greater than k1,  
        then only we can get o/p keys  
        in left subtree */
    if ( k1 < curr->data )  
        rangesearch(curr->left, k1, k2);  
       // return rangesearch(curr->left, k1, k2);
    /* if root's data lies in range,  
    then prints root's data */
    if ( k1 <= curr->data && k2 >= curr->data )  
        cout<<curr->data<<" ";  
     // return 1 + rangesearch(curr->left, k1,k1) + 
                    //rangesearch(root->right,k1, k2);
    /* If root->data is smaller than k2, 
        then only we can get o/p keys  
        in right subtree */
    if ( k2 > curr->data )  
        rangesearch(curr->right, k1, k2);
        //return rangesearch(curr->right, k1, k2);
  
    // Special Optional case for improving efficiency 
   // if (curr->data == k2 && curr->data == k1) 
      //  return 1;    
    }
    void rangesearch2(int k1,int k2)  {
    rangesearch(root,k1,k2);
        }
    int height(node* curr)  
  {  
    if (curr == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lheight = height(curr->left);  
        int rheight = height(curr->right);  
      
        /* use the larger one */
        if (lheight > rheight)  
            return(lheight + 1);  
        else return(rheight + 1);  
     }  
   }  
      };
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
    cout<<"countnode is:"<< bst1.CountNodes(bst1.root)<<endl;
    cout<<"countnode is:"<< bst1.CountNodes(bst1.root)<<endl;
    bst1.rangesearch2(2,7);
   // cout<<" number of nodes between the range is:"<<bst1.rangesearch2(2,7)<<endl;
    cout<<"height of the bst is :"<<bst1.height(bst1.root)<<endl;
     cout<<"height of the bst is :"<<bst1.height(bst1.root)<<endl;
    return 0;
      }

 
