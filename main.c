/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:47:08 by pedrogon          #+#    #+#             */
/*   Updated: 2023/10/10 03:31:48 by pedro            ###   ########.fr       */
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

/*Esta función me realiza un dos split para dividir la linea palabra por palabra y con el segundo 
dividimos las palabras que traen una coma para diferenciar la altura de la parte que es un color*/

void	ft_coma(t_data *data)
{
	char	**coma;
	char	**doble;// Los nombres de las variables hay que cambiarlos.
	int		j;
	int		i;

	
	coma = ft_split(data->line, ' ');//Me falta que después de haberlo dividido todo indicar cual es el color
	i = 0;
	while (coma[i])
	{
		doble = ft_split(coma[i], ',');//Antes de meter doble en points tengo que transformarlos en enteros, ya que esto es un string.
		j = 0;
		while (doble[j])
		{
			printf("%s ", doble[j]);
			j++;
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
	int		high;

	if (argc == 2)
	{
		data.dir = ft_strdup("./test_maps/");
		data.file = ft_strjoin(data.dir, argv[1]);
		data.fd = open(data.file, O_RDONLY);
		data.line = get_next_line(data.fd);// Esto lo volvemos a repetir, importante para hacer una función
		check = count_word(data.line, ' ');
		high = 0;
		while (data.line != NULL) // El primer get_next_line lo seguimos con esta función
		{
			len = count_word(data.line, ' ');
			data.line = get_next_line(data.fd);
			high++;
			if (len != check)
				return (1);
		}
		close(data.fd);
		data.x_matrix = len;
		data.y_matrix = high;
		data.matrix = malloc(sizeof(t_point *) * data.y_matrix);
		int	altura = 0;
		while (altura < data.y_matrix)
		{	
			data.matrix[altura] = malloc(sizeof(t_point) * data.x_matrix); 
			altura++;
		}
		data.fd = open(data.file, O_RDONLY);
		data.line = get_next_line(data.fd);
		int contador = 0;
		while (data.line != NULL)
		{
			ft_coma(&data);
			data.line = get_next_line(data.fd);
			contador++;
		}

	}
	printf("La x vale %d y la y %d\n", data.x_matrix, data.y_matrix);
	write(1, "\n", 1);
	return (0);
}
