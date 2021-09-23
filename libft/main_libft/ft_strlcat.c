#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	const char	*ptr_src;
	size_t		init_size;
	size_t		curr_size;

	ptr_src = src;
	init_size = ft_strlen(dest);
	curr_size = ft_strlen(dest);
	while (*src && curr_size + 1 < size)
		dest[curr_size++] = *src++;
	dest[curr_size] = '\0';
	if (size > init_size)
		return (ft_strlen(ptr_src) + init_size);
	return (ft_strlen(ptr_src) + size);
}
