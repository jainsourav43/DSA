#include<bits/stdc++.h>
#include<iostream>
//#include"files 2.cpp"
using namespace std;
struct person{
	char lastname[20];
	char firstname[20];
	char address[20];
};
istream &operator >>(istream &stream ,person &p)
{
	char delim;
	stream.getline(p.firstname,19,'|');
	if(strlen(p.firstname)==0)
	{
	return stream;
    }   
	stream.getline(p.lastname,20,'|');
	stream.getline(p.address,20,'|');
	return stream;
}
int main()
{
	char filename[20];
	person p;
	cout<<"Enter the filename\n";
	cin>>filename;
	ifstream stream;
	stream.open(filename,ios::in);
	while(1)
	{
		stream>>p;
		if(strlen(p.firstname)==0)break;
		cout<<p.firstname<<endl;
		cout<<p.lastname<<endl;
		cout<<p.address<<endl;
	//	cout<<p;
	}
}
