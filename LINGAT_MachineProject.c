/*
	De La Salle University - College of Computer Studies
	Department of Software Technology
	CCPROG1 Machine Project
	Title: "Gilgamesh's Mega Gil Adventures"
	Student's Name: Carl Vincent Blix P. Lingat
	Section: S18B
	
	Student's email: carl_lingat@dlsu.edu.ph
	
	Documentation:
	
	N.B. SOME FILES HAVE THEIR OWN DOCUMENTATION. THIS DOCUMENTATION MOSTLY COVERS WHAT THE SHOPS' FUNCTION DOES AS WELL AS MAIN'S.
	
	1. In the other files, the variables that are related to an item are shortened. (e.g. Dark Matter -> DM, Phoenix Down -> PD, Trapezohedron -> TH). 
	In this documentation, I will be calling them "item codes" or IC for short.
	
	Item Code List:
	Phoenix Down = PD
	Elixir Essence = EE
	Platinum Ingot = PI
	Golden Materia = GM
	Scarletite = SL
	Adamantite = AD
	Dark Matter = DM
	Trapezohedron = TH
	
	2. addDayDebtDeposit(int* pCurrentDay, int* pDebt, int* pDeposit)
	"Passes" the day by adding 1, adds 15% of the debt to the total, and 10% of the Gils deposited to the total. This is to be executed once a shop has been visited.
	
	3. StoreName(&dDay, &dWallet, &dDebt, &dPhoenixDown, &dElixirEssence, &dPlatinumIngot, &dGoldenMateria, &dScarletite, &dAdamantite, &dDarkMatter, &dTrapezohedron); 
	These parameters are passed so that the necessary information as well as the essential items needed for transactions to be performed like the amount of Gils and other items on hand.
	
	4. Since the shops' function are identical and the only difference being the special items, Here are the notes of what is inside the function and what they do:
	
		Note: Some stores have if statements for the player's option as opposed to switch statements. This is due to my programming abilities back then until I became more comfortable using switch statements.
		
		1. Variable declaration and assignment:
		
		int dPriceIC = getPrice(UpperPrice,LowerPrice), dStockIC = getStock(UpperStock,LowerStock), dChanceIC = getRandomizer(10,1), dSellIC;
			^ Contains the price of an item which will		^ Contains the number of an item that	^ If this variable's value is	 ^ This gets a value which is decided by
			be decided by the function getPrice					is in stock which is decided by		1 to 3, then the item that it	   the price and amount to buy of an item.
			and parameters are the numbers specified			the getStock function.				it is assigned to will be out		It also ensures that the original price never
			in the specification sheet																of stock.						    changes throughout the transaction.
			
			The variables above are not inside the loop so that their values stay the same throughout the player's stay in the shop.
		
			if (dChanceIC <= 3) <= If getRandomizer picks 1 to 3 for that variable, it sets the price and stock of that item to zero, effectively making it sold out.
			{
				dStockIC = dStockIC*0;
				dPriceIC = dPriceIC*0;
		    }
		    
		2. Buying:
		
			if (dStockIC == 0) <= Informs the user if the item is out of stock
			{
				printf("Shopkeeper: The item you wish to purchase is out of stock. I apologize for the inconvenience.\n"); 
				system("pause");
			}
			
			else
			{
				printf("Shopkeeper: How many would you like to buy?\n");
				do
				{
					scanf("%d", &dAmount); <= Asks the user how many of an item they would like to buy
				}
				while (dAmount > dStockIC || dAmount < 0); <= Repeats if the input is larger than the amount in stock or is a negative number.
				
				dSellIC = dPriceIC*dAmount; <= Multiplies the price by the amount to buy and it is stored in a variable which contains the amount that user has to pay.
				
				if (*pWallet < dSellIC) <= Informs the user if they do not have enough Gils on hand.
				{
					printf("Shopkeeper: I'm sorry but you don't have enough Gils to purchase the goods.\n");
					system("pause");
				}
				else
				{
					*pWallet = *pWallet - dSellIC; <= Deducts the amount of Gils on hand according to the price of the total number of items to buy
					*pItemCode = *pItemCode + dAmount; <= Adds the amount bought to the user's inventory of that item
					dStockIC = dStockIC - dAmount; <= Subtracts the amount available with the amount bought
					printf("Shopkeeper: Thank you for purchasing (name of the item purchased)!\n");
					system("pause");
				}
			}
			
		3. Selling:
		
		if (dStockIC == 0 && dPriceIC == 0) <= Informs the user if an item is out of stock due to the 30% chance.
		{
			printf("Shopkeeper: Sorry, I cannot buy an item that we do not have. It's company policy.\n");
			system("pause");
		}
		else if (*pItemCode == 0) <= Informs the user that they do not have the item to sell.
		{
			printf("Shopkeeper: It looks like you don't have (item name) to sell.\n");
			system("pause");
		}
		else
		{
			printf("Shopkeeper: How many (item name) do you want to sell?\n");
			
			do
			{
				scanf("%d", &dSellIC); <= Asks user how many they want to sell
			}
			while (dSellPD > *pItemCode || dSellIC <= 0); <= Repeats if input is more than what the user has or a negative number
			
			*pItemCode = *pItemCode - dSellIC; <= Adjusts inventory according to amount sold.
			dSellBack = dSellIC*dPriceIC; <= Computes for the Gils to be given to the user after selling.
			*pWallet = *pWallet + dSellBack; <= Adjusts Gils on hand according to the total cost of the items sold.
			dStockIC = dStockIC + dSellIC; <= Adjusts the stock of the store with the amount of the item sold.
			printf("Shopkeeper: Here's your %d Gils. Nice doing business with you!\n", dSellBack);
			system("pause");
		}
	
	5. rand() % (UpperValue-LowerValue + 1) + LowerValue; is retrieved from https://www.geeksforgeeks.org/generating-random-number-range-c/
*/

#include <stdio.h>
#include <stdlib.h>
#include "LINGAT_TycoonMeteorMinerals.c"
#include "LINGAT_PulsianRestoratives.c"
#include "LINGAT_ArchadianLuxuries.c"
#include "LINGAT_CidsMagicalEscapades.c"
#include "LINGAT_GaiainGratitudes.c"
#include "LINGAT_RichesAndMineralsofSpira.c"
#include "LINGAT_MerchantoftheRift.c"

void addDayDebtDeposit(int* pCurrentDay, int* pDebt, int* pDeposit) // This function is called after a store has been visited, simulating a day passing and the adjustment of the deposit and debt.
{
	*pCurrentDay = *pCurrentDay + 1; // Adds 1 to the day count after a store has been visited
	*pDebt = *pDebt*.15 + *pDebt; // Adds 15% to the total of the current debt
	*pDeposit = *pDeposit*.10 + *pDeposit; // Adds 10% to the total of deposited gils
}

int getPrice (int UpperPrice, int LowerPrice) // Randomizes the price given a certain price range. 
{
	return rand() % (UpperPrice - LowerPrice + 1) + LowerPrice;
}

int getStock(int UpperStock, int LowerStock) // Randomizes the amount of an item in stock given a certain number range
{
	return rand() % (UpperStock - LowerStock + 1) + LowerStock;
}

int getRandomizer(int UpperChance, int LowerChance) // This generates a number between 1-10. If the number is 1-3, then the item is out of stock.
{
	return rand() % (UpperChance - LowerChance + 1) + LowerChance;
}

// This function displays the amount of an item the user currently possesses.
void InventoryCheck (int* pPhoenixDown, int* pElixirEssence, int* pPlatinumIngot, int* pGoldenMateria, int* pScarletite, int* pAdamantite, int* pDarkMatter, int* pTrapezohedron)
{
	system("cls");
	printf("INVENTORY\n\n");
	printf("Phoenix Down = %d\n", *pPhoenixDown);
	printf("Elixir Essence = %d\n", *pElixirEssence);
	printf("Platinum Ingot = %d\n", *pPlatinumIngot);
	printf("Golden Materia = %d\n", *pGoldenMateria);
	printf("Scarletite = %d\n", *pScarletite);
	printf("Adamantite = %d\n", *pAdamantite);
	printf("Dark Matter = %d\n", *pDarkMatter);
	printf("Trapezohedron = %d\n\n", *pTrapezohedron);
	
	system("pause");
}

int main ()
{
	int dChoice, dWallet, dDebt, dDay, dDepositGil, dQuit; // Variables for input, Gils on hand, debt, day, Gils deposited to the Merchant of the Rift, and condition for quitting the game.
	int dPhoenixDown, dElixirEssence, dPlatinumIngot, dGoldenMateria, dScarletite, dAdamantite; // Variables for containing the amount of an item
	int dDarkMatter, dTrapezohedron; // Variables for containing the amount of an item
	char dPlay, dPlay2; // dPlay is for Yes or No if the user wants to play the game and dPlay2 is if they want to play again.
	
	// These printf statements contain the "lore" and give the users an idea on how to play the game.
	printf("-------------------------------");
	printf("\nGILGAMESH'S MEGA GIL ADVENTURES\n");
	printf("-------------------------------\n\n");
	
	printf("You play as Gilgamesh, a warrior lost in the rift who has the ability to travel to different worlds.\n");
	printf("As a weapon collector who is in search of the legendary Excalibur, you prepare to set out on a journey.\n");
	printf("You realize that you need Gils (the in-game currency) to purchase equipment that you will need during your battles and more importantly, buy rare weapons that you desire.\n");
	printf("The only reasonable way to earn Gils is to do it in an honest manner and that is through buying and selling goods in different worlds.\n");
	printf("There are some items that are considered priceless in many worlds that are quite common in another world. You can use this knowledge to buy low and sell high.\n\n\n");

	printf("You researched and found out that the following are the items that will help you gain a lot of Gils so when you visit each world, these are the items that you will pay attention to:\n\n");
	printf("Goods\t\t\tEstimated Buy/Sell Price\n");
	printf("Phoenix Down\t\t500-1,200 Gils\n");
	printf("Elixir Essence\t\t1,500-2,100 Gils\n");
	printf("Platinum Ingot\t\t5,000-7,000 Gils\n");
	printf("Golden Materia\t\t3,500-5,500 Gils\n");
	printf("Scarletite\t\t8,000-12,000 Gils\n");
	printf("Adamantite\t\t15,000-30,000 Gils\n");
	printf("Dark Matter\t\t40,000-70,000 Gils\n");
	printf("Trapezohedron\t\t60,000-90,000 Gils\n\n\n");
	
	printf("Since you do not have much goods to your name, save for your Genji equipment which can be sold for a hefty amount, you approach the Merchant of the Rift.\n");
	printf("As a sneaky way of earning Gils, the Merchant of the Rift offers you some Gils to help you start with your adventure and use your Genji equipment as collateral.\n");
	printf("You, who does not think much before acting hastily agreed. The Merchant explains that your debt will increase by 15 percent everyday.\n");
	printf("You must earn enough Gils to pay off your debts and retrieve the Genji equipment back within 30 days.\n\n\n");
	
	printf("With 20,000 Gils on hand and a 50,000 Gil debt, you set on an adventure to different worlds.\n");
	printf("Do you wish to start the journey? [Y]es / [N]o\n");
	

	do
	{		
		scanf("%c", &dPlay); // This asks the user to input Y / y for Yes and N / n for No.
	}	
	while (dPlay != 'Y' && dPlay != 'y' && dPlay != 'N' && dPlay != 'n'); // Input Validation (repeats if input is neither Y/y nor N/n)
	
	if (dPlay == 'Y' || dPlay == 'y') // This if statement executes the game if the user inputs Y / y
	{
	
	do
	{
	
	dWallet = 20000; dDebt = 50000; dDay = 1; dDepositGil = 0; dPhoenixDown = 0; dElixirEssence = 0; dPlatinumIngot = 0; dGoldenMateria = 0; dScarletite = 0; dAdamantite = 0; dDarkMatter = 0; dTrapezohedron = 0; dQuit = 0;
	// Variable initialization is done here so that when the user wants to play the game again, the do-while loop resets the variables to their initial values.
	
	do
	{
		
		do
		{
		system("cls");
		printf("Gilgamesh: Where should my travels take me to?\n");
		printf("	[1] Tycoon Meteor's Minerals						Day#%d\n", dDay); // displays the day
		printf("	[2] Pulsian Restoratives						Gil: %d\n", dWallet); // displays Gils on hand
		printf("	[3] Archadian Luxuries							Debt: %d\n", dDebt); // displays debt
		printf("	[4] Cid's Magical Escapades\n");
		printf("	[5] Gaiain Gratitudes							[0] Quit\n");
		printf("	[6] Riches and Minerals of Spira\n");
		printf("	[7] Go see the Merchant of the Rift\n");
		printf("	[8] Check your inventory\n");
		printf("\n\n*ITEM NAME* indicates that it is the store's specialty item.\n\n");
		printf("Your choice: ");
		scanf("%d", &dChoice);
		}
		while (dChoice < 0 || dChoice > 8); // Input validation. Repeats the statements if dChoice is less than 0 or greater than 8
		
		switch (dChoice)
		{
			
		case 0: // Sets dQuit to 1, which terminates the loop by making one of the statements false.
			dQuit = 1; 
			break;
			
		case 1:
			TycoonMeteorMinerals(&dDay, &dWallet, &dDebt, &dPhoenixDown, &dElixirEssence, &dPlatinumIngot, &dGoldenMateria, &dScarletite, &dAdamantite, &dDarkMatter, &dTrapezohedron); // Opens the Tycoon Meteor Mineral
			addDayDebtDeposit(&dDay, &dDebt, &dDepositGil);
			break;

		case 2:
			PulsianRestoratives(&dDay, &dWallet, &dDebt, &dPhoenixDown, &dElixirEssence, &dPlatinumIngot, &dGoldenMateria, &dScarletite, &dAdamantite, &dDarkMatter, &dTrapezohedron); // Opens the Pulsian Restorative store
			addDayDebtDeposit(&dDay, &dDebt, &dDepositGil);
			break;
		
		case 3:
			ArchadianLuxuries(&dDay, &dWallet, &dDebt, &dPhoenixDown, &dElixirEssence, &dPlatinumIngot, &dGoldenMateria, &dScarletite, &dAdamantite, &dDarkMatter, &dTrapezohedron); // Opens the Archadian Luxuries store
			addDayDebtDeposit(&dDay, &dDebt, &dDepositGil);
			break;
		
		case 4:
			CidsMagicalEscapades(&dDay, &dWallet, &dDebt, &dPhoenixDown, &dElixirEssence, &dPlatinumIngot, &dGoldenMateria, &dScarletite, &dAdamantite, &dDarkMatter, &dTrapezohedron); // Opens Cid's Magical Escapades store
			addDayDebtDeposit(&dDay, &dDebt, &dDepositGil);
			break;
		
		case 5:
			GaiainGratitudes(&dDay, &dWallet, &dDebt, &dPhoenixDown, &dElixirEssence, &dPlatinumIngot, &dGoldenMateria, &dScarletite, &dAdamantite, &dDarkMatter, &dTrapezohedron); // Opens Gaiain Gratitudes store
			addDayDebtDeposit(&dDay, &dDebt, &dDepositGil);
			break;
			
		case 6:
			RichesAndMineralsOfSpira(&dDay, &dWallet, &dDebt, &dPhoenixDown, &dElixirEssence, &dPlatinumIngot, &dGoldenMateria, &dScarletite, &dAdamantite, &dDarkMatter, &dTrapezohedron); // Opens Riches Minerals and Riches of Spira store
			addDayDebtDeposit(&dDay, &dDebt, &dDepositGil);
			break;
			
		case 7:
			MerchantOfTheRift(&dDay, &dWallet, &dDebt, &dDepositGil); // Brings user to the Merchant of the Rift
			break;
		
		case 8:
			InventoryCheck(&dPhoenixDown, &dElixirEssence, &dPlatinumIngot, &dGoldenMateria, &dScarletite, &dAdamantite, &dDarkMatter, &dTrapezohedron); // The function displays how much of an item does the user have
		}
	}
	while (dDay <= 30 && dQuit == 0); // Program continues until dDay is 30 or the user decides to quit by initializing dQuit to 1
	
	system("cls");
	
	if (dQuit == 1)
		printf("\n\nYou quit at Day %d\n\n", dDay); // Informs the user what day did they quit
		
	if (dDepositGil + dWallet > dDebt) // Displays the "winning screen" if the Gils deposited and on hand combined are higher than the debt.
		{
			printf("Debt: %d \nGils On Hand: %d \nGils Deposited: %d\n\n", dDebt, dWallet, dDepositGil);
			printf("You won the game!\n\n");
			printf("Gilgamesh: That was merely a test of your strength, mortals! A prelude if you will! The real contest begins now!\n");
		}
	else // Displays the "losing screen" if condition above is not met
		{
			printf("Debt: %d \nGils On Hand: %d \nGils Deposited: %d\n\n", dDebt, dWallet, dDepositGil);
			printf("You lost the game!\n\n");
			printf("Merchant of the Rift: REALLY? YOU COULDN'T EVEN EARN ENOUGH TO BUY AN EXCALIPOOR!\n\n");
		}
	
	printf("Do you want to continue playing? [Y]es or [N]o\n");

	do
	{
		scanf("%c", &dPlay2); // Asks user if they want to continue playing. 
	} while (dPlay2 != 'Y' && dPlay2 != 'y' && dPlay2 != 'N' && dPlay2 != 'n');
	

	} while (dPlay2 == 'Y' || dPlay2 == 'y'); // Game repeats until user inputs N or n.
	
	}
	 
	return 0;
}
