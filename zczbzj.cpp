#include <bits/stdc++.h>
#include<map>
using namespace std;
map<string,int> m;
map<string,map<int,bool> >v;
using namespace std;

int main() {
    int q;
    cin >> q;
    // Process each command
    for(int a0 = 0; a0 < q; a0++)
    {
        // Read the first string denoting the command type
        string command,s1,s2;
        cin >> command;
        if(command=="rnm")
        {
            cin>>s1>>s2;
          
             int mai=0,i,len=s1.length();
            string temp;
            if(s1.at(len-1)==')')
            {
                  int num=0;
                temp=s1.substr(0,len-3);
                int j=len-2;
                while(s1.at(j)!='(')
                {
                    j--;
                }
                j++;
                while(s1.at(j)!=')')
                {
                    num=num*10+(s1.at(j)-'0');
                }
                
                
                mai=num;
            }
           int t1= m[temp]--;
           int t2=m[s2]++;
            v[s1][mai]=false;
            //cout<<v[s2][0]<<endl;
           // cout<<"count= "<<t2<<endl;
             for(i=0;i<=t2;i++)
            {
                if(v[s2][i]==false)
                    break;
            }
            //cout<<"i= "<<i<<endl;
        //    cout<<
            v[s2][i]=true;
             
            
          
            if(t1==1)
            {



                if(i==0)
                    cout<<"r "<<s1<<" -> "<<s2<<endl;
                else
                    cout<<"r "<<s1<<" -> "<<s2<<"("<<i<<")"<<endl;    

            }
            else
            {

                if(i==0)
                    cout<<"r "<<s1<<" -> " <<s2<<endl;
                else
                    cout<<"r "<<s1<<" -> " <<s2<<"("<<i<<")"<<endl;
            }
            
        }
        else
        {
            
            cin>>s1;
            if(command=="del")
            {
                string temp=s1;
                int len=s1.length();
                int mai=0;
                if(s1.at(len-1)==')')
                {
                    int num=0;
                    temp=s1.substr(0,len-3);
                    int j=len-2;
                    while(s1.at(j)!='(')
                    {
                   cout<< s1.at(j)<<endl;	
                        j--;
                    }
                    j++;
                    while(s1.at(j)!=')')
                    {
                        num=num*10+(s1.at(j)-'0');
                    }


                    mai=num;
                }
               // cout<<"- "<<temp<<endl;
                int t= m[temp];
                                
                v[temp][mai]=false;
                m[temp]--;
             //   int t=m[temp];
               cout<<"- "<<s1<<endl;
            }
            else
            {
                
                m[s1]++;
                int t=m[s1],i;
                
                    for(i=0;i<t;i++)
                    {
                        if(v[s1][i]==false)
                         break;
                    }
                    if(i==0)
                    cout<<"+ "<<s1<<endl;
                    else
                     cout<<"+ "<<s1<<"("<<i<<")"<<endl;  
                    v[s1][i]=true;
            }
        }
        // Write additional code to read the command's file name(s) and process the command
        // Print the output string appropriate to the command
    }
    return 0;
}

