#ifndef CHIP8_HPP
#define CHIP8_HPP

#include <cstdint>
#include <random>

class Chip8 {
    private:
        uint8_t registers[16];
        uint8_t memory[4096];
        uint16_t index;
        uint16_t pc;
        uint16_t stack[16];
        uint8_t sp;
        uint8_t delay_timer;
        uint8_t sound_timer;
        uint8_t keypad[16];
        uint32_t display[64 * 32];
        uint16_t opcode;

        std::default_random_engine rand_gen;
        std::uniform_int_distribution<uint8_t> rand_byte;

    public:
        Chip8();
        ~Chip8();

        void LoadROM(const char* filename);

        void OP_00E0(); // Clear the display.
        void OP_00EE(); // Return from a subroutine.
        void OP_1nnn(); // Jump to location nnn.
        void OP_2nnn(); // Call subroutine at nnn.
        void OP_3xkk(); // Skip next instruction if Vx = kk.
        void OP_4xkk(); // Skip next instruction if Vx != kk.
        void OP_5xy0(); // Skip next instruction if Vx = Vy.
        void OP_6xkk(); // Set Vx = kk.
        void OP_7xkk(); // Set Vx = Vx + kk.
        void OP_8xy0(); // Set Vx = Vy.
        void OP_8xy1(); // Set Vx = Vx OR Vy.
        void OP_8xy2(); // Set Vx = Vx AND Vy.
        void OP_8xy3(); // Set Vx = Vx XOR Vy.
        void OP_8xy4(); // Set Vx = Vx + Vy.

};

#endif // CHIP8_HPP
