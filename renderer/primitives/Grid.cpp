#include "Grid.h"

#include <cstdint>

#include "renderer/Renderer.h"

Grid::Grid(Point origin, [[maybe_unused]]float cellWidth, float cellHeight, [[maybe_unused]]float fullWidth, [[maybe_unused]]float fullHeight) {
	int32_t horizontalLinesCount = static_cast<int32_t>((fullHeight / cellHeight) - 1);

	for (int32_t i = 0; i < horizontalLinesCount; i++) {
		float startPointY = origin.y + (cellHeight * (static_cast<float>(i) + 1.0f));
		float startPointX = origin.x;
		float endPointY = startPointY;
		float endPointX = fullWidth;

		Line line = {
				Point{startPointX, startPointY},
				Point{endPointX, endPointY},
				Color::RED
		};

		lines.push_back(line);
	}

//	int32_t verticalLinesCount = static_cast<int32_t>((fullWidth / cellWidth) - 1);
}

void Grid::draw(Renderer& renderer) {
	for (Line& line : lines) {
		renderer.render(line);
	}
}
