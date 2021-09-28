#include "../inc/pipex.h"

void execute(char *cmd, char *envp[])
{
	char *main_path;
	char **possible_path;
	char **commands;
	char *file;
	while (!(main_path = ft_strstr("PATH", *envp)))
		envp++;
	possible_path = ft_split(main_path + 5, ':');
	commands = ft_split(cmd, ' ');
	while (!access((file = ft_strjoin(*possible_path++, *commands)), X_OK))
	{
		execve(file, commands, envp);
		free(file);
	}
	free(possible_path);
	free(commands);
	// error
}

void	pipex(int fdin, int fdout, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid1;

	if (pipe(fd) < 0)
		exit(1);
	pid1 = fork();
	// in a func
	if (pid1 == 0)
	{	// in a func
		dup2(fd[1], STDOUT_FILENO);
		dup2(fdin, STDIN_FILENO);
		close(fd[0]);
		close(fdin);
		execute(argv[2], envp);
		waitpid(pid1, NULL, 0);
	}
	else if (pid1 > 0)
	{
		// put this in a func
		dup2(fd[0], STDIN_FILENO);
		dup2(fdout, STDOUT_FILENO);
		close(fdout);
		close(fd[1]);
		execute(argv[3], envp);
	}
	else if (pid1 == -1)
		return (perror("Fork:"));
	
}

int main(int argc, char *argv[], char *envp[])
{
	int f1;
    int f2;
	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
    f1 = open(argv[1], O_RDONLY);
    f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
    pipex(f1, f2, argv, envp);
    return (0);
}