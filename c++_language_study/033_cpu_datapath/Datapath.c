#include "Datapath.h"

static word m[MEMORY_SIZE];
static word regfile[REGISTER_NUM];
static word acc;

//0:0		0		inst
//1:3		001		add r1 r2 r3	
//4:15		4:7		r1
//			8:11	r2
//			11:15	r3
void exec001(bus12 ibus)
{
	bus4 rfnr1b4 =
				{
					ibus.wires[0],
					ibus.wires[1],
					ibus.wires[2],
					ibus.wires[3]
				};

	bus16 r1w = fetch_regfile
				(
					rfnr1b4
				);
	
	word r2w = 
	fetch_regfile
	(
		ibus.wires[4],
		ibus.wires[5],
		ibus.wires[6],
		ibus.wires[7]
	);

	IALU(0, 0, 0, r1w, r2w);

	word res = fetch_acc();

	write_regfile(res, b12, b13, b14, b15);
}


// ALU control specification
// cw1 cw2 cw3
//  0   0   0	ADD
//  0   0   1	SUB
//  0   1   0	MUL
//  0   1   1	DIV
//  1   0   0	INV
void IALU
(
	bus3 cbus, 
	bus16 ip1bus, 
	bus16 ip2bus
)
{
	if (!cw1 && !cw2 && !cw3) 
	{
		int res = intpwi(w1) + intpwi(w2);
		write_acc(wrpiw(res));
		return;
	}
	if (!cw1 && !cw2 && cw3)
	{
		int res = intpwi(w1) - intpwi(w2);
		write_acc(wrpiw(res));
		return;
	}
	if (!cw1 && cw2 && !cw3)
	{
		int res = intpwi(w1) * intpwi(w2);
		write_acc(wrpiw(res));
		return;
	}
	if (!cw1 && cw2 && cw3)
	{
		int res = intpwi(w1) / intpwi(w2);
		write_acc(wrpiw(res));
		return;
	}
	if (!cw1 && cw2 && cw3)
	{
		int res = intpwi(w1) * -1;
		write_acc(wrpiw(res));
		return;
	}
}

bus16 fetch_mem(bus8 mabus8)
{
	return	
		distribute_word_bus16
		(
			m
			[
				demux8
				(
					mabus8
				)
			]
		)
	;
}

bus16 fetch_regfile(bus4 rfnb4)
{
	return
		distribute_word_bus16
		(
			regfile
			[
				demux4
				(
					rfnb4
				)
			]
		)	
	;
}

bus16 fetch_acc()
{
	return
		distribute_word_bus16
		(
			acc
		)
	;
}

void write_memory(bus16 wdb16, bus8 mab8)
{
	m
	[
		demux8
		(
			mab8
		)
	] = assemble_bus16_word
		(
			wdb16
		)
	;
}

void write_regfile(bus16 wdb16, bus4 rfnb4)
{
	regfile
	[
		demux4
		(
			rfnb4
		)
	] = assemble_bus16_word
		(
			wdb16
		)
	;
}

void write_acc(bus16 wdb16)
{
	acc	=	assemble_bus16_word
			(
				wdb16
			)
	;
}

//0		sign field
//1:15	quantity field
int intpwi(word w)
{
	return 0;
}

//0		sign field
//1:5	exponent field
//6:15	mantissa field
float intpwf(word w)
{
	return 0.0f;
}

//0		sign field
//1:15	quantity field
word wrpiw(int i)
{
}

//0		sign field
//1:5	exponent field
//6:15	mantissa field
word wrpfw(float f)
{
}

word assemble_bus16_word(bus16 b16)
{
	word w = 
	{
		b16.wires[0],
		b16.wires[1],
		b16.wires[2],
		b16.wires[3],
		b16.wires[4],
		b16.wires[5],
		b16.wires[6],
		b16.wires[7],
		b16.wires[8],
		b16.wires[9],
		b16.wires[10],
		b16.wires[11],
		b16.wires[12],
		b16.wires[13],
		b16.wires[14],
		b16.wires[15]
	};

	return w;
}

bus16 distribute_word_bus16(word w)
{
	bus16 b16 =
	{
		w.bits[0],
		w.bits[1],
		w.bits[2],
		w.bits[3],
		w.bits[4],
		w.bits[5],
		w.bits[6],
		w.bits[7],
		w.bits[8],
		w.bits[9],
		w.bits[10],
		w.bits[11],
		w.bits[12],
		w.bits[13],
		w.bits[14],
		w.bits[15],
	};

	return b16;
}

// [3] [2] [1] [0]
wire demux4(bus4 ib4)
{
	wire iw = 0;

	iw += 1 * w0;
	iw += 2 * w1;
	iw += 4 * w2;
	iw += 8 * w3;

	return iw;
}

// [7] [6] [5] [4] [3] [2] [1] [0]
wire demux8(bus8 ib8)
{
	wire iw = 0;

	iw += 1 * w0;
	iw += 2 * w1;
	iw += 4 * w2;
	iw += 8 * w3;
	iw += 16 * w4;
	iw += 32 * w5;
	iw += 64 * w6;
	iw += 128 * w7;

	return iw;
}

bus2 halfadder(wire a, wire b)
{
	return bus2();
}

bus2 fulladder(wire a, wire b, wire c)
{
	return bus2();
}


