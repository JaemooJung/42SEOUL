#include "ft_printf_bonus.h"

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

char	*process_hex(long long num, t_opts *opts)
{
	char	*rtn;
	char	*tmp;
	int		i;

	rtn = ft_itoa_hex(num);
	if (!rtn)
		return (NULL);
	if (opts->type == 'X')
	{
		i = 0;
		while (rtn[i])
		{
			rtn[i] = ft_toupper(rtn[i]);
			i++;
		}
	}
	else if (opts->type == 'p')
	{
		tmp = ft_strjoin("0x", rtn);
		ft_free(rtn);
		rtn = tmp;
	}
	return (rtn);
}
