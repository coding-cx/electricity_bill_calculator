#include <stdio.h>
#include <math.h>

//Declaring all user-defined functions at one place
float usageBill(int unitsConsumed[]);
float finalBill(float amt);
float finalBillPostDue(float amt);
void printBill(int accNo, float amt, float amtPostDue);

int main()
{
    int accNo;
    int unitsConsumed[3]; //For storing 3 months of values
    char c;
    printf("Welcome to Electricity Bill Application\n\n");
    /* Start of Gathering Inputs */
    printf("Enter the Account Number to proceed\n");
    scanf("%d", &accNo);
    printf("Enter the units consumed in the past 3 months\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &unitsConsumed[i]);
    }
    /* End of Gathering Inputs */

    float usageAmount = usageBill(unitsConsumed);

    if (usageAmount < 0)
    { //Negative UsageAmount received?
        printf("Invalid Input Entered\n");
        printf("Terminating the program...");
    }
    else
    {
        float finalAmount = finalBill(usageAmount);
        float finalAmountPostDue = finalBillPostDue(finalAmount);
        printBill(accNo, finalAmount, finalAmountPostDue);
    }
    return 0;
}

float usageBill(int unitsConsumed[])
{
    int totalUnits = 0;
    int fixedCharge;
    float energyCharge;
    for (int i = 0; i < 3; i++)
    {
        if (unitsConsumed[i] >= 0)
            totalUnits = totalUnits + unitsConsumed[i];
        else
            return -1;
    }
    printf("Total Units:\t%d\n", totalUnits);

    //Decide Tariff Rate with if-Else Ladder
    if (totalUnits >= 0 && totalUnits <= 100)
    {
        fixedCharge = 3;
        energyCharge = 0.25;
    }
    else if (totalUnits >= 101 && totalUnits <= 300)
    {
        fixedCharge = 7;
        energyCharge = 0.50;
    }
    else if (totalUnits >= 301 && totalUnits <= 500)
    {
        fixedCharge = 10;
        energyCharge = 0.75;
    }
    else
    { //Anything more than 500 units
        fixedCharge = 12;
        energyCharge = 1.00;
    }
    printf("\nCharges Levied as:\n");
    printf("Fixed Charge:\t$%d\n", fixedCharge);
    printf("Energy Charge:\t$%.2f per unit\n", energyCharge);
    return fixedCharge + (totalUnits * energyCharge);
}

float finalBill(float amt)
{
    return ceil(amt + ((0.5 / 100) * amt));
}

float finalBillPostDue(float amt)
{
    return ceil(amt + ((5.0 / 100) * amt));
}

void printBill(int accNo, float amt, float amtPostDue)
{
    for (int i = 0; i < 15; i++)
        printf("*");
    printf("\nAccount Number:\t\t\t\t%d", accNo);
    printf("\nFinal Amount:\t\t\t\t$%.0f", amt);
    printf("\nFinal Amount Post DueDate:\t\t$%.0f", amtPostDue);
    printf("\n");
    for (int i = 0; i < 15; i++)
        printf("*");
}