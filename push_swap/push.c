/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:15:17 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/13 22:40:30 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pusb_b(t_stack *stack)
{
	t_node	*a_node;
	t_node	*b_node;

	b_node = stack->b_top;
	a_node = stack->a_top;
	stack->a_top = stack->a_top->next;
	stack->a_top->prev = 0;
	a_node->prev = 0;
	a_node->next = 0;
	if (!b_node)
	{
		stack->b_top = a_node;
		stack->b_top->prev = 0;
		stack->b_top->next = 0;
	}
	else
	{
		while (b_node->next)
			b_node = b_node->next;
		b_node->next = a_node;
		b_node->next->prev = b_node;
	}
	write(1, "pb\n", 3);
}
