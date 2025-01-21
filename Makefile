NAME 	= push_swap
#BNAME 	= checker
CC 		= cc
FLAGS 	= -Wall -Wextra -Werror #-fsanitize=address -g3
RM 		= rm -f
SRCS 	=	push_swap.c \
			sources/utils_stack/stack_utils_01.c \
			sources/utils_stack/stack_utils_02.c \
			sources/utils_stack/stack_utils_03.c \
			sources/utils_stack/stack_utils_04.c \
			sources/operations/operations_01.c \
			sources/error/error.c \
			Libft/ft_bzero.c \
			Libft/ft_calloc.c \
			Libft/ft_isalnum.c \
			Libft/ft_isalpha.c \
			Libft/ft_isascii.c \
			Libft/ft_isdigit.c \
			Libft/ft_isprint.c \
			Libft/ft_itoa.c \
			Libft/ft_memchr.c \
			Libft/ft_memcmp.c \
			Libft/ft_memcpy.c \
			Libft/ft_memmove.c \
			Libft/ft_memset.c \
			Libft/ft_putchar_fd.c \
			Libft/ft_putendl_fd.c \
			Libft/ft_putnbr_fd.c \
			Libft/ft_putstr_fd.c \
			Libft/ft_split.c \
			Libft/ft_strchr.c \
			Libft/ft_strdup.c \
			Libft/ft_striteri.c \
			Libft/ft_strjoin.c \
			Libft/ft_strlcat.c \
			Libft/ft_strlcpy.c \
			Libft/ft_strlen.c \
			Libft/ft_strmapi.c \
			Libft/ft_strncmp.c \
			Libft/ft_strnstr.c \
			Libft/ft_strrchr.c \
			Libft/ft_strtrim.c \
			Libft/ft_substr.c \
			Libft/ft_tolower.c \
			Libft/ft_toupper.c \
			Printf/ft_printf.c \
			Printf/ft_putchar.c \
			Printf/ft_putstr.c \
			Printf/ft_putnbr.c \
			Printf/ft_unsinbr.c \
			Printf/ft_putnbr_base.c \
			Printf/ft_putvoid.c 



OBJS 	= $(SRCS:.c=.o)
#BOBJS 	= $(BSRCS:.c=.o)


.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

#bonus: $(BNAME)

#$(BNAME): $(BOBJS)
#	@$(CC) $(FLAGS) -o $(BNAME) $(BOBJS)

clean:
	@$(RM) $(OBJS) 
#$(BOBJS)

fclean: clean
	@$(RM) $(NAME)
#$(BNAME)

re: fclean all