/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jade <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:22:48 by jade              #+#    #+#             */
/*   Updated: 2018/01/21 22:15:28 by nshah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_sudoku(char str[9][9])
{
	int		i;
	char	c;

	if (!str)
	{
		write(1, "Error\n", 6);
		return ;
	}
	i = 0;
	while (i < 81)
	{
		c = ' ' - 22 * ((i % 9) == 8);
		write(1, str[i / 9] + i % 9, 1);
		write(1, &c, 1);
		i++;
	}
}