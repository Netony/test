/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:02:46 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/29 10:43:31 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "../libft.h"

void	ft_exit(void);

int	main(int argc, char **argv, char **envp)
{
	
}

void	ft_exit(void)
{
	perror("pipex");
	exit(1);
}

int		ft_check_path(char *cmd, char *path)
{
	path = ft_split
}
