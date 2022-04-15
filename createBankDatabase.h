
// header files or C++ standard libraries ie. preprocessor derectives 
#include<iostream> //for standard input/output in C++ 
#include<conio.h>  //clrscr(for turbo c++), getch, getche
#include<string>
#include<map> //STL associative container
#include<math.h>
#include<time.h> //to access system time
#include<cstdlib>    //for srand
#include<ctime>   //for srand function
#include<cstdint>
#include<windows.h> // for Sleep() to create a delay
#include<stdlib.h> //for system("cls") and for exit(0) function 
#include<stdio.h> //for input/output in C 
#include<iterator>
#include<algorithm>
#include<fstream> //for file operations
#include<malloc.h>

// to use the namespace defined in C++ libraries and not any other or userdefined namespace, to avoid any ambiguity 
using namespace std;

//map : to map the account numbers with the name of the account holder
map<int,string> mp;
map<int,string>::iterator it;
char accopen='N';
int cnt=0, pos, acc_for_deleting=0;

struct node
{   int data;  // data is the account number
	struct node* next;
}*head,*ptr,*ptr1,*temp,*nnode,*nn;

// to create the linked list
void create()
{
	string name;
	int x,n;
	cout<<"\n*********** Storing Account Numbers in the Bank Database ************";
	cout<<"\nEnter the number of account numbers to be stored: ";
	cin>>n;
	
		while(1)
		{
			cout<<"\nEnter 5 Digit Account number 1: ";
			cin>>x;
			if(x>9999 && x<100000)
			{
			   nnode=(struct node*)malloc(sizeof(struct node));
			   nnode->data=x;
               nnode->next=NULL;
               head=nnode;
               
               cout<<"\nEnter the name of the account holder 1: ";
		       cin>>name;
		       mp.insert(pair<int,string>(x,name));
		       cnt++;
               break;
			}
       }
       
       for(int i=2;i<=n;i++)
	    {
		while(1)
		{
			cout<<"\nEnter 5 Digit Account number "<<i<<": ";
			cin>>x;
			if(x>9999 && x<100000)
			{
			   nn=(struct node*)malloc(sizeof(struct node));
			   nn->data=x;
               nn->next=NULL;
               nnode->next=nn;
               nnode=nnode->next;
               cout<<"\nEnter the name of the account holder "<<i<<":";
		       cin>>name;
		       mp.insert(pair<int,string>(x,name));
		       cnt++;			
			   break;
            }
	    }
	}
		
	cout<<"\n"<<mp.size()<<" Account Numbers have been successfully stored in the Bank Database as follows:\n\n";
	
	for (it = mp.begin(); it != mp.end(); it++) 
		 cout<<(*it).first<<" : "<<(*it).second<<endl;
		 
	cout<<"\nBank Database has been saved and closed\n";
	cout<<"\n-----------------------------------------\n";

}

// to check the existence of the account in the bank
int search(int key)
{
		ptr=head;
	    pos=1;
	 while(ptr!=NULL)
	{
		if(ptr->data==key)
			return pos;
			
		ptr=ptr->next;
		pos++;
	}
	return 0;
}

//to insert the newly created accounts
void insert(int key)
{
	ptr=head;
	nnode=(struct node*)malloc(sizeof(struct node));
	nnode->data=key;
	 while(ptr->next!=NULL)
		ptr=ptr->next;			
	 ptr->next=nnode;
	 nnode->next=NULL;
	cout<<"\nYour account with number "<<key<<" has been included in our Bank Account database\nThankyou for giving us an opportunity to provide our services to you hereafter\n";
}

//to close / delete a bank account from the database
void del(int key)      
{   
    pos=search(key);
	if(pos==0)
        cout<<"\nYour account with number "<<key<<" is not present in our Bank\nPlease re-enter the correct account number";
	else 
	{
		ptr=head;
	if(pos==1)
		head=ptr->next;
	else
	{
		while(ptr->next!=NULL)
		{
			ptr1=ptr;
			ptr=ptr->next;			
		}
		if(pos==cnt)
		    ptr1->next=NULL;
		else
		    ptr1->next=ptr->next;
    }
    
        mp.erase(ptr->data); //deletes the key and it's value from map
    
		cout<<"\nYour account with number "<<ptr->data<<" has been closed\nThankyou for giving us an opportunity to provide our services to you\n";
		free(ptr);
    } 
}

