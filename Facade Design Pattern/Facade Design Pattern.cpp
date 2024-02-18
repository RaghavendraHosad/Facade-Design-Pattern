// Facade Design Pattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//Resctricting to 4 common transactions to study purpose
namespace atm {
	enum choice { Balance = 0, Withdraw, Deposit, Statement };
}


//SubSystem 1 - A card reader is the essential part of ATM. that validates card inserted!
class CardReader {
private:
public:
	bool atmCard()
	{
		//read card informations
		//validate card
		//Hope card is valid and allow user to do transactions.

		return true;
	}
};

//SubSystem 2 - After user enter PIN, amount and account type. ATM constructs a message and send to HOST
class MessagetoHost {
private:
public:
	bool constructHostMessage()
	{
		//collect info such as amount to withraw & construct message and send to host
		//Successfuly sent message
		return true;
	}
};

//SubSystem 3 - Host evaluates account and balance, Updates account and send back Client message
//it could be Operational, Functional or command type or combination of one or more
class MessagetoClient {
public:
	bool constructClientMessage()
	{
		//Update amount deduction against account# at host
		//Construct client message to instruct withdrawal and send ACK
		//Hope succesfully recieved it!
		return true;
	}
};

//SubSystem 4 - Presenter presents the cash.
class Presenter {
private:
public:
	void PresentMoney()
	{
		cout << "Presents cash/bills!" << endl;
	}
};

//SubSystem 5 - As indicated by the host message ATM instructs dispensor to 
//dispence cash of different denomination
class Dispenser {
private:
public:
	void DispenseMoney()
	{
		cout << "Dispenses the cash!" << endl;
	}
};

//SubSystem 6 - if user would like to know his balance!
class AccountBalanceCheck {
private:
	double amt;
public:
	double getBalance()
	{
		//Assuming Rs 100.00 in account
		amt = 100.00;
		return amt;
	}
};

//SubSystem 7 - Print Statement if User wish to!
class StatementPrinter {
private:
public:
	void getStatement()
	{
		cout << "Printing last 5 transaction's statement to recipt!" << endl;
	}
};

//ATM facade class
class Atm {
private:
	CardReader objCardReader_;
	MessagetoHost objMessagetoHost_;
	MessagetoClient objMessagetoClient_;

	Dispenser objDispenser_;
	Presenter  objPresenter_;
	AccountBalanceCheck objAccountBalanceCheck_;
	StatementPrinter objStatement_;

public:
	Atm()
	{
		InsertCard();
		MessageHost();
		MessageClient();
	}

	void uiWindow(atm::choice c) {
		if (c == atm::Balance)
		{
			CheckBalanceBalance();
		}
		else if (c == atm::Withdraw)
		{
			WithdrawCash();
		}
		else if (c == atm::Deposit)
		{
			//TO DO
		}
		else if (c == atm::Statement)
		{
			CheckBalanceBalance();
			PrintStatement();
		}
	}

	bool InsertCard() {
		return objCardReader_.atmCard();
	}

	bool MessageHost()
	{
		return objMessagetoHost_.constructHostMessage();
	}

	bool MessageClient()
	{
		return objMessagetoClient_.constructClientMessage();
	}

	bool CheckBalanceBalance() {
		return objAccountBalanceCheck_.getBalance();
	}
	void WithdrawCash() {
		objDispenser_.DispenseMoney();
		objPresenter_.PresentMoney();
	}
	void PrintStatement()
	{
		objStatement_.getStatement();
	}
	//bool DepositCash() {
	// TO DO
	//}
};


int main(int argc, char argv[])
{
	Atm objAtm;
	objAtm.uiWindow(atm::Balance);
	objAtm.uiWindow(atm::Withdraw);
	return 0;
}