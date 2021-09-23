#include "libft.h"

static void	ft_arrclean(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i++] = NULL;
	}
	free(arr);
	arr = NULL;
}

static void	ft_skipspl(const char **str, char spl)
{
	while (**str && **str == spl)
		(*str)++;
}

static int	ft_firstlen(const char *str, char spl)
{
	int	wordlen;

	wordlen = 0;
	while (*str && *str != spl)
	{
		wordlen++;
		str++;
	}
	return (wordlen);
}

static int	ft_countwords(const char *str, char spl)
{
	int	n_words;

	n_words = 0;
	while (*str)
	{	
		ft_skipspl(&str, spl);
		if (*str)
		{
			n_words++;
			str = str + ft_firstlen(str, spl);
		}
	}
	return (n_words);
}

char	**ft_split(const char *str, char spl)
{
	char	**splitted;
	int		i;

	i = 0;
	splitted = (char **)malloc((ft_countwords(str, spl) + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	while (ft_countwords(str, spl))
	{
		ft_skipspl(&str, spl);
		if (*str)
		{
			splitted[i++] = ft_substr(str, 0, ft_firstlen(str, spl));
			if (!splitted[i - 1])
			{
				ft_arrclean(splitted);
				return (NULL);
			}
			str = str + ft_firstlen(str, spl);
		}
	}
	splitted[i] = NULL;
	return (splitted);
}
