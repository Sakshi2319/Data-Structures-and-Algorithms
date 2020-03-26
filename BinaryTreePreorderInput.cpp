#include<iostream>

using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;
        node(int d)
        {
            data=d;
            left=right=NULL;
        }
};

int height(node* root){
 if(root==NULL){
    return 0;
}
int leftkiheight=height(root->left);
int rightkiheight=height(root->right);
return 1+max(leftkiheight,rightkiheight);

}
//-----------------------------------Preorder Input--------------------------
node* PreorderCreate()
{
    int d;
    cin>>d;
    node* root= new node(d);
    string s;
    cin>>s;
    if(s=="true")
        root->left=PreorderCreate();
    cin>>s;
    if(s=="true")
        root->right=PreorderCreate();
    return root;
}
//---------------------------------------------------------------------------------
bool IsBalanced(node*root){
//base case
if(root==NULL)
    return true;

//recursive case
 if(IsBalanced(root->left)&&IsBalanced(root->right)&&(abs(height(root->left)-height(root->right))<=1))
     return true ;
    else
      return false;

}
int main()
{
    node*root=NULL;
    root=PreorderCreate();
    if (IsBalanced(root)==true){
    cout<<"true";
    }
  else{
    cout<<"false";
  }
  return 0;
}
