#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student rec;

struct student
{
  char name[10];
  int roll;
  float m1,m2,percent;
};


rec * input()
{
  rec *A;
  char str[10];
  float t;
  A = (rec *)malloc(sizeof(rec));
  printf("\nEnter the Roll No. : ");
  scanf("%d",&A->roll);
  while ((getchar()) != '\n');
  printf("Enter the Name : ");
  scanf("%s",str);
  strcpy(A->name,str);
  printf("Enter the 1st Mark : ");
  scanf("%f",&t);
  if(t>100 && t<0)    printf("Marks should be between 0-100...!!");
  else  A->m1=t;
  printf("Enter the 2nd Mark : ");
  scanf("%f",&t);
  if(t>100 && t<0)    printf("Marks should be between 0-100...!!");
  else  A->m2=t;

  A->percent = (A->m1 + A->m2)/2;

  return A;
}

void display(rec *A)
{
  printf("\n\nRoll No.  : %d",A->roll);
  printf("\nName      : %s",A->name);
  printf("\nMark 1    : %.2f",A->m1);
  printf("\nMark 2    : %.2f",A->m2);
  printf("\nPercentage: %.2f%%",A->percent);
}



void displaytbl()
{
  int i=0;;
  rec p;
  FILE *fp;

  fp = fopen("student.dat","r");

  if(fp==NULL)  printf("\nFile Error....!");

  printf("\n\n*******************************************************");
  printf("\n%-4s%-10s%-15s%8s%8s%8s\n","No.","Roll No.","Name","M 1","M 2","%%");

  while(feof(fp)==0)
  {
    fscanf(fp,"\n %10d %15s %8f %8f %8f",&p.roll,p.name,&p.m1,&p.m2,&p.percent);
    printf("\n%-4d%-10d%-15s%8.2f%8.2f%8.2f",(i+1),p.roll,p.name,p.m1,p.m2,p.percent);
    i++;
  }
  printf("\n*******************************************************");

  fclose(fp);

}

void search()
{
  rec *p;
  p=(rec *)malloc(sizeof(rec));
  FILE *fp;
  int f=0,key;

  fp=fopen("student.dat","r");

  if(fp==NULL)  printf("\nFile Error....!");

  printf("\nEnter the Roll No. to search : ");
  scanf("%d",&key);

  while(feof(fp)==0)
  {
    fscanf(fp,"\n %10d %15s %8f %8f %8f",&p->roll,p->name,&p->m1,&p->m2,&p->percent);
    if(p->roll==key)
    {
      display(p);
      f++;
    }
  }

  free(p);

  if(f==0)  printf("\nRecord not found....!");
  fclose(fp);

}

void entry()
{
  rec *p;
  p=(rec *)malloc(sizeof(rec));
  FILE *fp;
  fp = fopen("student.dat","w");
  char ans='y';
  if(fp==NULL)  printf("\nFile Error....!");
  while(ans=='y')
  {
    p=input();
    fprintf(fp,"\n %10d %15s %8.3f %8.3f %8.3f",p->roll,p->name,p->m1,p->m2,p->percent);
    while ((getchar()) != '\n');
    printf("\nDo you want to add more data(y/n) : ");
    scanf("%c",&ans);
  }

  fclose(fp);
}

void insert()
{
  rec *p;
  p=(rec *)malloc(sizeof(rec));
  FILE *fp;
  fp = fopen("student.dat","a");

  if(fp==NULL)  printf("\nFile Error....!");

  p=input();
  fprintf(fp,"\n %10d %15s %8.3f %8.3f %8.3f",p->roll,p->name,p->m1,p->m2,p->percent);

  fclose(fp);
}

void delete()
{
  int key,f=0;
  rec *p;
  p=(rec *)malloc(sizeof(rec));
  char ans;
  FILE *fp1,*fp2;

  fp1 = fopen("student.dat","r");
  fp2 = fopen("temp.dat","w");

  if(fp1==NULL)  printf("\nFile Error....!");

  printf("\nEnter the Roll No. to delete : ");
  scanf("%d",&key);


  while(feof(fp1)==0)
  {
    fscanf(fp1,"\n %10d %15s %8f %8f %8f",&p->roll,p->name,&p->m1,&p->m2,&p->percent);
    if(p->roll==key)
    {
      display(p);
      printf("\nDo you want to delete(y/n) : ");
      while ((getchar()) != '\n');
      scanf("%c",&ans);
      f++;
      if(ans!='y')      fprintf(fp2,"\n %10d %15s %8.3f %8.3f %8.3f",p->roll,p->name,p->m1,p->m2,p->percent);

    }
    else
    fprintf(fp2,"\n %10d %15s %8.3f %8.3f %8.3f",p->roll,p->name,p->m1,p->m2,p->percent);

  }

  fclose(fp1);
  fclose(fp2);

  remove("student.dat");
  rename("temp.dat","student.dat");

  free(p);

  if(f==0)  printf("\nRecord not found....!");
}

rec * edit(rec *A)
{
  char str[10];
  while ((getchar()) != '\n');
  printf("Enter the Name : ");
  scanf("%s",str);
  strcpy(A->name,str);
  printf("Enter the 1st Mark : ");
  scanf("%f",&A->m1);
  printf("Enter the 2nd Mark : ");
  scanf("%f",&A->m2);

  A->percent = (A->m1 + A->m2)/2;

  return A;
}

void modify()
{
  int key,f=0;
  rec *p;
  p=(rec *)malloc(sizeof(rec));
  char ans;
  FILE *fp1,*fp2;

  fp1 = fopen("student.dat","r");
  fp2 = fopen("temp.dat","w");

  if(fp1==NULL)  printf("\nFile Error....!");

  printf("\nEnter the Roll No. to modify : ");
  scanf("%d",&key);


  while(feof(fp1)==0)
  {
    fscanf(fp1,"\n %10d %15s %8f %8f %8f",&p->roll,p->name,&p->m1,&p->m2,&p->percent);
    if(p->roll==key)
    {
      display(p);
      printf("\nDo you want to modify(y/n) : ");
      while ((getchar()) != '\n');
      scanf("%c",&ans);
      f++;
      if(ans!='y')      fprintf(fp2,"\n %10d %15s %8.3f %8.3f %8.3f",p->roll,p->name,p->m1,p->m2,p->percent);
      else
      {
        p=edit(p);
        fprintf(fp2,"\n %10d %15s %8.3f %8.3f %8.3f",p->roll,p->name,p->m1,p->m2,p->percent);
      }
    }
    else
    fprintf(fp2,"\n %10d %15s %8.3f %8.3f %8.3f",p->roll,p->name,p->m1,p->m2,p->percent);
  }

  fclose(fp1);
  fclose(fp2);

  remove("student.dat");
  rename("temp.dat","student.dat");

  free(p);

  if(f==0)  printf("\nRecord not found....!");
}



int menu()
{
  int o=0,o1;

  printf("\n***************************\n");

  printf("\n1.Create Database");
  printf("\n2.Display Database");
  printf("\n3.Display Record");
  printf("\n4.Insert Record");
  printf("\n5.Delete Record");
  printf("\n6.Modify Record");
  printf("\n0.Exit");
  printf("\n\nEnter your choice : ");
  scanf("%d",&o1);

  if(o1==0)  exit(0);
  else if(o1>-1 && o1<7)  {}
  else printf("\nERROR...!!!");

  return o1;
}



int main(int argc, char const *argv[]) {

  int o=4;

  while(o!=0)
  {
    o=menu();
    switch(o)
    {
      case 1 :  entry();
                break;
      case 2 :  displaytbl();
                break;
      case 3 :  search();
                break;
      case 4 :  insert();
                break;
      case 5 :  delete();
                break;
      case 6 :  modify();
                break;
    }
  }

  return 0;
}

