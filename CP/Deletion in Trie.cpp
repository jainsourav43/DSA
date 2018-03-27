#include<iostream>
#define null NULL
#include<string.h>
using namespace std;
struct trnode;
struct leafnode;
union un
{
	trnode **ptr1;
	leafnode *ptr2;
};
struct leafnode
{
	char key[50];
};
typedef
struct trnode
{
	union un ptr;
	int tag;
	trnode* par;
} *trptr;
int index(char str[],char str1[],int k)
{
	int m;
	for( m=0;m<strlen(str);m++)
	{
		if(str1[k]==str[m])
		{
			break;
		}
	}
	return m;
}
trptr makenode(trptr &tr1,int i,int n)
{
	trptr tr=tr1;int u;
	tr->ptr.ptr1[i]=new trnode;
	tr->ptr.ptr1[i]->par=tr;
	tr->ptr.ptr1[i]->ptr.ptr1=new trptr[n+1];
	tr=tr->ptr.ptr1[i];
	tr->tag=1;
	for(u=0;u<=n;u++)
	{
		tr->ptr.ptr1[u]=null;
	}
	return tr;
}
void insert(trptr &tr1,char str[],char str1[],int n,int ind,int ke)
{
	trptr tr=tr1;int ti,in,i,y;
	in=index(str,str1,ind);
	cout<<"in =" <<in<<endl;
    int check=0,check1=0;
    if(ke==1)
	for(y=0;y<=n;y++)
	{
		if(tr->ptr.ptr1[y]&&tr->ptr.ptr1[y]->tag==1)
		{
			check=1;
		}
	}
	if(ind==strlen(str1)&&check==1)
	{
		check1=1;
	}
	if((tr->ptr.ptr1[in]==null&&check==0)||check1==1)
	{
		cout<<"if\n";
		if(check1==0)
		{
		leafnode *l;
		l=new leafnode;
		strcpy(l->key,str1);
		tr->ptr.ptr1[in]=new trnode;
		tr->ptr.ptr1[in]->par=tr;
		tr=tr->ptr.ptr1[in];
		tr->tag=0;
		tr->ptr.ptr2=l;
	   }
	   else 
	   {
	   	leafnode *l;
		l=new leafnode;
		strcpy(l->key,str1);
		tr->ptr.ptr1[n]=new trnode;
		tr->ptr.ptr1[n]->par=tr;
		tr=tr->ptr.ptr1[n];
		tr->tag=0;
		tr->ptr.ptr2=l;
	   }
	}
	else if(tr->ptr.ptr1[in]&&tr->ptr.ptr1[in]->tag==0)
	{
		cout<<"Else if\n";
		i=in;int j=ind;
		trptr temp;
		temp=tr->ptr.ptr1[in];
		while(str1[j]==temp->ptr.ptr2->key[j])
		{
			cout<<"While\n";
			i=index(str,str1,j);
			tr=makenode(tr,i,n);
			j++;
		}
	    ti=index(str,temp->ptr.ptr2->key,j);
	    cout<<"j = "<<j<<"ti ="<<ti<<endl;
		tr->ptr.ptr1[ti]=temp;
		if(strlen(str1)==j)
		{
			tr->ptr.ptr1[n]=new trnode;
			tr->ptr.ptr1[n]->par=tr;
			tr->ptr.ptr1[n]->tag=0;
			leafnode *l=new leafnode;
			strcpy(l->key,str1);
			tr->ptr.ptr1[n]->ptr.ptr2=l;
		}
		else 
		{
			ti=index(str,str1,j);//cout<<"Ti 2 ="<<ti<<endl;
			tr->ptr.ptr1[ti]=new trnode;
			tr->ptr.ptr1[ti]->par=tr;
			tr->ptr.ptr1[ti]->tag=0;
			leafnode *l=new leafnode;
			strcpy(l->key,str1);
			tr->ptr.ptr1[ti]->ptr.ptr2=l;
		}
	}
	else
	{
		cout<<"Else\n";
		ind++;
		ke=1;
		insert(tr->ptr.ptr1[in],str,str1,n,ind, ke);
	}
}
void print(trptr tr,int n)
{
	if(tr!=null)
	{
	   
	   	   if(tr->tag==1)
	   	   {
			for(int i=0;i<=n;i++)
	   	   	print(tr->ptr.ptr1[i],n);
		   }
		   else if(tr->tag==0)
		   {
		   	cout<<tr->ptr.ptr2->key<<"    ";
		   }
    }
}
int io;
trptr repair(trptr &tr1,int in,int n,trptr temp,char str1[],char str[],int k)
{
	trptr tr=tr1;int i;
	k--;int count=0;
	tr=tr->par;cout<<"Enter Repair\n";
	for(i=0;i<=n;i++)
	{
		if(tr&&tr->ptr.ptr1[i]!=null)
		{
			count++;
		}
	}
	io=index(str,str1,k);cout<<"io ="<<io<<endl;
	while(count==1&&tr->par!=null)
	{cout<<"while repair\n";
		in=index(str,str1,k);
		tr->ptr.ptr1[in]=null;
		k--;
		tr=tr->par;
		count=0;
		for(i=0;i<=n;i++)
		{
			if(tr->ptr.ptr1[i]!=null)
			{
				count++;
			}
		}
		io=in;
	}
	cout<<"Before retur \n";
//	tr->ptr.ptr1[io]=null;
	return tr;
}
void deleteit(trptr &tr1,char str[],char str1[],int ind,int n)
{
	int in,i,j,k;
	trptr tr=tr1,temp;
	in=index(str,str1,ind);
	if(tr->ptr.ptr1[in]->tag==0)
	{
		tr->ptr.ptr1[in]=null;
	}
	else 
	{ cout<<"else delete \n";
		while(tr->ptr.ptr1[in]->tag==1)
		{
			tr=tr->ptr.ptr1[in];
			k++;
			in=index(str,str1,k);
		}
		int count=0;
		for(i=0;i<=n;i++)
		{
			if(tr->ptr.ptr1[i]!=null)
			{
				count++;
			}
		}
		if(count==2)
		{cout<<"if delete \n";
			tr->ptr.ptr1[in]=null;
			for(i=0;i<=n;i++)
			{
				if(tr->ptr.ptr1[i]!=null)
				{
					temp=tr->ptr.ptr1[i];
				}
			}
			cout<<"after\n";
			//cout<<"temp ="<<temp->ptr.ptr1[i]->ptr.ptr2->key<<endl;
			
			if(temp->tag==0)
			{
			cout<<"k= "<<k<<endl;cout<<"in ="<<in<<endl;
			if(strlen(temp->ptr.ptr2->key)!=k)
			{
			
			tr=repair(tr,in,n,temp,temp->ptr.ptr2->key,str,k);cout<<"After Repair\n";
			in=index(str,temp->ptr.ptr2->key,io);
			cout<<"in1 ="<<in<<endl;
			if(tr->ptr.ptr1[in]&&tr->ptr.ptr1[in]->tag!=1||io==0)
			{
			tr->ptr.ptr1[in]=temp;
		    }
			else
			{
			in=index(str,temp->ptr.ptr2->key,io-1);
			cout<<"in 2= "<<in<<endl;
			tr->ptr.ptr1[in]=temp;	
			}
		   }
		   else
		   {
		   	tr=repair(tr,in,n,temp,temp->ptr.ptr2->key,str,k);cout<<"After Repair\n";
			in=index(str,temp->ptr.ptr2->key,io);
			cout<<"in1 ="<<in<<endl;
			tr->ptr.ptr1[in-1]=temp;
		   }
		   }
		   else
		   {
		   	tr->ptr.ptr1[in]=null;
		   }
			
		}
		else
		{
			tr->ptr.ptr1[in]=null;
		}
	}
}
int main()
{
	trptr tr;
	leafnode *l;
	l=new leafnode;
	cout<<"Enter the no of characters u will be using \n";
	int n,i,ch;
	cin>>n;
	cout<<"Enter the String\n";
	char str[27],str1[27];
	cin>>str;
	tr=new trnode;
	tr->par=null;
	tr->ptr.ptr1=new trptr[n+1];
	tr->tag=1;
	for(i=0;i<=n;i++)
	{
		tr->ptr.ptr1[i]=null;
	}
	cout<<"Enter 1 for continue else -1\n";
	cin>>ch;
	cout<<"Enter the input string \n";
	cin>>str1;
	for(i=0;i<strlen(str);i++)
	{
		if(str1[0]==str[i])
		{
			break;
		}
	}	
	strcpy(l->key,str1);	
	tr->ptr.ptr1[i]=new trnode;	
	tr->ptr.ptr1[i]->tag=0;
	tr->ptr.ptr1[i]->ptr.ptr2=l;
	while(ch!=-1)
	{
		
		cout<<"Enter 1 for continue else -1\n";
		cin>>ch;
		if(ch!=-1)
		{
		cout<<"Enter the string to input\n";
		cin>>str1;
		insert(tr,str,str1,n,0,0);
	   }
	}
	print(tr,n);
	ch=1;
    while(ch!=-1)
    {
    	cout<<"\nEnter 1 for delete else -1\n";
    	cin>>ch;
    	if(ch!=-1)
    	{
    		cout<<"Enter string for delete \n";
    		cin>>str1;
    		deleteit(tr,str,str1,0,n);
    		print(tr,n);
		}
	}
}
