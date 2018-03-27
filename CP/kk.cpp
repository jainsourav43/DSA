#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
bool primes[100000];
vector<int>p1;
void prime1(int n)
{
	int limit=floor(sqrt(n))+1;
	cout<<"limit ="<<limit<<endl;
	primes[1]=true;
	int p=2,i;
	int check=0;
	while(check==0)
	{
	for(int i=2*p;i<=limit;i+=p)
	{
		primes[i]=true;
	}
	check=1;
	for(i=p+1;i<=n;i++)
	{
		if(primes[i]==false)
		{
			check=0;
			p=i;
			break;
		}
	}
	}
	for(i=1;i<limit;i++)
	{
		if(!primes[i])
		{
			p1.push_back(i);
			cout<<i<<endl;
		}
	}
	
	int l=limit;
	int h=2*limit,j;
	
	while(l<=n)
	{
		cout<<"again\n";
		int m[limit+1];
		int lo;
		for(i=0;i<limit+1;i++)
		{
			m[i]=true;
		}
		for(int i=0;i<p1.size();i++)
		{
			lo=floor(l/p1[i])*p1[i];
			if(lo<l)
			{
				lo+=p1[i];
			}
			
			
			for(j=lo;j<=h;j+=p1[i])
			{
				m[j-l]=false;
			}
			
		}
		for (int i = l; i<h; i++)
            if (m[i - l] == true)
            {
				cout<<i<<endl;
                p1.push_back(i);
            }
                l+=limit;
                h+=limit;
                if(h>n) h=n;
		
	}
	
	
	
}


int main()
{
	int n;
	cin>>n;
	prime1(n);
}
