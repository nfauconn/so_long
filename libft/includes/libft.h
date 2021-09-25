/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:22:20 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/25 19:31:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BUFFER_SIZE 2048
# define CONVFLAGS "cspdiuxX%-0.*123456789"
# define CONV "cspdiuxX%"
# define FLAGS "-0.*123456789"
# define BUFFSIZE 3

enum
{
	c = 0,
	s,
	p,
	d,
	i,
	u,
	x,
	mx,
	percent,
};

typedef unsigned long long	t_ull;

typedef struct s_conv
{
	size_t	left;
	size_t	zero_padded;
	size_t	is_width;
	size_t	width;
	size_t	is_prec;
	size_t	prec;
	size_t	if_positive;
	char	sign;
	size_t	hashtag;
	size_t	len;
	char	*str;
	size_t	nb_s;
	size_t	nb_z;
}				t_conv;

typedef struct s_pf
{
	char	*format;
	char	*buffer;
	size_t	bufsize;
	char	*ptr;
	int		index_conv;
	size_t	bufalloc;
	void	(*fun_ptr[9])(va_list *, t_conv *);
}				t_pf;

int			ft_printf(const char *str, ...);
void		init_pf(t_pf *pf, const char *format);
void		init_conv(t_conv *conv);
void		insert_into_buffer(t_pf *pf, char *insert, size_t len);
void		convert(va_list *ap, t_pf *pf);
void		conv_c(va_list *ap, t_conv *conv);
void		conv_s(va_list *ap, t_conv *conv);
void		conv_p(va_list *ap, t_conv *conv);
void		conv_d_i(va_list *ap, t_conv *conv);
void		conv_u(va_list *ap, t_conv *conv);
void		conv_x(va_list *ap, t_conv *conv);
void		conv_mx(va_list *ap, t_conv *conv);
void		conv_percent(va_list *ap, t_conv *conv);
void		spaces_zeros(t_conv *conv, size_t sign);
void		fill_without_pw(t_conv *conv, char *str, size_t sign);
void		fill_with_pw(t_conv *conv, const char *str, size_t sign);
int			main_loop(t_pf *pf, va_list *ap);
void		parse_flag(t_pf *pf, t_conv *conv, va_list *ap);
int			parse_conv(t_pf *pf);
void		convert(va_list *ap, t_pf *pf);

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memalloc(size_t size);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		ft_memdel(void **ap);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlen(const char *str);
int			ft_nbrlen_base(int nbr, int base);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isflagpf(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *s);
int			ft_atoi_base(const char *s, int base);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
void		ft_strfdup(char **over, char *buff);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_strfjoin(char **over, char *buff);
char		*strfjoinchar(char *str, char c);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_ulltoa_base(unsigned long long n, int base, size_t maj);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			*sort_int_tab(int *tab, int size);
int			str_isdigit(char *str);
void		rev_int_tab(int *tab, int size);

#endif
