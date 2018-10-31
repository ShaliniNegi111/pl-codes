#include<stdio.h>
#include<stdlib.h>
int r1 , c1 , r2 , c2 ;
void display ( int ** m , int r  , int c )
{
    int i , j ;
    for ( i = 0 ; i <  r ; i ++ )
    {

        for(  j = 0 ; j < c ; j ++ )
            printf("%d\t" , m [ i ] [ j ] ) ;
        printf("\n" );
    }
}

int ** add ( int **m1 , int ** m2 , int n1 , int n2 )
{

     int i , j , k;
     int **  ans = ( int ** ) malloc ( n1 *( sizeof( int * ) ) ) ;
     for ( i = 0 ; i < n1 ; i ++ )
            ans [ i ] = ( int * ) malloc ( n2 * ( sizeof( int ) ) ) ;
     for(  i = 0 ; i < n1 ; i ++ )
     {
         for ( j = 0 ; j < n2 ; j ++ )
         {
             ans [ i ] [ j ] = m1 [ i ][ j ] + m2 [ i ] [ j ] ;
         }
     }
     return ans ;

}
int ** multiplication ( int ** m1 , int ** m2 , int r1 ,int c1 ,  int c2 )
{

    int i , j , k ;
     int **  m3 = ( int ** ) malloc ( r1 *( sizeof( int * ) ) ) ;
     for ( i = 0 ; i < r1 ; i ++ )
            m3 [ i ] = ( int * ) malloc ( c2 * ( sizeof( int ) ) ) ;
    for ( i = 0 ; i < r1 ; i ++ )
    {
        for (  j = 0 ; j < c2 ; j ++ )
        {
            m3 [ i ] [ j] = 0 ;
            for ( k = 0 ; k < c1 ; k ++ )
                m3[ i ] [ j ]+= m1[ i ] [ k ] * m2 [ k ] [ j ] ;
        }
    }
    return m3 ;
}

void saddlepoint ( int ** a , int r , int c )
{
    int row [ r ] ;
    int ind , i , j ;
    for ( i = 0 ; i < r ; i ++ )
    {
        int mini = a [ i ] [ 0 ] ;
        for (  j = 0 ; j < c ; j ++)
        {
            if ( a[ i ] [ j ] <= mini )
            {
                mini = a [ i ] [ j ] ;
                ind = j ;
            }
        }
        row [ i ] = ind ;
    }


    for ( i = 0 ; i < r ; i ++ )
    {
        int maxi = a [ i ] [ 0 ] ;
        for (j = 0 ; j < r ; j ++ )
        {
            if ( a [ j ] [ row [ i ]]  >= maxi )
                maxi = a [ j ] [ row [ i ]] ;
        }
        if ( maxi == a [ i ] [ row [ i ] ] )
        {
            printf("saddle point found at %d %d\n "  , i ,row [ i ] ) ;
            return ;
        }
    }
    printf("SADDLE POINT NOT FOUND \n " ) ;
}

int main()
{
    char ch ;
    int ** m1 , ** m2 ,**m3 ,  i , j , c ;
    printf("ENTER THE RAW AND COLOUM OF FIRST MATRIX \n " );
    scanf("%d %d" , &r1 , &c1 ) ;
    m1 = ( int ** ) malloc ( r1 *( sizeof( int * ) ) ) ;
    for ( i = 0 ; i < r1 ; i ++ )
        m1 [ i ] = ( int * ) malloc ( c1 * ( sizeof( int ) ) ) ;
    printf("ENTER THE RAW AND COLOUM OF SECOND MATRIX \n " );
    scanf("%d %d" , &r2 , &c2 ) ;
     m2 = ( int ** ) malloc ( r2 *( sizeof( int * ) ) ) ;
    for ( i = 0 ; i < r2 ; i ++ )
        m2 [ i ] = ( int * ) malloc ( c2 * ( sizeof( int ) ) ) ;
    printf("ENTER THE FIRST MATRIC \n " );
    for (i = 0 ; i < r1 ; i ++ )
    {
        for ( j = 0 ; j < c1 ; j ++ )
            scanf("%d" , &m1 [ i ] [ j ] ) ;
    }
    printf("ENTER THE SECOND MATRIC \n " );
    for (i = 0 ; i < r2 ; i ++ )
    {
        for ( j = 0 ; j < c2 ; j ++ )
            scanf("%d" , &m2 [ i ] [ j ] ) ;
    }
    printf("FIRST MATRIX IS \n " );
    display ( m1 , r1 , c1 ) ;
    printf("SECOND MATRIX IS \n ");
    display ( m2 , r2 , c2 ) ;
    do{
        printf("1.ADDITION \n 2. MULTIPLICATION \n 3. SADDLE POINT \n 4. TRANSPOSE \n " ) ;
        scanf("%d" , &c   ) ;
        switch ( c )
        {
            case 1 : m3 = add( m1 , m2 , r1 , c1 ) ;
                     display ( m3 , r1 ,  c1   ) ;
                     break ;
            case 3 : saddlepoint ( m1 , r1 ,c1 ) ;
                     saddlepoint ( m2 , r2 , c2 ) ;
                     break ;
            case 2 :
                     m3 = multiplication ( m1 , m2 , r1 ,c1 ,  c2 ) ;
                     display ( m3 , r1 , c2  ) ;
                     break ;

        }
        getchar () ;
        printf("PRESS Y OR y TO CONTINUE \n " ) ;
        scanf("%c" , &ch ) ;
    }while ( ch == 'y' ||  ch == 'Y' ) ;




}
