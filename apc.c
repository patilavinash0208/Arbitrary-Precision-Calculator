#include "apc.h"

// Function definitions
extern char operator;
extern int pos_flag1, pos_flag2, neg_flag1, neg_flag2;

int cla_validation(int argc, char *argv[])
{
    //1.must have only 4 arguments
		//	--> No - Print error and usage msg & EXIT
		//	--> Yes -  Move on to next step
    if(argc != 4)
    {
        printf("ERROR: Invalid no of argumennts\n");
        return FAILURE;
    }
	//2. check both operands (It must contains numerical characters)
		//	--> No - Print an error and usage msg & EXIT
		//	--> Yes - Return SUCCESS

    //Checking first char of operand 1
    if(!isdigit(argv[1][0]) && argv[1][0] != '+' && argv[1][0] != '-')
    {
        printf("Operand 1 first char must be + , - or digit\n");
        return FAILURE;
    }
    //Checking all characters of operand 1
    for(int i=1; argv[1][i]!= 0 ;i++)
    {
        if(!isdigit(argv[1][i]))
        {
            printf("Operand 1 must contain only digits\n");
            return FAILURE;
        }
    }

    //Checking first char of operand 2
    if(!isdigit(argv[3][0]) && argv[3][0] != '+' && argv[3][0] != '-')
    {
        printf("Operand 1 first char must be + , - or digit\n");
        return FAILURE;
    }
    //Checking all characters of operand 2
    for(int i=1; argv[3][i]!= 0 ;i++)
    {
        if(!isdigit(argv[3][i]))
        {
            printf("Operand 1 must contain only digits\n");
            return FAILURE;
        }
    }

    //Checking Operator
    if(strlen(argv[2]) != 1)
    {    
        printf("ERROR: Invalid Operator\n");
        return FAILURE;
    }
    if(argv[2][0]=='+' || argv[2][0]=='-' || argv[2][0]=='x' || argv[2][0]=='X' || argv[2][0]=='/' || argv[2][0]=='%')
        return SUCCESS;
    else
    {
        printf("ERROR: Invalid Operator\n");
        return FAILURE;
    }
    
}

void operation_decider(char *argv[])
{
    //Checking sign of operand1
    if(argv[1][0] == '+' || (isdigit(argv[1][0])))
        pos_flag1 = 1;
    else if(argv[1][0] == '-')
        neg_flag1 = 1;
    
    //Checking sign of operand2
    if(argv[3][0] == '+' || (isdigit(argv[3][0])))
        pos_flag2 = 1;
    else if(argv[3][0] == '-')
        neg_flag2 = 1;
    
    //When operator is '+'
    if(argv[2][0] == '+')
    {
        if((pos_flag1 == pos_flag2) || (neg_flag1 == neg_flag2))    //both operands have same sign then perform addition else substraction
            operator = '+';
        else
            operator = '-';
    }

    //When operator is '-'
    else if(argv[2][0] == '-')
    {
        if((pos_flag1 == pos_flag2) || (neg_flag1 == neg_flag2))    //both operands have same sign then perform substraction else addition
            operator = '-';
        else
            operator = '+';
    }
    else
        operator = argv[2][0]; //either multiplication or division or modulus
}

void create_list(char *opr, node **head, node **tail)
{
    // Create 2 lists of operands
		//1. Create 2 lists for operands
			// head1, tail1 --> operand1
			// head2, tail2 --> operand2
		
		//2. Fetch character by character
			//--> Convert a char into a digit

		//3. Store the digit into the linked list (insert_last)
        for(int i=0;opr[i];i++)
        {
            if(opr[i] == '+' || opr[i] == '-')
                continue;
        
            if(insert_last(head,tail,opr[i]-'0') == FAILURE)
            {
                perror("Insertion Failed\n");
                return;
            }
        }
}


int insert_last(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));
    if(new == NULL)
        return FAILURE;
    new->data = data;
    
    if(*head == NULL && *tail == NULL)
    {
        new->prev = NULL;
        new->next = NULL;
        *head = new;
        *tail = new;
    }
    else
    {
       (*tail)->next = new;
       new->prev = *tail;
       new->next = NULL;
       *tail = new;
    }
   return SUCCESS;
}

int insert_first(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));
    if(new == NULL)
        return FAILURE;
    new->data = data;
    
    if(*head == NULL && *tail == NULL)
    {
        new->prev = NULL;
        new->next = NULL;
        *head = new;
        *tail = new;
    }
    else
    {
       (*head)->prev = new;
       new->prev = NULL;
       new->next = *head;
       *head = new;
    }
   return SUCCESS; 
}

void print_list(node *head)
{
    /* Checking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
	    }
    	printf("\n");
    }
}

int list_len(node *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int compare_list(node *head1, node *head2)
{
    int len1 = list_len(head1);
    int len2 = list_len(head2);

    if(len1 > len2)
        return OPERAND1;
    else if(len2 > len1)
        return OPERAND2;
    else
    {
        while(head1 != NULL || head2 != NULL)
        {
            if(head1->data > head2->data)
                return OPERAND1;
            else if(head2->data > head1->data)
                return OPERAND2;
            else
            {
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        return SAME;
    }
}

void remove_pre_zeros(node **head)
{
    while((*head)->data == 0)
    {
        if((*head)->next == NULL)
            return;
        
        node *temp = *head;
        *head = (*head)->next;
        free(temp);
        (*head)->prev = NULL;
    }
}

int delete_list(node **head, node **tail)
{
    node *temp = *head;
    while(*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        if(*head != NULL)
        (*head)->prev = NULL;
    }
    *tail = NULL;
}