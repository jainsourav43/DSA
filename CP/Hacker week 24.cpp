#include<iostream>
using namespace std;


int main(){
    int s;
    int t;
    cin >> s >> t;
    int a;
    int b;
    cin >> a >> b;
    int m;
    int n;
    cin >> m >> n;
    int ap[m],ora[n],i,j,k,count1=0,count2=0; 
     for( i=0;i<m;i++)
        {
        cin>>ap[i];
        
        j=ap[i]+s;
        if(j>=s&&j<=t)
            {
            count1++;
        }
    }
    for(i=0;i<n;i++)
        {
        cin>>ora[i];
        j=t+ora[i];
        if(j>=s&&j<=t)
            count2++;
    }
    cout<<count1<<endl;
    cout<<count2<<endl;
    //for()
    return 0;
}

