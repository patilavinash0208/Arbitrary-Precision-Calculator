#include "apc.h"

void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    int borrow_flg=0;
    int sub = 0;
    while(tail1 != NULL)
    {
        if(borrow_flg == 1)
        {
            tail1->data -= 1;   //if borrowing was done in prev iteration, current num should be reduced
            borrow_flg = 0; //clear borrow flag as num is reduced
        }

        if(tail2 != NULL)
        {
            if(tail1->data < tail2->data)
            {
                tail1->data += 10;  //if digit1 < digit2, after borrowing 10 needs to be added
                borrow_flg = 1; //set flg after borrowing
            }

            sub = tail1->data - tail2->data; //substraction of both list digits
        }
        else
        {
            if(tail1->data < 0)
            {
                tail1->data += 10;  //if digit1 < digit2, after borrowing 10 needs to be added
                borrow_flg = 1; //set flg after borrowing
            }
            sub = tail1->data; //when list2 don't have digits 
        }

        insert_first(headR,tailR,sub);  //insert substracted result in result list

        //Move pointers
        tail1 = tail1->prev;
        if(tail2 != NULL)
            tail2  = tail2->prev;

    }

    //Remove pre-zeroes
    remove_pre_zeros(headR);
}
