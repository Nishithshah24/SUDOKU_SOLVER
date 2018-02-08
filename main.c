/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:40:40 by kykim             #+#    #+#             */
/*   Updated: 2018/01/21 17:40:02 by jade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		build_board(char **argv, char brd[9][9]);
int		next_spot(char brd[9][9], int spot);
int		solve_board(char brd[9][9], int spot);
void	print_sudoku(char str[9][9]);

int		main(int argc, char **argv)
{
	char board[9][9];

	if (argc == 10)
	{
		if (!build_board((argv + 1), board))
		{
			if (solve_board(board, next_spot(board, 0)))
			{
				print_sudoku(board);
				return (0);
			}
		}
	}
	print_sudoku(0);
	return (0);
}
