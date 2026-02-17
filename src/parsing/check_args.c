/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:19:06 by ajami             #+#    #+#             */
/*   Updated: 2025/07/19 18:33:06 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static void	check_stack(char *stack, t_stack_node **stack_node)
{
	char	**tab;
	char	**tmp;
	int		value;

	tab = ft_split(stack, ' ');
	if (!tab || !tab[0])
	{
		if (tab)
			ft_free_split(tab);
		free(stack);
		write(2, "Error\n", 6);
		exit(1);
	}
	tmp = tab;
	while (*tab)
	{
		if (big_check(*tab, &value))
		{
			free(stack);
			clean_exit(stack_node, tmp, NULL);
		}
		add_to_end(stack_node, value);
		tab++;
	}
	ft_free_split(tmp);
}

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

static char	*join_arguments(char **av, int ac)
{
	char	*joined;
	int		i;

	joined = ft_strdup("");
	if (!joined)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		if (!av[i] || av[i][0] == '\0')
		{
			free(joined);
			return (NULL);
		}
		joined = ft_strjoin_free(joined, av[i]);
		if (!joined)
			return (NULL);
		if (++i < ac)
		{
			joined = ft_strjoin_free(joined, " ");
			if (!joined)
				return (NULL);
		}
	}
	return (joined);
}

void	join_args(char **av, int ac, t_stack_node **stack_node)
{
	char	*joined;

	joined = join_arguments(av, ac);
	if (!joined)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	check_stack(joined, stack_node);
	check_double(*stack_node, joined);
	index_stack(*stack_node);
	free(joined);
}
