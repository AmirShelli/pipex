#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t size)
{
	char	*str;
	char	*aux_str;

	if (!s)
		return (NULL);
	if (ft_strlen(s + start) < size)
		size = ft_strlen(s + start);
	str = (char *)ft_calloc(size + 1, sizeof(char));
	aux_str = str;
	if (str)
	{
		if (start < ft_strlen(s))
			while (*(s + start) && size--)
				*str++ = *(s++ + start);
	}
	return (aux_str);
}
