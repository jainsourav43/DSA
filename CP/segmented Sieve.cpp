#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<string.h>
#include<stdio.h>
using namespace std;

int fact(int c,int n)
{
    int p=1;
    for(int i=2;i<=n;i++)
    p=p*i;
    return c*p;
}

int findRank(string s) {
    string s1=s;int count=0;
    sort(s1.begin(),s1.end());
    int n=s1.size();
    cout<<s1<<endl;cout<<s<<endl;
    int ans=0,i,j;
    for(i=0;i<s.size();i++)
    {
        count=0;
        for(j=i;j<s1.size();j++)
        {
        	cout<<"s,s1 = "<<s.at(i)<<" "<<s1.at(j)<<endl;
            if(s.at(i)>s1.at(j))
            {
                count++;
            }
        }
        
        cout<<count<<" "<<n-1-i<<endl;
        ans+=fact(count,n-i-1);
    }
    return ans+1;
    
}
//int trailingZeroes(int n) {
//    // Do not write main() function.
//    // Do not read input, instead use the arguments to the function.
//    // Do not print the output, instead return values as specified
//    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
//    int i,sum=0,j=n,k=1;
//    for(i=1;k>0;i++)
//    {
//        int j=pow(5,i);
//		k=n/j;        
//        sum=sum+k;
//    }
//    return sum;
//    next_permutation()
//}
int reverse(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    long long sum=0;
    
    if(A<0)
    {
        A=A*-1;
        while(A)
        {
            sum=sum*10+A%10;
            A/=10;
        }
       // cout<<sum<<endl;
        if(sum>INT_MAX)
        {  
        cout<<sum<<endl;
        cout<<"TRUE\n";
                return 0;
		}

        return sum*(-1);
    }
    else 
    {
        while(A)
        {
            sum=sum*10+A%10;
            A/=10;
        }
        if(sum>INT_MAX)
        return 0;
        return sum;
    }
}
 vector<int> prime;
void simpleSieve(int n)
{
    // Create a boolean array "mark[0..n-1]" and initialize
    // all entries of it as true. A value in mark[p] will
    // finally be false if 'p' is Not a prime, else true.
    
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
    
    // Print all prime numbers and store them in prime
    for (int p=2; p<=n; p++)
    {
        if (a[p] == false)
        {
            prime.push_back(p);
           // cout << p << "  ";
        }
    }
}
vector<int> segmentedSieve(int n)
{
    // Compute all primes smaller than or equal
    // to square root of n using simple sieve
    int limit = floor(sqrt(n))+1;
    
    simpleSieve(limit); 
 
    // Divide the range [0..n-1] in different segments
    // We have chosen segment size as sqrt(n).
    int low  = limit;
    int high = 2*limit;
 
    // While all segments of range [0..n-1] are not processed,
    // process one segment at a time
    while (low < n)
    {
        // To mark primes in current range. A value in mark[i]
        // will finally be false if 'i-low' is Not a prime,
        // else true.
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
 
        // Use the found primes by simpleSieve() to find
        // primes in current range
        for (int i = 0; i < prime.size(); i++)
        {
            // Find the minimum number in [low..high] that is
            // a multiple of prime[i] (divisible by prime[i])
            // For example, if low is 31 and prime[i] is 3,
            // we start with 33.
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
 
            /*  Mark multiples of prime[i] in [low..high]:
                We are marking j - low for j, i.e. each number
                in range [low, high] is mapped to [0, high-low]
                so if range is [50, 100]  marking 50 corresponds
                to marking 0, marking 51 corresponds to 1 and
                so on. In this way we need to allocate space only
                for range  */
            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
 
        // Numbers which are not marked as false are prime
        for (int i = low; i<high; i++)
            if (mark[i - low] == true)
                prime.push_back(i);
 
        // Update low and high for next segment
        low  = low + limit;
        high = high + limit;
        if (high >= n) high = n;
    }
    return prime;
}
vector<int>primesum(int n) {
    
        // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    //cout<<"ENter\n";
    //bool a[n+1];
    int i=1;
    vector<int> b,c;
        b=segmentedSieve(n);
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
int main()
{
	string s;
	cin>>s;
	
//	int n;
//	cin>>n;
//	//sieve(n);
//	vector<int>d;
//	//d=primesum(n);
int s1=findRank(s);
	cout<<s1<<endl;
//	for(int i=0;i<d.size();i++)
//	{
//		cout<<d[i]<<endl;
//	
//	}
	}

