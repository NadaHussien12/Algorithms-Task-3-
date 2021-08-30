//Calling some important libraries
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//A linked list node to store a queue entry
struct Node
{
   int data;
   struct Node *next;
};

// The queue, (front) stores the front node of LL(Linked List) and (rear) stores the last node of LL(Linked List)
struct Node *front = NULL,*rear = NULL;


//Function (EnQueue) to insert value to the queue:
void EnQueue(int value)
{
	
//To create a new linked list node:
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode ->data = value;
    newNode -> next = NULL;
    
// If queue is empty, then new node is front and rear both
    if(front == NULL)
        front = rear = newNode;
    else
    {
//add newnode in rear->next
        rear -> next = newNode;
        
//make the new node as the rear node
        rear = newNode;
    }
    printf("\n(Data is inserted successfully in the Queue)\n\n");
}


// Function(Dequeue) to remove a value from the given queue 
void DeQueue()
{

// If queue is empty,print a message on the console screen.
    if(front == NULL)
        printf("\n (Queue is Empty)\n\n");
    else
    {

// Store previous front and move front one node ahead
        struct Node *temp = front;
        
        //make the front node points to the next node logically removing the front element
        front = front -> next;
        printf("\nDeleted element is: %d\n", temp->data);
        printf("\n(Data is deleted successfully from the Queue)\n\n");
    
        //free the first node
        free(temp);
    }
}

//Function (display) to display the values of the queue on the console screen:
void display()
{
	
// If queue is empty,print a message on the console screen.
    if(front == NULL)
        printf("\n(Queue is Empty!)\n");
    else
    {

//Structure (Node) with object pointer(*temp)
        struct Node *temp = front;
        while(temp->next != NULL)
        {

//print the queue if it is not empty
            printf("%d --> ",temp->data);
            temp = temp -> next;
        }
        printf("%d \n",temp->data);
   }
}

//Function (getFront) to display the front value on the console screen:
void getFront()
{

//check if the queue is null or not
    if(front==NULL)
         printf("\n(Queue is Empty!)\n");
    else
        printf("\n Data at front of the queue is %d \n",front->data);
}

//Function (getRear) to display the rear value on the console screen:
void getRear()
{
	
//check if the queue is null or not
    if(rear==NULL)
         printf("\n(Queue is Empty!)\n");
    else
        printf("\n Data at rear of the queue is %d \n",rear->data);
}




//Main Function
int main()
{
	
//Declaration od some variables
    int choice, value;
    
//Applying an infinite loop
    while(1)
    {
    	
//Print some messages on the console screen to make the choice easy on the user
        printf("Please choose the operation you want for the queue:\n\n");
        printf("(1): Insert in Queue\n");
        printf("(2): Delete From Queue\n");
        printf("(3): Front of the Queue\n");
        printf("(4): Rear of the Queue\n");
        printf("(5): Display Queue\n");
        printf("(6): Exit\n");

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
                printf("Insert the value you want to enter: ");
                
            //Take value from the user
                scanf("%d", &value);
                
            //Calling the function (EnQueue) with parameter(value)
                EnQueue(value);
                break;

//if the user enters the choice (2)
         case 2:
         	
         	//Calling the function (DeQueue)
                DeQueue();
                break;
                
//if the user enters the choice (3)
         case 3:
         	
         	//Calling the function (getFront)
                getFront();
                break;
                
//if the user enters the choice (4)
         case 4:
         	
         	//Calling the function (getRear)
                getRear();
                break;
                
//if the user enters the choice (5)
         case 5:
         	
         	//Calling the function (display)
                display();
                break;
                
//if the user enters the choice (6)
        case 6:
        	
        	//Terminate the program
        		exit(0);
        		
//if the user enters wrong number
         default:
                printf("\nInvalid Selection!...Please Enter a correct number!\n\n");
        };
    }
   return 0;
}












