#include<iostream>
#define null NULL
#define ll long long
#include<set> 
using namespace std;
struct trnode;
struct leafnode;
union un
{
	trnode *tptr[27];
	leafnode *lptr;
};
typedef struct leafnode
{
	string str;
} * leafptr;
typedef struct trnode
{
	int tag;
	un ptr;
	trnode *par;
} * trieptr;
void initialse(trieptr t)
{
//	cout<<"initialise\n";
	for(int i=0;i<=26;i++)
	t->ptr.tptr[i]=null;
}
void createnode(trieptr t,int tag)
{
	if(tag==1)
	{
		t->tag=1;
		initialse(t);
	}
	else
	{
		t->tag = 0;
	}
 } 

int findIndex(string &str,int i,char* &cs)
{
	if(i>=str.length()) return 26;
	char ch = str[i];
	for(int j=0;j<26;j++)
	{
		if(cs[j]==ch)
		return j;
	}
}
void insertnode(trieptr &t,string &s,int i,int ind,char *&cs )
{
	if(t->ptr.tptr[ind]==null)
	{
		t->ptr.tptr[ind]=new trnode;
		createnode(t->ptr.tptr[ind],0);
		t->ptr.tptr[ind]->ptr.lptr=new leafnode;
		t->ptr.tptr[ind]->ptr.lptr->str=s;
	}
	else
	{
		if(t->ptr.tptr[ind]->tag==1)
		{
			insertnode(t->ptr.tptr[ind],s,i+1,findIndex(s,i+1,cs),cs);
		}
		else
		{
			trieptr tmp=t->ptr.tptr[ind];
			t->ptr.tptr[ind]=new trnode;
			createnode(t->ptr.tptr[ind],1);
			t->ptr.tptr[ind]->ptr.tptr[findIndex(s,i+1,cs)]=tmp;
			insertnode(t,s,i+1,findIndex(s,i+1,cs),cs);
		}
	}
}

string search(trieptr &t ,string &s,int i,char *&cs)
{
	int ind=findIndex(s,i,	cs);
	if(t!=null)
	{
	if(t->tag==1)
	{
		return search(t->ptr.tptr[ind],s,i+1,cs);
	}
	else if(t->tag==0)
	{
		int j=0;
		while(s.length()>j&&t->ptr.lptr->str.length()>j&&t->ptr.lptr->str.at(j)==s.at(j))
		{
			j++;
		}
		if(j<s.length()&&j<t->ptr.lptr->str.length())
		return s.substr(0,j+1);
		else if(j==s.length()&&j<t->ptr.lptr->str.length())
		{
			return "98";
		}
		else if (j<s.length()&&j==t->ptr.lptr->str.length())
		{
			return s.substr(0,j+1);
		}
	}
	}
	else
	{
		return s.substr(0,i);
	}
}
void print(trieptr tr)
{
	if(tr!=null)
	{
	   	//	cout<<"print\n";
	   	   if(tr->tag==1)
	   	   {
	   	   	//cout<<"print1\n";
			for(int i=0;i<26;i++)
	   	   	print(tr->ptr.tptr[i]);
		   }
		   else if(tr->tag==0)
		   {
		   //cout<<"print2\n";
		  //cout<<tr->ptr.lptr if()
		   	cout<<tr->ptr.lptr->str<<"    ";
		   }
    }
}



int main()
{
	
	ll n,i,j;
	int ans=0;
	cin>>n;
	string b[n+1],u[n+1];
	char c[n+1];
	ll l=0,m=0;
	for(i=0;i<n;i++)
	{
		cin>>c[i];
		if(c[i]=='+')
		{
			cin>>u[l++];
		}
		else
		{
			cin>>b[m++];
		}
	}
	if(m>=1)
	{
	trieptr t;
	char *cs="abcdefghijklmnopqrstuvwxyz";
	t=new trnode;
	t->tag=1;
	createnode(t,1);	
	for(i=0;i<l;i++)
	{
	insertnode(t,u[i],0,findIndex(u[i],0,cs),cs);
	}	
	//print(t);
	string tep1;
	set<string> se;
	for(i=0;i<m;i++)
	{
	ans=0;
	tep1=search(t,b[i],0,cs);
		if(tep1!="98")
		se.insert(se.end(),tep1);
		else
		{
		ans=1;
		break;
		}		
	}
	if(ans==0)
	{
	cout<<se.size()<<endl;
	typeof(se.begin()) it=se.begin();
	for(int i=0;it!=se.end();i++)
	{
		cout<<*it<<" \n";
		it++;
	}
	}
	else
	{
		cout<<-1<<endl;
	}
	}
	else
	{
		cout<<-1<<endl;
	}
}

