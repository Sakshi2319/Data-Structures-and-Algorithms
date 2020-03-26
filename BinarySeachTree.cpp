#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
class node{
public:
    int data;
    node*left;
    node*right;
    node(int d): data(d),left(NULL),right(NULL){}

};
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


int height(node* root){
 if(root==NULL){
    return 0;
}
int leftkiheight=height(root->left);
int rightkiheight=height(root->right);
return 1+max(leftkiheight,rightkiheight);

}


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

node*InsertInBST(node*root,int data){
//base case
 if(root==NULL){ //agar tree nahi hai toh toh new banao usi ko return krdo
    root=new node(data);
    return root;
 }

//recursive case
  if(root->data<=data){ //data bada hai
  root->right=InsertInBST(root->right,data);
  }
  else{
    root->left=InsertInBST(root->left,data);
  }
    return root;

}


node*CreateTreee(){
  int data;
  cin>>data;
  node*root=NULL;
  while(data!=-1){
    root=InsertInBST(root,data);
    cin>>data;
  }
 return root;
}
//-----------------------------------search--------------------------------
node* SearchElementInBST(node*root,int key){
    //base case
    if(root==NULL){
        return NULL;
    }
    //recursive
    if(root->data==key){
        return root;
    }
    if(key<root->data){
        SearchElementInBST(root->left,key); //left tree mein dhundo
    }
    else{
    SearchElementInBST(root->right,key);//right tree mein dhundo
    }
    return root;


}
//------------------------------------balanced------------------------------------
bool IsBalanced(node*root){
//base case
if(root==NULL)
    return true;

//recursive case //for root ke liye hum krde by using height of left and right subtree AND baaki recursion se puhlo
 if(IsBalanced(root->left)&&IsBalanced(root->right)&&(abs(height(root->left)-height(root->right))<=1))
     return true ;
    else
      return false;

}
//---------------------------check bst ----------------------------------------------
bool IsBST(node*root,int min=INT_MIN,int max=INT_MAX){
//base case
if(root==NULL){
    return true;
}
//recursive case
if(root->data<=max &&root->data>=min && IsBST(root->left,min,root->data) && IsBST(root->right,root->data,max))
    return true;
else{
    return false;
}
}
//-----------------------------convert into LL---------------------------------------------
class LinkedList{
 public:
     node*head;
     node*tail;
};
LinkedList BSTtoLL(node*root){
//base case
 LinkedList l;
  if(root==NULL){
    l.head=l.tail=NULL;
    return l;
  }

//recursive cases
//4 cases
  if(root->left==NULL&&root->right!=NULL){
    LinkedList right=BSTtoLL(root->right); //recursion right wali krdega
    root->right=right.head;
    l.head=root;
    l.tail=right.tail;
    return l;
  }

  else if(root->left!=NULL&&root->right==NULL){
    LinkedList left=BSTtoLL(root->left);
    left.tail->right=root;
    l.head=left.head;
    l.tail=root;
    return l;
  }
  else if(root->left==NULL&&root->right==NULL){
    l.head=l.tail=root;
    return l;
  }
  else{
    LinkedList left=BSTtoLL(root->left);
    LinkedList right=BSTtoLL(root->right);
    left.tail->right=root; //beech mein 8 (root) daalna hai bas
    root->right=right.head;
    l.head=left.head;
    l.tail=right.tail;
    return l;
  }

}

void Printll(node*head){
    while(head){
        cout<<head->data<<"-->";
        head=head->right;
    }
}
//---------------------------------------------------------------------------



//8 3 10 1 6 14 4 7 13 9 -1
int main(){
  node*root=CreateTreee();
  Preorder(root);
  cout<<endl;
  Inorder(root);
  cout<<endl;
  Postorder(root);
  cout<<endl;

  PrintLevelOrder(root);

  LinkedList l=BSTtoLL(root);

  Printll(l.head);


  cout<<endl;
  int key;
  cin>>key;
  if(SearchElementInBST(root,key)){
    cout<<"Found"<<endl;
    //cout<<"Searched is:"<<SearchElementInBST(root,key)->data;
  }
  else{
    cout<<"Not found";
  }


  if (IsBalanced(root)==true){
    cout<<"Balanced";
  }
  else{
    cout<<"Not Balanced";
  }
 if(IsBST(root)){
    cout<<"BST hai";
 }
 else{
    cout<<"BST nahi hai";
 }


return 0;
}
