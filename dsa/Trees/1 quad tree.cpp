#include <iostream>
#include<algorithm>
#define null NULL
typedef
struct qnode{
int x;
int y;
qnode *ptr[4];
}*qptr;
using namespace std;
void insert(qptr &t,int x1,int y1)
{

    if(t==null)
    {
        t=new qnode;
        t->x=x1;
        t->y=y1;
        for(int i=0;i<4;i++)
        {
            t->ptr[i]=null;
        }
    }
    else if(t->x>x1&&t->y>y1)
    {
        insert(t->ptr[0],x1,y1);
    }
    else if(t->x<x1&&t->y>y1)
    {
        insert(t->ptr[1],x1,y1);
    }
    else if(t->x>x1&&t->y<y1)
    {
        insert(t->ptr[2],x1,y1);
    }
    else
    {
        insert(t->ptr[3],x1,y1);
    }
}
int main()
{
    qptr t=new qnode;
    int x1,y1;
    cout<<"enter the value of x \n";
    cin>>x1;
    t->x=x1;
    cout<<"enter the value of x \n";
    cin>>y1;
    t->y=y1;
    for(int i=0;i<4;i++)
    {
        t->ptr[i]=null;
    }
    while(x1!=-1)
    {
        cout<<"enter the value of x else -1 \n";
        cin>>x1;
        cout<<"enter the value of y else -1 \n";
        cin>>y1;
        if(x1!=-1)
        {
        t->x=x1;
        t->y=y1;
        insert(t,x1,y1);
        }
    }
    //cout << "Hello world!" << endl;
    return 0;
}

