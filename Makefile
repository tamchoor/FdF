NAME = fdf

CC = cc
FLAGS = -Wall -Werror -Wextra -O2
LIBRARIES = -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)

HEADER = fdf.h
HEADERS_DIRECTORY = .

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./minilibx_macos/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

SOURCES = read_fd.c main.c init_point.c init.c get_next_line.c get_next_line_utils.c ft_error.c ft_atoi_base.c draw.c key_control.c menu_back.c mouse_control.c utils.c

OBJECTS	=  $(SOURCES:%.c=%.o)

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m


all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_DIRECTORY)/*.c $(LIBFT_DIRECTORY)/*.h
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIRECTORY)

$(MINILIBX):
	@echo "$(NAME): $(GREEN)Creating $(MINILIBX)...$(RESET)"
	@$(MAKE) -C $(MINILIBX_DIRECTORY)

clean:
	@$(MAKE) -C $(LIBFT_DIRECTORY) clean
	@$(MAKE) -C $(MINILIBX_DIRECTORY) clean
	@rm -f $(OBJECTS)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(MINILIBX)
	@echo "$(NAME): $(RED)$(MINILIBX) was deleted$(RESET)"
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all