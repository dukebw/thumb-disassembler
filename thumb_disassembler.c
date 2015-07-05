#include "allheads.h"

#define ARM_INSTRUCTION_LENGTH 4
#define THUMB_INSTRUCTION_LENGTH 2

#define MOV_IMMEDIATE 0x1D

int main(int argc, char **argv)
{
    Stopif(argc < 2, return 1, "No input");

    FILE *InputBinary = fopen(argv[1], "rb");
    Stopif(InputBinary == 0, return 1, "File does not exist");

    uint32 NextInstruction;
    uint32 InstructionLength = ARM_INSTRUCTION_LENGTH;
    while (fread(&NextInstruction, InstructionLength, 1, InputBinary))
    {
        if (InstructionLength == ARM_INSTRUCTION_LENGTH)
        {
            uint32 InstructionEncoding = ((NextInstruction >> 21) & 0x7F);

            switch (InstructionEncoding)
            {
                case MOV_IMMEDIATE:
                {
                    printf("mov");
                    // TODO(brendan): condition codes
                    break;
                }
                default:
                {
                    Stopif(true, return 1, "Bad Instruction");
                    break;
                }
            }
        }
        else
        {
        }
    }
}
