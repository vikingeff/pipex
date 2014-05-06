/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 13:02:31 by gleger            #+#    #+#             */
/*   Updated: 2014/05/07 01:53:32 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	ft_fork_error(void)
{
	FP2("Error: fork has encountered a problem and can't be executed.", 2);
	FP2("Exit.\n", 2);
	exit(-1);
}

void	ft_right_error(const char *s)
{
	FP2("Error: Permission denied for ", 2);
	FP2(s, 2);
	FP2("\n", 2);
	exit(-2);
}

void	ft_exist_error(const char *s)
{
	FP2("Error: ", 2);
	FP2(s, 2);
	FP2(" doesn't exist\n", 2);
	exit(-3);
}

void	ft_arg_error(const char *s)
{
	FP2("Pipex usage error: ", 2);
	FP2(s, 2);
	FP2("\n", 2);
	FP2("Usage: ./pipex infile command1 command2 outfile\n", 2);
	exit(-4);
}
