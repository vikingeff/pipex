/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 12:04:57 by gleger            #+#    #+#             */
/*   Updated: 2014/05/07 01:32:25 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	ft_copy_environ(char **environ, char ***env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (environ[i] != NULL)
		i++;
	if (!((*env) = (char**)malloc(sizeof(char*) * (i + 1))))
		ft_malloc_error(AM);
	i = 0;
	while (environ[i] != NULL)
	{
		j = 0;
		while (environ[i][j] != '\0')
			j++;
		if (!((*env)[i] = (char*)malloc(sizeof(char) * j)))
			ft_malloc_error(AM);
		j = -1;
		while (environ[i][++j] != '\0')
			(*env)[i][j] = environ[i][j];
		(*env)[i][j] = '\0';
		i++;
	}
	(*env)[i] = NULL;
}

int		main(int ac, char **av)
{
	extern char	**environ;
	t_cmd		*arg;
	char		**env;

	ft_copy_environ(environ, &env);
	if (ac != 5)
		ft_arg_error("Not enough arguments");
	if (!(arg = (t_cmd*)malloc(sizeof(t_cmd))))
		ft_malloc_error("Unable to allocated suffisant memory");
	arg->av = av;
	arg->env = env;
	ft_begin(arg);
	return (0);
}
