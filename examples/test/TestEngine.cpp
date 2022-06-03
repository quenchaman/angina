#include "TestEngine.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <utility>
#include "resources/Resources.h"
#include "core/math/geometry/Geometry.h"

#include "enginev2/graphics/commons/primitives/Dimensions.h"
#include "enginev2/graphics/commons/primitives/Line.h"
#include "enginev2/graphics/commons/primitives/Color.h"

const int32_t width = 960;
const int32_t height = 860;
const int32_t squareSize = 4;

TestEngine::TestEngine(): GameEngine() {
	GameEngine::init("Hello SDL!", width, height);
}

void TestEngine::onStart() {
	srand(time(NULL));

	for (int32_t i = 0; i < pointCount; i++) {
		int32_t randomX = rand() % width;
		int32_t randomY = rand() % height;

		points[i] = Point(randomX, randomY);
		Dimensions dim = Dimensions(squareSize, squareSize);
		rectangleComponent.loadRectangle(points[i], dim, Color::RED, true);
	}
}

void TestEngine::handleEvent() {
	if (inputComponent.type == EventType::MOUSE_RELEASE) {
		Point p = findRectOrigin(inputComponent.posX, inputComponent.posY);

		std::cout << "Point clicked " << p << std::endl;

		Point closest = findClosestPoint(p);

		if (closest != Point::UNDEFINED) {
			std::cout << "The closest point is with coordinates " << closest << std::endl;

			lineComponent.clear();

			Point offsetFromOrigin = Point(squareSize / 2, squareSize / 2);

			lineComponent.loadLine(p + offsetFromOrigin, closest + offsetFromOrigin, Color::GREEN);
		} else {
			std::cout << "No close point found" << std::endl;
		}
	}
}

Point TestEngine::findRectOrigin(int32_t x, int32_t y) const {
	for (int32_t i = 0; i < pointCount; i++) {
		Point p = points[i];
		PointPair origin = std::make_pair(p.x, p.y);
		DimensionsPair dims = std::make_pair(squareSize, squareSize);
		PointPair query = std::make_pair(x, y);

		bool isInsideRect = Geometry::isInRect(origin, dims, query);

		if (isInsideRect) {
			return p;
		}
	}

	return Point::UNDEFINED;
}

int32_t TestEngine::distanceBetweenPoints(const Point& p1, const Point& p2) const {
	int32_t deltaX = p1.x - p2.x;
	int32_t deltaY = p1.y - p2.y;
	return static_cast<int32_t>(sqrt(deltaX * deltaX + deltaY * deltaY));
}

Point TestEngine::findClosestPoint(const Point& p) const {
	Point closestPoint = Point::UNDEFINED;
	int32_t smallestDistance = width + 1;

	for (int32_t i = 0; i < pointCount; i++) {
		Point candidate = points[i];

		if (candidate == p) continue;

		int32_t distance = distanceBetweenPoints(p, candidate);

		if (distance < smallestDistance) {
			closestPoint = candidate;
			smallestDistance = distance;
		}
	}

	return closestPoint;
}

void TestEngine::findClosestForAllPoints() {
	Point offsetFromOrigin = Point(squareSize / 2, squareSize / 2);

	for (int32_t i = 0; i < pointCount; i++) {
			Point candidate = points[i];
			Point closest = findClosestPoint(candidate);

			if (closest != Point::UNDEFINED) {
				lineComponent.loadLine(candidate + offsetFromOrigin, closest + offsetFromOrigin, Color::GREEN);
			}
	}
}
