#include<stdio.h>
#include<stdlib.h>
typedef struct node node ;
struct node{
    int val ;
    node * next ;
};
  node * create_node()
  {
      int i ,  n , v ;
      node * head , * temp ;
      head = ( node *) malloc ( sizeof ( node ) ) ;
      printf("ENTER THE NO OF ELEMET TO BE ADDED \n " ) ;
      scanf ( "%d" , &n ) ;
      head -> val = n ;
      temp = head ;
     for ( i = 0 ; i < n ; i ++ )
     {
         temp -> next = ( node * )  malloc ( sizeof (node) ) ;
         temp = temp -> next ;
         printf("ENTER THE VALUE OF NODE \n " ) ;
         scanf ( "%d" , &v ) ;
         temp ->val = v ;
         temp -> next = NULL ;
     }
      return head ;
  }


   void display ( node * head )
   {
       node * temp = head ->next ;
       while ( temp != NULL )
       {

           printf("%d \n " , temp -> val ) ;
           temp = temp -> next ;
       }
   }

  /* void insert ( node * head )
   {
       node * ptr = head -> next , * temp ;
       int v , i , flag = 0 ;
       printf ("ENTER THE VAL AFTER WHICH YOU WANT TO APPEND \n ") ;
       scanf ("%d" , &v ) ;
       for ( i = 0 ; i < head -> val ; i ++ )
       {
           if ( ptr -> val == v )
           {
               temp = ptr -> next ;
               ptr -> next = ( node *) malloc ( sizeof node ) ;
               printf("ENTER THE VAL IN NODE \n ") ;
               scanf("%d" , &v ) ;
               ptr ->next->val = v ;
               ptr->next->next = temp ;
               (head -> val )++ ;
               flag = 1 ;
               break ;
           }
       }
       if ( flag == 0 ) printf("RECORD NOT FOUND \n ") ;
   } */

   void insert ( node * head )
   {
       int loc , i , v ;
       node * ptr = head -> next , *temp , *ptr1;
       printf("ENTER THE LOCATION IN WHICH YOU WANT TO INSERT \n ") ;
       scanf ("%d" , &loc ) ;
       if ( loc <= head->val && loc >= 0 )
       {
           for ( i = 0 ; i < loc  ; i ++ ) ptr = ptr -> next ;
           ptr1 = ptr->next ;
           temp = ( node * )malloc ( sizeof (node) ) ;
           printf("ENTER THE VAL IN NODE \n ") ;
           scanf("%d" , &v ) ;
           temp ->val = v ;
           ptr->next = temp ;
           temp->next = ptr1 ;
           (head->val )++ ;
       }
       else printf("ERROR\n") ;
   }



   void delete_node( node * head )
   {
       int i , v , loc ;
       printf("ENTER THE VAL IN NODE \n ") ;
       scanf("%d" , &loc  ) ;
       node * temp = head -> next , *temp1 ;
       if ( loc < head->val && loc>=0)
       {

        for ( i = 0 ; i < loc ; i ++ ) temp = temp -> next ; // one location before which you want to delete
        temp1 = temp->next ;
        temp ->next = temp1->next ;
       ( head -> val ) -- ;
       }
       else printf("ERROR\n") ;
   }



   void reverse_node( node * head )
   {

       node * p1 , *p2 , *p3 ;
       p1 = NULL ;
       temp = p2 ;
       p2 = head -> next ;
       p3 = p2 -> next ;
       p2 ->next = NULL ;

       while ( p3 != NULL)
       {
           ptr = p3-> next ;
           p3 -> next = temp ;
           temp = p3 ;
           p3 = ptr ;
       }
   }
int main ()
{
    node * head ;
    int ch , ch1 ;
    do {

     printf(" 1. create link list \n 2 . display list \n 3. insert node \n 4 .delete node \n 5 . reverse node \n 6 . display reverse node \n ") ;
     scanf("%d" , &ch1) ;

    switch ( ch1 )
    {

        case 1: head = create_node() ;
                break ;

        case 2 : display ( head ) ;
                 break ;

        case 3: insert ( head ) ;
                break ;

        case 4 : delete_node( head ) ;
                break ;

        case 5: reverse_node( head ) ;
                break ;

        case 6: display_reverse (head ) ;
                break ;
    }

    printf ("PRESS 1 TO CONTINUE \n ") ;
    scanf("%d" , &ch) ;

    } while ( ch == 1) ;
}
