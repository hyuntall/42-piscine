/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:31:40 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/09/06 21:30:37 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(0);
	while (line)
	{
		printf("Gnl %d line : %s", i++, line);
		free(line);
		line = get_next_line(0);
	}
	printf("\n");
	free(line);
	return (0);
}
