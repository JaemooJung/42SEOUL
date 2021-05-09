#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rtn;

	if (!s)
		return (NULL);
	if (!(*f))
		return ((char *)s);
	rtn = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!rtn)
		return (NULL);
	i = 0;
	while (s[i])
	{
		rtn[i] = f(i, s[i]);
		i++;	
	}
	rtn[i] = '\0';
	return (rtn);
}