/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouze <vtouze@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:33:11 by vtouze            #+#    #+#             */
/*   Updated: 2023/08/12 15:32:47 by vtouze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_btoa(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (1 << bit);
	else if (sig == SIGUSR2)
		i &= ~(1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(i, 1);
		bit = 0;
		i = 0;
	}
}

int main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		printf("\033[31m");
		ft_printf("Error\n");
		printf("\033[0m");
		return (1);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	while(1)
	{
		signal(SIGUSR1, &ft_btoa);
		signal(SIGUSR2, &ft_btoa);
		continue ;
	}
	return (0);
}