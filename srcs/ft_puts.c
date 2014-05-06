/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 13:02:31 by gleger            #+#    #+#             */
/*   Updated: 2014/05/07 00:42:57 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(const char *s, int fd)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_strichr(char *str, int l)
{
	char	c;
	int		i;

	i = 0;
	c = (char)l;
	while (str[i] != c)
	{
		if (str[i] == '\0' && c != '\0')
			return (-1);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	int		i;
	int		j;
	char	*s3;

	i = 0;
	l = ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	s3 = (char*)malloc(sizeof(char) * l);
	if (!s3)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

int		ft_strncmp(const char *str, const char *str2, size_t n)
{
	unsigned int		i;

	i = 0;
	while (*str != '\0' && *str2 != '\0' && *str == *str2 && i < (n - 1))
	{
		str++;
		str2++;
		i++;
	}
	return (*str - *str2);
}

int		ft_count_length(const char *s, char c, int *i)
{
	int		j;

	j = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		*i += 1;
		j++;
	}
	return (j);
}

int		*ft_build_length_tab(const char *s, char c, int wdcnt)
{
	int		i;
	int		j;
	int		l;
	int		*tab;

	i = j = l = 0;
	if (!(tab = (int*)malloc(sizeof(int) * wdcnt)))
		return (NULL);
	while (s[j] != '\0' && i < wdcnt)
	{
		while (s[j] == c)
			j++;
		if (s[j] != c)
			l = ft_count_length(s, c, &j);
		tab[i] = l + 1;
		l = 0;
		j++;
		i++;
	}
	return (tab);
}

static char		**ft_build_tab_tab(const char *s, char c)
{
	int		wdcnt;
	int		*nb;
	char	**tab;

	if ((wdcnt = ft_word_count(s, c)) < 0)
		wdcnt = 0;
	nb = ft_build_length_tab(s, c, wdcnt);
	if (!(tab = (char**)malloc(sizeof(char*) * (wdcnt + 1))))
		return (NULL);
	while (wdcnt > -1)
	{
		if (nb[wdcnt] < 0)
			nb[wdcnt] = 0;
		if (!(tab[wdcnt] = (char*)malloc(sizeof(char) * nb[wdcnt] + 1)))
			return (NULL);
		wdcnt -= 1;
	}
	return (tab);
}

char			**ft_fill_word(char **tab, int *i, int *l, const char *s)
{
	int		j;

	j = 0;
	tab[*i][j] = s[*l];
	*l += 1;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		l;
	char	**tab;

	i = l = 0;
	if (!(tab = ft_build_tab_tab(s, c)))
		return (NULL);
	while (s[l] != '\0')
	{
		j = 0;
		while (s[l] == c)
			l++;
		if (s[l] != '\0')
		{
			while (s[l] != c && s[l] != '\0')
			{
				tab[i][j++] = s[l++];
			}
			tab[i][j] = '\0';
			i += 1;
		}
	}
	tab[i] = NULL;
	return (tab);
}

int		ft_word_count(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j++;
			i++;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				return (j);
		}
		i++;
	}
	return (j);
}
