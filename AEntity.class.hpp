/**
 * File              : AEntity.class.hpp
 * Author            : pdeguing <pdeguing@student.42.us.org>
 * Date              : 05.05.2019
 * Last Modified Date: 05.05.2019
 * Last Modified By  : pdeguing <pdeguing@student.42.us.org>
 */

#ifndef AENTITY_CLASS_HPP
# define AENTITY_CLASS_HPP

#include <iostream>

class AEntity {

	public:

		AEntity(void);
		AEntity(AEntity const & src);
		AEntity(int y, int x);
		AEntity(int y, int x, int ch, int attr);
		virtual	~AEntity(void);

		AEntity &	operator=(AEntity const &tmp);

		virtual void		moveUp(int limit);
		virtual void		moveDown(int limit);
		virtual void		moveLeft(int limit);
		virtual void		moveRight(int limit);

		void		takeDamage(int damage) ;

		AEntity*	shoot() const;

		int		getY() const;
		int		getX() const;
		int		getCh() const;
		int		getCollidable() const;
		int		getHp() const;
		int		getAttr() const;

	protected:

		int	y;
		int	x;
		int	ch;
		int	collidable;
		int	hp;
		int	attr;
};

#endif // AENTITY_CLASS_HPP
