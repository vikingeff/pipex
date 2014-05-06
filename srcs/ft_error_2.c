/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 19:57:43 by gleger            #+#    #+#             */
/*   Updated: 2014/05/07 00:46:41 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_malloc_error(const char *s)
{
	FP2("Malloc Error: ", 2);
	FP2(s, 2);
	FP2("\n", 2);
	exit(-5);
}

void	ft_lseek_error(void)
{
	FP2("lseek error: unable to return to beginning of file.\n", 2);
	exit(-6);
}

void	ft_command_error(void)
{
	FP2("Error: Unable to retrieve PATH from environment.", 2);
	exit(-7);
}

void	ft_unknown_error(const char *s)
{
	FP2("An unknown error as appeared in ", 2);
	FP2(s, 2);
	FP2(". Exit.\n", 2);
	exit(-8);
}

void	ft_execve_error(const char *s)
{
	FP2("Execve: An error as occured while tring to execute ", 2);
	FP2(s, 2);
	FP2(".\n", 2);
	exit(-9);
}
