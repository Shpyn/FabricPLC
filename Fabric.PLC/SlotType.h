#ifndef SLOTTYPE_H
#define SLOTTYPE_H

#include <string>

class SlotType {
public:
    SlotType(const std::string& type) : type_(type) {}

    std::string getType() const {
        return type_;
    }

private:
    std::string type_;
};

#endif

