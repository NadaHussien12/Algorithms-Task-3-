//Calling some important libraries
#include<stdio.h>
#include<stdlib.h>

//defining the size of queue
# define N 6

//Declaration and initialization of some variables 
int s[N],top = -1;


//Function(pop) to remove an element from stack
int pop()
{
	return s[top--];
	printf("%d\n",s[top--]);
}

//Function(push) to insert an element into stack
void push(int x)
{
	if(top == N-1)
		printf("Stack is Full");
	else
	{
		top++;
		s[top] = x;	
	}
}

//Function (enqueue) to insert element in the queue using recursive stack call(push)
void enqueue(int x)
{
	push(x);
}


//Function (dequeue) to dequeue(delete) element from a queue using recursive stack call(pop)
int dequeue()
{	

//Declaration of some variables 
	int data,res;
	if(top == -1)
	{
		printf("Queue is Empty");
    }
	else if(top == 0)
	{
		return pop();
	}
	
	data = pop();
	res = dequeue();
	push(data);
	return res;
 	
}

//Function (peek) to get the last entered element of the queue 
int peek(int s[])
{
	if(top == -1)
	{
	printf("\n STACK IS EMPTY");
	return -1;
	}
	else
	printf("The peek of the queue: %d\n",s[top]);
}


//function to print elements of a queue
void display()
{
	int i, stack[N];
	for(i=0;i<=top;i++)
		printf("\n%d",s[i]);
}




//Main Function
int main()
{
	
//Declaration of some variables
	int choice,t,value;

//Applying an infinite loop
	while(1)
	{

//Print some messages on the console screen to make the choice easy on the user
		printf("\nPlease choose the operation you want for the queue:\n\n");
        printf("(1): Insert in Queue\n");
        printf("(2): Delete From Queue\n");
        printf("(3): Peek of the Queue\n");
        printf("(4): Display Queue\n");
        printf("(5): Exit\n");
        
//Ask the user about the choice
        printf("\nEnter your choice: ");
        
//Take value from the user
        scanf("%d",&choice);
        
//Applying Switch case (conditional tool)
		switch(choice)
		{
			
//if the user enters the choice (1)
			case 1:
				//Ask the user about the value
                printf("Insert the value you want to enter: \n");
                
            //Take value from the user
                scanf("%d", &value);
                
            //Calling the function (EnQueue) with parameter(value)
                enqueue(value);
                printf("\n(Data is inserted successfully from the Queue)\n\n");
                break;
			
//if the user enters the choice (2)	
			case 2:
				
			//Calling the function (dequeue)
				t = dequeue();
				printf("\nDequeued element:%d\n",t);
				printf("\n(Data is deleted successfully from the Queue)\n\n");
				break;
				
//if the user enters the choice (3)
			case 3:
			//Calling the function (peek)
				peek(s);
				break;
				
//if the user enters the choice (4)
			case 4:
			//Calling the function (display)
				display();
				break;
				
//if the user enters the choice (5)			
			case  5:	
			//Terminate the program
				exit(0);
				
//if the user enters wrong number
			default:
				printf("\nIncorrect Choice");
			
		}
	}
	
}




