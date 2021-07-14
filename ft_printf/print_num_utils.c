#include "ft_printf.h"

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
