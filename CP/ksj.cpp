#include <iostream>
using namespace std;
int main() {
	//code
	
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int a[n],i,j;
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    int p=1,m=-100000,count=0,p1=1;
	    for(i=0;i<n;i++) 
	    if(a[i]<0)
	    count++;
	    if(count%2==0)
	    {
	   for(i=0;i<n;i++)
	   {
	      p=p*a[i];
	      if(m<p)
	      {
	          m=p;
	          
	      }
	      if(p==0)
	      p=1;
	   }
	   cout<<m<<endl;
	    }
	    else
	    {
	    	int check=0;
	        for(i=0;i<n;i++)
	        {
	        	if(check==0)
	            p1=p;
	            p=p*a[i];
	       	cout<<"p,p1 ="<<p<<" "<<p1<<endl;
	            if(m<p)
	            m=p;
	            check=0;
	            if(p<0)
	            {
	            cout<<"checkpoint1 p,p1 ="<<p<<" "<<p1<<endl;
	               if(p1<0)
	               {
				   
	               p=p*p1;
	               p1=1;
	           }
	               else
	               {
	                p1=p;
	                p=1;
	               }
	                  if(m<p)
	                   m=p;
	              cout<<"checkpoint2 p,p1 ="<<p<<" "<<p1<<endl;
	               check=1;
	            }
	            else if(p==0)
	            {
				
	            p=1;
	            check=1;
	            p1=1;
	       		 }
	        
	        }
	        cout<<m<<endl;
	    }
	}
	return 0;
}
