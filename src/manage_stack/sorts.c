/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 00:59:21 by ajami             #+#    #+#             */
/*   Updated: 2025/07/19 18:35:02 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_four(t_stack_node **a, t_stack_node **b)
{
	int	min_pos;
	int	min_index;

	min_index = stack_min_index(*a);
	min_pos = get_index_position(*a, min_index);
	if (min_pos <= 1)
	{
		while ((*a)->index != min_index)
			ra(a);
	}
	else
	{
		while ((*a)->index != min_index)
			rra(a);
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	int	min_pos;
	int	min_index;

	min_index = stack_min_index(*a);
	min_pos = get_index_position(*a, min_index);
	if (min_pos <= 2)
	{
		while ((*a)->index != min_index)
			ra(a);
	}
	else
	{
		while ((*a)->index != min_index)
			rra(a);
	}
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

int	stack_size(t_stack_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
