#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
const int l=10;
const int N=10;

int hash(int k)
{
	return k%N;
}

int insert(ofstream &ofile, ifstream &ifile, int k)
{
	if(k==-1) return -1;
	int hashedKey = hash(k);
	ofile.seekp(hashedKey*(l+2),ios::beg);
	ifile.seekg(hashedKey*(l+2),ios::beg);
	char ch;
	int n=0;
	ifile>>ch;
	while(ch!='*')
	{
		hashedKey++;
		if(hashedKey==10) hashedKey=0;
		ofile.seekp(hashedKey*(l+2),ios::beg);
		ifile.seekg(hashedKey*(l+2),ios::beg);
		n++;
		//cout<<n<<endl;
		if(n>10)
		return -1;
		ifile>>ch;
	}
	
	ofile<<k;
	n=0;
	while(k)
	{
		k/=10;
		n++;
	}
	for(int i=n;i<10;i++)
	{
		ofile<<'*';
	}
	ofile.flush();
	return 1;
}

int main()
{
	ofstream ofile;
	ofile.open("hashFile2.txt");
	ifstream ifile;
	ifile.open("hashFile2.txt");
	for(int i=0;i<10;i++)
	{
		for(int i=0;i<10;i++)
		ofile<<'*';
		ofile<<'\n';
	}
	int key=0;
	while(1)
	{
		cout<<"\nEnter a number that is to be added in the file: ";
		cin>>key;
		key=insert(ofile,ifile,key);
		if(key==-1)
		break;
	}
	ofile.close();
	ifile.close();
//	char ch;
//	ifstream ifile;
//	ifile.open("hashFile2.txt");
//	ifile.seekg(0,ios::beg);
//	while(1)
//	{
//		ifile>>ch;
//		if(ifile.eof())
//		break;
//		cout<<ch;
//	}
//	ifile.close();
	return 0;
}
