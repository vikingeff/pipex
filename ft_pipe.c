/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 15:23:44 by gleger            #+#    #+#             */
/*   Updated: 2014/05/07 00:42:49 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_write_to_file(t_cmd *arg)
{
	int		fd;
	char	*buf;
	int		l;

	buf = (char*)malloc(sizeof(char) * 50);
	fd = open(arg->av[4], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	while ((l = read(0, buf, 50)) > 0)
		write(fd, buf, l);
}

void	ft_execute_2(t_cmd *arg)
{
	char	*cmd;

	arg->cmd2 = ft_strsplit(arg->av[3], ' ');
	cmd = ft_check_command_2(arg, X_OK);
	if (execve(cmd, arg->cmd2, arg->env) == -1)
		ft_execve_error(cmd);
}

void	ft_execute(t_cmd *arg)
{
	char	*cmd;

	arg->cmd1 = ft_strsplit(arg->av[2], ' ');
	cmd = ft_check_command(arg, X_OK);
	if (execve(cmd, arg->cmd1, arg->env) == -1)
		ft_execve_error(cmd);
}

void	ft_begin(t_cmd *arg)
{
	int		childpid;
	int		fd;
	int		fd2;

	pipe(arg->fd);
	if ((childpid = fork()) == -1)
		ft_fork_error();
	if (childpid == 0)
	{
		fd = ft_check_file(arg->av[1], R_OK);
		dup2(fd, 0);
		dup2(arg->fd[1], 1);
		close(arg->fd[0]);
		ft_execute(arg);
	}
	if (childpid > 0)
	{
		fd2 = ft_check_file_exist(arg);
		dup2(fd2, 1);
		dup2(arg->fd[0], 0);
		close(arg->fd[1]);
		ft_execute_2(arg);
	}
}
