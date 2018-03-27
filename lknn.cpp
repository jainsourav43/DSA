#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<int,set<int> > m;
	m[0].insert(0);
	m[0].insert(8);
	m[1].insert(3);
	m[1].insert(1);
	m[1].insert(4);
	m[1].insert(7);
	m[1].insert(8);
	m[1].insert(9);
	m[2].insert(2);
	m[2].insert(8);
	m[3].insert(8);
	m[3].insert(3);
	m[3].insert(9);
	m[4].insert(8);
	m[4].insert(4);
	m[4].insert(9);
	m[5].insert(8);
	m[5].insert(5);
	m[5].insert(9);
	m[6].insert(8);
	m[6].insert(6);
	m[7].insert(7);
	m[7].insert(8);
	m[7].insert(9);
	m[7].insert(0);
	m[8].insert(8);
	m[9].insert(8);
	m[9].insert(9);
	int n,m1;
	cin>>n>>m1;
	if(n<=m1)
	{
		vector<int> v,u;
		vector<int>ans;
		int temp=n,i,j,k,in,check=0;
		while(temp)
		{
			v.push_back(temp%10);
			temp/=10;
		}
		reverse(v.begin(),v.end());
		 temp=m1;
		while(temp)
		{
			u.push_back(temp%10);
			temp/=10;
		}
		reverse(u.begin(),u.end());
		for(j=0;j<=u.size()-v.size();j++)
		{
			k=j;
			cout<<"j,k= "<<j<<" "<<k<<endl;
		//	cout<<"v[i],u[k] = "<<v[i]<<" "<<u[k]<<endl;
			for(i=0;i<v.size();i++)
			{
				cout<<"v[i],u[k] = "<<v[i]<<" "<<u[k]<<endl;
				if(m[v[i]].find(u[k])!=m[v[i]].end())
				{
					k++;	
			    }
				else
				{
					break;
			    }	   
			}
			if(k==j+v.size())
			{
				in=j;
				check=1;
				break;
			}
			
		}
	
		if(check)
		{
			for(i=0;i<in;i++)
			{
				ans.push_back(u[i]);
			}
		  for(i=in;i<in+v.size();i++)
		  {
		  	auto it=m[u[i]].begin();
		     for(j=0;j<m[u[i]].size();j++)
			 {
			 	if(*(it)<u[i])
			 	{
			 		it++;
				}
				else if(*it>u[i])
				{
					it--;
					break;
				}
				else 
				{
					break;
				}
				
		     }
			 ans.push_back(*it);	
		  } 
		  for(i=in+v.size();i<u.size();i++)
		  {
		  	ans.push_back(u[i]);
			}	
		}
		for(i=0;i<ans.size();i++)
		{
			cout<<ans[i]<<" ";
		}
		
		
		
		
	}
	else
	{
		
	}
	
}
