#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*next;
    node(int d){
    data=d;
    next=NULL;
    }

};
void InsertAtEnd(int data,node*&head){
  if(head==NULL){
    node*n=new node(data);
    return;
  }
    node*n = new node(data);
    node*temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}



void print(node*&head){
 while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
 }
}
bool check(node*head,int d) //already woh element exists or not
{
    while(head!=NULL)
    {
        if(head->data==d)
           return true;
        head=head->next;
    }
    return false;
}

//------------------------------------
void buildlist(node*&head)
{
    int d;
    cin>>d;
    head=new node(d);
    cin>>d;
    int flag=1;
    while(d!=-1)
    {
         if( flag==1)
        {
            if(check(head,d)==false)
            {
               InsertAtEnd(d,head);
            }
            else
            {
                node*temp=head;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                node*repeat=head;
                while(repeat->data!=d)
                {
                   repeat=repeat->next;
                }
                temp->next=repeat;
                flag=0;
            }
        }
        cin>>d;
    }
}

//----------------------------------------
bool detectcycle(node*head){
  node*slow=head;
  node*fast=head;

  while(fast!=NULL and fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow)
        return true;
    }
    return false;
}
//--------------------------------------------
//run time error see the correct ans
void BreakCycle(node*head){
node* slow = head;
node* fast = head;
node*prev;
	while(fast!=NULL and fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow)
        break;
    }
            if(slow==fast)  //removing the loop if it exists
            {
                slow = head;

                while(fast!=slow)
                {
                    prev=fast;
                    fast = fast->next;
                    slow = slow->next;

                }
                prev->next = NULL;//remove loop
            }

    return;
}

//---------------------------------------------------

int main(){
node*head=NULL;
 node*tail=NULL;

 /*int arr[100000];
 for(int j=0;j<100000;j++){
    cin>>arr[j];
    if(arr[j]==-1)
        break;
    InsertAtEnd(arr[j],head,tail);
    }
*/

buildlist(head);
 if(detectcycle(head)){
        BreakCycle(head);
 }
  print(head);



return 0;
}
