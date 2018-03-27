#include<iostream>
using namespace std;
int start=4;int h=1;int u=1;int o=0;
void hy(int g)
{
		if(o<g)	{cout<<"  ";o++;}
	else if(h<8){cout<<h<<" ";h++;}
}
void day(int j)
{
	if(j==1)cout<<"mo  ";
	else if(j==2)cout<<"tu  ";
	else if(j==3)cout<<"we  ";
	else if(j==4)cout<<"th  ";
	else if(j==5)cout<<"fr  ";
	else if(j==6)cout<<"sa  ";
	else if(j==7)cout<<"su  ";	
}
int leap(int y)
{
	if(y%4==0&&y%100!=0||y%400==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void print(int start,int y)
{
cout<<"Welcome to the calender in verticle fashion\n"<<"      "<<y<<endl;
	int a[12];	string p[]={"janurary","feburary","march","april","may","june","july","august","september","october","november","december"};//for printing months using 
    int i,j,k=0,l;int m=1;
  if(leap(y))
     int a[12]={31,29,31,30,31,30,31,31,30,31,30,31};
  else
  	  	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  for(i=0;i<=11;i++)//months in a year
  {
  cout<<"      "<<p[i]<<endl<<endl;k=0;
  	for(j=1;j<=7;j++)//used for ptint lines 
  	{
  		day(j);hy(start);//hy is used foe first coloumn
	  
  	for(l=7+j-start;l<=a[i];l+=7)//days
	  {
	  if(l<10)
	  	cout<<l<<"  ";//double spaces for single digit
	  	else
	  		cout<<l<<" ";}//single space for two digit no.
	  cout<<endl;
	  }
	  start=start+a[i]%7;//updating start
	  if(start>=7)
	  	start=start%7;
	 o=0;h=1;cout<<endl<<endl;//updating o,h
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
{
	int g;
	cout<<"Please enter the year \n";
	cin>>g;int i;
	if(g>0)
	{
upstart(g);
print(start,g);
}
else
{
	cout<<"You entered the stupid year\n";
}
	return 0;
}
