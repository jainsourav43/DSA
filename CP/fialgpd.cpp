#include<iostream>
using namespace std;
#define ll long long 
#include<bits/stdc++.h>
#include<map>
#include<limits.h>
 
//graph Graph[10002];
//ll g[5001][5001];
ll n,q,r,uk,min1,max1,in;
void dfs(ll v,ll u,ll k,map< ll ,ll > &M,map< ll ,ll > &P,map< ll ,ll > &ma,map< ll ,ll > &mi,map< ll ,bool > &che)
{
	ll t1;
	ll i;
//	cout<<"in dfs\n";
cout<<"v = "<<v<<endl;
	if(u!=-1)
	{	
//	cout<<"che[v] = "<<che[v]<<endl;
	if(che[v]==true)
	{
	if(ma[v]>max1)
	{
		max1=ma[v];
	}
	if(mi[v]<min1)
	{
		min1=mi[v];
	}
	//cout<<"gajab\n";
	u=-1;
	}
	else
	{	
	ll temp1,temp2;
	if(v!=r)
	{
	temp1=P[v]^k;
	}	
	else
	temp1=uk^k;
	
	if(v==r)
	{
		u=-1;
	}
	if(temp1>max1)
	{
		max1=temp1;
		
	}
	if(min1>temp1)
	{
		min1=temp1;
	}
	if(u!=-1)
	{
	//cout<<"t1 = "<<t1<<endl;
	//	cout<<"M[v] = "<<M[v]<<endl;
	dfs(M[v],u,k,M,P,ma,mi,che);
	}
	}
}
}
 
 
int main()
{
	
	cin>>n>>q;
	map< ll ,ll > P; 
	map< ll,ll > M;
	map<ll,ll>ma;
	map<ll,ll>mi;
	map<ll,bool> che;
	cin>>r>>uk;
	ll i;
	//	map<string,string,ll>;
	//	P.first["ram"]=1;
		ll tempu,tempv,tempk;
		che[r]=false;
	for(i=0;i<n-1;i++)
	{
		cin>>tempu>>tempv>>tempk;
	//	g[tempv][tempu]=tempk;
	
	
		//itoa(tempu,ch,10);
	//	itoa(tempv,ch1,10);
		//ch[strlen(ch)]='\0';
	//	cout<<"ch,ch1 = "<<ch<<" "<<ch1<<endl;
		P[tempu]=tempk;
		M[tempu]=tempv;
		che[tempu]=false;
		//che[tempv]=false;
	//	cout<<"M[ch] = "<<M[ch]<<" \n";//<<"M[ch1] = "<<M[ch1]<<"\n";
		//P.first[ch]=tempk;
		//P.second=tempv;
	}
	 in=n-1;
	ll la=0;
	ll t;
	ll u,v,k;
	for(i=0;i<q;i++)
	{
		cin>>t;
		t=t^la;
		if(t==0)
		{
			cin>>v>>u>>k;
			v=v^la;
			u=u^la;
			k=k^la;
			che[u]=false;
			//che[v]=false;
			M[u]=v;
			P[u]=k;
		//P.first[ch]=k;
		//P.second=v;
		}
		else
		{
			cin>>v;
			cin>>k;
			v=v^la;
			k=k^la;
			//cout<<"av  = "<<v<<endl;
			min1=INT_MAX;
			max1=INT_MIN;
			dfs(v,1,k,M,P,ma,mi,che);
			ma[v]=max1;
			mi[v]=min1;
			che[v]=true;
			cout<<min1<<" "<<max1<<endl;
			la=max1^min1;
		}
	}
	
	
	return 0;
} 
