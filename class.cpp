#include<iostream>
#include<cstring>
using namespace std;
//-----------------BLUE PRINT------------------

class car{
private:
    int price;

public:
     static int count;
     char *name;//for dynamic memory           //char name[20];
    int model;
    int seats;
    const int tyres;

    void print()const{
    cout<<"Name:"<<name<<endl;
    cout<<"Price:"<<price<<endl;
    cout<<"Model:"<<model<<endl;
    cout<<"Tyres:"<<tyres<<endl;
    }

    void setprice(int p){
    price=p;
    }

    car():tyres(4){
        name=NULL;//name ko khali (garbage)nahi chod skte//segmentation fault
    cout<<"\n default constructor"<<endl;
    count++;
    }

    car(char*n,int p,int s,int m):tyres(4),price(p),seats(s),model(m){ //bmw stored in n
        name=new char[strlen(n)+1];//now we can copy since now space is allocated
        strcpy(name,n);
        //price=p;
        //seats=s;
        //model=m;
        count++;
    }

    void setname(char*n){
    name=new char[strlen(n)+1];
       strcpy(name,n);
    }

    car(car &x):tyres(4){
        price=x.price;
        seats=x.seats;
        model=x.model;
        name=new char[strlen(x.name)+1];
        strcpy(name,x.name);
        count++;
        }  //by default ek aur copy constructor exists


        //operator overloading
        //returntype operator=(){}

        void operator=(car x){
            cout<<"\n in copy assignment operator"<<endl;

            if(name!=NULL){
                delete []name;
                name=NULL;
            }
            name=new char[strlen(x.name)+1];
            strcpy(name,x.name);
            price=x.price+100;
        seats=x.seats;
        model=x.model;

        }

    //destructor
    ~car(){
    cout<<"in destructor"<<name<<endl;
    count--;
    }


};
//-------------------------------------------------
int car::count=0;


int main()
{
    int p;
    car a;
    cin>>p;
    //int n=strlen("BMW");
    //char *name=new char[n+1];
    /*a.name[0]='B';
     a.name[1]='M';
      a.name[2]='W';
      a.name[3]='\0';*/
      a.setname("Maruti");
      a.model=2000;
       a.setprice(p);

   /* cout<<a.name<<endl;
    cout<<a.model;*/

    car b("merc",100000,7,2001);

    car c("BMW",100,5,2002);


    car d=a;//first way of calling
    //car e(d);//second way of calling copy const


    //copy assignment
    //car e=d-->calls copy const
    car e;
    e=d;//copy assignmaent operator
  e.name[0]='T';

  int *m=new int;
  float *f=new float;
  car *g=new car;     //new car created , iska name assign hoga derefer krke

  // if parameterised car se value chaiye - car *g=new car("f1",500,3,3000);
  (*g).name=new char[10];
  strcpy((*g).name,"f1");
  cout<<(*g).name<<endl;


        a.print();
        b.print();
        c.print();
        d.print();
        e.print();
        (*g).print();
        cout<<"\no of cars:"<<a.count<<endl;
        delete g;//isko pehle del krdiya main ke scope se pehle kyunki programmer ko del krna pdega dynamic memory ko
        g=NULL;
        cout<<"\n No of cars:"<<car::count<<endl;

    return 0;
}
