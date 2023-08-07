/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:57:44 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/05 16:22:05 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* ************************************************************************** */
/* __/\\\____________________/\\\_______________/\\\\\_______________         */
/*  _\/\\\___________________\/\\\_____________/\\\///________________        */
/*   _\/\\\______________/\\\_\/\\\____________/\\\__________/\\\______       */
/*    _\/\\\_____________\///__\/\\\_________/\\\\\\\\\____/\\\\\\\\\\\_      */
/*     _\/\\\______________/\\\_\/\\\\\\\\\__\////\\\//____\////\\\////__     */
/*      _\/\\\_____________\/\\\_\/\\\////\\\____\/\\\_________\/\\\______    */
/*       _\/\\\_____________\/\\\_\/\\\__\/\\\____\/\\\_________\/\\\_/\\__   */
/*        _\/\\\\\\\\\\\\\\\_\/\\\_\/\\\\\\\\\_____\/\\\_________\//\\\\\___  */
/*         _\///////////////__\///__\/////////______\///___________\/////____ */
/* ************************************************************************** */

// _         _         _
//(_)_ _  __| |_  _ __| |___ ___
//| | ' \/ _| | || / _` / -_(_-<
//|_|_||_\__|_|\_,_\__,_\___/__/
////////////////////////////////////////////////////////////////////////////////
# include <stdlib.h>// Libft is the starting project of the 42 curus and acts //
# include <unistd.h>// as a foundation for its core curriculum.               //
////////////////////////////////////////////////////////////////////////////////

// _____                                    _
//|  ______  _ __ _____      _____  _ __ __| |
//| |_ / _ \| '__/ _ \ \ /\ / / _ \| '__/ _` |
//|  _| (_) | | |  __/\ V  V | (_) | | | (_| |
//|_|  \___/|_|  \___| \_/\_/ \___/|_|  \__,_|
////////////////////////////////////////////////////////////////////////////////
// When I started 42, I speedrunned this project. I had already started libft //
// before the school even started and was therfore able to bridge the gap from//
// piscine to the kickoff, without loosing much tempo or knowledge gathered in//
// the piscine. I finished in under 3 days, not beeing able to evaluate it for//
// a week, becuase there where simply no eval points in circulation(on my lvl)//
// Still proud on my achivment, I started the next projects and finished the  //
// coding part of the first circle in the first three weeks.				  //
// At the time my startup, I slidered in and became co-founder 1 Month prior  //
// to 42, started to become more serious and work intensive. Suddenly I was   //
// developing an app, with no prior coding experience other than theoretic    //
// IT knowledge, literally last-updated 20 years ago, I learned in school.    //
// Needless to say, that I did not have time or focus for anything 42 related //
// in the next 7 month.                                                       //
// Speedrunning another circle, after dipping to 2 days blackhole, and        //
// a well deserved 2 Month freeze to recover from startup and personal stress //
// later, I shall return to actually being a student.                         //
// I am currently writing this to give myself a break from creating silly     //
// Ascii artworks with stupid lines, based on inside jokes I have with myself.//
// That should tell you enough about my current level of sanity.              //
// Tonight I decided to document my libft like a libary, because It's being   //
// used by my project partner (PS: Sorry if your reading this, thinking this  //
// was important) and to regaine an overview over the code that I have written//
// in the past. A overview I would probably have, if I didn't do it at 3 am on//
// 3 Liters of espresso.                                                      //
// I know this isn't remotly the right scope for a text like this but I think //
// this, the head of the little libary that is constantly evolving with me,   //
// evolving as a student, is the right spot to remind me of my journey, every //
// time i go to add a new function for my future me.
// A journey of learning that always trying to speedrun stuff, makes you not  //
// actually play the game you and your privilidges worked so hard to be a     //
// part of. LOL                                                               //
// Also nobody looks iside libft header files after the first circle          //
////////////////////////////////////////////////////////////////////////////////

/*      /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\     *\
       /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾.‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\
      /                              .|.                                  \
     /                     .-..      |||  .                                \
    /                      | _|_     ||| _|_      o                         \
   /                      -|- |      .-.  |  .-.  .                          \
  /                        |  |     (   ) | (   ) |                           \
 /                         '  `-'____`-'`-`-'`-'-' `-                          \
( À toi! Small and irresistibly French: With strings, longs and ints <3 À toi!  )
 \     .-..           .              j_I   .-..          .      .              /
  \    | _|_       o _|_            .)_(.  | _|_        _|_     |             /
   \  -|- |        .  |  .-.  .-.   |===| -|- |      .--.|  .--.| .-. .--.   /
    \  |  |        |  | (   )(   )  /___\  |  |      `--.|  |   |(.-' |  |  /
     \ '  `-'____-' `-`-'`-'  `-'`-//___\\ '  `-'____`--'`-''   `-`--''  - /
      \                           /=======\                               /
       \                         / .-"""-. \                             /
        \                       |__|     |__|                           /
\*       ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾     */

/// @brief Computes the length of string \p [str].
/// @param str String of which length to get.
/// @return Returns the number of characters of \p [str] that precede the
/// terminating NUL-character.
size_t	ft_strlen(const char *str);

/// @brief converts the the initial portion of the string pointed by \p [str] to
/// its int representation, ignoring leading whitespaces.
/// @param str String to be converted.
/// @return Returns the int representation of \p [str]. Exp: " aa-1234" -> -1234
int		ft_atoi(const char *str);

/// @brief converts the initial portion of the string pointed by \p [str] to
/// its long representation, ignoring leading whitespaces.
/// @param str String to be converted.
/// @return Returns the long representation of \p [str]. Exp: " a-1234" -> -1234
long	ft_atoi_l(const char *str);

/// @brief Allocates and returns a string representing of the integer \p [n].
/// @details Also handels negative numbers.
/// @param n The integer to convert.
/// @return Returns pointer to the string representing the integer.
/// NULL if the allocation fails.
char	*ft_itoa(int n);

/*     /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\    *\
      /    ____      __ _                             _          ____    \
     /    / __ \    / _| |_   _ __  ___ _ __  ___ ___| |_       / __ \    \
    /    / / / /   |  _|  _| | '  \/ -_) '  \(_-</ -_)  _|     / / / /     \
   /    / /_/ /    |_|  \__|_|_|_|_\___|_|_|_/__/\___|\__|    / /_/ /       \
  /     \____/            |___|                               \____/         \
 /                                                                            \
( Filling up that memory as if it were my bank account! (There are only zer0s) )
 \       __ _             _ _           _    __ _     _                       /
  \     / _| |_   __ __ _| | |___  __  | |  / _| |_  | |__ ______ _ _ ___    /
   \   |  _|  _| / _/ _` | | / _ \/ _| | | |  _|  _| | '_ \_ / -_) '_/ _ \  /
    \  |_|  \__|_\__\__,_|_|_\___/\__| | | |_|  \__|_|_.__/__\___|_| \___/ /
     \        |___|                    |_|        |___|                   /
\*    \__________________________________________________________________/    */

/// @brief Writes \p n bytes with the value '\0' to the string \p [s].
/// @param src Pointer to the zeroed string.
/// @param n Amount of Bytes to be zeroed.
void	ft_bzero(void *src, size_t n);

/// @brief contiguously allocates enough space for \p [count] objects
/// that are \p  [size] bytes of memory each and returns a pointer to the
/// allocated memory. The allocated memory is filled with bytes of value '\0'.
/// @param count Number of objects.
/// @param size Size of objects.
/// @return Returns a pointer to the allocated memory. NULL if allocation fails.
void	*ft_calloc(size_t count, size_t size);

/// @brief Writes \p [n] amount bytes of value \p [c] to string \p [str].
/// @param str String to be changed.
/// @param c Value to be assigned.
/// @param n Amount of bytes.
/// @return Returns a pointer to str.
void	*ft_memset(void *str, int c, size_t n);

/* ************************************************************************** *\
 *                                             /$$                            *
 *                                            | $$                            *
 *      /$$$$$$$ /$$$$$$ /$$   /$$        /$$$$$$$/$$   /$$ /$$$$$$           *
 *     /$$_____//$$__  $| $$  | $$       /$$__  $| $$  | $$/$$__  $$          *
 *    | $$     | $$  \ $| $$  | $$      | $$  | $| $$  | $| $$  \ $$          *
 *    | $$     | $$  | $| $$  | $$      | $$  | $| $$  | $| $$  | $$          *
 *    |  $$$$$$| $$$$$$$|  $$$$$$$      |  $$$$$$|  $$$$$$| $$$$$$$/          *
 *     \_______| $$____/ \____  $$       \_______/\______/| $$____/           *
 *             | $$      /$$  | $$                        | $$                *
 *             | $$     |  $$$$$$/                        | $$                *
 *COPYCATS>Need to copy? Try our 5 original options! More coming-soon<COPYCATS*
 *                                                                            *
 *                 /$$$$$$/$$$$  /$$$$$$ /$$    /$$/$$$$$$                    *
 *                | $$_  $$_  $$/$$__  $|  $$  /$$/$$__  $$                   *
 *                | $$ \ $$ \ $| $$  \ $$\  $$/$$| $$$$$$$$                   *
 *                | $$ | $$ | $| $$  | $$ \  $$$/| $$_____/                   *
 *                | $$ | $$ | $|  $$$$$$/  \  $/ |  $$$$$$$                   *
 *                |__/ |__/ |__/\______/    \_/   \_______/                   *
 *                                                                            *
\* ************************************************************************** */

/// @brief Duplicates \p [s1] and allocates sufficent memory for the copy.
/// @param s1 String to be duplicated.
/// @return Returns pointer to the copied string. NULL if allocation fails.
char	*ft_strdup(const char *s1);

/// @brief Copies \p [n] amount of bytes from source \p [src] to destination
/// \p [dest]. Don't use if memory could overlap instead use \ref ft_memmove()
/// @param dest Destination of the copy.
/// @param src Source of the copy.
/// @param n How many bytes to copy.
/// @return Returns the original pointer value of \p [dest].
void	*ft_memcpy(void *dest, const void *src, size_t n);

/// @brief Copies \p [n] amount of bytes from source \p [src] to destination
/// \p [dest]. If character \p [c] is found within \p [n] bytes, the copy stops.
/// Don't use if memory could overlap.
/// @param dst Destination of the copy.
/// @param src Source of the copy.
/// @param c Delimiter character.
/// @param n Max. Number of Bytes to be copied.
/// @return If \p [c] is found, returns a pointer to the byte after the copy of
/// \p [c] in the string \p [dst]. If \p [c] is NOT found, returns NUL-pointer.
void	*ft_memccpy(void *dst, void *src, int c, size_t n);

/// @brief Copies, \p [len] amount of bytes, from source \p [src] to destination
/// \p [dst]. Strings are allowed to overlap.
/// @param dest Destination of the copy.
/// @param src Source of the copy.
/// @param len How many bytes to copy.
/// @return Returns the original pointer value of \p [dst].
void	*ft_memmove(void *dst, const void *src, size_t len);

/// @brief Copies up to dstsize - 1 characters from the string \p src to \p dst,
/// NUL-terminating the result if \p dstsize is not 0.
/// @details ft_strlcpy() takes the full size of the destination buffer and
/// guarantees NUL-termination if there is room. Note that room for the NUL
/// should be included in \p size. Also note that ft_strlcpy() only operates on
/// true 'C' strings. This means that \p src must be NUL-terminated.
/// @param dst Pointer to the destination.
/// @param src Pointer to the string to be copied.
/// @param size Size of destination.
/// @return Returns strlen(src). If return >= \p size output string was cut off.
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/*----------------------------------------------------------------------------*/
/* Discover chars, unsigned chars, and chars* in strings. Unmatched Diversity!*/
/*----------------------------------------------------------------------------*/

/// @brief Searches the first occurence of \p [c] in string \p [s] whithin
/// \p [n] bytes.
/// @param s String to be searched.
/// @param c character to be searched (converted to unsigned char).
/// @param n Number of bytes to be searched.
/// @return Returns pointer to first located byte of value \p [c]. Else NULL.
void	*ft_memchr(const void *s, int c, size_t n);

/// @brief Searches the first occurence of \p [c] in string \p [s]
/// until '\0', including '\0'.
/// @param s String to be searched.
/// @param c Value to be searched (converted to char).
/// @return Returns a pointer to the first occurance of \p c. Else NULL.
char	*ft_strchr(const char *s, int c);

/// @brief Searches the last occurence of \p [c] in string \p [s],
/// until '\0' including '\0'.
/// @param s String to be searched.
/// @param c Value to be searched (converted to char).
/// @return Returns a pointer to the last occurance of \p c. Else NULL.
char	*ft_strrchr(const char *s, int c);

/// @brief Locates first occurance of \p [needle] sub-string in \p [haystack]
/// string. Does not search more then \p [len] characters.
/// @details Characters that appear after a ‘\0’ character are not searched.
/// @param haystack Haystack string that is searched for \p [needle].
/// @param needle Sub-String that \p [haystack] is searched for.
/// @param len Max. Amount of characters being searched.
/// @return If \p [needle] is empty, \p [haystack] is returned; if \p [needle]
/// occurs nowhere in \p [haystack], NULL is returned; otherwise a pointer to
/// the first character of the first occurrence of \p [needle] is returned.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/*----------------------------------------------------------------------------*/
/*Comparing s1 to s2 for n bytes felt brutal until I discovered this lifehack.*/
/*----------------------------------------------------------------------------*/

/// @brief Compares String \p [s1] to String \p [s2] for \p [n] amount of bytes.
/// @param s1 String 1 as unsigned char*.
/// @param s2 String 2 as unsigned char*.
/// @param n Amount of bytes to be compared.
/// @return Returns NULL if strings are identical. (s1[i] - s2[i]) if not.
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/// @brief Compares String \p [s1] to String \p [s2] for \p [n] amount of bytes.
/// @details Does not compare beyond '\0’ character unlike \ref ft_memcmp().
/// @param s1 String 1 as unsigned char*.
/// @param s2 String 2 as unsigned char*.
/// @param n Amount of bytes to be compared.
/// @return return NULL if strings are identical. (s1[i] - s2[i]) if not.
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*----------------------------------------------------------------------------*/
/*What when or who is c? The quest is not safe. Be alert, they can c your fear*/
/*----------------------------------------------------------------------------*/

/// @brief Checks if \p c is Alphabetical ("A-Z"/"a-z").
/// @param c character to be checked.
/// @return Returns 1 if \p c is Alphabetical (True). 0 if not (False).
int		ft_isalpha(int c);

/// @brief Checks if \p [c] is printable (Value between 32-126).
/// @param c Value to be checked.
/// @return Returns 1 if printable (true). 0 if not (false).
int		ft_isprint(int c);

/// @brief Checks if \p c is digit ("0-9").
/// @param c character to be checked.
/// @return Returns 1 if character is digit (True). 0 if not (False).
int		ft_isdigit(int c);

/// @brief Checks if \p c is "A-Z"/"a-z"/"0-9".
/// @param c character to be ckecked.
/// @return Returns 1 if c is alphanumeric (True), 0 if not (False).
int		ft_isalnum(int c);

/// @brief Checks if character is Ascii (Value between 0 - 127).
/// @param c character to be checked.
/// @return Returns 1 if character is Ascii (true). 0 if not (false).
int		ft_isascii(int c);

/*----------------------------------------------------------------------------*/
/*Strings make strings, strings join strings, strings trim strings. Thats life*/
/*----------------------------------------------------------------------------*/

/// @brief Allocates and returns a new string, consisting of \p [s1]
/// (prefix) and \p [s2] (sufix).
/// @param s1 Prefix String.
/// @param s2 Sufix String.
/// @return Returns pointer to the new string. NULL if allocation fails.
char	*ft_strjoin(char const *s1, char const *s2);

/// @brief Appends string \p [src] to the remaining size in \p [dst] and
/// NUL-terminates the result.
/// @details It will append at most \p dstsize - strlen(dst) - 1 characters.
/// It will then NUL-terminate, unless \p dstsize is 0 or the original \p dst
/// string was longer than \p dstsize (in practice this should not happen as
/// it means that either \p dstsize is incorrect or that \p dst is not a proper
/// string). Also note that ft_strlcat() only operates on true 'C' strings that
/// means both \p src and \p dst must be NUL-terminated.
/// If the \p src and \p dst strings overlap, the behavior is undefined.
/// @param dst Pointer to the destination including the dst string.
/// @param src Pointer to the append string.
/// @param dstsize Total size in \p [dst].
/// @return Returns total length of the string tried to create (strlen(dst)
/// + strlen(dst)). If return >= \p dstsize, output string was cut off.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/// @brief Allocates and returns a copy of \p [s1] with the characters specified
/// in \p [set] removed from the start and the end of the string.
/// @details Removes characters from the beginning or the end as long as the
/// characters at those ends match any of the characters in \p [set].
/// @param s1 String to be trimmed.
/// @param set Set of characters to trim.
/// @return Returns pointer to the trimmed string. NULL if the allocation fails.
char	*ft_strtrim(char const *s1, char const *set);

/// @brief Allocates and returns a substring from the string \p [s].
/// The substring begins at index \p [start] and is of maximum size \p [len].
/// @param s String that the substr is created from.
/// @param start Index of byte where the substr begins.
/// @param len Max. length of substr.
/// @return Returns pointer to the substring. NULL if the allocation fails.
char	*ft_substr(char const *s, unsigned int start, size_t len);

/// @brief Allocates and returns an array of strings by splitting \p [s] using
/// the character \p [c] as a delimiter. The array ends with a NULL pointer.
/// @param s String to be split.
/// @param c Delimiter character - indicates where to split.
/// @return Returns a pointer to the array of new strings resulting from
/// the split. NULL if the allocation fails.
char	**ft_split(char const *s, char c);

/*----------------------------------------------------------------------------*/
/*Changing chars has never been easy. Here are 4 tips to make it less charring*/
/*----------------------------------------------------------------------------*/

/// @brief Capitalizes \p  c "a-z" to "A-Z".
/// @param c character to be Capitalized.
/// @return Returns capitalized character value. \p [c] if not capitalized.
int		ft_toupper(int c);

/// @brief lowers \p c "A-Z" to "a-z".
/// @param c character to be lowered.
/// @return Returns the value of the lowered character. \p [c] if not lowered.
int		ft_tolower(int c);

/// @brief Applies the function \p [f] to each character of the string \p [s],
/// passing each characters index as first argument. Creating a new string,
/// resulting from successive applications of \p [f].
/// @param s The string on wich to apply \p [f]
/// @param f The functions to apply to each character of \p [s]
/// @return The string created from the successive applications of \p [f].
/// Returns NULL if the allocation fails.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/// @brief Applies the function \p [f] to each character of the string \p [s],
/// passing each characters index as first argument and its address as second,
/// to be modified if necessary.
/// @param s The string on wich to apply \p [f]
/// @param f The functions to apply to each character of \p [s]
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* ---------------------------------------------------------------------------*/
/*    Don't know where to print? Try fd's! (1024 outputs instant available)   */
/* ---------------------------------------------------------------------------*/

/// @brief Outputs the character \p [c] to the given file descriptor \p [fd]
/// @param c Charachter to output.
/// @param fd The file descriptor to write to.
/// @return Returns number of charachters written (1). -1 if an error occoured.
int		ft_putchar_fd(char c, int fd);

/// @brief Outputs the string \p [s] to the given file descriptor \p [fd]
/// @param s String to output.
/// @param fd The file descriptor to write to.
/// @return Returns number of charachters written.
/// return != ft=strlen(s) if an error occoured.
int		ft_putstr_fd(char *s, int fd);

/// @brief Outputs the integer \p [n] to the file descriptor \p [fd]
/// @param n The integer to output.
/// @param fd The file descriptor to write to.
/// @param i Counter for written decimals. Always call with i = 1.
/// @return Returns number of written decimals.
int		ft_putnbr_fd(int n, int fd, int i);

/// @brief Outputs string \p [s] to the file descriptor \p [fd] followed by \\n
/// @param s String to output.
/// @param fd The file descriptor to write to.
void	ft_putendl_fd(char *s, int fd);

/*----------------------------------------------------------------------------*/
/*          What rhymes to linked list? This shit should not exist!           */
/*----------------------------------------------------------------------------*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/// @brief Adds the node \p [new] at the beginning of \p [lst].
/// @details Assigns \p new->next = \p *lst and \p *lst = \p new
/// @param lst The address of a pointer to the first link of a list.
/// @param new The address of a pointer to the node to be added to the list.
void	ft_lstadd_front(t_list **lst, t_list *new);

/// @brief adds the list \p [new] to the end of list \p [lst]
/// @details If \p *lst is empty (!*lst), \p *lst is assigned the value of
/// \p new, making it the first and last value of \p lst. Otherwise a new
/// node newlst is assigned the value of ft_lstlast(*lst) to make its
/// newlst->next the value of \p new. {value here referes to pointer val}
/// @param lst The address of a pointer to the first link of a list.
/// @param new The address of a pointer to the node to be added to the list.
void	ft_lstadd_back(t_list **lst, t_list *new);

/// @brief Counts the number of nodes in a list \p [lst].
/// @details Duplicates pointer of \p [lst] as list and assigns it list->next,
/// counting every step, until list->next is NULL.
/// @param lst The beginning of the list.
/// @return Returns the number of nodes in \p [lst].
int		ft_lstsize(t_list *lst);

/// @brief Allocates and creates a new node with \p [content] as content.
/// @details t_list \a *new_list is allocated using malloc(sizeof(t_list)).
/// \a new_list->content is assigned \p content and new_list->next = NULL
/// @param content The content to create the node with.
/// @return Returns pointer to new node. NULL if allocation fails.
t_list	*ft_lstnew(void *content);

/// @brief Finds last node of list \p [lst].
/// @details While \p lst->next exists, value of \p lst pointer is
/// assigned the value of pointer \p lst->next.
/// @param lst List to search last node of.
/// @return Returns pointer to last node of \p lst. NULL if \p lst is empty.
t_list	*ft_lstlast(t_list *lst);

/// @brief Frees node \p [lst] and deletes its content using \p [del].
/// @details Returns instant if \p lst is empty. Else: Uses del(lst->content).
/// to delete content of \p lst, and free(lst), to free the address of \p lst.
/// @param lst Pointer to node to be freed.
/// @param del Address of the Function used to delete the content of the node.
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/// @brief Frees every node of \p [lst] and deletes its contents using \p [del].
/// @details Returns instant if \p lst is NULL. \a newlist gets Assigned pointer
/// value of *lst. Then while \a newlst != NULL, del(newlst->content) is used
/// to delete content of current node. Then \a free_lst is assigned pointer
/// value of \a newlst and \a newlst is assigned to the next node. Last
/// free(free_lst) is used on prior node. Cycle continues till \a newlst, thus
/// \p *lst is completly cleared. \p *lst still pointing to its first node is
/// assigned NULL, concluding \ref ft_lstclear().
/// @param lst The address of a pointer to a node.
/// @param del The address of the function used to delete content of the node.
void	ft_lstclear(t_list **lst, void (*del)(void *));

/// @brief Uses function \p [f] on the content of all \p [lst] nodes.
/// @details While \p lst exist uses \p f(lst->content) and goes to next node.
/// @param lst The address of a pointer to a node.
/// @param f The address of the function used on the contents.
void	ft_lstiter(t_list *lst, void (*f)(void *));

/// @brief \p [f] is used on the content of the nodes from list \p [lst]
/// to create a new list. \p [del] is used to delete content if necessary.
/// @details If \p [lst] or \p [f] don't exist return NULL. Two helper variables
/// are needed: \a *newlst and \a *newnode. \a Newlst holds the new list.
/// \a Newnode holds the new nodes being added to newlist. To create a new node
/// \a ft_lstnew(f(lst->content)) is used and assigned to \a newnode. If the
/// allocation in \ref ft_lstnew() fails, ft_lstclear(&newlst, del) is used
/// to free the list and return. \ref ft_lstadd_back(&newlst, newnode) is used
/// to add \a newnode to \a newlst. This is done for every node in \p [lst].
/// @param lst Address of a pointer to a node of lst.
/// @param f Function used on content of nodes.
/// @param del Function used to delete content of nodes.
/// @return Returns pointer to first node of the new list.
/// NULL if any allocation fails during runtime.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ---------------------------------------------------------------------------*/
/*       Have you missed these gems from the all-time classic ft_split()?     */
/* ---------------------------------------------------------------------------*/

/// @brief Counts words in string \p [s] delimited by char \p [c].
/// @details Helper function of \ref ft_split() used to find needed
/// allocation amount.
/// @param s String to count words within.
/// @param c Word delimiter (A word is everything delimited by \p [c]).
/// @return Returns number of words delimited by \p [c].
int		wordcount(const char *s, char c);

/// @brief creates and allocates sub String from \p [str], \p [z] till \p [fin],
/// excluding \p [fin].
/// @details Helper function of \ref ft_split() used to create the splitted
/// sub-strings that split returns.
/// @param str String to create sub-strings of.
/// @param z Start index of sub-string.
/// @param fin Stop index of sub-string.
/// @return Returns a pointer to allocated and Nul-terminated sub-string.
char	*fillstr(const char *str, int z, int fin);

/*----------------------------------------------------------------------------*/
/*ft_printf(), now with 1024 times more choices. Infinity just got an update^°*/
/*----------------------------------------------------------------------------*/

/// @brief Formats and prints its arguments \p [...] on the STDOUT. Controlled
/// by the string \p [format]. The \p [format] string consist of literal chars,
/// that get printed as their character, interupted by flags, preluded by a '%'
/// and followed by {c,s,i,u,x,p,X,%}. Flags define the way a value in \p [...],
/// is handeled. The interpreted values are printed to their respectives
/// postitions of the flag inside the \p [format] string.
/// @note Usage example ft_printf("I am %X %s in Hex", 20, "Years");
/// @details Result: "I am 14 Years in Hex".
/// @param format String controlling formating and handling of other arguments.
/// @param [...] Successive arguments, controlled by flags in \p [format].
/// @return Returns the total number of chars printed.
int		ft_printf(const char *format, ...);

/// @brief Formats and prints its arguments \p [...] to the file descriptor
/// \p [fd]. Controlled by the string \p [format], consisting of literal
/// chars that just get coppied to the \p [fd]. Chars get interupted by flags,
/// preluded by a '%' and followed by {c,s,i,u,x,p,X,%}. Flags cause printing
/// of the next successive argument in \p [...]. Interpreted values are printed
/// on the respectives postition of their flag inside the \p [format] string.
/// @note Usage example ft_printf_fd(1, "I am %d %s in decimal", 20, "Years");
/// @details Result: "I am 20 Years in decimal".
/// @param fd File discriptor where the output should be printed.
/// @param format String controlling formating and handling of other arguments.
/// @param [...] Successive arguments, controlled by flags in \p [format].
/// @return Returns the total number of chars printed.
int		ft_printf_fd(int fd, const char *format, ...);

#endif
