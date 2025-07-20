#include "sound.hpp"

Value SoundBlocks::volume(Block &block, Sprite *sprite) {
    return Value(sprite->volume);
}

BlockResult SoundBlocks::playSoundUntilDone(Block &block, Sprite *sprite, Block **waitingBlock, bool *withoutScreenRefresh) {
}

BlockResult SoundBlocks::playSound(Block &block, Sprite *sprite, Block **waitingBlock, bool *withoutScreenRefresh) {
}

BlockResult SoundBlocks::stopAllSounds(Block &block, Sprite *sprite, Block **waitingBlock, bool *withoutScreenRefresh) {
}

BlockResult SoundBlocks::changeEffectBy(Block &block, Sprite *sprite, Block **waitingBlock, bool *withoutScreenRefresh) {
}

BlockResult SoundBlocks::setEffectTo(Block &block, Sprite *sprite, Block **waitingBlock, bool *withoutScreenRefresh) {
}

BlockResult SoundBlocks::clearSoundEffects(Block &block, Sprite *sprite, Block **waitingBlock, bool *withoutScreenRefresh) {
}

BlockResult SoundBlocks::changeVolumeBy(Block &block, Sprite *sprite, Block **waitingBlock, bool *withoutScreenRefresh) {
}

BlockResult SoundBlocks::setVolumeTo(Block &block, Sprite *sprite, Block **waitingBlock, bool *withoutScreenRefresh) {
}
