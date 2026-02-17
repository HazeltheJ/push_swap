/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:13:53 by ajami             #+#    #+#             */
/*   Updated: 2025/07/18 19:49:18 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack_node **a)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!*a || !(*a)->next)
		return ;
	second_last = NULL;
	last = *a;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *a;
	*a = last;
	ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!*b || !(*b)->next)
		return ;
	second_last = NULL;
	last = *b;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *b;
	*b = last;
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	if (*a && (*a)->next)
		rra(a);
	if (*b && (*b)->next)
		rrb(b);
	ft_printf("rrr\n");
}
