/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:29:53 by tbezerra          #+#    #+#             */
/*   Updated: 2023/10/25 17:07:27 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define DECIMAL   "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* Part 1 */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_atoi(const char *s);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t nelem, size_t elsize);
void	ft_bzero(void *str, size_t n);
void	*ft_memset(void *str, int i, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);

/* Part 2 */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);

/* Bonus */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*Get Next Line*/
char	*get_next_line(int fd);
char	*ft_erro(char *rest, char *line, int size);
int		ft_strlen2(char *str);
int		check_char(char *s, int c);
char	*ft_strjoin2(char *rest, char *line);

/*Ft_Printf*/
int		ft_printf(const char *str, ...);
int		ft_putchar_var(va_list arg, const char var);
int		ft_putnbr_base(long nbr, char *base);
int		ft_putnbr_base_u(unsigned long nbr, char *base);
int		ft_putchar_len(int c);
int		ft_printmem(unsigned long long num);
void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_printpercent(void);



#endif
