/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<bits/stdc++.h>
 using namespace std;
 struct TreeNode
 {
 	int val;
 	TreeNode* left;
 	TreeNode* right;
 
 };
 class Solution
 {
 	public: vector<TreeNode*> generateTrees(int );
 };
 vector<TreeNode*> ans;
 typedef TreeNode* tptr;
 tptr root;
 #define null NULL
int size(tptr t)
{
    if(t==null)
    {
        return 0;
    }
    else
    {
        return size(t->left)+size(t->right)+1;
    }
}
bool check(tptr t,int i)
{
    if(t==null)
    {
        return false;
    }
    if(t->val==i)
    {
        return true;
        
    }
    if(check(t->left,i)||check(t->right,i))
    return true;
    return false;
    
}
void print(tptr t)
{
	if(t==null)
	return ;
	print(t->left);
			cout<<t->val<<" ";
	print(t->right);
}
void print1(tptr t)
{
	if(t==null)
	return ;
	cout<<t->val<<" ";
	print1(t->left);
	print1(t->right);
}
bool good(tptr t,int min,int max)
{
	static TreeNode* k=null;
	if(t)
	{
    	if(t->val<min||t->val>max)
    	return false;
    	return good(t->left,min,t->val-1)&&good(t->right,t->val+1,max);
	}
	
	return true;
}
void generate(tptr &t,int i,int n)
{
	cout<<"Print without \n";
	print1(root);
	cout<<endl;
    if(size(t)==n)
    {
        ans.push_back(t);
        return ;
    }
    
    if(t==null&&root==null)
    {
        root=new TreeNode;
        root->left=null;
        root->right=null;
        root->val=i;
        cout<<"special\n";
        print1(root);
        cout<<endl;
        t=root;
        if(size(root)==n)
        {
        	if(good(root,INT_MIN,INT_MAX))
        	{
            ans.push_back(root);
           	print(root);
           	cout<<endl;
           	print1(root);
           	cout<<endl;
            return ;
           }
           else
           return ;
          
        }
    }
    else if(t==null)
    {
    	t=new TreeNode;
    	t->left=null;
    	t->right=null;
    	t->val=i;
    	cout<<"special\n";
    	print1(root);
    	cout<<endl;
    	if(size(root)==n)
        {
        	if(good(root,INT_MIN,INT_MAX))
    	    {
            ans.push_back(root);
           	print(root);
           	cout<<endl;
           	print1(root);
           	cout<<endl;
            return ;
           }
           else
           return ;
        }
        
      
	}
    for(int i=1;i<=n;i++)
    {
    	cout<<"root="<<root->val<<endl;
    	cout<<"check\n";
    	cout<<check(root,i)<<endl;
    	
        if(!check(root,i))
        {
            if(i<t->val)
            {
            generate(t->left,i,n);
            }
            else
            {
            generate(t->right,i,n);
       
           }
           
           t->right=null;
        t->left=null;
        }
 
    }
//         t->right=null;
//        t->left=null;

    
}
 
 
 
vector<TreeNode*> Solution::generateTrees(int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i;tptr t=null;
    for(i=1;i<=n;i++)
    {
    	t=null;root=null;
        generate(t,i,n);
    }
    
    
    return ans;
}

int main()
{
	Solution s;
	int n;
	cin>>n;
	s.generateTrees(n);
	
}
