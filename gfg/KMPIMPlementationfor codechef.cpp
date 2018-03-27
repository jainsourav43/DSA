#include<iostream>
#include<bits/stdc++.h>
#define ll long long
ll lps[300001],index[300001],count1=0,count2=0;
char s[300001],f[300001]; ll index2[300001],sum[300001];bool v[300001];
void calclps(char f[],ll m)
{
	int len=0;
	int i=1;
	lps[0]=0;
	while(i<m)
	{
		if(f[i]==f[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}

}
void kmp(char s[],char f[],int n,int m)
{
	calclps(f,m);
	int i=0,j=0;
	while(i<n)
	{
		if(s[i]==f[j])
		{
			i++;
			j++;
			
		}
		if(j==m)
		{
			index[count1++]=i-j;
			j=lps[j-1];
		}
		if(i<n&&s[i]!=f[j])
		{
			if(j!=0)
			j=lps[j-1];
			else
			i=i+1;
		}
		
	}
	
	
}

using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		count1=0,count2=0;
		cin>>s>>f;
		ll n,m;
		n=strlen(s);
		m=strlen(f);
		kmp(s,f,n,m);
		for(int i=0;i<count1;i++)
		{
			cout<<index[i]<<" ";
		}
		cout<<endl;
		int j=0,i=0;
		for(i=0;i<count1;i++)
		v[index[i]]=true;
		for(i=1;i<count1;i++)
		{
			
			if(index[i]-index[j]>=m)
			{
			//	index2[count2++]=index[i];
			count2++;
				j=index[i-1];
			}
		}
			cout<<count2<<endl;
			int ans=0;
			for(i=0;i<n;i++)
			{
				ans=ans+count1;
			}
			
			ll ma=*max_element(index,index+count1);
			sum[ma]=1;
			for(i=ma-1;i>=0;i--)
			{
				if(v[i])
				{
					sum[i]=sum[i+1]+1;
				}	
				else
				{
					sum[i]=sum[i+1];
				}
			}
			for(i=0;i<=ma;i++) cout<<sum[i]<<" ";cout<<endl;
	}
	
}
