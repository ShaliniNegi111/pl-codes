#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a [ 100 ] [ 100 ] , b [ 100 ] [ 100 ] , ans [ 100 ] [ 100 ] ;
char ch ;
int c , r1 , r2 , c1 , c2 , i , j , c0 , n ;
void display ( int a[ ] [ 100 ] , int r , int c )
{

    for ( i = 0; i < r ; i ++ )
    {
        for ( j= 0;j < c ; j ++ )
            printf("%d\t" , a [ i ] [ j ]);
        printf("\n") ;
    }
}
void  add ( int a[ ] [100] , int b[ ] [100])
{


    for ( i = 0 ; i < r1 ; i ++ )
    {

        for ( j = 0 ; j < c1 ; j ++ )
            printf("%d\t" , ( a[ i] [ j ] + b [ i ] [ j ])) ;
        printf("\n") ;
    }

}

void  multi (int a [ ] [ 100 ] , int b [ ] [ 100 ] )
{
    int k ;
    int ans [ 100 ] [ 100 ] ;
    for ( i = 0 ; i < r1 ; i++ )
    {

        for( j = 0 ; j < c2 ; j ++ )
        {
            ans [ i ] [ j ] = 0 ;
            for( k=0;k<r1;k++)
                            ans[i][j]=+a[i][k]*b[k][j];
        }
    }

     for ( i = 0 ; i < r1 ; i ++ )
    {

        for ( j = 0 ; j < c1 ; j ++ )
            printf("%d\t" , ans [ i ] [ j ]) ;
        printf("\n") ;
    }


}


void transpose ( int a [ ] [ 100 ] , int r , int c )
{

    for ( i = 0 ; i < r ; i ++ )
    {

        for ( j = 0 ; j < c ; j ++ )
                printf("%d\t" , a [ j ] [ i ] ) ;
        printf("\n") ;
    }
}


void saddle ( int a [ ] [ 100 ] ,  int r , int c )
{
    int arr [ r ] , maxi, indx , mini ;
    for ( i = 0 ; i < r ; i ++ )
    {
        maxi = -124567832;
        for ( j = 0 ; j < c ; j ++ )
        {
            if ( a [ i ] [ j ] > maxi )
            {
                maxi = a [ i ] [ j ] ;
                indx = j ;
            }
        }
        arr [ i ] = indx ;
    }

    int flag = 0 ;
    for ( i = 0 ; i < r ; i ++ )
    {
        int val = a [ i ] [ arr [ i ] ] ;
        mini =  235789 ;
        for ( j = 0 ; j < r ; j++ )
        {
            if ( a [ i ] [ j ] < mini )
                mini = a [ i ] [ j ] ;
        }
        if ( mini == val )
        {
            printf("SADDLE POINT FOUND \n " );
            printf("%d %d" , i , arr [ i ] ) ;
            flag = 1 ;
            break ;
        }
    }
    if ( flag == 0 ) printf("SADDLE POINT NOT FOUND \n " ) ;
}
int main()
{
    printf("ENTER THE ROW AND COLOMN OF FIRST MATRIX \n " ) ;
    scanf("%d %d" , &r1 , &c1 ) ;
    printf("ENTER THE FIRST MATRIX \n " ) ;
    for (  i = 0 ; i < r1 ; i ++ )
    {
        for ( j = 0 ; j < c1 ; j ++ )
            scanf("%d" , &a [ i ] [ j ] ) ;
    }
    display ( a , r1 , c1  ) ;
    printf("ENTER THE ROW AND COLOMN OF SECOND MATRIX \n " ) ;
    scanf("%d %d" , &r2 , &c2 ) ;
    printf("ENTER THE SECOND MATRIX \n " ) ;
     for (  i = 0 ; i < r2 ; i ++ )
    {
        for ( j = 0 ; j < c2 ; j ++ )
            scanf("%d" , &b [ i ] [ j ] ) ;
    }
    display ( b , r2 , c2 ) ;
    do
    {
        printf("1.ADDITION \n 2.MULTIPLICATION \n 3.TRANPOSE \n 4.SADDLE POINT\n " ) ;
        scanf("%d" , &c0 ) ;
        switch( c0 )
        {

                case 1: if ( r1 == r2 && c1 == c2 )
                                add ( a , b ) ;
                        else printf("NOT COMPATIBLE FOR ADDITION \n " ) ;
                        break ;
                case 2: if ( c1 == r1 )
                            multi( a , b ) ;
                        else printf("NOT COMPATIBLE FOR MULTIPLICATION \n " ) ;
                        break ;
                case 3 : printf("ENTER THE CHOICE \n 1.A \n 2.B \n " ) ;
                         scanf("%d" , &n ) ;
                         if ( n == 1 )
                         {
                             if ( r1 == c1 )
                                    transpose ( a , r1 , c1 ) ;
                             else printf("NOT COMPATIBLE FOR TRANSPOSE \n " ) ;
                         }
                         else
                         {
                              if ( r2 == c2 )
                                   transpose ( b , r2 , c2 ) ;
                              else printf("NOT COMPATIBLE FOR TRANSPOSE \n " ) ;
                         }
                         break ;
               case 4 : printf("ENTER THE CHOICE \n 1.A \n 2.B \n " ) ;
                        scanf("%d" , &n ) ;
                        if ( n == 1)
                            saddle ( a , r1 , c1 ) ;
                        else
                            saddle ( b , r2 , c2 ) ;
                        break ;
        }
        getchar() ;
        printf("ENTER Y OR y TO CINTINUE \n " ) ;
        scanf("%c" , &ch ) ;


    }while ( ch == 'Y' || ch=='y' ) ;

}
