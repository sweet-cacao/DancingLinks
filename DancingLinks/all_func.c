#include "dance.h"

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------

int			ft_atoi(const char *str)
{
    unsigned long long	res;
    unsigned long long	prev;
    unsigned long long	negative;

    negative = 0;
    while (ft_isspace(*str))
        str++;
    if (*str == '-')
        negative = 1;
    if (*str == '-' || *str == '+')
        str++;
    res = 0;
    while (ft_isdigit(*str))
    {
        prev = res;
        res = res * 10 + (*str++ - '0');
        if (res < prev || res > ((unsigned long long)INT64_MAX) + negative)
            return (negative ? 0 : -1);
    }
    return ((int)((negative ? -1 : 1) * res));
}


void	ft_bzero(void *s, size_t n)
{
    ft_memset(s, '\0', n);
}


int		ft_isalnum(int c)
{
    return (ft_isalpha(c) || ft_isdigit(c));
}

int		ft_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int		ft_isascii(int c)
{
    return (c >= 0 && c <= 0177);
}

int		ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

int		ft_isprint(int c)
{
    return (c >= 32 && c < 127);
}


void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
    unsigned char	*d;
    unsigned char	*s;
    unsigned char	cc;

    d = (unsigned char *)dst;
    s = (unsigned char *)src;
    cc = (unsigned char)c;
    while (n-- > 0)
    {
        if ((*d++ = *s++) == cc)
            return (d);
    }
    return (NULL);
}


void	*ft_memchr(const void *s, int c, size_t n)
{
    unsigned char	*ptr;
    unsigned char	ch;

    ptr = (unsigned char *)s;
    ch = (unsigned char)c;
    while (n-- > 0)
    {
        if (*ptr == ch)
            return ((void *)ptr);
        ptr++;
    }
    return (NULL);
}


int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char	*p1;
    unsigned char	*p2;
    int				res;

    p1 = (unsigned char *)s1;
    p2 = (unsigned char *)s2;
    res = 0;
    while (n-- > 0 && !(res = (int)(*p1++ - *p2++)))
        ;
    return (res);
}


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char	*d;
    unsigned char	*s;

    if (!dst && !src)
        return (NULL);
    d = (unsigned char *)dst;
    s = (unsigned char *)src;
    while (n-- > 0)
        *d++ = *s++;
    return (dst);
}


void	*ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char	*d;
    unsigned char	*s;

    if (!dst && !src)
        return (NULL);
    d = (unsigned char *)dst;
    s = (unsigned char *)src;
    if (d < s)
    {
        while (len-- > 0)
            *d++ = *s++;
    }
    else
    {
        d += (len - 1);
        s += (len - 1);
        while (len-- > 0)
            *d-- = *s--;
    }
    return (dst);
}


void	*ft_memset(void *b, int c, size_t len)
{
    unsigned char	*bb;
    unsigned char	cc;
    unsigned long	*bbb;
    unsigned long	ccc;

    bbb = (unsigned long *)b;
    ccc = 0UL;
    while (len > 8)
    {
        *bbb++ = ccc;
        len -= 8;
    }
    bb = (unsigned char *)bbb;
    cc = (unsigned char)c;
    while (len > 0)
    {
        *bb++ = cc;
        len--;
    }
    return (b);
}


char	*ft_strcat(char *s1, const char *s2)
{
    char	*ptr;

    ptr = s1;
    while (*s1)
        s1++;
    while (*s2)
        *s1++ = *s2++;
    *s1 = '\0';
    return (ptr);
}


char	*ft_strchr(const char *s, int c)
{
    unsigned char	*ptr;
    unsigned char	ch;

    ptr = (unsigned char *)s;
    ch = (unsigned char)c;
    while (*ptr && *ptr != ch)
        ptr++;
    if (*ptr == ch)
        return ((void *)ptr);
    return (NULL);
}


int		ft_strcmp(const char *s1, const char *s2)
{
    unsigned char	*p1;
    unsigned char	*p2;

    p1 = (unsigned char *)s1;
    p2 = (unsigned char *)s2;
    while (*p1 && *p2 && *p1 == *p2)
    {
        p1++;
        p2++;
    }
    return ((int)(*p1 - *p2));
}


char	*ft_strcpy(char *dst, const char *src)
{
    char	*ptr;

    ptr = dst;
    while (*src)
        *dst++ = *src++;
    *dst = *src;
    return (ptr);
}


char	*ft_strdup(const char *s1)
{
    char	*result;
    size_t	size;

    size = ft_strlen(s1);
    if (size == SIZE_MAX)
        return (NULL);
    size++;
    result = (char *)malloc(size * sizeof(char));
    if (result)
        ft_memcpy(result, s1, size);
    return (result);
}


size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t	len;

    len = 0;
    while (size > 0 && *dst)
    {
        size--;
        len++;
        dst++;
    }
    if (size > 0)
    {
        size--;
        ft_memcpy(dst, src, size);
        dst[size] = '\0';
    }
    return (len + ft_strlen(src));
}


size_t	ft_strlen(const char *s)
{
    size_t	len;

    len = 0;
    while (*s++)
        len++;
    return (len);
}


char	*ft_strncat(char *s1, const char *s2, size_t n)
{
    char	*ptr;

    ptr = s1;
    while (*s1)
        s1++;
    while (*s2 && n-- > 0)
        *s1++ = *s2++;
    *s1 = '\0';
    return (ptr);
}


int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
    const char	*ptr;
    size_t		len;

    ptr = s1;
    len = 0;
    while (n-- > 0)
    {
        len++;
        if (!*ptr)
            break ;
        ptr++;
    }
    return (ft_memcmp(s1, s2, len));
}


char	*ft_strncpy(char *dst, const char *src, size_t len)
{
    char	*res;

    res = dst;
    while (*src && len > 0)
    {
        *dst++ = *src++;
        len--;
    }
    while (len > 0)
    {
        *dst++ = '\0';
        len--;
    }
    return (res);
}


char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    const char	*ptr;
    size_t		len1;
    size_t		len2;

    ptr = haystack;
    len1 = 0;
    while (len-- > 0 && *ptr)
    {
        ptr++;
        len1++;
    }
    len2 = ft_strlen(needle);
    while (len1-- >= len2)
    {
        if (ft_memcmp(haystack, needle, len2) == 0)
            return ((char *)haystack);
        haystack++;
    }
    return (NULL);
}


char	*ft_strrchr(const char *s, int c)
{
    char	*ptr;
    char	ch;

    ptr = ft_strchr(s, 0);
    if (ptr)
    {
        ch = (char)c;
        while (s <= ptr)
        {
            if (*ptr == ch)
                return (ptr);
            ptr--;
        }
    }
    return (NULL);
}


char	*ft_strstr(const char *haystack, const char *needle)
{
    const char	*p1;
    const char	*p2;

    if (!*needle)
        return ((char *)haystack);
    while (*haystack)
    {
        p1 = haystack;
        p2 = needle;
        while (*p1++ == *p2++)
            if (!*p2)
                return ((char *)haystack);
        haystack++;
    }
    return (NULL);
}

int		ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        c += 'a' - 'A';
    return (c);
}

int		ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        c += 'A' - 'a';
    return (c);
}


char	*ft_itoa(int n)
{
    char			*res;
    unsigned int	nn;
    int				len;
    int				sta;

    sta = ((n < 0) ? 1 : 0);
    len = sta + 1;
    nn = ((n < 0) ? (unsigned int)(-n) : (unsigned int)n);
    while (nn > 9)
    {
        nn /= 10;
        len++;
    }
    res = ft_strnew(len);
    if (res)
    {
        nn = ((n < 0) ? (unsigned int)(-n) : (unsigned int)n);
        while (len-- > 0)
        {
            res[len] = ((len < sta) ? '-' : '0' + nn % 10);
            nn /= 10;
        }
    }
    return (res);
}


void	*ft_memalloc(size_t size)
{
    void	*ptr;

    ptr = malloc(size);
    if (ptr)
        ft_bzero(ptr, size);
    return (ptr);
}


void	ft_memdel(void **ap)
{
    if (ap)
    {
        free(*ap);
        *ap = NULL;
    }
}


void	ft_putchar(char c)
{
    ft_putchar_fd(c, 1);
}


void	ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}


void	ft_putendl(char const *s)
{
    ft_putendl_fd(s, 1);
}


void	ft_putendl_fd(char const *s, int fd)
{
    ft_putstr_fd(s, fd);
    ft_putchar_fd('\n', fd);
}


void	ft_putnbr(int n)
{
    ft_putnbr_fd(n, 1);
}


void	ft_putnbr_fd(int n, int fd)
{
    unsigned int	nn;

    if (n < 0)
        ft_putchar_fd('-', fd);
    if (n < 0)
        nn = (unsigned int)(-n);
    else
        nn = (unsigned int)n;
    if (nn / 10 > 0)
        ft_putnbr_fd(nn / 10, fd);
    ft_putchar_fd('0' + nn % 10, fd);
}


void	ft_putstr(char const *s)
{
    ft_putstr_fd(s, 1);
}


void	ft_putstr_fd(char const *s, int fd)
{
    if (s)
    {
        while (*s)
            ft_putchar_fd(*s++, fd);
    }
}


void	ft_strclr(char *s)
{
    if (s)
        while (*s)
            *s++ = '\0';
}


void	ft_strdel(char **as)
{
    ft_memdel((void **)as);
}


int		ft_strequ(char const *s1, char const *s2)
{
    return (s1 && s2 && ft_strcmp(s1, s2) == 0 ? 1 : 0);
}

void	ft_striter(char *s, void (*f)(char *))
{
    if (s && f)
        while (*s)
            (*f)(s++);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int	i;

    if (s && f)
    {
        i = 0;
        while (*s)
            (*f)(i++, s++);
    }
}


char	*ft_strjoin(char const *s1, char const *s2)
{
    char	*str;
    size_t	len_s1;
    size_t	len_s2;

    if (!s1 || !s2)
        return (NULL);
    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    str = ft_strnew(len_s1 + len_s2);
    if (str)
    {
        ft_memcpy(str, s1, len_s1);
        ft_memcpy(str + len_s1, s2, len_s2);
    }
    return (str);
}


char	*ft_strmap(char const *s, char (*f)(char))
{
    char	*res;
    char	*ptr;

    if (!s)
        return (NULL);
    res = ft_strdup(s);
    if (res)
    {
        ptr = res;
        while (*ptr)
        {
            *ptr = (*f)(*ptr);
            ptr++;
        }
    }
    return (res);
}


char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int	i;
    char			*res;
    char			*ptr;

    if (!s)
        return (NULL);
    res = ft_strdup(s);
    if (res)
    {
        i = 0;
        ptr = res;
        while (*ptr)
        {
            *ptr = (*f)(i++, *ptr);
            ptr++;
        }
    }
    return (res);
}


int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
    return (s1 && s2 && ft_strncmp(s1, s2, n) == 0 ? 1 : 0);
}


char	*ft_strnew(size_t size)
{
    if (size == SIZE_MAX)
        return (NULL);
    return ((char *)ft_memalloc(size + 1));
}


static char		**ft_strsplit_recursive(char const *s, char c, int index)
{
    char	**res;
    int		len;

    if (!*s)
        return (char **)ft_memalloc((index + 1) * sizeof(char *));
    while (*s == c)
        s++;
    len = 0;
    while (s[len] && s[len] != c)
        len++;
    res = ft_strsplit_recursive(s + len, c, index + (len > 0 ? 1 : 0));
    if (res && len > 0)
    {
        res[index] = ft_strsub(s, 0, len);
        if (!res[index])
        {
            index++;
            while (res[index])
                ft_strdel(&res[index++]);
            free(res);
            res = NULL;
        }
    }
    return (res);
}

char			**ft_strsplit(char const *s, char c)
{
    if (s)
        return (ft_strsplit_recursive(s, c, 0));
    return (NULL);
}


char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
    char	*result;
    size_t	index;

    if (len == SIZE_MAX)
        return (NULL);
    result = (char *)malloc((len + 1) * sizeof(char));
    if (result)
    {
        index = 0;
        while (s && s[start] && len-- > 0)
            result[index++] = s[start++];
        result[index] = '\0';
    }
    return (result);
}


static int	ft_strtrim_skip(char c)
{
    return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
    char	*str;
    size_t	len;

    if (!s)
        return (NULL);
    while (ft_strtrim_skip(*s))
        s++;
    len = ft_strlen(s);
    while (len > 0 && ft_strtrim_skip(*(s + len - 1)))
        len--;
    str = ft_strnew(len);
    if (str)
        ft_strncpy(str, s, len);
    return (str);
}

int		ft_isspace(int c)
{
    return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' \
		|| c == ' ');
}


size_t	ft_lstlen(t_list *lst)
{
    size_t	len;

    len = 0;
    while (lst)
    {
        lst = lst->next;
        len++;
    }
    return (len);
}


void	ft_lstrev(t_list **alst)
{
    t_list	*list;
    t_list	*next;
    t_list	*prev;

    list = *alst;
    prev = NULL;
    while (list)
    {
        next = list->next;
        list->next = prev;
        prev = list;
        list = next;
    }
    *alst = prev;
}


void	*ft_memdup(const void *src, size_t size)
{
    void	*dst;

    dst = malloc(size);
    if (dst)
        ft_memcpy(dst, src, size);
    return (dst);
}


char	*ft_strndup(const char *src, size_t maxsize)
{
    char		*dst;
    size_t		len;

    len = ft_strnlen(src, maxsize);
    dst = ft_strnew(len);
    if (dst)
        ft_strncpy(dst, src, len);
    return (dst);
}


size_t	ft_strnlen(const char *src, size_t maxsize)
{
    const char	*ptr;

    ptr = src;
    while (maxsize-- > 0 && *ptr)
        ptr++;
    return ((size_t)(ptr - src));
}


void	ft_lstadd(t_list **alst, t_list *new)
{
    t_list	*ptr;

    if (alst && new)
    {
        ptr = new;
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = *alst;
        *alst = new;
    }
}


void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
    if (alst && del)
    {
        while (*alst)
            ft_lstdelone(alst, del);
    }
}


void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
    t_list	*ptr;

    if (alst && del && *alst)
    {
        ptr = *alst;
        (*del)(ptr->content, ptr->content_size);
        *alst = ptr->next;
        free(ptr);
    }
}


void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
    if (f)
    {
        while (lst)
        {
            (*f)(lst);
            lst = lst->next;
        }
    }
}


static void		ft_lstmap_del(void *content, size_t content_size)
{
    if (content_size)
        content_size = 0;
    free(content);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
    t_list	*result;
    t_list	**addr;

    result = NULL;
    addr = &result;
    if (f)
    {
        while (lst)
        {
            *addr = (*f)(lst);
            if (!*addr)
            {
                ft_lstdel(&result, &ft_lstmap_del);
                return (NULL);
            }
            addr = &(*addr)->next;
            lst = lst->next;
        }
    }
    return (result);
}


t_list	*ft_lstnew(void const *content, size_t content_size)
{
    t_list	*res;

    res = (t_list *)ft_memalloc(sizeof(t_list));
    if (res)
    {
        if (content)
        {
            res->content = malloc(content_size);
            if (!res->content)
            {
                free(res);
                return (NULL);
            }
            ft_memcpy(res->content, content, content_size);
            res->content_size = content_size;
        }
    }
    return (res);
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------


int		tetrim_text(t_tetrim *self, char *text)
{
    int		count;
    int		index;

    count = 0;
    index = 0;
    while (index < 20)
    {
        if (index % 5 == 4)
        {
            if (text[index] != '\n')
                return (0);
        }
        else
        {
            if (text[index] != '#' && text[index] != '.')
                return (0);
            if (text[index] == '#' && count++ < 4)
            {
                self->block[count - 1].x = (index - (index / 5)) % 4;
                self->block[count - 1].y = (index - (index / 5)) / 4;
            }
        }
        index++;
    }
    return (count == 4);
}

void	tetrim_area(t_tetrim *self)
{
    int		x;
    int		y;
    int		index;

    self->x0 = 3;
    self->y0 = 3;
    self->x1 = 0;
    self->y1 = 0;
    index = 0;
    while (index < 4)
    {
        x = self->block[index].x;
        y = self->block[index].y;
        if (self->x0 > x)
            self->x0 = x;
        if (self->y0 > y)
            self->y0 = y;
        if (self->x1 < x)
            self->x1 = x;
        if (self->y1 < y)
            self->y1 = y;
        index++;
    }
}

static inline int	paired(t_point a, t_point b)
{
    return ((a.x + 1 == b.x && a.y == b.y) || (a.x == b.x && a.y + 1 == b.y));
}

int					tetrim_valid(t_tetrim *self)
{
    int		count;

    count = 0;
    count += paired(self->block[0], self->block[1]);
    count += paired(self->block[0], self->block[2]);
    count += paired(self->block[0], self->block[3]);
    count += paired(self->block[1], self->block[2]);
    count += paired(self->block[1], self->block[3]);
    count += paired(self->block[2], self->block[3]);
    return (count > 2);
}

void	tetrim_destroy(t_tetrim **addr)
{
    if (addr && *addr)
    {
        tetrim_destroy(&(*addr)->next);
        ft_memdel((void **)addr);
    }
}

t_tetrim	*tetrim_create(char *text)
{
    t_tetrim	*self;

    self = (t_tetrim *)ft_memalloc(sizeof(t_tetrim));
    if (self)
    {
        if (tetrim_text(self, text))
        {
            tetrim_area(self);
            if (tetrim_valid(self))
                return (self);
        }
    }
    if (self)
        tetrim_destroy(&self);
    return (NULL);
}

t_tetrim				*tetrim_readfile(int fd)
{
    t_tetrim	*self;
    char		buff[20];
    int			ret;

    ret = read(fd, buff, 20);
    if (ret == 20)
    {
        self = tetrim_create(buff);
        if (self)
        {
            ret = read(fd, buff, 1);
            if (ret == 0)
                return (self);
            if (ret == 1 && buff[0] == '\n')
            {
                self->next = tetrim_readfile(fd);
                if (self->next)
                    return (self);
            }
            tetrim_destroy(&self);
        }
    }
    return (NULL);
}

int		tetrim_count(t_tetrim *walk)
{
    int		count;

    count = 0;
    while (walk)
    {
        walk = walk->next;
        count++;
    }
    return (count);
}
