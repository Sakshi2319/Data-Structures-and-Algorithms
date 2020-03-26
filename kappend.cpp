#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;

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
void print(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}


 node* kappend(node* &head,node* prev,node* temp,int k)
{
    while(k>0)
    {
        int i=1;
        int j=1;
        if(j<=k)
        {
            while(i<length(head)-j)
            {
                temp = temp->next;
                i++;
                }
            prev = temp;
            temp = temp->next;
            prev->next = temp->next;
            temp->next = head;
            head = temp;
            k--;
            j++;
        }
    }
    return head;
}


int main()
{
	node* head=NULL;
	node* tail=NULL;

	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		InsertAtEnd(a[i],head,tail);
	}
	int k;
	cin>>k;

    if(k>length(head))
    {
        k = k%length(head);
        node* a =kappend(head,NULL,head,k);
        print(a);
    }
    else
    {
        node* c =kappend(head,NULL,head,k);
        print(c);
    }
	return 0;
}

