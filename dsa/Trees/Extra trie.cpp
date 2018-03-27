void create(trptr &tr1,char str1[],char str[],int n)
{
	leafnode *l1;int k=0,i,j,m,m1,ans,u;
	trptr tr=tr1;
	for(i=0;i<strlen(str);i++)
	{
		if(str1[0]==str[i])
		{
			break;
		}
	}
	if(tr->ptr.ptr1[i]&&tr->ptr.ptr1[i]->tag==0)
	{
	    cout<<"COme1\n";
		l1=tr->ptr.ptr1[i]->ptr.ptr2;	
		cout<<"k= "<<k<<" i= "<<i<<" j =  "<< j<<"l1->key = "<<l1->key<<endl;
		for(j=0;(str1[j]==l1->key[j])&&j<strlen(str1);j++)
		{
			k++;cout<<"k= "<<k<<" i= "<<i<<" j =  "<< j<<"	tr->ptr.ptr1[i]=  "<<tr->ptr.ptr1[i]<<endl;
			tr->ptr.ptr1[i]=new trnode;
			tr->ptr.ptr1[i]->ptr.ptr1=new trptr[n+1];
			cout<<"y\n";
			tr=tr->ptr.ptr1[i];
			cout<<"y1\n";
			tr->tag=1;
			for(u=0;u<=n;u++)
			{
				tr->ptr.ptr1[u]=null;
			}
			cout<<"y2\n";
			for(m=0;m<strlen(str);m++)
			{
				if(str1[k]==str[m])
				{
					break;
				}
			}
			cout<<"y3\n";
			for(m1=0;m1<strlen(str);m1++)
			{
				if(l1->key[k]==str[m1])
				{
					break;
				}
			}
			cout<<"y4\n";
			ans=m1;
			i=m;
		}
		cout<<"i=  "<<i<<"ans = "<<ans<<endl;
		tr->ptr.ptr1[i]=new trnode;
		tr->ptr.ptr1[ans]=new trnode;
		tr->ptr.ptr1[i]->tag=0;
		tr->ptr.ptr1[ans]->tag=0;
		tr->ptr.ptr1[i]->ptr.ptr2=new leafnode;
		tr->ptr.ptr1[ans]->ptr.ptr2=new leafnode;
		strcpy(tr->ptr.ptr1[ans]->ptr.ptr2->key,l1->key);
		strcpy(tr->ptr.ptr1[i]->ptr.ptr2->key,str1);
	}
	else
	{   
	    cout<<"COme\n";
	    if(tr->ptr.ptr1[i]==null)
	    {
		leafnode *l;
		l=new leafnode;
		strcpy(l->key,str1);
		tr->ptr.ptr1[i]=new trnode;
		tr=tr->ptr.ptr1[i];
		tr->tag=0;
		tr->ptr.ptr2=l;
	   }
	  else
	  {
	  	for(j=0;j<strlen(str1);j++)
	  	{
	  		if(tr->ptr.ptr1[i]&&tr->ptr.ptr1[i]->tag!=0)
	  		{
	  			tr=tr->ptr.ptr1[i];
	  			for(m=0;m<strlen(str);m++)
				{
					if(str1[k]==str[m])
					{
						break;
					}
				}
				i=m;
			}
			else
			{cout<<"Else\n";
			  l1=tr->ptr.ptr1[i]->ptr.ptr2;
			  for(j=k;j<strlen(str1);j++)
			  {
			  	 
			  }
			}
		    k++;
	    }
	  }
	}
}
