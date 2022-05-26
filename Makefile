NAME = minisynth
SRC = minisynth.c waves.c
OBJS = $(SRC:.c=.o)
CFLAGS = -I/Users/acamaras/.brew/include/SDL2 -D_THREAD_SAFE
LIB = -L/Users/acamaras/.brew/lib -lSDL2

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(LIB) -o $@ $^

%.o: %.c
	gcc $(CFLAGS) $(LIB) -c $<

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all