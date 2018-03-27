#include<iostream>
using namespace std;
int main()
{
		int n;
		cin>>n;
		int i,j,o=0,e=0,f,h;
		int a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]==0)
			{
				e++;
			}
			else
			{
				o++;
			}
		}
		f=o/2;
	    h=o%2;
	    cout<<((f+h)/2)+1<<endl;
	    return 0;
	    
}
