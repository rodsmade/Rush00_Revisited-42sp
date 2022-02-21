#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_matrix(char **matrix)
{
	int	i;
	int	j;

	i = -1;
	while (matrix[++i])
	{
		j = -1;
		while (matrix[i][++j])
		{
			printf("%c", matrix[i][j]);
			if (matrix[i][j + 1])
				printf(" ");
		}
		printf("\n");
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		size;
	char		*substr;

	i = 0;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr || !s)
		return (NULL);
	size = ft_strlen(s);
	while (start < size && i < len)
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

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
			matrix[line][column] = '0';
		line++;
	}
	matrix[line] = NULL;
	line = 0;
	// while (line < matrix_size)
	// {
	// 	column = -1;
	// 	while (++column < matrix_size)
	// 		printf("%c ,", matrix[line][column]);
	// 	printf("\n");
	// 	line++;
	// }
	return (matrix);
}

int	validate_input(int matrix_size, char *argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (argv[i] == '0' || argv[i] > (matrix_size + '0'))
			return (0);
	}
	return (1);
}

char	get_max_pair(char view_from, char max_views)
{
	char	max_pair;

	max_pair = (((max_views - view_from) + 1) + '0');
	return (max_pair);
}

int	check_views(int matrix_size, char *view_from, char *view_to)
{
	int		i;
	char	max_views;

	i = -1;
	max_views = matrix_size + '0';
	printf("f %s\nt %s\n", view_from, view_to);
	while (view_from[++i])
	{
		if ((view_from[i] == max_views && view_to[i] == max_views) && (view_from[i] == '1' && view_to[i] == '1'))
		{	
			printf("Error 1\n");
			return (0);
		}
		if (view_from[i] == max_views && view_to[i] != '1' || view_to[i] == max_views && view_from[i] != '1')
		{
			printf("Error 2\n");
			return (0);
		}
		if (view_from[i] != '1' && (view_from[i] == view_to[i] && view_from[i] > ((matrix_size / 2) + '0')))
		{
			printf("Error 3\n");
			return (0);
		}
		if (view_to[i] > get_max_pair(view_from[i], max_views))
		{
			printf("Error 4\n");
			return (0);
		}
	}
	return (1);
}

char	*trim_chars(char *original, char to_trim)
{
	char	*str_trimmed;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = -1;
	if (!original)
		return (NULL);
	while (original[++i])
	{
		if (original[i] != to_trim)
			count++;
	}
	str_trimmed = (char *)malloc(sizeof(char) * (count + 1));
	if (!str_trimmed)
		return (NULL);
	str_trimmed[i] = '\0';
	i = -1;
	j = 0;
	while (original[++i])
	{
		if (original[i] != to_trim)
			str_trimmed[j++] = original[i];
	}
	return (str_trimmed);
}

void	put_max(char **matrix, char *col_up, char *col_down, char *row_left, char *row_right)
{
	int	i;

	i = -1;
	while (col_up[++i])
	{
		if (col_up[i] == )
	}
}

void	solve_it(char **matrix, char *col_up, char *col_down, char *row_left, char *row_right)
{
	//Solve part by part
	put_max(matrix, col_up, col_down, row_left, row_right);
	//put_min
	//put_n1
	//put_n2
	//put_nx
}

void	check_input_pairs(int matrix_size, char *argv, char **matrix)
/*
	CONCLUSÃO 1: a combinação [MAX_SIZE, N] só é OK se N = 1;
	CONCLUSÃO 2*: a combinação [N, N] onde N > 1 e N <= MAX_SIZE/2 é OK, caso contrário, NOK;
		*para números ímpares, [N+1, N+1] é ok !!!! 
	CONCLUSÃO 3: ATÉ: [i, MAX_SIZE - i + 1] => OK
	----
	fazer check_row e check_column, e só precisa testar 1x da esquerda pra direita e 1x de cima pra baixo
*/
{
	char	*col_up;
	char	*col_down;
	char	*row_left;
	char	*row_right;
	char	*all_views;

	all_views = trim_chars(argv, ' ');
	col_up = ft_substr(all_views, 0, matrix_size);
	col_down = ft_substr(all_views, matrix_size, matrix_size);
	row_left = ft_substr(all_views, 2*(matrix_size), matrix_size);
	row_right = ft_substr(all_views, 3*(matrix_size), matrix_size);
	/*Print views*/
	printf("col_up %s\n", col_up);
	printf("col_down %s\n", col_down);
	printf("row_left %s\n", row_left);
	printf("row_right %s\n", row_right);
	if (!check_views(matrix_size, col_up, col_down) || !check_views(matrix_size, row_left, row_right))
		write(1, "Something is wrong here\n", 24);
	else
		write(1, "Everything is okay\n", 19);
	solve_it(matrix, col_up, col_down, row_left, row_right);
}

void	rush01(int matrix_size, char *argv[])
{
	char	**matrix;

	if (matrix_size < 4 || matrix_size > 9)
	{
		write(1, "Size must be between 4x4 and 9x9\n", 33);
		return ;
	}
// validate_input(); // valida: se o range tá certo (não entra 0's e numeros > matrix_size); e se matrix size >=4 e <=9;
	if (!validate_input(matrix_size, argv[1]))
	{
		write(1, "Invalid input! 3\n", 17);
		return ;
	}
	matrix = create_matrix(matrix_size);
	if (!matrix)
		return;
	check_input_pairs(matrix_size, argv[1], matrix);
	print_matrix(matrix);
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