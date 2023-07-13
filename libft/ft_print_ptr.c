/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:33:32 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/03 17:52:28 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ptr_size(uintptr_t ptr)
{
	int	sol;

	sol = 0;
	while (ptr != 0)
	{
		sol++;
		ptr /= 16;
	}
	return (sol);
}

void	putptr(uintptr_t hexa)
{
	if (hexa >= 16)
	{
		putptr(hexa / 16);
		putptr(hexa % 16);
	}
	else
	{
		if (hexa <= 9)
			printchars(hexa + '0');
		else
			printchars(hexa - 10 + 'a');
	}
}

int	ptr_print(uintptr_t ptr)
{
	int	sol;

	sol = 0;
	sol = write (1, "0x", 2);
	if (ptr == 0)
	{
		write (1, "0", 1);
		return (sol + 1);
	}
	putptr(ptr);
	sol += ptr_size(ptr);
	return (sol);
}
