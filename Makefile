NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

FOLDER = ./src/

SRC = $(FOLDER)printf.c $(FOLDER)utils.c

OBJ := $(SRC:%.c=%.o)

all:	$(NAME)

$(NAME): $(OBJ) $(libft)
	make all -C ./libft
	cp ./libft/libft.a libftprintf.a
	ar -rcs $(NAME) $(OBJ)

libft:
	make all -C ./libft

clean:
	rm -rf $(OBJ)
	rm -rf ./a.out


fclean:	clean
	rm -rf $(NAME)
	make fclean -C ./libft

re:	fclean all

push:
	git add .
	git commit -m "update"
	git push

clang:
	$(CC) $(CFLAGS) main.c libftprintf.a
	./a.out

valgrind:
	$(CC) $(CFLAGS) -g main.c libftprintf.a
	valgrind --track-origins=yes  ./a.out

sanitize:
	$(CC) $(CFLAGS) -g -fsanitize=address main.c libftprintf.a
	./a.out
