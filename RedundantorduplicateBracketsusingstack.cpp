/*bool IsRedundant(stack <char> s,char*in){

 for(int i=0;in[i]!='\0';i++){

    if(in[i]==')'){

        char topelement=s.top();
        s.pop();
         bool x=true;//if it has opening wla then true

         while(topelement!='('){
                //operators ke liye
                if(topelement=='+'||topelement=='-'||topelement=='*'||topelement=='/')
                x=false;
           topelement=s.top();
           s.pop();
        }

        if(x==true)//operators nahi mile
            return true;
        }
    else //ki closing wle nahi mile toh
        s.push(in[i]);//push all elements
 }
 return false;

}*/


//------------------------------------------------------------------
#include<iostream>
#include<stack> //stl
#include<cstring>
using namespace std;
//------------------------------------------------------------------
void IsRedundant(char*in){
    stack <char> s;

 for(int i=0;i<strlen(in);i++){

    if(in[i]!=')'){

			s.push(in[i]);
		}
		else
		{
			if (s.top() == '(')
			{
				cout << "Duplicate"<<endl;
				return;
			}

			while (s.top() != '(')
			s.pop();
			s.pop();
		}
	 }
	 cout << "Not Duplicates"<<endl;

}
//----------------------------------------------------------
int main(){

char in[10000];
int n;
cin>>n;
for(int i=0;i<n;i++){
    cin>>in;
   IsRedundant(in);
 }
   return 0;
}


