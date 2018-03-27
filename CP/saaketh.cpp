#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int v[1000000] = {0};
int jumps( string a ,int i ,int n)
{
	if(i == n )
	{
		//cout<<"  i"<<i;
		v[i] = 1;
		return 0;
	}
	if( a[i] == '1' )
	{
		if( i== 0)
		{
			v[0]  = 1;
			v[i+1] ++;
			return jumps( a , i+1, n);
		}
		if( i>=1)
		{
			if( v[i-1] == 0 ) 
			{
				v[i-1] ++;
				return jumps(a , i-1 ,n);
			}
			else 
			{
				v[i+1] ++ ;
				return jumps ( a , i+1 ,n);
			}
		}
		
	}
	if( a[i] == '2')
	{
		if( i ==0)	
		{	
			v[i] =1;
			v[i+2] ++;
			return jumps( a , i+2, n);
		}
		if( i == 1)
		{
			v[i+2] ++;
			return jumps( a ,i+2, n);
		}
		if(i>1)
		{
			v[i+2] ++;
			return jumps( a,i+2,n);
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	   	string a,b;
	   	cin>>a>>b;
	   	int i,flag =0,flag2=0,count =0;;
	   	if( a.length() ==1 && b.length() ==1)
	   	{
	   		cout<<2<<endl;
	   		
		   }
		else
		{	
			for( i=0 ;i< 1000000;i++)
			{
				v[i] =0;
			}
			jumps (a , 0 , a.length() -1);
				
				for( i=0;i< a.length();i++)
		{
		//	cout<<v[i]<<"   "<<i<<endl;
			if( v[i] != 1)
			{
				flag = 99;
				break;
			}
		}		
			for( i=0 ;i< 1000000;i++)
			{
				v[i] =0;
			}
			jumps (b , 0 , b.length() -1);
			for( i=0;i< a.length();i++)
		{
		//	cout<<v[i]<<"   "<<i<<endl;
			if( v[i] != 1)
			{
			flag2 = 99;
				break;
		}
		}
		if( flag ==0 && flag2 ==0)
		{
			for( i=0; i<a.length() ;i++)
			{
				if( a[i] == b[i])
				count++;
			}
			count++;
			cout<<pow(2 , count)<<endl;
		}
		else 
		cout<<0<<endl;
		}
	}	
}
