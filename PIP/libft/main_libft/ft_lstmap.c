#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*next;
	t_list	*tmp;

	new_lst = NULL;
	while (lst)
	{
		next = ft_lstnew((*f)(lst->content));
		if (!next)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, next);
		tmp = new_lst->next;
		lst = lst->next;
	}
	return (new_lst);
}
