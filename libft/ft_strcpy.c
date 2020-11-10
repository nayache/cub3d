#include "libft.h"

char	*ft_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	if (!src || !dst)
		return (NULL);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
