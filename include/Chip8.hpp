#ifndef CHIP8_HPP
#define CHIP8_HPP

#include <cstdint>
#include <random>

class Chip8 {
    private:
        uint8_t registers[16];
        uint8_t memory[4096];
        uint16_t index; // Index register
        uint16_t pc;
        uint16_t stack[16];
        uint8_t sp;
        uint8_t delay_timer;
        uint8_t sound_timer;
        uint16_t opcode;

        std::default_random_engine rand_gen;
        std::uniform_int_distribution<uint8_t> rand_byte;

        typedef void (Chip8::*Chip8Func)() ;
        Chip8Func table[0xF + 1];
        Chip8Func table0[0xE + 1];
        Chip8Func table8[0xE + 1];
        Chip8Func tableE[0xE + 1];
        Chip8Func tableF[0x65 + 1];


    public:
        Chip8();

        uint8_t keypad[16];
        uint32_t display[64 * 32];

        void LoadROM(const char* filename);
        void Cycle();

        void Table0();
        void Table8();
        void TableE();
        void TableF();

        void OP_NULL();
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
        void OP_8xy5(); // Set Vx = Vx - Vy.
        void OP_8xy6(); // Set Vx = Vx SHR 1.
        void OP_8xy7(); // Set Vx = Vy - Vx.
        void OP_8xyE(); // Set Vx = Vx SHL 1.
        void OP_9xy0(); // Skip next instruction if Vx != Vy.
        void OP_Annn(); // Set I = nnn.
        void OP_Bnnn(); // Jump to location nnn + V0.
        void OP_Cxkk(); // Set Vx = random byte AND kk.
        void OP_Dxyn(); // Display n-byte sprite starting at memory location I at (Vx, Vy), set VF = collision.
        void OP_Ex9E(); // Skip next instruction if key with the value of Vx is pressed.
        void OP_ExA1(); // Skip next instruction if key with the value of Vx is not pressed.
        void OP_Fx07(); // Set Vx = delay timer value.
        void OP_Fx0A(); // Wait for a key press, store the value of the key in Vx.
        void OP_Fx15(); // Set delay timer = Vx.
        void OP_Fx18(); // Set sound timer = Vx.
        void OP_Fx1E(); // Set I = I + Vx.
        void OP_Fx29(); // Set I = location of sprite for digit Vx.
        void OP_Fx33(); // Store BCD representation of Vx in memory locations I, I+1, and I+2.
        void OP_Fx55(); // Store registers V0 through Vx in memory starting at location I.
        void OP_Fx65(); // Read registers V0 through Vx from memory starting at location I.

};

#endif // CHIP8_HPP
