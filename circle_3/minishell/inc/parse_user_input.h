/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_user_input.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:46:55 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/03/16 14:04:39 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_USER_INPUT_H
# define PARSE_USER_INPUT_H

# define T_NULL 1
# define T_PIPE 2
# define T_REDIRECTION 3
# define T_WORD 4

# define NODE_PIPE 1
# define NODE_PHRASE 2
# define NODE_REDIRS 3
# define NODE_IO_REDIR 4
# define NODE_COMMAND 5
# define NODE_REDIR_TYPE 6
# define NODE_FILE_NAME 7
# define NODE_FILE_PATH 8
# define NODE_ARGV 9

# define LEFT 0
# define RIGHT 1

# define UNCLOSED_QUOTE -44
# define UNQUOTE_MALLOC_FAIL -45

# define PARSE_ERROR 258

typedef struct s_ast_node	t_ast_node;
typedef struct s_list		t_list;

typedef struct s_token
{
	int			type;
	char		*value;
}	t_token;

typedef struct s_ast_node
{
	int				node_type;
	char			*file_path;
	t_list			*argv;
	t_ast_node		*left;
	t_ast_node		*right;
}	t_ast_node;

int			split_input(char const *input, t_list **splited);
char		*j_strdup(const char *s1);
char		*j_strjoin(char const *s1, char const *s2);
char		*conv_str_join(char *argv, char *new_str);
t_list		*make_argv(t_token **token);
void		print_parsed(t_ast_node *tree);

t_ast_node	*make_ast_node(int node_type, char *file_path, t_list *argv);
t_ast_node	*ast_insert(t_ast_node *root, t_token *token, int side);
t_ast_node	*ast_insert_node(t_ast_node *root, t_ast_node *node, int side);
void		clear_ast(t_ast_node *root);

int			lexer(t_list *splitted, t_token **tokens);
int			parse_pipeline(t_ast_node **root, t_token **tokens);
int			parser(t_token **tokens, t_ast_node **tree);

int			get_quote_strlen(const char *str, char quote);
int			compare_and_join_env(char **str_to_expand,
				t_list *our_env, int i, int exit_status);
int			expand_env(t_ast_node *tree, t_list *our_env, int exit_status);

int			parse_user_input(const char *input, t_ast_node **tree,
				t_list *our_env, int exit_status);

#endif