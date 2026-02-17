/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:29:45 by ajami             #+#    #+#             */
/*   Updated: 2025/07/19 18:18:52 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
}						t_stack_node;

void					join_args(char **stack, int ac,
							t_stack_node **stack_node);
int						big_check(char *str, int *value);
t_stack_node			*add_to_end(t_stack_node **stack_node, int value);
int						check_double(t_stack_node *stack, char *joined);
void					index_stack(t_stack_node *stack);
int						stack_size(t_stack_node *stack);
int						is_sorted(t_stack_node *stack);
void					pa(t_stack_node **a, t_stack_node **b);
void					pb(t_stack_node **a, t_stack_node **b);
void					rra(t_stack_node **a);
void					rrb(t_stack_node **b);
void					ra(t_stack_node **a);
void					rb(t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);
void					rrr(t_stack_node **a, t_stack_node **b);
void					sa(t_stack_node **a);
void					sort_four(t_stack_node **a, t_stack_node **b);
void					sort_five(t_stack_node **a, t_stack_node **b);
void					sb(t_stack_node **b);
void					clean_exit(t_stack_node **stack, char **split,
							char *joined);
void					ft_free_split(char **tab);
int						stack_max_index(t_stack_node *stack);
void					ss(t_stack_node **a, t_stack_node **b);
void					sort_stack(t_stack_node **a, t_stack_node **b);
void					sort_three(t_stack_node **a);
int						stack_min_index(t_stack_node *stack);
int						stack_max_index(t_stack_node *stack);
void					chunk_sort(t_stack_node **a, t_stack_node **b);
void					rotate_to_min(t_stack_node **a);
void					free_stack(t_stack_node **stack);
void					exit_with_error(t_stack_node **stack);
void					free_all(t_stack_node **a, t_stack_node **b);
int						get_index_position(t_stack_node *stack, int index);
void					smart_push_back(t_stack_node **a, t_stack_node **b);
int						get_index_position(t_stack_node *stack, int index);

#endif