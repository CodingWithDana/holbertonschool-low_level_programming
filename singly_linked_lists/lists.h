#ifndef LISTS_H
#define LISTS_H
#include <stddef.h>
/**
 * struct list - a list's basic info
 * @str: pointer to a string
 * @len: the length of the string
 * @next: pointer to the next element/node in the list
 */
/* Create a struct list_t */
typedef struct list
{
	char *str;
	unsigned int len;
	struct list *next;
} list_t;

/* Function prototypes */
int _putchar(char c);
size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);

#endif
