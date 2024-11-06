
SRCS	=	main.c init.c math_utils.c render.c string_utils.c events.c ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putstr.c ft_putunbr.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	fractol

MLX		=	libmlx.a

all		:	$(NAME)

%.o		:	%.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME)	:	$(MLX) $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(MLX)	:
	make -C mlx

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)
	make -C mlx clean

re		:	fclean all

.PHONY	:	clean fclean re all