/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:57:00 by adakhama          #+#    #+#             */
/*   Updated: 2026/03/14 18:28:01 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbase(char *base, size_t nbr, int verif, size_t *len)
{
	size_t	baselen;

	baselen = len(base);
	if (verif == 0)
	{
		if (nbr == 0)
		{
			ft_putstr("(nil)", len);
			return ;
		}
		ft_putstr("0x", len);
		verif ++;
	}
	if (nbr >= baselen)
		ft_putbase(base, nbr / baselen, verif, len);
	ft_putchar(base[nbr % baselen], len);
}
