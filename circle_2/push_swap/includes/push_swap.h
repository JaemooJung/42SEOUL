#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_node	t_node;
struct	s_node
{
	int			value;
	t_node		*prev;
	t_node		*next;
};

typedef struct s_stack
{
	int			size;
	t_node		*top;
	t_node		*bottom;
}				t_stack;

int		check_arguments_and_append(int argc, char **argv);

t_node	*new_node(int value);
void	dupcheck_and_append(t_node **head, t_node *new_node);
void	append(t_node **head, t_node *new_node);

void	error_handler();

long long	ft_atoi(char *str);

#endif