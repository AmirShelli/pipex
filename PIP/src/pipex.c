#include "../inc/pipex.h"

char	**get_path(char *envp[])
{
	char	*main_path;

	main_path = ft_strstr(*envp, "PATH");
	while (!main_path)
		main_path = ft_strstr(*envp++, "PATH");
	return (ft_split(main_path + 5, ':'));
}

void	execute(char *cmd, char *envp[])
{
	char	**commands;
	char	*paths;
	char	*file;
	int		i;

	i = 0;
	commands = ft_split(cmd, ' ');
	paths = get_path(envp);
	while (paths[i])
	{
		file = ft_strjoin(paths[i++], "/");
		cmd = ft_strjoin(file, *commands);
		free(file);
		if (!access(cmd, X_OK))
			execve(cmd, commands, envp);
		free(cmd);
	}
	ft_putstr_fd("command not found: ", STDERR_FILENO);
	ft_putstr_fd(commands[0], STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	pipex(int fdin, int fdout, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid1;

	if (pipe(fd) < 0)
		exit(1);
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		dup2(fdin, STDIN_FILENO);
		close(fd[0]);
		close(fdin);
		execute(argv[2], envp);
	}
	else if (pid1 > 0)
	{
		waitpid(pid1, NULL, 0);
		dup2(fd[0], STDIN_FILENO);
		dup2(fdout, STDOUT_FILENO);
		close(fd[1]);
		close(fdout);
		execute(argv[3], envp);
	}
	else if (pid1 == -1)
		return (perror("Fork:"));
}

int	main(int argc, char *argv[], char *envp[])
{
	int	f1;
	int	f2;

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
	close(f1);
	close(f2);
	return (0);
}
