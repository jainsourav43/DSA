void right(node *root)
    {
    if(root->right!=NULL)
        {cout<<root->right->data<<" ";
        right(root->right);
        
}
}
void top_view(node * root)
{
    static int  k=0;
     k++;
     if(root!=NULL)
      { 
       top_view(root->left);   
      cout<<root->data<<" ";
         k--;
      }
    if(k==1)
        {
       right(root);
       }
}
