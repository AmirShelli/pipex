#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest)
		return (0);
	while (src[i] && i + 1 < n)
		*dest++ = src[i++];
	if (n)
		*dest = '\0';
	return (ft_strlen(src));
}
