#include<stdio.h>
#include<stdlib.h>
int pass  , n , arr [ 10001 ];
void merge (  int l [ ] , int r [ ] , int n1 , int n2 )
{
    int i = 0 , j = 0 , k = 0 ;
    while ( i < n1  && j < n2 )
    {
        if ( l [ i ] <= r [ j ] )
        {
            arr [ k ] = l [ i ] ;
            i ++ , k ++ ;
        }
        else
        {
            arr [ k ] = r [ j ] ;
            j ++ , k ++ ;
        }
    }

    while ( i < n1 )
    {
           arr [ k ] = l [ i ] ;
            i ++ , k ++ ;
    }

    while ( j < n2 )
    {
            arr [ k ] = r [ j ] ;
            j ++ , k ++ ;
    }

}
void mergesort ( int arr1 [ ]  , int N   )
{
   int k ;
   pass ++ ;
   printf("ARRAY AFTER PASS NO %d IS\n " , pass ) ;
   for ( k = 0 ; k < n ; k ++ )
        printf ("%d \t" , arr [ k ] ) ;
   printf("\n") ;
   if ( N < 2 ) return ;
   int mid = N / 2 ;
   int n1 , n2 , i  , j ;
   int l [ mid ], r [ N - mid ] ;
   for ( i = 0 ; i < mid ; i ++ ) l [ i ] = arr1 [ i ] ;
   for ( j = mid ; j < N ; j ++ ) r [ j - mid  ] = arr1 [ j  ] ;
   mergesort ( l  , mid  );
   mergesort ( r , N - mid  );
   merge (  l , r , n1 , n2 ) ;

}
int main ()
{
    int i , k ;
    printf("ENTER THE NO OF ELEMENTS \n " ) ;
    scanf("%d" , &n ) ;
    printf("ENTER THE  ELEMENTS OF ARRAY \n " ) ;
    for ( i = 0 ; i < n ; i ++ )
        scanf ("%d" , &arr [ i ] ) ;
    for ( i = 0 ; i < n ; i ++ )
        printf ("%d \t" , arr [ i ] ) ;
    printf("\n") ;
    mergesort ( arr , n ) ;
}



