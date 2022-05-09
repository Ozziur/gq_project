/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:03:38 by mruizzo           #+#    #+#             */
/*   Updated: 2022/05/09 18:53:57 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <time.h>
#include <stdlib.h>

typedef struct s_sec
{
	void *img;
	int state;
} t_sec;

typedef struct s_circle
{
	void *mlx;
	void *template;
	void *window;
	int x;
	int y;
	t_sec *section[40];
	
}	t_circle;

int	end_program(t_circle *circle)
{
	exit(0);
}

void create_state(t_circle *circle)
{
	int i = 0;
	while (i != 40)
	{
		circle->section[i]->state = rand()% 2;
		i++;
	}
}

int	input(int key, t_circle *circle)
{
	if (key == 49)
	create_state(circle);
}

int	main()
{
	t_circle circle;
	circle.mlx = mlx_init();
	
	
	circle.x = 1000;
	circle.y = 1000;
	circle.window = mlx_new_window(circle.mlx, circle.x, circle.y, "gq_project");
	//open_images(circle);
	//create_state(&circle);
	mlx_hook(circle.window, 17, 0, end_program, &circle);
//	mlx_hook(circle.window, 2, 0, input, &circle);
	//mlx_loop_hook(circle.mlx, update, (void *)&circle);
	mlx_loop(circle.mlx);
}