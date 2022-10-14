/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:28:26 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/14 19:33:02 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sort(t_stack *stack)
{
	t_node	*node;

	node = stack->a_top;
	while (node->next)
	{
		if (node->num > node->next->num)
			return (0);
		node = node->next;
	}
	return (1);
}
