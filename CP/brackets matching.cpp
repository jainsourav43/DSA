#include<iostream>
#include<stack>
using namespace std;
stack <int> s;
int main()
{
	int n;
	cin>>n;
	int a[n],i,j;
	int b;
	cout<<b<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int index1,index2,max1=0,count1=0,max2=0,findex;//cout<<count1<<endl;
	for(i=0;i<n; )
	{
		if(count1==0)
		index2=i+1;
		while(a[i]==1)
		{
			s.push(a[i]);
			count1++;
			i++;
			
		}
		if(max1<s.size())
		{
			max1=s.size();
			index1=i;
		}
		while(a[i]==2)
		{
			s.pop();
			i++;
			count1++;
		}
		if(s.size()==0&&max2<count1)
		{
		max2=count1;
		findex=index2;
			count1=0;
		}
		if(s.size()==0) count1=0;
	

	}
w	cout<<max1<<" "<<index1<<" "<<max2<<" "<<findex<<endl;
}
