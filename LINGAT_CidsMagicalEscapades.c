#include <stdio.h>
#include <stdlib.h>

// This function acts as Cids Magical Escapades. Please see the main file for documentation.

void CidsMagicalEscapades (int* pDay, int *pWallet, int* pDebt, int* pPhoenixDown, int* pElixirEssence, int* pPlatinumIngot, int* pGoldenMateria, int* pScarletite, int* pAdamantite, int* pDarkMatter, int* pTrapezohedron)
{
	int dAction, dBuy, dSell, dAmount, dSellBack;
	
	int dPricePD = getPrice(1200,500), dStockPD = getStock(33,17), dChancePD = getRandomizer(10,1), dSellPD;
	int dPriceEE = getPrice(2100,1500), dStockEE = getStock(20,10), dChanceEE = getRandomizer(10,1), dSellEE;
	int dPricePI = getPrice(7000,5000), dStockPI = getStock(18,9), dChancePI = getRandomizer(10,1), dSellPI;
	
	int dPriceGM = getPrice(5000,3000), dStockGM = getStock(30, 16), dSellGM;
	
	int dPriceSL = getPrice(12000, 8000), dStockSL = getStock(14,6), dChanceSL = getRandomizer(10,1), dSellSL;
	int dPriceAD = getPrice(30000, 15000), dStockAD = getStock(11,7), dChanceAD = getRandomizer(10,1), dSellAD;
	int dPriceDM = getPrice(70000, 40000), dStockDM = getStock(8,4), dChanceDM = getRandomizer(10,1), dSellDM;
	int dPriceTH = getPrice(90000,60000), dStockTH = getStock(5,2), dChanceTH = getRandomizer(10,1), dSellTH;
	
	do
	{
		fflush(stdin);
		system("cls");
		
		if (dChancePD <= 3)
		{
			dStockPD = dStockPD*0;
			dPricePD = dPricePD*0;
		}
		
		if (dChanceEE <= 3)
		{
			dStockEE = dStockEE*0;
			dPriceEE = dPriceEE*0;
		}
		
		if (dChancePI <= 3)
		{
			dStockPI = dStockPI*0;
			dPricePI = dPricePI*0;
		}
		
		if (dChanceSL <= 3)
		{
			dStockSL = dStockSL*0;
			dPriceSL = dPriceSL*0;
		}
		
		if (dChanceAD <= 3)
		{
			dStockAD = dStockAD*0;
			dPriceAD = dPriceAD*0;
		}
		
		if (dChanceDM <= 3)
		{
			dStockDM = dStockDM*0;
			dPriceDM = dPriceDM*0;
		}
		
		if (dChanceTH <= 3)
		{
			dStockTH = dStockTH*0;
			dPriceTH = dPriceTH*0;
		}
		
		printf("Day: %d Gil: %d Debt: %d\n\n", *pDay, *pWallet, *pDebt);
		
		printf("CID'S MAGICAL ESCAPADES\n");
		printf("\n");
		printf("Shopkeeper: Welcome! How can I be of service?\n");
		printf("\n");
		
		printf("Item			Stocks		Price\t\tInventory\n");
		printf("Phoenix Down		  %d		%d G\t\t%d\n", dStockPD, dPricePD, *pPhoenixDown);
		printf("Elixir Essence	  	  %d		%d G\t\t%d\n", dStockEE, dPriceEE, *pElixirEssence);
		printf("Platinum Ingot		  %d		%d G\t\t%d\n", dStockPI, dPricePI, *pPlatinumIngot);
		printf("*Golden Materia*	  %d		%d G\t\t%d\n", dStockGM, dPriceGM, *pGoldenMateria);
		printf("Scarletite		  %d	  	%d G\t\t%d\n", dStockSL, dPriceSL, *pScarletite);
		printf("Adamantite		  %d		%d G\t\t%d\n", dStockAD, dPriceAD, *pAdamantite);
		printf("Dark Matter		  %d		%d G\t\t%d\n", dStockDM, dPriceDM, *pDarkMatter);
		printf("Trapezohedron		  %d		%d G\t\t%d\n", dStockTH, dPriceTH, *pTrapezohedron);
		
		printf("[1] Buy [2] Sell [3] Leave\n");
		scanf("%d", &dAction);
		
	if (dAction == 1)
		{
			printf("\n");
			printf("Shopkeeper: What do you want to buy?\n");
			printf(" [1] - Phoenix Down\n");
			printf(" [2] - Elixir Essence\n");
			printf(" [3] - Platinum Ingot\n");
			printf(" [4] - Golden Materia\n");
			printf(" [5] - Scarletite\n");
			printf(" [6] - Adamantite\n");
			printf(" [7] - Dark Matter\n");
			printf(" [8] - Trapezohedron\n");
			
		do
		{
		scanf("%d", &dBuy); 
		}
		while (dBuy < 1 || dBuy > 8);
		
		switch(dBuy)
		{
			case 1:
				if (dStockPD == 0)
			{
				printf("Shopkeeper: The item you wish to purchase is out of stock. I apologize for the inconvenience.\n");
				system("pause");
			}
			else
			{
				printf("Shopkeeper: How many would you like to buy?\n");
				do
				{
					scanf("%d", &dAmount);
				}
				while (dAmount > dStockPD  || dAmount < 0);
				
				dSellPD = dPricePD*dAmount;
				
				if (*pWallet < dSellPD)
				{
					printf("Shopkeeper: I'm sorry but you don't have enough Gils to purchase the goods.\n");
					system("pause");
				}
				else
				{
				*pWallet = *pWallet - dSellPD;
				*pPhoenixDown = *pPhoenixDown + dAmount;
				dStockPD = dStockPD - dAmount;
				printf("Shopkeeper: Thank you for purchasing Phoenix Down!\n");
				system("pause");
				}
			}
			break;
			
			case 2:
			if (dStockEE == 0)
			{
				printf("Shopkeeper: The item you wish to purchase is out of stock. I apologize for the inconvenience.\n");
				system("pause");
			}
			else
			{
				printf("Shopkeeper: How many would you like to buy?\n");
				do
				{
					scanf("%d", &dAmount);
				}
				while (dAmount > dStockEE  || dAmount < 0);
				
				dSellEE = dPriceEE*dAmount;
				
				if (*pWallet < dSellEE)
				{
					printf("Shopkeeper: I'm sorry but you don't have enough Gils to purchase the goods.\n");
					system("pause");
				}
				else
				{
				*pWallet = *pWallet - dSellEE;
				*pElixirEssence = *pElixirEssence + dAmount;
				dStockEE = dStockEE - dAmount;
				printf("Shopkeeper: Thank you for purchasing Elixir Essence!\n");
				system("pause");
				}
			}
			break;
			
			case 3:
			if (dStockPI == 0)
			{
				printf("Shopkeeper: The item you wish to purchase is out of stock. I apologize for the inconvenience.\n");
				system("pause");
			}
			else
			{
				printf("Shopkeeper: How many would you like to buy?\n");
				do
				{
					scanf("%d", &dAmount);
				}
				while (dAmount > dStockPI  || dAmount < 0);
				
				dSellPI = dPricePI*dAmount;
				
				if (*pWallet < dSellPI)
				{
					printf("Shopkeeper: I'm sorry but you don't have enough Gils to purchase the goods.\n");
					system("pause");
				}
				else
				{
				*pWallet = *pWallet - dSellPI;
				*pPlatinumIngot = *pPlatinumIngot + dAmount;
				dStockPI = dStockPI - dAmount;
				printf("Shopkeeper: Thank you for purchasing Platinum Ingot!\n");
				system("pause");
				}
			}
			break;
			
			case 4:
			if (dStockGM == 0)
			{
				printf("Shopkeeper: The item you wish to purchase is out of stock. I apologize for the inconvenience.\n");
				system("pause");
			}
			else
			{
				printf("Shopkeeper: How many would you like to buy?\n");
				do
				{
					scanf("%d", &dAmount);
				}
				while (dAmount > dStockGM  || dAmount < 0);
				
				dSellGM = dPriceGM*dAmount;
				
				if (*pWallet < dSellGM)
				{
					printf("Shopkeeper: I'm sorry but you don't have enough Gils to purchase the goods.\n");
					system("pause");
				}
				else
				{
				*pWallet = *pWallet - dSellGM;
				*pGoldenMateria = *pGoldenMateria + dAmount;
				dStockGM = dStockGM - dAmount;
				printf("Shopkeeper: Thank you for purchasing Golden Materia!\n");
				system("pause");
				}
			}
			break;
			
			case 5:
			if (dStockSL == 0)
			{
				printf("Shopkeeper: The item you wish to purchase is out of stock. I apologize for the inconvenience.\n");
				system("pause");
			}
			else
			{
				printf("Shopkeeper: How many would you like to buy?\n");
				do
				{
					scanf("%d", &dAmount);
				}
				while (dAmount > dStockSL  || dAmount < 0);
				
				dSellSL = dPriceSL*dAmount;
				
				if (*pWallet < dSellSL)
				{
					printf("Shopkeeper: I'm sorry but you don't have enough Gils to purchase the goods.\n");
					system("pause");
				}
				else
				{
				*pWallet = *pWallet - dSellSL;
				*pScarletite = *pScarletite + dAmount;
				dStockSL = dStockSL - dAmount;
				printf("Shopkeeper: Thank you for purchasing Scarletite!\n");
				system("pause");
				}
			}
			break;
			
			case 6:
			if (dStockAD == 0)
			{
				printf("Shopkeeper: The item you wish to purchase is out of stock. I apologize for the inconvenience.\n");
				system("pause");
			}
			else
			{
				printf("Shopkeeper: How many would you like to buy?\n");
				do
				{
					scanf("%d", &dAmount);
				}
				while (dAmount > dStockAD  || dAmount < 0);
				
				dSellAD = dPriceAD*dAmount;
				
				if (*pWallet < dSellAD)
				{
					printf("Shopkeeper: I'm sorry but you don't have enough Gils to purchase the goods.\n");
					system("pause");
				}
				else
				{
				*pWallet = *pWallet - dSellAD;
				*pAdamantite = *pAdamantite + dAmount;
				dStockAD = dStockAD - dAmount;
				printf("Shopkeeper: Thank you for purchasing Adamantite!\n");
				system("pause");
				}
			}
			break;
			
			case 7:
			if (dStockDM == 0)
			{
				printf("Shopkeeper: The item you wish to purchase is out of stock. I apologize for the inconvenience.\n");
				system("pause");
			}
			else
			{
				printf("Shopkeeper: How many would you like to buy?\n");
				do
				{
					scanf("%d", &dAmount);
				}
				while (dAmount > dStockDM  || dAmount < 0);
				
				dSellDM = dPriceDM*dAmount;
				
				if (*pWallet < dSellDM)
				{
					printf("Shopkeeper: I'm sorry but you don't have enough Gils to purchase the goods.\n");
					system("pause");
				}
				else
				{
				*pWallet = *pWallet - dSellDM;
				*pDarkMatter = *pDarkMatter + dAmount;
				dStockDM = dStockDM - dAmount;
				printf("Shopkeeper: Thank you for purchasing Dark Matter!\n");
				system("pause");
				}
			}
			break;
			
			case 8:
			if (dStockTH == 0)
			{
				printf("Shopkeeper: The item you wish to purchase is out of stock. I apologize for the inconvenience.\n");
				system("pause");
			}
			else
			{
				printf("Shopkeeper: How many would you like to buy?\n");
				do
				{
					scanf("%d", &dAmount);
				}
				while (dAmount > dStockTH  || dAmount < 0);
			
					dSellTH = dPriceTH*dAmount;
			
				if (*pWallet < dSellTH)
				{
					printf("Shopkeeper: I'm sorry but you don't have enough Gils to purchase the goods.\n");
					system("pause");
				}
				else
				{
				*pWallet = *pWallet - dSellTH;
				*pTrapezohedron = *pTrapezohedron + dAmount;
				dStockTH = dStockTH - dAmount;
				printf("Shopkeeper: Thank you for purchasing Trapezohedron!\n");
				system("pause");
				}
			}
			break;
			
		}
		
		}
	
	if (dAction == 2)
	{
		printf("\n");
		printf("Shopkeeper: What are you going to sell?\n");
		printf(" [1] - Phoenix Down\n");
		printf(" [2] - Elixir Essence\n");
		printf(" [3] - Platinum Ingot\n");
		printf(" [4] - Golden Materia\n");
		printf(" [5] - Scarletite\n");
		printf(" [6] - Adamantite\n");
		printf(" [7] - Dark Matter\n");
		printf(" [8] - Trapezohedron\n");
		
		do
		{
		scanf("%d", &dSell);
		}
		while (dSell < 1 || dSell > 8);
		
		switch (dSell)
		{
			case 1:
			if (dStockPD == 0 && dPricePD == 0)
			{
			printf("Shopkeeper: Sorry, I cannot buy an item that we do not have. It's company policy.\n");
			system("pause");
			}
			else if (*pPhoenixDown == 0)
			{	
			printf("Shopkeeper: It looks like you don't have Phoenix Downs to sell.\n");
			system("pause");
			}
			else
			{
			printf("Shopkeeper: How many Phoenix Downs do you want to sell?\n");
			
			do
			{
				scanf("%d", &dSellPD);
			}
			while (dSellPD > *pPhoenixDown || dSellPD <= 0);
			
			*pPhoenixDown = *pPhoenixDown - dSellPD;
			dSellBack = dSellPD*dPricePD;
			*pWallet = *pWallet + dSellBack;
			dStockPD = dStockPD + dSellPD;
			printf("Shopkeeper: Here's your %d Gils. Nice doing business with you!\n", dSellBack);
			system("pause");
			}
			break;
			
		case 2:
		if (dStockEE == 0 && dPriceEE == 0)
		{
			printf("Shopkeeper: Sorry, I cannot buy an item that we do not have. It's company policy.\n");
			system("pause");
		}
		else if (*pElixirEssence == 0)
		{
			printf("Shopkeeper: It looks like you don't have Elixir Essences to sell.\n");
			system("pause");
		}
		else
		{
			printf("Shopkeeper: How many Elixir Essences do you want to sell?\n");
			
			do
			{
				scanf("%d", &dSellEE);
			}
			while (dSellEE > *pElixirEssence || dSellEE <= 0);
			
			*pElixirEssence = *pElixirEssence - dSellEE;
			dSellBack = dSellEE*dPriceEE;
			*pWallet = *pWallet + dSellBack;
			dStockEE = dStockEE + dSellEE;
			printf("Shopkeeper: Here's your %d Gils. Nice doing business with you!\n", dSellBack);
			system("pause");
		}
		break;
		
		case 3:
		if (dStockPI == 0 && dPricePI == 0)
		{
			printf("Shopkeeper: Sorry, I cannot buy an item that we do not have. It's company policy.\n");
			system("pause");
		}
		else if (*pPlatinumIngot == 0)
		{
			printf("Shopkeeper: It looks like you don't have Platinum Ingots to sell.\n");
			system("pause");
		}
		else
		{
			printf("Shopkeeper: How many Platinum Ingots do you want to sell?\n");
			
			do
			{
				scanf("%d", &dSellPI);
			}
			while (dSellPI > *pPlatinumIngot || dSellPI <= 0);
			
			*pPlatinumIngot = *pPlatinumIngot - dSellPI;
			dSellBack = dSellPI*dPricePI;
			*pWallet = *pWallet + dSellBack;
			dStockPI = dStockPI + dSellPI;
			printf("Shopkeeper: Here's your %d Gils. Nice doing business with you!\n", dSellBack);
			system("pause");
		}
		break;
		
		case 4:
		if (*pGoldenMateria == 0)
		{
			printf("Shopkeeper: It looks like you don't have Golden Materias to sell.\n");
			system("pause");
		}
		else
		{
			printf("Shopkeeper: How many Golden Materias do you want to sell?\n");
			
			do
			{
				scanf("%d", &dSellGM);
			}
			while (dSellGM > *pGoldenMateria || dSellGM <= 0);
			
			*pGoldenMateria = *pGoldenMateria - dSellGM;
			dSellBack = dSellGM*dPriceGM;
			*pWallet = *pWallet + dSellBack;
			dStockGM = dStockGM + dSellGM;
			printf("Shopkeeper: Here's your %d Gils. Nice doing business with you!\n", dSellBack);
			system("pause");
		}	
		break;
		
		case 5:
		if (dStockSL == 0 && dPriceSL == 0)
		{
			printf("Shopkeeper: Sorry, I cannot buy an item that we do not have. It's company policy.\n");
			system("pause");
		}
		else if (*pScarletite == 0)
		{
			printf("Shopkeeper: It looks like you don't have Scarletites to sell.\n");
			system("pause");
		}
		else
		{
			printf("Shopkeeper: How many Scarletites do you want to sell?\n");
			
			do
			{
				scanf("%d", &dSellSL);
			}
			while (dSellSL > *pScarletite || dSellSL <= 0);
			
			*pScarletite = *pScarletite - dSellSL;
			dSellBack = dSellSL*dPriceSL;
			*pWallet = *pWallet + dSellBack;
			dStockSL = dStockSL + dSellSL;
			printf("Shopkeeper: Here's your %d Gils. Nice doing business with you!\n", dSellBack);
			system("pause");
		}
		break;
		
		case 6:
		if (dStockAD == 0 && dPriceAD == 0)
		{
			printf("Shopkeeper: Sorry, I cannot buy an item that we do not have. It's company policy.\n");
			system("pause");
		}
		else if (*pAdamantite == 0)
		{
			printf("Shopkeeper: It looks like you don't have Adamantite to sell.\n");
			system("pause");
		}
		else
		{
			printf("Shopkeeper: How many Adamantites do you want to sell?\n");
			
			do
			{
				scanf("%d", &dSellAD);
			}
			while (dSellAD > *pAdamantite || dSellAD <= 0);
			
			*pAdamantite = *pAdamantite - dSellAD;
			dSellBack = dSellAD*dPriceAD;
			*pWallet = *pWallet + dSellBack;
			dStockAD = dStockAD + dSellAD;
			printf("Shopkeeper: Here's your %d Gils. Nice doing business with you!\n", dSellBack);
			system("pause");
		}
		break;
		
		case 7:
		if (dStockDM == 0 && dPriceDM == 0)
		{
			printf("Shopkeeper: Sorry, I cannot buy an item that we do not have. It's company policy.\n");
			system("pause");
		}
		else if (*pDarkMatter == 0)
		{
			printf("Shopkeeper: It looks like you don't have Dark Matter to sell.\n");
			system("pause");
		}
		else
		{
			printf("Shopkeeper: How many Dark Matter do you want to sell?\n");
			
			do
			{
				scanf("%d", &dSellDM);
			}
			while (dSellDM > *pDarkMatter || dSellDM <= 0);
			
			*pDarkMatter = *pDarkMatter - dSellDM;
			dSellBack = dSellDM*dPriceDM;
			*pWallet = *pWallet + dSellBack;
			dStockDM = dStockDM + dSellDM;
			printf("Shopkeeper: Here's your %d Gils. Nice doing business with you!\n", dSellBack);
			system("pause");
		}
		break;
		
		case 8:
		if (dStockTH == 0 && dPriceTH == 0)
		{
			printf("Shopkeeper: Sorry, I cannot buy an item that we do not have. It's company policy.\n");
			system("pause");
		}
		else if (*pTrapezohedron == 0)
		{
			printf("Shopkeeper: It looks like you don't have Trapezohedrons to sell.\n");
			system("pause");
		}
		else
		{
			printf("Shopkeeper: How many Trapezohedrons do you want to sell?\n");
			
			do
			{
				scanf("%d", &dSellTH);
			}
			while (dSellTH > *pTrapezohedron || dSellTH <= 0);
			
			*pTrapezohedron = *pTrapezohedron - dSellTH;
			dSellBack = dSellTH*dPriceTH;
			*pWallet = *pWallet + dSellBack;
			dStockTH = dStockTH + dSellTH;
			printf("Shopkeeper: Here's your %d Gils. Nice doing business with you!\n", dSellBack);
			system("pause");
		}
		break;
		
		}
	}
		
	}
	while (dAction < 3);
}
