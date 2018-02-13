#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{int value,index;
 struct node *next;
};
node *root;

int parent(int i)
{i=(i%2==0)?i:i+1; 
 return ((i/2)-1);}

void swap(node *b,node *c)
{int temp=b->value;
 b->value=c->value;
 c->value=temp;
}

void heapify(node* start)
{if(start==NULL){return;}
 int left=2*(start->index)+1;
 int right=2*(start->index)+2;
 node *p1=start,*p2=start;
 while(p1->index!=left&&p1!=NULL){p1=p1->next;}
 while(p2->index!=right&&p2!=NULL){p2=p2->next;}

 node *smallest=start;
 if ((p1->value)<(start->value) &&p1!=NULL)
		{smallest = p1;}
 if ((p2->value)<(smallest->value)&&p2!=NULL)
		{smallest = p2;}

 if(smallest!=start)
 {swap(smallest,start);
  heapify(smallest);
 }
}

void extract_min()
{node* start=root;
 if(start==NULL){cout<<"underflow"<<endl;return;}
 int val=start->value;
 if(root->next==NULL){root=NULL;cout<<"Min= "<<val<<endl;return;}
 
 root=root->next;
 while((start=start->next)!=NULL)
 {start->index=start->index-1;}
 cout<<"Min= "<<val<<endl;
 heapify(start);
 
}

void insert(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
 temp->value=data;
 temp->next=NULL;
 if(root==NULL){temp->index=0;root=temp;return;}
 
 node *pointer1,*pointer2;
 pointer1=root;
 pointer2=root;

 while(pointer1->next!=NULL)
 {pointer1=pointer1->next;}
 
 pointer1->next=temp;
 temp->index=(pointer1->index)+1;
 pointer1=pointer1->next;

 while((pointer1->index)!=0)
 { 
   int parent_index=parent(pointer1->index);
   while(pointer2->index!=parent_index)
   {pointer2=pointer2->next;}

   if(pointer1->value<pointer2->value)
   {swap(pointer1,pointer2);}

   pointer1=pointer2;
   pointer2=root;
 }	
}

void display()
{node *start=root;
 if(start==NULL){cout<<"underflow"<<endl;return;}
 while((start->next)!=NULL)
 {cout<<start->value<<endl;
  start=start->next;
 }
 cout<<(start->value)<<endl;
}

int main()
{int data,i,option=0,min;
 do
 {cout<<"1-Insert"<<endl<<"2-Display"<<endl<<"3-Extract Min"<<endl<<"0-exit"<<endl;cin>>option;
 switch(option)
 {case 1:cout<<"enter number";cin>>data;
		 insert(data);break;
  case 2:display();break;
  case 3:extract_min();
		 break;
  default:option=0;
 }
 }while(option);
}
