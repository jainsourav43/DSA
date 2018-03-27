#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char ch,filename[20];
	fstream file;
	cout<<"Enter the file name\n"<<flush;
	cin>>filename;
	file.open(filename,ios::in);
	file.unsetf(ios::skipws);
	while(1)
	{
		file>>ch;
		if(file.fail())
		{
			break;
		}
		cout<<ch;
		
	}
	file.close();
}
