#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node* next;

    node(int d)
    {
        data=d;
        next=NULL;
    }
};

void InsertAtEnd(int data,node*&head,node*&tail){
   if(head==NULL){
    node*n=new node(data);
    head=tail=n;
   }
   else{
    node*n=new node(data);
    tail->next=n;
    tail=n;

    }
}

void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void BubbleSort(node*&head,int i,int n)
{
    if(i==n-1)
    {
        return;
    }

    node* currentnode;
    node* prevnode;
    node* nextnode;

    currentnode=head;
    prevnode=NULL;
    while((currentnode && currentnode->next)!=NULL)
    {
        nextnode=currentnode->next;
        if(currentnode->data > nextnode->data)   //swap
        {
            if(prevnode==NULL)
            {
                currentnode->next=nextnode->next;
                nextnode->next=currentnode;
                head=nextnode;
                prevnode=nextnode;
            }
            else
            {
                currentnode->next=nextnode->next;
                nextnode->next=currentnode;
                prevnode->next=nextnode;
                prevnode=nextnode;
            }
        }
        else  //no swap
        {
            prevnode=currentnode;
            currentnode=currentnode->next;
        }
    }
    BubbleSort(head,i+1,n);

}

int main()
{
    node* head=NULL;
    node* tail=NULL;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        InsertAtEnd(arr[i],head,tail);
    }


    BubbleSort(head,0,n);
    print(head);
}
