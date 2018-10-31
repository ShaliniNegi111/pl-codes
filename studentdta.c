#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ch , ch1 ;
int n , i , c , pos , r , flag , j ;
typedef struct student student ;
struct student
{
    char name [ 20] ;
    int roll ;
    float marks , per;
};
void input( student * s )
{
                        printf("ENTER THE NAME OF STUDENT \n" ) ;
                        scanf("%s" , s->name ) ;
                        printf("ENTER THE ROLL NO  OF STUDENt\n " ) ;
                        scanf("%d" , &s->roll ) ;
                        printf("ENTER THE marks  OF STUDENT \n" ) ;
                        scanf("%f" , &s->marks ) ;
                        printf("ENTER THE PERCENTAGE  OF STUDENT \n" ) ;
                        scanf("%f" , &s->per) ;
}
int main()
{
    printf("ENTER THE TOTAL NO OF STUDENT \n " ) ;
    scanf("%d" , &n ) ;
    student *s;
    s = ( student *) malloc ( 20 * sizeof (student ) ) ;
    do{
        printf("1.CRETE DATABASE \n 2.DISPLAY \n 3.ADD NEW RECORD \n 4.MODIFY \n 5.DELETE \n " ) ;
        scanf("%d" , &c ) ;
        switch ( c )
        {
            case 1 :
                    for ( i = 0 ; i < n ; i ++ )
                     input ( ( s + i ) ) ;
                    break ;
            case 2 :
                   for ( i = 0 ; i < n ; i ++ )
                    {
                        printf(" THE NAME OF STUDENT  \n" ) ;
                        printf("%s\n" , (s + i )->name ) ;
                        printf(" THE ROLL NO  OF STUDENT \n" ) ;
                        printf("%d\n" , (s + i )->roll ) ;
                        printf(" THE marks  OF STUDENT \n" ) ;
                        printf("%f\n" , (s + i )->marks ) ;
                        printf("THE PERCENTAGE  OF STUDENT \n" ) ;
                        printf("%f\n" , (s + i )->per) ;
                        printf("--------------------------------------------------------------------------------\n") ;
                    }
                    break ;
           case 3 : printf("ENTER AT WHICH POSTION YOU WANT TO ADD \n " );
                    scanf("%d", &pos ) ;
                    n+= 1 ;
                    for ( i = n ; i >=(pos-1) ; i --)
                    {
                        strcpy(  ( s + i )-> name , ( s + i -1 )-> name );
                        ( s + i )-> roll = ( s + i -1 )-> roll ;
                        ( s + i )-> marks = ( s + i -1 )-> marks ;
                        ( s + i )-> per = ( s + i -1 )-> per;

                    }
                     getchar() ;
                    input(( s + (pos-1) )) ;
                    break ;
          case 4: printf("ENTER AT ROLL NO YOU WANT TO MODIFY \n " );
                  scanf("%d", &r ) ;
                  flag = 0 ;
                  for ( i = 0 ; i < n  ; i ++ )
                    {
                       if ( ( s+ i ) -> roll == r )
                       {
                           flag = 1 ;
                           input ( ( s+ i ) ) ;
                           break ;
                       }
                    }
                    if ( flag == 0 ) printf("RECORD NOT FOUND \n " ) ;
                    break ;
          case 5 : printf("ENTER AT ROLL NO YOU WANT TO DELETE \n " );
                   scanf("%d", &r ) ;
                   flag = 0 ;
                   for ( i = 0 ; i < n  ; i ++ )
                    {
                       if ( ( s+ i ) -> roll == r )
                       {
                            printf("DELETED SUCCESSFULLY \n " ) ;
                           flag = 1 ;
                           for ( j = i  ; j < n - 1  ; i ++ )
                           {
                                strcpy(  ( s + j )-> name , ( s + j+1 )-> name );
                                ( s + j )-> roll = ( s + j+1 )-> roll ;
                                ( s + j )-> marks = ( s + j+1)-> marks ;
                                ( s + j )-> per = ( s + j+1 )-> per;
                           }
                           n -- ;
                           break ;
                       }
                    }
                    if ( flag == 0 ) printf("RECORD NOT FOUND \n " ) ;
                    break ;
        }
        getchar () ;
        printf("PRESS Y or y TO CONTINUE\n " ) ;
        scanf("%c" , &ch ) ;
    }while ( ch == 'Y' || ch == 'y' ) ;

    return 0 ;
}

