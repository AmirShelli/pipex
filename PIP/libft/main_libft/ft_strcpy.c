char	*ft_strcpy(char *dest, char *src)
{
	char	*start_dest;

	start_dest = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (start_dest);
}
