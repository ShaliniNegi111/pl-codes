#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node
{
  int c,e;
  struct node *next;
} node;


node * create()
{
  int n,i,d;
  node *ptr,*head=NULL;

  printf("\n\nEnter the number of Terms : ");
  scanf("%d",&n);

  if(n>0)
  {
    printf("\n\nEnter the Terms : ");

    head=(node *)malloc(sizeof(node));
    printf("\nEnter the Coeff. of term :");
    scanf("%d",&d);
    head->c=d;
    printf("\nEnter the Expo. of term :");
    scanf("%d",&d);
    head->e=d;
    ptr=head;

    for(i=0;i<(n-1);i++)
    {
      ptr->next=(node *)malloc(sizeof(node));
      ptr=ptr->next;
      printf("\nEnter the Coeff. of term :");
      scanf("%d",&ptr->c);
      printf("\nEnter the Expo. of term :");
      scanf("%d",&ptr->e);
    }
    ptr->next=head;
  }
  else printf("\nERROR...!!!");

  return head;
}


void display(node *head)
{
  node *ptr;
  ptr=head;

  printf("\nElements of the Polynomial : ");

  while(ptr->next!=head)
  {
    printf("  (%d*x%d)",ptr->c,ptr->e);
    ptr=ptr->next;
  }
  printf("  (%d*x%d)",ptr->c,ptr->e);
  printf("\n\n");
}



node * add(node *h1,node * h2)
{
  int f=0,f1=0,f2=0;
  node *p1,*p2,*h3=NULL,*p3,*a;
  p1=h1;  p2=h2;
  do
  {
    if(p1->e==p2->e)
    {
      a=(node *)malloc(sizeof(node));
      a->e=p1->e;
      a->c = p1->c + p2->c;
      p1=p1->next;  p2=p2->next;
    }
    else if(p1->e<p2->e)
    {
      a=(node *)malloc(sizeof(node));
      a->e=p1->e;
      a->c = p1->c;
      p1=p1->next;
    }
    else
    {
      a=(node *)malloc(sizeof(node));
      a->e=p2->e;
      a->c = p2->c;
      p2=p2->next;
    }
    if(f==0)
    {
      h3=a;
      p3=h3;   f++;
    }
    else
    {
      p3->next=a;
      p3=p3->next;
    }

    if(p1->next==h1)  f1++;
    if(p2->next==h2)  f2++;

  }while((p1!=h1 && p2!=h2) || (f1!=1 && f2!=1));

  if(p1==h1 && f1==1)  f1++;
  if(p2==h2 && f2==1)  f2++;

  if(f1!=2)
  {
    do
    {
      a=(node *)malloc(sizeof(node));
      a->e=p1->e;
      a->c = p1->c;
      p1=p1->next;
      if(f==0)
      {
        h3=a;
        p3=h3;   f++;
      }
      else
      {
        p3->next=a;
        p3=p3->next;
      }
      if(p1->next==h1)  f1=1;
    }while(p1!=h1 || f1!=1);
  }

  if(f2!=2)
  {
    do
    {
      a=(node *)malloc(sizeof(node));
      a->e=p2->e;
      a->c = p2->c;
      p2=p2->next;
      if(f==0)
      {
        h3=a;
        p3=h3;   f++;
      }
      else
      {
        p3->next=a;
        p3=p3->next;
      }
      if(p2->next==h2)  f2=1;
    }while(p2!=h2 || f2!=1);
  }

  p3->next=h3;

  return h3;

}

node * multi(node *h1,node * h2)
{
  node *p1,*p2,*p3,*h3=NULL,*a;
  int f=0,f1=0,f2=0,i=0;

  p1=h1;  p2=h2;

  do
  {
    f2=0;
    do
    {
      a=(node *)malloc(sizeof(node));
      a->e=p2->e+p1->e;
      a->c = p2->c * p1->c;
      p2=p2->next;

      if(i>25) break;
      if(f==0)
      {
        h3=a;
        p3=h3;   f++;
      }
      else
      {
        p3->next=a;
        p3=p3->next;
      }
      if(p2->next==h2)  f2++;

    }while(p2!=h2 || f2!=1);

    p1=p1->next;
    if(p1->next==h1)  f1++;

  }while(p1!=h1 || f1!=1);

  p3->next=h3;
  return h3;
}


node * reduce(node *head)
{
  int f=0,f1=0,i,j=0;
  node *p1,*p2,*h2=NULL,*a;
  int arr[10000];

  for(i=0;i<10000;i++)    arr[i]=0;

  p1=head;
  do
  {
    arr[p1->e]+=p1->c;
    p1=p1->next;
    if(p1->next==head)  f1++;
  }while(p1!=head || f1!=1);

  for(i=0;i<10000;i++)
  {
    if(arr[i]!=0)
    {
      a=(node *)malloc(sizeof(node));
      a->e=i;
      a->c=arr[i];
      if(f==0)
      {
        h2=a;
        p2=h2;   f++;
      }
      else
      {
        p2->next=a;
        p2=p2->next;
      }
    }
  }
  p2->next=h2;
  return h2;
}

long long int evaluate(node *head)
{
  int f=0;
  long long int val=0,x,c,e;
  node *p;
  p=head;

  printf("\nEnter the value of 'x' : ");
  scanf("%lld",&x);

  do
  {
    e=p->e; c=p->c;
    val+=(c*pow(x,e));
    p=p->next;
    if(p->next==head)  f++;
  }while(p!=head || f!=1);

  return val;
}

int menu()
{
  int o=0,o1;

  printf("\n***************************\n");

  printf("\n1.Polynomial Evaluate");
  printf("\n2.Polynomial Simplify");
  printf("\n3.Polynomial Addition");
  printf("\n4.Polynomial Multiplication");
  printf("\n0.Exit");
  printf("\n\nEnter your choice : ");
  scanf("%d",&o1);

  if(o1==0)  exit(0);
  else if(!(o1>-1 && o1<5))  printf("\nERROR...!!!");

  return o1;
}


void main()
{
  node *h1,*h2,*h3,*h4;
  long long int val;
  int o=10;

  system("clear");

  while(o!=0)
  {
    o=menu();
    switch(o)
    {
      case 1: h1=create();
              h2=reduce(h1);
              display(h2);
              val=evaluate(h2);
              printf("\n\nValue : %lld",val);
              break;
      case 2: h1=create();
              h2=reduce(h1);
              display(h2);
              break;
      case 3: h1=create();
              h1=reduce(h1);
              display(h1);
              h2=create();
              h2=reduce(h2);
              display(h2);
              h3=add(h1,h2);
              display(h3);
              break;
      case 4: h1=create();
              h1=reduce(h1);
              display(h1);
              h2=create();
              h2=reduce(h2);
              display(h2);
              h3=multi(h1,h2);
              h3=reduce(h3);
              display(h3);
              break;
      case 0: printf("\n\nBye...\n\n");
              break;
      default : printf("\n\nBye...\n\n");
              break;
    }
  }
}
