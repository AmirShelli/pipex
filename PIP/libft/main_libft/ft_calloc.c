#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr)
	{	
		ft_bzero(ptr, size * nmemb);
		return (ptr);
	}
	return (NULL);
}
