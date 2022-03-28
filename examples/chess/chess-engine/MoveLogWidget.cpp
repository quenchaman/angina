#include "MoveLogWidget.h"

#include "engine/repositories/TextRepository.h"
#include "renderer/primitives/Text.h"
#include "engine/components/textstack/TextStack.h"

MoveLogWidget::MoveLogWidget(TextStack& txtStack, TextRepository& txtRepo, IdGenerator& gen, uint32_t cap): textStack(txtStack),
    textRepo(txtRepo), idGen(gen), sizeCap(cap) {}

void MoveLogWidget::add(std::string& text) {
    if (textLineIds.size == sizeCap) {
        textLineIds.pop_back();
    }

    int32_t id = idGen.next();
    Text* textTexture = textStack.add(text);
    textLineIds.push_back(id);
}
