#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
    	int  in,s1,s2,k,m;
    	long long n;
		cin>>in>>s1>>s2>>k>>n;
		 long long i,j,*tax;
		tax=new long long[102];
		int h=101;
		tax[0]=in;
		int check=0;
		for(i=1;i<n;i++)
		{  if(i<=s1)
			{
			tax[i%h]=((tax[(i-1)%h])%(100000007)+1)%(100000007);
			//g++;
		}
			 if (i>s1&&i<=s1+s2)
			{
			tax[i%h]=(2*(tax[(i-1)%h])%(100000007))%(100000007);
		//	g++;
			}
			if(i>s1+s2)
			{
			    m=k;//tax[i%h]=1;
				//for(j=1;j<=k;j++)
				////{
				if(check)
					tax[i%h]=(((tax[(i-1)%h])%(100000007))*((tax[(i-1)%h])%(100000007))/tax[(i-m-1)%h])%(100000007);
					else
					{
						m=k;tax[i%h]=1;
			       	for(j=1;j<=k;j++)
					{
						tax[i%h]=((tax[(i-m)%h])%(100000007)*(tax[i%h])%(100000007))%(100000007);
						m--;
					}
					}
					
				check++;

				//}
			}
			}
			

		cout<<(tax[(n-1)%h])%(100000007)<<endl;
	
			delete[] tax;
	}
	return 0;
} 
