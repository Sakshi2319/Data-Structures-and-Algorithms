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

node* maketree(int* in,int* post,int s,int e,int posts,int poste)
{
	//base case
	if(s>e || posts>poste)
	{
		return NULL;
	}
	//recursive case
	//pick ith postorder data and make it root node
	int data=post[poste];
	poste--;
	node* root=new node(data);
    if(s == e)
    {
        return root;
    }
	int k=-1;
	for(int j=s;j<=e;j++)
	{
		if(in[j]==data)
		{
			k=j;
			break;
		}
	}
	root->left=maketree(in,post,s,k-1,posts,posts+k-(s+1));
	root->right=maketree(in,post,k+1,e,posts+k-s,poste);
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
	int post[100];
	int in[100];

	for(int i=0;i<n;i++){
	cin>>post[i];
	}
	int m;
	cin>>m;
	for(int j=0;j<m;j++){
	cin>>in[j];
	}
	root=maketree(in,post,0,m-1,0,n-1);
	print(root);
}
