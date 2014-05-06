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
