#include<iostream>
using namespace std;
#include<vector>


vector<int> primesum(int n) {
    
        // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    //cout<<"ENter\n";
   int i=1;
    int p=2,check=0,j;
        vector <int> b;vector <int> c;

    a[1]=true;
    for(i=2;i<=n;i++) a[i]=false;
        while(check==0)
        {
      //  	cout<<"in\n";
            for(j=2;j*p<=n;j++)
            {//        	cout<<"in2\n";

              a[p*j]=true;  
            }
            check=1;
            for(i=p+1;i<=n;i++)
            {  //      	cout<<"in3\n";

                if(a[i]==false)
                {
                    p=i;
                    check=0;
                    break;
                }
            }
            
        }
        for(i=2;i<=n;i++)
        {
            if(a[i]==false)
            {
                b.push_back(i);
            }
        }
        
        int l=0,r=b.size()-1;
        while(l<=r&&l<=b.size()-1&&r>=0)
        {
            if(b[l]+b[r]>n)
            {
                r--;
            }
            else if(b[l]+b[r]<n)
            {
                l++;
            }
            else
            {
                c.push_back(b[l]);
                c.push_back(b[r]);
                break;
            }
        }
        return c;
    }
void sieve(int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    //cout<<"ENter\n";
    bool a[n+1];int i=1;
    int p=2,check=0,j;
    a[1]=true;
    for(i=2;i<=n;i++) a[i]=false;
        while(check==0)
        {
      //  	cout<<"in\n";
            for(j=2;j*p<=n;j++)
            {//        	cout<<"in2\n";

              a[p*j]=true;  
            }
            check=1;
            for(i=p+1;i<=n;i++)
            {  //      	cout<<"in3\n";

                if(a[i]==false)
                {
                    p=i;
                    check=0;
                    break;
                }
            }
            
        }
        for(i=2;i<=n;i++)
        {
            if(a[i]==false)
            {
                b.push_back(i);
            }
        }
        
    
}
int main()
{
	int n;
	cin>>n;
	//sieve(n);
	vector<int>d;
	d=primesum(n);
	for(int i=0;i<d.size();i++)
	{
		cout<<d[i]<<endl;
	}
}
