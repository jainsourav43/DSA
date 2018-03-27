#include<ostream>
#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>p1,pair <int,int>p2)
{
	return p1.second<p2.second;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,i,j;
		cin>>n>>k;
		vector<pair <int ,int >  > v;
		for(i=0;i<k;i++)
		{
			int x,y;cin>>x>>y;
			v.push_back(make_pair(x,y));
		}
		sort(v.begin(),v.end(),comp);
		string s;
		for(i=0;i<n;i++)
		{
			s=s+'.';
		}
		for(i=0;i<k;i++)
		{
			int flag=0;
			for(j=v[i].first;j<=v[i].second;j++)
			{
				if(!flag)
				{
					if(s[j]=='.')
					{
						s[j]='(';
					}
					flag=(!flag);
				}
				else
				{
					if(s[j]=='.')
					{
						s[j]=')';
					}
					flag=(!flag);
				}
			}
		}
		for(i=0;i<n;i++)
		{
			if(s[i]=='.')
			{
				s[i]=')';
			}
		}
		cout<<s<<endl;
	}
}
