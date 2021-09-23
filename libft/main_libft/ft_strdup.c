#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*aux_src;
	char	*copy;

	aux_src = malloc(ft_strlen(src) + 1);
	if (!aux_src || !src)
		return (NULL);
	copy = aux_src;
	while (*src)
		*aux_src++ = *src++;
	*aux_src = '\0';
	return (copy);
}
