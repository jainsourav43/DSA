#include<iostream>
using namespace std;
int start=4;
void day(int j)
{
	if(j==1)
	{
		cout<<"mo  ";
	}
	else if(j==2)
	{
		cout<<"tu  ";
	}
	else if(j==3)
	cout<<"we  ";
	else if(j==4)
	cout<<"th  ";
	else if(j==5)
	cout<<"fr  ";
	else if(j==6)
	cout<<"sa  ";
	else if(j==7)
	cout<<"su  ";
}
void month(int m)
{
	if(m==1)
	{
		cout<<"    january"<<endl;
	}
	else if(m==2)
	{
		cout<<"    Febuary"<<endl;
	}
	else if(m==3)
	{
		cout<<"    march"<<endl;
	}
	else if(m==4)
	{
		cout<<"    april"<<endl;
	}
	else if(m==5)
	{
		cout<<"    may"<<endl;
	}
	else if(m==6)
	{
		cout<<"    june"<<endl;
	}
	else if(m==7)
	{
		cout<<"    july"<<endl;
	}
	else if(m==8)
	{
		cout<<"   august"<<endl;
	}
	else if(m==9)
	{
		cout<<"   september"<<endl;
	}
	else if(m==10)
	{
		cout<<"    october"<<endl;
	}
	else if(m==11)
	{
		cout<<"    november"<<endl;
	}
	else if(m==12)
	{
		cout<<"    december"<<endl;
	}
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
	int a[12];
    int i,j,k=0,l;int m=1;
  if(leap(y))
  {
  int 	a[12]={31,29,31,30,31,30,31,31,30,31,30,31};
  }
  else
  {
  	  	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  }
  for(i=0;i<=11;i++)
  {month(m);
  	for(j=1;j<=7;j++)
  	{
  		day(j);
	  if(k<start)
   	{
  		cout<<"  ";
  	
	  }
  	for(l=7+j-start;l<=a[i];l+=7)
	  {
	  if(k==start)
	  {
	  	l=1;
	  }
	  if(l<10)
	  	cout<<l<<"  ";
	  	else
	  	{
	  		cout<<l<<" ";
		  }
	  }
	  cout<<endl;
	  k++;
	  }
	  start=start+a[i]%7;
	  if(start>=7)
	  {
	  	start=start%7;
	  }
	  m++;
  }
}
int main()
{
	print(start,2016);
	return 0;
}
