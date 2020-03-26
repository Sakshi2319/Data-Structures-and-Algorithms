#include<iostream>
#include<queue>
using namespace std;
void Stock(queue <int> q )
{
    q.pop();
    if(q.empty())
    {
        return;
    }
    int ans=1;
    int temp = q.front();
    while(!q.empty())
    {
        q.pop();
        cout<<ans<<" ";
        if(q.front()>=temp)
        {
            ans = ans+1;
            temp  = q.front();
        }
        else
        {
            ans = 1;
            temp = q.front();
        }
    }
    cout<<"END"<<endl;
    return;
}
int main()
{
    queue<int>q;
    q.push(0);
    int n,i;
    cin>>n; //size
    while(n>0)
    {
        cin>>i;
        q.push(i);
        n--;
    }
    Stock(q);
	return 0;
}
