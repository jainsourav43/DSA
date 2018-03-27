#include <bits/stdc++.h>
#include<map>
#include<set>
int v[1];
using namespace std;
map<string,int> m;
map<string,set<int> > p;
using namespace std;

int main() {
    int q;
    cin >> q;
    // Process each command
    for(int a0 = 0; a0 < q; a0++){
        // Read the first string denoting the command type
        string command,s1,s2;
        cin >> command;
        if(command=="rnm")
        {
        	set<int> se;
        //	se.set(m[s1].begin(),m[s1].end());
        	se= m[s1];
            cin>>s1>>s2;
           int t1= --m[s1];
          // p[s1]
           int t2=++m[s2];
                if(t1==1)
                {
                    if(t2==1)
                    cout<<"r "<<s1<<" -> "<<s2<<endl;
                    else
                     cout<<"r "<<s1<<" -> "<<s2<<"("<<t2-1<<")"<<endl;    
                     
                }
                else
                {
                    if(t2==1)
                         cout<<"r "<<s1<<"("<<t1<<")"<<" -> " <<s2<<endl;
                    else
                 cout<<"r "<<s1<<" -> " <<s2<<"("<<t2-1<<")"<<endl;
                }
            
        }
        else
        {
            
            cin>>s1;
            if(command=="del")
            {
                string temp=s1;
                int len=s1.length();
                if(s1.at(len-1)==')')
                {
                    temp=s1.substr(0,len-3);
                }
                cout<<temp<<endl;
                m[temp]--;
                int t=m[temp];
               cout<<"- "<<s1<<endl;
            }
            else
            {
                m[s1]++;
                int t=m[s1];
                if(t==1)
                {
                    cout<<"+ "<<s1<<endl;
                }
                else
                {
                 cout<<"+ "<<s1<<"("<<t-1<<")"<<endl;   
                }
            }
        }
        // Write additional code to read the command's file name(s) and process the command
        // Print the output string appropriate to the command
    }
    return 0;
}

