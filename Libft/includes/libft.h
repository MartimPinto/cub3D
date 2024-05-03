/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:06:04 by axelc             #+#    #+#             */
/*   Updated: 2024/01/22 11:02:29 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @brief fills the first n bytes of the memory area pointed to by s
 * with the constant byte c.
 * 
 * @param s to fill
 * @param c to fill with
 * @param n bytes to fill
 * @return void* 
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief erases the data in the n bytes of the memory area starting 
 * at the location pointed to by s, by writing '\0' to that area
 * 
 * @param s to fill
 * @param n bytes to fill
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief copies n bytes from memory area src to memory area dest.
 * Memory areas must not overlap.
 * 
 * @param dest 
 * @param src 
 * @param n bytes to copy
 * @return void* 
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief copies n bytes from memory area src to memory area dest.
 * Memory areas can overlap.
 * 
 * @param dest 
 * @param src 
 * @param n 
 * @return void* 
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief scans the initial n bytes of the memory area pointed to
 * by s for the first instance of c.
 * 
 * @param s to scan
 * @param c to find
 * @param n bytes to scan
 * @return void* pointer to first ocurr, NULL if not found
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief compares the first n bytes (each interpreted as
 * unsigned char) of the memory areas s1 and s2.
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 0 if equal
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief returns size of the string pointed to by s.
 * 
 * @param s 
 * @return size_t 
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Concacenates the string pointed by src to the
 * string pointed by dest.
 * 
 * @param dst to concatenate to
 * @param src to concatenate
 * @param size of dest
 * @return size_t of the string that is beeing created
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Copies the content of the string pointed by src
 * into the string pointed by dst.
 * 
 * @param dst 
 * @param src 
 * @param size of dest
 * @return size_t of the string that is beeing created
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief returns a pointer to the first occurrence of
 * the character c in the string s.
 * 
 * @param s to find in
 * @param c to find
 * @return char* NULL if not found
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief returns a pointer to the last occurrence of
 * the character c in the string s.
 * 
 * @param s to find in
 * @param c to find
 * @return char* NULL if not found
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief locates the first occurrence of the null-terminated
 * string little in the null-terminated string big.
 * 
 * @param big to find in
 * @param little to find
 * @param len bytes to try to find in
 * @return char* NULL if not occuring
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief compares two strings.
 * 
 * @param s1 
 * @param s2 
 * @param n bytes to compare
 * @return int 0 if s1 is equal to s2
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief transform a string into an int.
 * 
 * @param nptr to transform
 * @return int 
 */
int		ft_atoi(const char *nptr);

/**
 * @brief checks if c is a char of the alphabet.
 * 
 * @param c 
 * @return int 1 if true
 */
int		ft_isalpha(int c);

/**
 * @brief checks if c is a digit.
 * 
 * @param c 
 * @return int 1 if true
 */
int		ft_isdigit(int c);

/**
 * @brief checks if c is a char of the alphabet or a digit.
 * 
 * @param c 
 * @return int 1 if true
 */
int		ft_isalnum(int c);

/**
 * @brief checks if c is an ascii char.
 * 
 * @param c 
 * @return int 1 if true
 */
int		ft_isascii(int c);

/**
 * @brief checks if c is a printable char.
 * 
 * @param c 
 * @return int 1 if true
 */
int		ft_isprint(int c);

/**
 * @brief puts lower case letters to upper case.
 * 
 * @param c 
 * @return c
 */
int		ft_toupper(int c);

/**
 * @brief puts upper case letters to lower case.
 * 
 * @param c 
 * @return c
 */
int		ft_tolower(int c);

/**
 * @brief  duplicates the string pointed to by s and returns
 * the copy.
 * 
 * @param s 
 * @return char* copied string
 */
char	*ft_strdup(const char *s);

/**
 * @brief allocates memory space for the type specified by
 * nmemb.
 * 
 * @param nmemb type of the variable to allocate
 * @param size size of the memory space to allocate
 * @return void* pointer to the memory space allocated
 */
void	*ft_calloc(size_t nmemb, size_t size);

/*2nd part*/
/**
 * @brief return a substring from the string pointed to by s
 * from the index start of size len.
 * 
 * @param s 
 * @param start index to start
 * @param len size of the substring
 * @return char* substring
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief joins two string. returns a pointer of the joined string
 * allocated on the heap.
 * 
 * @param s1 
 * @param s2 
 * @return char* joined
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief remove character found in the string pointed to by
 * set from the beggining and the end of s1.
 * 
 * @param s1 
 * @param set 
 * @return char* trimmed string
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief split the string pointed to by s into an array of
 * string on the specified separator c.
 * 
 * @param s 
 * @param c to split on
 * @return char** pointer to array of string
 */
char	**ft_split(char const *s, char c);

/**
 * @brief transform an int into a string.
 * 
 * @param n to transform
 * @return char* 
 */
char	*ft_itoa(int n);

/**
 * @brief applies a function pointed to by f to each elements
 * of the string pointed to by s.
 * 
 * @param s string on which to iterate
 * @param f function to apply
 * @return char* string created from applicatio of f
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief applies a function pointed to by f to each elements
 * of the string pointed to by s. 
 * 
 * @param s 
 * @param f 
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * @brief puts a char in the file descriptor specified by fd.
 * 
 * @param c 
 * @param fd 
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief puts the string pointed to by s in the file descriptor
 * specified by fd.
 * 
 * @param c 
 * @param fd 
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief puts the string pointed to by s followd by a new line
 * in the file descriptor specified by fd.
 * 
 * @param c 
 * @param fd 
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief puts the int in the file descriptor specified by fd.
 * 
 * @param c 
 * @param fd 
 */
void	ft_putnbr_fd(int n, int fd);

/*BONUS*/
/**
 * @brief creates a new node of a list and returns it.
 * 
 * @param content 
 * @return t_list* 
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief adds the node pointed to by new_node at the beggining
 * of the lst. **lst then points to the new_node.
 * 
 * @param lst 
 * @param new_node 
 */
void	ft_lstadd_front(t_list **lst, t_list *new_node);

/**
 * @brief returns the size of the list pointed to by lst.
 * 
 * @param lst 
 * @return int 
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief returns the last node of the list pointed to by lst.
 * 
 * @param lst 
 * @return t_list* last node
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief adds the node pointed to by new_node at the end
 * of the lst. **lst then points to the new_node.
 * 
 * @param lst 
 * @param new_node 
 */
void	ft_lstadd_back(t_list **lst, t_list *new_node);

/**
 * @brief applies the delete function to each element of the
 * list pointed to by lst.
 * 
 * @param lst 
 * @param del 
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief applies the delete function to the element of the
 * list pointed to by lst.
 * 
 * @param lst 
 * @param del 
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief applies the function pointed to by f to each element
 * of thec list pointed to by lst. returns a pointer to the
 * head of the modified list allocated on the heap. (undirect modfication)
 * 
 * @param lst 
 * @param del to invoke upon failure to allocate new node
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief applies the function pointed to by f to each element
 * of the list pointed to by lst. (direct modification)
 * 
 * @param lst 
 * @param del 
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/*GET_NEXT_LINE*/
/**
 * @brief returns the first new-line-terminated line from the
 * file descriptor fd.
 * 
 * @param fd 
 * @return char* 
 */
char	*get_next_line(int fd);

/*PRINTF*/
/**
 * @brief print output containing values specified in the string
 * pointed to by format.
 * 
 * @param format 
 * @param ... 
 * @return int nb of char printed upon success, negative upon error
 */
int		ft_printf(char const *format, ...);

char	*ft_realloc_str(char *ptr, size_t new_size);
char	*ft_alloc_fill(int size, char to_fill);
void	ft_memdel(void **ap);
int		ft_isnumeric(char *str);

#endif
