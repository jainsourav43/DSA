/*You are required to complete this method */
#include<bits/stdc++.h>
using namespace std;
map <double,int > slope;
int maxPoints(int x[], int y[],int n) {
    
    slope.clear();
    int i,j,fmax=1;
    for(i=0;i<n;i++)
    {
        slope.clear();
        for(j=0;j<n;j++)
        {
            if(i==j)
            continue;
            double s;
            if(x[j]-x[i]!=0)
            {
            s=(double)(y[j]-y[i])/(double)(x[j]-x[i]);
             cout<<s<<" ";
            if(slope.find(s)==slope.end())
            slope[s]=1;
            else
            slope[s]++;
            }
            else
            if(slope.find(INT_MAX)==slope.end())
            slope[INT_MAX]=1;
            else
            slope[INT_MAX]++;
           
        }
    map<double,int>:: iterator it=slope.begin();
    int max1=0;
    for(; it!=slope.end();it++)
    {
       // cout<<it->second<<" ";
        if(max1<it->second+1)
        {
            max1=it->second+1;
        }
    }
     cout<<endl;
    if(max1>fmax)
    fmax=max1;
    }
    //int max1=*max_element(slope.begin(),slope.end());
  
    // if(max1>n)
    // return n;
    // else
    return fmax;
    
    
     //Your code here
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int x[n],y[n];
		int i;
		for(i=0;i<n;i++)
		cin>>x[i];
		for(i=0;i<n;i++)
		cin>>y[i];
		
		cout<<maxPoints(x,y,n);
	}
}
