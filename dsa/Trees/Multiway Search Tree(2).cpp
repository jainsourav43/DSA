#include<iostream>
#define null NULL
#include<algorithm>
using namespace std;
typedef
struct mstnode
{
	int *key;
	mstnode **ptr;
	int count;
}*mstptr;
void print(mstptr t,int m)
{
	if(t!=null)
	{
	    int j,i;
		for(i=0;i<=m;i++)
		{
		print(t->ptr[i],m);
	   	if(i<=t->count)
	   	{ 
		cout<<t->key[i]<<"  ";}
        }
	}
}//for(j=i+1;j<t->count;j++)
int findmax(mstptr t,int m)
{
	if(t!=null)
	{
		//for(i=0;i<=m;i++)
		if(t->ptr[m]==null)
		return t->key[t->count];
		else
		{
			return findmax(t->ptr[m],m);
		}
	}
}
int findmin(mstptr t,int m)
{
	if(t!=null)
	{
		if(t->ptr[0]==null)
		return t->key[0];
		else
		{
		return	findmin(t->ptr[0],m);
		}
	}
}
void delete1(mstptr t,int k,int m)
{
	int k1,h,k2,k3;
	if(t==null)
	return;
	else 
	{   k1=0;k3=0;
		mstptr t2=t,t3=t,t4;
		while(t3->key[k3]!=k)
		{k1=0;cout<"!\n";
		for(int j=0;j<=t3->count;j++)
		{
			if(t3->key[j]<k)
			{cout<<"@\n";
				k1++;
			}
			else if(t3->key[j]>k)
			{
				t3=t3->ptr[0];
				break;
			}
		}k2=k1;
		if(k1==0)k2=1;k3=k1;
		if(t3->key[k2-1]==k)
		{
			t4=t3;
		}
		if(k1>0&&t3->key[k1]!=k)
		{
			t3=t3->ptr[k1];
		}
		if(k3>t3->count)k3=k3-1;
	   }
	   k2=k1;
	   if(k1==0)k1=1;
	   int y,c=0,c1=0,j,ch1=0,ch=0;
	for(int y=j-1;y>=0;y--)
 	if(t->ptr[y]!=null)
 	{
 	c=y;ch=1;
 	break;
    }
 	for(int y=j;y<=m;y++)
 	if(t->ptr[y]!=null)
 	{
ch1=1;
 	c1=y;
 	break;
    }
	   if(ch==1&&ch1==1)//t3->ptr[k1-1]!=null&&t3->ptr[k2+1]!=null
	   {cout<<"3\n";
	   	h=findmin(t3->ptr[c1],m);
	   	t3->key[k2]=h;
	   	delete1(t3->ptr[c1],h,m);
	   }
	   else if(ch==0&&ch1!=0)//t3->ptr[k1-1]==null&&t3->ptr[k2+1]!=null
	   {cout<<"4\n";
	   	h=findmin(t3->ptr[c1],m);
	   	t3->key[k2]=h;
	   	delete1(t3->ptr[c1],h,m);
	   }
	   else if(ch!=0&&ch1==0)//t3->ptr[k1-1]!=null&&t3->ptr[k2+1]==null
	   {cout<<"5\n";
	   	h-findmax(t3->ptr[c],m);
	   	t3->key[k2]=h;
	   	delete1(t3->ptr[c],h,m);
	   }
	   else
	   {cout<<"6\n";
	   	if(t3->count==0)
	   	{
	   		t3=null;
		   }
		   else 
		   {
		   	t3->key[k2]=10000;
		   	sort(t3->key,t3->key+t3->count);
		   	//t3->count=t3->count-1;
		   }
	   }
	}
}

void insert(mstptr &t,int f,int m)
{
	int i,j,k,k1=0,temp,temp2;mstptr t2=t,t3=t,k3=0;
	if(t3==null||t3->count==m-1)
	{
	 cout<<"  !  \n";
	 k3++;
	 while(t2!=null)
	 {
	 k1=0;
	for(i=0;i<=t3->count;i++)
	{
		if(t3->key[i]<f)
		{
			k1++;
		}			
	}
//	cout<<"K1   "<<k1;
	if(t3->ptr[k1]!=null&&t3->count==m-1)
	{
	t3=t3->ptr[k1];
    }
 else
  break;
	t2=t2->ptr[k1];
    }
	if(t3->ptr[k1]==null&&t3->count==m-1)
	{
	cout<<"UU\n";
	t3->ptr[k1]=new mstnode;
    t3=t3->ptr[k1];
	t3->key=new int[m];
	t3->ptr=new mstnode*[m+1];
	t3->count=0;
	t3->key[0]=f;
	for(int i=0;i<=m;i++)
	t3->ptr[i]=null;
   
   } //cout<<NULL;
   else if(t3->count<m-1)
	{
	   cout<<"2  \n";int k3=0;k=0;
		for(i=0;i<=t3->count;i++)
		{
			if(t3->key[i]<f)
			{
				k=i;k3=0;
			}
			else if(t3->key[i]>f) 
			{
			   cout<<"YYY\n";
			   k3=1;
			   if(f<t3->key[0])
			   {
			   temp=t3->key[0];
			   t3->key[0]=f;
			   k=-1;
	         	}
	         	else
	         	{
		
			   if(k<t3->count)
				temp=t3->key[k+1];
				t3->key[k+1]=f;
			   }
				for(j=k+1;j<=t3->count;j++)
				{
					if(j<t3->count)
					temp2=t3->key[j+1];
					t3->key[j+1]=temp;
					temp=temp2;
				}
				break;
			}
		}
		if(k3==0)
		{
			t3->key[k+1]=f;
		}
		t3->count=t3->count+1;
	}
	}
	else if(t->count<m-1)
	{
	   cout<<"2  \n";int k3=0;k=0;
		for(i=0;i<=t->count;i++)
		{
			if(t->key[i]<f)
			{
				k=i;k3=0;
			}
			else if(t->key[i]>f) 
			{
			   cout<<"YYY\n";
			   k3=1;
			   if(f<t->key[0])
			   {
			   temp=t->key[0];
			   t->key[0]=f;
			   k=-1;
	         	}
	         	else
	         	{
		
			   if(k<t->count)
				temp=t->key[k+1];
				t->key[k+1]=f;
			   }
				for(j=k+1;j<=t->count;j++)
				{
					if(j<t->count)
					temp2=t->key[j+1];
					t->key[j+1]=temp;
					temp=temp2;
				}
				break;
			}
		}
		if(k3==0)
		{
			t->key[k+1]=f;
		}
		t->count=t->count+1;
	}
}
void deleteit(mstptr &t,int k,int m,int j)
{
    cout<<"CALLing\n";
	if(t==null)
	return ;
	else if(t->key[0]!=k)
	{
	for(int i=0;i<=m;i++)
	{
	if(i<=t->count)
	{cout<<"TF! \n";
	if(t->key[i]>k)
	{				
		if(i==0)
		deleteit(t->ptr[j],k,m,j);
		else 
		{cout<<"ELSE @\n";
		if(j-1<0)j=1;
			deleteit(t->ptr[j-1],k,m,j-1);
		}
	}
	else if(t->key[i]<k)
	{cout<<"TB\n";
		if(j<m)
		{cout<<"9\n";
			deleteit(t->ptr[j+1],k,m,j+1);
		}
		else
		{cout<<"10\n";
			deleteit(t->ptr[m],k,m,j);
		}
	}
    }
    }
 }
 else
 {cout<<"TTTT\n";
 	int c=0,c1=0;
 	int h,ans,g=0;
 	//t->key[j]=h;
 	for(int y=0;y<j;y++)
 	if(t->ptr[y]!=null)
 	c++;
 	for(int y=j;y<=m;y++)
 	if(t->ptr[y]!=null)
 	c1++;
 	if(c1>0&&c>0)
 	{cout<<"KKI\n";
 	for( g=j+1;g<=m;g++)
 	if(t->ptr[g]!=null)
 	{
 		break;
	 }
 	if(g>m)g=m;
     h=findmin(t->ptr[g],m);
     deleteit(t->ptr[g],h,m,0);
    }
 	else
 	if(c1>0&&c==0)
 	{cout<<"^^\n";
	 	 for( g=j-1;g>=0;g--)
 	if(t->ptr[g]!=null)
 	{
 		ans=g;break;
	 }if(g<0)g=0;
 		h=findmin(t->ptr[g],m);
 		deleteit(t->ptr[g],h,m,0);	
	}
	else if(c1==0&&c>0)
	{cout<<"VVV\n";
	for( g=j+1;g<=m;g++)
 	if(t->ptr[g]!=null)
 	{
 		ans=g;break;
	 }
	 if(g>m)g=m;
	 h=findmax(t->ptr[g],m);
	 deleteit(t->ptr[g],h,m,0);	
	}
	else
	{cout<<"uuuuu\n";
		t->key[j]=10000;
		sort(t->key,t->key+t->count);
		t->count=t->count-1;
	}
 }
}
void insert()

/*void insert1(mstptr &t,int f,int m)
{
	int i,k;int temp,temp1;
	if(t==null)
	{cout<<"if1  ";
		if(t->count<m-1)
		{		t->count=t->count+1;

		//for(i=0;i<t->count;i++)
		//{
			if(t->key[i]>f)
			{
				t->key[0]=f; temp=t->key[0];
				for(int j=i;j<=t->count-1;j++)
				{
					t->key[j+1]=temp;
				}print(t);cout<<endl;
			}
			else
			{cout<<"ELSE1  ";
				for(i=0;i<t->count;i++)
				{
					if(t->key[i]<f)
					{cout<<"**    ";
						k=i;
					}
					else
					{cout<<"**&&&    ";
					//	
					t->key[k+1]=f;
					temp=t->key[k+1];
						for(i=k+1;i<t->count-1;i++)
						{	temp1=t->key[i+1];
						t->key[i+1]	=temp;
						temp=temp1;
						}print(t);cout<<endl;
					}
				}
			}
		//}
	}
	else
	{
	cout<<"ELSE2  ";int i2;
	for(i2=0;t->count>i2;i2++)
	{
		if(t->key[i2]<f&&t->key[i2+1]>f)
		{
			continue;
		}
		else  
		break;
	}
	t->ptr[i2]=new mstnode;
	t->ptr[i2]->count=0;
	t->ptr[i]->key[0]=f;
	for(int  i1=0;i<=m;i++)
	{
		t->ptr[i1]=null;
	}	
	}	
	}
	else //if(t->key[0]<f||t->key[m-1]>f)
	{cout<<"Else3  ";
			if(t->key[0]>f)
			{
			insert(t->ptr[0],f);print(t);cout<<endl;
			}
			else if(t->key[m-1]<f)
			{
				insert(t->ptr[m],f);print(t);cout<<endl;
			}
			for(i=0;i<t->count-1;i++)
		if(t->key[i]<f&&t->key[i+1]>f)
		{
			insert(t->ptr[i],f);print(t);cout<<endl;
		}
	}
}*/

int main()
{
	mstptr t;
	int f,m;
	cout<<"Enter the no. of keys\n";
	cin>>m;
	cout<<"Enter the data to insert\n";
	cin>>f;
	t=new mstnode;
	t->key=new int[m];
	t->ptr=new mstnode*[m+1];
	t->count=0;
	t->key[0]=f;
	for(int i=0;i<=m;i++)
	t->ptr[i]=null;

	while(f!=-1)
	{
	cout<<"Enter the data to insert\n";
	cin>>f;
	if(f!=-1)
	{
		insert(t,f,m);
	}
    }
    print(t,m);
    int k=findmax(t,m);   cout<<"Max is "<<k<<endl;
    k=findmin(t,m);   cout<<"Min is "<<k<<endl;
    cout<<"Enter the no. to delete\n";
    cin>>k;
    delete1(t,k,m);cout<<endl;
 print(t,m);
}

