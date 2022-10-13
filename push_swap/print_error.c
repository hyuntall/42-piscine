/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:52:18 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/13 21:41:24 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(t_stack	*stack)
{
	t_node	*node;
	t_node	*temp;

	node = stack->a_top;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	//node_remove(&node);
	write(2, "Error\n", 6);
	exit(1);
}
