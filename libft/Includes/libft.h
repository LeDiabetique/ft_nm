/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:11:51 by hdiot             #+#    #+#             */
/*   Updated: 2022/12/06 12:31:12 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

char	*get_next_line(int fd);
char	*get_next_line_bonus(int fd);
char	*ft_joinfree(char *str, char *buf);

int		ft_putstr(char *str);
int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_printpercent(void);
int		ft_printnbr(int n);
int		ft_printunsigned(unsigned int n);
int		ft_printhex(unsigned int num, const char format);
int		ft_putptr(unsigned long long num);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	*ft_memset(void	*str, int c, size_t	count);
void	*ft_memcpy(void	*dest, const void	*src, size_t	n);
char	*ft_strchr(const char	*str, int c);
int		ft_atoi(const char	*str);
void	ft_bzero(void	*s, size_t	n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void	*s, int c, size_t	n);
int		ft_memcmp(const void	*p1, const void	*p2, size_t	i);
char	*ft_strchr(const char	*str, int c);
size_t	ft_strlen(const char	*c);
int		ft_strncmp(const char	*s1, const char	*s2, size_t	n);
char	*ft_strnstr(const char	*b, const char	*l, size_t i);
char	*ft_strrchr(const char	*str, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlcpy(char	*dest, const char	*src, size_t i);
size_t	ft_strlcat(char	*dest, const char	*src, size_t i);
void	*ft_memmove(void	*dest, const void	*src, size_t n);
char	*ft_strdup(const char	*src);
void	*ft_calloc(size_t count, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strjoin(char const	*s1, char const	*s2);
char	*ft_substr(char const	*s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list	*lst, void (*f)(void *));
t_list	*ft_lstmap(t_list	*lst, void *(*f)(void *), void (*del)(void *));

#endif
