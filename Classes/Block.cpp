#include "Block.h"

//Judge if rects intersect
bool rectIntersect(setRect* rect1, setRect* rect2)
{
	bool rightTop = pointInrect(rect1, rect2->right, rect2->top);
	bool rightBottom = pointInrect(rect1, rect2->right, rect2->bottom);
	bool leftTop = pointInrect(rect1, rect2->left, rect2->top);
	bool leftBottom = pointInrect(rect1, rect2->left, rect2->bottom);

	if (rightTop || rightBottom || leftTop || leftBottom)
		return true;

	return false;
}

//Judge rect1's points are in the rect2
bool pointInrect(setRect* rect1,int rect2x,int rect2y)
{
	if (rect2x >= rect1->left && rect2x <= rect1->right && rect2y <= rect1->top && rect2y >= rect1->bottom)
		return true;
	return false;
}

Block::Block()
{

}

Block::~Block()
{}

void Block::collideHero(Hero* hero)
{}

