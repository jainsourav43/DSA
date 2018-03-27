#include<iostream>
using namespace std;
int k=0;int pn;
void pri(int im,int o)
{
	if(im==1)
	{
		switch(o)
		{
			case 1:cout<<"Eleven  ";
			break;
			case 2:cout<<"Twelve  ";
			break;
			case 3:cout<<"Thirteen ";
			break;
			case 4:cout<<"fourteen ";
			break;
			case 5:cout<<"fifteen  ";
			break;
			case 6:cout<<"sixteen  ";
			break;
			case 7:cout<<"seventeen  ";
			break;
			case 8:cout<<"eighteen  ";
			break;
			case 9:cout<<"ninteen  ";
			break;
			
		}
	}
}
void print(int n)
{
	int i,j,k,l;
	if(n<10)
	{
		
	}
	else
	{
		k++;pn=n%10;
		print(n/10);
	}
	if(k==1)
	switch(i)
	{
		case 1:cout<<"one"<<" ";
		break;
		case 2:cout<<"two  ";
		break;
		case 3 :cout<<"three  ";
		break;
		case 4:cout<<"four  ";
		break;
		case 5:cout<<"five  ";
		break;
		case 6 :cout<<"Six  ";
		break;
		case 7:cout<<"seven  ";
		break;
		case 8 :cout<<"eight  ";
		break;
		case 9:cout<<"nine  ";
		break;
	}
	else if(k==3)
	{
		switch(i)
	{
		case 1:cout<<"one"<<" ";
		break;
		case 2:cout<<"two  ";
		break;
		case 3 :cout<<"three  ";
		break;
		case 4:cout<<"four  ";
		break;
		case 5:cout<<"five  ";
		break;
		case 6 :cout<<"Six  ";
		break;
		case 7:cout<<"seven  ";
		break;
		case 8 :cout<<"eight  ";
		break;
		case 9:cout<<"nine  ";
		break;
	}
	cout<<"Hundred ";
	}
	if(k==2)
	{
		switch(i)
	{
		case 1:
		{
//	pri(int i,int pn);
		break;}
		case 2:cout<<"twenty ";
		break;
		case 3 :cout<<"thirty  ";
		break;
		case 4:cout<<"fourty  ";
		break;
		case 5:cout<<"fifty  ";
		break;
		case 6 :cout<<"Sixty  ";
		break;
		case 7:cout<<"seventy  ";
		break;
		case 8 :cout<<"eighty  ";
		break;
		case 9:cout<<"ninty  ";
		break;
	}
	}	
}
int main()
{
	print(3245);
	return 0;
}
