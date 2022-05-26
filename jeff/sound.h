/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:22:35 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/26 11:29:48 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOUND_H
#define SOUND_H

#include "libft/ft_printf.h"
#include <fcntl.h>

# define A 27.50
# define B 30.87
# define C 16.35
# define D 18.35
# define E 20.60
# define F 21.83
# define G 24.50
# define R 0

typedef struct s_instru
{
	int tempo;
	double pitch;
	int flat_sharp;
	int	octa;
	float duration;
	struct s_instru *next;
}				t_instru;


#endif
