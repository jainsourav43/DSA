#include<iostream>
using namespace std;
typedef
struct node
{
	int data;
	struct node *next;
} *lptr;
void addbegin(lptr &l1,int d)
{
	lptr t;
	t=new struct node;
	t->data=d;
	t->next=l1;
	l1=t;	
}
void add_end(lptr l,int d)
{
	lptr t=l;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=new struct node;
	t=t->next;
	t->data=d;
	t->next=NULL;
}
void addbefore(lptr l,int d)
{
	lptr t,t2;
	t=l;int n;
	cout<<"Enter the data \n";
	cin>>n;
	while(t->next->data!=d)
	{
		t=t->next;
	}
	t2=t->next;
	t->next=new struct node;
	t=t->next;
	t->data=n;
	t->next=t2;
}
void addafter(lptr l,int d)
{
	lptr t;
	t=l;int n;
	cout<<"Enter the data to be added\n";
	cin>>n;
	while(t->data!=d)
	{
		t=t->next;
	}
	lptr t2=t->next;
	t->next=new struct node;
	t=t->next;
	t->data= n;
	t->next=t2;
}
void display(lptr l)
{
//	lptr t=l;
	while(l!=NULL)
	{
		cout<<l->data<<" ";	
		l=l->next;
	}cout<<endl;	
}
void create(lptr l)
{
	int d;lptr t;
//	t=l;
//	cout<<"Enter the first element or -1 to exit\n";
//	cin>>d;
//	if(d!=-1)
//	{
//		t->data=d;
//		t->next=NULL;
//	}
	while(d!=-1)
	{
	    cout<<"Enter the element or -1 to exit\n";
		cin>>d;
		if(d!=-1)
		add_end(l,d);
	}
}
void deleteend(lptr l)
{
lptr t;
t=l;
	while(t->next->next!=NULL)
	{
		t=t->next;
	}
	lptr t2;
	t2=t->next;
	t->next=NULL;
	delete(t2);
}
void deletebegin(lptr &l)
{
	lptr t;
	t=new struct node;
	t=l;
	l=l->next;
	delete t;
}
void deleteatpos(lptr l,int p)
{
	lptr t=l;int d;
	while(t->next->data!=p)
	t=t->next;
	lptr t2=t->next;
	t->next=t->next->next;
	delete t2;
}
void deleteafter(lptr l,int d)
{
	lptr t,t2;
	t=l;
	while(t->data!=d)
	{
		t=t->next;
	}
	t2=t->next;
	t->next=t->next->next;
	delete t2;
}
void deletebefore(lptr l,int p)
{
	lptr t,t2;
	t=l;
	while(t->next->next->data!=p)
	{
		t=t->next;
	}
	t2=t->next;
	t->next=t->next->next;
	delete t2;
}
/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
node* MergeLists(node *headA, node* headB)
{
  node *t1,*t2,*t3,*t4;
    t4=t3;
    t1=headA;int i=0;
    t2=headB;
    while(t1!=NULL&&t2!=NULL)
        {
        if(t1->data>t2->data)
            {
            if(i==0)
                {
                 t3=new node;
                t3->data=t2->data;
                t3->next=NULL;
                i++;
            }
            else
                {
                t3->next=new node;
                t3=t3->next;
                t3->data=t2->data;
                t3->next=NULL;
                i++;
                
            }
        }
        else
            {
             if(i==0)
                {
                 t3=new node;
                t3->data=t1->data;
                t3->next=NULL;
                i++;
            }
            else
                {
                t3->next=new node;
                t3=t3->next;
                t3->data=t1->data;
                t3->next=NULL;
                i++;
                
            }
        }
            
        }
    while(t1!=NULL)
        {
    
        if(i==0)
                {
                 t3=new node;
                t3->data=t1->data;
                t3->next=NULL;
                i++;
            }
            else
                {
                t3->next=new node;
                t3=t3->next;
                t3->data=t1->data;
                t3->next=NULL;
                i++;
                
            }
}
    while(t2!=NULL)
        {
        {
            if(i==0)
                {
                 t3=new node;
                t3->data=t2->data;
                t3->next=NULL;
                i++;
            }
            else
                {
                t3->next=new node;
                t3=t3->next;
                t3->data=t2->data;
                t3->next=NULL;
                i++;
                
            }
}
}
    return t4;
}

int main()
{
	lptr l;
	int item;int ch;
	l=new struct node;
	int d;
	cout<<" enter First element of linked list\n";
	cin>>d;
	l->data=d;
	l->next=NULL;
	 while(1)
  {
  cout<<"A heartly welcome to the world of linked list\n";
  cout<<"1 for creating the linked list\n";
  cout<<"2 for insert at end \n";
  cout<<"3 for displaying \n";
  cout<<"4 for insert at begigning"<<endl;
  cout<<"5 for add after node \n";
  cout<<"6 for add before node\n";
  cout<<"7 for delete at begigning\n";
  cout<<"8 for delete at end \n";
  cout<<"9 for delete at nth position \n";
  cout<<"10 for delete before\n";
  cout<<"11 for delete after\n";
  cout<<"Please enter your choice"<<endl;
  cin>>ch;
  switch(ch)
  {
  	case 1 :
  		{
  			//node *tmp;
  		create(l);
  			break;
		  }
		  case 2 :
		  	{
		  	cout<<"enter the data\n";
			  cin>>d;
			  add_end(l ,d);	
			  break;
			  }
			  case 3:
			  	{
			  		display(l);
			  		break;
				  }
				  case 4 :
				  	{
				  		cout<<"Enter the number \n";
				  		cin>>d;
				  	   addbegin(l,d);
				  		break;
					  }
					  case 5 :
					  	{
					  		cout<<"enter the item\n";
					  		cin>>item;
					  		addafter(l,item);
					  		break;
						  }
						  case 6 :
						  	{
						  		cout<<"enter the item\n";
						  		cin>>item;
						  		addbefore(l,item);
						  		break;
							  }
							  case 7:
							  	{
							  	
							  		deletebegin(l);
							  		break;
								  }
								  case 8:
								  	{
                                       deleteend(l)	;		
									   	break;
									  }
									  case 9:
									  	{
									  	cout<<"enter the data\n";
									  	cin>>d;
                                          deleteatpos(l,d)	;		
		       						  	break;
										  }
										  case 10:
										  	{
											  cout<<"Enter the number before u wish to delete\n";
										  	  cin>>d;
										  		deletebefore(l,d);
											  }
											  break;
											  case 11:
											  	{
											  		cout<<"Enter the number after  which u wish to delete\n";
											  		cin>>d;
											  		deleteafter(l,d);
												  }
												  break;
											  default :
											  	cout<<"wrong choice\n";
  }
  }

}
