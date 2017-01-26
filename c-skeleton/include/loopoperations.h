/*************************** for statement **********************************************
 * 
 * Used when the number of iterations is perdetermined
 * for(ini
 *
 ****************************************************************************************/

void printZeroToFour()
{
	int a;
	for(a=0; a< 5; a++)
	{
		printf("Number: %d\n", a);
	}
}

void printOneToFour()
{
	int a;
	for(a = 1; a < 5; a++)
	{
		printf("Number: %d\n", a);
	}
}

void printTenToOne()
{
	int a;
	for(a = 10; a >= 1; a--)
	{
		printf("Number: %d\n", a);
	}
}

void printRange()
{
	int i;
	float grade;

	for(i = 1; i < 5; i++)
	{
		printf("Enter grade: ");
		scanf("%f", &grade);
	

		// If grade >= 5 && grade <= 10 print it
		if(grade >= 5 && grade <= 10)
		{
			printf("Grade: %f\n", grade);
		}
	}
}

/******************** Break Statement ***************************************************
 *
 * Transfer control to first statement after the loop
 *
 ***************************************************************************************/

void breakStateMent()
{
	int i;
	for(i = 1; i < 10; i++)
	{
		if(i == 5)
		{
			break;		
		}
		
		printf("Number: %d\n", i);
	}

	printf("Break: i = %d\n", i);
}

void readNumberUntilZeroIsEntered()
{
	int i = 1;

	while(i > 0)
	{
		printf("Enter Number: ");
		scanf("%d", &i);
		if(i == 0)
		{
			printf("You entered zero!!! %d", i-1);
		
			if(i > 0)
			{
				printf("Number: %d\n", i);
			}
		}

	}

}
