/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flags_manager.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 14:39:28 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 14:39:31 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 ** Initialize a new fresh t_flags object.
 ** Return the object or NULL if error.
*/

static t_flags *new_flags(void)
{
	t_flags *flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->left_justify = FALSE;
	flags->padding = FALSE;
	flags->positive = FALSE;
	flags->blank = FALSE;
	flags->diese = FALSE;
	return (flags);
}

/*
 ** Initilize a new fresh t_format object.
 ** Return the object or NULL if error.
*/

t_format *new_format(void)
{
	t_format *format;
	t_flags *flags;

	format = (t_format *)malloc(sizeof(t_format));
	if (!format)
		return (NULL);
	flags = new_flags();
	if (!flags)
		return (NULL);
	format->flags = flags;
	format->min_width = 0;
	format->period = FALSE;
	format->precision = 0;
	format->modifier = NULL;
	format->type = '\0';
	format->is_numeric = FALSE;
	format->is_negative = FALSE;
	return (format);
}
