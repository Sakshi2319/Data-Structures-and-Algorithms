#include<iostream>
using namespace std;
class node
{
  public:
  int data;
  node* next;
  node(int d):data(d),next(NULL){
  }
};
int length(node* head)
{
    int i=0;
    while(head)
    {
        head = head->next;
        i++;
    }
    return i;
}

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

void print(node*&head){
 while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
 }
 cout<<endl;
}

node* Reverse(node* &head,int k)
{
	node* temp = head;
    node* prev = NULL;
    node* Next = NULL;
    int i=0;
    while(temp !=NULL && i<k)
    {
        Next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = Next;
        i++;
    }
    if(Next!=NULL)
    {
        head->next = Reverse(Next,k);
    }

    return prev;;
}

int main() {

    node* head=NULL;
    node* tail =NULL;
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
	{
		cin>>a[i];
		InsertAtEnd(a[i],head,tail);
	}
    node*c =Reverse(head,k);
    print(c);
	return 0;
}
