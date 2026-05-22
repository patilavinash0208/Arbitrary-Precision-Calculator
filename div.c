#include "apc.h"

void division(node *head_L1, node *head_OPR2, node *tail_OPR2, node **headR, node **tailR)
{
    node *head_OPR1 = NULL, *tail_OPR1 = NULL; //a list to store opr1 for performing substractn operatn
    node *temp = head_L1; //for traversing through list 1
    node *head_SR = NULL, *tail_SR = NULL;  //list to store substraction result

    if(temp!=NULL)
    insert_last(&head_OPR1, &tail_OPR1, temp->data); //insert first node from list1 in opr1 list

    while( compare_list(head_OPR1,head_OPR2) == OPERAND2)   //keep inserting nodes till operand 1 becomes greater than operand 2
    {
        if(temp!=NULL)
        {
            temp =  temp->next; //move temp to next node
            if(temp != NULL)
            insert_last(&head_OPR1, &tail_OPR1, temp->data); //insert node opr1 list
        }
    }

    while(temp != NULL)
    {
        int sub_count = 0;  //initialising no of substractions count = 0

        //Keep Subtracting till opr1 is greater than opr2
        while ((compare_list(head_OPR1,head_OPR2) == OPERAND1) || (compare_list(head_OPR1,head_OPR2) == SAME))
        {
            subtraction(tail_OPR1,tail_OPR2,&head_SR,&tail_SR); //subtract opr2 from opr1 and store in SR list
            delete_list(&head_OPR1,&tail_OPR1); //delete opr1 list for reuse
            head_OPR1 = head_SR;    //change head_opr1 & tail_opr1 pointing to head_sr & tail_sr
            tail_OPR1 = tail_SR;
            head_SR = NULL, tail_SR = NULL; //make head_sr & tail_sr as NULL
            sub_count++;    //increment no of substractions
        }
        insert_last(headR,tailR,sub_count); //store sub_count(quotient) in result list
        if(temp!=NULL)
        {
            temp =  temp->next; //move temp to next node
            if(temp != NULL)
            insert_last(&head_OPR1, &tail_OPR1, temp->data);    //insert digit in opr1 list
        }
        remove_pre_zeros(&head_OPR1);   //remove unwanted zeroes
    }
}
