/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/22 23:18:52 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void projeta(int x, int y, int z,
					int * sx, int * sy,
					int pad,
					int offx, int offy)
{
	*sx = offx + x * pad;
	*sy = offy + y * pad - z;
}

/**
 * Desenha uma linha de (x0,y0) até (x1,y1) pixel a pixel usando
 * apenas operações inteiras (algoritmo de Bresenham).
 *
 * Parámetros:
 *   conn  - ponteiro de conexão MLX
 *   win   - ponteiro da janela MLX
 *   x0,y0 - coordenadas do ponto inicial
 *   x1,y1 - coordenadas do ponto final
 *   color - cor do pixel (0xRRGGBB)
 */
void bresenham(void * conn, void * win,
			   int x0, int y0,
			   int x1, int y1,
			   int color)
{
	// ---------------------------------------------------
	// 1) Cálculo das distâncias e das direções de avanço
	// ---------------------------------------------------
	// dx = quanto precisamos andar em X (sempre positivo)
	int dx = abs(x1 - x0);
	// sx = direção de avanço em X: +1 se x1 > x0, -1 caso contrário
	int sx = (x0 < x1) ? 1 : -1;

	// dy = quanto precisamos andar em Y (sempre negativo para facilitar o erro)
	// usamos o negativo para que err = dx + dy seja igual a dx - |dy|
	int dy = -abs(y1 - y0);
	// sy = direção de avanço em Y: +1 se y1 > y0, -1 caso contrário
	int sy = (y0 < y1) ? 1 : -1;

	// ---------------------------------------------------
	// 2) Inicialização do erro acumulado
	// ---------------------------------------------------
	// err armazena a diferença entre a posição real da reta
	// e o pixel atual. Começa como dx - |dy|:
	int err = dx + dy; // equivalente a dx - abs(dy)

	// variável auxiliar que vai receber 2*err a cada iteração
	int e2;

	// ---------------------------------------------------
	// 3) Loop principal: desenha um pixel a cada passo
	// ---------------------------------------------------
	while (1)
	{
		// 3.1) Pinta o pixel atual
		mlx_pixel_put(conn, win, x0, y0, color);

		// 3.2) Se já chegamos no destino (x0==x1 e y0==y1), paramos
		if (x0 == x1 && y0 == y1)
			break;

		// 3.3) Dobramos o erro para decidir qual eixo avançar
		//     e2 = 2 * err
		e2 = err * 2;

		// 3.4) Teste para avanço em X:
		//     Se e2 >= dy, significa que err >= |dy|:
		//     ainda “resta” erro suficiente para dar um passo em X
		if (e2 >= dy)
		{
			// 3.4.1) Atualiza err removendo |dy|
			err += dy; // como dy é negativo, isto subtrai abs(dy)
			// 3.4.2) Move um pixel em X na direção sx
			x0 += sx;
		}

		// 3.5) Teste para avanço em Y:
		//     Se e2 <= dx, significa que err <= dx:
		//     ainda não ultrapassamos o limite que exige passo em Y
		if (e2 <= dx)
		{
			// 3.5.1) Atualiza err somando dx
			err += dx;
			// 3.5.2) Move um pixel em Y na direção sy
			y0 += sy;
		}
	}
}

void render(t_mlx * mlx)
{
	int pad = 20;
	int offx = mlx->window->vw / 3;
	int offy = mlx->window->vh / 3;
	int x, y;
	int sx0, sy0, sx1, sy1;
	int z0, z1;
	int color;

	y = 0;
	while (y < mlx->map->size_y)
	{
		x = 0;
		while (x < mlx->map->size_x)
		{
			z0 = mlx->map->coordinates[y][x];
			color = (z0 == 0 ? 0x00FF00 : 0x0000FF);

			// projeta o ponto atual
			projeta(x, y, z0, &sx0, &sy0, pad, offx, offy);

			// vizinho à direita
			if (x + 1 < mlx->map->size_x)
			{
				z1 = mlx->map->coordinates[y][x + 1];
				projeta(x + 1, y, z1, &sx1, &sy1, pad, offx, offy);
				bresenham(mlx->connection,
						  mlx->window->content,
						  sx0, sy0, sx1, sy1, 0xFF0000);
			}
			// vizinho abaixo
			if (y + 1 < mlx->map->size_y)
			{
				z1 = mlx->map->coordinates[y + 1][x];
				projeta(x, y + 1, z1, &sx1, &sy1, pad, offx, offy);
				bresenham(mlx->connection,
						  mlx->window->content,
						  sx0, sy0, sx1, sy1, 0xFF0000);
			}
			x++;
		}
		y++;
	}
	mlx_loop(mlx->connection);
}
