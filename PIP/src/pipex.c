#include "../inc/pipex.h"

void free_arr(char **words)
{
	int	i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
}

void execute(char *cmd, char *envp[])
{
	char *main_path;
	char **possible_path;
	char **commands;
	char *file;
	int i;

	i = 0;
	while (!(main_path = ft_strstr(*envp, "PATH")))
		envp++;
	possible_path = ft_split(main_path + 5, ':');
	commands = ft_split(cmd, ' ');
	while (possible_path[i])
	{
		file = ft_strjoin(possible_path[i++], "/");
		char	*temp;
		temp = file;
		file = ft_strjoin(file, *commands);
		free(temp);
		if (!access(file, X_OK))
			execve(file, commands, envp);
		free(file);
	}

	//free_arr(possible_path);
	ft_putstr_fd("command not found: ", STDERR_FILENO);
	ft_putstr_fd(commands[0], STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	//free_arr(commands);
	exit(EXIT_FAILURE);
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
		
	}
	else if (pid1 > 0)
	{
		// put this in a func
		dup2(fd[0], STDIN_FILENO);
		dup2(fdout, STDOUT_FILENO);
		close(fd[1]);
		close(fdout);
		execute(argv[3], envp);
	}
	else if (pid1 == -1)
		return (perror("Fork:"));
	waitpid(pid1, NULL, 0);
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
	close(f1);
	close(f2);
    return (0);
}