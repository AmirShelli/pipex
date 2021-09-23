#include "pipex.h"

void	pipex()
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) < 0)
		exit(1);
	pid1 = fork();
	if (pid1 == 0)
	{	// in a func
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
	else if(pid1 == -1)
		return (perror("Fork 1"));
	pid2 = fork();
	if (pid2 == 0)
	{	// in a func
		dup2(fd[1], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
	else if(pid2 == -1)
		return (perror("Fork 2"));
	// put this in a func
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}