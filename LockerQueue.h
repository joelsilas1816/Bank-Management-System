#include<iostream>
#include<windows.h> // for Sleep() function
using namespace std;

//Doubly Linked Priority Queue
struct pq
	{
		int ln;
		struct pq *f,*b;        // f is next pointer and b is previous pointer
	}*front=NULL , *rear=NULL;
	
struct pq *tempo=front;
	
//displays the existing queue i.e. along with the user other aaccount holders also want to access their respective lockers.
//the queue is formed as per the priority of the locker decided by its number
	void display()
	{
		cout<<"\nThe Queue is : ";
		for(tempo=front; tempo!=rear ; tempo=tempo->f)
			cout<<tempo->ln<<"\t";
		cout<<tempo->ln;
	}
	
	/* Bubble sort the data nodes of the given linked list */
void bubbleSort() 
{ 
    int swapped, i; 
    struct pq *ptr1; 
  
    do
    { 
        swapped = 0; 
        ptr1 = front; 
  
        while (ptr1!= rear) 
        { 
            if (ptr1->ln > (ptr1->f)->ln)  //ascending ordering of elements i.e. smallest Lcoker number will have highest priority
											//and for descending order replace '>' with '<' 
            {  
                swap(ptr1->ln, ptr1->f->ln); 
                swapped = 1; 
            } 
            ptr1 = ptr1->f; 
        } 
    }while (swapped); 
} 
  
/* function to swap data of two nodes a and b*/
void swap(int a, int b) 
{ 
    int temp = a; 
    a = b; 
    b = temp; 
}

// to create the Doubly Linked Priority Queue
	void createMembers()
	{
		struct pq *item[5];
		
		for(int i=0 ; i<5 ; i++)
			item[i] =(struct pq*)malloc(sizeof(struct pq));

		item[0]->ln=28; 
		   
		item[1]->ln=3;
		item[2]->ln=22;
		item[3]->ln=6;
		
		item[4]->ln=9;
		
	for(int i=0 ; i<5 ; i++)
		{
			if (i==0)
			{
				item[i]->f=item[i+1];
				item[i]->b=NULL;			//NULL pointer
			}
			else if (i==4)
			{
				item[i]->b=item[i-1];
				item[i]->f=NULL;		
			}
			else
			{
				item[i]->f=item[i+1];
				item[i]->b=item[i-1];
			}	
		}
		
		front=item[0];		//1st node
		rear=item[4];		//last node before you are enqueued

		cout<<"\nBefore imposing Priority : ";
		display();
		bubbleSort();
		cout<<"\n\nAfter imposing Priority : ";
		display();
	}
	
	//counts the number of members in the queue
	void qcount()
	{
		int queueCount=0;

		for(tempo=front; tempo!=rear ; tempo=tempo->f)
			queueCount++;
		cout<<"\nTotal number of members in the queue : "<<++queueCount;
	}
		
bool isEmpty()
{
	return (rear==NULL);  // or (front==rear==NULL)
}

//inserts you in the queue and then sorts the queue as per priority of your locker
void enqueue(int lockerNum)
{
	struct pq *newnode=(struct pq*)malloc(sizeof(struct pq*));
	newnode->ln=lockerNum;
	
	if(isEmpty())
	{
		front=rear=newnode;
		newnode->f=NULL;
		newnode->b=NULL;
	}
	else
	{
		rear->f=newnode;
		newnode->f=NULL;
		newnode->b=rear;
		rear=newnode;
	}
	bubbleSort();
	cout<<"\nAfter you have been enqueued : ";
	display();
}

//removes the customer from the queue once he has been provided service
void dequeue(int lockerNum)
{
	int status=1;
	struct pq* rem=front;
	cout<<"\n\n***** The dequeue process has been initiated *****\n";
	
	while(1)
{
	if(isEmpty())
	{
		cout<<"\nQueue is empty\n***** End of dequeue process *****";
		break;
	}
	else
	{
		display();
		qcount();
		
		cout<<"\nCurrently, Locker service is being provided to Locker number : "<<rem->ln<<endl;
		
		if(status && rem->ln==lockerNum)  //if you are at the first node
		{
			cout<<"Before you : --\n";					//accessed by pointer b
			cout<<"After you  : "<<rem->f->ln<<endl;	//accessed by pointer f
			status=0;
		}
		else if(status) 			//if you are not at the first node
		{
			cout<<"Before him : --\n";
			cout<<"After him  : "<<rem->f->ln<<endl;
			status=0;
		}

else if(rem->ln==lockerNum && rem==rear)		//if you are at the last node
		{
			cout<<"After you  : --\n";
			cout<<"Before you : "<<rem->b->ln<<endl;
		}
		else if(rem==rear)		//if you are not at the last node
		{
			cout<<"After him  : --\n";
			cout<<"Before him : "<<rem->b->ln<<endl;
		}

else if(rem->ln==lockerNum)			// if you are in the middle
		{
			cout<<"Before you : "<<rem->b->ln<<endl<<"After you  : "<<rem->f->ln<<endl;
		}
		else
		{
			cout<<"Before him : "<<rem->b->ln<<endl<<"After him  : "<<rem->f->ln<<endl;
		}

			if(front==rear)
				front=rear=NULL;
		else
		{
			rem =rem->f;
			front=front->f;
		}
		
		Sleep(1000);   // to convey the dequeuing process
	
	}
}
free(rem);		// free the dequeued node which is pointed to by the rem pointer
}

void LockerQueue(int myLno)  // enables the dequeuing process
{
	createMembers();	//first create the queue
	cout<<endl;
	enqueue(myLno);		//then enqueue the user
	dequeue(myLno);		//then service is provided to him and he is dequeued from the queue
}
