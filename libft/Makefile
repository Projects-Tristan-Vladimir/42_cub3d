

#*********** VARIABLES ************

#VARIABLE=VALUE
CC = cc
CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address
NAME = libft.a

SRCS = ft_bzero.c\
		ft_calloc.c\
		ft_strlen.c\
		ft_strndup.c\
		ft_atoi.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_split.c\
		ft_strncmp.c\
		ft_strjoin_free.c\
		ft_free_null_str.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_putstr_fd.c\
		ft_putchar_fd.c\
		ft_bzero.c ft_calloc.c\
		ft_strndup.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strtrim.c\
		ft_is_in_charset.c\
		ft_memset.c\
		ft_itoa.c

#${SRCS:.c=.o} means, take the variable value ${SRCS},
# which is a string composed of words separated by spaces,
# and for each word, replace the suffix .c with .o
OBJS=$(SRCS:.c=.o)

#*********** RULES ************

#syntax for target/rule :
#target/rule: dependencies
#        command

#old fashioned suffix rule : ‘.c.o’ (target = '.o', source = '.c')
# is equivalent to the pattern rule ‘%.o : %.c’. which is up to date.
%.o : %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#command ar : creates, modifies, and extracts from archives.
#An archive is a single file holding a collection of other files in a structure
# that makes it possible to retrieve the original individual files
#lib statique under UNIX = big file which contains all the *.o files,
#to be used for the compilator
$(NAME): $(OBJS)
	ar rcs $@ $^

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

#in case files exist with same name as targets
.PHONY: all clean fclean re bonus
