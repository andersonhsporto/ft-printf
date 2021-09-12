NAME = libftprintf.a

CC = gcc

INCLUDE = -I ./includes

CFLAGS = -Wall -Werror -Wextra $(INCLUDE)

SRC = ./src/

MAIN =	$(SRC)ft_printf.c $(SRC)print_csdui.c $(SRC)print_void.c \
		$(SRC)print_hexadecimal.c

OBJ := $(MAIN:%.c=%.o)

$(NAME): $(OBJ)
	make all -C ./libft
	cp ./libft/libft.a libftprintf.a
	ar -rcs $(NAME) $(OBJ)

all:	$(NAME)

libft:
	make -C ./libft

clean:
	rm -rf $(OBJ)
	rm -rf ./a.out
	make clean -C ./libft


fclean:	clean
	rm -rf $(NAME)
	make fclean -C ./libft

re:	fclean all

push:
	make fclean
	git add .
	git commit -m "update"
	git push

clang:
	$(CC) $(CFLAGS) main.c $(MAIN) ./libft/libft.a
	./a.out

valgrind:
	$(CC) $(CFLAGS) -g main.c $(MAIN) ./libft/libft.a
	valgrind --track-origins=yes  ./a.out

sanitize:
	$(CC) $(CFLAGS) -g -fsanitize=address main.c $(MAIN) ./libft/libft.a
	./a.out
