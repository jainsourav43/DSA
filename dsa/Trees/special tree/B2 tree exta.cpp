void overflow1(bptr &t,int a[],bptr lc,bptr rc,int k,int g)
{
	int che=0;
	cout<<"OVERFLOW\n";
	bptr t2,t3,t4;int i,j,l,m,in=0;
	if(t->par==null)
	{
	if(t->count==2*d-1)
	{	
	  cout<<"O IF\n";
      t2=new bnode;
      t2->count=-1;
	  t3=new bnode;
	  t3->count=-1;
      t2->par=t;
      t3->par=t;
      for(i=0;i<2;i++)
      {
      	t2->key[i]=a[i];
	  }
	  t2->count=1;
	   for( j=0;j<2;j++)
	  {
	  	t3->key[j]=a[j+d+1];
	  }
	cout<<"CG\n";
	  for(i=0;i<=2*d;i++)
	  {
	  	t2->ptr[i]=null;
	  }
	  for(i=0;i<=2*d;i++)
	  {
	  	t3->ptr[i]=null;
	  }int h=0;
	  for(i=0;i<=d;i++)
	  {
	  	if(t2->key[i]!=k)
	  	{
	  		if(h==1)
	  		t2->ptr[i]=t->ptr[i-1];
	  		else
	  		t2->ptr[i]=t->ptr[i];
	  		if(t2->key[i]!=a[d]&&i==d-1)
	  		{
	  			t2->ptr[i+1]=t->ptr[i+1];
			}
	    }
	    else if(t2->key[i]==k)
	    {cout<<"LLL\n";
	    	 h=1;
	    	t2->ptr[i]=lc;
	    	t2->ptr[i+1]=rc;
	    	i++;	
			che=1;
	    	//break;
 		}
	  }
	  cout<<"LG\n";cout<<"t  = "<<t3->key[1]<<endl;cout<<"K++++==   "<<a[d]<<endl;
	  for(i=d;i<2*d;i++)
	  {
	  	if(t3->key[i-d]!=k)
	  	{
	  		if(che==0)
	  		t3->ptr[i-d]=t->ptr[i+1];
	  		else
	  		t3->ptr[i-d]=t->ptr[i];
	  		
	  		if(t3->key[i-d]!=k&&i==2*d-1)
	  		{
			    cout<<"RRRTTTT\n";
			    if(t3&&t)
	  			t3->ptr[i-d+1]=t->ptr[i+1];
	  			cout<<"RRT !!\n";
			  }
		}
		else if(t3->key[i-d]==k)
		{
			cout<<"OPPPP\n";
			//cout<<"I+1  == "<<i+1<<endl;
			t3->ptr[i-d]=lc;	
			if(lc)
			cout<<"lc   ==  "<<lc->key[0]<<endl;
			//cout<<"RRT @@\n";
				t3->ptr[i+1-d]=rc;
			if(rc)
	    cout<<"rc   ==  "<<rc->key[0]<<endl;
	    	//cout<<"RRT @@ 3\n";

	    //	i++;
	    	//break;
		}
	  }
	 
	  cout<<"FG\n";
	   t3->count=1;
	  t->ptr[0]=t2;
	  t->ptr[1]=t3;
	  t->key[0]=a[d];
	  t->count=0;
	  //cout<<"T->par ->key[0]  = "<<t->key[0]<<endl;
	  for(i=2;i<=2*d;i++)
	  {
	  	t->ptr[i]=null;
	  }
//	  cout<<"T->key[0]=  "<<t->key[0]<<endl;
//	  cout<<"T->ptr[0]"<<t->ptr[0]->key[0]<<endl;
//	  cout<<"T->ptr[0]"<<t->ptr[0]->key[1]<<endl;
//	  cout<<"T->ptr[0]"<<t->ptr[1]->key[0]<<endl;
//	  cout<<"T->ptr[0]"<<t->ptr[1]->key[1]<<endl;
//cout<<t->ptr[0]<<"  "<<t->ptr[1]<<"   "<<t->ptr[2]<<"  "<<t->ptr[3]<<"  "<<t->ptr[4]<<endl;
//cout<<t2->ptr[0]<<"  "<<t2->ptr[1]<<"   "<<t2->ptr[2]<<"  "<<t2->ptr[3]<<"  "<<t2->ptr[4]<<endl;
//cout<<t3->ptr[0]<<"  "<<t3->ptr[1]<<"   "<<t3->ptr[2]<<"  "<<t3->ptr[3]<<"  "<<t3->ptr[4]<<endl;
       for(i=0;i<=2*d;i++)
	  {
	  	if(t2->ptr[i]!=null)
	  	t2->ptr[i]->par=t2;
	  }
	  for(i=0;i<=2*d;i++)
	  {
	  	if(t3->ptr[i]!=null)
	  	t3->ptr[i]->par=t3;
	  }
}
else
{
cout<<"Special\n";
        for( i=t->count;i>=0;i--)
		{
			if(t->key[i]>k)
			{
				t->key[i+1]=t->key[i];
				t->ptr[i+2]=t->ptr[i+1];
			}
			else
			{
				break;
			}
		}cout<<"I=  "<<i<<endl;
		t->key[i+1]=k;
		t->count++;
		t->ptr[i+2]=rc;
		t->ptr[i+1]=lc;
	}	
    }
	else if(t->par!=null)
	{
		int b[5];
	  if(g==0)
	  {
	  cout<<"ELSE OVER  2\n";
	  cout<<"T->par ->key[0]  = "<<t->par->key[0]<<endl;
	  cout<<"Ram\n";
	  t3=new bnode;
	  t3->count=-1;
	  for(i=0;i<=2*d;i++)
	  t3->ptr[i]=null;
	    cout<<"t->key  = "<<t->key[0]<<endl;
	    cout<<"  y1= "<<t->par->key[0]<<endl;
	    	    cout<<"  y1= "<<t->par->ptr[0]->key[0]<<endl;

	  	cout<<"  y1= "<<t->par->key[1]<<endl;
	  for( i=0;i<d;i++)
      {
      	t->key[i]=a[i];
	  }
	  t->count=d-1;
	   for( j=0;j<d;j++)
	  {
	  	t3->key[j]=a[j+d+1];
	  }
	  t3->count=d-1;
	  t3->par=t->par;
   }
   else
   {
   	  che=0;
   	  cout<<"ELSE OVER\n";
	  cout<<"T->par ->key[0]  = "<<t->par->key[0]<<endl;
	  t3=new bnode;
	  t3->count=-1;
	  cout<<"t->key "<<t->key[0]<<endl;
	        cout<<"t->par->key[0] =  "<<t->par->key[0]<<endl;

	  for( j=0;j<d;j++)
	  {
	  	cout<<"Ram 35\n";
	  	t3->key[j]=a[j+d+1];
	  }
	  t3->count=d-1;
	   for( i=0;i<d;i++)
      {
      	cout<<"Ram 33\n";
      	t->key[i]=a[i];
	  }
	  t->count=d-1;      cout<<"t->par->key[0] =  "<<t->par->key[0]<<endl;

	  for(i=0;i<=d;i++)
	  {
	  	if(t->key[i]!=k)
	  	{
	  		t->ptr[i]=t->ptr[i];
	  		if(t->ptr[i])
	  		{
	  			cout<<"zz ="<<t->ptr[i]->key[0]<<endl;
			  }
		}
		else 
		{
			t->ptr[i]=lc;
			t->ptr[i+1]=rc;
			if(t->ptr[i])
	  		{
	  			cout<<"zz 1="<<t->ptr[i]->key[0]<<endl;
			  }
			  if(t->ptr[i])
	  		{
	  			cout<<"zz +="<<t->ptr[i+1]->key[0]<<endl;
			  }
			i++;che=1;
		}
	  }      cout<<"t->par->key[0] =  "<<t->par->key[0]<<endl;

	  for(i=d;i<2*d;i++)
	  {
	  	if(t3->key[i-d]!=k)
	  	{
	  		if(che==1)
	  		t3->ptr[i-d]=t->ptr[i+1];
	  		else
	  		t3->ptr[i-d]=t->ptr[i];
	  		if(t3->key[i-d]!=k&&i==2*d-1)
	  		{
			    cout<<"RRRTTTT\n";
	  			t3->ptr[i-d+1]=t->ptr[i+1];
	  			cout<<"RAM 2\n";
	  			i++;
			  }
		}
		else if(t3->key[i-d]==k)
		{
			cout<<"OPPPP\n";
			cout<<"I+1  == "<<i+1<<endl;
			t3->ptr[i-d]=lc;	
	    	t3->ptr[i+1-d]=rc;
	    	if(rc)
	    	cout<<"rc  = "<<rc->key[0]<<endl;
	    	else
	    	cout<<"LC  ="<<endl;
	    	i++;
		}
	  }
	  cout<<"Ram 30\n";
//	  for(i=0;i<=2*d;i++)
//	  {
//	  	cout<<"Ram 31\n";
//	  	      cout<<"t->par->key[0] =  "<<t->par->key[0]<<endl;
//
//	  	if(t3->ptr[i]!=null)
//	  	{
//		cout<<"Gaya\n";
//	  	t3->ptr[i]->par=t3;
//	  }
//	  }
	  cout<<"Ram 32\n";
	    //cout<<"t->key  = "<<t->key[0]<<endl;
	    //cout<<"  y1= "<<t->par->key[0]<<endl;
	  	//cout<<"  y1= "<<t->par->key[1]<<endl;
	 
	  cout<<"Ram 34\n";
	  cout<<"Ram 3\n";
	  t3->count=d-1;      
	  cout<<"t->par->key[0] =  "<<t->par->key[0]<<endl;

	  t3->par=t->par;
	  cout<<"Ram 4\n";
   }
      cout<<"RAm 5\n";
      cout<<"t->par->key[0] =  "<<t->par->key[0]<<endl;
      if(t->par->count==3)
      {
      	for(i=0;i<4;i++)
      	b[i]=t->par->key[i];
      	b[4]=a[d];
      	sort(b,b+5);
      	cout<<"jjj 1 ="<<t->key[0]<<endl;
      	cout<<"jjj 2 "<<t3->key[0]<<endl;
      	overflow1(t->par,b,t,t3,a[d],1);
      	
	  }
	  else
	  {
	    cout<<"ELsE 2\n ";
	  	int in=0;
	  	cout<<"  y= "<<t->par->key[0]<<endl;
	  //	cout<<"  y= "<<t->par->key[1]<<endl;
	    cout<<"t->par->count "<<t->par->count<<endl;
	  	for(in=t->par->count;in>=0;in--)
	  	{
	  		if(t->par->key[in]>a[d])
	  		{
	  			cout<<"T->  "<<endl;
	  			t->par->key[in+1]=t->par->key[in];
	  			t->par->ptr[in+2]=t->par->ptr[in+1];
			}
			else
			{cout<<"KJIU\n";
				break;
			}
		}
		//in=t->par->count;
		cout<<"IN  =="<<in<<endl;
		cout<<t->par->key[0]<<endl;//cout<<t->par->key[1]<<endl;
		t->par->key[in+1]=a[d];
		cout<<t->par->key[in+1]<<"kk5\n  i+2 ="<<i+2;
		t->par->count++;
		t->par->ptr[in+1]=t;
		cout<<"t->key"<<t->key[0]<<endl;
	            	if(t->ptr[0]!=null)	
				cout<<"t->key"<<t->ptr[0]->key[0]<<endl;

		t->par->ptr[in+2]=t3;
		cout<<"t3->key= "<<t3->key[0]<<endl;
		if(t3->ptr[0]!=null)
			cout<<"t->key"<<t3->ptr[0]->key[0]<<endl;
			for(i=in+3;i<=2*d;i++)
			t->par->ptr[i]=null;
	  }
	}
}
