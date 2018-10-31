#include<stdio.h>
#include<stdlib.h>
int arr [ 10001 ] , n , i , pass ;
void quicksort ( int start , int end  )
{
     pass ++ ;
     printf("ARRAY AFTER PASS %d IS \n" , pass ) ;
     for ( i = 0 ; i < n ; i ++ )
        printf ("%d \t" , arr [ i ] ) ;
    printf("\n");
    int i , j , k , temp ;
    i = start , j = end , k = end  ;
    if ( start < end )
    {
        while ( i < j )
        {

            while ( arr [ k ] > arr [ i ] && i <= end ) i ++ ;
            while ( arr [ k ] < arr [ j ] && j >= start ) j -- ;
            if ( i < j  )
            {
                temp = arr [ i] ;
                arr [ i ] = arr [ j ] ;
                arr [ j ] = temp ;
            }
        }

        temp = arr [ j ] ;
        arr [ j ] = arr [ k ] ;
        arr [ k ] = temp ;
        quicksort (  start , j - 1 )  ;
        quicksort ( j + 1 , end  )  ;
    }


}
int main ()
{

    printf("ENTER THE NO OF ELEMENTS \n " ) ;
    scanf("%d" , &n ) ;
    printf("ENTER THE  ELEMENTS OF ARRAY \n " ) ;
    for ( i = 0 ; i < n ; i ++ )
        scanf ("%d" , &arr [ i ] ) ;
    for ( i = 0 ; i < n ; i ++ )
        printf ("%d \t" , arr [ i ] ) ;
    printf("\n") ;
    quicksort ( 0 , n -1 ) ;
}
