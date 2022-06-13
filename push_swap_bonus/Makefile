# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 17:04:36 by schoe             #+#    #+#              #
#    Updated: 2022/06/13 17:37:20 by schoe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
BSRCS = main_b.c ft_get_av_b.c ft_quick_sort_b.c ft_error_check_b.c \
		ft_stack_list_b.c command_p_s_b.c command_r_b.c command_rr_b.c 
BOBJS = ${BSRCS:.c=.o}
RM = rm -f
INCLUDE = -I../includes
NAME = ../checker

all : $(NAME)

$(NAME) : ${BOBJS}
		${CC} ${CFLAGS} ${BOBJS} ../libft.a -o $(NAME)

%.o : %.c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INCLUDE}
clean :
		${RM} ${BOBJS}

fclean : clean
		${RM} $(NAME)
re : 
	${MAKE} fclean 
	${MAKE} all

.PHONY: all clean fclean re
