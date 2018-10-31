#include<stdio.h>
#include<stdlib.h>
typedef long long ll ;
ll arr [ 1000001 ] ;

typedef struct node node ;
struct node
{

    int c , e ;
    node * next ;
};

 node * create ()
 {
     node * head , * ptr ;
     int n , i ;
     printf("ENTER THE NO OF TERMS \n") ;
     scanf("%d" , &n ) ;
     if ( n > 0 )
     {

            head = ( node * ) malloc ( sizeof ( node ) ) ;
            printf("ENTER THE COEFICIENT OF TERMS \n ") ;
            scanf("%d" , &head -> c ) ;
            printf("ENTER THE EXPONENT OF  TERMS \n ") ;
            scanf("%d" , &head -> e ) ;
            ptr = head ;
            for (i = 0 ; i < (n - 1) ; i ++ )
            {

                ptr ->next = ( node *) malloc ( sizeof ( node ) ) ;
                ptr = ptr -> next ;
                printf("ENTER THE COEFICIENT OF TERMS \n") ;
                scanf("%d" , &ptr -> c ) ;
                printf("ENTER THE EXPONENT OF  TERMS \n") ;
                scanf("%d" , &ptr-> e ) ;
            }
            ptr -> next = head ;

     }
     else
            printf (" ERROR \n " ) ;
     return head ;

 }


 node * simplyfy ( node * h1 )
 {

    node * ptr = h1 , * h2 , *h3 , *temp  , *head ;
    ll f = 0 ,  i ;
    do
    {
        arr [ ptr -> e ] += ptr -> c ;
        ptr = ptr -> next ;
        if ( ptr -> next == h1 ) f ++ ;

    }while ( ptr != h1 || f != 1 ) ;
    f = 0 ;
    for ( i = 0 ; i < 100001 ; i ++ )
    {
        if ( arr [ i ] != 0 )
        {
            temp = ( node * ) malloc ( sizeof ( node ) ) ;
            temp -> c = arr [ i ] ;
            temp -> e = i ;
            if ( f == 0 )
            {
                h2 = temp ; // assignment of head
                h3 = temp ; // movement
                f ++ ;
            }
            else
            {
                h3 ->next = temp ;
                h3 = h3 ->next ;
            }
        }
    }
    h3-> next = h2 ;
    return h2 ;
 }


 void display ( node * head )
 {
     node * ptr = head ;
     printf("POLYNOMIAL IS AS FOLLOW \n" ) ;
     while ( ptr -> next != head )
     {
         printf ("%d*x%d+" , ptr->c , ptr->e ) ;
         ptr = ptr -> next ;
     }
    printf ("%d*x%d" , ptr->c , ptr->e ) ;
 }

void evaluate ( node * head )
{
    node * ptr ;
    ptr = head ;
    int x , val = 0  , val1 ;
    printf ("ENTER THE VALUE OF X \n " ) ;
    scanf ("%lld" , &x ) ;
    while ( ptr -> next != head )
    {
        val1 = pow ( x , ptr -> e ) ;
        val += ( (ptr -> c) * val1 ) ;
        ptr = ptr -> next ;
    }
    val1 = pow ( x , ptr -> e  ) ;
    val += ( (ptr -> c) * val1 ) ;
    printf("THE VALUE OF POLYNOMAIL IS %lld " , val ) ;
}

node * add ( node * head1 , node * head2 )
{
    node *h ,  *h1 , * h2 , *temp , *ptr;
    h1 = head1 , h2 = head2 ;
    int f = 0 ,f1 = 0 , f2 = 0 ;
    do
    {
        if ( h1 -> e == h2 -> e )
        {
            temp =  ( node * ) malloc ( sizeof (node) ) ;
            temp -> c =  h1 -> c + h2 -> c ;
            temp -> e =  h1 -> e ;
            h1 = h1 -> next ;
            h2 = h2 -> next ;
        }
        else if ( h1 -> e > h2 -> e)
        {
            temp = ( node * ) malloc ( sizeof (node) ) ;
            temp -> c =  h2 -> c ;
            temp -> e =  h2 -> e ;
            h2 = h2-> next ;
        }
        else
        {
            temp =( node * ) malloc ( sizeof (node) ) ;
            temp -> c =  h1 -> c ;
            temp -> e =  h1 -> e ;
            h1 = h1 -> next ;
        }
        if ( f == 0 )
        {
            h = temp ;
            ptr = temp ;
            f++ ;
        }
        else
        {
            ptr -> next = temp ;
            ptr = ptr -> next ;
        }

        if ( h1 -> next == head1 ) f1++ ;    // if it is in the last node
        if ( h2 -> next == head2 ) f2++ ;   // if it is in the last node

    }while ( ( h1 != head1 && h2 != head2 ) || ( f1!= 1 && f2 != 1 ) )  ;

    if ( h1 == head1 && f1 == 1 ) f1++  ; // end of the link list
    if ( h2 == head2 && f2 == 1 ) f2++ ;  // end of the link list

    if ( f1 != 2 )
    {
        f1 = 0 ;
        do
        {
            temp = ( node * ) malloc ( sizeof (node) ) ;
            temp -> e = h1 -> e ;
            temp -> c = h1 -> c ;
            h1 = h1 -> next ;
            if ( f == 0 )
            {
                h = temp;
                ptr = temp ;
                f++ ;
            }
            else
            {
                ptr -> next = temp ;
                ptr = ptr -> next ;
            }
            if ( h1 -> next == head1 ) f1 ++ ;

        }while ( h1 != head1 || f1 != 1 ) ;

    }

    if ( f1 != 2 )
    {
        do
        {
            temp = ( node * ) malloc ( sizeof (node) ) ;
            temp -> e = h2 -> e ;
            temp -> c = h2 -> c ;
            h2 = h2 -> next ;
            if ( f == 0 )
            {
                h = temp;
                ptr = temp ;
                f++ ;
            }
            else
            {
                ptr -> next = temp ;
                ptr = ptr -> next ;
            }
            if ( h2 -> next == head2 ) f2 ++ ;

        }while ( h2 != head2 || f2 != 1 ) ;

    }
    ptr -> next = h ;
  return h ;
}


node *multiplication  ( node * head1 , node * head2 )
{
    node * h ,  * h1 , *h2 , *temp , *ptr;
    h1 = head1 , h2 = head2 ;
    int f = 0 , f1 = 0 , f2 = 0 ;
    do
    {
        do
        {
            temp = ( node * ) malloc ( sizeof ( node ) ) ;
            temp -> e = h1 -> e + h2 -> e ;
            temp -> c = h1 ->c * h2 -> c ;
            h2 = h2 -> next ;
            if ( f == 0 )
            {
                h = temp ;
                ptr = h ;
            }
            else
            {
               ptr -> next = temp ;
               ptr = ptr -> next ;
            }
            if ( h2 -> next == head2 ) f2++ ;
        }while ( h2 != head2 || f2 != 1 ) ;
        h1 = h1 -> next ;
        if ( h1 -> next == head1 ) f1 ++ ;

    }while ( h1 != head1 || f1 != 1 ) ;
    ptr -> next = h ;
    return h ;

}

int main ()
{
    node * h1 , *h2 , *h3 , *h4 ;
    char ch ;
    int c ;
    do
    {
            printf("VARIOUS OPTIONS AVAILABLE ARE \n 1.EVALUATE POLYNOMIAL \n 2.SIMPLIFY POLYNOMIAL \n 3.ADDITION \n 4.MULTIPLICATION \n ") ;
            printf("ENTER THE CHOICE \n") ;
            scanf("%d" , &c ) ;
            printf("%d" , c ) ;
            switch (c)
            {
                case 1 : h1 = create () ;
                         h2 = simplyfy ( h1 ) ;
                         display ( h2 ) ;
                         evaluate ( h2 ) ;
                         break ;
                case 2 : h1 = create () ;
                         h2 = simplyfy (h1) ;
                         display ( h2 ) ;
                         break ;
                case 3 : h1 = create() ;
                         h1 = simplyfy ( h1 ) ;
                         h2 = create () ;
                         h2 = simplyfy ( h2 ) ;
                         h3 = add ( h1 , h2 ) ;
                         display ( h3 ) ;
                         break ;
                case 4 :h1 = create () ;
                        h1 = simplyfy( h1 ) ;
                        h2 = create () ;
                        h2 = simplyfy( h2 ) ;
                        h3 = multiplication ( h1 , h2 ) ;
                        display ( h3 ) ;
                        break ;
            }
            printf("ENTER Y OR y TO CONTINUE \n" ) ;
            scanf("%c"  , &ch ) ;
    }while ( ch == 'Y' || ch =='y' ) ;


}
