/**
 * File              : Asteroid.class.cpp
 * Author            : pdeguing <pdeguing@student.42.us.org>
 * Date              : 05.05.2019
 * Last Modified Date: 05.05.2019
 * Last Modified By  : pdeguing <pdeguing@student.42.us.org>
 */

#include "Asteroid.class.hpp"

Asteroid::Asteroid(void) {
	return ;
}

Asteroid::Asteroid(Asteroid const & src) {
	*this = src;
	return ;
}

Asteroid::Asteroid(int y, int x) : AEntity(y, x, ACS_DIAMOND, COLOR_PAIR(2)) {
}

Asteroid::~Asteroid(void) {
	return ;
}
