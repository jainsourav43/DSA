#include<iostream>
#define ll long long
#include<algorithm>
using namespace std;
bool v[100000][4][4];
int main()
{
	ll t ;
	cin>>t;
	while(t--)
	{
	ll n,m;
	cin>>n>>m;
	char b[4],a[n][4][4];
	ll i,j,k;
	ll q[m],l[m],r[m],pos[m];
	for(i=0;i<n;i++)
	{
	
			for(k=0;k<4;k++)
			{
				cin>>a[i][k];
			}
	//	}
	//	cin>>b;
	}
	int count[n]={0};
		for(i=0;i<n;i++)
        count[i]=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				if(a[i][j][k]=='1'&&!v[i][j][k])
				{
				  if(((j-1)>=0&&!v[i][j-1][k])||(j-1<0))
				  {
				  	if(((k-1)>=0&&!v[i][j][k-1])||k-1<0)
				  	{
				  		if((((j+1)<=3)&&!v[i][j+1][k])||j+1>3)
				  		{
					  		if((((k+1)<=3)&&!v[i][j][k+1])||k+1>3)
					  		{
					  			count[i]++;
							}
						}
					}
				  }
		     	}
				  bool aage=false,niche=false,upar=false,piche=false;
					if(a[i][j][k]=='1')
					{
						if((k+1)<=3&&a[i][j][k+1]=='1'&&v[i][j][k+1]==false)
						{
							//v[i][j][k+1]=true;
							aage =true;
						}
						if((j+1)<=3&&a[i][j+1][k]=='1'&&v[i][j+1][k]==false)
						{
							//v[i][j+1][k]=true;
							niche=true;
						}
						if((k-1)>=0&&a[i][j][k-1]=='1'&&v[i][j][k-1]==false)
						{
							//v[i][j][k-1]=true;
							piche=true;
						}
						if((j-1)>=0&&a[i][j-1][k]=='1'&&v[i][j-1][k]==false)
						{
							//v[i][j-1][k]=true;
							upar=true;
						}
						if(aage&&niche)
						{
								if((j+1)<=3&&a[i][j+1][k+1]=='1'&&v[i][j+1][k+1]==false)
								{
								v[i][j][k]=true;	v[i][j+1][k]=true;v[i][j][k+1]=true;v[i][j+1][k+1]=true;
								}
								else
								{
									v[i][j][k]=true;	v[i][j+1][k]=true;v[i][j][k+1]=true;
								}
						}
						
						
					}
			//	}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<"Count  for  "<<" i= "<<i<< " "<<count[i]<<"   ";
	}
	j=0;k=0;
	int u,v,w;
	for(i=0;i<m;i++)
	{
		cin>>q[i];
		if(q[i]==1)
		{
		cin>>l[j]>>r[j];	
		j++;	
		}
		else
		{
			cin>>pos[k];
			//for(int h=0;h<4;h++)
			//{
				for(int h1=0;h1<4;h1++)
				{
					cin>>a[pos[k]][h1];
				}
			
			k++;
		}
	}
}
}
