#include "libft.h"

void	ft_putendl(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			write(1, &str[i++], 1);
		write(1, "\n", 1);
	}
}
