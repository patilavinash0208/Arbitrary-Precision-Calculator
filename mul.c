#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR1, node **tailR1)
{
    int count = 0;
    node *temp1 = tail1, *temp2 = tail2, *headR2 = NULL , *tailR2 = NULL, *head_AR = NULL, *tail_AR = NULL;

    insert_first(headR1,tailR1,0);  //intialising Result list with 0
    int carry = 0, prod = 1;    //initially set carry=0 and prod=1

    while(temp2 != NULL)    //run loop till temp2 reaches NULL i.e. no further nodes available
    {
        for(int i=0;i<count;i++)    //insert count times zeroes in listR2 where prod is stored
        {
            insert_first(&headR2,&tailR2,0);
        }
        carry = 0;  //reset carry

        while(temp1 != NULL)    //loop for accessing list1 nodes 
        {
            prod = temp1->data * temp2->data + carry;   //multiply list2 node with each list1 node and store in prod
            insert_first(&headR2,&tailR2,prod%10);  //store last digit of prod in listR2
            carry = prod/10;    //store first digit of prod in carry
            temp1 = temp1->prev;    //move temp1 to prev node
        }
        
        addition(*tailR1,tailR2,&head_AR,&tail_AR); //add main result list & R2 list in which prod is stored and store in temp AR list
        delete_list(headR1,tailR1); //delete list R1 & R2
        delete_list(&headR2,&tailR2);
        *headR1 = head_AR;  //Change pointing of headR1 & tailR1 to AR list pointers
        *tailR1 = tail_AR;
        head_AR = NULL;     //make head_AR & tail_AR as NULL
        tail_AR = NULL;

        temp2 = temp2->prev;    //move temp2 to prev node
        temp1 = tail1;  //move temp1 again to last node
        count++;    //increment count
    }
    if(carry)   //if carry is present insert it in R2 list 
      insert_first(headR1,tailR1,carry);  
    remove_pre_zeros(headR1);
}
