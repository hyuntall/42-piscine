/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:29:04 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/13 22:40:47 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init(t_stack *stack)
{
	stack->a_size = 0;
	stack->a_top = 0;
	stack->a_bottom = 0;
	stack->b_size = 0;
	stack->b_top = 0;
	stack->b_bottom = 0;
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	init(&stack);
	// 파라미터 파싱 하는 함수
	if (!argv_to_stack(&stack, ++argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	swap_a(&stack);
	pusb_b(&stack);
	pusb_b(&stack);
	printf("top: %d\n", stack.a_top->num);
	printf("bottom: %d\n", stack.a_bottom->num);
	printf("size: %d\n", stack.a_size);

	t_node *node;
	node = stack.b_top;
	while (node)
	{
		printf("list %d\n", node->num);
		node = node->next;
	}
	// 파싱된 함수의 배열을 정렬하는 함수
	// push_swap
	system("leaks a.out");
	return (0);
}