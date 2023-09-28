/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:47:08 by pedrogon          #+#    #+#             */
/*   Updated: 2023/09/28 19:54:49 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_word(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && count == 0 && *str != '\n')
		{
			count = 1;
			i++;
		}
		else if (*str == c)
			count = 0;
		str++;
	}
	return (i);
}

void	ft_coma(char *str)
{
	char	**coma;
	int		i;
	int		j;

	coma = ft_split(str, ' ');//He separado la linea en palabras y me queda buscar si tiene alguna coma y si la tiene dividir esa palabra en dos y dicer que lo que hay detrás de la coma es un color.
	i = 0;
	j = 0;
	while (coma != NULL)
	{
		if (coma[i][j] == ',')
		while (coma != NULL)
		{
			printf("%s ", coma[i][j]);
		}
		i++;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		len;
	int		check;

	if (argc > 1)
	{
		data.dir = ft_strdup("./test_maps/");
		data.file = ft_strjoin(data.dir, argv[1]);
		data.fd = open(data.file, O_RDONLY);
		data.line = get_next_line(data.fd);
		check = count_word(data.line, ' ');
		while (data.line != NULL)
		{
			//data.coma = ft_split(data.line, ',');//Tengo que hacer una función para ver cada linea.
			ft_coma(data.line);
			len = count_word(data.line, ' ');
			//printf("%d\n", len);
			data.line = get_next_line(data.fd);
			if (len != check)
				return (1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
