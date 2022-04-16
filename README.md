# Bank-Management-System

# Object Oriented Programming (OOP) and Fundamentals of Data Structures (FDS) Mini Project Documentation


### The Bank Management System is a project in Object Oriented Programming (OOP) and Fundamentals of Data Structures (FDS) implemented using almost all the concepts in OOP. I have also included many concepts of Data Structures and Algorithms. <br/> It consists of about 2064 lines of code and many other lines as comments I really learnt a lot from this self-motivated hands on practical experience which is similar to software development.

## 📌FEATURES :
1.	creating the bank database
2.	checking validity of customers by matching name with account number
3.	restart if account details do not match or if account has been blocked
4.	net banking 
5.	credit card banking
6.	debit card banking
7.	to issue upto two ATM cards only
8.	alternative procedures if card is blocked
9.	display current bank balance
10.	savings account
11.	current account
12.	minimum balance of account (Rs. 500) should be maintained
13.	Deposit (user can deposit upto a certain non-zero amount on a single day)
14.	Withdrawal (only if balance is greater than minimum balance)
15.	Alternative procedures if withdrawal amount exceeds the minimum balance  
16.	Loan services if withdrawal amount exceeds the minimum balance  
17.	foreign currency exchange
18.	locker room system
19.	(doubly linked priority) queue system to access lockers
20.	display number of members in the queue
21.	display the locker number to which service had been provided before and after you using the previous and next field pointers of the linked queue.
22.	low and high access priority lockers
23.	deleting/closing bank account from bank bank database 
24.	inserting one's bank account details in bank database
25.	blocking/deactivating one's account
26.	display bank statement (transactions)
27.	many other error detection features....

## 📌CONCEPTS used :
1.	different data types ( int , char  , bool , float , double )
2.	user defined header files
3.	header files or C++ standard libraries ie. preprocessor derectives (iostream, conio.h, string, map, math.h, time.h, stdlib.h, windows.h, stdio.h, iterator, fstream and so on)
4.	macros definition to initialise the minimum balance of the account as a constant
5.	global and local variables
6.	predefined time() function to display system time
7.	file handling to read (input), store, retrieve & display (output) the bank statement (transactions) on a permanent basis
8.	user defined datatype : structure to create bank database and define the doubly linked priority queue
9.	functions called with and without passing parameters
10.	default arguments
11.	arithmetic operators , increment and decrement ( + , - , * , / , % , ++ , -- )
12.	assignment operators ( = ,  , += , -= ,  ) 
13.	comparison / relational operators ( > , < , <= , >= , == , != ) 
14.	logical operators ( && , || , ! )
15.	this pointer
16.	pre and post increment and decrement
17.	if – else if – else programming constructs
18.	nested conditional statements
19.	switch case with default case
20.	nested switch case
21.	different escape sequences like \n , \t , \r
22.	return statement
23.	user defined datatype : class
24.	friend function
25.	sizeof() operator
26.	overloading cin and cout objects of the iostream class by friend function
27.	scope resolution operator to define members of the class outside the scope of the class
28.	for , while , do while looping statements
29.	getch() and getche()
30.	break statement
31.	exception handling in file operations
32.	static variables and datamembers
33.	friend function
34.	friend class
35.	exception handling by try , catch and throw statements
36.	string datatype
37.	user defined namespace for netbanking
38.	restricted number of attempts while entering details controlled by looping statememts
39.	goto statement
40.	map associative container in STL to map the account number with the account holder name
41.	exit() function
42.	pointers to objects
43.	pointers to arrays
44.	inheritance : multiple, multilevel, hierarchical, hybrid
45.	compile time polymorphism (operator and function overloading)
46.	run time polymorphism (method overriding and virtual functions)
47.	linked list : creation , deletion , insertion , display, linear searching and recursively binary searching the data of the nodes, bubble sorting data fields of nodes
48.	malloc() function to allocate memory and create a node 
49.	 free() function to deallocate memory from the node
50.	pointers in inheritance
51.	virtual base class in ATM banking
52.	user defined random number generator to generate account numbers and pin numbers for ATM cards
53.	class templates
54.	function templates
55.	mutable keyword
56.	typename keyword
57.	constant variables 
58.	constant objects of classes
59.	membership operators
60.	inline functions
61.	arrays
62.	virtual destructor
63.	default constructor
64.	 parameterised constructor
65.	copy constructor
66.	call by reference
67.	new and delete memory management operators used for variables and objects of a class
68.	user defined quicksort
69.	user defined bubble sort
70.	user defined linear search 
71.	user defined recursive binary search
72.	a variant of for loop
73.	user defined multiple stack handled using a single array to hold locker numbers and assign them to customers as per requirement
74.	user defined doubly linked priority queue to avail the locker services for yourself along with other customers in the same queue
75.	count the number of members in the queue
76.	inserts / enqueues you in the queue and then sorts the queue as per priority of your locker number
77.	removes / dequeues the customers from the queue once he/she has been provided locker services 
78.	user defined functions to check if stack and queue are full or empty
79.	Sleep() function to cause some delay while the bank is providing locker room services to customers in the queue
80.	Different logics to handle features of error detection

## 📌PROGRAM CODE :
It consists of 5 files :
1 C++ file with extension .cpp and 5 user defined C++ header files which are as follows :
1.	DriverCode.cpp : one main page of driving code in C++

2.	createBankDatabase.h : to store bank account details and for operations between them
3.	card_banking.h : to handle ATM banking
4.	Foreign_Exchange.h : to handle foreign currency exchange
5.	LockerRoom.h : to deal with high and low priority lockers
6.	LockerQueue.h : to create doubly linked priority queue and enqueue , dequeue customers in it


## 📌Note : 
I could have used the Standard Template Library (STL) in C++ for sorting , binary searching , deque , stack , etc. but since I wanted to involve most of the C++ concepts to test my creative problem solving , technical , analytical & logical skills , efficiency and self-sufficiency, I myself have designed and defined these highlighted algorithms and data structures to satisfy my requirements. These can also be replaced by the predefined utilities of the STL in C++.

## 📌Further improvements and potential upgrades in this project to be done in future : 
1.	Use of exception handling to prompt the user and guide the user input
2.	set locker password
3.	more features for the locker room
4.	forgot password option and security questions
5.	net banking password logic
6.	reactivate the blocked services if the user has contacted the bank
7.	Handle multiple ATM cards
8.	pay back loans and credit before terminating the program
9.	credit card limit
10.	change card password
11.	user defined password length restricted to n characters
12.	user defined password should include specified characters
13.	provide more bank services , etc.

## 📌More concepts that can be included in this project in future :
1.	pointer to function
2.	shared pointer
3.	special pointer
4.	abstract base class
5.	Type casting (implicit and explicit)
6.	Pointers to Pointers
7.	Return pointers from functions
8.	void pointer
9.	to indicate monetary transactions done via debit and credit.
10.	number of times credit and debit card has been used , etc.


### Thank you. 

### Best regards ,
### Joel Silas
### JSPM’S JSCOE , Hadapsar , Pune – 411028
### Department of Computer Engineering








