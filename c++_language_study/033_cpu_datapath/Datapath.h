#pragma once

#define WORD_SIZE (16)
#define MEMORY_SIZE (256)
#define REGISTER_NUM (16)

typedef char bit;
typedef char wire;

typedef struct byte		{bit bits[8];}			byte;

typedef struct word		{bit bits[WORD_SIZE];}	word;

typedef struct bus2		{wire wires[2];}		bus2;
typedef struct bus3		{wire wires[3];}		bus3;
typedef struct bus4		{wire wires[4];}		bus4;
typedef struct bus8		{wire wires[8];}		bus8;
typedef struct bus13	{wire wires[12];}		bus12;
typedef struct bus16	{wire wires[16];}		bus16;

void exec001(bus12);
void IALU(bus3, bus16, bus16);

bus16 fetch_mem(bus8);
bus16 fetch_regfile(bus4);
bus16 fetch_acc();

void write_memory(bus16, bus8);
void write_regfile(bus16, bus4);
void write_acc(bus16);

int intpwi(word);
float intpwf(word);

word wrpiw(int);
word wrpfw(float);

word assemble_bus16_word(bus16);
bus16 distribute_word_bus16(word);

wire demux4(bus4);
wire demux8(bus8);

bus2 halfadder(wire, wire);
bus2 fulladder(wire, wire, wire);