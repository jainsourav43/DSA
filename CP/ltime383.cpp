#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define FOR(i,n) for(i=0;i<n;i++)
 
using namespace std;
 
int main() {
    int t;
    scanf("%d",&t);
    
    while(t) {
        vector<int> v;
        int n;
        long long int p,q;
        scanf("%d%lld%lld",&n,&p,&q);
        int i,j;
        for(i=0;i<n;i++) {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }
        int count=0;
        sort(v.begin(),v.end());
        if(p==0) {
            
            for(i=0;i<n;i++) {
            if(v[i]%2==0) {
            int x=v[i]/2;
            if(x<=q) {
                q-=x;
                v[i]-=(2*x);
                if(v[i]==0) count++;
            }
            else {
                v[i]-=(2*q);
                q=0;
            }
            }
        }
        }
        else {
        
        for(i=0;i<n;i++) {
      //      printf("%d and %d\n",p,q);
            if(p!=0) {
                int x=v[i]/2;
                if(q>=x) {
                    q-=x;
                    v[i]-=(2*x);
                    if(v[i]!=0 && p>=v[i] && p!=0) {
                        v[i]-=1;
                        p-=1;
                        int y=v[i]/2;
                        if(q>=y && v[i]!=1) {
                            q-=y;
                            v[i]=0;
                        }
                        else {
                            p-=v[i];
                            v[i]=0;
                        }
                    }
                    else if(p!=0&&p<v[i]&&v[i]!=0){
                        v[i]-=1;
                        p-=1;
                        int y=v[i]/2;
                        if(q>=y && v[i]!=1) {
                            q-=y;
                            v[i]=0;
                        }
                    }
                }
            
                else {
                    
                    v[i]-=(2*q);
                    q=0;
                    if(v[i]!=0 && p>=v[i] && p!=0) {
                        v[i]-=1;
                        p-=1;
                        int y=v[i]/2;
                        if(q>=y && v[i]!=1) {
                            q-=y;
                            v[i]=0;
                        }
                        else {
                            p-=v[i];
                            v[i]=0;
                        }
                    }
                    else if(p!=0&&p<v[i]&&v[i]!=0){
                        v[i]-=1;
                        p-=1;
                        int y=v[i]/2;
                        if(q>=y && v[i]!=1) {
                            q-=y;
                            v[i]=0;
                        }
                    }
                    
                }
                
            }   
            else {
                
                if(v[i]%2==0) {
                    if(q>=v[i]/2) {
                        q-=(v[i]/2);
                        v[i]=0;
                    }
                }
                
            }
        //    printf("%d and %lld and %lld\n",v[i],p,q);
            if(v[i]==0) count++;
        }
        }
        printf("%d\n",count);
        t--;
    }
}
