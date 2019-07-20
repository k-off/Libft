/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:00:42 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:01:42 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_precision(t_data *data, const char *s, int *i)
{
	data->precision = ft_atoi(&s[*i]);
	if (data->precision <= 0)
	{
		data->precision = 0;
		data->no_precision = -1;
	}
	while (ft_isdigit(s[*i]))
		(*i)++;
}

static void	get_width(t_data *data, const char *s, int *i)
{
	data->width = ft_atoi(&s[*i]);
	if (data->width < 0)
		data->width = 0;
	while (ft_isdigit(s[*i]))
		(*i)++;
}

static void	flags_2(t_data *data, const char *s, int *i)
{
	if ((s[*i] == 'h' && s[*i + 1] == 'h')
		|| (s[*i] == 'l' && s[*i + 1] == 'l'))
		(*i) += 2;
	else if (s[*i] == '.')
	{
		data->dot = 1;
		(*i)++;
		if (ft_isdigit(s[*i]))
			get_precision(data, s, i);
		else
			data->no_precision = -1;
	}
	else if (s[*i] != 0 && ft_isdigit(s[*i]))
		get_width(data, s, i);
	else
		(*i)++;
}

void		flags_1(t_data *data, const char *s, int *i)
{
	if (s[*i] == 'h' && s[*i + 1] == 'h')
		data->hh = 1;
	else if (s[*i] == 'l' && s[*i + 1] == 'l')
		data->ll = 1;
	else if (s[*i] == 'h')
		data->h = 1;
	else if (s[*i] == 'l')
		data->l = 1;
	else if (s[*i] == 'L')
		data->lll = 1;
	else if (s[*i] == '#')
		data->hash = 1;
	else if (s[*i] == '0')
		data->zero = 1;
	else if (s[*i] == '-')
		data->minus = 1;
	else if (s[*i] == '+')
		data->plus = 1;
	else if (s[*i] == ' ')
		data->space = 1;
	flags_2(data, s, i);
}
