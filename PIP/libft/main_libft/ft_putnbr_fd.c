#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr < 0)
	{
		if (nbr == -2147483648)
			ft_putstr_fd("-2147483648", fd);
		else
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(nbr * (-1), fd);
		}
	}
	else
	{
		if (nbr > 9)
		{
			ft_putnbr_fd(nbr / 10, fd);
			ft_putchar_fd('0' + (nbr % 10), fd);
		}
		else
			ft_putchar_fd('0' + (nbr % 10), fd);
	}
}
