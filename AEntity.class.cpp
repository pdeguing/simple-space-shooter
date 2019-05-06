/**
 * File              : AEntity.class.cpp
 * Author            : pdeguing <pdeguing@student.42.us.org>
 * Date              : 05.05.2019
 * Last Modified Date: 05.05.2019
 * Last Modified By  : pdeguing <pdeguing@student.42.us.org>
 */
#include "AEntity.class.hpp"

AEntity::AEntity(void) {}

AEntity::AEntity(AEntity const & src) {*this = src;}

AEntity::AEntity(int y, int x) : y(y), x(x) {}

AEntity::AEntity(int y, int x, int ch, int attr) : y(y), x(x), ch(ch), attr(attr) {}

AEntity::~AEntity(void) {}

AEntity &	AEntity::operator=(AEntity const & tmp) {
	if (this == &tmp)
		return *this;
	this->y = tmp.getY();
	this->x = tmp.getX();
	this->ch = tmp.getCh();
	this->collidable = tmp.getCollidable();
	this->hp = tmp.getHp();
	this->attr = tmp.getAttr();
	return *this;
}

void	AEntity::moveUp(int limit) {
	if (this->y > limit)
		this->y--;
}

void	AEntity::moveDown(int limit) {
	if (this->y < limit - 1)
		this->y++;
}

void	AEntity::moveLeft(int limit) {
	if (this->x > limit + 1)
		this->x--;
}

void	AEntity::moveRight(int limit) {
	if(this->x < limit - 2)
		this->x++;
}

void	AEntity::takeDamage(int damage) {
	this->hp -= damage;
	if (this->hp < 0)
		this->hp = 0;
}

AEntity*	AEntity::shoot() const {
	AEntity*	bullet = new AEntity(this->y, this->x);
	return bullet;
}

int	AEntity::getY() const {
	return this->y;
}

int	AEntity::getX() const {
	return this->x;
}

int	AEntity::getCh() const {
	return this->ch;
}

int	AEntity::getCollidable() const {
	return this->collidable;
}

int	AEntity::getHp() const {
	return this->hp;
}

int	AEntity::getAttr() const {
	return this->attr;
}
