#include <stdio.h>

/**
 * jack_bauer - Prints every minute of the day from 00:00 to 23:59
 *
 * Return: nothing (void)
 */
void jack_bauer(void)
{
	int hour, min;

	for (hour = 0; hour < 24; hour++)
	{
		for (min = 0; min < 60; min++)
		{
			printf("%02d:%02d\n", hour, min);
		}
	}
}
