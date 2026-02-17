/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 22:56:48 by ajami             #+#    #+#             */
/*   Updated: 2025/07/19 18:35:07 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	free_all(t_stack_node **a, t_stack_node **b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}

void	exit_with_error(t_stack_node **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	clean_exit(t_stack_node **stack, char **split, char *joined)
{
	if (split)
		ft_free_split(split);
	if (joined)
		free(joined);
	if (stack && *stack)
		free_all(stack, NULL);
	write(2, "Error\n", 6);
	exit(1);
}
