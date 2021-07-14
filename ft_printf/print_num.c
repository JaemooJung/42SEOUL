#include "ft_printf.h"

char	*process_num_blank(char *buff, char blk, int total_len, t_opts *opts)
{
	char	*rtn;
	char	*blk_str;
	int		blk_size;
	int		i;

	i = 0;
	blk_size = total_len - ft_strlen(buff);
	blk_str = (char *)malloc(sizeof(char) * (blk_size + 1));
	if (!blk_str)
	{
		ft_free(buff);
		return (NULL);
	}
	while (i < blk_size)
		blk_str[i++] = blk;
	blk_str[i] = '\0';
	if (opts->minus && opts->prec < 1)
		rtn = ft_strjoin(buff, blk_str);
	else
		rtn = ft_strjoin(blk_str, buff);
	ft_free(buff);
	ft_free(blk_str);
	return (rtn);
}

char	*process_negative(char *buff, t_opts *opts)
{
	char	*rtn;

	rtn = ft_strjoin("-", buff);
	opts->d_negative = -1;
	ft_free(buff);
	return (rtn);
}

char	*make_buffer(long long num, t_opts *opts)
{
	char	*rtn;

	if (num < 0)
	{
		num = -num;
		opts->d_negative = 1;
	}
	if (opts->prec && opts->prec_scale == 0 && num == 0)
		rtn = ft_strdup(" ");
	else
	{
		if (opts->type == 'X' || opts->type == 'x' || opts->type == 'p')
			rtn = process_hex(num, opts);
		else
			rtn = ft_itoa(num);
	}
	if (!rtn)
		return (NULL);
	if (opts->prec && (opts->prec_scale > ft_strlen(rtn)))
		rtn = process_num_blank(rtn, '0', opts->prec_scale, opts);
	opts->prec = -1;
	if (opts->d_negative > 0)
		rtn = process_negative(rtn, opts);
	return (rtn);
}

char	*process_width(char *buff, t_opts *opts)
{
	char	blk;

	if (ft_strlen(buff) < opts->width)
	{
		if (opts->zero && !(opts->prec))
			blk = '0';
		else
			blk = ' ';
		buff = process_num_blank(buff, blk, opts->width, opts);
	}
	if (opts->d_negative > 0)
		buff = process_negative(buff, opts);
	return (buff);
}

int	print_num(long long num, t_opts *opts)
{
	char	*buff;
	int		rtn;
	char	*tmp;

	buff = make_buffer(num, opts);
	if (!buff)
		return (0);
	buff = process_width(buff, opts);
	if (!buff)
		return (0);
	ft_putstr_fd(buff, 1);
	rtn = ft_strlen(buff);
	ft_free(buff);
	return (rtn);
}
