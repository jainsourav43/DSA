#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<int ,int>m;
int main()
{
	vector<int>a,ans;
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	int i;
	for(i=0;i<k;i++)
	{
		m[a[i]]++;
	}
	ans.push_back(m.size());
	for(i=k;i<n;i++)
	{
		m[a[i-k]]--;
		if(m[a[i-k]]==0)
		m.erase(a[i-k]);
		m[a[i]]++;
		ans.push_back(m.size());
	}
	for(i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	
}
