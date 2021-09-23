#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_notabs(int n)
{
	if (n < 0)
		return (n);
	return (-n);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	size = ft_intlen(n);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n < 0)
		str[0] = '-';
	if (!n)
		str[0] = '0';
	n = ft_notabs(n);
	while (n)
	{
		str[--size] = '0' - (n % 10);
		n /= 10;
	}
	return (str);
}
