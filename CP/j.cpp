#include<iostream>
using namespace std;
int main()
{
	int q;
	cin>>q;
	char str[1024];
	str[0]='0';
	int len=1,temp;
	for(int i=0;i<10;i++)
	{			 temp=len;

		for(int j=0;j<len;j++)
		{
			if(str[j]=='0')
			str[temp]='1';
			else
			str[temp]='0';
			temp++;
			//cout<<"temp=  "<<temp<<endl;
		}
		len=temp;
		//cout<<"len= "<<len<<endl;
	}
//	cout<<" temp length= "<<temp<<endl;
//	cout<<"length= "<<len<<endl;
//	cout<<str[2]<<endl;
//	for(int i=0;i<1024;i++) cout<<str[i];
	while(q--)
	{
		int x;
		cin>>x;
		cout<<str[x]<<endl;
	}
}
