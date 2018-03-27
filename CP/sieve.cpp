#include<iostream>
using namespace std;
#include<vector>
    vector <int> b;

void sieve(int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    cout<<"ENter\n";
    bool a[n+1],i=1;
   while(i<=n)
    {cout<<"I,n = "<<i<<" "<<n<<endl;
        a[i]=false;
        i++;
    }
    int p=2,check=0,j;
        while(check==0)
        {
        	cout<<"in\n";
            for(j=2;j*p<=n;j++)
            {        	cout<<"in2\n";

              a[p*j]=true;  
            }
            check=1;
            for(i=p+1;i<=n;i++)
            {        	cout<<"in3\n";

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
	sieve(n);
	for(int i=0;i<b.size();i++)
	{
		cout<<b[i]<<endl;
	}
}
