#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	char	*ptr_src;
	char	*aux_src;

	ptr_src = (char *)src;
	aux_src = (char *)src;
	while (*ptr_src)
	{
		if (*ptr_src == (char)c)
			aux_src = (char *)ptr_src;
		ptr_src++;
	}
	if (*ptr_src == (char)c)
		return (ptr_src);
	if (*aux_src == (char)c)
		return (aux_src);
	return (NULL);
}
