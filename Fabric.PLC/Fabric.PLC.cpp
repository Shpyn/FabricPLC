#include <iostream>
#include <vector>
#include "Input.h"
#include "Output.h"
#include "InputImpl.h"
#include "OutputImpl.h"
#include "SlotType.h"

int main() {
    std::vector<Input*> inputs;
    std::vector<Output*> outputs;

    char choice = 'i';
    while (choice == 'i' || choice == 'o') {
        std::cout << "Choose what to add: input (i) or output (o), or q to quit: ";
        std::cin >> choice;

        if (choice == 'i') {
            int inpLenBits, inpOffset, inpSizeBytes;
            std::string slotTypeStr;
            std::cout << "Enter InpLenBits, InpOffset, InpSizeBytes, SlotType (Digital/Analog): " 
                << std::endl << "InpLenBits= ";
            std::cin >> inpLenBits;
            std::cout << "InpOffset= ";
            std::cin >> inpOffset;
            std::cout << "InpSizeBytes= ";
            std::cin >> inpSizeBytes;
            std::cout << "SlotType= ";
            std::cin >> slotTypeStr;
                

            // Validate SlotType input
            SlotType slotType(slotTypeStr);
            while (slotType.getType() != "Digital" && slotType.getType() != "Analog") {
                std::cout << "Invalid SlotType. Please enter 'Digital' or 'Analog': ";
                std::cin >> slotTypeStr;
                slotType = SlotType(slotTypeStr);
            }

            InputFactoryImpl factory;
            Input* input = factory.createInput(inpLenBits, inpOffset, inpSizeBytes, slotType);

            std::cout << "Created input: InpLenBits=" << input->getInpLenBits()
                << " InpOffset=" << input->getInpOffset()
                << " InpSizeBytes=" << input->getInpSizeBytes()
                << " SlotType=" << input->getSlotType().getType() << std::endl;

            inputs.push_back(input);
        }
        else if (choice == 'o') {
            int outLenBits, outOffset, outSizeBytes;
            std::string slotTypeStr;
            std::cout << "Enter OutLenBits, OutOffset, OutSizeBytes, SlotType (Digital/Analog) ";
            std::cout << "OutLenBits= ";
            std::cin >> outLenBits;
            std::cout << "OutOffset= ";
            std::cin >> outOffset;
            std::cout << "OutSizeBytes= ";
            std::cin >> outSizeBytes;
            std::cout << "SlotType= ";
            std::cin >> slotTypeStr;

            // Validate SlotType input
            SlotType slotType(slotTypeStr);
            while (slotType.getType() != "Digital" && slotType.getType() != "Analog") {
                std::cout << "Invalid SlotType. Please enter 'Digital' or 'Analog': ";
                std::cin >> slotTypeStr;
                slotType = SlotType(slotTypeStr);
            }

            OutputFactoryImpl factory;
            Output* output = factory.createOutput(outLenBits, outOffset, outSizeBytes, slotType);

            std::cout << "Created output: OutLenBits=" << output->getOutLenBits()
                << " OutOffset=" << output->getOutOffset()
                << " OutSizeBytes=" << output->getOutSizeBytes()
                << " SlotType=" << output->getSlotType().getType() << std::endl;

            outputs.push_back(output);
        }
        else if (choice != 'q') {
            std::cout << "Invalid choice. Please choose i, o, or q." << std::endl;
        }
    }

    std::cout << "Inputs:" << std::endl;
    for (Input* input : inputs) {
        std::cout << "InpLenBits=" << input->getInpLenBits()
            << " InpOffset" <<  input->getInpOffset()
            << " InpSizeBytes=" << input->getInpSizeBytes()
            << " SlotType=" << input->getSlotType().getType() << std::endl;
    }

    std::cout << "Outputs:" << std::endl;
    for (Output* output : outputs) {
        std::cout << "OutLenBits=" << output->getOutLenBits()
            << " OutOffset=" << output->getOutOffset()
            << " OutSizeBytes=" << output->getOutSizeBytes()
            << " SlotType=" << output->getSlotType().getType() << std::endl;
    }

    // Clean up memory
    for (Input* input : inputs) {
        delete input;
    }

    for (Output* output : outputs) {
        delete output;
    }

    return 0;
}