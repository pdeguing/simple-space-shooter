/**
 * File              : Missile.class.cpp
 * Author            : pdeguing <pdeguing@student.42.us.org>
 * Date              : 05.05.2019
 * Last Modified Date: 05.05.2019
 * Last Modified By  : pdeguing <pdeguing@student.42.us.org>
 */

#include "Missile.class.hpp"

Missile::Missile(void) {
	return ;
}

Missile::Missile(Missile const & src) {
	*this = src;
	return ;
}

Missile::Missile(int y, int x) : AEntity(y, x, ACS_BULLET, COLOR_PAIR(0)){
}

Missile::~Missile(void) {
	return ;
}
