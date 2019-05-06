/**
 * File              : Missile.class.hpp
 * Author            : pdeguing <pdeguing@student.42.us.org>
 * Date              : 05.05.2019
 * Last Modified Date: 05.05.2019
 * Last Modified By  : pdeguing <pdeguing@student.42.us.org>
 */

#ifndef MISSILE_CLASS_HPP
# define MISSILE_CLASS_HPP

#include "AEntity.class.hpp"
#include <ncurses.h>

class Missile : public AEntity {

	public:

		Missile(void);
		Missile(Missile const & src);
		Missile(int y, int x);
		virtual	~Missile(void);
};

#endif // MISSILE_CLASS_HPP
