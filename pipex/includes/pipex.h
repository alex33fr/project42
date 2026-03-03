/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:14:09 by aprivalo          #+#    #+#             */
/*   Updated: 2026/03/02 11:12:24 by aprivalo         ###   ########.fr       */
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
	char	**cmd1_args;
	char	**cmd2_args;
	char	*cmd1_path;
	char	*cmd2_path;
	char	**envp;
}	t_pipex;
int		main(int ac, char **av, char **envp);
void	init_pipex(t_pipex *px, char **envp);
int		open_files(t_pipex *px, char *infile, char *outfile);
void	child1(t_pipex *px, char *cmd);
void	child2(t_pipex *px, char *cmd);
char	*find_path(char *cmd, char **envp);
char	*get_path_line(char **envp);
char	*build_full_path(char *dir, char *cmd);
char	**parse_cmd(char *cmd);
void	free_tab(char **tab);
void	free_pipex(t_pipex *px);
void	error_exit(char *msg);
#endif
