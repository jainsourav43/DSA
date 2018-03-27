#include<iostream>
using namespace std;
int start=4;
int leap(int y)
{
	if(y%4==0&&(y%100!=0)||y%400==0)
	return 1;
	else
	return 0;
}
void print(int y)
{
	cout<<"Welcome to the calender of year"<<endl;
	cout<<"      "<<y<<endl<<endl;
	int a[12];
	string p[]={"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
	if(leap(y))
	int a[]={31,29,31,30,31,30,31,31,30,31,30,31};
	else
	int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int i,j,k;
	for(i=0;i<=11;i++)
	{
		cout<<"       "<<p[i]<<endl;
		cout<<"mo tu we th fr sa su\n";
		for(k=0;k<start;k++)
			cout<<"   ";
		for(j=1;j<=a[i];j++)
		{
			if(j<10)
			cout<<j<<"  ";
			else
			cout<<j<<" ";
			if((j+start)%7==0)
			cout<<endl;
		}
		start=start+a[i]%7;
		if(start>=7)
		start=start%7;
		cout<<endl<<endl;
	}
}
void upstart(int g)
{int i;
		if(g>2016)
	{
	for(i=2016;i<g;i++)
{
	if(leap(i))
	{
		start=start+2;
	}
	else
	{
		start=start+1;
	}
	
}
if(start>=7)
{
	start=start%7;
}
}
else
{
	for(i=2015;i>=g;i--)
	{
		if(leap(i))
	{
		start=start-2;
	}
	else
	{
		start=start-1;
	}
	if(start<0)
	{
	start=7+start	;
	}
	}
}
}
int main()
{	int g;
	cout<<"Enter the year \n";
	cin>>g;int i;
upstart(g);
	print(g);
	return 0;
}
