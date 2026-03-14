/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:31:10 by adakhama          #+#    #+#             */
/*   Updated: 2026/03/14 18:28:01 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = len(s);
	if (s[i] == (unsigned char)c)
		return ((char *)(s + i));
	while (i--)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
	}
	return (0);
}
