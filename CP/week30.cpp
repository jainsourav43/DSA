#include<iostream>
#include<string.h>
using namespace std;
int length=0,n1;
bool check(int i)
{
	if(i-96==1||i-96==5||i-96==9||i-96==15||i-96==21)
	{
		return true;
	}
	else
	return false;
}
void mini(int n,int pos,int prev ,int first,char str[])
{
	length=pos;
	int i;
	if(n>0)
	{
	for(i=1;i<=26;i++)
	{
		length=pos;
		if(pos==0)
		{
			if(i==25)
			continue;
			else
			{
			if(check(96+i))
			{
				str[length]=char(96+i);
				length++;
				mini(n-1,pos+1,96+i,1,str);
			}
			else
			{
				str[length]=char(96+i);
				length++;
				mini(n-1,pos+1,96+i,0,str);	
			}
		    }
		}
		else 
		{
			
				if(check(prev))
				{
					if(!check(96+i)&&char(96+i)!='y')
					{
						str[length]=char(96+i);
						
						length++;
						mini(n-1,pos+1,96+i,first,str);
						length--;
					}
					else continue;
				}
				else if(!check(prev)&&char(96+i)!='y')
				{
					if(check(96+i))
					{
						//cout<<char(96+i);
						str[length]=char(96+i);
						length++;
						mini(n-1,pos+1,96+i,first,str);
						length--;
					}
					else continue;
				}
		}
	}
}
else
{
	if(length)
	{

	for(i=0;i<length;i++)
	{
	cout<<str[i];
     }
	cout<<endl;}
}

}
int main()
{
	int n,t;
	cin>>n;n1=n;
	char str[7];
///	cout<<(char)97+1;
//	cout<<"  "<<char(97+1);
	mini(n,0,0,0,str);
	
}

