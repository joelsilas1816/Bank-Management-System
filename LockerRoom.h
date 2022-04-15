#include<iostream>
#include<conio.h>

// user defined header file to include the Doubly Linked Priority Queue system
#include"LockerQueue.h"   

char have_ans , want_ans , want_another_ans , wl;
int flag=0, opted_for_locker, non_zero_cnt;

int copymyLockers[10];

//inline functions
inline void haveLocker()
		{
			cout<<"\n\nDo you have a locker ? (y/n) ";	
			cin>>have_ans;
		}
		
inline char wantLocker()
		{
			cout<<"\nDo you want a locker ? (y/n) ";
			cin>>want_ans;	
			return want_ans;	
		}
	
class locker
{
	private:
		int myLockers[10], lockerIndex=0, len;
		static int topl, toph;
	public:
		
		// friend class
		friend class security;
		
		bool lpIsEmpty()       //if stack for lower priority lockers is empty i.e. these lockers have not yet been assigned to anyone 
		{
		return (topl==len);
		}
		
		bool hpIsEmpty()	//if stack for higher priority lockers is empty i.e. these lockers have not yet been assigned to anyone 
		{
		return (toph==len/2);
		}
		
		bool lpIsFull()	//if stack for lower priority lockers is full i.e. all these lockers have been assigned to customers 
		{
		return (topl==len/2);
		}
		
		bool hpIsFull()		//if stack for higher priority lockers is full i.e. all these lockers have been assigned to customers 
		{
		return (toph==0);	
		}
		
		int assign(int a[] , int);  //passing arrays as parameters to a function
		
		void avail(int aa[]);
		
		void display()
		{
			cout<<"\nWelcome to Locker Access procedure";
		}
		
		virtual	~locker()   //virtual destructor
		{ }	
}lr; //object of class locker

int locker::toph=0;	//static datamembers
int locker::topl=5;

//function definition to swap  
void qswap(int *a , int* b)   
{
	int hold=*a;
	*a=*b;
	*b=hold;
}

//partitioning for quicksort 
int partition(int myLockers[] , int lb , int ub)
{
	int pivot=myLockers[lb];
	int i=lb, j=ub;
	
	while(i<j)
	{
		if(myLockers[i]<pivot)
			i++;
		if(myLockers[j]>pivot)
			j--;
		if(i<j)
			qswap(&myLockers[i],&myLockers[j]);  //call by reference
	}
	qswap(&myLockers[j],&pivot);
	return j;
}

//quicksort algorithm
int quickSort(int myLockers[] , int lb , int ub)
{
	if(lb<ub)
{
	int loc=partition(myLockers , lb , ub);
	quickSort(myLockers , lb , loc-1);
	quickSort(myLockers , loc+1 , ub);
}
}

//recursive approach to binary search algorithm to check if the user entered locker number belongs to the him/her or not
bool binSearch( int myLockers[] , int key , int low , int high)
{
	quickSort(myLockers , low , high);
	
	int mid;
	if(low>high)
		return false;
	
	mid=(low+high)/2;
	
	if(myLockers[mid]==key)
		return true;
	else if(myLockers[mid]<key)
		binSearch( myLockers , key , mid+1 , high );
	else
		binSearch( myLockers , key , low , mid-1 );		
}

//friend class definition
	class security
	{
		int myLno;
		public:
			
			void disp(locker &l)
			{
				l.display();
			}
			
			void accessLocker(locker &l)
			{
				non_zero_cnt=0;
				char rep;
				for(int h : l.myLockers)  //a new variant of for loop i.e. h represents an element in l.myLockers array
					{
						if(h!=0)
							non_zero_cnt++;
					}

					int i=0, nonZeromyLockers[non_zero_cnt];
						for(int h : l.myLockers)        
					{
						if(h!=0)
						{
							nonZeromyLockers[i]=h;
							i++;
						}
					}
					
				int lb=0, ub=sizeof(nonZeromyLockers)/sizeof(nonZeromyLockers[0])-1;
		
				do
				{
				cout<<"\nEnter Locker Number : ";    
				cin>>myLno;
				
					if(binSearch(nonZeromyLockers , myLno , lb , ub))
				{
					cout<<"\nAccess granted";
					LockerQueue(myLno);
				}
				else
				{
					cout<<"\nSorry this locker does not belong to you !!!";
				}
					
				cout<<"\n\nDo you want to continue ? (y/n) : ";
				cin>>rep;
				}while(rep=='Y' || rep=='y');
				
			}
	};	 

		int locker::assign(int lockersAvailable[] , int length)
		{	
			int lockerChoice;
			char again;
			len=length;
			 // push and pop operations are done at the front of the respective lists
				
		do{
			cout<<"\n----------------------------------------------------------------------- ";
			
			if(wl=='Y' || wl=='y')
			{
				cout<<"\nLocker assignment procedure has been started";
			do{
			cout<<"\nSelect any one :\n 1. High Priority Locker \n 2. Low Priority Locker";
			if(hpIsFull( ))
					cout<<"\nAll high priority lockers are available";
			if(lpIsFull( ))
					cout<<"\nAll low priority lockers are available";
			cout<<endl;
			cout<<"\nChoice : ";
			cin>>lockerChoice;
			
			if (lockerChoice==1)
			{
				if(hpIsEmpty( ))
					cout<<"\nSorry all high priority lockers have been occupied";
				else	
				{
				cout<<"\nYour Locker number is : "<<lockersAvailable[toph];
				myLockers[lockerIndex]=lockersAvailable[toph];
				lockerIndex++;
				lockersAvailable[toph]=0;
				toph++;
				}
				break;
			}
			else if(lockerChoice==2)
			{
				if(lpIsEmpty( ))
					cout<<"\nSorry all low priority lockers have been occupied";
				else	
				{
				cout<<"Your Locker number is : "<<lockersAvailable[topl];
				myLockers[lockerIndex]=lockersAvailable[topl];
				lockerIndex++;
				lockersAvailable[topl]=0;
				topl++;
				}
				break;
			}
			else
				cout<<"\nPlease enter an appropriate choice";
				
		}while(1);
	
			for(int a=0,z=a ; a<10 ; a++,z++)             //multiple conditions in a for loop
				copymyLockers[z]=lockersAvailable[a];
			
			avail(lockersAvailable);
			
			flag++;
			cout<<"\n\nDo you want another locker?(y/n)";
			cin>>again;
			if(again=='n' || again=='N')
				return 1;
			}
		else
		{
			cout<<"\nSorry you don't have a locker";
			return 0;
		}
			}while(again=='Y' || again=='y');
}

		void locker::avail(int la[])
		{
			cout<<"\n\nLockers available are : \n";
			cout<<"\tHigh Priority Lockers : ";
		for(int i=0;i<len;i++)
		{
			if (i==5)	
				cout<<"\n\tLow Priority Lockers  : ";
			if (la[i]==0)
				cout<<"--\t";   // i.e. this locker number has been already assigned 
			else
				cout<<la[i]<<"\t";
		}
		}
	
void lockerIsMyChoice()
{

	int lch;
	haveLocker();
	if( flag==0 && (have_ans=='y' || have_ans=='Y'))  // flag indicates that this is the first time the user is using Locker room services
	{
		cout<<"\nSorry you don't have a locker";
		return;	
	}
	else if(flag!=0 && (have_ans=='n' || have_ans=='N') && opted_for_locker)
	{
		cout<<"\nYou have "<<non_zero_cnt<<" lockers" ;
	}
	
	if(flag==0)
	{
		wl=wantLocker();
		if(wl!='y' && wl!='Y')
		{
			cout<<"\nSorry you don't have a locker";
			return;	
		}		
	}
	
	if(flag!=0 && opted_for_locker)
	{
		cout<<"\n1. Access already owned lockers\n2. Want more lockers";
		cout<<"\nEnter choice: \t";
		cin>>lch;
		do{
		
		switch(lch)
		{
			case 1:
				if(opted_for_locker)
					goto MyLockerExists;
				else
				{
					cout<<"\nSorry you don't have a locker";
				}
			// no need of break;
			case 2:
				want_another_ans='Y';
				break;
			default:
				cout<<"Please enter the available choice";
				break;
		}
		}while(lch!=1 && lch!=2);
	}
		
	int lockersAvailable[10];
	
	if((have_ans=='n' || have_ans=='N') && (wl=='Y' || wl=='y'))
	{
			for(int r=0;r<10;r++)
				lockersAvailable[r]=0;
	
	int length=sizeof(lockersAvailable)/4; //or length=10
	if(lch!=2)
		{
	cout<<"\nInitially : ";
	
	for( int k=0 ; k<length ; k++ )
		cout<<*(lockersAvailable + k);
	
	cout<<"\nCreating Lockers : ";
	int j=11, topl=0, toph=length/2 ;
	
	for(int i=1; i<length+1; i++)   // user defined multiple stack
	{
		if ((topl!=length/2 ) && (toph!=length))
		{
			lockersAvailable[topl]=j;
			topl++;
			lockersAvailable[toph]=j+5;
			toph++;
			j++;
		}
	}
}
	if(lch==2)
		{
			int g=0;
			for(int aa : copymyLockers)
			{
				lockersAvailable[g]=aa;
				g++;
			}
		}
	cout<<"\nLockers available are: ";
	cout<<"\n\tHigh Priority Lockers (1 to 15) : ";
	
	for( int i : lockersAvailable)
	{	if(i==0)
			cout<<"--\t";
		else
			cout<<i<<"\t";
		if(i==15)
			cout<<"\n\tLow Priority Lockers (16 to 30) : ";
	}

		if(lr.assign(lockersAvailable,length))
			opted_for_locker= 1;
		else
			opted_for_locker= 0;
	}
	if(opted_for_locker)   // if user has lockers then he can access them
	{
		MyLockerExists :
		
		security s;
		s.disp(lr);
		s.accessLocker(lr);
	}
	
}
