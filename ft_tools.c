/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 13:02:31 by gleger            #+#    #+#             */
/*   Updated: 2014/05/07 01:33:32 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

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

	i = 0;
	j = 0;
	l = 0;
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

char	**ft_build_tab_tab(const char *s, char c)
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

char	**ft_fill_word(char **tab, int *i, int *l, const char *s)
{
	int		j;

	j = 0;
	tab[*i][j] = s[*l];
	*l += 1;
	return (tab);
}

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		l;
	char	**tab;

	i = 0;
	l = 0;
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
				tab[i][j++] = s[l++];
			tab[i][j] = '\0';
			i += 1;
		}
	}
	tab[i] = NULL;
	return (tab);
}
