#include<iostream>
using namespace std;

//generic programming by using class templates 
template <class T>
class exchange
{
	public:
		//mutable keyword
	mutable int from, to;
	mutable T fr,fy,fd;

		exchange(int f, int t)
		{
			from=f;
			to=t;
			fr=0,fy=0,fd=0;
		}
		
		void from_to() const
		{
			while(1)
			{
			cout<<"\n 1. Rupee\n 2. Dollars\n 3. Yen";
			
			while(1)
			{
				cout<<endl<<" FROM : "; 
			    cin>>from;
			    
			    if (from<1 || from>3)	
					cout<<"\nPlease enter an appropriate choice (1/2/3)";
			    else
			    	break;   	
			}
			
			while(1)
			{	
				cout<<endl<<" TO : ";   
				cin>>to;
				
				if (to<1 || to>3)	
					cout<<"\nPlease enter an appropriate choice (1/2/3)";
			    else
			    	break;   	
			}
			
				if (from==to)
				{
					cout<<"\n****** Conversion must take place between 2 different currencies ******";
					cout<<"\nPlease re-enter your choices";
				}
				else   
					break;
			}
		}
		
		void money(T fm) const
		{			
		if(from==1)
			fr=fm;
		else if(from==2)
			fd=fm; 
 		else if(from==3)
			fy=fm;
		}
		
		void convert() const
		{
			switch(from)
			{
				case 1:
					cout<<endl<<fr<<" rupees is ";
					switch(to)
					{
						case 2:    cout<<fr*0.014<<" in dollars";      break;
						case 3:    cout<<fr*1.41<<" in yen";          break;	
					}
					break;
					
				case 2:
					cout<<endl<<fd<<" dollars is ";
					switch(to)
					{
						case 1: cout<<fd*73.7749<<" in rupees";      break;
						case 3: cout<<fd*103.53<<" in yen";         break;	
					}
					break;
					
				case 3:
					cout<<endl<<fy<<" yen is ";					
					switch(to)
					{
						case 1:  cout<<fy*0.71<<" in rupees";      break;
						case 2:  cout<<fy*0.0097<<" in dollars";		break;	
					}	
					break;	
			}
		}
};

// function templates
template<typename A>
void for_exchange()
{
	int i=0;
	A x;
	char again;
	
	cout<<"\n***** Welcome to Foreign Exchange Services *****";
	
repeat:	

		// creating a constant object of the class template in a function template
		const exchange<double> m(0,0);
		m.from_to();
		
		cout<<"\n Enter the amount in";
	
		if(m.from==1)
			cout<<" Rupees: ";
		else if(m.from==2)
			cout<<" Dollars: ";
		else
			cout<<" Yen: ";
			
		cin>>x;
		
		m.money(x);
		m.convert();
	
	cout<<"\n\nDo you want to continue ? (y/n) : ";
	cin>>again;
	
	if (again=='Y' || again=='y')
	{
		i++;
		goto repeat;
	} 
		
		cout<<"\nTotal number of foreign exchanges is: "<<i+1<<endl;	

}

