#include<iostream>
using namespace std;
int dow(int y, int m, int d)
{
   static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
   y -= m < 3;
   cout<<(m<3)<<endl;
   return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
int main()
{
	int y=2012,m=2,d=1;
	cin>>y>>m>>d;
	cout<<dow(y,m,d)<<endl;
	
}
