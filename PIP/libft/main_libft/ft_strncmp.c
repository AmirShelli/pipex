#include "libft.h"

int	ft_strncmp(const char *s_st, const char *s_nd, unsigned int n)
{
	unsigned int	i;
	unsigned char	*aux_st;
	unsigned char	*aux_nd;

	i = 0;
	aux_st = (unsigned char *)s_st;
	aux_nd = (unsigned char *)s_nd;
	if (!n)
		return (0);
	while (aux_st[i] == aux_nd[i] && aux_st[i] && aux_nd[i] && --n)
		i++;
	return (aux_st[i] - aux_nd[i]);
}
