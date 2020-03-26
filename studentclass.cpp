#include<iostream>
#include<string.h>
using namespace std;
//-----------------BLUE PRINT------------------

class student{
private:
    int rno;
public:
    static int count;
    char *name;
    char *branch;
    int year;

   void print()
   {
       cout<<"NAME:"<<name<<endl;
       cout<<"BRANCH:"<<branch<<endl;
       cout<<"ROLL NO:"<<rno<<endl;
       cout<<"YEAR:"<<year<<endl<<endl;
   }

   void setrno(int r){
   rno=r;
   }

   void setname(char*n){
    name=new char[strlen(n)+1];
       strcpy(name,n);
    }
    void setbranch(char*b){
       branch=new char[strlen(b)+1];
       strcpy(branch,b);
    }

  //------------------default constructor----------------------------
   student(){
       name=NULL;
       branch=NULL;
       cout<<"Default constructor called"<<endl;
       count++;
   }
  //-----------------parameterised constructor-------------------------
  student(char*n,char*b,int r,int y){
      cout<<"Parameterised constructor called"<<endl;
      name=new char[strlen(n)+1];
      strcpy(name,n);
      branch=new char[strlen(b)+1];
      strcpy(branch,b);
      rno=r;
      year=y;
      count++;
    }
  //------------------copy constructor-----------------------------------
  student(student&X){
      cout<<"Copy constructor called"<<endl;
      rno=X.rno;
      year=X.year;
      name=new char[strlen(X.name)+1];
      strcpy(name,X.name);
      branch=new char[strlen(X.branch)+1];
      strcpy(branch,X.branch);
      count++;

  }
  //--------------------------operator overloading-----------------------
  void operator=(student &X){
      cout<<"Assignment operator overloaded"<<endl;
   if(name!=NULL){
    delete []name;
    name=NULL;
   }
   name=new char[strlen(X.name)+1];
   strcpy(name,X.name);

    if(branch!=NULL){
    delete []branch;
    branch=NULL;
   }
   branch=new char[strlen(X.branch)+1];
   strcpy(branch,X.branch);
   rno=X.rno;
   year=X.year;

   }

   void operator+=(student &X){
     cout<<"Adding two students"<<endl;
     rno+=X.rno;
     year+=X.year;
    //name
     int len1=strlen(name);
     int len2=strlen(X.name);
     char *newname= new char[len1+len2+1];
     strcpy(newname,name);
     for(int i=0;i<len2;i++){
        newname[i+len1]=X.name[i];
     }
     newname[len1+len2]='\0';
     delete []name;//name mein jo pehle tha usko del krdo
     name=newname;
    //branch
     int l1=strlen(branch);
     int l2=strlen(X.branch);
     char *newbranch= new char[l1+l2+1];
     strcpy(newbranch,branch);
     for(int i=0;i<l2;i++){
        newbranch[i+l1]=X.branch[i];
     }
     newbranch[l1+l2]='\0';
     delete []branch;//name mein jo pehle tha usko del krdo
     branch=newbranch;

}
//-------------------------------------destructor--------------------------
   ~student(){
      cout<<"Destructor called"<<endl;
      count--;

    }

};

int student::count;
//--------------------------------------------------------------------------
int main()
{
   student a;
   a.setrno(1);
   a.setname("Ayush");
   a.year=2010;
   a.setbranch("ECE");
       a.print();

   student b("Anantika","IT",2,2011);
      b.print();
   student c("Akshit","CSE",3,2012);
       c.print();
   student d=a; //copy constructor
         d.print();
   student e;
   e=b;//copy assignment
   e.name[0]='V';
    e.print();

     a+=c;//adding
     a.print();
     cout<<"No of students :"<<student::count<<endl;

}
