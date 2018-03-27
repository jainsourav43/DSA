#include<iostream>
using namespace std;
int check(int a[],int n)
{
    int i=0;
    int count=0,index;
    for(i=1;i<=n;i++)
    {
        if(a[i]==1)
        {
            index=i;
            count++;
        }
    }
   // cout<<"INDex=" <<index<<endl;
 //   cout<<"count= "<<count;
    if(count==1)
    {
        return index;
    }
    else
    return 0;
}
int josephus(int n, int k)
{
    int a[n+1];int i;
    
    for(i=1;i<=n;i++)
    {
        a[i]=1;
    }
    
     i=1;int temp=1;int c=0;
        while(1)
        {
            c=0;
             while(c<k-1)
             {
        
                 if(a[temp]==1)
                 {
                 temp=(temp+1);
                 if(a[temp]==1)
                 c++;
                 }
                 else
                 {
                 	temp++;
                 	if(temp==n+1)
                 temp=1;
				 }
                 if(temp==n+1)
                 temp=1;
                 cout<<"In= "<<temp<<endl;
                // cout<<"C= "<<c<<endl;
                  if(check(a,n))
                  return check(a,n);   
              }
             a[temp]=-1;
             cout<<"temp= "<<temp<<endl;
           //  temp++;
               if(temp==n+1)
                 temp=1;
           //  cout<<"Check= "<<check(a,n)<<endl;
            if(check(a,n))
            return check(a,n);            
        }

    
    
    
    
}
int main()
{
	int n,k;
	cin>>n>>k;
	josephus(n,k);
}
