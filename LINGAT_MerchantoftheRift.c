#include <stdio.h>

// This function acts as the Merchant of the Rift. It has its own documentation.

void MerchantOfTheRift (int* pDay, int* pWallet, int* pDebt, int* pDeposit) // Merchant of the Rift Page
{	
	int dChoice, dDepositAmount, dWithdraw, dPay, dLoan;
	
	do
{

	system("cls");
	printf("MERCHANT OF THE RIFT\n\n");
	printf("Merchant of the Rift: Are you ready to pay your debts?\n");
	printf("	[1] Deposit Gils						Day#%d\n", *pDay);
	printf("	[2] Withdraw Gils					Gil: %d\n", *pWallet);
	printf("	[3] Pay off debt					Debt: %d\n", *pDebt);
	printf("	[4] Ask for additional loan				Gils Deposited: %d\n", *pDeposit);
	printf("	[5] Leave\n");
	
	printf("Your choice: ");
	scanf("%d", &dChoice); // Asks user what they need to do with the Merchant of the Rift.
	
	if (dChoice == 1)
	{
		if (*pWallet == 0) // Displays if user does not have Gils on hand
		{
			printf("Merchant of the Rift: Your wallet looks empty. You're so broke that I cannot stop laughing!\n");
			system("pause");
		}
		else
		{
				printf("Merchant of the Rift: How much would you like to deposit? Be informed that the minimum amount is 100 Gils.\n"); 
				// Asks player the amount they want to deposit. Minimum of 100 Gils in order to ensure no logical errors. (Also, banks in real life have a minimum amount to deposit, right?)
			do
		{
				scanf("%d", &dDepositAmount);
		} 
			while (dDepositAmount > *pWallet || 1 > dDepositAmount || dDepositAmount <= 99); // Repeats asking the input until user enters valid input (e.g. lower than or equal to the deposited amount)
		
				*pDeposit = dDepositAmount + *pDeposit; // Adds the inputed amount to the total gils deposited
				*pWallet = *pWallet - *pDeposit; // Subtracts the deposited amount from the "wallet"
				printf("Merchant of the Rift: I will take %d Gils and increase it by 10 percent everyday!", dDepositAmount);
				printf("\n");
				system("pause");
		}
	}

	if (dChoice == 2)
	{
		if (*pDeposit == 0)
		{
			printf("Merchant of the Rift: Wait a minute! You actually don't have Gils deposited.\n"); // Displays if the user does not have Gils on hand.
			system("pause");
		}
		else
		{
			printf("Merchant of the Rift: How much do you want to withdraw? Be reminded that you have to withdraw at least 100 Gils.\n");
			do
			{
				scanf("%d", &dWithdraw); // Asks user how much they want to withdraw
			}
			while (dWithdraw > *pDeposit || 1 > dWithdraw || dWithdraw < 100); // Repeats if the user inputs 0, a number less than 100, or a number higher than the amount deposited.
	
				*pDeposit = *pDeposit - dWithdraw; // Subtracts inputed amount from the total gils deposited
				*pWallet = *pWallet + dWithdraw; // Adds input into the "wallet" 
				printf("Merchant of the Rift: Alright. Here's your %d Gils.", dWithdraw);
				printf("\n");
				system("pause");
		}
	}
	
	if (dChoice == 3)
	{
		if(*pWallet == 0)
		{
			printf("Merchant of the Rift: How can you pay your debts with an empty wallet?\n"); // Displays if the user does not have Gils on hand.
			system("pause");
		}
		else if (*pDebt == 0) // Displays if the user has no debt and still wants to pay the Merchant.
		{
			printf("Merchant of the Rift: Your debt is zero. Are you giving me free money?\n");
			system("pause");
		}
		else
		{
			printf("Merchant of the Rift: Finally! How much do you want to pay back? ");
			do
			{
				scanf("%d", &dPay); // Prompts user to input how much they want to pay.
			}
			while (dPay > *pWallet || 1 > dPay || dPay > *pDebt); // Repeats if user inputs a number higher than Gils on hand, lower than 1, and more than their debt.
			
			*pWallet = *pWallet - dPay; // Deducts Gils on hand with the amount of debt to pay
			*pDebt = *pDebt - dPay; // Adjusts debt according to the amount
			printf("Merchant of the Rift: Alright! Thanks for paying your debts!\n");
			system("pause");
		}
	}
	
	if (dChoice == 4)
	{
		printf("Merchant of the Rift: How much do you want to borrow? ");
		scanf("%d", &dLoan); /// Asks user how much they want to borrow. No limitation.
		*pWallet = *pWallet + dLoan; // Adjusts Gils on hand with the amount
		*pDebt = *pDebt + dLoan; // Adjusts the debt as well.
		printf("Merchant of the Rift: Alright. Here's your %d Gils but remember your debt increases by 15 percent everyday!\n", dLoan);
		system("pause");
	}
}
	while (dChoice < 5);
}
