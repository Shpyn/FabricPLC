#ifndef OUTPUTIMPL_H
#define OUTPUTIMPL_H

#include "Output.h"
#include "SlotType.h"

class OutputImpl : public Output {
public:
    OutputImpl(int outLenBits, int outOffset, int outSizeBytes, const SlotType& slotType) :
        outLenBits_(outLenBits), outOffset_(outOffset), outSizeBytes_(outSizeBytes), slotType_(slotType) {}

    int getOutLenBits() const override { return outLenBits_; }
    int getOutOffset() const override { return outOffset_; }
    int getOutSizeBytes() const override { return outSizeBytes_; }
    const SlotType& getSlotType() const override { return slotType_; }

private:
    int outLenBits_;
    int outOffset_;
    int outSizeBytes_;
    SlotType slotType_;
};

class OutputFactoryImpl : public OutputFactory {
public:
    Output* createOutput(int outLenBits, int outOffset, int outSizeBytes, const SlotType& slotType) override {
        return new OutputImpl(outLenBits, outOffset, outSizeBytes, slotType);
    }
};

#endif

