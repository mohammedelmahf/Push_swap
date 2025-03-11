NAME    = push_swap
BNAME   = checker
CC      = cc
FLAGS   = -Wall -Wextra -Werror  #-fsanitize=address -g3
RM      = rm -f

SRCS    = push_swap.c \
          sources/utils_stack/stack_utils_01.c \
          sources/utils_stack/stack_utils_02.c \
          sources/utils_stack/stack_utils_03.c \
          sources/utils_stack/stack_utils_04.c \
          sources/operations/operations_01.c \
          sources/operations/operations_02.c \
          sources/operations/operations_03.c \
          sources/sorting_algo/sorting_algo_01.c \
          sources/sorting_algo/sorting_algo_02.c \
          sources/sorting_algo/sorting_algo_03.c \
          sources/error/error.c \
          Printf/ft_printf.c \
          Printf/ft_putchar.c \
          Printf/ft_putstr.c \
          Printf/ft_putnbr.c \
          Printf/ft_unsinbr.c \
          Printf/ft_putnbr_base.c \
          Printf/ft_putvoid.c \
          Libft/ft_putstr_fd.c \
          Libft/ft_split.c \
          Libft/ft_strncmp.c \
          Libft/ft_isdigit.c \
          Libft/ft_strlen.c

BSRCS   = sources/bonus/checker_bonus.c \
          sources/bonus/operations_01_bonus.c \
          sources/bonus/operations_02_bonus.c \
          sources/bonus/operations_03_bonus.c \
          sources/utils_stack/stack_utils_01.c \
          sources/utils_stack/stack_utils_02.c \
          sources/utils_stack/stack_utils_03.c \
          sources/utils_stack/stack_utils_04.c \
          sources/operations/operations_01.c \
          sources/operations/operations_02.c \
          sources/operations/operations_03.c \
          sources/sorting_algo/sorting_algo_01.c \
          sources/sorting_algo/sorting_algo_02.c \
          sources/sorting_algo/sorting_algo_03.c \
          sources/error/error.c \
		  Get-Next-Line/get_next_line_utils.c\
		  Get-Next-Line/get_next_line.c\
          Printf/ft_printf.c \
          Printf/ft_putchar.c \
          Printf/ft_putstr.c \
          Printf/ft_putnbr.c \
          Printf/ft_unsinbr.c \
          Printf/ft_putnbr_base.c \
          Printf/ft_putvoid.c \
          Libft/ft_putstr_fd.c \
          Libft/ft_split.c \
          Libft/ft_strncmp.c \
          Libft/ft_isdigit.c \
          Libft/ft_strlen.c
          
OBJS    = $(SRCS:.c=.o)
BOBJS   = $(BSRCS:.c=.o)

.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

bonus: $(BNAME)

$(BNAME): $(BOBJS)
	@$(CC) $(FLAGS) -o $(BNAME) $(BOBJS)

clean:
	@$(RM) $(OBJS) $(BOBJS)

fclean: clean
	@$(RM) $(NAME) $(BNAME)

re: fclean all
