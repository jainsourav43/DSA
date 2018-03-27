#include<iostream>
#include<vector>
using namespace std;

//6 1 2 5 -7 2 3
vector<int> maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector< vector<int> > B;
    int i,j=0,l=0;
    cout<<A.size()<<endl;
    for(i=0;i<A.size();i++)
    {
    	cout<<A[i]<<"  ";
        if(A[i]>=0)
        {
        	cout<<"before\n";
            B[j].push_back(A[i]);  	cout<<"after\n";
            //count++;
            l=0;
        }
        else
        {
            j++;
            l=1;
        }
        
    }
    int max1=0,in;
    if(l==1) j--;
    for(i=0;i<=j;i++)
    {
        if(B[i].size()>max1)
        {
            max1=B[i].size();
            in=i;
        }
    }
   cout<<"in = "<<in<<endl;
    return B[in];
}

int main()
{
	vector<int> A,B;
	int n;
	cin>>n;int tmp;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		A.push_back(tmp);
	}
	
	B=maxset(A);
//	for(int i=0;i<B.size();i++) cout<<B[i]<<endl;
	
}
