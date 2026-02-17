/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:59:03 by ajami             #+#    #+#             */
/*   Updated: 2025/07/19 14:52:00 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*add_to_end(t_stack_node **stack_node, int value)
{
	t_stack_node	*tmp;
	t_stack_node	*nouveau;

	nouveau = malloc(sizeof(t_stack_node));
	if (!nouveau)
		return (NULL);
	nouveau->value = value;
	nouveau->index = -1;
	nouveau->next = NULL;
	if (*stack_node == NULL)
	{
		*stack_node = nouveau;
		return (nouveau);
	}
	tmp = *stack_node;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = nouveau;
	return (nouveau);
}

void	index_stack(t_stack_node *stack)
{
	t_stack_node	*cur;
	t_stack_node	*min;
	int				index;

	index = 0;
	while (1)
	{
		cur = stack;
		min = NULL;
		while (cur)
		{
			if (cur->index == -1 && (!min || cur->value < min->value))
				min = cur;
			cur = cur->next;
		}
		if (!min)
			break ;
		min->index = index++;
	}
}

int	is_sorted(t_stack_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}
