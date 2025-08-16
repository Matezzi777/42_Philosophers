#################### COMPILING ####################
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
INCLUDES = -I/usr/include -I./includes

###################### FILES ######################
RAW_SRCS = main.c \
			check_parameters.c \
			parsing.c \
			utils.c
SRCS = $(addprefix srcs/, $(RAW_SRCS))
OBJS = $(SRCS:.c=.o)

###################### RULES ######################
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all fclean clean re