#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *left;
		node* right;

		node(int d)
		{
			data=d;
			left=NULL;
			right=NULL;
		}
};
int i=0;
node* maketree(int* in,int* pre,int s,int e)
{

	//base case
	if(s>e)
	{
		return NULL;
	}
	//recursive case
	//pick ith preorder data and make it root node
	int data=pre[i];
	i++;
	node* root=new node(data);
	int k=-1;
	for(int j=s;j<=e;j++)
	{
		if(in[j]==data)
		{
			k=j;
			break;
		}
	}
	root->left=maketree(in,pre,s,k-1);
	root->right=maketree(in,pre,k+1,e);
	return root;
}
void print(node*root){
	if(root==NULL){
	return;
	}
    if(root->right!=NULL&&root->left!=NULL){
        cout<<root->left->data<<" => "<<root->data<<" <= "<<root->right->data<<endl;
    }
	if(root->left==NULL&&root->right==NULL){
		cout<<"END => "<< root->data <<" <= END"<<endl;
	}
	if(root->left==NULL&&root->right!=NULL){
		cout<<"END => "<< root->data <<" <= "<<root->right->data<<endl;
	}
	if(root->right==NULL&&root->left!=NULL){
		cout<<root->left->data<<" => "<< root->data <<" <= END"<<endl;
	}
	print(root->left);
	print(root->right);

}

int main(){
node*root=NULL;
	int n;
	cin>>n;
	int pre[100];
	int in[100];

	for(int i=0;i<n;i++){
	cin>>pre[i];
	}
	int m;
	cin>>m;
	for(int j=0;j<m;j++){
	cin>>in[j];
	}
	root=maketree(in,pre,0,n-1);
	print(root);
}
