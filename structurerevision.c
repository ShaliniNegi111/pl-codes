#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef  struct  student student ;
struct student
{
    char name [ 30 ] ;
    float marks , percent;
    int roll ;
} ;
void input ( student *s )
{
    printf("ENTER THE NAME OF STUDENT \n " ) ;
    scanf("%s" , s-> name ) ;
    printf("ENTER THE MARKS OF STUDENT \n " ) ;
    scanf("%f" , &s-> marks ) ;
    printf("ENTER THE PERCENT OF STUDENT \n " ) ;
    scanf("%f" , &s->percent ) ;
    printf("ENTER THE ROLL OF STUDENT \n " ) ;
    scanf("%d" , &s-> roll ) ;

}

void display ( student * s )
{
    printf("THE NAME OF STUDENT \n " ) ;
    printf("%s\n" , s-> name ) ;
    printf(" THE MARKS OF STUDENT \n " ) ;
    printf("%f\n" , s-> marks ) ;
    printf(" THE PERCENTAGE OF STUDENT \n " ) ;
    printf ("%f\n" , s->percent ) ;
    printf(" THE ROLL NO OF STUDENT \n " ) ;
    printf("%d\n" , s-> roll ) ;
    printf("\n----------------------------------------------------------\n") ;

}
int main ()
{
    char ch ;
    student *s ;
    s = ( student *) malloc ( 100 * sizeof( student ) ) ;
    int n , i , pos , c , flag = 0 , ind ;
    printf("ENTER HOW MANY RECORD YOU WANT TO ENTER \n " ) ;
    scanf("%d" ,&n ) ;
    for ( i = 0 ; i < n ; i ++ )
        input ( ( s+ i ) ) ;
    do{
          printf("1.DISPLAY DATABASE \n 2. ADD RECORD \n 3.MODIFY RECORD \n 4.DELETE RECORD \n 5.SEARCH \n " );
          scanf("%d" , &c ) ;
          switch ( c )
          {
              case 1 : for ( i = 0 ; i < n ; i ++ )
                            display ( ( s+ i ) ) ;
                        break ;
              case 2 : printf ("ENTER THE POSITION AT WHIC YOU WANT TO INSERT \n " ) ;
                       scanf ("%d" , &pos ) ;
                       for ( i = n ; i >= pos -1 ; i -- )
                       {
                           strcpy(( s + i )-> name ,( s + i -1 ) -> name ) ;
                           ( s+ i ) -> marks = ( s+ i -1 ) ->marks ;
                           ( s+ i ) -> percent = ( s+ i - 1) -> percent ;
                           ( s+ i ) -> roll = ( s+ i - 1) -> roll ;
                       }
                       n+= 1 ;
                       input ( ( s + pos - 1 ) ) ;
                       break ;
             case 3 : flag = 0 ;
                      printf("ENTER THE ROLL NO WHICH YOU WANT TO MOFIFY \n " ) ;
                      scanf("%d" , &pos) ;
                     for ( i = 0 ; i < n ; i ++ )
                     {
                         if ( ( s+ i ) -> roll == pos )
                         {
                             input( ( s+ i ) ) ;
                             flag = 1;
                             break ;
                         }
                     }
                     if ( flag == 0 )
                        printf("RECORD NOT FOUND \n " ) ;
                     break ;
             case 4 : flag = 0 ;
                      printf("ENTER THE ROLL NO WHICH YOU WANT TO DELETE\n " ) ;
                      scanf("%d" , &pos) ;
                     for ( i = 0 ; i < n ; i ++ )
                     {
                         if ( ( s+ i ) -> roll == pos )
                         {
                             ind = i ;
                             flag = 1;
                             break ;
                         }
                     }
                     if ( flag == 1 )
                     {
                         for ( i = ind ; i < n -1 ; i ++ )
                         {
                            strcpy(( s + i )-> name ,( s + i+1 ) -> name ) ;
                           ( s+ i ) -> marks = ( s+ i +1 ) ->marks ;
                           ( s+ i ) -> percent = ( s+ i +1 ) -> percent ;
                           ( s+ i ) -> roll = ( s+ i +1 ) -> roll ;
                         }
                         n-- ;
                     }
                     if ( flag == 0 )
                        printf("RECORD NOT FOUND \n " ) ;
                     break ;
          }
          getchar();
          printf("PRESS Y OR y TO CONTINUE \n " );
          scanf("%c" , &ch );

    }while ( ch == 'Y' ||  ch =='y' ) ;

}
