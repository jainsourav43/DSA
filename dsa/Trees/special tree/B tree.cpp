#include<iostream>
#define d 2
#include<algorithm>
#define null NULL
using namespace std;
typedef 
struct bnode
{
	bnode *par;
	int key[4];
	bnode *ptr[5];
	int count;
}*bptr;
struct queue
{
	int size;
	bptr element[560];
	int front;
	int rear;
};
void enque(queue &q,bptr x)
{
	if((q.rear+1)%q.size==q.front)
	{
		cout<<"Queue is overloaded\n";
	}
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=(q.rear+1)%q.size;
		q.element[q.rear]=x;
	}
}
bptr deque(queue &q)
{
	int  t;
	
	if(q.front==-1)
	{
		cout<<"Queue is Empty\n";
	}
	else
	{
		t=q.front;
		if(q.front==q.rear)
		{
			q.front=-1;
			q.rear=-1;
		}
		else
		{
			q.front=(q.front+1)%q.size;
		}
		return q.element[t];
    }    	
}
bptr  search(bptr t,int k)
{
	if(t!=null)
	{
	//cout<<"ENter search \n";
	int check =0,i;
	if(t->key[0]>k)
	{
//	cout<<"SEARCH if\n";
	if(t->ptr[0]!=null)
	return search(t->ptr[0],k);
	else
	return t;
	}
	else if(t->key[0]<k)
	{
//	cout<<"ELSe if sr\n";
	for( i=0;i<=t->count;i++)
	{

		if(t->key[i]<k)
		{
			if(t->ptr[i+1]!=null&&i+1>=t->count&&t->key[i+1]>k)
			{ // cout<<"COME1\n";
			return search(t->ptr[i+1],k);
		}
			else if(t->ptr[i+1]!=null&&i+1>=t->count&&t->key[i+1]<k&&i+2>=t->count+1&&t->ptr[i+2]!=null)
			{
             // cout<<"COME2\n";
			  return search(t->ptr[i+2],k);
		     }
			else if(t->ptr[i+1]!=null&&i+1<=t->count&&t->key[i+1]<k&&i+2<=t->count)
			{  //cout<<"COME3\n";
			continue;
	      	}
			else if(t->ptr[i+1]!=null)
			{  //cout<<"COME4\n";
			return search(t->ptr[i+1],k);
	       }
		}	
		else if(t->key[i]>=k)
		{
		  //  cout<<"@ ELSE IF \n";
			check=1;
			return search(t->ptr[i],k);
		}
	//	cout<<"t->key[0]"<<t->key[0]<<endl;
         return t;
   }
  }	
//cout<<"END\n";
}
}
void print(bptr t,int m)
{	
	if(t!=null)
	{
	  // cout<<"WElcome\n";
	    int j,i;
		for(i=0;i<=m;i++)
		{
		print(t->ptr[i],m);
	   	if(i<=t->count)
	   	{ 
		cout<<t->key[i]<<"  ";}
        }
	}
}
void initialise(bptr &t)
{
	for(int i=0;i<=2*d;i++)
	{
		t->ptr[i]=null;
	}
	t->count=-1;
}
void printlevel(bptr t,int m)
{
	if(t!=null)
	{
		queue q;
		q.front=-1;
		q.rear=-1;
		q.size=500;
		bptr t2,t3;
	     int i,c[20],f=0;
		enque(q,t);
		//cout<<"T->key[0]  in level =" <<t->key[0]<<endl;
		while(q.front!=-1)
		{
			f++;
			t2=deque(q);
			for(i=0;i<=t2->count;i++)
			{
				cout<<t2->key[i]<<"  ";
			}
			cout<<endl;
			for(i=0;i<=m;i++)
			{
				if(t2->ptr[i]!=null)
				{
					//c[f-1]++;
					enque(q,t2->ptr[i]);
				}
			}
		}
	}
}
void overflow(bptr &t,bptr lc,bptr rc,int k,int a[])
{
	int i,j,l,che=0,b[5],che1=0;
if(t->par==null)
{cout<<"Overflow 1\n";
 bptr t2=new bnode;
 bptr t3=new bnode;
 initialise(t2);
 initialise(t3);
 t2->par=t;
 t3->par=t;
 for(i=0;i<d;i++)
 {
 	t2->key[i]=a[i];
 	t3->key[i]=a[i+d+1];
 }
 t2->count=1;
 t3->count=1;
 t->key[0]=a[d];
   //cout<<"t3->key[0]  ="<<t3->key[0]<<endl;
//cout<<"T->count= "<<t->count<<endl;
 bptr t4 =t2,t5=t3;
 for(i=0;i<=d;i++)
 {
 	if(t2->key[i]!=k)
 	{
 		if(che==1)
 		t2->ptr[i]=t->ptr[i-d+1];
 		else
 		t2->ptr[i]=t->ptr[i];
 		if(t2->ptr[i])
	 	t2->ptr[i]->par=t4;
 		if(i+1==d&&t2->key[i]!=k)
 		{
 		t2->ptr[i+1]=t->ptr[i+1];
 		if(t2->ptr[i])
	 	t2->ptr[i]->par=t4;
 		i++;
 	    }
	 }
	 else
	 {
	 	che=1;
	 	t2->ptr[i]=lc;
	 	if(t2->ptr[i])
	 	t2->ptr[i]->par=t4;
	 	t2->ptr[i+1]=rc;
	 	if(t2->ptr[i+1])
	 	t2->ptr[i+1]->par=t4;
	 	i++;
	 }
 }   //cout<<"t3->key[0]  ="<<t3->key[0]<<endl;
t->key[0]=a[d]; 
 for(i=d;i<2*d;i++)
 {
 	if(t3->key[i-d]!=k)
 	{
 		if(che==1)
 		{
 		t3->ptr[i-d]=t->ptr[i]; //cout<<"if  =t3->key[0]  ="<<t3->key[0]<<endl;
 		if(t3->ptr[i-d])
	 	t3->ptr[i-d]->par=t5; //cout<<"if  6 = t3->key[0]  ="<<t3->key[0]<<endl;
	    }
 		else
 		{
 		t3->ptr[i-d]=t->ptr[i+1]; //cout<<"else = t3->key[0]  ="<<t3->key[0]<<endl;
 		if(t3->ptr[i-d])
	 	t3->ptr[i-d]->par=t5;// cout<<" if  5= t3->key[0]  ="<<t3->key[0]<<endl;
		 }
 	
 		if(i+1==2*d&&t3->key[i]!=k)
 		{
 		t3->ptr[i+1-d]=t->ptr[i+1]; //cout<<"if 2 =t3->key[0]  ="<<t3->key[0]<<endl;
 		if(t3->ptr[i+1-d])
	 	t3->ptr[i+1-d]->par=t5; //cout<<"if 5 =t3->key[0]  ="<<t3->key[0]<<endl;
 		i++;
 	    }
	 }
	 else
	 {
	 	che1=1;
	 	t3->ptr[i-d]=lc;// cout<<" lc =t3->key[0]  ="<<t3->key[0]<<endl;
	 	if(t3->ptr[i+1-d])
	 	t3->ptr[i-d]->par=t5;
	 	t3->ptr[i-d+1]=rc;// cout<<" rc =t3->key[0]  ="<<t3->key[0]<<endl;
	 	if(t3->ptr[i+1-d])
	 	t3->ptr[i+1-d]->par=t5;// cout<<"t3->key[0]  ="<<t3->key[0]<<endl;
	 	i++;
	 }
 }t->key[0]=a[d];//   cout<<"t3->key[0]  ="<<t3->key[0]<<endl;cout<<"T3->count =, t->count ="<<t3->count<<" "<<t->count<<endl;;

 if(che==0&&che1==0)
 {
 	//cout<<"Enter \n";
 	t2->ptr[d]=lc;
 	t3->ptr[0]=rc;
 	for(int i=d;i<2*d;i++)
 	{
 		t3->ptr[i-d+1]=t->ptr[i+1];
	 }
 	
 }   //cout<<"t3->key[0]  ="<<t3->key[0]<<endl;

 //initialise(t);
 t->count=0;
 t->par=null;t->key[0]=a[d];
 t->ptr[0]=t2;   //cout<<"t3->key[0]  ="<<t3->key[0]<<endl;

 t->ptr[1]=t3; //  cout<<"t3->key[0]  ="<<t3->key[0]<<endl;
for(int i=2;i<=2*d;i++)
t->ptr[i]=null;
t->key[0]=a[d];
  //cout<<"t->key[0]  ="<<t->key[0]<<endl;cout<<"T3->count ="<<t3->count<<endl;
  //cout<<"t->ptr[0]->key[0]  ="<<t->ptr[0]->key[0]<<endl;
  //cout<<"t->ptr[1]->key[0]  ="<<t->ptr[1]->key[0]<<endl;cout<<"T3->count ="<<t3->count<<endl;
   //cout<<"t3->key[0]  ="<<t3->key[0]<<endl;
//cout<<"T3->count ="<<t3->count<<endl;
}
else
{cout<<"Overflow 2\n";
	bptr t2=new bnode,t3=new bnode;
	initialise(t2);
	initialise(t3);
	t2->par=t->par;
	t3->par=t->par;
	for(i=0;i<d;i++)
	{
		t2->key[i]=a[i+d+1];
		t2->count++;
		t3->key[i]=a[i];
	}
//	cout<<"T->ke[0]  "<<t->key[0]<<endl;
	t3->count=1;
	for(i=0;i<=d;i++)
   {
 	if(t3->key[i]!=k)
 	{
 		if(che==1)
 		t3->ptr[i]=t->ptr[i-d+1];
 		else
 		t3->ptr[i]=t->ptr[i];
 	//	cout<<"t->ptr[i] = "<<t->ptr[i]<<endl;
 		if(t3->ptr[i])
 		t3->ptr[i]->par=t3;
 		if(i+1==d&&t3->key[i]!=k)
 		{
 		t3->ptr[i+1]=t->ptr[i+1];
 		if(t->ptr[i+1])
 		t3->ptr[i+1]->par=t;
		 //cout<<"t->ptr[i] = "<<t->ptr[i+1]<<endl;
 		i++;
 	    }
	 }
	 else
	 {
	 	che=1;
	 	t3->ptr[i]=lc;
	 //cout<<"t->ptr[i] = "<<t->ptr[i]<<endl;
	 	if(t3->ptr[i])
 		t3->ptr[i]->par=t3;
	 	t3->ptr[i+1]=rc;
	 	if(t->ptr[i+1])
 		t3->ptr[i+1]->par=t3;
	// cout<<"t->ptr[i] = "<<t->ptr[i+1]<<endl;
	 	i++;
	 }
  }
  bptr t4=t2;
 for(i=d;i<2*d;i++)
 {
 	if(t2->key[i-d]!=k)
 	{
 		if(che==1)
 		{
		
 		t2->ptr[i-d]=t->ptr[i];
 		if(t2->ptr[i-d])
 		t2->ptr[i-d]->par=t4;
 	 }
 		else
 		{
	//	cout<<"GAYA                  special "<<i-d<<endl;
 		t2->ptr[i-d]=t->ptr[i+1];
 		if(t2->ptr[0])
 		//cout<<t2->ptr[0]->key[0]<<"ghfy\n";
 		//cout<<"AAYa\n";
 		if(t2->ptr[i-d])
 		t2->ptr[i-d]->par=t4;
 	}
 		if(i+1==2*d&&t2->key[i]!=k)
 		{
 		t2->ptr[i+1-d]=t->ptr[i+1];
 		if(t2->ptr[i-d+1])
 		t2->ptr[i-d+1]->par=t4;
 		i++;
 	   } 
	 }
	 else
	 {//cout<<"COME  R \n";
	 	t2->ptr[i-d]=lc;
	 	if(t2->ptr[i-d])
 		t2->ptr[i-d]->par=t4;
	 	t2->ptr[i-d+1]=rc;
	 	if(t2->ptr[i-d+1])
 		t2->ptr[i-d+1]->par=t4;
 	
	 }
 }
 //cout<<"t2->ptr[0] ="<<t2->ptr[0]<<endl;
 for(i=3;i<=2*d;i++)
 {
   t3->ptr[i]=null; 
   t2->ptr[i]=null;
}
 if(t->par->count==3)
 {
 	    for(i=0;i<4;i++)
      	b[i]=t->par->key[i];
      	b[4]=a[d];
      	sort(b,b+5);
      	overflow(t->par,t3,t4,a[d],b);
 }
 else
 {
 	for(i=t->par->count;i>=0;i--)
 	{
 		if(t->par->key[i]>a[d])
 		{
 			t->par->key[i+1]=t->par->key[i];
 			t->par->ptr[i+2]=t->par->ptr[i+1];
		 }
		 else
		 {
		 	break;
		 }
 		
	 }
	// cout<<t->par->key[0]<<"  j j\n";
	 t->par->key[i+1]=a[d];
	//cout<<t->par->key[i+1]<<" H\n";
	 t->par->ptr[i+1]=t3;
	// cout<<t->key[0]<<"  OO \n";
	 t->par->ptr[i+2]=t2;
	 //if(t2->ptr[0])
	 //cout<<"t2->key[0] = "<<t2->ptr[0]->key[0]<<endl;
	 t->par->count++;
 }
}	
}
void add(bptr &t1,int k)
{
	int i;
//	cout<<"RRR\n";
	bptr t=search(t1,k);//	cout<<t->key[0]<<"kk"<<endl;
    //cout<<"-count"<<t->count<<endl;
	if(t->count<2*d-1)
	{
	    //cout<<"PP\n";//cout<<"t->key[]   = "<<t->key[0]<<endl;
		//t->key[++t->count]=k;
		for( i=t->count;i>=0;i--)
		{
			if(t->key[i]>k)
			{
				t->key[i+1]=t->key[i];
				t->ptr[i+2]=t->ptr[i+1];
			}
			else
			{
				break;
			}
		}//cout<<"I=  "<<i<<endl;
		t->key[i+1]=k;
		t->count++;
		t->ptr[i+2]=t->ptr[i+2];
		t->ptr[i+1]=t->ptr[i+1];
	}
	else 
	{
	   // cout<<"QQQ\n";
		int a[5];
		//t->count=-1;
		for(int i=0;i<2*d;i++)
		{
            a[i]=t->key[i];
		}
		a[4]=k;
		sort(a,a+5);
		//cout<<"OOVV\n";
		overflow(t,null,null,a[d],a);
		//cout<<"REturn \n";
	}
}
int main()
{
	bptr t=null;
	t=new bnode;
	int n=1;
	t->par=null;
	cout<<"Enter the no. to add else -1\n";
	cin>>n;
	t->count=0;
	t->key[0]=n;
	for(int i=0;i<=2*d;i++)
	t->ptr[i]=null;n++;
	while(n<=50)
	{
//	cout<<"Enter the no. to add else -1\n";
//    cin>>n;
    if(n!=-1)
		add(t,n);
	//	cout<<"ER\n";
		print(t,2*d);	
		cout<<"\nLevel order ::"<<endl;
		printlevel(t,2*d);n++;
	}
	int a,b=1;
	a=-b;
	return 0;
}
