#include<iostream>
#include<stdio.h>
#include<string>
#include<cstdlib>    
#include<ctime>  
using namespace std;

// user defined random number generator function declaration or prototype
int printRandoms(int,int,int a=1);
int cpassg=printRandoms(1000,4999);
int dpassg=printRandoms(5000,9999);

static int caccess=1,daccess=1;
int finalCreditPass , finalDebitPass , sent=-999 , further , litmusTest=0, ccardused=0, dcardused=0 ;

/* hybrid inheritence : combination of mutiple , multilevel and hierarchical inheritance

					atm_card         //grandparent class
					/      \
				   /        \
				credit		debit     //parent classes
					\        /
					 \      /
					 attempts        //grandchild class
*/

class atm_card //virtual base class 
{
public:	
		char card_issue;
		int card_choice, r, cpass, dpass, ctest, dtest, my_cpass, my_dpass, opted, proceeding;
    
	char *reason;
	
    atm_card();                    //default constructor
    atm_card(int,int);			 //parameterised constructor
    atm_card(const atm_card&);     //copy constructor
    
    void inquire();
	virtual int issue();         //virtual function	used to support polymorphism
	
	~atm_card()           //destructor
	{ }
};

    atm_card::atm_card()
    {
    	this->cpass=cpassg;
    	this->dpass=dpassg;
	}

	void atm_card::inquire()
	{
			cout<<"\nYou can have a maximum of 1 credit and 1 debit card";
			cout<<"\nDo you want us to issue an atm card? (y/n): ";
			cin>>card_issue;
    }
		    
	int atm_card::issue()
		{
			if(card_issue=='y' || card_issue=='Y')
		    {	
		    //reference variables
				int &cp=cpass , &dp=dpass ;
			
		    	change:
				
				while(1)
		    	{	
					
				cout<<"\nSelect an option:\n1. CREDIT CARD\n2. DEBIT CARD :\t";
		    	cin>>opted;
		    		if(opted==1 || opted==2)
		    			break;
		    		else
		    			cout<<"\nPlease enter an available choice (1/2)";
				}
		    	
		    if(sent!=-999 && further==2)	
			{
		   	do
		   	{
		    if(sent==2 && opted==1)
		    {
		    	cout<<"\nYou already have a credit card\nPlease select the other option";
				goto change;
			}
			else if(sent==3 && opted==2)
			{
				cout<<"\nYou already have a debit card\nPlease select the other option";
				goto change;
			}
			else
			{
				break;
			}
			}while(1);
			}
				
		    do
		    {
		    cout<<"\n1. Continue the Procedure\n2. Cancel the Procedure\n3. Change my choice :\t";
		    cin>>proceeding;
		   		 switch(proceeding)
		   		 {
		    	case 1:
		    		break;
		    	case 2:
		    		cout<<"\nCard issue procedure has been cancelled successfully !!!";
		    		return -6;
		    	case 3:
		    		goto change;
		    		
		    	default:
		    		cout<<"\nPlease enter the available choice :\t";
		    		break;
			    }
			}while(proceeding!=1 && proceeding!=2 && proceeding!=3);
					
		    	switch(opted)
		    	{
		    		case 1:
		    			cout<<"\n************* Your credit card has been issued with system generated password "<<cp<<" ***********";
						break;
		    		case 2:
		    			cout<<"\n************* Your debit card has been issued with system generated password "<<dp<<" ***********";
						break;
		    		default:
		    			cout<<"\nPlease enter the available choice";
		    			break;
		        }
	}
	    	else
			{
				if(sent!=-999)
					return -6;
				else
					return 0;
			}
	}
	
class credit : virtual public atm_card
{
	public:
		char retry='Y';
		int setcpassword();
};

        int credit::setcpassword()    
        {int one=0;
        do
		{
		cout<<"\nEnter system generated password for credit card activation : ";
		cin>>ctest;
		if(ctest==cpass)
		{
			cout<<"\nEnter your desired credit card password : ";
			cin>>my_cpass;
			finalCreditPass=my_cpass;
			cout<<"\n*** Credit card password change complete ***";
			return 1;
	    }
	    else
	    {	
	    	one++;
	    	if(one==4)
	    	{
			cout<<"\nYou have entered the wrong password 4 times\nSorry, your card has been blocked for security reasons\nContact your nearest Bank Branch at 020-249834 or by visit to reactivate your card\n";
			return 0;
			}
	    	cout<<"\n*** Credit card password change unsuccessful ***";
			cout<<"\nDo you want to retry ? (y/n) ";
			cin>>retry;
			
			if(retry=='n' || retry=='N')
			{
				cout<<"\nSorry, your credit card could not be activated";
				return 0;
			}
		}
		}while(retry=='Y'|| retry=='y');
    	}

class debit : public virtual atm_card
{
	public:
		 char retry='Y';
		 int setdpassword();
};

        int debit::setdpassword()    
        {int two=0;
        do
		{
		cout<<"\nEnter the system generated password for debit card activation : ";
		cin>>dtest;
		if(dtest==dpass)
		{
			cout<<"\nEnter your desired debit card password : ";
			cin>>my_dpass;
			finalDebitPass=my_dpass;
			cout<<"\n*** Debit card password change complete ***";
			return 1;
	    }
	    else
	    {
	    	two++;
	    	if(two==4)
	    	{
			cout<<"\nYou have entered the wrong password 4 times\nSorry, your card has been blocked for security reasons\nContact your nearest Bank Branch at 020-249834 or by visit to reactivate your card\n";
			return 0;
			}
	    	cout<<"\n*** Debit card password change unsuccessful ***";
			cout<<"\nDo you want to retry ? (y/n) ";
			cin>>retry;
			
			if(retry=='n' || retry=='N')
			{
				cout<<"\nSorry, your debit card could not be activated";
				return 0;
			}
		}
		}while(retry=='Y'|| retry=='y');
    	}	

class attempts : public credit, public debit
{	
	public:
		
		attempts()
		{}
				
		int issue(int);
};

		int attempts::issue(int a=1)  //default arguments
		{
			int cpassentered,dpassentered;
			 
			for(int i=0;i<4;i++)
			{
				cout<<"\nThis is attempt "<<i+1<<" :"<<"\nYou have another "<<(4-i+1)<<" attempts remaining";
				
				if(opted==1 || a==2) //credit card
			   {
				cout<<"\nEnter credit card password: ";
				cin>>cpassentered;
				 if(cpassentered==finalCreditPass)
				 {
					cout<<"\nPassword matched!!!\nCongratulations your credit card is functional\n";
					litmusTest++;
					if(a==2)
						ccardused++;
					return 2;
		     	 }
		    	}
	
				else if(opted==2 || a==3) //debit card
				{
 				cout<<"\nEnter debit card password: ";
				cin>>dpassentered;
				if(dpassentered==finalDebitPass)
					{
					cout<<"\nPassword matched!!!\nCongratulations your debit card is functional\n";
					litmusTest++;
					if(a==3)
						dcardused++;
					return 3;
			        }
				}
			}
			cout<<"\nYou have entered the wrong password 4 times\nSorry your";
			
			if(opted==1)
			{
				cout<<" credit card has been blocked for security reasons\nContact your nearest Bank Branch at 020-249834 or by visit to reactivate your card\n";
				caccess=0;
				return -2;
			}
				
			else if(opted==2)
			{
				cout<<" debit card has been blocked for security reasons\nContact your nearest Bank Branch at 020-249834 or by visit to reactivate your card\n";
				daccess=0;
				return -3;	
			}		
		}

// user defined random number generator function definition
int printRandoms(int lower, int upper, int count) 
{ 
    int key;
	srand(time(0));
	for (int i = 0; i < count; i++) 
		key = (rand() % (upper - lower + 1)) + lower;
	return key;
} 

// acts as a main function for this header file
int card (int direct)
{

// to issue a new card
if (direct==1) 
{
attempts *ob1 = new attempts() , ob2 , *p;  //new operator
ob2=*ob1;
p=&ob2;         

(*p).inquire();      //pointer to an object

int call=p->atm_card::issue();

if(call==0 || call==-6)
	return call;

int opt=0;
		    if(p->opted==1)
				if(p->setcpassword()==0)
					opt=4;      
			if(p->opted==2)
				if(p->setdpassword()==0)
					opt=5;     
			if(opt!=0)
				return opt;	

cout<<"\n**** This is to test the validity of the changed password ****\n";
return (p->issue());     			
}

// to access already existing cards
if(direct==2 || direct==3)
{
	attempts ob2;
	return (ob2.issue(direct));	
}          
}
