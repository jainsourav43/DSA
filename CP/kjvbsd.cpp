#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
vector<long long int > a;
void  make(char* s,int n)
{
	int i=0;
	long long num=0;
	while(i<n)
	{
		num=0;
		while(i<n&&s[i]!=' ')
		{
			num=num*10+(s[i]-'0');
			i++;
		}
///		cout<<num<<endl;
		a.push_back(num);
		i++;
	}
}
int main()
{
	int t;
	cin>>t;
	int c=0;
	t++;
	
	while(t--)
	{
	    char s[5001];
		a.clear();
		if(c==0)
		{
		c++;
		cin.getline(s,5000);
		continue;
		}
		cin.getline(s,5000);
				int len=strlen(s);

		make(s,len);

		int n=a.size()-1;
//		cout<<"N= "<<n<<endl;
		for(int i=0;i<a.size();i++)
		{
			if(a[i]==n)
			{
				a[i]=INT_MIN;
				break;
			}
		}
		int ans=INT_MIN;
		for(int i=0;i<a.size();i++)
		{
//			cout<<" a[i]= "<<a[i]<<endl;
			if(ans<a[i])
			{
				ans=a[i];
			}
		}
		cout<<ans<<endl;
      
		
	}
}
