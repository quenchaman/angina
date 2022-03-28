#ifndef EXAMPLES_CHESS_CHESS_ENGINE_MOVELOGWIDGET_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_MOVELOGWIDGET_H_

#include <deque>
#include <string>
#include <stdint.h>

#include "engine/widget/Widget.h"

struct TextStack;
struct TextRepository;
struct IdGenerator;

class MoveLogWidget : public Widget {
public:
    MoveLogWidget(TextStack&, TextRepository&, IdGenerator&, uint32_t sizeCap);

    void add(std::string&);
private:
    TextStack& textStack;
    TextRepository& textRepo;
    IdGenerator& idGen;
    uint32_t sizeCap;

    std::deque<int32_t> textLineIds;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_MOVELOGWIDGET_H_ */
