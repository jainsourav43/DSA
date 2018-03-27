#include<iostream>
using namespace std;
int k=0;int pn;int pn1;
void p(int y)
{
	switch(y)
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
}
void pri(int o)
{
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
	int i,j,l;
	if(n<10)
	{pn1=n;
		return;
	}else
	{
	    pn=n%10;	k++;l=k;
		print(n/10);
	}l+=1;
	if(l==1)
	switch(n%10)
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
	 if(l==3)
	{
		switch((n/10)%10)
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
	}if((n/10)%10!=0)
	cout<<"Hundred ";
	}
	if(l==4)
	{
			switch(n/10)
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
	cout<<"thousand  ";
	}
	if(l==2)
	{
		switch((n/10)%10)
	{
		case 1:
	    case 0:
		pri(pn);
		break;
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
	if((n/10)%10!=1)
	p(n%10);
	}
}
int main()
{int n;
	cout<<"enter  the 4 digit no. \n ";
	cin>>n;
	print(n);
}
