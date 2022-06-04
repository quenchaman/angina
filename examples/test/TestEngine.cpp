#include "TestEngine.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <utility>
#include <vector>
#include <unordered_set>
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
	srand(static_cast<int32_t>(time(NULL)));

	for (int32_t i = 0; i < pointCount; i++) {
		int32_t randomX = rand() % width / 2 + (width / 4);
		int32_t randomY = rand() % height / 2 + (height / 4);

		points[i] = Point(randomX, randomY);
		Dimensions dim = Dimensions(squareSize, squareSize);
		rectangleComponent.loadRectangle(points[i], dim, Color::RED, true);
	}

	std::vector<Point> ps = outlineConvex();

	for (size_t i = 1; i < ps.size(); i++) {
	  Point current = ps[i];
	  Point previous = ps[i - 1];

	  lineComponent.loadLine(current, previous, Color::GREEN);
	}
}

void TestEngine::handleEvent() {

}

std::vector<Point> TestEngine::outlineConvex() {
  Point current = Point::UNDEFINED;

  for (int32_t i = 0; i < pointCount; i++) {
    Point candidate = points[i];

    if (candidate.x < current.x) {
      current = candidate;
    } else if (candidate.x == current.x && candidate.y > current.y) {
      current = candidate;
    }
  }

  std::unordered_set<Point, Point::Hash> convexPointsSet;
  std::vector<Point> convexPoints;
  convexPoints.push_back(current);

  do {
    int32_t bestDotScore = -1;
    Point convexPoint = Point::UNDEFINED;

    for (int32_t i = 0; i < pointCount; i++) {
        Point candidate = points[i];

        if (candidate != current && convexPointsSet.find(candidate) == convexPointsSet.end()) {
          Point negatedLeftMostPoint = Point(0, 0) - current;
          Point vectorBetweenCurrentAndCandidate = candidate - current;

          int32_t dotProduct = abs(negatedLeftMostPoint.x * vectorBetweenCurrentAndCandidate.x +
              negatedLeftMostPoint.y * vectorBetweenCurrentAndCandidate.y);

          if (dotProduct > bestDotScore) {
            bestDotScore = dotProduct;
            convexPoint = candidate;
          }
        }
    }

    std::cout << convexPoint << std::endl;

    convexPoints.push_back(convexPoint);
    convexPointsSet.insert(convexPoint);
    current = convexPoint;
  } while (convexPoints[0] != convexPoints[convexPoints.size() - 1]);

  return convexPoints;
}
