#pragma once
#include "../blockExecutor.hpp"

class PenBlocks{
public:
    static BlockResult PenDown(Block& block, Sprite* sprite, Block** waitingBlock, bool* withoutScreenRefresh);
    static BlockResult PenUp(Block& block, Sprite* sprite, Block** waitingBlock, bool* withoutScreenRefresh);
    static BlockResult EraseAll(Block& block, Sprite* sprite, Block** waitingBlock, bool* withoutScreenRefresh);
    static BlockResult SetPenOptionTo(Block& block, Sprite* sprite, Block** waitingBlock, bool* withoutScreenRefresh);
    static BlockResult ChangePenOptionBy(Block& block, Sprite* sprite, Block** waitingBlock, bool* withoutScreenRefresh);
    static BlockResult Stamp(Block& block, Sprite* sprite, Block** waitingBlock, bool* withoutScreenRefresh);
    static BlockResult SetPenColorTo(Block& block, Sprite* sprite, Block** waitingBlock, bool* withoutScreenRefresh);
    static BlockResult SetPenSizeTo(Block& block, Sprite* sprite, Block** waitingBlock, bool* withoutScreenRefresh);
    static BlockResult ChangePenSizeBy(Block& block, Sprite* sprite, Block** waitingBlock, bool* withoutScreenRefresh);
};