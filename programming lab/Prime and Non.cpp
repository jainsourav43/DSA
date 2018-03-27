#include<bits/stdc++.h>
using namespace std;
class prime
{
	bool Check_Prime(int p)
	{
		int i=0;
		for(i=2;i<=sqrt(p);i++)
		{
			if(p%i==0)
			{
				return false;
			}
			else 
			{
				continue;
			}
		}
		return true;
	}
	public :void Seprate();
};
void prime ::Seprate()
{
	ofstream fout1,fout2;
	ifstream fin;
	int n;
	fout1.open("Prime.txt");
	fout2.open("NonPrime.txt");
	fin.open("Natural.txt");
	while(!fin.eof())
	{
		fin>>n;
		if(Check_Prime(n))
		{
			fout1<<n<<" ";
		}
		else
		{
			fout2<<n<<" ";
		}
	}
}
int main()
{
	prime obj1;
	obj1.Seprate();
	return 0;
}
