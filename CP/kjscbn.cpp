#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long 
ll a[20];
int n,k,ans=0;
void check(int *b)
{
	int i;int sum=0;
	int check=0;
//	cout<<"printing b\n";
//	for(i=0;i<n;i++)
//	{
//		cout<<b[i]<<" ";
//	}
//	cout<<endl;
//	cout<<"printing a\n";
//	for(i=0;i<n;i++)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	for(i=0;i<n;i++)
	{
		
		if(a[i]>b[i])
		{
			check=1;
			break;
		}
		else if(a[i]<b[i])
		{
			check=0;
			break;
		}
		else
		{
			continue;
		}
	}
	if(check==1)
	{
		for(i=0;i<n;i++)
		{
			sum=sum+abs(a[i]-b[i]);
		}
			if(sum<=k)
			{
				//cout<<"Hii\n";
				ans++;
			}
	}

}
void permute(int *b, int l, int r)
{
   int i;
   if (l == r)
   {
   	check(b);
   }
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((b[l]), (b[i]));
          permute(b, l+1, r);
          swap((b[l]), (b[i])); //backtrack
       }
   }
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
			//cout<<"mod"<<mod<<endl;

		cin>>n;
		cin>>k;
		int b[n];
		int i;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			b[i]=a[i];
		}
		ans=0;
		permute(b,0,n-1);
		
		cout<<ans<<endl;
	
	
	
		
		
	
	}
}
