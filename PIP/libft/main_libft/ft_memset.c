#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*aux_str;

	aux_str = str;
	while (n--)
		*aux_str++ = c;
	return (str);
}
