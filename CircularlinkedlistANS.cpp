#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node*next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertattail(node*&head, int d)
{
    if (head == NULL)
    {
        head=new node(d);
        return;
    }
    node*n = new node(d);
    node*temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

bool check(node*head,int d)
{
    while(head!=NULL)
    {
        if(head->data==d)
           return true;
        head=head->next;
    }
    return false;
}

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
            if(check(head,d)==false)     //if element already not present then insert at tail
            {
               insertattail(head,d);
            }
            else                         // if already present
            {
                node*temp=head;
                while(temp->next!=NULL)   //go to the last node
                {
                    temp=temp->next;
                }
                node*repeat=head;
                while(repeat->data!=d)    //go the the node with repeated element
                {
                   repeat=repeat->next;
                }
                temp->next=repeat;        //put repeated element in the last node
                flag=0;
            }
        }

        cin>>d;
    }
}

void print(node*head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

bool checkfloydcycle(node*&head)
{
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
void floydcycle(node*&head)
{
    node*slow=head;
    node*fast=head;
    while(fast!=NULL and fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow)
        break;
    }
    slow=head;
    if(slow==fast)
    {
        while(fast->next!=slow)
        {
            fast=fast->next;
        }
        fast->next=NULL;
    }
    else{
    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=NULL;
    }
}

int main()
{
    node*head=NULL;
    buildlist(head);
    if(checkfloydcycle(head)==true)
    {
        floydcycle(head);
    }
    print(head);


}
