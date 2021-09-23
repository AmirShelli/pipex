#include "libft.h"

int ft_isnbr(char *str)
{
	while(*str)
		if(!ft_isdigit(*str++))
			return (0);
	return (1);
}