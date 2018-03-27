#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	int n1,n2,n3,r1,r2,r3,s=0,g=0;
	int score=100;
	srand(time(NULL));
	r1=rand()%10;
	if(r1==0)
	{
		r1+=1;
	}
	r2=rand()%10;
	if(r2==0)
	{
		r2+=1;
	}
	r3=rand()%10;
	if(r3==0)
	{
		r3+=1;
	}
	while(s!=3)
	{
	cout<<"Enter three number\n";
	cin>>n1>>n2>>n3;
	if(n1==r1)
	{
		s++;
	}
	else if(n1==r1||n1==r3)
	{
		g++;
	}
	if(n2==r2)
	{
		s++;
	}
	else if(n2==r1||n2==r3)
	{
		g++;
	}
	if(n3==r3)
	{
		s++;
	}
	else if(n3==r2||n3==r1)
	{
		g++;
	}
	cout<<s<<" Source  and "<<g <<" Goal \n";
	if(s==3)
	{
		cout<<" You Won and Your Score is  :"<<score;
		break;
	}
	else
	{
	s=0;
	g=0;
	score-=5;
    }
	}
	return 0;
}
