/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:55:17 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/03 17:52:33 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define TAM 20

char	*ft_unsigned_itoa(unsigned int n)
{
	char	str[TAM];
	long	val;
	int		i;

	i = TAM - 1;
	val = (long) n;
	str[i--] = '\0';
	while (val > 0)
	{
		str[i--] = (char)(val % 10 + '0');
		val /= 10;
	}
	if (n == 0)
		str[i--] = '0';
	return (ft_strdup(&str[i + 1]));
}

int	print_numbers(int n)
{
	int		sol;
	char	*num;

	num = ft_itoa(n);
	sol = ft_strlen((char *)num);
	printstr(num);
	free(num);
	return (sol);
}

int	print_unsigned(unsigned int n)
{
	int		sol;
	char	*str;

	sol = 0;
	if (n < 0)
		return (-1);
	str = ft_unsigned_itoa(n);
	printstr(str);
	sol = ft_strlen(str);
	free(str);
	return (sol);
}
