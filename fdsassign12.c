#include<stdio.h>
#include<stdlib.h>

typedef struct rec{
  int bno;
  char name[25];
  char auth[25];
} rec;

typedef struct node {
  rec r;
  int n;
  struct node *next;
} node;

void rec_entry(rec *obj)
{
  printf("\nEnter the Book No. : ");
  scanf("%d",&obj->bno);
  printf("\nEnter the Book Name : ");
  scanf("%s",obj->name);
  printf("\nEnter the Author Name : ");
  scanf("%s",obj->auth);
}

void rec_display(rec obj)
{
  printf("\nBook No.    : %d",obj.bno);
  printf("\nBook Name   : %s",obj.name);
  printf("\nAuthor Name : %s",obj.auth);
  printf("\n");
}

void rec_modify(rec *obj)
{
  printf("\nBook No. : %d",obj->bno);
  printf("\nEnter the Book Name : ");
  scanf("%s",obj->name);
  printf("\nEnter the Author Name : ");
  scanf("%s",obj->auth);
}

node * create()
{
  int n,i;
  rec ele;
  node *head,*p1;
  head=malloc(sizeof(node));
  p1=head;

  printf("\n\nEnter the number of Book Records : ");
  scanf("%d",&n);
  head->n=n;

  printf("\n\nEnter the Data for Records : ");

  for(i=0;i<n;i++)
  {
    p1->next=malloc(sizeof(node));
    p1=p1->next;
    rec_entry(&p1->r);
    p1->next=NULL;
  }

  return head;
}

void display(node *head)
{
  node *ptr;

  ptr=head->next;

  printf("\nRecords of the Database : ");

  while(ptr!=NULL)
  {
    rec_display(ptr->r);
    ptr=ptr->next;
  }
  printf("\n\n");
}


void modify(node *head)
{
  int bno,f=0;
  node *p1;
  p1=head;
  printf("\nWrite the Record Book No. to Modify : ");
  scanf("%d",&bno);

  while(p1!=NULL)
  {
    if(p1->r.bno==bno)
    {
      rec_modify(&p1->r);
      f++;
      printf("\nRecord Modified...");
      break;
    }
    else    p1=p1->next;
  }

  if(f==0) printf("\nRecord not found...!!!");
}

void delete_loc(node *head)
{
  int n,i,loc;
  node *p1,*p2,*tmp;
  p1=head;
  n=head->n;
  printf("\nWrite the location of Record to delete : ");
  scanf("%d",&loc);
  if(loc<=n && loc>0)
  {
    for(i=1;i!=loc;i++) p1=p1->next;
    p2=p1->next;
    tmp=p2;
    printf("\nDeleted Book No. : %d\n",p2->r.bno);
    p2=p2->next;
    p1->next=p2;
    free(tmp);
    head->n--;
  }
  else printf("\nERROR...!!!");
}

void delete_no(node *head)
{
  int bno,f=0;
  node *p1,*p2,*p3;
  p2=head->next;
  p1=head;
  printf("\nWrite the Record Book No. to delete : ");
  scanf("%d",&bno);

  while(p2!=NULL)
  {
    if((p2->r).bno==bno)
    {
      p3=p2->next;
      p1->next=p3;
      free(p2);
      printf("\nRecord Deleted...");
      f++;
      head->n--;
      break;
    }
    else
    {
      p2=p2->next;
      p1=p1->next;
    }
  }

  if(f==0) printf("\nRecord not found...!!!");
}

void insert(node *head)
{
  int n,i,loc;
  node *p1,*p2,*tmp;
  p1=head;
  n=head->n;
  printf("\nWrite the location to insert Record : ");
  scanf("%d",&loc);
  if(loc<=(n+1) && loc>0)
  {
    for(i=1;i!=loc;i++) p1=p1->next;
    p2=p1->next;
    tmp=malloc(sizeof(node));
    printf("\nEnter the data for Record : ");
    rec_entry(&tmp->r);
    tmp->next=p2;
    p1->next=tmp;
    head->n++;
  }
  else printf("\nERROR...!!!");
}

void delete(node *head)
{
  int ch;
  printf("\n1.Delete by Location");
  printf("\n2.Delete by Book No");
  printf("\n3.Go Back");
  printf("\n\nEnter your choice : ");
  scanf("%d",&ch);

  if(ch>0 && ch<4)
  {
    if(ch==1) delete_loc(head);
    else  delete_no(head);
  }
  else printf("\nERROR...!!!");
}

int menu()
{
  int o1;

  printf("\n***************************\n");

  printf("\n1.Create Book Database");
  printf("\n2.Display Book Database");
  printf("\n3.Insert Book Record");
  printf("\n4.Delete Book Record");
  printf("\n5.Modify Book Record");
  printf("\n0.Exit");
  printf("\n\nEnter your choice : ");
  scanf("%d",&o1);

  if(o1==0)  exit(0);
  else if(o1>-1 && o1<6)  {}
  else printf("\nERROR...!!!");

  return o1;
}

void main()
{
  node *head;
  int o=10,f=0;
  system("clear");

  while(o!=0)
  {
    o=menu();

    switch(o)
    {
      case 1: head = create();
              f++;
              break;
      case 2: if(f!=0)  display(head);
              else printf("\nMake a list first...!");
              break;
      case 3: if(f!=0)  insert(head);
              else printf("\nMake a list first...!");
              break;
      case 4: if(f!=0)  delete(head);
              else printf("\nMake a list first...!");
              break;
      case 5: if(f!=0)  modify(head);
              else printf("\nMake a list first...!");
              break;
      case 0: printf("\nBye......\n");
              break;
      default : printf("\nERROR....!!!");
              break;
    }
 }

}
