#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n1 , n2 , a [ 100 ] , b [ 100 ] , i , j , c1 , ans [ 100 ] , ans1[ 100 ] , ans2 [ 100 ] , c3 ;
int hashn1[ 100 ] , hashp1[ 100 ] , hashn2[ 100 ] , hashp2[ 100 ];
char ch ;
void display ( int arr [ 100 ]  )
{
    printf("ARRAY IS AS FOLLOW \n " );
    for ( i = 0 ; arr[i] !='\0' ; i ++ )
            printf("%d\t" , arr [ i ] ) ;
    printf("\n") ;
}

void unionofset ( int a [ 100 ] , int b [ 100 ] , int  c [ 100 ], int n1 ,int  n2 )
{
    memset ( c , 0 , sizeof(c) ) ;
    memset ( hashn1 , 0 , sizeof( hashn1) ) ;
    memset ( hashp1 , 0 , sizeof( hashp1) ) ;
    memset ( c , 0 , sizeof( c) ) ;
    int s = 0 ;
    for ( i = 0 ; i < n1 ; i ++ )
    {
        if ( a [ i] >= 0 && hashp1 [ a [ i ] ] == 0 )
        {
            c [ s ] = a [ i ] ;
            s ++ ;
            hashp1 [ a [ i ] ]++ ;
        }
        else if ( a [ i] < 0 && hashn1 [ abs(a [ i ]) ] == 0 )
        {
            c [ s ] = a [ i ] ;
            s ++ ;
            hashn1 [ abs(a [ i ]) ] ++ ;
        }
    }
    for ( i = 0 ; i < n2 ; i ++ )
    {
        if ( b [ i] >= 0 && hashp1 [ b [ i ] ] == 0 )
        {
            c [ s ] = b [ i ] ;
            s ++ ;
            hashp1 [ b[ i ] ]++ ;
        }
        else if (b [ i] < 0 && hashn1 [ abs(b [ i ]) ] == 0 )
        {
            c [ s ] = b[ i ] ;
            s ++ ;
            hashn1 [ abs(b [ i ]) ] ++ ;
        }
    }
    c [ s ] ='\0' ;
}


void intersection ( int a [ 100 ] , int b [ 100 ] , int  c [ 100 ], int n1 , int n2 )
{
    memset ( c , 0 , sizeof(c) ) ;
    memset ( hashn1 , 0 , sizeof( hashn1) ) ;
    memset ( hashp1 , 0 , sizeof( hashp1) ) ;
    memset ( hashn2 , 0 , sizeof( hashn2) ) ;
    memset ( hashp2 , 0 , sizeof( hashp2) ) ;
    memset ( c , 0 , sizeof( c) ) ;
    int s = 0 ;
    for ( i = 0 ; i < n1 ; i ++ )
    {
        if ( a [ i] >= 0 )
            hashp1 [ a [ i ] ]++ ;
        else if ( a [ i] < 0 )
            hashn1 [ abs(a [ i ]) ] ++ ;
    }

    for ( i = 0 ; i < n2 ; i ++ )
    {
        if ( b [ i] >= 0  )
            hashp2 [ b[ i ] ]++ ;
        else if ( b [ i] < 0  )
            hashn2 [ abs(b [ i ]) ] ++ ;
    }
    for( i = 0 ; i < 100 ; i ++ )
    {

        if ( hashp1 [ i ] != 0 && hashp2 [ i ] != 0 )
        {
            c [ s ] = i ;
            s ++ ;
        }
        else if ( hashn1 [ i ] != 0 &&  hashn2 [ i ] != 0 )
        {
            c [ s ] = -i ;
            s++ ;
        }
    }
    c [ s ] = '\0' ;

}

void differene( int a [ 100 ] , int b [ 100 ] , int c [ 100 ] , int n1 , int n2 )
{
    memset ( c , 0 , sizeof(c) ) ;
    memset ( hashn1 , 0 , sizeof( hashn1) ) ;
    memset ( hashp1 , 0 , sizeof( hashp1) ) ;
    memset ( hashn2 , 0 , sizeof( hashn2) ) ;
    memset ( hashp2 , 0 , sizeof( hashp2) ) ;
    memset ( c , 0 , sizeof( c) ) ;
    int s = 0 ;
    for ( i = 0 ; i < n1 ; i ++ )
    {
        if ( a [ i] >= 0 )
            hashp1 [ a [ i ] ]++ ;
        else if ( a [ i] < 0 )
            hashn1 [ abs(a [ i ]) ] ++ ;
    }

    for ( i = 0 ; i < n2 ; i ++ )
    {
        if ( b [ i] >= 0  )
            hashp2 [ b[ i ] ]++ ;
        else if ( b [ i] < 0  )
            hashn2 [ abs(b [ i ]) ] ++ ;
    }

    for( i = 0 ; i < 100 ; i ++ )
    {

        if ( hashp1 [ i ] != 0 && hashp2 [ i ] == 0 )
        {
            c [ s ] = i ;
            s ++ ;
        }
        else if ( hashn1 [ i ] != 0 &&  hashn2 [ i ] == 0 )
        {
            c [ s ] = -i ;
            s++ ;
        }
    }
    c [ s ] = '\0' ;
}


 void symm_diff ( int ans1[ 100 ] , int ans2[ 100 ]  )
 {
     for ( i = 0 ; ans1 [ i ] != '\0' ; i ++ )
        printf("%d\t" , ans1 [ i ] ) ;
     for ( i = 0 ; ans2 [ i ] != '\0' ; i ++ )
        printf("%d\t" , ans2 [ i ] ) ;
 }
int main()
{

        printf("ENTER THE SIZE OF FIRST SET \n " );
        scanf("%d" , &n1 ) ;
        printf("ENTER THE SIZE OF SECOND SET \n " );
        scanf("%d" , &n2 ) ;
        printf("ENTER THE FIRST SET \n " );
        for ( i = 0 ; i < n1 ; i ++ )
            scanf("%d" , &a [ i ] ) ;
        a [ n1 ] ='\0';
        display ( a ) ;
        printf("ENTER THE SECOND SET \n " );
        for ( i = 0 ; i <n2 ; i ++ )
            scanf("%d" , &b[ i ] ) ;
        b [ n2 ] = '\0' ;
        display ( b  );
        do{
            printf("1.UNION \n 2.INTERSECTION \n 3.DIFFERNCE \n 4.SYMMETRIC DIFFERNCE \n " ) ;
            scanf("%d" , &c1 ) ;
            switch ( c1 )
            {
                   case 1: unionofset ( a , b , ans , n1 , n2 ) ;
                           display ( ans ) ;
                           break ;
                   case 2: intersection ( a , b ,ans ,  n1 , n2 ) ;
                           display( ans );
                            break ;
                   case 3: printf("1.A-B \n 2.B-A \n " );
                          scanf("%d" , &c3) ;
                          if (c3 == 1 )
                              differene ( a , b , ans , n1 , n2 ) ;
                          else
                               differene ( b, a , ans , n2 , n1 ) ;
                          display ( ans ) ;
                          break ;
                   case 4: differene ( a , b , ans1 , n1 , n2 ) ;
                           differene ( b, a , ans2 , n2 , n1 ) ;
                           symm_diff ( ans1 , ans2  ) ;
                           break ;
            }
            getchar() ;
            printf("PRESS Y or y to continue\n " ) ;
            scanf("%c" , &ch ) ;
        }while ( ch == 'Y' || ch =='y' ) ;


}
