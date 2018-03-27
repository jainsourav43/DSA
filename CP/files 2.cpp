#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct person{
	char lastname[20];
	char firstname[20];
	char address[20];
};
istream &operator>>(istream &stream,person &p)
{
	stream.getline(p.firstname,20);
	stream.getline(p.lastname,20);
	stream.getline(p.address,20);
	return stream;
}
ostream &operator<<(ostream &stream,person &p)
{
	stream<<p.lastname<<p.firstname<<p.address;
	return stream;
}
int main()
{
	char filename[20];
	person p;
	cout<<"enter the filename:"<<flush;
	cin.getline(filename,19);
	ofstream stream;
	stream.open(filename,ios::out);
	if(stream.fail())
	{
		cout<<"File opened failed\n";
		return 0;
	}
	while(1)
	{
		cin>>p;
		if(strlen(p.firstname==0))break;
		stream<<p;
	}
	
}
