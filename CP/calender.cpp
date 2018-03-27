#include<iostream>
using namespace std;
int start=4;
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
{ int i,j,k,l;int a[12];int m=1;;
  if(leap(y))
  {
  int 	a[12]={31,29,31,30,31,30,31,31,30,31,30,31};
  }
  else
  {
  	  	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  }
  cout<<"Welcome to the calender\n";
 cout<<"    "<<y<<endl;
  for(i=0;i<=11;i++)
  { month(m);
  cout<<"mo tu we th fr sa su"<<endl;
  for(k=0;k<start;k++)
  {
  	cout<<"   ";
  }
  	for(j=1;j<=a[i];j++)
  	{   if(j<10)
  		cout<<j<<"  ";
  		else
  		{
  			cout<<j<<" ";
		  }
  		if((j+start)%7==0)
  		{
  			cout<<endl;
		  }
	  }
	  start=start+a[i]%7;
	  if(start>=7)
	  {
	  	start=start%7;
	  }
	  cout<<endl;
	  m++;
  }
}
int main()
{
	print(start,2016);
	return 0;
}
