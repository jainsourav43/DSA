#include<iostream>

using namespace std;

int d=2;     // global d
//structure definition

typedef
struct btree
{
  int count;
  int keys[4];
  btree* ptr[5];
}
*btptr;

//structure to be used while sorting the overflow node
struct btkey
{
  btptr lchild;
  int data;
  btptr rchild;
};

typedef
struct llist
{
  btptr data;
  llist* next;
}
*lptr;

struct que
{
  lptr first;
  lptr data;
  lptr rare;
};

// llist funcitons

void initialize(lptr &);
void addback(lptr&,btptr&);

//queue funcions

void initialize(que&);
btptr deq(que&);
void enq(que& ,btptr&);
bool empty(que);

//btkey functions

void initialize(btkey&);
bool check(btkey);  //check for NULL empty key

//sort
void bubble_sort(btkey* ,int,int);
void bubble_sort(int *,int);
void node_sort(btptr&);
// structure functions declarations

void initialize(btptr &);
void reset(btptr&);
btkey split(btptr &,int key);
btptr insert(btptr &,int); //set overflow node also
void add(btptr &,int );
void print(btptr t);
void print2(btptr ); // to print each node first and then the other children
void print_node(btptr t);
void pr(btkey* ,int );
void pr(int *,int);
bool if_left(btptr ,int);
bool if_right(btptr ,int );
void level_print(btptr);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
  btptr t=NULL;
  int input[20]={2,4,5,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,7}; // 18=34
  int input2[22]={4,7,22,21,35,12,23,39,16,32,29,46,28,43,64,9,49,53,40,42,24,60};
  for(int i=0;i<50;i++)
  {
    add(t,i+1);
    //cout<<"\nAfter adding "<<input[i]<<endl;
    //print(t);
  }
  /*for(int i=50;i>=25;i--)
  {
    add(t,i);
    //cout<<"\nAfter adding "<<input[i]<<endl;
    //print(t);
  }
  for(int i=1;i<=24;i++)
  {
    add(t,i);
    //cout<<"\nAfter adding "<<input[i]<<endl;
    //print(t);
  }*/
  cout<<"\npre order printing\n";
  print(t);
  cout<<"\n\n";
  cout<<"\nlevel printing \n";
  level_print(t);
//  print2(t);
  cout<<"\n";

  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//function definitions

//llist funcitons

void initialize(lptr &l)
{
  l=new llist;
  l->data=NULL;
  l->next=NULL;
}

void addback(lptr& l,btptr &t)
{
  if(l!=NULL)
  {
    if(l->next!=NULL)
    {
    addback(l->next,t);
    return;
    }
    initialize(l->next);
      l->next->data=t;
      return;
  }
  else
  {
    initialize(l);
    l->data=t;
  }
}

//queue functions

void initialize(que &q)
{
  q.first=NULL;
  q.data=NULL;
  q.rare=NULL;
}

void enq(que &q,btptr &t)
{
  //make sure q is initialized

  addback(q.data,t);
  if(q.first==NULL)
  q.first=q.data;
  lptr x=q.data;
  while(x->next!=NULL)
  {
    x=x->next;
  }
  q.rare=x;

}

btptr deq(que& q)
{
  if(q.data!=NULL)
  {
  q.first=q.data->next;
  btptr x=q.data->data;
  q.data=q.data->next;
  if(q.data==NULL)
  q.rare=NULL;
  return x;
  }
  else
  {
    cout<<"\nqueue is empty\n";
    return NULL;
  }
}

bool empty(que q)
{
  if((q.first==q.rare)&&(q.first==NULL)||q.data==NULL)
  {
    return true;
  }
  return false;
}

// btkey functions

bool check(btkey key)
{
  if(key.lchild==NULL && key.rchild==NULL and key.data==-1)
  return false;
  return true;
}

void initialize(btkey &key)
{
  key.lchild=NULL;
  key.rchild=NULL;
  key.data=-1;
}

//btree functions

void print_node(btptr t)
{
  //cout<<"\nprinting node\n";
  cout<<" /";
  if(t!=NULL)
  {
    //cout<<"\nhere\n";
    for(int i=0;i<t->count;i++)
    {
      if(i!=0)
      cout<<",";
      cout<<t->keys[i];
    }
    cout<<"/ ";
  }
}

void pr(btkey *arr,int size)
{
  cout<<"\n";
  for(int i=0;i<size;i++)
  {
    cout<<arr[i].data<<" ";
    if(arr[i].lchild!=NULL)
    cout<<arr[i].lchild->keys[0]<<" ";
    if(arr[i].rchild!=NULL)
    cout<<arr[i].rchild->keys[0]<<" ";
    cout<<"\n";
  }
}

void pr(int *arr,int size)
{
  cout<<"\n";
  for(int i=0;i<size;i++)
  {
    cout<<arr[i]<<" ";
  }
}

void bubble_sort(btkey *arr,int size,int key)
{
  for(int i=0;i<size-1;i++)
  {
    for(int j=1;j<size-i;j++)
    {
      if(arr[j].data<arr[j-1].data)
      {
        btkey temp=arr[j];
        //
        arr[j]=arr[j-1];
        //
        arr[j-1]=temp;
      }
    }
  }
  for(int i=0;i<size;i++)
  {
    if(arr[i].data==key)
    {
      if(i-1>0)
      {
        arr[i-1].rchild=arr[i].lchild;
      }
      if(i+1<size)
      {
        arr[i+1].lchild=arr[i].rchild;
      }
      break;
    }
  }
}

void bubble_sort(int *arr,int size)
{
  for(int i=0;i<size-1;i++)
  {
    for(int j=1;j<size-i;j++)
    {
      if(arr[j]<arr[j-1])
      {
        int temp=arr[j];
        //
        arr[j]=arr[j-1];
        //
        arr[j-1]=temp;
      }
    }
  }
}

void initialize(btptr &t)
{
  t=new btree;
  for(int i=0;i<(2*d+1);i++)
  {
    t->ptr[i]=NULL;
  }
  for(int i=0;i<(2*d);i++)
  {
    t->keys[i]=0;
  }
  t->count=0;
}

void reset(btptr &t)
{
  for(int i=0;i<(2*d+1);i++)
  {
    t->ptr[i]=NULL;
  }
  for(int i=0;i<(2*d);i++)
  {
    t->keys[i]=0;
  }
  t->count=0;
}

btptr insert(btptr &t,int key)
{
  static int level=0,flag=-1;
  btptr temp=NULL;
  /*if(key==5)
  {
    //cout<<"\nbefore 5\n";
    //cout<<"\nlevel\n"<<level<<endl;
    //print_node(t);
  }*/
  if(t!=NULL)
  {
    //cout<<"\nt is not null\n";
    int i=0;
    for(i;i<t->count;i++)
    {
      if(t->keys[i]>key)
      break;
    }
    if(t->ptr[i]!=NULL)
    {
      //cout<<"\n in t lock\n";
      level++;
      temp=insert(t->ptr[i],key);
      level--;
    }
    else if((t->count<2*d)&&(flag==-1))
    {
      //rearran

      btkey arr[t->count+1];
      int size=0;
      //cout<<"\nbefore rearranging node is : ";
      //print(t);
      for(size=0;size<t->count;size++)
      {
        arr[size].lchild=t->ptr[size];
        arr[size].rchild=t->ptr[size+1];
        arr[size].data=t->keys[size];
      }

      arr[size].lchild=NULL;
      arr[size].rchild=NULL;
      arr[size].data=key;
      size++;

      //cout<<"\nbefore sorting\n";
    //pr(arr,size);

      bubble_sort(arr,size,key);

      reset(t);

      for(t->count=0;t->count<size;t->count++)
      {
        t->keys[t->count]=arr[t->count].data;
        t->ptr[t->count]=arr[t->count].lchild;
        t->ptr[t->count+1]=arr[t->count].rchild;
      }
      flag=-2;
      if(level==0)
      flag=-1;
      return NULL;
    }

    else if(flag==-1)
    {
      if(level!=0)
      flag=level-1;
      if(level!=0)
      return NULL;
      return t;
    }

    if(level==flag)
    {
    flag=-2;
    if(level==0)
    flag=-1;
    return t;
    }

    if(level==0)
    {
      flag=-1;
    }

  }
  return temp;
}

btkey split(btptr &t,int key)
{
  static int level=0;
  btkey this_key;
  initialize(this_key);
  if(t!=NULL)
  {
    //cout<<"\nspliting for "<<key<<endl;
    int i=0;
    for(i=0;i<t->count;i++)
    {
      if(t->keys[i]>key)
      break;
    }
    if(t->ptr[i]!=NULL)
    {
      level++;
      this_key=split(t->ptr[i],key);
      level--;
    }
    if(check(this_key)||t->ptr[i]==NULL)
    {
      //cout<<"\ni am here\n";
      //if(level==0)
      //cout<<"\nin root node only\n";
      //print_node(t);
      if(!check(this_key))
      {
        this_key.data=key;
        this_key.lchild=NULL;
        this_key.rchild=NULL;
      }

      btkey arr[2*d+1];
      int size=0;
      for(size=0;size<t->count;size++)
      {
        arr[size].lchild=t->ptr[size];
        arr[size].data=t->keys[size];
        arr[size].rchild=t->ptr[size+1];
      }

      arr[size]=this_key;
      size++;
      //
      bubble_sort(arr,size,this_key.data);
      //
      int mid=d;

      if(t->count<2*d)
      {
        reset(t);
        for(int x=0;x<size;x++)
        {
          t->keys[x]=arr[x].data;
          t->ptr[x]=arr[x].lchild;
          t->ptr[x+1]=arr[x].rchild;
          t->count++;
        }
        initialize(this_key);
        return this_key;
      }
      else
      {
      btptr new_node;
      initialize(new_node);

      reset(t);
      for(int j=0;j<mid;j++)
      {
        t->keys[j]=arr[j].data;
        t->ptr[j]=arr[j].lchild;
        t->ptr[j+1]=arr[j].rchild;
        t->count++;
      }

      int z=mid+1;
      for(int j=0;j<mid;j++,z++)
      {
        new_node->keys[j]=arr[z].data;
        new_node->ptr[j]=arr[z].lchild;
        new_node->ptr[j+1]=arr[z].rchild;
        new_node->count++;
      }

      arr[mid].lchild=t;
      arr[mid].rchild=new_node;

      //cout<<"\narr mid\n";
      //cout<<arr[mid].lchild<<" "<<arr[mid].rchild<<" "<<arr[mid].data<<endl;

      //cout<<"\nbefore checking root node\n";
      //print_node(t);

      if(level==0)
      {
        btptr node3;
        initialize(node3);
        node3->count=1;
        node3->ptr[0]=arr[mid].lchild;
        node3->ptr[1]=arr[mid].rchild;
        node3->keys[0]=arr[mid].data;
        initialize(this_key); // not initializing just reseting
        cout<<"\n";
        t=node3;
        return  this_key;
      }
      else
      {
      return arr[mid];
      }
      }
    }
    //initialize(this_key);
    return this_key;
  }
}

void add(btptr &tree,int key)
{
  if(tree==NULL)
  {
    //will initialize if root node is not present
    initialize(tree);
    tree->keys[0]=key;
    tree->count++;
    return;
  }

  btptr t=insert(tree,key);

  if(t)
  {
    bool flag=true;

    if(if_left(t,key))
    {

      flag=false;
      int i=0;
      for(i=0;i<t->count;i++)
      {
        if(key<t->keys[i])
        break;
      }
      int size1=t->ptr[i-1]->count;
      int arr[size1+2*d+2];
      int size=0;
      for(size=0;size<size1;size++)
      {
        arr[size]=t->ptr[i-1]->keys[size];
      }

      arr[size]=t->keys[i-1];
      size++;

      for(int x=0;x<2*d;x++)
      {
        arr[size]=t->ptr[i]->keys[x];
        size++;
      }

      arr[size]=key;
      size++;

      //pr(arr,size);

      bubble_sort(arr,size);

      //pr(arr,size);

      int new_size=0;

      t->ptr[i-1]->count=size1+1;

      for(int x=0;x<size1+1;x++)
      {
        t->ptr[i-1]->keys[x]=arr[new_size];
        new_size++;
      }

      t->keys[i-1]=arr[new_size];
      new_size++;

      for(int x=0;x<2*d;x++)
      {
        t->ptr[i]->keys[x]=arr[new_size];
        new_size++;
      }
    }
    else if(flag&&if_right(t,key))
    {
      flag=false;
      int i=0;
      for(i=0;i<t->count;i++)
      {
        if(key<t->keys[i])
        break;
      }
      int size1=t->ptr[i+1]->count;
      int arr[size1+2*d+2];
      int size=0;
      for(size=0;size<size1;size++)
      {
        arr[size]=t->ptr[i+1]->keys[size];
      }

      arr[size]=t->keys[i];
      size++;

      for(int x=0;x<2*d;x++)
      {
        arr[size]=t->ptr[i]->keys[x];
        size++;
      }

      arr[size]=key;
      size++;

      //pr(arr,size);

      bubble_sort(arr,size);

      //pr(arr,size);

      size--;

      t->ptr[i+1]->count=size1+1;

      for(int x=size1;x>=0;x--)
      {
        t->ptr[i+1]->keys[x]=arr[size];
        size--;
      }

      t->keys[i]=arr[size];
      size--;

      for(int x=2*d-1;x>=0;x--)
      {
        t->ptr[i]->keys[x]=arr[size];
        size--;
      }
    }
    if(flag)
    btkey x=split(tree,key);
  }

}

void print(btptr t)
{
  if(t!=NULL)
  {
    int i=0;
    for(i=0;i<t->count;i++)
    {
      print(t->ptr[i]);
      cout<<t->keys[i]<<" ";
    }
    print(t->ptr[i]);
  }
}

void print2(btptr t)
{
  static int level=0;
  if(t!=NULL)
  {
    cout<<"\nNode at level "<<level<<endl;
    for(int j=0;j<t->count;j++)
    {
      cout<<t->keys[j]<<" ";
    }
    int i=0;
    for(i;i<t->count;i++)
    {
      level++;
      print2(t->ptr[i]);
      level--;
    }
    level++;
    print2(t->ptr[i]);
    level--;
  }
}

bool if_left(btptr t,int key)
{
  if(t!=NULL)
  {
    int i=0;
    for(i;i<t->count;i++)
    {
      if(key<t->keys[i])
      break;
    }
    if((i-1>=0)&&(t->ptr[i-1]!=NULL))
    {
      if(t->ptr[i-1]->count<(2*d))
      return true;            // check only firt pointer case
    }
  }
  return false;
}

bool if_right(btptr t,int key)
{
  if(t!=NULL)
  {
    int i=0;
    for(i;i<t->count;i++)
    {
      if(key<t->keys[i])
      break;
    }
    if(((i+1)<2*d)&&(t->ptr[i+1]!=NULL))
    {
      if(t->ptr[i+1]->count<(2*d))
      return true;
    }
  }
  return false;
}

void level_print(btptr t)
{
  que q;
  initialize(q);
  enq(q,t);
  btptr flag;
  initialize(flag);
  enq(q,flag);
  while(!empty(q))
  {
    btptr node=deq(q);
    if(node==flag)
    {
      cout<<"\n";
      if(!empty(q))
      {
      node=deq(q);
      enq(q,flag);
      }
      else
      break;
    }
    if(node!=NULL&&node!=flag)
    {
    print_node(node);
    int i;
    for(i=0;i<node->count;i++)
    {
      enq(q,node->ptr[i]);
    }
    enq(q,node->ptr[i]);
    }
  }
}
