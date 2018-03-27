#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
ll t;
cin>>t;
while(t--)
{
ll n;
cin>>n;
ll a[n],i,j=0,m,o=0,e=0;ll k[n],size[4];
for(i=0;i<n;i++)
{
	cin>>a[i];
	if(a[i]%2==0)
	{
		e++;
	}
	else
	{k[j]=i;
		o++;
		j++;
	}
}
if(o%2==0)
{
	cout<<n<<endl;
}
else
{
	size[0]=k[0];
	size[1]=n-(k[0]+1);
	size[2]=k[j-1];
	size[3]=n-(k[j-1]+1);
	sort(size,size+4);
if(o!=0)
cout<<size[3]<<endl;
}

}	
return 0;
}

