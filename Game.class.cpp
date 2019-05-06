/**
 * File              : Game.class.cpp
 * Author            : pdeguing <pdeguing@student.42.us.org>
 * Date              : 05.05.2019
 * Last Modified Date: 05.05.2019
 * Last Modified By  : pdeguing <pdeguing@student.42.us.org>
 */

#include "Game.class.hpp"

Game::Game(void) : _player(NULL), _clock(0) {
	return ;
}

Game::Game(Game const & src) {
	*this = src;
	return ;
}

Game::~Game(void) {
	return ;
}

Game &	Game::operator=(Game const & tmp) {
	if (this == &tmp)
		return *this;
	return *this;
}

void	Game::init() {
	int	starty, startx;
	char	msg[] = "PRESS Q TO EXIT";

	//std::cerr << "game.init()\n";
	this->_status = GAME_DEFAULT;
	for (int i = 0; i < N_ENTITIES; i++) {
		this->_entities[i] = NULL;
		this->_missilesPlayer[i] = NULL;
	}

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);

	start_color();
	init_color(COLOR_BLACK, 18, 18, 18);
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);

	starty = (LINES - HEIGHT) / 2;
	startx = (COLS - WIDTH) / 2;

	attron(A_BOLD);
	mvprintw(1, (COLS - strlen(msg)) / 2, "%s", msg);
	attroff(A_BOLD);
	refresh();

	this->_wgame = createWindow(HEIGHT, WIDTH, starty, startx);
	this->_player = new AEntity(HEIGHT - 3, WIDTH / 2);
}

void	Game::input() {
	int	ch;

	//std::cerr << "game.input()\n";
	ch = getch();
	switch (ch) {

		case KEY_QUIT:
			this->_status = GAME_OVER;
			break ;

		case KEY_SPACE:
			this->insertMissile();
			break ;

		case KEY_LEFT:
			this->_player->moveLeft(0);
			break ;

		case KEY_RIGHT:
			this->_player->moveRight(WIDTH);
			break ;

		default:
			break ;
	}
}

void	Game::update() {

	//std::cerr << "game.update()\n";
	if (this->_clock % 10 == 0) {
		for (int i = 0; i < N_ENTITIES; i++) {
			if (!this->_entities[i])
				continue ;
			this->_entities[i]->moveDown(HEIGHT);
			if (this->_entities[i]->getY() >= HEIGHT - 1) {
				delete this->_entities[i];
				this->_entities[i] = NULL;
			}
		}
		this->spawnEnemies();
	}
	if (this->_clock % 5 == 0) {
		for (int i = 0; i < N_ENTITIES; i++) {
			if (!this->_missilesPlayer[i])
				continue ;
			this->_missilesPlayer[i]->moveUp(0);
			if (this->_missilesPlayer[i]->getY() <= 0) {
				delete this->_missilesPlayer[i];
				this->_missilesPlayer[i] = NULL;
			}
		}
	}
	this->resolveCollisions();
}

void	Game::render() const {
	AEntity	*currEntity;

	//std::cerr << "game.render()\n";
	wclear(this->_wgame);
	//wattron(this->_wgame, COLOR_PAIR(0) | A_BOLD);
	//box(this->_wgame, 0, 0);
	//wattroff(this->_wgame, COLOR_PAIR(0) | A_BOLD);
	wattron(this->_wgame, COLOR_PAIR(0));
	mvwaddch(this->_wgame, this->_player->getY(), this->_player->getX(), ACS_UARROW);
	wattroff(this->_wgame, COLOR_PAIR(0));
	for (int i = 0; i < N_ENTITIES; i++) {
		currEntity = this->_entities[i];
		if (!currEntity)
			continue ;
		wattron(this->_wgame, currEntity->getAttr());
		mvwaddch(this->_wgame, currEntity->getY(), currEntity->getX(), currEntity->getCh());
		wattroff(this->_wgame, currEntity->getAttr());
	}
	for (int i = 0; i < N_ENTITIES; i++) {
		currEntity = this->_missilesPlayer[i];
		if (!currEntity)
			continue ;
		wattron(this->_wgame, currEntity->getAttr());
		mvwaddch(this->_wgame, currEntity->getY(), currEntity->getX(), currEntity->getCh());
		wattroff(this->_wgame, currEntity->getAttr());
	}
	wrefresh(this->_wgame);
}

void	Game::resolveCollisions() {
	//std::cerr << "game.resolveCollisions()\n";
	for (int i = 0; i < N_ENTITIES; i++) {
		if (this->_entities[i]) {
			if (this->_player->getY() == this->_entities[i]->getY()
					&& this->_player->getX() == this->_entities[i]->getX()) {
				this->_status = GAME_OVER;
				return ;
			}
			for (int j = 0; j < N_ENTITIES; j++) {
				if (this->_missilesPlayer[j] 
						&& this->_entities[i]->getY() == this->_missilesPlayer[j]->getY()
						&& this->_entities[i]->getX() == this->_missilesPlayer[j]->getX()
						&& this->_entities[i] != this->_missilesPlayer[j]) {
					delete this->_entities[i];
					delete this->_missilesPlayer[j];
					this->_entities[i] = NULL;
					this->_missilesPlayer[j] = NULL;
					break ;
				}
			}
		}
	}
}

void	Game::spawnEnemies() {
	//std::cerr << "game.spawnEnemies()\n";
	for (int i = 1; i < WIDTH - 1; i++) {
		if ((rand() % 100) < 1) {
			for (int j = 0; j < N_ENTITIES; j++) {
				if (!this->_entities[j]) {
					this->_entities[j] = new Asteroid(1, i);
					break ;
				}
			}
		}
	}
}

WINDOW*	Game::createWindow(int height, int width, int y, int x) {
	WINDOW	*newWin;

	newWin = newwin(height, width, y, x);
	/*
	wattron(newWin, COLOR_PAIR(0) | A_BOLD);
	box(newWin, 0, 0);
	wattroff(newWin, COLOR_PAIR(0) | A_BOLD);
	*/

	wrefresh(newWin);

	return newWin;
}

void	Game::upClock() {
	this->_clock++;
}

void	Game::insertMissile() {
	//std::cerr << "game.insertMissile()\n";
	for (int j = 0; j < N_ENTITIES; j++) {
		if (!this->_missilesPlayer[j]) {
			this->_missilesPlayer[j] = new Missile(this->_player->getY() - 1, this->_player->getX());
			break ;
		}
	}
}

int	Game::getStatus() const {
return this->_status;
}
