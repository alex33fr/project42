/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:14:09 by aprivalo          #+#    #+#             */
/*   Updated: 2026/03/13 10:26:48 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <sys/wait.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;
void	ft_child1(t_pipex *pipex, char *cmd, char **envp);
void	ft_child2(t_pipex *pipex, char *cmd, char **envp);
char	*ft_find_path(char *cmd, char **envp);
void	ft_free_pipex_tab(char **tab);
void	ft_close(int fd1, int fd2);
int		ft_wait_child(t_pipex *pipex);
#endif