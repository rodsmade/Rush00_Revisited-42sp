#include <stdio.h>
#include <stdlib.h>

char	**create_matrix(int matrix_size)
{
	int 	line;
	int 	column;
	char	**matrix;

	line = 0;
	matrix = (char **) calloc(matrix_size + 1, sizeof(char *));
	while (line < matrix_size)
	{
		matrix[line] = (char *) calloc(matrix_size + 1, sizeof(char));
		matrix[line][matrix_size] = '\0';
		column = -1;
		while (++column < matrix_size)
			matrix[line][column] = 'a';
		line++;
	}
	matrix[line] = NULL;
	line = 0;
	while (line < matrix_size)
	{
		column = -1;
		while (++column < matrix_size)
			printf("%c ,", matrix[line][column]);
		printf("\n");
		line++;
	}
	return (matrix);
}

void	rush01(int matrix_size, char *argv[])
{
	char	**matrix;

	// validate_input(); // valida: se o range tá certo (não entra 0's e numeros > matrix_size); e se matrix size >=4 e <=9;
	matrix = create_matrix(matrix_size);
	return ;
}


int	ft_isdigit(char c)
{
	int index;

	index = 0;
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	argument_is_valid(char *argv)
{
	int	flag;
	int	spaces;
	int	count;
	int	i;

	flag = 0;
	count = 0;
	spaces = 0;
	i = -1;
	while (argv[++i])
	{
		if ((flag == 0 && !ft_isdigit(argv[i]))
			|| (flag == 1 && argv[i] != ' '))
			return (0);
		if (flag == 1 && argv[i] == ' ')
		{
			flag = 0;
			spaces++;
		}
		if (flag == 0 && ft_isdigit(argv[i]))
		{
			flag = 1;
			count++;
		}
	}
	if (spaces != count - 1)
		return (0);
	return (count);
}

int	get_matrix_size(int	count)
{
	int	i;

	i = 0;
	while(++i)
	{
		if (i*i == count)
			return (i);
		else if (i*i > count)
			return (0);
	}
}


int	main(int argc, char **argv)
{
	char	**matrix;
	int		matrix_len;
	int		digits;
	
	if (argc != 2)
	{
		printf("Invalid argument 1\n");
		return (0);
	}
	matrix_len = get_matrix_size(argument_is_valid(argv[1]));
	if (!matrix_len)
	{
		printf("Invalid argument 2\n");
		return (0);
	}
	rush01(matrix_len, argv);
	return (0);
}