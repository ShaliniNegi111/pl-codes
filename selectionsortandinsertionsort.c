#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i = 0 ;
void swap (  char s1 [  100 ] , char s2 [ 100 ] )
{
     char temp [ 100 ] ;
     strcpy ( temp , s1 ) ;
     strcpy ( s1 , s2 ) ;
     strcpy ( s2 , temp  ) ;

}
char * selectionsort( char s[ 100] [ 100 ] , int n )
{
    int j ;
    for ( i = 0 ; i < n + 1; i ++ )
    {
        for ( j = i  ; j < n + 1 ; j ++ )
        {
            if ( strcmp ( s [ i ] , s [ j ] ) > 1 )
                swap ( s [ i ] , s[ j ] ) ;
        }
    }
}

char * insertionsort( char s[ 100] [ 100 ] , int n )
{
    char temp [ 100 ] ;
    int index ;
    for ( i = 1 ; i < n + 1 ; i ++ )
    {
        strcpy (temp ,  s [ i ] ) ;
        index = i - 1 ;
        while ( index > 0 && strcmp (s [ index ] , temp ) < 0  )
        {
            strcpy ( s [ index + 1 ] , temp );
            index -- ;
        }
        strcpy (s[ index + 1 ] , temp ) ;
        printf("\n Pass %d => ", i);
        display(s,n);
    }
}



char * getstr ()
{

    char * temp , *s , ch ;
    temp =  ( char *) malloc ( 1000 * sizeof ( char ) ) ;
    do
    {
       scanf("%c" , &ch ) ;
       *( temp + i ) = ch;
       i ++ ;
    }while ( ch != '\n') ;

    s = ( char *) malloc ( strlen( temp ) * sizeof ( char ) ) ;
    strcpy ( s , temp ) ;
    s [ i ] = '\0' ;
    free (temp) ;
    return s ;
}

void display (char s [ 100 ] [ 100 ] , int n )
{

    for (i = 0 ; i < n +1  ; i ++ )
            printf("%s " , s[ i ] ) ;
    printf("\n") ;
}

int words ( char * s , char b [ 100 ] [ 100 ] )
{
    int  k = 0 , j = 0 ;
    for ( i = 0 ; i < strlen( s ) ; i ++ )
    {

        if ( s [ i ] != ' ' )
        {
            b [ k ] [ j ] = s [ i ] ;
            j ++ ;
        }
        else
        {
            b [ k ] [ j ] ='\0' ;
            k ++ , j= 0 ;
        }
    }
    return k ;
}
int main ()
{
    int n ;
    char * s , * s1 , * s2 ;
    char b [ 100 ] [ 100] ;
    printf("ENTER THE STRING \n " ) ;
    s = getstr () ;
    printf("ENTERED STRING IS \n " ) ;
    n = words( s , b ) ;
    printf("%d\n" , n  ) ;
    display ( b , n  );
    printf("SELECTION SORTING IS \n " ) ;
    selectionsort( b , n ) ;
    display ( b , n );
    printf("INSERTION SORTING IS \n " ) ;
    insertionsort( b , n ) ;
    display ( b , n );



}
