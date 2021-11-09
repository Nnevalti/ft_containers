NAME	=	ft_containers_tests

CC		=	clang++

CFLAGS	= -std=c++98 -Wall -Werror -Wextra

SRCS	=	main.cpp \
				test_vector.cpp \
				test_stack.cpp \
				test_map.cpp \
				test_set.cpp

OBJS	=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):
			$(CC) $(CFLAGS) -c $(SRCS)
			$(CC) $(OBJS) -o $(NAME)


clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:		fclean all
