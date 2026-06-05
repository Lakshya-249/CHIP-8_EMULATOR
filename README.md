# CHIP-8 Emulator

A CHIP-8 emulator built from scratch that accurately reproduces the behavior of the original CHIP-8 virtual machine. The emulator implements the full execution cycle, memory management, graphics rendering, keypad input, timers, and ROM loading, allowing classic CHIP-8 programs and games to run as intended.

---

## Features

- Complete CHIP-8 instruction set implementation
- 4 KB memory model
- 16 general-purpose registers (V0–VF)
- Stack and subroutine support
- Delay and sound timers
- 64×32 monochrome display
- 16-key hexadecimal keypad
- Sprite rendering with collision detection
- ROM loading and execution
- Adjustable emulation speed
- Cross-platform architecture

---

## Architecture

| Component | Description |
|------------|------------|
| Memory | 4 KB |
| Registers | V0–VF |
| Index Register | I |
| Program Counter | PC |
| Stack | 16 Levels |
| Display | 64×32 Pixels |
| Input | 16-Key Hex Keypad |
| Timers | Delay Timer & Sound Timer |

---

## Memory Layout

```text
0x000 - 0x1FF   Reserved for interpreter
0x050 - 0x09F   Font set
0x200 - 0xFFF   Program ROM area
```

---

## Execution Cycle

```text
Fetch Opcode
      ↓
Decode Opcode
      ↓
Execute Instruction
      ↓
Update Timers
      ↓
Render Frame
```

---

## Building

### Linux

```bash
mkdir build
cd build

cmake ..
make
```

### Windows

```bash
mkdir build
cd build

cmake ..
cmake --build . --config Release
```

---

## Running

```bash
./chip8 path/to/rom.ch8
```

Example:

```bash
./chip8 roms/PONG.ch8
```

---

## Key Mapping

| CHIP-8 | Keyboard |
|---------|----------|
| 1 | 1 |
| 2 | 2 |
| 3 | 3 |
| C | 4 |
| 4 | Q |
| 5 | W |
| 6 | E |
| D | R |
| 7 | A |
| 8 | S |
| 9 | D |
| E | F |
| A | Z |
| 0 | X |
| B | C |
| F | V |

---

## Supported ROMs

- Pong
- Tetris
- Space Invaders
- IBM Logo
- Maze
- Breakout

---

## Project Goals

This project was created to explore:

- Emulator development
- CPU architecture fundamentals
- Instruction decoding
- Memory management
- Graphics rendering
- Event-driven input systems
- Low-level systems programming

---

## Future Improvements

- Super CHIP (SCHIP) support
- Save states
- Debugger
- Opcode tracing
- Breakpoints
- WebAssembly build
- Performance profiling

---

## License

MIT License

---

Building a CHIP-8 emulator is a classic systems programming challenge that provides practical experience with CPU design, memory organization, instruction execution, graphics pipelines, and real-time input handling.
