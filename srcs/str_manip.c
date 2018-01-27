/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   str_manip.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 15:10:48 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 15:10:51 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
 ** Remove n char from str.
*/
char *resize(char *str, int n)
{
    char *res;
    if (!str)
    {
        printf("Resize 1 error str : %s, n : %i\n", str, n);
        return (NULL);
    }
    if (n == 0)
        return (str);
    res = ft_strsub(str, n, ft_strlen(str) - n);
    if (!res)
    {
        printf("Resize 2 error\n");
        return (NULL);
    }
    return (res);
}