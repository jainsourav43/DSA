#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
struct CompareVec
{
    CompareVec(const std::vector<int>& _in) : compare_against(_in){}

    bool operator()(const std::vector<int>& rhs) const
    {
        return compare_against == rhs;
    };

    const std::vector<int>& compare_against;
};
map<string, bool> se;
bool balanced(string str)
{
	stack<char> s;
	int i=0;
	int len=str.length();
//	cout<<str<<endl;
	while(i<len)
	{
//	cout<<"Bye\n";
	while(i<len&&str.at(i)=='(')
	{
		s.push(str.at(i));
		i++;	
	}
	while(i<len&&str.at(i)==')')
	{
	//	cout<<"Hii\n";
		if(!s.empty()&&s.top()=='(')
		{
			i++;
			s.pop();
		}
		else
		{
			se[str]=false;
			return false;
		}
	}
	}
	
	if(s.empty())
	{
	se[str]=true;
	return true;
	}
	se[str]=false;
	return false;
}
void myfun(vector< string> &ans,string str,int n,int open,int close)
{
	cout<<"s= "<<str<<endl;
if(open==close&&open==n)
{
	ans.push_back(str);
}
if(open>n||close>n)
return;
if(open<n)
{
	str.push_back('(');
	myfun(ans,str,n,open+1,close);
	str.pop_back();
}
if(close<open)
{
	str.push_back(')');
	myfun(ans,str,n,open,close+1);
	str.pop_back();
}
	      
		
		
}
vector<string> func(int n)
{
	
		string s;
		int i;
	for(i=0;i<n;i++)
	{
		s=s+"(";
	}
	for(i=n;i<2*n;i++)
	{
		s=s+")";
	}
	vector<string > ans;
	sort(s.begin(),s.end());
	string str="";
//	cout<<"befoe main= "<<s<<endl;

    myfun(ans,str,n,0,0);

	sort(ans.begin(),ans.end());
	ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
	for(i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<"  ";
	}
	return ans;
	
}
int main()
{
	int n;
	cin>>n;
	int s;
//	cin>>s;
	func(n);
	
}
