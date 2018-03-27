#include<iostream>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	bool v[n+1];
	for(int i=1;i<=n;i++)
	{
		v[i]=false;
	}
	string str;int ch;
	int sum=0;
	for(int i=0;i<k;i++)
	{
		cin>>str;
		if(str=="CLICK")
		{
			int ch;
			cin>>ch;
			if(v[ch]==false)
			{
				sum++;
			}
			else
			{
				sum--;
			}
			v[ch]=(!v[ch]);
			if(sum>=0) cout<<sum<<endl;
			else
			cout<<0<<endl;
		}
		else
		{
				for(int j=1;j<=n;j++)
				{
					v[j]=false;
				}
				sum=0;
				cout<<0<<endl;
		}
		
	}
}
