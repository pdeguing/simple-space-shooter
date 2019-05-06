/**
 * File              : Asteroid.class.hpp
 * Author            : pdeguing <pdeguing@student.42.us.org>
 * Date              : 05.05.2019
 * Last Modified Date: 05.05.2019
 * Last Modified By  : pdeguing <pdeguing@student.42.us.org>
 */

#ifndef ASTEROID_CLASS_HPP
# define ASTEROID_CLASS_HPP

#include "AEntity.class.hpp"
#include <ncurses.h>

class Asteroid : public AEntity {

	public:

		Asteroid(void);
		Asteroid(Asteroid const & src);
		Asteroid(int y, int x);
		virtual	~Asteroid(void);

};

#endif // ASTEROID_CLASS_HPP
