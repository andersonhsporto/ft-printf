NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I$(INCLUDE)

SRC = ./src/

INCLUDE = ./include

MAIN = $(SRC)printf.c $(SRC)print_csdui.c $(SRC)print_void.c $(SRC)print_hexadecimal.c

OBJ := $(MAIN:%.c=%.o)

$(NAME): $(OBJ)
	make all -C ./libft
	cp ./libft/libft.a libftprintf.a
	ar -rcs $(NAME) $(OBJ)

all:	$(NAME)

libft:
	make all -C ./libft

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
	$(CC) $(CFLAGS) main.c $(SRC) ./libft/libft.a
	./a.out

valgrind:
	$(CC) $(CFLAGS) -g main.c $(SRC) ./libft/libft.a
	valgrind --track-origins=yes  ./a.out

sanitize:
	$(CC) $(CFLAGS) -g -fsanitize=address main.c $(SRC) ./libft/libft.a
	./a.out
