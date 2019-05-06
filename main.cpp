/**
 * File              : main.cpp
 * Author            : pdeguing <pdeguing@student.42.us.org>
 * Date              : 05.05.2019
 * Last Modified Date: 05.05.2019
 * Last Modified By  : pdeguing <pdeguing@student.42.us.org>
 */

#include "Game.class.hpp"

int	main() {
	Game	game;

	game.init();
	while (1) {
		game.input();
		game.update();
		if (game.getStatus() == GAME_OVER)
			break ;
		game.render();
		usleep(10000);
		game.upClock();
	}
	endwin();
	return 0;
}
