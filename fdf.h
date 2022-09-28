/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:51:52 by tamchoor          #+#    #+#             */
/*   Updated: 2022/02/03 11:49:20 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <math.h>

# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

# define RED		0x8b0000
# define HOTPINK	0xff6eb4
# define BLUE		0xcae1ff
# define PURPLE		0x551a8b

# define HEIGHT			540
# define WIDTH			960
# define BUTTONPRESS		4
# define BUTTONRELEASE		5
# define BUTTONMOVE			6
# define ON_DESTROY			17

typedef struct s_crdnts
{
	int		count_x;
	int		count_y;
	char	**one_line;
	char	**one_var;
	int		**z_stack;
	int		**clr_stack;
	int		medium_x;
	int		medium_y;
	int		y;
}	t_crdnts;

typedef struct s_key
{
	float		shift_x;
	float		shift_y;
	float		angl_x;
	float		angl_y;
	float		change_z;
	float		press_x;
	float		press_y;
	float		button;
	float		back;
}	t_key;

typedef struct s_fdf
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*addr;
	int					bits_p_pix;
	int					line_length;
	int					endian;
	int					zoom;
	int					clear;
	t_key				key;
	t_crdnts			*crdnts;
}						t_fdf;

typedef struct s_p
{
	float		x;
	float		y;
	float		z;
	int			clr;
}	t_p;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

struct s_gnl
{
	char	buf_line[BUFFER_SIZE + 1];
	int		count;
	int		i;
} ;

char	*get_next_line(int fd);
size_t	ft_strlen1(char *str);
char	*ft_strchr1(char *s, int c);
char	*ft_strjoin1(char *s1, char *s2);

void	ft_error_print(char *str, t_crdnts *crdnts);
void	init_crdnts(t_crdnts **crdnts);
void	read_fd(char *argv, t_crdnts **crdnts);
int		ft_atoi_base(char *str, int base);
void	init_fdf(t_fdf **fdf, t_crdnts **crdnts);
t_p		ft_init_point(int x, int y, t_fdf ***fdf);
void	draw(t_fdf **fdf);
int		key_control(int key, t_fdf *fdf);
int		deal_mouse_press(int button, int x, int y, t_fdf *fdf);
int		deal_mouse_release(int button, int x, int y, t_fdf *fdf);
int		deal_mouse_move(int x, int y, t_fdf *fdf);
int		ft_tab(int c);
long	ft_minus(int c, unsigned int *ptr_i);
void	ft_free_split(char ***str);
void	ft_print_background(t_fdf ***fdf);
void	ft_print_menu(t_fdf ***fdf);
void	my_pixel_put(int x, int y, int clr, t_fdf ****fdf);
void	calloc_two_stack(t_crdnts *****crdnts, int y);
void	count_symb1(t_crdnts *****crdnts);
#endif