//user defined header files
#include"createBankDatabase.h"                   
#include"card_banking.h"
#include"LockerRoom.h"   
#include"Foreign_Exchange.h"

//definition of macros
#define min_bal 500    // Rs 500 is minimum balance of account  

//global variables
int gameOver=0, no_of_deposits=1, no_of_withds=1, no_of_loans=1, acctype_choice, netb_res, acno_netbank_pass, j=1, srno=0, res=0, no_more=0;

//to display the system date and time
time_t t = time(NULL);

//file pointer
fstream fp;

//user defined data type: structure for loan requests
struct loan_process
{
	double amt,add,def;
	
	//amt is withdrawal amount which exceeds minimum balance
	int loan(double amt,double balance)   
	{
		//this pointer
		this->amt=amt;
		
		//4 loan requests are only possible
		if(no_of_loans<4)
		{   
			srno++;  //post increment
			cout<<"\nRULES:\nLoan can be granted only thrice";
			
			if(no_of_loans==1)
			  cout<<"\nThis is the "<<no_of_loans<<"st time of a loan request. "<<3-no_of_loans<<" requests are further possible\n";
			else if(no_of_loans==2)
			  cout<<"\nThis is the "<<no_of_loans<<"nd time of a loan request."<<3-no_of_loans<<" requests are further possible\n";
			else if(no_of_loans==3)
			  cout<<"\nThis is the "<<no_of_loans<<"rd time of a loan request."<<3-no_of_loans<<" requests are further possible\n";

		//nested if - else if - else programming constructs
        if(balance==min_bal)
	        add = amt;
		else if(balance>min_bal)
		{
			if(amt>balance || amt<=balance)
			{
				def=balance-amt;
				add=min_bal-def;
		    }
		    else if(amt>min_bal)
			    add=(min_bal+(2*amt)-balance);
		} 
		
		// loan amount is being deposited in the account
		        balance+=add;
                fp<<srno<<"\t"<<"loan "<<no_of_loans<<"\t\t"<<add<<"\t"<<balance<<"\t"<<ctime(&t)<<"\n";
                
		        cout<<"\nYou are defeceit of Rs. "<<add;
				cout<<"\nLoan amount of Rs. "<<add<<" has been added to your account\n";
				
				//comparison / relational operators
 				if(1<=amt<5000)
				{
				   cout<<"\nAmount of Rs. "<<add+(30*2)<<" needs to be paid within 30 days (at 2% interest)\n";
				   fp<<"Amount of Rs. "<<add+(30*2)<<" needs to be paid within 30 days (at 2% interest)\n\n";
				}
				else if(5000<=amt<10000)
				{
				   cout<<"\nAmount of Rs. "<<add+5*30<<" needs to be paid within 30 days (at 5% interest)\n";
				   fp<<"Amount of Rs. "<<add+5*30<<" needs to be paid within 30 days (at 5% interest)\n\n";
				}
				else
				{
				   cout<<"\nAmount of Rs. "<<add+7*30<<" needs to be paid within 30 days (at 7% interest)\n";
				   fp<<"Amount of Rs. "<<add+7*30<<" needs to be paid within 30 days (at 7% interest)\n\n";
			    }
				cout<<"\nElse legal action will be taken";
				
 				no_of_loans++;
 				
 				//return statement
				return balance;
		}
		else
	        return balance;
	}
}wopt;

// user defined data type: class : to handle the account details
class person
{
	public:
		
		// string as an array of characters
		char bank_br[20];
		int accno;
		
		// string datatype
		string name,add,phno,IFSC,acctype,nat;
	public:
		
		//overloading cin and cout objects of the iostream class by friend function
		friend istream &operator >>(istream &in, person &p);
		friend ostream &operator <<(ostream &out, person &p);
};

//defining outside the scope of the class
istream &operator >>(istream &in,person &p)
{
	//exit controlled loop : do while loop
	do{
	cout<<"\nEnter your name: ";      		
	in>>p.name;
	cout<<"\nEnter your address: ";   		
	in>>p.add;
	cout<<"\nEnter your 10 digit phone number: ";
	while(1)
	{
		in>>p.phno;
		if (p.phno.length()!=10)
		   cout<<"\nPlease Enter a 10 digit phone number: ";
		else  break;
	}
	cout<<"\nEnter your Nationality: ";   
	in>>p.nat;
	cout<<"\nEnter your Bank & Branch: ";   
	in>>p.bank_br;
	
	// logical Inclusive OR operator i.e. ||
	if(accopen=='N' || accopen=='n')
	{
	 cout<<"\nEnter your Account Number: ";
	
	//entry controlled loop : while loop
	while(1)
	{
		in>>p.accno;
		if(p.accno<9999 || p.accno>99999)
			cout<<"\nPlease enter 5 Digit Account no: ";
			
		// user defined function to check the existence	of bank account in bank database
		else if(search(p.accno)==0)
		    {
		    	if(gameOver==0)
		    	{
		    		cout<<"\nYour account with number "<<p.accno<<" does not exist in our Bank";
		    		cout<<"\nPlease re-enter your correct account number: ";	
				}
				
				// if I want to close / delete my account
				else if(gameOver==1)
				{
						cout<<"\nSave or Edit ?(s/e)";
					if (getche()=='s' || getche()=='S')
     				{
     					if(p.accno==acno_netbank_pass)
     					{
     						cout<<"\nYour account with number "<<p.accno<<" does not exist in our Bank";
						cout<<"\nsince it has been deleted successfully";
						break;
						 }
						 else
						 {
						 	cout<<"\nPlease enter the correct accno : ";
						 }
     					
					}
				}
        }
        else
        	break;
    }
    }
    
    	// if I do not want to close / delete my account
    if(gameOver==0)
    {
    	cout<<"\nSave or Edit ?(s/e)";
		if (getche()=='s' || getche()=='S')
     	break;   	
	}  
	else if(gameOver==1)
    	break;
    	
}while(1);  // end of do while loop
}

ostream &operator <<(ostream &out,person &p)
{
	string data;
	
	if(accopen=='n' || accopen=='N')
	{
		
	// file handling to create bank statement	
	fp<<"------------------------------------------------------------------\n";
	fp<<"                         : Bank Statement :\n";
	fp<<"------------------------------------------------------------------\n";
	fp<<"\nAccount holder          : "<<p.name;
	fp<<"\nAddress                 : "<<p.add;
	fp<<"\nContact Number          : "<<p.phno;
	fp<<"\nNationality             : "<<p.nat;
	fp<<"\nBank & Branch           : "<<p.bank_br;
	fp<<"\nIFSC Code               : BKID030214";
	fp<<"\nAccount Number          : "<<p.accno;
	
	// account type is decided based on range of account number
	if(p.accno>=10000 && p.accno<50000)
	    p.acctype="SAVINGS ACCOUNT";
	else if(p.accno>=50000 && p.accno<100000)
	    p.acctype="CURRENT ACCOUNT";
	    
 	fp<<"\nAccount Type            : "<<p.acctype;
	fp<<"\nInitial Minimum Balance : "<<min_bal<<endl;
	fp.close();
	
	fp.open("bank_statements.txt",ios::in);
	int track=1; // to display the required lines of the file at output
	    	if(fp)
	    	{
	    		if(!fp.fail()) // to handle exceptions in file handling
	    				while(getline(fp, data))
	    				{
	    					track++;
	    					if(track>3)
	    					{
	    						out<<data<<endl;
							}
						}
				else
					out<<"\n******Bank Statement Cannot Be Displayed******";
			}
			else
				out<<"\n******Bank Statement Does Not Exist******";
	out<<"\n------------------------------------------------------------------";
	fp.close();
	fp.open("bank_statements.txt",ios::app);
	
}
else
{
	out<<"\n------------------------------------------------------------------\n";
	out<<"\nAccount holder          : "<<p.name;
	out<<"\nAddress                 : "<<p.add;
	out<<"\nContact Number          : "<<p.phno;
	out<<"\nNationality             : "<<p.nat;
	out<<"\nBank & Branch           : "<<p.bank_br;
	out<<"\nIFSC Code               : BKID030214";
	out<<"\nAccount Number          : "<<p.accno;
	
	if(p.accno>=10000 && p.accno<50000)
	    p.acctype="SAVINGS ACCOUNT";
	else if(p.accno>=50000 && p.accno<100000)
	    p.acctype="CURRENT ACCOUNT";
	    
 	out<<"\nAccount Type            : "<<p.acctype;
	out<<"\nInitial Minimum Balance : "<<min_bal<<endl;
	out<<"\n------------------------------------------------------------------\n";
}
}

// to handle the transactions of the account 
class bank
{
	public:
		
	// static datamembers	
    static double bal;  
	double amt;

	    bool access=true;
	    
	    double deposit();
		
		void balance()
		{
			if(res==1)
			   bal=min_bal;
			cout<<"\nBalance is : "<<bal;
		}
		
		void withd();
		
		//friend function to display bank statement
		friend void bank_statements(bank &);
};

//initialising static datamembers
double bank::bal=min_bal;   

// defining member functions outside the class using scope resolution operator so that they do not behave as inline functions
		double bank::deposit() 
		{
			if(res==1)
			   bal=min_bal;
			srno++;  
			while(1)
			{
			cout<<"\nEnter the amount to be deposited:\n";
			cin>>amt;
			
			// deposit non-zero amount only
			if(amt==0)
			{
			    cout<<"\nPlease deposit non-zero amount";
			    cout<<"\nDo you want to continue?(y/n)";
			}
			else if(amt>=25000)
			    {
				cout<<"\nYou cannot deposit Rs."<<amt<<" in a single go in a single day\nDepositing parts of Rs. "<<amt<<" separately is recommended";
			    return 0;
			    }
			else
			    break;
			if(getche()=='n' || getche()=='N')
			    return 0;
			}
			bal+=amt;
			cout<<"\nRs. "<<amt<<" has been successfully deposited in your account ";

			fp<<srno<<"\t"<<"deposit "<<no_of_deposits<<"\t"<<amt<<"\t"<<bal<<"\t"<<ctime(&t)<<"\n";
            no_of_deposits++;
			return bal;
		}
		
		void bank::withd()
		{
			if(res==1)
			   bal=min_bal;
			int ch;
			cout<<"\nEnter the amount to be withdrawn:\n";
			cin>>amt;
			try
			{
				//exception handling if withdrawal amount exceeds the minimum balance of the account
				if((bal-amt)<min_bal)
				   throw (amt);
				else
				{
					srno++;  // keeps a track of number of transactions 
 
					bal-=amt;
			        cout<<"\nRs. "<<amt<<" has been successfully withdrawn from your account ";
				    fp<<srno<<"\t"<<"withdrawal "<<no_of_withds<<"\t"<<amt<<"\t"<<bal<<"\t"<<ctime(&t)<<"\n";
                    no_of_withds++;
					cout<<"\nBalance is: "<<bal;
				}
			}
			catch(double amt)
			{   int i=4; //i is for multiple wrong_withdrawal_option(<1 or >3) attempts & j is for multiple wrong loan(if loan_amount>15000) attempts
			  
				char approach='y', loan_opt='k';
			    
				cerr<<"Your Balance is: "<<bal<<"\nAmount of Rs. "<<amt<<" exceeds the minimum balance of Rs. "<<min_bal;
				do{
				cout<<"\n\tSelect one of the following procedures to continue:";
				if (j<4)
				cout<<"\n1.Withdrawal of a lesser amount\n2.Bank Loan\n3.Exit procedure\n";
				else
				cout<<"\n1.Withdrawal of a lesser amount\n3.Exit procedure\n\tLOAN FACILITY HAS BEEN BARRED FOR YOUR ACCOUNT FOR 30 DAYS\n";
				cin>>ch;
				
				//switch case to handle different possibilities of loan requests
				    switch(ch)
				   {
					case 1:
						withd();
						approach='n';
						break;
					case 2:
						if(j<4)
						{
							do{	
							if(amt<=15000)
						    {
						    	double b=wopt.loan(amt,bal);
						    	if(b>bal)
						    	{
						    	bal=b;
                                cout<<"\nNow withdrawal of Rs. "<<amt<<" is possible\n"; 
								loan_opt='n';
							    }
                            	else
                                {
								cout<<"\nSorry loan has already been granted thrice. No more loan applications are possible";
                                cout<<"\nPlease choose another option\n";
                                break;
                                }
                            }
						    else
						     {
							  cout<<"You are not eligible for a loan since amount of Rs. "<<amt<<" exceeds your loan limit of Rs. 15000";
							  cout<<"\nDo you want to apply for a loan of a lesser amount(y/n)";
							  
						      if(loan_opt=='y' || loan_opt=='Y')
						           j++;
							  cin>>loan_opt;
						      if(loan_opt=='y' || loan_opt=='Y')
						      {
						         cout<<"\nEnter lesser loan amount: ";
						         cin>>amt;
						      }
						      else
						      	{
								cout<<"\nLoan request cancelled";
						      	break;
						        } 
						     }
							 }while((loan_opt=='y' || loan_opt=='Y') && j<4);
					     cout<<"YOU ARE NOT ELIGIBLE FOR LOAN FACILITY SINCE IT HAS BEEN BARRED FOR YOUR ACCOUNT FOR 30 DAYS FOR SECURITY REASONS.";	
					    }
					    else
						  cout<<"YOU ARE NOT ELIGIBLE FOR LOAN FACILITY SINCE IT HAS BEEN BARRED FOR YOUR ACCOUNT FOR 30 DAYS FOR SECURITY REASONS.";	
					 	approach='n';
						break;
					case 3:
						approach='n';
						break;
						
					default:
						i--;
						cout<<"\nPlease select an appropriate choice(1/2/3)";
						cout<<"\nYou have "<<i<<" attempts remaining else your account will be deactivated for security reasons\n";
						break;
				    }
			        }while((approach=='Y' || approach=='y') && i!=0);
			    
			    if (approach=='N' || approach=='n')
			    {
			        cout<<"\nEND OF DEFICEIT WITHDRAWAL SERVICES";
			        cout<<"\nThankyou for trusting our services";
			    }
			    else if(i==0)
			       {
			        cout<<"\nSorry we are not able to help you";
			        access=false;
			        cout<<"\nYour account has been blocked for security reasons";
			        cout<<"\nContact your nearest Bank Branch at 020-249834 or by visit to reactivate your account";
			       }
	       }
	    }
	    
	    // to display bank statement
	    void bank_statemnt(bank& b)
{
	    	string str; 
	    	
			fp<<"------------------------------------------------------------------\n";
			fp<<"                         : Summary :\n";
			fp<<"------------------------------------------------------------------\n";
			fp<<"\nNumber of transactions               : "<<srno;
			fp<<"\nNumber of deposits                   : "<<--no_of_deposits;
			fp<<"\nNumber of withdrawals                : "<<--no_of_withds;		//preincrement
			fp<<"\nNumber of loans                      : "<<--no_of_loans;
		//	fp<<"\nNumber of times credit card was used : "<<ccardused;
		//	fp<<"\nNumber of times debit card was used  : "<<dcardused;
    		fp<<"\n------------------------------------------------------------------\n";
    		fp<<"\n****************** END  OF  BANK  STATEMENT **********************";
	    	fp.close();
	    	
	    	fp.open("bank_statements.txt",ios::in);
	    	if(fp)
	    	{
	    		if(!fp.fail())
	    			while(getline(fp, str))
	    				cout<<str<<endl;
				else
					cout<<"\n******Bank Statement Cannot Be Displayed******";
			}
			else
				cout<<"\n******Bank Statement Does Not Exist******";
			//fp.close();
	    }

// user defined namespace
namespace nb{
	int netbanking()
	{
		int nbpass,wrongatt=0;
						while(wrongatt<3)  // login within 3 attempts
						{
						cout<<"\nEnter the last four digits of your bank account number: ";
						cin>>nbpass;
						
						// login by entering last four digits of your bank account
						if(nbpass==(acno_netbank_pass%10000))
						{
							cout<<"\nAccess granted";
					        return 1;
						}
						else
						{
							wrongatt++;
							cout<<"\nIncorrct entry";
						}
						}
						cout<<"\nYou have made more than three wrong attempts.\nYour account has been blocked for security reasons.\nPlease Contact your nearest Bank Branch at 020-249834 or by visit to reactivate your account";
						return 0;
	}
}

//alternatives if card is not working or unavailable
int card_down()
{
					int alt;
					
					cout<<"\n Select any one of the following alternative options: ";
					cout<<"\n\t1. Net banking\n\t2. Exit this procedure";
					cin>>alt;
					if(alt==1)
					{
						netb_res=nb::netbanking();
							if(netb_res)
							return 1;					
						else
							return 0;
					}
					else
					{
						cout<<"\n********* Exit Successful **********\n";
						return 2;
					}		
}


int main()
{
	char yesacc='y';
	create();
	//loop
 do{
 	
start:
	cout<<"\nDo you have your bank account in our Bank ?(y/n)";
	cin>>yesacc;
	
	//if account exists in database
	if(yesacc=='Y' || yesacc=='y')
	{ 
	cout<<"\n********** WELCOME TO BANKING SERVICES **************";
	bank obj;
	double balance;
	char ans,delacc='n';
	fp.open("bank_statements.txt",ios::out);
	
	afterDel:
		
	cout<<"\nPlease enter the following details\n";
	person p1;
	cin>>p1;
	if(gameOver)
	{
		 cout<<"\n********* BANK SERVICE COMPLETED **********";
		 return 0;
	}
    int flag1=0;
    
    //to check validity by matching name and account number 
	for (it = mp.begin(); it != mp.end(); it++) 
	{
		 if((*it).first==p1.accno && (*it).second==p1.name)     // or if mp[name]==value;
	    {
	    	acno_netbank_pass=p1.accno;
		    cout<<endl<<p1;
		    flag1=1;
	        break;
	    }
    }
	    if(flag1==0)      //If name doesn't match account number
		{
		
				cout<<"\n*********** Account details do not match *************";
				goto no_match;
    	}
    	
	fp<<"\n------------------------------------------------------------------";
    fp<<"\nSr.No.\tTransaction\tAmount\tBalance\t   Date\t       Time\t\n";
    fp<<"------------------------------------------------------------------\n";
	
	int ch;
	do{

		do{
			
		int mode;
		char card_availability;	
		
		fromdown2:
		
		// to select login mode
		cout<<"\n\nEnter the mode of transaction: \n1: Net banking\n2: ATM banking\n3: Foreign Exchange\n4: Locker Room\n5: Exit Bank services\t";
		cin>>mode;
		
		switch(mode)
		{
			case 1:
				netb_res=nb::netbanking();
						if(netb_res)
							goto from_online_mode;
						else
							obj.access=false;
			break;
			
			case 2: 
				cout<<"\nDo you have an atm card? (y/n) : ";
cin>>card_availability;

// if card has not been issued
if(card_availability=='n' || card_availability=='N')
{
	// to check if user already has an atm card or not
	if(litmusTest!=0)
		cout<<"\nYou already have atm card";
	else
	{
		sent=card(1);
		/////////////////////
		if(sent==2 || sent==3)
					goto from_online_mode;  // if card is working and pin number entered is correct
				else if(sent==0 || sent==-3 || sent==4 || sent==5 || sent==-2)
				{
					int abc=card_down();  // if card is inaccessible
					if(abc==1)
					{
						goto from_online_mode;
					}
					else if(abc==0)
					{
						cout<<"\nSorry no transactions are possible for your account";
						cout<<"\n End of bank services. Thank you";/////
						exit(2);
					}
					else if(abc==2)
					    goto fromdown2; 
		////////////////////
				}
	}
}

// if card has been issued
else if(card_availability=='y' || card_availability=='Y')
{
	int cord;
	if(litmusTest==0)
	{
		cout<<"\nSorry, you don't have an atm card";
	}
	else if(litmusTest>0)
	{	
		scared:
			char view;
			
		do
		{
			
		if (no_more==1)
			goto posting;
			
		cout<<"\nSelect anyone option :";
		cout<<"\n1. Use my existing atm cards\n2. Want to use another atm card : ";
		cin>>further;
		posting:
		if(further==1 || no_more==1) // if account already has 1 credit and 1 debit card
		{	
			if(no_more==1)
				cout<<"\nPlease select any one of your cards";
				
			cout<<"\n1. CREDIT CARD\n2. DEBIT CARD\n";
			cout<<"\nMy choice : ";
			cin>>cord;
			
			if(no_more==1 && cord==1)
				goto noMoreSoGoCredit;
			else if(no_more==1 && cord==2)
				goto noMoreSoGoDebit;
					
			else if(sent==2 && cord==1)
			{	
				noMoreSoGoCredit:
					
				cout<<"Welcome to credit card services";
				sent=card(2);
				///////
				if(sent==2 || sent==3)
					goto from_online_mode;
				else if(sent==0 || sent==-3 || sent==4 || sent==5 || sent==-2)
				{
					int abc=card_down();
					if(abc==1)
					{
						goto from_online_mode;
					}
					else if(abc==0)
					{
						cout<<"\nSorry no transactions are possible for your account";
						cout<<"\n End of bank services. Thank you";/////
						exit(2);
					}
					else if(abc==2)
					    goto fromdown2; 
				////////
			}
		}
			else if(sent!=2 && cord==1)
			{
				cout<<"\nSorry you do not have a credit card";
			}
			else if(sent==3 && cord==2)
			{	
				noMoreSoGoDebit:
					
				cout<<"Welcome to debit card services";
			    sent=card(3);
				///////
				if(sent==2 || sent==3)
					goto from_online_mode;
				else if(sent==0 || sent==-3 || sent==4 || sent==5 || sent==-2)
				{
					int abc=card_down();
					if(abc==1)
					{
						goto from_online_mode;
					}
					else if(abc==0)
					{
						cout<<"\nSorry no transactions are possible for your account";
						goto no_match;
					}
					else if(abc==2)
					    goto fromdown2; 
				////////
		}
		}
			else if(sent!=3 && cord==2)
				cout<<"\nSorry you do not have a debit card";
		}

		else if(further==2)  // if user wants more cards
		{
			int aa=card(1);
			if(aa==-6)
				goto scared;
			else
				no_more=1;
		}
		cout<<"\nDo you want to continue ATM Banking? (y/n)";
		cin>>view;
	}while(view=='y' || view=='Y');			
	}
}
		            break;
		            
		            //for foreign currency exchange
		        case 3:
		        	for_exchange<double>();   
					break;
		        	
		        	// to locker room 
				case 4:
					cout<<"\n****** Welcome to the Locker Room ******";
					lockerIsMyChoice();
					break;
					
					//to exit from all the bank services
				case 5:
					goto way2;
					
				default:
					cout<<"\nPlease enter the available choice";
		        }
		        }while(obj.access==true); // i.e. while the account is not blocked
		
if(obj.access==false)
    goto no_match;   // if account has been blocked
			
from_online_mode:
		
	cout<<"\nEnter the transaction you want to perform";
	cout<<"\n\t1.Deposit\n\t2.Withdrawal\n\t3.Display Balance\n\t4.Display Bank Statement\n";
	cin>>ch;
		
	if(obj.access) // if account is not blocked
	{
	switch(ch)
	{
 		case 1:
 			 	
			balance=obj.deposit();
			if (balance!=0)
				cout<<"\nBalance is: "<<balance;
			else
			   cout<<"\nDeposit request cancelled";
			break;
			
		case 2:
			  
			obj.withd();
			break;
			
		case 3:
			cout<<"\nBalance is: "<<obj.bal;
			break;
			
		case 4:
    		bank_statemnt(obj); // to dispaly the bank statement stored in the file
			break;
			
		default:
			cout<<"\nPlease enter the right selection(1/2/3/4)";
			break;
	}	
	    if(obj.access)
			cout<<"\n\nDo you want to continue to avail the bank services ? (y/n)"; //to continnue or exit from all the bank services
		else
		 break;	
    }
    
    }while(getche()=='y' || getche()=='Y');
    goto way2;
    
no_match:
	
    cout<<"\nDO YOU WANT TO RESTART?(y/n)"; //if account has been blocked
    cout<<"\nIf yes and if you've performed some previous transactions:\n then they are cancelled and your balance reduces to min. balance of Rs. 500.\nIf your account or any mode of transaction is blocked it will be reactivated\n\nIf no then our services are complete.\n";
    cin>>ans;
    if(ans=='Y' || ans=='y')
       {
       	res=1;
	    system("cls"); //to clear the screen
	    obj.access=true;
	    caccess=1; daccess=1;
        goto start;
       }
    else
    {
    	res=0; //if I don't want to restart
	}
        
  	way2:   
    cout<<"\n********** END OF TRANSACTIONS ************";
    cout<<"\nDo you want to close your account? (y/n) "; 
    cin>>delacc;
    if(delacc=='Y' || delacc=='y')
    {
        del(p1.accno);  
        gameOver=1;
        cout<<"To check whether your account has been deleted, please enter your details";
        goto afterDel;
    }

     finally:           
    cout<<"\n********* BANK SERVICE COMPLETED **********";
    
	return 0;
}

// if I want to create my new account
else 
{   
    int key;
	cout<<"\nWould you like to open your bank account in our bank at a minimum balance of Rs.500 ? (y/n)";
	cin>>accopen;
	if(accopen=='y' || accopen=='Y')
	{
		cout<<"\nPlease enter the following details:\n";
		person p2;
	    cin>>p2;
		cout<<"\nWhich type of account do you want to open ?\nSelect anyone:\t1.SAVINGS ACCOUNT\n                2.CURRENT ACCOUNT\n";
		cin>>acctype_choice;
        
        int lower,upper;
        
        //count indicates the number of such numbers that get displayed
		if (acctype_choice==1)
		    {
			    lower = 10000, upper = 49999;
			    key=printRandoms(lower, upper);
			    cout<<"\nYour SAVINGS ACCOUNT has been opened successfully with number: "<<key<<endl;
		    }
		if (acctype_choice==2)
		   {
		        lower = 50000, upper = 80000; 
		        key=printRandoms(lower, upper);
			    cout<<"\nYour CURRENT ACCOUNT has been opened successfully with number: "<<key<<endl;
		   }
			
	    insert(key);
	    mp.insert(pair<int,string>(key,p2.name));
	    
	    p2.accno=key;
		cout<<p2;  // to display the details entered by the user
		accopen='N';
	}
	else //if I don't want to open my account in this bank
	{
		cout<<"\nOk. Thankyou."; 
		cout<<"\n***** BANK SERVICES COMPLETE *****";
		exit(1);
	}
}
}while(1); // infinite loop
}
