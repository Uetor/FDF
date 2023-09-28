/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:39:06 by pedrogon          #+#    #+#             */
/*   Updated: 2023/09/28 19:49:17 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
    //Matriz y variables.
	int		y_matrix;
	int		x_matrix;
	char	**matrix;

    //Direction
	char	*dir;
	char	*file;

    //Read
	int		fd;
	char	*line;
}t_data;

// Función para compbrobar el mapa.
int	count_word(const char *str, char c);


#endif