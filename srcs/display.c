/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 19:35:21 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 19:35:23 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
 ** Puts on stdout n char from str.
*/

void display(const char *str, int n)
{
	int i;

	if (!str || n <= 0)
		return;
	i = 0;
	while (str[i] && i < n)
	{
		ft_putchar(str[i]);
		i++;
	}
}

char *process_type_with_modifier(t_format *infos, va_list *args)
{
	void *value;
	char *res;

	value = va_arg(*args, void *);

	if (infos->type == '%')
		return ft_strdup("%");
	if (infos->type == 'i' || infos->type == 'd' || infos->type == 'D')
	{
		if (infos->modifier)
		{
			if (ft_strcmp(infos->modifier, "l") == 0)
				return ft_itoall((long)value);
			if (ft_strcmp(infos->modifier, "ll") == 0)
				return ft_itoall((long long)value);
			if (ft_strcmp(infos->modifier, "z") == 0)
				return ft_itoaull((size_t)value);
			if (ft_strcmp(infos->modifier, "j") == 0)
				return ft_itoall((intmax_t)value);
			if (ft_strcmp(infos->modifier, "hh") == 0 && infos->type == 'D')
				return ft_itoall((long)value);
			if (ft_strcmp(infos->modifier, "hh") == 0)
				return ft_itoall((char)value);
			if (ft_strcmp(infos->modifier, "h") == 0)
				return ft_itoall((short)value);
		}
		if (infos->type == 'D')
			return ft_itoall((long)value);
		return ft_itoall((int)value); // modifier h or hh call int
	}
	else if (infos->type == 'u' || infos->type == 'U')
	{
		if (infos->modifier)
		{
			if (ft_strcmp(infos->modifier, "l") == 0)
				return ft_itoaull((unsigned long)value);
			if (ft_strcmp(infos->modifier, "ll") == 0)
				return ft_itoaull((unsigned long long)value);
			if (ft_strcmp(infos->modifier, "j") == 0)
				return ft_itoaull((uintmax_t)value);
			if (ft_strcmp(infos->modifier, "z") == 0)
				return ft_itoaull((size_t)value);
			if (ft_strcmp(infos->modifier, "h") == 0 && infos->type == 'U')
				return ft_itoaull((unsigned long)value);
			if (ft_strcmp(infos->modifier, "h") == 0)
				return ft_itoaull((unsigned short)value);
			if (ft_strcmp(infos->modifier, "hh") == 0 && infos->type == 'U')
				return ft_itoaull((unsigned long)value);
			if (ft_strcmp(infos->modifier, "hh") == 0)
				return ft_itoaull((unsigned char)value);
		}
		if (infos->type == 'U')
			return ft_itoaull((unsigned long)value);
		return ft_itoaull((unsigned int)value);
	}
	else if (infos->type == 's')
	{
		res = (char *)value;
		if (!res)
			return ft_strdup("(null)");
		return (res);
	}
	else if (infos->type == 'X' || infos->type == 'x')
	{
		if (infos->modifier)
		{
			if (ft_strcmp(infos->modifier, "l") == 0)
				return ft_itoaull_base((unsigned long)value, 16, infos->type == 'X');
			if (ft_strcmp(infos->modifier, "ll") == 0)
				return ft_itoaull_base((unsigned long long)value, 16, infos->type == 'X');
			if (ft_strcmp(infos->modifier, "z") == 0)
				return ft_itoaull_base((size_t)value, 16, infos->type == 'X');
			if (ft_strcmp(infos->modifier, "h") == 0)
				return ft_itoall_base((unsigned short)value, 16, infos->type == 'X');
			if (ft_strcmp(infos->modifier, "h") == 0)
				return ft_itoaull_base((unsigned long)value, 16, infos->type == 'X');
			if (ft_strcmp(infos->modifier, "hh") == 0)
				return ft_itoaull_base((unsigned char)value, 16, infos->type == 'X');
			if (ft_strcmp(infos->modifier, "j") == 0)
				return ft_itoaull_base((uintmax_t)value, 16, infos->type == 'X');
		}
		return ft_itoaull_base((unsigned int)value, 16, infos->type == 'X');
	}
	else if (infos->type == 'o' || infos->type == 'O')
	{
		if (infos->modifier)
		{
			if (ft_strcmp(infos->modifier, "l") == 0)
				return ft_itoaull_base((unsigned long)value, 8, FALSE);
			if (ft_strcmp(infos->modifier, "ll") == 0)
				return ft_itoaull_base((unsigned long long)value, 8, FALSE);
			if (ft_strcmp(infos->modifier, "z") == 0)
				return ft_itoaull_base((size_t)value, 8, FALSE);
			if (ft_strcmp(infos->modifier, "h") == 0)
				return ft_itoall_base((unsigned short)value, 8, FALSE);
			if (ft_strcmp(infos->modifier, "h") == 0)
				return ft_itoaull_base((unsigned long)value, 8, FALSE);
			if (ft_strcmp(infos->modifier, "j") == 0)
				return ft_itoaull_base((uintmax_t)value, 8, FALSE);
			if (ft_strcmp(infos->modifier, "hh") == 0 && infos->type == 'O')
				return ft_itoaull_base((unsigned long)value, 8, FALSE);
			if (ft_strcmp(infos->modifier, "hh") == 0)
				return ft_itoaull_base((unsigned char)value, 8, FALSE);
		}
		if (infos->type == 'O')
			return ft_itoall_base((long)value, 8, FALSE);
		return ft_itoall_base((unsigned int)value, 8, FALSE);
	}
	else if (infos->type == 'c')
	{
		res = ft_strdup("");
		res[0] = (unsigned char)value;
		return (res);
	}
	else if (infos->type == 'p')
		return ft_strjoin("0x", ft_itoall_base((long)value, 16, FALSE));
	return (NULL);
}

char *ft_init(size_t len, char c)
{
	char *res;
	size_t i;

	res = ft_memalloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = c;
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
 ** Puts new in src at start_index
*/
void ft_write(char **src, char *new, size_t start_index)
{
	size_t y;

	y = 0;
	while (y < ft_strlen(new))
	{
		(*src)[start_index + y] = new[y];
		y++;
	}
}

char *process_flags_and_precision(char *res, t_format *format)
{
	char *final; // will be the final result
	char *add;   // will be the add bufffer to complete final

	int addlen;

	final = NULL;
	add = NULL;

	if (format->flags->blank && !(format->flags->positive)) // ' '
	{
		if (format->is_numeric && !(format->is_negative) && (format->type == 'D' || format->type == 'd' || format->type == 'i'))
			add = ft_strdup(" ");
	}

	if (format->flags->positive && format->is_numeric && (format->type == 'D' || format->type == 'd' || format->type == 'i')) // '+'
	{
		if (!(format->is_negative))
			add = ft_strdup("+");
	}

	if (format->is_numeric && format->is_negative)
		add = ft_strdup("-");

	if (format->period && format->precision == 0 && ft_strcmp(res, "0") == 0)
		res = ft_strdup("");

	if (format->flags->diese && format->is_numeric) // '#'
	{
		if (ft_strcmp(res, "0") != 0 && ft_strlen(res) > 0)
		{
			if (format->type == 'x')
				add = ft_strdup("0x");
			if (format->type == 'X')
				add = ft_strdup("0X");
		}
		if (format->type == 'o')
			add = ft_strdup("0");
	}

	addlen = add != NULL ? ft_strlen(add) : 0;

	if (format->is_numeric && format->precision > 0)
	{
		while (ft_strlen(res) < format->precision)
			res = ft_strjoin("0", res);
	}

	if (ft_strlen(res) + addlen < format->min_width)
	{
		if (format->flags->padding && format->is_numeric && !format->flags->left_justify && format->precision == 0) // '0'
			final = ft_init(format->min_width, '0');
		else
			final = ft_init(format->min_width, ' ');
	}
	else
	{
		if (add)
			final = ft_strjoin(add, res);
		else
			final = res;
		return (final);
	}

	if (format->flags->padding && !(format->flags->left_justify))
	{
		if (add)
			ft_write(&final, add, 0);
		ft_write(&final, res, ft_strlen(final) - ft_strlen(res));
	}
	else if (format->flags->left_justify) // '-'
	{
		if (add)
			ft_write(&final, add, 0);
		ft_write(&final, res, addlen);
	}
	else if (!(format->flags->left_justify) && !(format->flags->padding))
	{
		if (add)
			ft_write(&final, add, ft_strlen(final) - ft_strlen(res) - ft_strlen(add));
		ft_write(&final, res, ft_strlen(final) - ft_strlen(res));
	}

	return (final);
}

int display_format(t_format *infos, va_list *args)
{
	char *res;
	char *final;
	int len;

	if (!(infos->type))
		return 0;

	res = process_type_with_modifier(infos, args);
	if (!res)
		return (0);
	if (res[0] == 0)
	{
		ft_putchar(0);
		return (1);
	}
	if (res[0] == '-')
	{
		res = ft_strsub(res, 1, ft_strlen(res) - 1);
		infos->is_negative = TRUE;
	}
	final = process_flags_and_precision(res, infos);
	if (!final)
		return (0);

	ft_putstr(final);
	/*len = ft_strlen(final);

	free(res);
	free(final);*/

	len = ft_strlen(final);

	return (len);
}
