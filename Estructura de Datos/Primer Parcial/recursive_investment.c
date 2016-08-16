/*
   Gilberto Echeverria

   Recursive program to know the return of investment after a number of years
*/

#include<stdio.h>

float recursive_investment(float amount, int years, float interest)
{
	// At year 0, we only have the initial investment
    if (years == 0)
        return amount;
    
	// Use recursion to compute the interest over the acumulated account balance
    return (1 + interest) * recursive_investment(amount, years-1, interest);
}

int main(void)
{
    float investment;
    float interest;
    int years;

    printf("Interest return program\n");
    printf("=======================\n\n");
    printf("Enter initial investment: ");
    scanf("%f", &investment);
    printf("Enter yearly interest rate (decimal): ");
    scanf("%f", &interest);
    printf("Enter investment period in years: ");
    scanf("%d", &years);

    printf("Your investment after %d years becomes %.2f\n", years, recursive_investment(investment, years, interest));
}
