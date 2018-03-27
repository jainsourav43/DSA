bptr node_combine1(bptr t1,bptr t2)
{
    int i,j;
    cout<<"t->key[0] = "<<t1->key[0]<<"t2->key[0] = "<<t2->key[0]<<endl;
    if(t1->par->count==0)
    {
    	if()
	}
	else {
	for(i=0;i<d;i++)
	{
	t1->key[i+d]=t2->key[i];
	cout<<"in NC t2->key[i]=  "<<t2->key[i]<<"\n  ";
	t1->ptr[i+d+1]=t2->ptr[i+1];
	t1->count++;
	}
	t1->ptr[2*d]=t2->ptr[d];
	cout<<"end of the nc \n";
  }
	//delete t2;
	return t1;
}
void delete_node(bptr &t1,int k,int flag)
{
    int i,in;bptr node;
	bptr min,max;
  	bptr t=null;
    t=search(t1,k);
    cout<<"t->key[0] ="<<t->key[0]<<"t->count= "<<t->count<<endl;
    if(t->par)
    {
    cout<<"t->par->key[0] ="<<t->par->key[0]<<endl;
    }
  	int s=search1(t->par,t->key[0]);
  	in =index(t,k);
	if(t->ptr[0]==null&&t->count>d-1||(t->ptr[0]==null&&t==t1))
  	{   cout<<"enter special \n";
	    for( i=0;i<=t->count;i++)
		if(t->key[i]!=k)
		continue;
		else
		break;
		for(int j=i;j<t->count;j++)
		t->key[j]=t->key[j+1];
		t->count--;
	}
	else if(t->ptr[0]==null&&check(t))
	{	    cout<<"KK\n";
			redistribution3(t,k,s,check(t));
	}
	else if(t->ptr[0]==null&&t->count<d&&check(t)==0)
	{
		flag=1;
		cout<<"LEaf nc  in = "<<in<<endl<<"s  ="<<s<<"   t->par->count =  "<<t->par->count<<endl;
		if(s==t->par->count+1)
		{cout<<"LLLL\n";
		for(i=0;i!=in&&i<t->count;i++)
		t->key[i+1]=t->key[i];
		t->key[0]=t->par->key[s-1];
		cout<<"t->par->key[s]  = "<<t->par->key[s-1]<<endl;
		delete_node(t1,t->par->key[s-1],1);
	   }
	   else
	   {cout<<"LLLL 22\n";
	   	for(i=in;i<t->count;i++)
		t->key[i]=t->key[i+1];
		t->key[t->count]=t->par->key[s];
		cout<<"t->par->key[s]  = "<<t->par->key[s]<<endl;
		delete_node(t1,t->par->key[s],1);
	   }
	}
	else if(t->ptr[0]!=null)
	{
		if(flag==0)
		{
		   cout<<"ENter 1\n";
   		   int v=index(t,k);
		   min= find_min(t->ptr[v+1]);
		   cout<<"After min\n";
		   if(min->count<d)
	       {cout<<"ENter if 1 \n";
		 	if(v>0)
		 	{cout<<"Enter if 2 \n";
		 	cout<<"V ="<<v<<endl;
		 	max=find_max(t->ptr[v]);
		 	cout<<"max count ="<<max->count<<endl;
		 	cout<<"Afetr max\n";
		 	if(max->count<d)
		 	{
			    cout<<"ENter 2\n";
			    node=node_combine1(t->ptr[in],t->ptr[in+1]);
			    	if(t->count-1>=d-1)
				 	{
				 		for(i=t->count;i>in;i--)
				 		{
				 			t->key[i-1]=t->key[i];
				 			t->ptr[i-1]=t->ptr[i];
						 }
				 	t->ptr[in]=node;
				 	t->count--;
				 	t->ptr[in+1]=null;
				   }
				else
				{
		 	    for(i=v;i<t->count;i++)
		 	    {
	 	         t->key[i]=t->key[i+1];
				 t->ptr[i+1]=t->ptr[i+2];
			    }
			    t->ptr[in]=node;
			    if(t->par==null)
			    {
			    t->ptr[t->count+1]=null;t->count--;
			    }
				if(t->par!=null)
			    {
		 	    t->key[t->count]=t->par->key[s];
		 	    delete_node(t1,t->par->key[s],1);
		 	   }
		       }
			   }
			else
			{
				t->key[v]=max->key[max->count];
				cout<<"max->key[max-count] = "<<max->key[max->count]<<endl;
				delete_node(t->ptr[v],max->key[max->count],0);
			}
		   }
		   else if(v==0)
		   {
		 	max=find_max(t->ptr[v]);
		 	if(max->count<d)
		 	{
		 	if(t->par!=null&&check(t))
		 	{cout<<"hjk\n";
			 redistribution3(t,k,s,check(t));
			  delete_node(t1,t->par->key[s],1);
			 }
			 else
			 {
		 	   node=node_combine1(t->ptr[in],t->ptr[in+1]);
		 	   for(i=v;i<t->count;i++)
		 	   {
	 	        t->key[i]=t->key[i+1];
				 t->ptr[i+1]=t->ptr[i+2];
			   }
			   t->ptr[in]=node;
			    if(t->par==null)
			    {
			    if(t->count==0)
			    t1=node;
			    else
			    {
			    t->ptr[t->count+1]=null;t->count--;
			  }
			  }
			  if(t->par!=null)
			  {
		 	   t->key[t->count]=t->par->key[s];
		 	   delete_node(t1,t->par->key[s],1);
		    }
	    	}
			}
			else
			{
				t->key[v]=max->key[max->count];
				delete_node(t->ptr[v],max->key[max->count],0);
			}
		   }
		 }
		 else
		 {
		 t->key[v]=min->key[0];
		 delete_node(t->ptr[v+1],min->key[0],0);
	    }
	 }
	 else if(t->par!=null)
	 {

	   {int temp,temp1,ans=0;bptr tp,tp1;int che;s=search1(t->par,t->key[0]);cout<<"YYYY\n";
	   if(t->count-1<d-1){
	   	s=search1(t->par,t->key[0]);
		   if(s>0&&s<t->count+1)
		   {
		   if(t->par->ptr[s-1]->count>=d||t->par->ptr[s+1]->count>=d)
		   ans=1;
	      }
		   else if(s==0||s==t->count+1)
		   {
		   if(s==0&&t->par->ptr[s+1]->count>=d)
		   ans=1;
		   else if(s==t->count+1&&t->par->ptr[s-1]->count>=d)
		   ans=1;}
	  }
	 	 node=node_combine1(t->ptr[in],t->ptr[in+1]);
		 cout<<"After NC\n";
	 	if(t->count-1>=d-1)
	 	{	temp=t->key[t->count];tp=t->ptr[t->count+1];
 		for(i=t->count-1;i>=in;i--)
 		{   //t->key[i+1]=temp;
		     temp1=t->key[i];tp1=t->ptr[i+1];
 			t->key[i]=temp;
 			t->ptr[i+1]=tp;
 			temp=temp1;tp=tp1;
		 }
	 	t->ptr[in]=node;t->ptr[t->count+1]=null;
	 	t->count--;

	  }
	  else if(ans)
	  {
	 	if(s>0&&s<=t->count)
	 	{cout<<"LLK\n";
	     	min=find_min(t->par->ptr[s+1]);
	     	if(min->count>=d)
	     	che=2;
	     	max=find_max(t->par->ptr[s-1]);
	     	if(max->count>=d)
	     	che=1;
		 }
		 else if(s==0)
		 {
		 	min=find_min(t->par->ptr[s+1]);
		 	if(min->count>=d)
	     	che=2;
		 }
		 else if(s==t->count+1)
		 {
		 	max=find_max(t->par->ptr[s-1]);
		 	if(max->count>=d)
	     	che=1;
		 }

	 	if(che)
	 	{cout<<"COme\n";
	 		redistribution3(t,k,s,che);
		 }
		 t->ptr[in]=node;

			}
	 	else
	 	{
        if(t->par->count+1==s)
        {
        for(i=t->count-1;i>=0;i--)
	 	{
	 	t->key[i+1]=t->key[i];
	 	t->ptr[i+2]=t->ptr[i+1];
	    }
        t->key[0]=t->par->key[s-1];
        t->ptr[in+1]=node;

        }
        else
        {cout<<"AYAA\n";
        for(i=in;i<t->count;i++)
	 	{
	 	t->key[i]=t->key[i+1];
	 	t->ptr[i+1]=t->ptr[i+2];
	    }
        t->key[in+1]=t->par->key[s];

        t->ptr[d]=t->par->ptr[s+1]->ptr[0];
	 	t->ptr[in]=node;

	    }

	    if(t->par->count+1==s)
	 	delete_node(t1,t->par->key[s-1],1);
	 	else
	 	delete_node(t1,t->par->key[s],1);
	 }
	  }

	 }
	else if(t->par==null&&t->count==0)
	{S
		cout<<"special \n";
		t1=node_combine1(t->ptr[in],t->ptr[in+1]);
		s=search1(t->ptr[in+1]->par,t->key[0]);
		if(s!=t->ptr[in]->par->count+1)
		{cout<<"supper\n";
		for(i=0;i<d;i++)
		{
		t1->ptr[in]->ptr[i+d]=t->ptr[in+1]->ptr[i];
	    }
		t1->ptr[in]->ptr[2*d]=t->ptr[in+1]->ptr[d];
	    }
		t1->par=null;
		for(i=0;i<=t1->count+1;i++)
		if(t1->ptr[i])
		t1->ptr[i]->par=t1;
	}
	else if(t->par==null&&t->count!=0)
	{    cout<<"sssppp\n";
	     int c=t->count;
		node=node_combine1(t->ptr[in],t->ptr[in+1]);
		if(s!=t->ptr[in]->par->count+1)
		{
		for(i=0;i<d;i++)
		node->ptr[i+d]=t->ptr[in+1]->ptr[i];
		node->ptr[2*d]=t->ptr[in+1]->ptr[d];
	    }
		if(in!=t->count)
		{
	    for(i=in;i<t->count;i++)
	 	{
	 	t->key[i]=t->key[i+1];
	 	t->ptr[i+1]=t->ptr[i+2];
	    }
	    }
	   	t->ptr[in]=node;
	   	t->count--;
	   	t->ptr[c+1]=null;
	   	for(i=0;i<=t->count+1;i++)
		if(t1->ptr[i])
		t1->ptr[i]->par=t1;
	   	cout<<"back\n";

	}
	}

	}
