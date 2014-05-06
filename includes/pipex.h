/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 11:56:38 by gleger            #+#    #+#             */
/*   Updated: 2014/05/07 01:28:42 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define FP ft_printf
# define FP2 ft_putstr_fd
# define AM "allocate suffisant memory to copy the environment variables"

typedef struct	s_cmd
{
	int		fd[2];
	char	**av;
	char	**cmd1;
	char	**cmd2;
	char	**env;
}				t_cmd;

void			mod_path(char **path);
char			**ft_getenv(char *s, char **env);
int				ft_check_file_exist(t_cmd *arg);
char			*ft_check_command_2(t_cmd *arg, int amode);
char			*ft_check_command(t_cmd *arg, int amode);
int				ft_check_file(char *s, int amode);
int				ft_check_files_and_commands(t_cmd *arg);
void			ft_write_to_file(t_cmd *arg);
void			ft_execute_2(t_cmd *arg);
void			ft_execute(t_cmd *arg);
void			ft_begin(t_cmd *arg);
void			ft_fork_error(void);
void			ft_right_error(const char *s);
void			ft_exist_error(const char *s);
void			ft_arg_error(const char *s);
void			ft_malloc_error(const char *s);
void			ft_lseek_error(void);
void			ft_command_error(void);
void			ft_unknown_error(const char *s);
void			ft_execve_error(const char *s);
void			ft_copy_environ(char **environ, char ***env);
int				ft_word_count(const char *s, char c);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putchar_fd(char c, int fd);
size_t			ft_strlen(const char *str);
int				ft_strichr(char *str, int l);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strncmp(const char *str, const char *str2, size_t n);
char			**ft_strsplit(char const *s, char c);
/*pouet*/
#endif
