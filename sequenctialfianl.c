#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ch , ch1;
int c , n ;
typedef struct student student ;
struct student
{
    char name [ 50 ] ;
    int roll ;
    float marks , per;
};
void input( student * s )
{
    printf("ENTER THE NAME OF STUDENT \n " ) ;
    scanf("%s" , s-> name ) ;
    printf("ENTER THE ROLL OF STUDENT \n " ) ;
    scanf("%d" , &s-> roll ) ;
    printf("ENTER THE MARKS OF STUDENT \n " ) ;
    scanf("%f" , &s-> marks ) ;
    printf("ENTER THE PERCENTAGE OF STUDENT \n " ) ;
    scanf("%f" , &s-> per ) ;

}

void display ( student * s )
{
    printf(" NAME OF STUDENT \n " ) ;
    printf("%s\n" , s-> name ) ;
    printf(" THE ROLL OF STUDENT \n " ) ;
    printf("%d\n" , s-> roll ) ;
    printf(" THE MARKS OF STUDENT \n " ) ;
    printf("%f\n" , s-> marks ) ;
    printf(" THE PERCENTAGE OF STUDENT \n " ) ;
    printf("%f\n" , s-> per ) ;
    printf("\n---------------------------------------------------------------------------\n") ;
}
void create()
{
    FILE * fp ;
    fp = fopen ( "studentlucky.txt" , "w" ) ;
    if ( fp ==NULL )
        printf("ERROR \n " ) ;
    student * s ;
    s = ( student *) malloc ( sizeof (student ) ) ;
    do{
        input(s) ;
        fprintf(fp , "%s  %d  %f  %f " , s-> name , s->roll , s->marks , s->per ) ;
        getchar () ;
        printf("ENTER Y OR y TO CONTINUE \n " ) ;
        scanf("%c" , &ch1 ) ;
    }while ( ch1 == 'Y' || ch1 == 'y' ) ;

    fclose(fp) ;
}

void displaydata()
{
    student s ;
    FILE * fp;
    fp = fopen("studentlucky.txt" , "r") ;
    if ( fp ==NULL )
    {
         printf("ERROR \n " );
         return ;
    }
    while ( feof(fp)==0)
    {
        fscanf(fp , "%s %d %f %f " , s.name , &s.roll, &s.marks, &s.per) ;
        printf("%s %d %f %f " , s.name , s.roll, s.marks, s.per);

        printf("\n---------------------------------------------------------------------------\n") ;
    }
    fclose( fp ) ;
}


void displayrecord()
{
    int n , flag = 0 ;
    printf("NETR THE ROLL NO OF STUDENT \n" );
    scanf("%d" , &n ) ;
    student *s ;
    s = ( student *) malloc ( sizeof(student)) ;
    FILE * fp;
    fp = fopen("studentlucky.txt" , "r") ;
    if ( fp ==NULL )
    {
         printf("ERROR \n " );
         return ;
    }
    while ( feof(fp)==0)
    {
        fscanf(fp , "%s %d %f %f " , s->name , &s->roll, &s->marks, &s->per) ;
        if ( s->roll == n )
        {
            display( s ) ;
            flag = 1 ;
            break ;
        }
        printf("---------------------------------------------------------------------------") ;
    }
    if ( flag == 0 ) printf("RECORD NOT FOUND \n " ) ;
    fclose( fp ) ;
}

void insertrecord()
{

    FILE * fp ;
    fp = fopen ( "studentlucky.txt" ,  "a" ) ;
    if ( fp ==NULL )
        printf("ERROR \n " ) ;
    student * s ;
    s = ( student *) malloc ( sizeof (student ) ) ;
    input(s) ;
    fprintf(fp , "%s  %d  %f  %f " , s-> name , s->roll , s->marks , s->per ) ;
    fclose(fp) ;
}

void delete_record()
{
    int n , flag = 0 ;
    printf("NETR THE ROLL NO OF STUDENT \n" );
    scanf("%d" , &n ) ;
    FILE * fp1 , *fp2;
    fp1 = fopen ( "studentlucky.txt" ,  "r" ) ;
    fp2= fopen ( "temp.txt" ,  "w" ) ;
    if ( fp1 ==NULL )
        printf("ERROR \n " ) ;
    student * s ;
    s = ( student *) malloc ( sizeof (student ) ) ;
    while ( feof(fp1)==0)
    {
        fscanf(fp1 , "%s %d %f %f " , s->name , &s->roll, &s->marks, &s->per) ;
        if ( s->roll !=n )
        {
            fprintf(fp2 , "%s  %d  %f  %f " , s-> name , s->roll , s->marks , s->per ) ;
        }
        else flag = 1 ;
    }
    fclose(fp1) ;
    fclose(fp2) ;

    remove("studentlucky.txt");
    rename("temp.txt" , "studentlucky.txt");
    free(s) ;
    if ( flag == 0 ) printf("RECORD NOT FOUND \n " ) ;

}

int main()
{
    do{
        printf("1.CREATE DATABASE \n 2.DISPAY DATABASE \n 3.DISPLAY RECORD \n 4.INSERT RECORDS \n 5 .DELETE RECORD \n 6.MODIFY RECORD \n " );
        scanf("%d" , &c) ;
        switch ( c )
        {
                case 1: create() ;
                        break ;
                case 2: displaydata() ;
                        break ;
                case 3:displayrecord() ;
                        break ;
                case 4:insertrecord() ;
                       break ;
                case 5:delete_record() ;
                        break ;
                case 6 :modify_record() ;
                        break ;

        }
        getchar() ;
        printf("ENTER Y OR y TO CONTINUE \n " ) ;
        scanf("%c" , &ch ) ;
    }while ( ch == 'Y' ||  ch == 'y' ) ;
    return 0;
}

