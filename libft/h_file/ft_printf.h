/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:41:28 by mvolpi            #+#    #+#             */
/*   Updated: 2022/09/27 10:41:43 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void	ft_format(const char *str, va_list args, int *j, int i);
void	ft_str(const char *str, va_list args, int *j);
void	ft_hex(const char *str, va_list args, int *j);
void	ft_hex_x(unsigned int x, int i, int *j);
void	ft_hex_p(unsigned long x, int *j);
void	ft_num(const char *str, va_list args, int *j);
void	ft_putnbr(int nb, int *j);
void	ft_putnbr_u(unsigned int n, int *j);

#endif
