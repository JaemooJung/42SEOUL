#ifndef KEY_INPUT_HANDLER_H
# define KEY_INPUT_HANDLER_H

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

# define KEY_ESC			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2

void	check_wall_and_move(int keycode, t_game *game);
void	check_collectible(t_game *game);
void	check_exit(t_game *game);

int		key_input_handler(int keycode, t_game *game);

#endif
