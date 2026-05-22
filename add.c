#include "apc.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *temp1 = tail1, *temp2 = tail2;
    int sum=0,carry=0;

    while(temp1 != NULL || temp2 != NULL)
    {
        if(temp1 == NULL)   //if no digit present in list1
        {    
            sum = temp2->data + carry; //store list2 digit + carry of prev addition
            temp2 = temp2->prev;    //move only temp2 as list1 has no more digits
        }
        else if(temp2 == NULL)  //if no digit present in list2
        {
            sum = temp1->data + carry;  //store list1 digit + carry of prev addition
            temp1 = temp1->prev;    //move only temp1 as list2 has no more digits
        }
        else
        {
            sum = temp1->data + temp2->data + carry;    //store addition of both list digits + carry of prev addition
            temp1 = temp1->prev;    //move temp1 to prev node
            temp2 = temp2->prev;    //move temp2 to prev node
        }
        insert_first(headR, tailR, sum%10); //insert last digit of sum in result list
        carry = sum/10; //store first digit of sum in carry
    }

    if(carry)   //if at last carry has any digit insert it at first in result list
        insert_first(headR,tailR,carry);
    
    
}
