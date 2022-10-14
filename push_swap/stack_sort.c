/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:27:51 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/14 21:37:48 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*a_node;
	t_node	*b_node;

	a_node = stack->a_top;
	b_node = stack->b_top;
	while (a_node || b_node)
	{
		if (a_node && b_node)
		{
			printf("a: %12d,		b: %d\n", a_node->num, b_node->num);
			a_node = a_node->next;
			b_node = b_node->next;
		}
		else if (a_node)
		{
			printf("a: %12d,		b: null\n", a_node->num);
			a_node = a_node->next;
		}
		else
		{
			printf("a: %12s,	b: %d\n", "null", b_node->num);
			b_node = b_node->next;
		}
	}	
}

void	up_tri(t_stack *stack)
{
	t_node	*node;
	int		size;
	int		tmp;

	size = 0;
	tmp = stack->a_top->num;
	push_b(stack);
	while (size++ < 6)
	{
		node = stack->a_top;
		if (node->num > tmp)
		{
			tmp = node->num;
			push_b(stack);
		}
		else
			rotate_a(stack);
	}
}

void	down_tri(t_stack *stack)
{
	t_node	*node;
	int		size;
	int		tmp;

	size = 0;
	tmp = stack->a_top->num;
	push_b(stack);
	while (size++ < 6)
	{
		node = stack->a_top;
		if (node->num < tmp)
		{
			tmp = node->num;
			push_b(stack);
		}
		else
			rotate_a(stack);
	}
}

void	make_triangle(t_stack *stack, int size, int direct)
{
	if (size < 6)
	{
		if (direct)
		{
			down_tri(stack);
			down_tri(stack);
			up_tri(stack);
		}

		return ;
	}
}

void	stack_sort(t_stack *stack)
{
	t_node	*node;

	printf("atop: %d\n", stack->a_top->num);
	printf("abottom: %d\n", stack->a_bottom->num);
	printf("asize: %d\n", stack->a_size);
	node = stack->a_top;

	int	cnt;
	cnt = 0;
	int	temp;
	temp = 0;
	make_triangle(stack, 1, 1);
	print_stack(stack);
	/*
	print_stack(stack);
	push_b(stack);
	printf("------------------------\n");
	print_stack(stack);
	push_b(stack);
	printf("------------------------\n");
	print_stack(stack);
	push_a(stack);
	printf("------------------------\n");
	print_stack(stack);*/
}