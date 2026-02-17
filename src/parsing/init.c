/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:12:09 by ajami             #+#    #+#             */
/*   Updated: 2025/07/19 18:34:45 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smart_push_back(t_stack_node **a, t_stack_node **b)
{
	int	pos;
	int	size;
	int	index;

	while (*b)
	{
		index = stack_max_index(*b);
		pos = get_index_position(*b, index);
		size = stack_size(*b);
		if (pos <= size / 2)
		{
			while ((*b)->index != index)
				rb(b);
		}
		else
		{
			while ((*b)->index != index)
				rrb(b);
		}
		pa(a, b);
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	size;

	size = stack_size(*a);
	if (is_sorted(*a))
		return ;
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
	{
		chunk_sort(a, b);
		smart_push_back(a, b);
		rotate_to_min(a);
	}
}
