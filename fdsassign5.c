#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char * getstr()
{
  int i=0;
  char *B,*A;
  B=(char *)calloc(100,sizeof(char));

  for(i=0;*(B+i-1)!='\n';i++)
  {
    *(B+i)=getchar();
  }
  *(B+i-1)='\0';
  A=(char *)calloc(strlen(B),sizeof(char));
  strcpy(A,B);
  *(A+i-1)='\0';
  free(B);
  return A;
}

void swap(char A[10],char B[10])
{
  char t[10];

  strcpy(t,B);
  strcpy(B,A);
  strcpy(A,t);

}

int words(char *A, char B[10][20])
{
	int s=0,i,j=0;

	for(i=0;;i++)
	{
		if(A[i]!=' ')
    {
			B[s][j]=A[i];
      j++;
		}
		else{
			B[s][j]='\0';
			s++;
			j=0;
    }

		if(A[i]=='\0')
		    break;
	}
	return s;

}

void disp(char A[10][20],int s)
{
  int i;

  for(i=0;i<s+1;i++)
  {
    printf("%s ",A[i]);
  }
}

void bsort(char A[10][20],int s)
{
  int i,j;
  char t;
  printf("\n");

  for(i=0;i<s;i++)
  {
    for(j=1;j<=s;j++)
    {
       if(strcmp(A[j-1],A[j])>0)
       {
         swap(A[j-1],A[j]);
       }
    }
  }
}

void ins_sort(char A[10][20],int s)
{
  int i,j;
  char key[10];

  for (i=1;i<=s;i++)
  {
    strcpy(key,A[i]);
    j=i-1;

    while((j>=0)&&(strcmp(A[j],key)<0))
    {
      strcpy(A[j+1],A[j]);
      j--;
    }

    strcpy(A[j+1],key);

    printf("\n Pass %d => ",i);
    disp(A,s);
  }
}

int search(char A[10][20],int s,char key[10])
{
  int hi=s,lo=0,mid;


  while(hi>=lo)
  {
    mid=(hi+lo)/2;
    if(strcmp(A[mid],key)==0)
    {
      printf("\n");
      return mid;
    }
    else if(strcmp(A[mid],key)>0)
          hi=mid-1;
          else
          lo=mid+1;
  }

  printf("\nWord not found....!");
  return -1;

}



void main()
{
  char *A,B[10][20];
  char key[10];
  int s,loc;

  printf("\nEnter the string to be sorted : ");
  A=getstr();

  s=words(A,B);

  printf("\n\n====Insertion Sort(Decreasing Order)====\n");
  ins_sort(B,s);

  printf("\n\nAfter sorting : ");

  disp(B,s);

  printf("\n\n====Bubble Sort(Increasing Order)====\n");

  bsort(B,s);

  disp(B,s);


  printf("\n\nEnter the word to search : ");
  scanf("%s",key);

  loc=search(B,s,key);

  printf("\nIndex of word = %d\n",loc);

}
