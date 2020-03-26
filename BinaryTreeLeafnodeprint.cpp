#include<iostream>
using namespace std;
#include<queue>

class node{
public:
    int data;
    node*left;
    node*right;
    node(int d): data(d),left(NULL),right(NULL){}

};

node*  InputTreeLevelorder(){
 node*root=NULL;
 //cout<<"Enter Root Node:";
 int data;
 cin>>data;
 root=new node(data);

 queue<node*>q;
 q.push(root);

  while(!q.empty()){
    node* temp=q.front();
    q.pop();
    //cout<<"Enter children of: "<<temp->data<<" ";
    int c1,c2;
    cin>>c1>>c2;
    if(c1!=-1){   //mtlb NULL
        temp->left=new node(c1);
        q.push(temp->left);
    }
    if(c2!=-1){
        temp->right=new node(c2);
        q.push(temp->right);
    }
 }
 return root;

}
void Printleafnodes(node*root){
    if(root==NULL)  //tree hi nahi hai
        return;
    if(!root->left && !root->right){ //leaf node
        cout<<root->data<<" ";
    }
    if(root->left){   //left child hai ?
       Printleafnodes(root->left);
    }
    if(root->right){
       Printleafnodes(root->right);
    }
}



int main(){
    node*root=NULL;
    root=InputTreeLevelorder();
    Printleafnodes(root);

return 0;
}

