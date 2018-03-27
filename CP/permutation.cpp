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
bool che[3];
void print1(char str[],int i,int n)
{
	if(i==n)
	{
		cout<<str<<" \n";
	}
	else
	{
		for(int j=i;j<n;j++)
		{
			swap(str[i],str[j]);
			print1(str,i+1,n);
			swap(str[i],str[j]);
		}
	}
}
void print(char str[],int n,int pos,int o,char prev)
{
	int len=pos,check=0;
	if(n>0)
	{
	for(int i=0;i<3;i++)
	{
		
		che[o]=false;
		if(prev=='\0')
		{
			str[len]=char(97+i);
			len++;
			check=1;
		}
		else if(str[i]!=prev)
		{
	//	cout<<"hello guys\n";
		str[len]=char(97+i);
		len++;
			//cout<<str<<" ";
		check=1;
		}
		//if(len==3)
	//	cout<<str<<" ";
		//o++;
		if(check)
		print(str,n-1,pos+1,o,str[len-1]);
		else
		print(str,n-1,pos+1,o,prev);
		//o--;
		//o--;
		if(check)
		len--;
	}
	}
	else
	{
		if(len)
		{
		cout<<str<<" ";
		cout<<endl;
		}
	}
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
		//	cout<<char(96+i);
			
			
			if(check(96+i))
			{
				str[length]=char(96+i);
				length++;
				mini(n-1,pos+1,96+i,1,str);
			//	str[strlen(str)]='\0';
			}
			else
			{
				str[length]=char(96+i);
				length++;
				mini(n-1,pos+1,96+i,0,str);	
						//str[strlen(str)]='\0';
			}
		    }
		}
		else 
		{
			
				if(check(prev))
				{
					if(!check(96+i)&&char(96+i)!='y')
					{
						//cout<<char(96+i);	
						str[length]=char(96+i);
						
						length++;
						mini(n-1,pos+1,96+i,first,str);
						length--;
							//str[strlen(str)]='\0';
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
						//str[strlen(str)]='\0';
					}
					else continue;
				}
		}
	}
//	length--;
	//if(length<0)
	// length=0;
}
else
{
	if(length)
	{
	for(i=0;i<length;i++)
	{
	cout<<str[i];
     }
	//cout<<str<<endl;
	//length=0;
	cout<<endl;
	}
}

}
int main()
{
	int n,t;
	for(int u=0;u<3;u++) che[u]=true;
	cin>>n;n1=n;
	char str[7];
	
	for(int i=0;i<7;i++)
	{
		str[i]='\0';
	}
	strcpy(str,"abc");
///	cout<<(char)97+1;
//	cout<<"  "<<char(97+1);
	//mini(n,0,0,0,str);
	print1(str,0,n);
	
}

