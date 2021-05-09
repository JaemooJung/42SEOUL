#include <stdlib.h>
#include <stdio.h>
static int		get_numlen(int n)
{
	int	cnt;

	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	cnt = 0;
	if (n < 0)
	{
		cnt++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt);
}

static void		make_num_str(char *str, long int n, int numlen)
{
	int sign;

	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	else
		sign = 0;
	str[numlen] = '\0';
	numlen--;
	if (n == 0)
	{
		str[numlen] = '0';
		return ;
	}
	while (n > 0)
	{
		str[numlen] = '0' + (n % 10);
		n = n / 10;
		numlen--;
	}
	if (sign)
		str[numlen] = '-';
}

char			*ft_itoa(int n)
{
	char	*rtn;
	int		numlen;

	numlen = get_numlen(n);
	rtn = (char *)malloc((numlen + 1) * sizeof(char));
	if (!rtn)
		return (NULL);
	make_num_str(rtn, (long int)n, numlen);
	return (rtn);
}