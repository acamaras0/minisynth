/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:46:27 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/09 17:25:03 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_atolli(const char	*str)
{
	int				i;
	int				sign;
	long long int	value;

	i = 0;
	sign = 1;
	value = 0;
	if (str)
	{
		while (str[i] == '\r' || str[i] == '\n' || str[i] == '\t' || \
				str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign = sign * -1;
			++i;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			value = (value * 10) + (str[i] - 48);
			++i;
		}
	}
	return (value * sign);
}
