#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void display ( char s [ 100 ] [ 100 ] , int n )
{
    int i ;
    for ( i = 0 ; i < n ; i ++ )
       printf("%s\t" , s[ i ] ) ;
    printf("\n") ;

}
void bubblesort( char s [ 100 ] [ 100 ] , int n )
{
    char temp [ 1 ] [ 100 ] ;
    int i , j ;
    for ( i = 0 ; i < n ; i ++ )
    {
        for ( j = 0 ; j < n - i - 1 ; j ++ )
        {
            if ( strcmp ( s[ j ] , s [ j +1 ] ) > 0 )
            {
                strcpy ( temp , s [ j ] ) ;
                strcpy ( s [ j ] , s[ j + 1 ] ) ;
                strcpy ( s [ j +1 ] , temp  ) ;
            }
        }
        printf(" string after %d pass is as follow \n " , i + 1 ) ;
        display ( s , n ) ;
    }
}

void selectionsort ( char s [ 100 ] [ 100 ] , int n )
{
    int i , j , ind ;
    char temp [ 1 ] [ 100 ] , val [ 1 ] [ 100 ];
    for ( i =0 ; i < n ; i ++ )
    {
        strcpy(val , s [ i ]) ;
        for ( j = i ; j < n ; j ++ )
        {
            if ( strcmp ( s [ j ] , val ) > 0 )
            {
                strcpy (val , s[ j ] ) ;
                ind = j ;
            }
        }
        strcpy ( temp , s [ ind ] ) ;
        strcpy ( s [ ind ] , s[ i ] ) ;
        strcpy ( s [ i ] , temp  ) ;
        printf(" string after %d pass is as follow \n " , i + 1 ) ;
        display ( s , n ) ;
    }
}

void insertionsort ( char s [ 100 ] [ 100 ] , int n )
{
    int i , j , ind ;
    char temp [ 1 ] [ 100 ] , val [ 1 ] [ 100 ];
    for ( i =0 ; i < n ; i ++ )
    {
        strcpy(val , s [ i ]) ;
        j = i -1 ;
        while ( j >=0 && strcmp ( s [ j ] , val )< 0 )
        {
            strcpy ( s [ j + 1] ,s [ j ] ) ;
            j --;
        }
        strcpy ( temp , s [ j+1 ] ) ;
        strcpy ( s [ j+1 ] ,val ) ;
        strcpy ( val , temp  ) ;
        printf(" string after %d pass is as follow \n " , i + 1 ) ;
        display ( s , n ) ;
    }
}

int binary( char s1[ 100 ] [ 100 ] ,char word[ 1 ] [ 100 ] ,int  n1 )
{
    int start = 0 , end = n1 ;
    while ( start <= end )
    {
        int mid = ( start + end ) / 2 ;
        if ( strcmp(s1 [ mid ] , word) == 0  ) return mid ;
        else if ( strcmp(s1 [ mid ] ,word ) > 0 ) end = mid -1 ;
        else start = mid + 1 ;
    }
    return -1 ;


}

int rbinary( char s1[ 100 ] [ 100 ] ,char word[ 1] [ 100 ] ,int  start , int end  )
{

    if ( start <= end )
    {
        int mid = ( start + end ) / 2 ;
        if ( strcmp(s1 [ mid ] , word) == 0  ) return mid ;
        else if ( strcmp(s1 [ mid ] ,word ) > 0 ) return rbinary(s1 , word , start , mid -1 );
        else return rbinary(s1 , word , mid+1 , end );
    }
    return -1 ;
}

int main()
{
    char s1 [ 100 ] [ 100 ] , s2 [ 100 ] [ 100 ], s3 [ 100 ] [ 100 ] , word [ 1] [ 100 ] , ch ;
    int n1 , n2 , i , j , c , fpos ;
    printf("ENTER THE NO OF WORDS IN FIRST STRING \n " );
    scanf("%d" , & n1) ;
    printf("ENTER THE  FIRST STRING \n " );
    for ( i = 0 ; i < n1 ; i ++ )
        scanf("%s" , s1[ i ] );
    printf("FIRST STRING IS \n " ) ;
    display ( s1 , n1 ) ;
    for ( i = 0 ; i < n1 ; i ++ )
    {
        strcpy ( s2 [ i ] ,s1[ i ] ) ;
        strcpy ( s3 [ i ] ,s1[ i ] ) ;
    }
    printf("\n") ;
    do{
            printf("1.ACCENDING ORDER USING BUBBLE SORT \n 2.DECENDING USING SELECTION SORT \n 3.DECENDING USING INSERTION SORT \n 4.BINARY SEARCH RECURSION \n 5.NON RECURSION\n");
            scanf("%d" , &c ) ;
            switch ( c )
            {
                case 1: bubblesort ( s1 , n1 ) ;
                        break ;
                case 2: selectionsort( s2 , n1 ) ;
                        break ;
                case 3: insertionsort( s3 , n1 ) ;
                        break ;
                case 4 : //bubblesort ( s1 , n1 ) ;
                         printf("ENTER THE WORD TO BE SEARCHED \n " );
                         scanf("%s" , word ) ;
                         fpos = rbinary( s1 , word , 0 , n1 ) ;
                         if (fpos == -1)
                            printf("NOT FOUND \n " ) ;
                         else
                            printf("found at %d" , fpos ) ;
                         break ;
                case 5 : //bubblesort ( s1 , n1 ) ;
                         printf("ENTER THE WORD TO BE SEARCHED \n " );
                         scanf("%s" , word ) ;
                         fpos = binary( s1 , word , n1 ) ;
                         if (fpos == -1)
                            printf("NOT FOUND \n " ) ;
                         else
                            printf("found at %d" , fpos ) ;
                         break ;

            }
            getchar() ;
            printf("press y or Y to continue \n " ) ;
            scanf("%c" , &ch ) ;
    }while ( ch == 'Y' || ch =='y' ) ;

}
