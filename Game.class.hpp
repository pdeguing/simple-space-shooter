/**
 * File              : Game.class.hpp
 * Author            : pdeguing <pdeguing@student.42.us.org>
 * Date              : 05.05.2019
 * Last Modified Date: 05.05.2019
 * Last Modified By  : pdeguing <pdeguing@student.42.us.org>
 */

#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

#include <ncurses.h>
#include <string.h>
#include <unistd.h>

#include "AEntity.class.hpp"
#include "Asteroid.class.hpp"
#include "Missile.class.hpp"

#define N_ENTITIES	1000

#define GAME_DEFAULT	0
#define GAME_OVER	1

#define HEIGHT		51
#define WIDTH		61

#define BOTTOM	(LINES - ((LINES - HEIGHT) / 2))

#define KEY_SPACE	' '
#define KEY_QUIT	'q'

class Game {

	public:

		Game(void);
		Game(Game const & src);
		virtual	~Game(void);

		Game &	operator=(Game const &tmp);

		void	init();
		void	input();
		void	update();
		void	render() const;

		void	resolveCollisions();
		
		void	spawnEnemies();

		WINDOW*	createWindow(int height, int width, int y, int x);

		void	upClock();

		void	insertMissile();

		int	getStatus() const;

	private:

		int		_status;

		AEntity* 	_player;
		AEntity*	_entities[N_ENTITIES];
		AEntity*	_missilesPlayer[N_ENTITIES];

		WINDOW*		_wgame;

		int		_clock;
};

#endif // GAME_CLASS_HPP
