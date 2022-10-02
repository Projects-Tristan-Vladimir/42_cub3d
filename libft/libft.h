#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>

long long		ft_atoll(char *str);
size_t			ft_strlen(const char *s);
void			ft_bzero(void *ptr, size_t n);
void			*ft_calloc(size_t n, size_t size);
int				is_in_charset(char c, const char *charset);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_atoi(char *nptr);
size_t			ft_strlcpy(char *dst, const char *src, size_t dst_size);
char			*ft_strdup(char *s);
char			*ft_strndup(const char *s, int len);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strjoin_free(char **s1, char **s2);
char			**ft_split(char *s, char c);
char			**ft_freetbl(char **tbl, int pos);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_free_null_str(char **str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			*ft_memset(void *ptr, int c, size_t n);
char			*ft_itoa(int n);

#endif
