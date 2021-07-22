#include "ft_printf.h"

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

	if (opts->prec && opts->prec_scale == 0 && num == 0 && opts->type == 'p')
		return (ft_strdup("0x"));
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

char	*process_negative(char *buff, t_opts *opts)
{
	char	*rtn;

	if ((!(opts->zero) || (opts->zero && opts->prec))
		&& (opts->type == 'i' || opts->type == 'd'))
	{
		rtn = ft_strjoin("-", buff);
		ft_free(buff);
		opts->d_negative = -1;
		return (rtn);
	}
	return (buff);
}

char	*process_negative_with_zero(char *buff, t_opts *opts)
{
	char	*rtn;

	rtn = NULL;
	if (opts->zero)
	{
		if (ft_strlen(buff) > opts->width)
		{
			rtn = ft_strjoin("-", buff);
			free(buff);
		}
		else
		{
			if (buff[0] == '0')
			{
				buff[0] = '-';
				return (buff);
			}
			else
			{
				rtn = ft_strjoin("-", buff);
				free(buff);
			}
		}
	}
	return (rtn);
}
