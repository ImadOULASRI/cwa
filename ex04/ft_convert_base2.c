/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoulasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:16:50 by imoulasr          #+#    #+#             */
/*   Updated: 2023/08/29 10:32:34 by imoulasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *s)
{
	int	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

int	is_base_valid(char *s)
{
	int	length;
	int	i;
	int	j;

	length = ft_strlen(s);
	if (length < 2)
		return (0);
	i = 0;
	while (i < length)
	{
		if (s[i] == '+' || s[i] == '-')
			return (0);
		j = i + 1;
		while (j < length)
		{
			if (s[i] == s[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	find_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str, int length, char *base)
{
	int		sign;
	long	number;

	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	number = 0;
	while (find_index(*str, base) >= 0)
	{
		number *= length;
		number += find_index(*str, base);
		str++;
	}
	return (number * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	length;

	length = ft_strlen(base);
	if (is_base_valid(base))
		return (ft_atoi(str, length, base));
	return (0);
}
