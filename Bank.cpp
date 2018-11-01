#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h> //to use sleep in UNIX env
#include <sstream> //to convert int to string

using namespace std;

class bank
{
	private:
		string acc_holder, acc_type, acc_no, s,u,v;
		double balance;
	public:
		int flag=0;char c;
		
		string asc(string st) //to count ascii value of acc_holder
		{
            int i, sum = 0; 
            for (i = 0; st[i] != '\0'; i++)
                sum = sum + st[i];
            ostringstream temp;
            temp<<sum;
            return temp.str();
            //return sum;
        }

		void initialize()
		{
			int choice;
			double amt;

			cout<<"\nEnter the Account holder's Name:-  ";
			cin>>acc_holder;

			cout<<"\n---- Select the account type ---- \n";
			cout<<"\n1. Savings Account \n";
			cout<<"\n2. Current Account \n";
			cin>>choice;

			switch(choice)
			{
				case 1: acc_type="Savings Account";
					break;
				case 2: acc_type="Current Account";
					break;
			}

			cout<<"Enter the amount:-  ";
			cin>>amt;
			s = asc(acc_holder);
			u = acc_holder[2];
			v = acc_type[1];

		  system("clear");
      cout<<"Acoount No. : "<<u + s + v;
			cout<<"\n\n--- Account Created Succesfully ---";
			cin.get();
			usleep(5000000);
			system("clear");
			
			deposit(amt);
			flag = 1;
		}

		void withdraw(double amt)
		{
			if(balance - amt >= 0)
			{
				cout<<"\n\nAmount Withdrawn Succesfully:-  "<<amt;
				balance = balance - amt;
			}
		}

		void deposit(double amt)
		{
			balance = balance + amt;
			cout<<"\nAmount Debitted successfully \n";
		}

		double get()
		{
			return balance;
		}

};

int main()
{
	double amt;
	bank a1;
	int choice;
	do
	{
		//system("clear");
		cout<<"\n|----------BANK----------|";

		if(a1.flag != 0)
			cout<<"[ Balance = "<< a1.get() <<"  ]";
		else
			cout<<"\n\n1. Create New Account";

		cout<<"\n2. Deposit Amount";
		cout<<"\n3. Withdraw Amount";
		cout<<"\n0. Exit \n";

		cout<<"--> ";
		cin>>choice;

		if(choice == 2 || choice == 3)
		{
			do
			{
				system("clear");
                		cout<<"\n\tEnter the Amount\n\t--> ";
                		cin>>amt;
				system("clear");

			}while(amt==0.0);
		}

		switch(choice)
		{
			case 1: a1.initialize();
				break;

			case 2: a1.deposit(amt);
				break;

			case 3: a1.withdraw(amt);
				break;

			case 0: cout<<"\n--- THANK YOU ---\n";
				break;
		}
	}while(choice!=0);
}
