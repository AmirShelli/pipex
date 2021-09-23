#include "libft.h"

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		if (nbr == -2147483648)
			ft_putstr("-2147483648");
		else
		{
			ft_putchar('-');
			ft_putnbr(nbr * (-1));
		}
	}
	else
	{
		if (nbr > 9)
		{
			ft_putnbr(nbr / 10);
			ft_putchar('0' + (nbr % 10));
		}
		else
			ft_putchar('0' + (nbr % 10));
	}
}
