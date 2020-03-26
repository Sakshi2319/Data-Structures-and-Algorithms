#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;
    node(int d): data(d),left(NULL),right(NULL){}

};


node* CreateTree(){
  int d;
  cin>>d;
  if(d==-1){
    return NULL;
  }
  node*root=new node(d); //root node
  root->left=CreateTree();
  root->right=CreateTree();
  return root;

}

void Preorder(node* root){
    //base case
    if(root==NULL){
        return;
    }

    //recursive
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(node* root){
    //base case
    if(root==NULL){
        return;
    }
    //recursive
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Postorder(node* root){
    //base case
    if(root==NULL){
        return;
    }

    //recursive
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

int CountNodes(node*root){
//base case
if(root==NULL){
    return 0;
}
 return CountNodes(root->left)+CountNodes(root->right)+1;


}

int height(node* root){
 if(root==NULL){
    return 0;
}
int leftkiheight=height(root->left);
int rightkiheight=height(root->right);
return 1+max(leftkiheight,rightkiheight);

}

int main(){
node*root=NULL;

root=CreateTree();
//input - 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

Preorder(root);
cout<<endl;
Inorder(root);
cout<<endl;
Postorder(root);
cout<<endl;
cout<<"No of nodes :"<<CountNodes(root)<<endl;
cout<<"Height of tree :"<<height(root)<<endl;

}
