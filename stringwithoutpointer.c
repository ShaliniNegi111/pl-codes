#include<stdio.h>
#include<stdlib.h>
char ch , ch1;
int c , i , j , n1 , n2 , c0 , n3;
void enter ( char s[ 50 ])
{

  i = 0 ;
   do
    {
        scanf("%c" , &ch1 );
        s[ i ] = ch1 ;
        i ++ ;
    }while(ch1 != '\n') ;
    s[ i ] = '\0' ;
}

void display ( char  s[ 50 ] )
{
    i = 0 ;
    while ( s [ i ] !='\0')
    {
        printf("%c" , s [ i ] ) ;
        i ++ ;
    }
    printf("\n") ;
}

int length( char  s[50] )
{
    for ( i = 0 ; s [ i ] !='\0' ; i ++ );
    return (i-1) ;
}

int palindrome ( char  s[ 50] , int n )
{

    for ( i = 0 , j = n - 1 ; i < n ; i ++ , j -- )
        if ( s [ i ] != s[ j ] )
            return 0 ;
    return 1 ;
}

void reverse(char  s[ 50] , int n )
{
    for ( i = n - 1 ; i >= 0 ; i -- )
       printf("%c" , s [ i ] ) ;
}


void  substring (char * s2 , char * substr , int n1 , int n2 )
{
    int flag = 0 ;
    for (i = 0 ; i <= (n1 - n2) ; i ++ )
    {
        int k = i ;
        for ( j = 0 ; j < n2 ; j ++ )
        {
            if ( s2[ k ] != substr [ j ] )
                break ;
            else  k ++ ;
        }
        if ( ( k - i ) ==  n2 )
        {
            printf("SUBSTRING FOUND \n" ) ;
            flag = 1 ;
            break ;
        }
    }
    if ( flag == 0 ) printf("SUBSTRING NOT FOUND \n " ) ;
}
int main ()
{
    char s1 [ 50 ] , s2 [ 50 ] , s3 [ 50 ] , substr[ 50] ;
    printf("ENTER FIRST STRING IS \n " ) ;
    enter (s1) ;
    printf("ENTERSECOND STRING IS \n " ) ;
    enter (s2) ;
    printf("FIRST STRING IS \n " ) ;
    display ( s1 ) ;
    printf("SECOND STRING IS \n " ) ;
    display ( s2 ) ;
    do
    {
        printf("1.LENGTH \n 2.PALINDROME \n 3.REVERSE \n  \n 4.SUBSTRING \n " ) ;
        scanf("%d" , &c ) ;
        switch( c )
        {
            case 1: n1 = length( s1 ) ;
                    printf("LENTH OF FIRST STRING IS  %d \n" , n1  ) ;
                    n2 = length( s2 ) ;
                    printf("LENTH OF SECOND STRING IS \%d \n " , n2) ;
                    break ;
            case 2 : if ( palindrome ( s1 , n1 ) )
                        printf("STRING FIRST IS PLAINDROME \n " ) ;
                    else
                        printf("STRING FIRST IS NOT PALINDROME \n " );
                    if ( palindrome ( s2 , n2 ) )
                        printf("STRING SECOND IS PLAINDROME \n " ) ;
                    else
                        printf("STRING SECOND IS NOT PALINDROME \n " );
                    break ;
            case 3 :printf("THE REVERSE OF FIRST STRING IS \n " ) ;
                    reverse ( s1, n1) ;
                    printf("THE REVERSE OF SECOND  STRING IS \n " ) ;
                    reverse ( s2 , n2) ;
                    break ;
            case 4 :printf("ENTER THE CHOICE IN wHICH STRING YOU WAnT TO FIND SUBSTRING \n " ) ;
                    scanf("%d" , &c0) ;
                    if ( c0 == 1 )
                    {
                        getchar() ;
                        printf("ENTER THE SUBTRING TO TO FOUND IN SYTING FIRST \n " ) ;
                        enter (substr) ;
                        n3 = length( substr) ;
                        substring ( s1 , substr , n1 ,n3 ) ;
                    }
                    else
                    {
                        getchar() ;
                        printf("ENTER THE SUBTRING TO TO FOUND IN SYTING FIRST \n " ) ;
                        enter (substr) ;
                        n3 = length( substr) ;
                        substring ( s2 , substr, n2 , n3  ) ;
                    }
                    break ;
        }

        getchar() ;
        printf("PRESS Y OR y TO  CONTINUE \n " ) ;
        scanf("%c" , &ch ) ;
    }while (ch =='Y' ||ch == 'y' ) ;


}

