/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jade <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 14:42:31 by jade              #+#    #+#             */
/*   Updated: 2018/01/21 20:48:45 by jade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		next_spot(char brd[9][9], int start)
{
	while (start < 81)
	{
		if (brd[start / 9][start % 9] == '.')
		{
			return (start);
		}
		start++;
	}
	return (start);
}

int		check_square(char brd[9][9], int spot)
{
	int square;
	int i;

	i = 0;
	square = 0;
	while (i < 9)
	{
		if (square & ((brd[3 * (spot / 27) + (i / 3)]
				[(spot % 9) - (spot % 3) + (i % 3)] != '.')
			* (1 << (brd[3 * (spot / 27) + (i / 3)]
				[(spot % 9) - (spot % 3) + (i % 3)] - '1'))))
			return (0);
		square |= (brd[3 * (spot / 27) + (i / 3)]
				[((spot % 9) - (spot % 3)) + (i % 3)] != '.')
				* (1 << (brd[3 * (spot / 27) + (i / 3)]
							[((spot % 9) - (spot % 3)) + (i % 3)] - '1'));
		i++;
	}
	return (square);
}

int		check_spot(char brd[9][9], int spot)
{
	int rows;
	int cols;
	int i;

	i = 0;
	rows = 0;
	cols = 0;
	while (i < 9)
	{
		if (rows & ((brd[spot / 9][i] != '.')
				* (1 << (brd[spot / 9][i] - '1'))))
			return (0);
		rows |= (brd[spot / 9][i] != '.') * (1 << (brd[spot / 9][i] - '1'));
		if (cols & ((brd[i][spot % 9] != '.') *
				(1 << (brd[i][spot % 9] - '1'))))
			return (0);
		cols |= (brd[i][spot % 9] != '.') * (1 << (brd[i][spot % 9] - '1'));
		i++;
	}
	return ((rows | cols | check_square(brd, spot)) ^ ((1 << 9) - 1));
}

int		solve_board(char brd[9][9], int spot)
{
	int possible;
	int i;

	if (spot == 81)
		return (1);
	i = 0;
	possible = check_spot(brd, spot);
	while (possible)
	{
		while (!(possible & (1 << i)) && i < 8)
			i++;
		brd[spot / 9][spot % 9] = '1' + i;
		if (solve_board(brd, next_spot(brd, spot + 1)))
		{
			return (1);
		}
		possible ^= (1 << i);
		brd[spot / 9][spot % 9] = '.';
	}
	return (0);
}
