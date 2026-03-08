/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:14:09 by aprivalo          #+#    #+#             */
/*   Updated: 2026/03/08 01:08:53 by aprivalo         ###   ########.fr       */
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
int		main(int ac, char **av, char **envp);
void	ft_child1(t_pipex *pipex, char *cmd, char **envp);
void	ft_child2(t_pipex *pipex, char *cmd, char **envp);
char	*ft_find_path(char *cmd, char **envp);
void	ft_free_pipex_tab(char **tab);
char	**ft_get_path_splitted(char **envp);
void	ft_close_fd(int fd1, int fd2);
void	ft_close_files(int file1, int file2);
int		ft_wait_child(t_pipex *pipex);
#endif
