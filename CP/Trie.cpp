const int MaxN = 10000;
int sz = 0;

vector<int> next1[27];
vector<int> end1;
vector <bool> created;

void insert (string &s) {
	int v = 0;

	for (int i = 0; i < s.size(); ++i) {
		int c = s[i] - 'a';
		if (!created[next1[c][v]]) {
			next1[c][v] = ++sz;
			created[sz] = true;
		}
		v = next1[c][v];
	}
	++end1[v];
}

bool search (string tmp) {
	int v = 0;
	
	for (int i = 0; i < tmp.size(); ++i) {
		int c = tmp[i] - 'a';
		if (!created[next1[c][v]])
			return false;
		v = next1[c][v];
	}
	return end1[v] > 0;
}

// int main () {
// 	string keys[] = {"hi", "hello", "you", "ekta", "me"};
// 	string output[] = {"NO", "YES"};

// 	for (int i = 0; i < 5; ++i)
// 		insert (keys[i]);

// 	cout << output[search ("my")] << endl;
// 	cout << output[search ("me")] << endl;
	
// 	return 0;
// }
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    if(a.second==b.second)
    return a.first<b.first;
    return (a.second > b.second);
}
vector<int> Solution::solve(string s, vector<string> &s1)
{
        int len=s.size();
        sz=0;
        int i,j,k;
        int len1;
        for(i=0;i<27;i++)
        {
            next1[i].assign(MaxN,0);
        }
        end1.assign(MaxN,0);
        created.assign(MaxN,0);
        string tmp="";
        string temp;
        for(i=0;i<len;i++)
        {
            if(s[i]!='_')
            {
                tmp=tmp+s[i];
            }
            else
            {
                insert(tmp);   
                tmp="";
            }
        }
        insert(tmp);
        int n=s1.size();
        vector<int> count1(n+1,0);
        vector<pair<int,int> >ans(n,make_pair(0,0));
        for(i=0;i<n;i++)
        {
            len1=s1[i].length();
            tmp="";
            for(j=0;j<len1;j++)
            {
                if(s1[i][j]!='_')
                {
                    tmp=tmp+s1[i][j];
                }
                else
                {
                 //   cout<<"tmp= "<<tmp<<endl;
                    if(search(tmp))
                    {
                   //     cout<<"success\n";
                        count1[i]++;
                        
                    }
                    tmp="";
                }
                
            }// cout<<"tmp= "<<tmp<<endl;
                if(search(tmp))
                {
                //    cout<<"success\n";
                    count1[i]++;
                    
                }
    //        cout<<"count["<<i<<"]= "<<count1[i]<<endl;
            ans[i]=make_pair(i,count1[i]);
        }
    vector<pair<int,int> > :: iterator it=ans.begin();
    //cout<<"n,size= "<<n<<"  "<<s1.size()<<endl;
        // for(i=0;i<n;i++)
        // {
        //     cout<<it->first<<" "<<it->second<<endl;
        //     it++;
        // }
       sort(ans.begin(),ans.end(),sortbysec);
       it=ans.begin();
        // for(i=0;i<n;i++)
        // {
        //     cout<<it->first<<" "<<it->second<<endl;
        //     it++;
        // }
        vector<int> fans(n,0);
     //   vector<pair<int,int> > :: iterator it;
        it=ans.begin();
        i=0;
        for(; it!=ans.end();it++)
        {
            fans[i]=it->first;
            i++;
        }
      //  reverse(fans.begin(),fans.end());
        return fans;
    
    
    
    
}

