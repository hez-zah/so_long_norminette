/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 23:40:12 by sellyani          #+#    #+#             */
/*   Updated: 2025/02/17 23:40:53 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

char	*get_next_line(int fd);
char	**get_moves(t_stack *head);
void	double_free(char *str1, char *str2);
bool	check_moves(char *str);
void	set_move(t_stack **a, t_stack **b, char **lr);

#endif
