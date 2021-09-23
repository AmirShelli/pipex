#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*aux_s;
	size_t	i;

	aux_s = s;
	i = 0;
	while (i < n)
		aux_s[i++] = 0;
}
