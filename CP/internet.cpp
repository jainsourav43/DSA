#include<iostream>
#include<string.h>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		ll l=0,m=0,suma[n],sumb[n]={0},tempa=0,o=0,p=0,fans=0,tgf,countb=0,counta=0;
		int ans=1,check=1,a[n],b[n];
		int sum[n];suma[0]=0;
		char str[n+1];
		int checkb=0;
		cin>>str;
		ll len=strlen(str),i;
		int before=0;int pcheck=0;
		for(i=0;i<len;i++)
		{
			if(str[i]=='a')
			{
				a[l++]=i;
				
				suma[o]++;
				
				counta++;
				
				tempa++;
				check=0;
				pcheck=1;
				if(checkb)
				{
				p++;
				sumb[p]=0;
				}
				
			}
			else if(str[i]=='b')
			{
				if(check==1)
				before++;
				countb++;
				checkb=1;
				//check=1;
				tempa=0;
				b[m++]=i;
				sumb[p]++;
				if(check==0&&pcheck==1)
				{
				o++;
				suma[o]=0;
				}
								pcheck=0;

				//ans=ans*suma;
			}
		}
		
		if(pcheck==0) o--; 
	//	cout<<"countb =  "<<countb<<endl;
	//	cout<<"before = "<<before<<endl;
		ll tgh=(countb*k*(k-1))/2;
	//	cout<<"tgh = "<<tgh<<endl;		
	//	for(i=0;i<=o;i++) cout<<"suma[i],sumb[i] = "<<suma[i]<<" "<<sumb[i]; cout<<endl;
		int tempcountb=countb;int  tempk=k;int k1=0;
	//	cout<<"o ,p "<<o<<" "<<p<<endl;
		if(before) k1=1;
			for(i=0;i<=o;i++)
			{
			if(i==0)
			fans=fans+suma[i]*((tempcountb-before)*k+tgh);
			else
			{
				fans=fans+suma[i]*((tempcountb-before)*k+tgh);
			}
			tempcountb-=sumb[k1++];
			}		
		
		cout<<fans<<endl;
		
	}
		
}
