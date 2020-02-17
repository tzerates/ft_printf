SRCNAME	= 	ft_atoi.c \
			ft_printf.c \
			ft_print.c \
			ft_printf_utils.c \
			ft_print_number.c \
			ft_printf_utils2.c \
			ft_print_u.c \
			xx_ft_printf_xx.c \
			ft_print_p.c \
			
SRCS	= ${SRCNAME}

OBJS	= ${SRCS:.c=.o}
BOBJ    = ${BSRC:.c=.o}

NAME	= libftprintf.a

CC	= gcc
RM	= rm -f

.c.o:
			${CC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all: 		${NAME}

clean:
			${RM} ${OBJS} ${BOBJ}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

c:		all clean

.PHONY:		clean fclean re all bonus
