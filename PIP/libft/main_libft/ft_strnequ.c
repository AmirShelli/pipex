#include "libft.h"

int	ft_strnequ(char const *s_st, char const *s_nd, size_t n)
{
	size_t	i;

	i = 0;
	if (!s_st || !s_nd)
		return (0);
	if (!n)
		return (1);
	while ((s_st[i] == s_nd[i]) && (s_st[i]) && (s_nd[i]) && i < n - 1)
		i++;
	return (s_st[i] == s_nd[i]);
}
