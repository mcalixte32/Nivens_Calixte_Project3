// Mikeson Calixte: Completed Section 3 (Mode M, month validation,
// and a for loop) and Section 6 (summary output).
// Test 7: I tested 12 months at 3.68% to see how my savings grow over one year.
/*
ENGR140 - Project3 - DN - MC.cpp : This file contains the 'main' function.Program execution begins and ends there.
1. Savings rate 3.68 %, from my savings account at Axos bank 10 / 01 / 2026, https ://www.axosbank.com

	2. The yearly rate is divided by 12 so you can apply the rate evenly to each month.The balance grows a little faster each month
	becuase the interest earning the month before is added to the overall balance.This means the interest rate is working on a bigger
	balance each month.

	*/
#include <iostream>
#include <iomanip>
;

int main()
{

	// Variables
	double start_balance;
	double deposit;
	double rate;
	char mode;
	double balance;
	double interest;
	double total_deposits = 0.0;
	double total_interest = 0.0;
	int month = 0;
	double goal = 0.0;


	// Section 1: read and validate the three inputs

	// Get the starting balance
	do {
		std::cout << "Please enter a starting balance: ";
		std::cin >> start_balance;
		if (start_balance < 0) {
			std::cout << "Error, balance is less than zero. \n";
		}
	} while (start_balance < 0);



	// Get the monthly deposit
	do {
		std::cout << "Please enter the monthlhy deposit: ";
		std::cin >> deposit;
		if (deposit <= 0 || deposit > 5000) {
			std::cout << "There was an error with the deposit amount.\n";
		}
	} while (deposit <= 0 || deposit > 5000);

	do {
		std::cout << "Please enter the savings rate: ";
		std::cin >> rate;
		if (rate < 0 || rate > 15) {
			std::cout << "There was an error with the savings rate.\n";
		}
	} while (rate < 0 || rate > 15);

	balance = start_balance;

	// Section 2: Choose a Mode
	std::cout << "Plan by (M)onths or by (G)oal? Enter 'M' or 'G': ";
	std::cin >> mode;
	switch (mode) {
	case 'M':
	case 'm': {
		// Section 3: Plan by months
		int num_months;
		do {
			std::cout << "Enter the number of months (1-60): ";
			std::cin >> num_months;
			if (num_months < 1 || num_months > 60) {
				std::cout << "Enter 1 to 60 months.\n";
			}
		} while (num_months < 1 || num_months > 60);

		// Table header for Mode M
		std::cout << std::right << std::fixed << std::setprecision(2);
		std::cout << std::setw(6) << "Month" << std::setw(12) << "Deposit"
			<< std::setw(12) << "Interest" << std::setw(14) << "Balance" << "\n";
		std::cout << "--------------------------------------------\n";
		for (int current_month = 1; current_month <= num_months; ++current_month) {
			interest = balance * (rate / 100 / 12);
			balance = balance + interest + deposit;
			total_interest = total_interest + interest;
			total_deposits = total_deposits + deposit;
			month = current_month;
			std::cout << std::setw(6) << month << std::setw(12) << deposit
				<< std::setw(12) << interest << std::setw(14) << balance << "\n";
		}
		break;
	}
	case 'G':
		//section 4 inserted into the switch for 'G'
		do {
			std::cout << "Enter your savings goal: ";
			std::cin >> goal;
			std::cout << "\n\n";
			if (goal <= start_balance) {
				std::cout << "Error goal must be greater than starting balance. \n";
			}
		} while (goal <= start_balance);

		std::cout << std::fixed << std::setprecision(2);
		std::cout << "Month" << std::setw(12) << "Deposit" << std::setw(12) << "Interest" << std::setw(12) << "Balance\n";
		std::cout << "------------------------------------------- \n";      //43

		while (balance < goal && month < 120) {
			month += 1;
			// Do one month from section 5, one table row 
			interest = balance * (rate / 100 / 12);
			balance = balance + interest + deposit;
			total_interest = total_interest + interest;
			total_deposits = total_deposits + deposit;

			std::cout << std::setw(2) << month << std::setw(12) << deposit << std::setw(12) << interest << std::setw(12) << balance << "\n";
		}
		break;
	case 'g':
		//section 4 inserted into the switch for 'g'
		do {
			std::cout << "Enter your savings goal: ";
			std::cin >> goal;
			std::cout << "\n\n";
			if (goal <= start_balance) {
				std::cout << "Error goal must be greater than starting balance. \n";
			}
		} while (goal <= start_balance);

		std::cout << std::fixed << std::setprecision(2);
		std::cout << "Month" << std::setw(12) << "Deposit" << std::setw(12) << "Interest" << std::setw(12) << "Balance\n";
		std::cout << "------------------------------------------- \n";      //43

		while (balance < goal && month < 120) {
			month += 1;
			// Do one month from section 5, one table row 
			interest = balance * (rate / 100 / 12);
			balance = balance + interest + deposit;
			total_interest = total_interest + interest;
			total_deposits = total_deposits + deposit;

			std::cout << std::setw(2) << month << std::setw(12) << deposit << std::setw(12) << interest << std::setw(12) << balance << "\n";
		}
		break;
	default:
		std::cout << "Invalid choice.";
		return 1;


	}

	/* I started this but did not finish it, forgot I was to do section 4
	// Section 3: Mode M (Plan by Months) use a for loop
	int num_months;
	do {
		std::cout << "Enter the number of months: ";
		std::cin >> num_months;
		if (num_months < 1 || num_months > 60) {
			std::cout << "Error, please enter a number between 1 and 60 for months: \n";
		}
	} while (num_months < 1 || num_months > 60);
	*/



	// Section 6: Print the summary after the table - Mikeson Calixte
	int years = month / 12;
	int leftover_months = month % 12;

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "\n============================================\n";
	std::cout << "Summary\n";
	std::cout << "============================================\n";
	std::cout << "Months: " << month << " (" << years << " yr "
		<< leftover_months << " mo)\n";
	std::cout << std::left << std::setw(22) << "Starting balance:"
		<< "$" << std::right << std::setw(14) << start_balance << "\n";
	std::cout << std::left << std::setw(22) << "Total deposits:"
		<< "$" << std::right << std::setw(14) << total_deposits << "\n";
	std::cout << std::left << std::setw(22) << "Total interest:"
		<< "$" << std::right << std::setw(14) << total_interest << "\n";
	std::cout << std::left << std::setw(22) << "Final balance:"
		<< "$" << std::right << std::setw(14) << balance << "\n";


	// Section 7: Goal Message (mode G/g only)
	if (mode == 'g' || mode == 'G') {
		if (balance >= goal) {
			std::cout << "Goal reached!\n";
		}
		else {
			std::cout << "Goal not reached in 10 years. ";
			std::cout << "Amount still needed: $" << goal - balance << "\n";
		}
	}
	


	return 0;
}
