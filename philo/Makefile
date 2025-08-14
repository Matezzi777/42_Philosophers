#################### COMPILING ####################
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
INCLUDES = -I/usr/include -I.

###################### FILES ######################
RAW_SRCS = clean.c \
			forks.c \
			ft_atol.c \
			ft_isdigit.c \
			ft_putstr_fd.c \
			main.c \
			parse_arguments.c \
			philos.c
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