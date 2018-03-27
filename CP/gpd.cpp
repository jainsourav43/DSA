#include<iostream>
using namespace std;
#define ll long long 
#include<bits/stdc++.h>
#include<map>
#include<limits.h>
//vector< vector< int > > graph(5001, vector<int>(5001,0));

pair< map<char*,int> ,int > P; 
map<char*,char*>M;
struct graph
{
	int u,key,visited,v;
};

graph Graph[10002];
//int g[5001][5001];
int n,q,r,uk,min1,max1,in;
void dfs(int v,int u,int k)
{
	int t1;
	int i;
	cout<<"in dfs\n";
	if(u!=-1)
	{
	int temp1,temp2;
	if(v!=1)
	{
//	for( i=0;i<in;i++)
//	{
//		if(Graph[i].u==v)
//		{
//			temp2=Graph[i].key;
//			break;
//		}
//	}
	char temp3[20],temp4[20];
	itoa(v,temp3,10);
	cout<<"temp3= "<<temp3<<endl;
	cout<<"m[temp3] = "<<M[temp3]<<endl;
	strcpy(temp4,M[temp3]);
	cout<<"temp4 = "<<temp4<<endl;
//for(int j=0;j<strlen(M[temp3]);j++)
//{
//	temp4[j]=M[temp3][j];
//}
	t1=atoi(temp4);
	cout<<"t1 ="<<t1<<endl;
	temp2=P.first[temp3];
	cout<<"in == "<<in<<endl;
	temp1=temp2^k;
	}	
	else
	temp1=uk^k;
	
	if(v==1)
	{
		u=-1;
	}
	cout<<"temp   = "<<temp1<<" \n";
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
		cout<<"t1 = "<<t1<<endl;
	dfs(t1,u,k);
	}
	}
}


int main()
{
	cin>>n>>q;
	cin>>r>>uk;
	int i;
//	map<string,string,int>;
	//	P.first["ram"]=1;
		int tempu,tempv,tempk;
		char ch[20],ch1[20],ch2[20];
	for(i=0;i<n-1;i++)
	{
		cin>>tempu>>tempv>>tempk;
	//	g[tempv][tempu]=tempk;
	
	
		Graph[i].key=tempk;
		Graph[i].u=tempu;
		Graph[i].v=tempv;
		itoa(tempu,ch,10);
		itoa(tempv,ch1,10);
		cout<<"ch,ch1 = "<<ch<<" "<<ch1<<endl;
		
		M[ch]=ch1;
		cout<<"M[ch] = "<<M[ch]<<" \n";
		P.first[ch]=tempk;
		P.second=tempv;
	}
	 in=n-1;
	int la=0;
	int t;
	int u,v,k;
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
		Graph[in].key=k;
		Graph[in].u=u;
		Graph[in].v=v;
		in++;
		itoa(u,ch,10);
		itoa(v,ch1,10);
		M[ch]=ch1;
		P.first[ch]=k;
		P.second=v;
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
			dfs(v,1,k);
			cout<<min1<<" "<<max1<<endl;
			la=max1^min1;
		}
	}
	
	
}
