#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

/*
functionalities using oops

first it'll ask account number and passowrd of user. if we'll enter wrong account number it'll show
invalide user.
if we enter correct detail then, it'll display the function given below

1. check balance 

=>  to check amount in our bank
 
 
 
2. cash withdraw

=> if we'll enter 0, then it'll show invalid amount. so enter valid amount. once we enter valide amount,
if it'll substract amount that we enter and display correct amount that left in our bank.



3. user details

=>   it'll show user detail



4. update mobile number

=> if we want yto update current mobile number then, we have to enter current mobile number, then only we can update it with new number. 
if we fail to enter old number then, it'll show incorrect old number.


5. exit

=> to exit
*/

class atm
{
	private:     // private date member
		long int account_no;
		string name;
		int PIN;
		double balance;
		string mobile_no;
    public:    // public member function
        
        void setData(long int account_no_a, string name_a, int PIN_a, double balance_a, string mobile_a)
        {
        	// assigning value to private member
        	account_no= account_no_a;
        	name= name_a;
        	PIN=PIN_a;
        	balance= balance_a;
        	mobile_no= mobile_a;
		}
		
		long int getAccount()
		{
			return account_no;
		}
		
		string getName()
		{
			return name;
		}
		
		int getPIN()
		{
			return PIN;
		}
		
		double getBalance()
		{
			return balance;
		}
		
		string getMobileNo()
		{
			return mobile_no;
		}
		
		void setMobile(string mob_prev, string mob_new)
		{
			// to update new mobile number
			
			if(mob_prev==mobile_no)
			{
				mobile_no= mob_new; // if enter old mmobile number is correct then, update new mobile number
				cout<<"\n Successfully updated mobile number.";
				_getch(); // getch() hold screen untill user press any key
			}
			else
			{
				cout<<"\n Incorrect old mobile number!!";
				_getch();
			}
		}
        
		void cashWithDraw(int amount_a)
		{
			// cashwithdraw function is used to withdraw money from ATM
			if(amount_a>0 && amount_a<balance) // entered amount validity
			{
				balance= (double)balance- amount_a;
				cout<<"\n Please Collect Your Cash";
				cout<<"\n Available Balance: "<<setprecision(15)<<balance;
				_getch();
			}
			else
			{
				cout<<"\n Invalid Input or Insufficient Balance";
				_getch();
			}
		}	
	  	
};


int main()
{
	// for user authentication
	int choice=0;
	int enterPIN;
	long int enterAccountNo;
	
	system("cls");  // system function is used to clear the screen
	
	// create user(object)
	atm user1;
	
	// set user details( into object) and here we are setting it by default data
	
	user1.setData(1234567, "Prabhaa", 9999, 45000.909, "1234567899");
	
	do
	{
		system("cls");
		
		cout<<"\n ********************  WELCOME TO ATM  ********************\n";
		cout<<"\n Enter Your Account Number: ";
		cin>>enterAccountNo;
		
		cout<<"\n Enter PIN: ";
		cin>>enterPIN;
		
		
		//check whether enter values matches with user details or not
		
		if( (enterAccountNo==user1.getAccount()) && (enterPIN==user1.getPIN()))
		{
			
			do
			{
				int amount=0;
				string oldMobileNo, newMobileNo;
				
				system("cls");
				
				
				//user interface
				cout<<"\n ********************  WELCOME TO ATM  ********************\n";
		        cout<<"\n Select Options";
		        cout<<"\n 1. Check Balance";
		        cout<<"\n 2. Cash Withdraw";
		        cout<<"\n 3. Show User Details";
		        cout<<"\n 4. Update Mobile Number";
		        cout<<"\n 5. EXIT \n";
		        
		        //enter choice
		        cin>>choice;
		        
		        switch(choice)
		        {
		        	case 1:
		        		cout<<"\n Your Bank Balance is: "<<user1.getBalance();
		        		
		        		_getch();
		        		break;
		        	
					case 2:
					   cout<<" Enter the amount: ";
					   cin>>amount;	
					   // calling cashWithdraw function passing withdraw amount
					   user1.cashWithDraw(amount);
					   
					   break;
					   
					case 3:
					    cout<<"\n ************* USER DETAILS *************";
						cout<<"\n Account Number: "<<user1.getAccount();
						cout<<"\n Name: "<<user1.getName(); 
						cout<<"\n Balance: "<<setprecision(15)<<user1.getBalance();
						cout<<"\n Name: "<<user1.getMobileNo();
						_getch();
						break;
						
					case 4:
					    cout<<"\n Enter Old Mobile Number: ";
						cin>>oldMobileNo;
						
						cout<<"\n Enter New Mobile Number: ";
						cin>>newMobileNo;
						
						user1.setMobile(oldMobileNo, newMobileNo);
						break;	
						
					case 5:
					    exit(0);
					
					default:
					cout<<"\n Enter Valid Data !!!";		
				}
			}while(1);
		}
		else{
			cout<<"\n User Details are Invalide !!";
			_getch();
		}
		
	}while(1);
	
	return 0;
	
}


