
#ifndef OUTPUT_H
#define OUTPUT_H

#include "SlotType.h"

class Output {
public:
    virtual ~Output() {}

    virtual int getOutLenBits() const = 0;
    virtual int getOutOffset() const = 0;
    virtual int getOutSizeBytes() const = 0;
    virtual const SlotType& getSlotType() const = 0;
};

class OutputFactory {
public:
    virtual ~OutputFactory() {}

    virtual Output* createOutput(int outLenBits, int outOffset, int outSizeBytes, const SlotType& slotType) = 0;
};

#endif
