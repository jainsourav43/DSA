#include<iostream>
#include<vector>
using namespace std;
class BadNeighbors
{
	
	
	public :int maxDonations(vector<int> a)
	{
		int n=a.size();
		int i,j,sum1=0,sum2=0;
		for(i=0;i<n-1;i+=2)
		{
			sum1=sum1+a[i];
		
		}
		for(i=1;i<n;i+=2)
		{
			sum2=sum2+a[i];
		
		}
		//cout<<max(sum1,sum2)<<endl;
		return max(sum1,sum2);
	}
};
int main()
{
	vector<int> v;
	BadNeighbors b;
	v.push_back(7);
	v.push_back(7);
	v.push_back(7);
	v.push_back(7);
	v.push_back(7);
	v.push_back(7);
		v.push_back(7);
	b.maxDonations(v);
}
