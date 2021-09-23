#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	char			*aux;
	unsigned char	chr;

	aux = (char *)src;
	chr = c;
	while (*aux && *aux != chr)
		aux++;
	if (*aux == chr)
		return (aux);
	return (NULL);
}
