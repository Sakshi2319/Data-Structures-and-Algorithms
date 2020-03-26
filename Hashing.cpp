#include<iostream>
using namespace std;

template <typename T>
class node{
  public:
      string key;
      T value;
      node<T>*next;
      node(string k,T v){
      key=k;
      value=v;
      }
      /*~node(){
       if(next){
        delete next;
        next=NULL;
       }
      }*/
};

template<typename T>
class hashmap{
    node<T>**Bucket;//bucket banani hai of node* type
    int ts; //table size
    int cs;//current size
//--------------hash function----------------------------------------
    int hashFn(string key){
       int multiplicationfactor=1;
       int ans=0;
       for(int i=0;key[i]!='\0';i++){
          ans+=multiplicationfactor*key[i];
          multiplicationfactor*=37;
          ans%=ts;
          multiplicationfactor%=ts;

       }
       return ans%ts;//koi dikkat nahi

    }
//-------------------rehash-------------------------------------------
    void rehash(){
    node<T>**oldBucket=Bucket;
    int oldts=ts;

    Bucket=new node<T>*[2*ts];
    ts=2*ts;
    cs=0;
    for(int i=0;i<ts;i++){
        Bucket[i]=NULL;
    }
    for(int i=0;i<oldts;i++){
     node<T>* temp =oldBucket[i];

     while(temp){
        Insert(temp->key,temp->value);
        temp=temp->next;
       }
     delete oldBucket[i]; //linked list deleting node by node
    }
    delete []oldBucket;

  }
  //--------------------------------------------------------------------
   public:

       hashmap(int s=7){ //constructor
          ts=s;
          cs=0;
          Bucket= new node<T>*[ts]; //new node*[n]

          for(int i=0;i<ts;i++){
            Bucket[i]=NULL;//since pointer hai and not pointing to a valid location so initially to NULL
          }
       }

//---------------------------------------Insert------------------------------------------------
    void Insert(string key,T value){
        int i=hashFn(key);//i is hash index


        node<T> *n= new node<T>(key,value);
        n->next=Bucket[i];
        Bucket[i]=n; //insertion at front
         cs++;

         float load_factor= cs/(ts*1.0);//table kitni full hai
         if(load_factor>0.7){ //70% se zyada bhar gayi ho toh
            rehash();
         }

     }
//--------------------------------------Search-------------------------------------------------------
        T* Search(string key){//returning value of T type and we want to return null isliye pointer bhi
           int i=hashFn(key);
        node<T>*temp=Bucket[i];

        while(temp){
            if(temp->key==key){
                return &(temp->value);
            }
            temp=temp->next;
        }
        return NULL;

      }
//-------------------------------Operator overloading-----------------------------------------------------------
     T& operator[](string key){ //returning by reference bec actually we want to change jo neeche change honge woh update ho jaayenge
        T*ans=Search(key);//value bucket ka address

        if(ans==NULL){
                T garbage;
            Insert(key,garbage);
             ans = Search(key);
             return *ans;
          }
        else{
            return *ans;//derefer krke value bucket bec woh reference retuen kr rha tha
        }

    }
//----------------------------------remove--------------------------------------------------------------------------
void Remove(string key){
    int i=hashFn(key);
    node<T>*temp=Bucket[i];
    //now iterate through linked list and deletion from linked list
    if(temp->next==key){
        delete temp;
        temp=NULL;
    }
    else {
       node<T>*n=temp;
       temp=temp->next;
       delete n;
    }


}
//----------------------------------------Print--------------------------------------------------------------------

 void  Print(){
  for(int i=0;i<ts;i++){
    cout<<i<<"-->";
    node<T>*temp=Bucket[i];
    while(temp){
        cout<<temp->key<<"," ;
        temp=temp->next;
    }
    cout<<endl;
  }

 }

//-----------------------------------------------------------------------------------------------------------------


};

int main(){
hashmap<int> h;
h.Insert("Mango",100);
h.Insert("Pineapple",50);
h.Insert("Apple",150);
cout<<h["Mango"]<<endl;
h["Mango"]=200;//updation
cout<<h["Mango"]<<endl;//search

h["Guava"]=30;//insertion
h["Kiwi"]=60;

h.Print();
h.Remove("Pineapple");
h.Print();




return 0;
}
