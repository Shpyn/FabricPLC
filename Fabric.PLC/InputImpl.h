
#ifndef INPUTIMPL_H
#define INPUTIMPL_H

#include "Input.h"
#include "SlotType.h"

class InputImpl : public Input {
public:
    InputImpl(int inpLenBits, int inpOffset, int inpSizeBytes, const SlotType& slotType) :
        inpLenBits_(inpLenBits), inpOffset_(inpOffset), inpSizeBytes_(inpSizeBytes), slotType_(slotType) {}

    int getInpLenBits() const override { return inpLenBits_; }
    int getInpOffset() const override { return inpOffset_; }
    int getInpSizeBytes() const override { return inpSizeBytes_; }
    const SlotType& getSlotType() const override { return slotType_; }

private:
    int inpLenBits_;
    int inpOffset_;
    int inpSizeBytes_;
    SlotType slotType_;
};

class InputFactoryImpl : public InputFactory {
public:
    Input* createInput(int inpLenBits, int inpOffset, int inpSizeBytes, const SlotType& slotType) override {
        return new InputImpl(inpLenBits, inpOffset, inpSizeBytes, slotType);
    }
};

#endif
