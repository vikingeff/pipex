/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_things.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 13:07:51 by gleger            #+#    #+#             */
/*   Updated: 2014/05/07 01:34:34 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int		ft_check_file(char *s, int amode)
{
	int	fd;

	if (access(s, F_OK) == 0)
	{
		if (access(s, amode) == 0)
		{
			fd = open(s, O_RDONLY);
			return (fd);
		}
		else
			ft_right_error(s);
	}
	else
		ft_exist_error(s);
	return (0);
}

int		ft_check_file_exist(t_cmd *arg)
{
	int		fd;
	int		retf;
	int		retw;

	fd = 0;
	if ((retf = access(arg->av[4], F_OK)) == 0)
	{
		if ((retw = access(arg->av[4], W_OK)) == 0)
		{
			fd = open(arg->av[4], O_TRUNC | O_WRONLY);
			return (fd);
		}
		else
			ft_right_error(arg->av[4]);
	}
	else
		fd = open(arg->av[4], O_CREAT | O_WRONLY, S_IWUSR | S_IRUSR);
	return (fd);
}

char	*ft_check_command_2(t_cmd *arg, int amode)
{
	int		i;
	char	**path;
	char	*join;
	int		retf;
	int		reta;

	i = 0;
	if ((path = ft_getenv("PATH", arg->env)) == NULL)
		ft_command_error();
	while (path[i] != NULL)
	{
		join = ft_strjoin(path[i], arg->cmd2[0]);
		if ((retf = access(join, F_OK)) == 0)
		{
			if ((reta = access(join, amode)) == 0)
				return (join);
		}
		i++;
	}
	if (retf == -1)
		ft_exist_error(arg->cmd2[0]);
	else if (reta == -1)
		ft_right_error(arg->cmd2[0]);
	return (NULL);
}

char	*ft_check_command(t_cmd *arg, int amode)
{
	int		i;
	char	**path;
	char	*join;
	int		retf;
	int		reta;

	i = 0;
	if ((path = ft_getenv("PATH", arg->env)) == NULL)
		ft_command_error();
	while (path[i] != NULL)
	{
		join = ft_strjoin(path[i], arg->cmd1[0]);
		if ((retf = access(join, F_OK)) == 0)
		{
			if ((reta = access(join, amode)) == 0)
				return (join);
		}
		i++;
	}
	if (retf == -1)
		ft_exist_error(arg->cmd1[0]);
	else if (reta == -1)
		ft_right_error(arg->cmd1[0]);
	return (NULL);
}

int		ft_check_files_and_commands(t_cmd *arg)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (arg->av[i])
	{
		j = 0;
		k = 0;
		if (access(arg->av[i], F_OK) == 0)
		{
			if (access(arg->av[i], W_OK) == 0)
				k++;
			j++;
		}
		if (j != 1)
			ft_exist_error(arg->av[i]);
		if (k != 1)
			ft_right_error(arg->av[i]);
		i++;
	}
	return (0);
}
