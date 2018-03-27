#include<bits/stdc++.h>
using namespace std;
class FibonacciDiv2
{
public:int find(int );
void initialise();
int calculate1(int ,int,int  );
int calculate2(int ,int,int  );
int min(int,int);
};
int f[1000001];bool dp[2*1000001],check[2*1000001];
int count1;
int FibonacciDiv2::min(int n1,int n2)
{
if(n1<n2)
return n1;
return n2;
}

void FibonacciDiv2::initialise()
{
f[0]=0;
f[1]=1;
int i;
for(i=2;f[i-1]+f[i-2]<=2*1000000;i++)
{
f[i]=f[i-1]+f[i-2];
cout<<f[i]<<endl;
}
for(int j=0;j<i;j++)
{
	cout<<f[j]<<endl;
dp[f[j]]=true;
}
}

int FibonacciDiv2:: calculate1(int cn,int n,int p)
{
if(cn>2*n)
return 100000000;
if(dp[cn]==true)
return p;
else 
return  calculate1(cn+1,n,++p);
}

int FibonacciDiv2:: calculate2(int cn,int n,int p)
{
if(cn<0)
return 100000000;
if(dp[cn]==true)
return p;
else 
return  calculate2(cn-1,n,++p);
}
int FibonacciDiv2:: find(int n)
{
initialise();
check[0]=true;
check[1]=true;
int ans=min(calculate1(n,n,0),calculate2(n,n,0));
return ans;
}
int main()
{
	FibonacciDiv2 f;
//	cout<<"hii\n";
	int n;
	cin>>n;
	cout<<f.find(n);
}
