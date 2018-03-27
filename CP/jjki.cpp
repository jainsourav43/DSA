#include<cmath>
#include<iostream>
int b[500][500],c[500][500];
bool v[500][500];
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
    int a[n][n];
	int i,j,k,zero=0,one=0,bw=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
			if(a[i][j])
			{
				if(bw<abs(i-j))
				{
					bw=abs(i-j);
				}
				b[i][j]=1;
				one++;
			}
			else
			{
				zero++;
			}
		}
	}
	if(one==0||one <=n)
	{
		cout<<0<<endl;
	}
	else if(zero==0)
	{
		cout<<n-1<<endl;
	}
	else 
	{
	int tempone =one-n;
	i=1;
	while(tempone>0)
	{
		tempone-=2*(n-i);
		bw=i;
		i++;
	}
	cout<<bw<<endl;
	}
    }
}
