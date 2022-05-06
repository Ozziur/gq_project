/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:03:38 by mruizzo           #+#    #+#             */
/*   Updated: 2022/05/06 17:31:10 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "stdlib.h"

typedef struct s_circle
{
    
}	t_circle;

int	end_program(t_circle *circle)
{
	exit(0);
}

int	main(int argc, char **argv)
{
    void *mlx = mlx_init();
    int x = 500;
    int y = 500;
    t_circle circle;
    void *window = mlx_new_window(mlx, x, y, "gq_project");

	//open_images(circle);
	mlx_hook(window, 17, 0, end_program, &circle);
    mlx_loop(mlx);
}