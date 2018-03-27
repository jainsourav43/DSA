#include<iostream>
using namespace std;
#include<algorithm>
#include<string.h>
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int check=0,i,j,k;
		int index;
		char maxmin;
		char w[101];
		cin>>w;
		int length=strlen(w);
		for(i=length-2;i>=0;i--)
		{
			for(j=i+1;j<length;j++)
			{
				if(w[j]>w[i])
				{
					maxmin=w[j];
					index =j;
					int check2=0;
					//cout<<"w 0  ="<<w<<endl;
					for(k=i+1;k<length;k++)
					{
						if(maxmin>w[k]&&w[i]<w[k])
						{
							maxmin=w[k];
							index =k;
							check2=1;
						}
					}
					//cout<<"check2 = "<<check2<<endl;
					//	cout<<"w 01  ="<<w<<endl;
//						cout<<"minmax=  "<<maxmin<<endl;
//						cout<<"w[k] = "<<w[k]<<endl;
//						cout<<"w[i]= "<<w[i]<<endl;
//						cout<<"w[j]= "<<w[j]<<endl;	
					if(check2)
					swap(w[i],w[index]);
					else
					swap(w[i],w[j]);
					check=1;
						cout<<"w 02  ="<<w<<endl;
					//cout
					sort(w+i+1,w+length-1);
					cout<<"w 3 = "<<w<<endl;
					if(check==1)
					break;
				}
			}
			if(check)
			break;
		}
		if(check)
		cout<<w<<endl;
		else
		cout<<"no answer\n";
	}
}
