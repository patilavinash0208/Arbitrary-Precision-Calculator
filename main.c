/*
												PROJECT : ARBITRARY PRECISION CALCULATOR
												
										NAME	: Avinash Patil
										Batch	: 25036A
										Date	: 03/04/2026

						DESCRIPTION : 
						This project implements a calculator in C that performs arithmetic operations
						on integers of unlimited size using doubly linked lists. It supports addition,
						subtraction, multiplication, division, and modulus. The program handles large
						numbers, carry/borrow operations, and signed inputs efficiently using custom logic.
*/

#include "apc.h" 
char operator;
int pos_flag1, pos_flag2, neg_flag1, neg_flag2;

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;

    // Validation
		//1.must have only 4 arguments
		//	--> No - Print error and usage msg & EXIT
		//	--> Yes -  Move on to next step

		//2. check both operands (It must contains numerical characters)
		//	--> No - Print an error and usage msg & EXIT
		//	--> Yes - Return SUCCESS
		if(cla_validation(argc,argv)==FAILURE)
		{
			return FAILURE;
		}
		// printf("Success\n");
	//Decide operation to be done
		operation_decider(argv);
		// printf("Success\n");
    // Create 2 lists of operands
		//1. Create 2 lists for operands
			// head1, tail1 --> operand1
			// head2, tail2 --> operand2
		// node* head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL;

		create_list(argv[1],&head1,&tail1);
		// printf("Success\n");
		// print_list(head1);
		create_list(argv[3],&head2,&tail2);
		// printf("Success\n");
		// print_list(head2);
		
    // Remove pre zeros
		remove_pre_zeros(&head1);
		// printf("Success\n");
		remove_pre_zeros(&head2);
		// printf("Success\n");
		
    // char oper = argv[2][0];
	// printf("%c\n",operator);
    switch(operator)
    {
	case '+':
		addition(tail1,tail2,&headR,&tailR);	//addition of two operands
		if(neg_flag1==1)	// if operand1 is negative then result will be negative
		{
			printf("-");
			print_list(headR);
		}
		else
			print_list(headR);
	    break;

	case '-':
		int ret = compare_list(head1,head2);	//compare which operand is greater
		if(ret == OPERAND1)	//if operand1 is greater
		{
			subtraction(tail1,tail2,&headR,&tailR);	//substraction of two operands
			if(neg_flag1==1)	//if operand1 is negative then result  will be negative
			{
				printf("-");	
			}
			print_list(headR);
		}
		else if(ret == OPERAND2)	//if operand2 is greater
		{
			subtraction(tail2,tail1,&headR,&tailR);	//substraction of two operands
			if(pos_flag1==1)	//if operand1 is positive then result  will be negative
			{	
				printf("-");
			}
			print_list(headR);
		}
		else
		{
			insert_first(&headR,&tailR,0);	//if both operands are same then substraction will be zero
			print_list(headR);
		}
	    break;

	case 'x':
	case 'X':
		multiplication(tail1,tail2,&headR,&tailR);	//multiplication of two operands
		if((pos_flag1 != pos_flag2) || (neg_flag1 != neg_flag2))	//if both operands sign is not equal then result will be negative
			printf("-");
		print_list(headR);
	    break;

	case '/':
		int res = compare_list(head1,head2);	//compare which operand is greater
		if(res == OPERAND2)	//if operand2 is greater
		{
			insert_first(&headR,&tailR,0);	//dividing by greater number gives quotient zero hence insert zero in result list
			print_list(headR);
			return  SUCCESS;	
		}
		if(head2->data == 0)	//if operand2 is zero
		{
			printf("ERROR : cannot be divided by zero\n");	//division by zero cannot be possible
			return FAILURE;
		}
		division(head1,head2,tail2,&headR,&tailR);	//division of two operands
		if((pos_flag1 != pos_flag2) || (neg_flag1 != neg_flag2))	//if both operands sign is not equal then result will be negative
			printf("-");
		print_list(headR);
	    break;
	
	case '%':
	res  = compare_list(head1,head2);	//compare which operand is greater
	if(res == OPERAND2)		//if operand2 is greater
	{
		headR = head1 , tailR = tail1;	//modulo by greater no gives same operand1 as result
		print_list(headR);
		return  SUCCESS;	
	} 
	if(head2->data == 0)	//if operand2 is zero
	{
		printf("ERROR : cannot be divided by zero\n");	//division by zero cannot be possible
		return FAILURE;
	} 
	modulus(head1,head2,tail2, &headR,&tailR);	//modulus of two operands
	if(((pos_flag1 != pos_flag2) || (neg_flag1 != neg_flag2)) && headR->data != 0)	//if both operands sign is not equal then result will be negative
			printf("-"); 
	print_list(headR);

	 break;
	default:
	    printf("Invalid operator\n");
    }
}

