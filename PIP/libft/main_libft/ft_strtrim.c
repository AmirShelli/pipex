#include "libft.h"

static int	ft_isin(char c, const char *set)
{
	while (*set && c != *set)
		set++;
	return (c == *set);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t		size;
	char		*result;

	if (!s)
		return (NULL);
	while (*s && ft_isin(*s, set))
		s++;
	size = ft_strlen(s);
	while (size && ft_isin(s[size - 1], set))
		size--;
	result = ft_substr(s, 0, size);
	return (result);
}
