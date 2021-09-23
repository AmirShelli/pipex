#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
