# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 09:25:08 by vjean             #+#    #+#              #
#    Updated: 2022/06/30 12:43:15 by vjean            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_funct_ext.c ft_printf.c \

CC = gcc #le compilateur à utiliser

CFLAGS = -Wall -Wextra -Werror #les flags à ajouter pour la compilation

AR = ar rcs #pour créer et maintenir les archives des fichiers. r: insert the files member into archive (wit R eplacement).
#s: write an object-file index into the archive, or update an existing one, even if no other change is made to the archive(like ranlib)
#c: create the archive

RM = rm -f #remove the non-directory type files specified on the command line (with rm). -f: remove without prompting confirmation
#if does not exist, do not display a diagnostic message.

OBJS = $(SRCS:%c=%o) #ojets égal la variable des sources (dont les fonctions de sources qui se terminent en .c) et les objets sont
#dépendants des sources.

#BONUS_OBJS = $(BONUS:.c=.o) même principe que OBJS

all: $(NAME) #j'appelle le nom de ma variable

$(NAME): $(OBJS) #ma variable est dépendante de mes objets
	$(AR) $(NAME) $(OBJS) 
#recette qu'elle doit effectuer.
libftprintf:
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)
#quelles sont les variables utiles pour clean

fclean: clean
		$(RM) $(NAME)

re: fclean all

#bonus: $(OBJS) $(BONUS_OBJS)
#$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re #bonus //a recipe to be make as I have a specific request