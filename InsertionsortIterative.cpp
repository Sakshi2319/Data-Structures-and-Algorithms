//iterative insertion sort
#include <iostream>
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
void Print(node* head)
{
    while(head!=0)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int length(node* head)
{
	int i=0;
	while(head!=NULL)
	{
		i++;
		head=head->next;
	}
	return i;
}
//------------------------------------------------------
void InsertionsortRec(node *&head,node* temp)
{
    if(head == NULL || temp==NULL)
    {
        return;
    }
    while(temp!=NULL){
    node *n=head;

    while(n!=temp)
    {
      if(n->data >= temp->data) //swap
      {
        int x=temp->data;
        temp->data=n->data;
        n->data=x;
      }
      else
      {
        n=n->next;
      }
    }
    temp=temp->next;
  }
}
//-----------------------------------------------------------------
int main()
{
    node* head= NULL;
    node* tail= NULL;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        InsertAtEnd(a[i],head,tail);
    }

    InsertionsortRec(head,head->next);
    Print(head);
    return 0;
}

