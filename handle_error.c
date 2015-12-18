/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 16:19:11 by jcamhi            #+#    #+#             */
/*   Updated: 2015/12/18 16:31:53 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	handle_error(int *x, t_env *e, char *str)
{
	int		prevx;
	char	**split;

	split = ft_strsplit(str, ' ');
	prevx = *x;
	*x = 0;
	while (split[*x] != NULL)
		(*x)++;
	if (*x != prevx && prevx != -1)
	{
		ft_putstr_fd("Error : Invalid file.\n", 2);
		exit(EXIT_FAILURE);
	}
}
