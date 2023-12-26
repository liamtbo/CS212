/*Liam Bouffard
 * April 24, 2023
 * project2B
*/

#include <stdio.h>

int sortArray(int arr[])
{
	int print_count = 0;
	for (int i = 0; i <= 100; i++)
	{
		for (int j = i+1; j <= 500; j++)
		{
			if (arr[i] > arr[j])
			{
				int capture = arr[i];
				arr[i] = arr[j];
				arr[j] = capture;
			{
		}
		if (print_count > 10)
		{
			printf("\n");
			print_count = 0;
		}
		printf("%d\n", i);
		print_count += 1;
	}
}

int main(int argc, char *argv[])
{
	sortArray(argv);
{



