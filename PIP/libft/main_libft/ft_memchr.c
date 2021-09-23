#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*aux_src;

	aux_src = (unsigned char *)src;
	while (n--)
	{
		if (*aux_src == (unsigned char)c)
			return (aux_src);
		aux_src++;
	}
	return (NULL);
}
