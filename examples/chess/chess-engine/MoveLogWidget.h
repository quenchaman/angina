#ifndef EXAMPLES_CHESS_CHESS_ENGINE_MOVELOGWIDGET_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_MOVELOGWIDGET_H_

#include <deque>
#include <string>
#include <stdint.h>

#include "engine/widget/Widget.h"

struct TextStack;
struct TextRepository;

class MoveLogWidget : public Widget {
public:
    MoveLogWidget(TextStack&, TextRepository&, uint32_t sizeCap);

    void add(std::string&);
private:
    uint32_t sizeCap;
    TextStack& textStack;
    TextRepository& textRepo;
    std::deque<int32_t> textLineIds;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_MOVELOGWIDGET_H_ */
