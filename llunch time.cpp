#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	//s.reserve();
	int len=s.length();
	int flag=0;
	
		flag=1;
		int count=0;
		
		int i=len-1;
		while(i>=0&&s.at(i)=='0')
		i--;
		if(i>=0)
		
		
		{
			
		
	while(1)
	{	
		while(i>=0&&s.at(i)=='0')
		{
		
			i--;
		}
		if(i>=0)
		{
		i--;		
		count++;
		}
		if(i<0) break;
		while(i>=0&&s.at(i)=='1')
		{
		
			i--;
		}
		if(i>=0)
		{
		
		i--;	
		count++;
	    }
		if(i<0) break;
//			while(s.at(i)==1&&i>=0)
//		{
//		
//			i--;
//		}
//			if(i<0) break;
	
		
	}
}
	cout<<count<<endl;
}
