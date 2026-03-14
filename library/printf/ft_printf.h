/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:46:56 by adakhama          #+#    #+#             */
/*   Updated: 2026/03/14 18:28:01 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(int c, size_t *len);
int		ft_printf(const char *s, ...);
void	ft_putstr(char *s, size_t *len);
size_t	len(const char *str);
void	ft_putbase(char *base, size_t nbr, int verif, size_t *len);
void	ft_putnbr(long n, size_t *len);

#endif
