#include "main.h"

int main(void)
{
	int i = 0;
	char *str = "_putchar";

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');

	return (0);
}
