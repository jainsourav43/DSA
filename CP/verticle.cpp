#include<bits/stdc++.h>
using namespace std;
string m[]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};
string s[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
int d[]={31,29,31,30,31,30,31,31,30,31,30,31};
int t=5;
void makevcalendar(int xx,int t)
{
	cout<<"\n\n\t\t\t"<<m[xx]<<"\n\n";
	int a[7][6];
	memset(a,0,sizeof a);
	int c=1,c1=0;
	for(int i=0; i<t; i++)
	{
		a[i][0]=-1;
	
	}
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<7; j++)
		{
			if(c>d[xx])
			{
				a[j][i]=-1;
			}
			if(a[j][i]!=-1)
			{
				a[j][i]=c;
				c++;
			}
		}
	}
	for(int i=0; i<7; i++)
	{
		cout<<s[i]<<"\t";
		for(int j=0; j<6; j++)
		{
			if(a[i][j]==-1)
			cout<<"  \t";
			else
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
	for(int i=0; i<7; i++)
	{
		for(int j=0; j<6; j++)
		if(a[i][j]==-1)
		c1++;
	}
	cout<<endl;
	c1=(c1-t)%7;
	if(xx==11)
	return;
	makevcalendar(xx+1,(7-c1)%7);
}
int main()
{
	makevcalendar(0,t);
}
