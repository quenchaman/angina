#include "BoundingBox.h"

void BoundingBox::add(const Rectangle&)
{
}

bool BoundingBox::intersects(const BoundingBox& other)
{
	return this->max.x >= other.min.x && other.max.x >= this->min.x &&
		this->max.y >= other.min.y && other.max.y >= this->min.y;
}
