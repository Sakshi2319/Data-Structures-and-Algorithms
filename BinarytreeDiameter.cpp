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

//---------------------diameter---------------------------------------
int diameter(node*root){
//base case
if(root==NULL){
    return 0;
}
//recursive

//case 1
int op1=height(root->left)+height(root->right); //yeh cheez O(n^2) kr rha hai
//case2
int op2=diameter(root->left);

int op3=diameter(root->right);

   return max(op1,max(op2,op3));

}

//---------------------------------------------------------------------
//for O(n) complexity
class Pair{
    public:
     int dia;
     int height;
};

Pair fastDiameter(node*root){
    Pair p;

    //base case
    if(root==NULL){
        p.height=0;
        p.dia=0;
        return p;
    }

    //recursive case
    Pair left=fastDiameter(root->left);
    Pair right=fastDiameter(root->right);
    //find height of tree
    p.height=max(left.height,right.height)+1;

        //diameter
    int op1=left.height+right.height;
    int op2=left.dia;
    int op3=right.dia;
    p.dia=max(op1,max(op2,op3));
    return p;
}
//--------------------LEVEL ORDER--------------------------------------
void PrintLevelOrder(node*root){
queue<node*>q;
q.push(root);
q.push(NULL);

while(!q.empty()){
    node*temp=q.front();
    q.pop();
    if(temp==NULL){
        cout<<endl;
        if(!q.empty()){
            q.push(NULL);
        }
    }
    else{
    cout<<temp->data<<" ";
    if(temp->left){
        q.push(temp->left);
    }
    if(temp->right){
        q.push(temp->right);
    }
    }

}

}

//-----------------------------------------------------------------------



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
cout<<"Diameter is :"<<diameter(root)<<endl;

Pair p=fastDiameter(root);
cout<<"Fast height :"<<p.height<<endl;
cout<<"Fast diameter:"<<p.dia<<endl;
//diameter is max dist btwn root node to any node
cout<<"Level order printing:"<<endl;
PrintLevelOrder(root);


}
