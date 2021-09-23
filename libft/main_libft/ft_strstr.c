#include "libft.h"

char	*ft_strstr(char *big, const char *small)
{
	int		i;

	if (!*small)
		return (big);
	while (*big)
	{
		i = 0;
		while (big[i] && big[i] == small[i])
		{
			if (!small[i + 1])
				return (big);
			++i;
		}
		big++;
	}
	return (0);
}
