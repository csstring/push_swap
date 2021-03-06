# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 17:04:36 by schoe             #+#    #+#              #
#    Updated: 2022/06/13 17:59:30 by schoe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
DIR = ./m_srcs
SRCS = ${DIR}/command_p_s.c ${DIR}/ft_div_utils.c ${DIR}/ft_quick_sort.c \
	   ${DIR}/command_r.c ${DIR}/ft_error_check.c ${DIR}/ft_stack_list.c \
	   ${DIR}/command_rr.c ${DIR}/ft_get_av.c ${DIR}/main.c \
	   ${DIR}/ft_cmd_list.c ${DIR}/ft_push_swap.c ${DIR}/ft_div.c \
	   ${DIR}/ft_push_swap_utils.c
OBJS = ${SRCS:.c=.o}
RM = rm -f
INCLUDE = -I./includes
NAME = push_swap

all : $(NAME)

ifdef BONUS
	${MAKE} -C ./push_swap_bonus all
else
endif

$(NAME) : ${OBJS}
		${MAKE} -C ./libft all
		${CC} ${CFLAGS} ${OBJS} libft.a -o $(NAME)

%.o : %.c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INCLUDE}
bonus :
	make BONUS=1
clean :
		${MAKE} -C ./libft clean
		${MAKE} -C ./push_swap_bonus clean
		${RM} ${OBJS}

fclean : clean
		${MAKE} -C ./libft fclean
		${MAKE} -C ./push_swap_bonus fclean
		${RM} $(NAME)
re : 
	${MAKE} fclean 
	${MAKE} all

.PHONY: all clean fclean re bonus
