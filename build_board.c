/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jade <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 17:59:12 by jade              #+#    #+#             */
/*   Updated: 2018/01/21 17:14:59 by jade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		build_board(char **argv, char brd[9][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while ((argv[i][j] != 0) && (j < 9))
		{
			brd[i][j] = argv[i][j];
			brd[i][j] *= ((brd[i][j] >= '0') && (brd[i][j] <= '9'))
				|| (brd[i][j] == '.');
			j++;
		}
		if ((argv[i][j] != 0) || (j < 9))
		{
			return (1);
		}
		brd[i][j] = 0;
		i++;
	}
	return (0);
}
