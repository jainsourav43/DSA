#include<iostream>
#include<cstdlib>
#define d 2
#include<algorithm>
#define null NULL
using namespace std;
typedef
struct bnode
{
	bnode *par;
	int key[2*d];
	bnode *ptr[2*d+1];
	int count;
}*bptr;
struct queue
{
	int size;
	bptr element[500];
	int front;
	int rear;
};
void delete_node(bptr &t1,int k);
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
	{	t=q.front;
		if(q.front==q.rear)
		{
			q.front=-1;	q.rear=-1;
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
	int check =0,i;
	if(t->key[0]>k)
	{
	  if(t->ptr[0]!=null)
	return search(t->ptr[0],k);
	else
	return t;
	}
	else if(t->key[0]<=k)
	{
	for( i=0;i<=t->count;i++)
	{
		if(i+1<=t->count&&(t->key[i]==k||t->key[i+1]==k))
		return t;
		else if(t->key[i]<k)
		{
			if(t->ptr[i+1]!=null&&i+1>=t->count&&t->key[i+1]>k)
			{
			return search(t->ptr[i+1],k);
		    }
			else if(t->ptr[i+1]!=null&&i+1>=t->count&&t->key[i+1]<k&&i+2>=t->count+1&&t->ptr[i+2]!=null)
			{
			  return search(t->ptr[i+2],k);
		     }

			else if(t->ptr[i+1]!=null&&i+1<=t->count&&t->key[i+1]<k&&i+2<=t->count)
			{
			continue;
	      	}
			else if(t->ptr[i+1]!=null)
			{
			return search(t->ptr[i+1],k);
	       }
		}
		else if(t->key[i]>k)
		{
			check=1;
			return search(t->ptr[i],k);
		}
         return t;
   }
  }
}
}
void print(bptr t,int m)
{
	if(t!=null)
	{	    int j,i;
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
int search1(bptr t,int k)
{
	if(t!=null)
	{
		for(int i=0;i<=t->count+1;i++)
		{
			if(t->ptr[i]&&t->ptr[i]->key[0]==k)
			return i;
		}
	}
}
int  check(bptr t)
{
int s=search1(t->par,t->key[0]);//cout<<"s in check= "<<s<<endl;
if(s>0&&s<=3)
{//	cout<<"enter check 1\n";
if(t->par->ptr[s-1]!=null&&t->par->ptr[s-1]->count>=d)
	{	//cout<<"enter check 2\n";
		return 1;
	}
	else if(t->par->ptr[s+1]!=null&&t->par->ptr[s+1]->count>=d)
	{	//cout<<"enter check 3\n";
		return 2;
	}
}
else if(s==0||s==4)
{
	if(s==0)
	{
	 if(t->par->ptr[s+1]!=null&&t->par->ptr[s+1]->count>=d)
	{cout<<"check\n";		return 2;
	}
	}
	else if(s==4)
	{
	if(t->par->ptr[s-1]!=null&&t->par->ptr[s-1]->count>=d)
	{
		return 1;
	}
	}
}
return 0;
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
		while(q.front!=-1)
		{
			f++;
			t2=deque(q);
			for(i=0;i<=t2->count;i++)
			{
				cout<<t2->key[i]<<"  ";//if(t2->par&&i<=t2->par->count) cout<<"("<<t->par->key[i]<<")";
			}
			cout<<endl;
			for(i=0;i<=m;i++)
			{
				if(t2->ptr[i]!=null)
				{
					enque(q,t2->ptr[i]);
				}
			}
		}
	}
}
void redistribution1(bptr &t,int a[],int s,bptr lc,bptr rc)
{
	int temp=t->par->key[s-1],i;
	t->par->ptr[s-1]->key[++t->par->ptr[s-1]->count]=temp;
    for( i=0;i<2*d;i++)
    t->key[i]=a[i+1];
    t->count=2*d-1;
   	t->par->ptr[s-1]->ptr[t->par->ptr[s-1]->count+1]=t->ptr[0];
    for( i=0;i<2*d-1;i++)
    t->ptr[i]=t->ptr[i+1];
   	t->ptr[2*d-1]=lc;
 	t->ptr[2*d]=rc;
    t->par->key[s-1]=a[0];
 }
 void redistribution2(bptr &t,int a[],int s,bptr lc,bptr rc)
 {
 		int temp;
    temp=t->par->key[s];
	int i;
 	for(int i=t->par->ptr[s+1]->count;i>=0;i--)
 	{
 	t->par->ptr[s+1]->key[i+1]=t->par->ptr[s+1]->key[i];
 	t->par->ptr[s+1]->ptr[i+2]=t->par->ptr[s+1]->ptr[i+1];
    }
    t->par->ptr[1]->ptr[1]=t->par->ptr[s+1]->ptr[0];
    t->par->ptr[1]->ptr[0]=null;
 	t->par->ptr[s+1]->key[0]=temp;
 	t->par->ptr[s+1]->count++;
 	for( i=0;i<2*d;i++)
 	t->key[i]=a[i];
 	t->count=2*d-1;
    t->par->ptr[s+1]->ptr[0]=t->ptr[t->count+1];
    for(i=2*d;i>=2;i--)
    t->ptr[i]=t->ptr[i-1];
    t->ptr[0]=lc;
    t->ptr[1]=rc;
 	t->par->key[s]=a[2*d];
 }
int index(bptr t,int k)
{
	for(int i=0;i<=t->count;i++)
	{
		if(t->key[i]!=k)
		continue;
		else
		return i;
	}
}
void redistribution3(bptr &t,int k,int s,int c)
{
	int i,j,in;
	if(c==2)
	{
		in=index(t,k);
	 for(i=in;i<=t->count-1;i++)
	 {
	 	t->key[i]=t->key[i+1];
	 	t->ptr[i+1]=t->ptr[i+2];
   }
	  t->key[t->count]=t->par->key[s];
	 t->par->key[s]=t->par->ptr[s+1]->key[0];
	  t->ptr[t->count+1]=t->par->ptr[s+1]->ptr[0];
	 bptr tp=t->par->ptr[s+1]->ptr[i+1],tp1;
     for(i=0;i<t->par->ptr[s+1]->count;i++)
     {cout<<"F  OO  RR  \n";
     t->par->ptr[s+1]->key[i]=t->par->ptr[s+1]->key[i+1];
     t->par->ptr[s+1]->ptr[i]=t->par->ptr[s+1]->ptr[i+1];
    }t->par->ptr[s+1]->ptr[t->par->ptr[s+1]->count]=t->par->ptr[s+1]->ptr[t->par->ptr[s+1]->count+1];
    t->par->ptr[s+1]->ptr[t->par->ptr[s+1]->count+1]=null;
     t->par->ptr[s+1]->count--;
	}
	else if(c==1)
	{
		in=index(t,k);
		for(i=t->count;i>in;i--)
		{
			if(t->key[i]!=k)
			continue;
			else
			{
			t->key[i]=t->key[i-1];
			t->ptr[i]=t->ptr[i-1];
		   }
	   }
		t->key[0]=t->par->key[s-1];
		t->ptr[in]=t->par->ptr[s-1]->ptr[t->count+1];
		t->par->key[s-1]=t->par->ptr[s-1]->key[t->par->ptr[s-1]->count];
		t->par->ptr[s-1]->count--;
	}
}
bptr  find_min(bptr t)
{
	if(t!=null)
	{
		while(t->ptr[0]!=null)
		{
			t=t->ptr[0];
		}
		return t;
	}
}
bptr find_max(bptr t)
{
	if(t!=null)
	{
		while(t->ptr[0])
		{
			t=t->ptr[t->count+1];
		}
		return t;
	}
}
bptr node_combine1(bptr t1,bptr t2)
{
    int i,j;
    cout<<"t->key[0] = "<<t1->key[0]<<"t2->key[0] = "<<t2->key[0]<<endl;
	for(i=0;i<d;i++)
	{
	t1->key[i+d]=t2->key[i];
	cout<<"in NC t2->key[i]=  "<<t2->key[i]<<"\n  ";
	t1->ptr[i+d+1]=t2->ptr[i+1];
	t1->count++;
	}
	t1->ptr[2*d]=t2->ptr[d];
	cout<<"end of the nc \n";
	//delete t2;
	return t1;
}
void delete_node(bptr &t1,int k,int flag)
{
    int i,in;bptr node;
	bptr min,max;
  	bptr t=null;
    t=search(t1,k);
    cout<<"t->key[0] ="<<t->key[0]<<"t->count= "<<t->count<<endl;
    if(t->par)
    {
    //cout<<"check = "<<check(t)<<endl;
    cout<<"t->par->key[0] ="<<t->par->key[0]<<endl;
    }
  	int s=search1(t->par,t->key[0]);
  	in =index(t,k);
	if(t->ptr[0]==null&&t->count>d-1||(t->ptr[0]==null&&t==t1))
  	{   cout<<"enter special \n";
	    for( i=0;i<=t->count;i++)
		if(t->key[i]!=k)
		continue;
		else
		break;
		for(int j=i;j<t->count;j++)
		t->key[j]=t->key[j+1];
		t->count--;
	}
	else if(t->ptr[0]==null&&check(t))
	{	    cout<<"KK\n";
			redistribution3(t,k,s,check(t));
	}
	else if(t->ptr[0]==null&&t->count<d&&check(t)==0)
	{
		flag=1;
		cout<<"LEaf nc  in = "<<in<<endl<<"s  ="<<s<<"   t->par->count =  "<<t->par->count<<endl;
		if(s==t->par->count+1)
		{cout<<"LLLL\n";
		for(i=0;i!=in&&i<t->count;i++)
		t->key[i+1]=t->key[i];
		t->key[0]=t->par->key[s-1];
		cout<<"t->par->key[s]  = "<<t->par->key[s-1]<<endl;
		delete_node(t1,t->par->key[s-1],1);
	   }
	   else
	   {cout<<"LLLL 22\n";
	   	for(i=in;i<t->count;i++)
		t->key[i]=t->key[i+1];
		t->key[t->count]=t->par->key[s];
		cout<<"t->par->key[s]  = "<<t->par->key[s]<<endl;
		delete_node(t1,t->par->key[s],1);
	   }
	}
	else if(t->ptr[0]!=null)
	{
		if(flag==0)
		{
		   cout<<"ENter 1\n";
   		   int v=index(t,k);
		   min= find_min(t->ptr[v+1]);
		   cout<<"After min\n";
		   if(min->count<d)
	       {cout<<"ENter if 1 \n";
		 	if(v>0)
		 	{cout<<"Enter if 2 \n";
		 	cout<<"V ="<<v<<endl;
		 	max=find_max(t->ptr[v]);
		 	cout<<"max count ="<<max->count<<endl;
		 	cout<<"Afetr max\n";
		 	if(max->count<d)
		 	{
			    cout<<"ENter 2\n";
			    node=node_combine1(t->ptr[in],t->ptr[in+1]);
			    	if(t->count-1>=d-1)
				 	{
				 		for(i=t->count;i>in;i--)
				 		{
				 			t->key[i-1]=t->key[i];
				 			t->ptr[i-1]=t->ptr[i];
						 }
				 	t->ptr[in]=node;
				 	t->count--;
				 	t->ptr[in+1]=null;
				   }
				else
				{
		 	    for(i=v;i<t->count;i++)
		 	    {
	 	         t->key[i]=t->key[i+1];
				 t->ptr[i+1]=t->ptr[i+2];
			    }
			    t->ptr[in]=node;
			    if(t->par==null)
			    {
			    t->ptr[t->count+1]=null;t->count--;
			    }
				if(t->par!=null)
			    {
		 	    t->key[t->count]=t->par->key[s];
		 	    delete_node(t1,t->par->key[s],1);
		 	   }
		       }
			   }
			else
			{
				t->key[v]=max->key[max->count];
				cout<<"max->key[max-count] = "<<max->key[max->count]<<endl;
				delete_node(t->ptr[v],max->key[max->count],0);
			}
		   }
		   else if(v==0)
		   {
		 	max=find_max(t->ptr[v]);
		 	if(max->count<d)
		 	{
		 	if(t->par!=null&&check(t))
		 	{cout<<"hjk\n";
			 redistribution3(t,k,s,check(t));
			  delete_node(t1,t->par->key[s],1);
			 }
			 else
			 {
		 	   node=node_combine1(t->ptr[in],t->ptr[in+1]);
		 	   for(i=v;i<t->count;i++)
		 	   {
	 	        t->key[i]=t->key[i+1];
				 t->ptr[i+1]=t->ptr[i+2];
			   }
			   t->ptr[in]=node;
			    if(t->par==null)
			    {

			    t->ptr[t->count+1]=null;t->count--;
			  }
			  if(t->par!=null)
			  {
		 	   t->key[t->count]=t->par->key[s];
		 	   delete_node(t1,t->par->key[s],1);
		    }
		}
			}
			else
			{
				t->key[v]=max->key[max->count];
				delete_node(t->ptr[v],max->key[max->count],0);
			}
		   }
		 }
		 else
		 {
		 t->key[v]=min->key[0];
		 delete_node(t->ptr[v+1],min->key[0],0);
	    }
	 }
	 else if(t->par!=null)
	 {

	   {int temp,temp1,ans=0;bptr tp,tp1;int che;s=search1(t->par,t->key[0]);cout<<"YYYY\n";
	   if(t->count-1<d-1){
	   	s=search1(t->par,t->key[0]);
		   if(s>0&&s<t->count+1)
		   {
		   if(t->par->ptr[s-1]->count>=d||t->par->ptr[s+1]->count>=d)
		   ans=1;
	      }
		   else if(s==0||s==t->count+1)
		   {
		   if(s==0&&t->par->ptr[s+1]->count>=d)
		   ans=1;
		   else if(s==t->count+1&&t->par->ptr[s-1]->count>=d)
		   ans=1;}
	  }
	 	 node=node_combine1(t->ptr[in],t->ptr[in+1]);
		 cout<<"After NC\n";
	 	if(t->count-1>=d-1)
	 	{	temp=t->key[t->count];tp=t->ptr[t->count+1];
 		for(i=t->count-1;i>=in;i--)
 		{   //t->key[i+1]=temp;
		     temp1=t->key[i];tp1=t->ptr[i+1];
 			t->key[i]=temp;
 			t->ptr[i+1]=tp;
 			temp=temp1;tp=tp1;
		 }
	 	t->ptr[in]=node;t->ptr[t->count+1]=null;
	 	t->count--;

	  }
	  else if(ans)
	  {
	 	if(s>0&&s<=t->count)
	 	{cout<<"LLK\n";
	     	min=find_min(t->par->ptr[s+1]);
	     	if(min->count>=d)
	     	che=2;
	     	max=find_max(t->par->ptr[s-1]);
	     	if(max->count>=d)
	     	che=1;
		 }
		 else if(s==0)
		 {
		 	min=find_min(t->par->ptr[s+1]);
		 	if(min->count>=d)
	     	che=2;
		 }
		 else if(s==t->count+1)
		 {
		 	max=find_max(t->par->ptr[s-1]);
		 	if(max->count>=d)
	     	che=1;
		 }

	 	if(che)
	 	{cout<<"COme\n";
	 		redistribution3(t,k,s,che);
		 }
		 t->ptr[in]=node;

			}
	 	else
	 	{
        if(t->par->count+1==s)
        {
        for(i=t->count-1;i>=0;i--)
	 	{
	 	t->key[i+1]=t->key[i];
	 	t->ptr[i+2]=t->ptr[i+1];
	    }
        t->key[0]=t->par->key[s-1];
        t->ptr[in+1]=node;

        }
        else
        {cout<<"AYAA\n";
        for(i=in;i<t->count;i++)
	 	{
	 	t->key[i]=t->key[i+1];
	 	t->ptr[i+1]=t->ptr[i+2];
	    }
        t->key[in+1]=t->par->key[s];

        t->ptr[d]=t->par->ptr[s+1]->ptr[0];
	 	t->ptr[in]=node;

	    }

	    if(t->par->count+1==s)
	 	delete_node(t1,t->par->key[s-1],1);
	 	else
	 	delete_node(t1,t->par->key[s],1);
	 }
	  }

	 }
	else if(t->par==null&&t->count==0)
	{
		cout<<"special \n";
		t1=node_combine1(t->ptr[in],t->ptr[in+1]);
		s=search1(t->ptr[in+1]->par,t->key[0]);
		if(s!=t->ptr[in]->par->count+1)
		{cout<<"supper\n";
		for(i=0;i<d;i++)
		{
		t1->ptr[in]->ptr[i+d]=t->ptr[in+1]->ptr[i];
	    }
		t1->ptr[in]->ptr[2*d]=t->ptr[in+1]->ptr[d];
	    }
		t1->par=null;
		for(i=0;i<=t1->count+1;i++)
		if(t1->ptr[i])
		t1->ptr[i]->par=t1;
	}
	else if(t->par==null&&t->count!=0)
	{    cout<<"sssppp\n";
	     int c=t->count;
		node=node_combine1(t->ptr[in],t->ptr[in+1]);
		if(s!=t->ptr[in]->par->count+1)
		{
		for(i=0;i<d;i++)
		node->ptr[i+d]=t->ptr[in+1]->ptr[i];
		node->ptr[2*d]=t->ptr[in+1]->ptr[d];
	    }
		if(in!=t->count)
		{
	    for(i=in;i<t->count;i++)
	 	{
	 	t->key[i]=t->key[i+1];
	 	t->ptr[i+1]=t->ptr[i+2];
	    }
	    }
	   	t->ptr[in]=node;
	   	t->count--;
	   	t->ptr[c+1]=null;
	   	for(i=0;i<=t->count+1;i++)
		if(t1->ptr[i])
		t1->ptr[i]->par=t1;
	   	cout<<"back\n";

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

 bptr t4 =t2,t5=t3;
 for(i=0;i<=d;i++)
 {//cout<<"fo 1\n";
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
	 	if(lc)
	 	lc->par=t2;
	 	if(rc)
		 rc->par=t2;
	 }
 }
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
	 	t3->ptr[i+1-d]->par=t5;
	 	if(lc)
	 	lc->par=t3;
	 	if(rc)
	 	rc->par=t3;
	 	i++;
	 }
 }
 if(che==0&&che1==0)
 {	t2->ptr[d]=lc;
 	t3->ptr[0]=rc;
 	for(int i=d;i<2*d;i++)
 	{
 		t3->ptr[i-d+1]=t->ptr[i+1];
	 }
 }
 t->count=0;
 t->par=null;t->key[0]=a[d];
 t->ptr[0]=t2;
 t->ptr[1]=t3;
for(int i=2;i<=2*d;i++)
t->ptr[i]=null;
 t->key[0]=a[d];
}
else
{
    cout<<"Overflow 2\n";
int s;
s=search1(t->par,t->key[0]);
if(s>0&&s<=3)
{
	if(t->par->ptr[s-1]!=null&&t->par->ptr[s-1]->count<2*d-1)
	{
		redistribution1(t,a,s,lc,rc);
		return ;
	}
	else if(t->par->ptr[s+1]!=null&&t->par->ptr[s+1]->count<2*d-1)
	{
		redistribution2(t,a,s,lc,rc);
		return ;
	}
}
else if(s==0||s==4)
{
	if(s==0)
	{
	 if(t->par->ptr[s+1]!=null&&t->par->ptr[s+1]->count<2*d-1)
	{
		redistribution2(t,a,s,lc,rc);
		return ;
	}
	}
	else if(s==4)
	{
	if(t->par->ptr[s-1]!=null&&t->par->ptr[s-1]->count<2*d-1)
	{
		redistribution1(t,a,s,lc,rc);
		return ;
	}
	}
}
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
	t3->count=1;
	bptr t5=t3;//t6=t2;
	for(i=0;i<=d;i++)
   {
 	if(t3->key[i]!=k)
 	{
 		if(che==1)
 		t3->ptr[i]=t->ptr[i-d+1];
 		else
 		t3->ptr[i]=t->ptr[i];
 		if(t3->ptr[i])
 		t3->ptr[i]->par=t5;
 		if(i+1==d&&t3->key[i]!=k)
 		{
 		t3->ptr[i+1]=t->ptr[i+1];
 		if(t3->ptr[i+1])
 		t3->ptr[i+1]->par=t5;
 		i++;
 	    }
	 }
	 else
	 {
	 	che=1;
	 	t3->ptr[i]=lc;
	 	if(t3->ptr[i])
 		t3->ptr[i]->par=t5;
	 	t3->ptr[i+1]=rc;
	 	if(t->ptr[i+1])
 		t3->ptr[i+1]->par=t5;
 		if(lc)
 		lc->par=t3;
 		if(rc)
 		rc->par=t3;
	 	i++;
	 }
  }
  bptr t6=t2;
 for(i=d;i<2*d;i++)
 {
 	if(t2->key[i-d]!=k)
 	{
 		if(che==1)
 		{

 		t2->ptr[i-d]=t->ptr[i];
 		if(t2->ptr[i-d])
 		t2->ptr[i-d]->par=t6;
 	 }
 		else
 		{
 		t2->ptr[i-d]=t->ptr[i+1];
 		if(t2->ptr[0])

 		if(t2->ptr[i-d])
 		t2->ptr[i-d]->par=t6;
 	}
 		if(i+1==2*d&&t2->key[i]!=k)
 		{
 		t2->ptr[i+1-d]=t->ptr[i+1];
 		if(t2->ptr[i-d+1])
 		t2->ptr[i-d+1]->par=t6;
 		i++;
 	   }
	 }
	 else
	 {
	 	t2->ptr[i-d]=lc;
	 	if(t2->ptr[i-d])
 		t2->ptr[i-d]->par=t6;
	 	t2->ptr[i-d+1]=rc;
	 	if(t2->ptr[i-d+1])
 		t2->ptr[i-d+1]->par=t6;
 		if(lc) lc->par=t2;
 		if(rc) rc->par=t2;

	 }
 }
 for(i=d+1;i<=2*d;i++)
 {
   t3->ptr[i]=null; t2->ptr[i]=null;
}
 if(t->par->count==2*d-1)
 {
 	    for(i=0;i<4;i++)
      	b[i]=t->par->key[i];
      	b[4]=a[d];
      	sort(b,b+5);
      	overflow(t->par,t3,t6,a[d],b);
      	delete t;
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
	 t->par->key[i+1]=a[d];
	 t->par->ptr[i+1]=t3;
	 t->par->ptr[i+2]=t2;
	 t->par->count++;
 }
}
}
void add(bptr &t1,int k)
{
	int i;
	bptr t=search(t1,k);
	if(t->count<2*d-1)
	{
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
		}
		t->key[i+1]=k;
		t->count++;
		t->ptr[i+2]=t->ptr[i+2];
		t->ptr[i+1]=t->ptr[i+1];
	}
	else
	{
		int a[2*d+1];
		for(int i=0;i<2*d;i++)
		{
            a[i]=t->key[i];
		}
		a[4]=k;
		sort(a,a+2*d+1);
		overflow(t,null,null,a[d],a);
	}
}
int main()
{
	bptr t=null;
	t=new bnode;
	int n=1;
	t->par=null;
	int input[]={4,7,22,21,35,12,23,39,16,32,29,46,28,43,64,9,49,53,40,42,24,60};
	cout<<"Enter the no. to add else -1\n";
	cin>>n;
	t->count=0;
	t->key[0]=n;
	for(int i=0;i<=2*d;i++)
	t->ptr[i]=null;n++;
	while(n!=26)
	{
	//cout<<"Enter the no. to add else -1\n";
	  // cin>>n;
        if(n!=-1)
		add(t,n);
		print(t,2*d);cout<<endl;
		cout<<"\nLevel order ::"<<endl;
		printlevel(t,2*d);
		n++;
	}//print(t,2*d);cout<<endl;	cout<<endl;printlevel(t,2*d);
	int d1;
	while(d1!=-1)
	{
	cout<<"Enter the key to delete\n";

	cin>>d1;
	if(d1!=-1)
	delete_node(t,d1,0);
	cout<<"Level order after Deletion\n";
	printlevel(t,2*d);
	cout<<endl;
	print(t,2*d);
   }
	return 0;
}
