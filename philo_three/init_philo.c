/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-pra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:22:36 by avan-pra          #+#    #+#             */
/*   Updated: 2020/05/27 14:21:01 by raimbaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		ft_atoi(const char *str)
{
	int				i;
	int				ret;
	unsigned long	result;

	i = 0;
	ret = 1;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ret = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)result * ret);
}

char	*ft_itoa_next(unsigned long long dec,
	unsigned long long nb, int size)
{
	int		test;
	char	*res;

	test = 0;
	res = malloc(size * sizeof(char));
	while (test < size)
	{
		if (nb >= 10)
		{
			dec = dec / 10;
			res[test] = nb / dec + '0';
			nb -= nb / dec * dec;
		}
		else
			res[test] = nb % 10 + '0';
		test++;
	}
	res[test] = '\0';
	return (res);
}

char	*ft_itoa(unsigned long long nb)
{
	unsigned long long	test;
	unsigned int		size;
	unsigned long long	dec;

	dec = 1;
	size = 1;
	test = nb;
	while (test / 10 != 0)
	{
		size++;
		test = test / 10;
	}
	test = 0;
	while (test++ < size)
		dec *= 10;
	return (ft_itoa_next(dec, nb, size));
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}