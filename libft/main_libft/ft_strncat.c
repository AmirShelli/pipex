char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*start_dest;
	unsigned int	i;

	i = 0;
	start_dest = dest;
	while (*dest)
		dest++;
	while ((src[i]) && (i < nb))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (start_dest);
}
