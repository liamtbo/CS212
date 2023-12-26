/*
 * Liam Bouffard
 * CS212
 * April 12, 2022
*/

#include <stdio.h>
#include <stddef.h>

int odd_composite() 
{
	int x;
	int y;
	for (x=10; x<=500; x++) // loop from 10 to 100
	{
		if (x % 2 != 0) // check if odd
		{
			for (y=2; y<x; y++) // loop over every number 1 < y < x
			{
				if (x % y == 0) // check if composite
				{
					printf("%d is a composite number.\n", x);
					break;
				}
			}
		}
		
	}
	return 0;
}


int main()
{
	odd_composite();
	return 0;
}


