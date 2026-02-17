/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:11:00 by ajami             #+#    #+#             */
/*   Updated: 2025/07/18 19:50:50 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a)
{
	t_stack_node	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	t_stack_node	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	int	did_sa;
	int	did_sb;

	did_sa = 0;
	did_sb = 0;
	if (*a && (*a)->next)
	{
		sa(a);
		did_sa = 1;
	}
	if (*b && (*b)->next)
	{
		sb(b);
		did_sb = 1;
	}
	if (did_sa && did_sb)
		ft_printf("ss\n");
	else if (did_sa)
		ft_printf("sa\n");
	else if (did_sb)
		ft_printf("sb\n");
}
