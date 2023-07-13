/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:48:01 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/03 17:52:41 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printchars(int c)
{
	write (1, &c, 1);
	return (1);
}

int	printstr(char *str)
{
	if (str == NULL)
		return (write (1, "(null)", 6));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	printpercent(void)
{
	write (1, "%", 1);
	return (1);
}
