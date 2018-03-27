#include<iostream>
using namespace std;
int ans1=0,ans2=0;
int find(int s[],int i)
{
	
	if(s[i]==0)
	{
		return i;
	}
	else 
	{ans1++;
	return find(s,s[i]);
	}
}
int find1(int s[],int i)
{
	ans2++;
	if(s[i]==0)
	{
		return i;
	}
	else 
	return find(s,s[i]);
}
void unions(int s[],int i,int j)
{
	if(s[j]==0)
	{
		s[j]=i;
	}
	else if(s[i]==0)
	{
		s[i]=j;
	}
	else
	{
		s[find(s,i)]=s[find(s,j)];
	}
}
void sizes(int s[],int i,int n)
{
	find(s,i);
	for(int j=1;j<=n;j++)
	{
		if(s[j]==i)
		{
			find1(s,j);		
            break;

		}
	}
}
int main()
{
	int n,m;int q;
	//cout<<"Enter the no of elements\n";
	cin>>n>>q;
    char ch,M;
    
	int i=1,j;
	int s[n+1]={0};
	while(q--)
	{
		//cout<<"Enter the first element of the group else -1 \n";
        cin>>ch;
        if(ch=='Q')
            {
		cin>>i;
            sizes(s,i,n);
            cout<<"ANS 1 ="<<ans1<<endl;
            cout<<"ANS 2 ="<<ans2<<endl;
            cout<<ans1+ans2+1<<endl;ans1=0;ans2=0;
        }
        else if(ch=='M')
            		{
			//cout<<"Enter the second element of the group  \n";
		    cin>>i>>j;
		    unions(s,i,j);
        }
		
	}
	//cout<<"Enter the key for which u wanna search\n";
	//cin>>m;
	//sizes(s,m,n);int k=(ans1+ans2);
	
	//cout<<"Ans="<<k<<endl;
	
}
