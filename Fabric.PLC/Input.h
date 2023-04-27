
#ifndef INPUT_H
#define INPUT_H

#include "SlotType.h"

class Input {
public:
    virtual ~Input() {}

    virtual int getInpLenBits() const = 0;
    virtual int getInpOffset() const = 0;
    virtual int getInpSizeBytes() const = 0;
    virtual const SlotType& getSlotType() const = 0;
};

class InputFactory {
public:
    virtual ~InputFactory() {}

    virtual Input* createInput(int inpLenBits, int inpOffset, int inpSizeBytes, const SlotType& slotType) = 0;
};

#endif
