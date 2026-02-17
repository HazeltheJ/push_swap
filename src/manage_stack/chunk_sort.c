/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 01:36:19 by ajami             #+#    #+#             */
/*   Updated: 2025/07/19 15:52:36 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunk(t_stack_node **a, t_stack_node **b, int start, int end)
{
	int	size;
	int	count;

	size = stack_size(*a);
	count = 0;
	while (count < size)
	{
		if ((*a)->index >= start && (*a)->index < end)
		{
			pb(a, b);
			if ((*b)->index < (start + end) / 2)
				rb(b);
		}
		else
			ra(a);
		count++;
	}
}

void	chunk_sort(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	chunks;
	int	i;
	int	chunk_size;

	size = stack_size(*a);
	if (size <= 100)
		chunks = 5;
	else
		chunks = 11;
	chunk_size = (size / chunks) + 1;
	i = 0;
	while (i < chunks)
	{
		push_chunk(a, b, i * chunk_size, (i + 1) * chunk_size);
		i++;
	}
}
