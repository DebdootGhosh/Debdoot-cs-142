#include<iostream>
using namespace std;
class binaryheap{
 public:
       int* harr;
       int msize;
       int csize;
       binaryheap(int msize){
         harr=new int [msize];
         this->msize= msize;
         csize=0;
           }
           
          void swap(int *a,int *b){
                int temp=*a;
                *a=*b;
                *b=temp;
                }
                
              int parent(int i){return (i-1)/2;}
              int left(int i){return (i*2)+1;}
              int right(int i){return (i*2)+2;}
              int getmin(){return harr[0];}
              void insert(int val){
                if(csize==msize){
                cout<<"heap is overloaded"<<endl;
                   }
                   int i=csize++;
                   //csize++;
                   harr[i]=val;
                   while(i!=0 && harr[parent(i)]>harr[i]){
                    swap(&harr[parent(i)],&harr[i]);
                    i=parent(i);
                    }
                       }
                       
                  void display(){
                       for(int i=0;i<csize;i++){
                        cout<<harr[i]<<",";
                            }
                        cout<<endl;
                        }
                  int extractmin(){
                      if(csize<=0)
                      return harr[csize-1];
                      if(csize==1){
                      csize--;
                      return harr[0];
                        }
                        int root=harr[0];
                        harr[0]=harr[csize-1];
                        csize--;
                        Minheapify(0);
                        return root;
                          }
                   void decreasekey(int i,int newval){
                       
                        harr[i]=newval;
                        while (i!=0 && harr[parent(i)]>harr[i]){
                        swap(&harr[parent(i)],&harr[i]);
                         i=parent(i);
                            }
                          }
                   
                   int deletkeyat(int i){
                       decreasekey(i,harr[0]-7);
                       extractmin();
                          }
                    void Minheapify(int i){
                         int l=left(i);
                         int r=right(i);
                         int smallest=i;
                         if(l<csize && harr[l]<harr[i])
                           smallest=l;
                         if(r<csize && harr[r]<harr[i])
                           smallest=r;
                           if(smallest!=i){
                             swap(&harr[i],&harr[smallest]);
                             Minheapify(smallest);
                                   }
                                 }
                               };
    int main(){
    binaryheap bh1(20);
    for(int i =11; i>0 ; i--){
        cout << "Inserting " << i << endl;
        bh1.insert(i);
        bh1.display();
           }
    bh1.extractmin();
    bh1.display();
    bh1.deletkeyat(3);
    bh1.display();
    cout << endl;
     }   
                          
                        
                   
                   
                 
                   
                          
                     
                        
                   
                    
