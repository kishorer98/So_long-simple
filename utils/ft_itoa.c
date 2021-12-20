/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:30:27 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/13 00:58:56 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static int	ft_to_positive(int nb, char *rslt, int *count)
{
	rslt[0] = '-';
	*count += 1;
	if (nb == -2147483648)
	{
		rslt[1] = '2';
		*count += 1;
		nb = -147483648;
	}
	return (nb - nb - nb);
}

static int	ft_quantitynum(int nb)
{
	int		count;
	int		pos;

	pos = 0;
	count = 0;
	if (nb < 0)
	{
		pos = nb - nb - nb;
		nb = pos;
		count++;
	}
	if (nb == -2147483648)
		return (11);
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count + 1);
}

char	*ft_itoa(int n)
{
	char	*rslt;
	int		count;
	int		firstpos;

	firstpos = 0;
	count = ft_quantitynum(n);
	rslt = malloc(count + 1);
	if (rslt == NULL)
		return (NULL);
	rslt[count] = 0;
	count--;
	if (n < 0)
		n = ft_to_positive(n, rslt, &firstpos);
	while (count >= firstpos)
	{
		rslt[count] = (n % 10) + '0';
		n /= 10;
		count--;
	}
	return (rslt);
}
