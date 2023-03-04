/*
	olc::NES - Picture Processing Unit (PPU) 2C02
	"Thanks Dad for believing computers were gonna be a big deal..." - javidx9

	License (OLC-3)
	~~~~~~~~~~~~~~~

	Copyright 2018-2019 OneLoneCoder.com

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions
	are met:

	1. Redistributions or derivations of source code must retain the above
	copyright notice, this list of conditions and the following disclaimer.

	2. Redistributions or derivative works in binary form must reproduce
	the above copyright notice. This list of conditions and the following
	disclaimer must be reproduced in the documentation and/or other
	materials provided with the distribution.

	3. Neither the name of the copyright holder nor the names of its
	contributors may be used to endorse or promote products derived
	from this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
	A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
	HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
	LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
	DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
	THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


	Relevant Video: https://youtu.be/-THeUXqR3zY

	Links
	~~~~~
	YouTube:	https://www.youtube.com/javidx9
				https://www.youtube.com/javidx9extra
	Discord:	https://discord.gg/WhwHUMV
	Twitter:	https://www.twitter.com/javidx9
	Twitch:		https://www.twitch.tv/javidx9
	GitHub:		https://www.github.com/onelonecoder
	Patreon:	https://www.patreon.com/javidx9
	Homepage:	https://www.onelonecoder.com

	Author
	~~~~~~
	David Barr, aka javidx9, ©OneLoneCoder 2019
*/

#pragma once
#include <cstdint>
#include <memory>

#include "olcPixelGameEngine.h"

#include "Cartridge.h"

class olc2C02
{
public:
	olc2C02();
	~olc2C02();

private:		
	uint8_t     tblName[2][1024];
	uint8_t     tblPattern[2][4096];
	uint8_t		tblPalette[32];

private:
	olc::Pixel  palScreen[0x40];
	// In Video
	// olc::Sprite sprScreen = olc::Sprite(256, 240);
	// olc::Sprite sprNameTable[2] = { olc::Sprite(256, 240), olc::Sprite(256, 240) };
	// olc::Sprite sprPatternTable[2] = { olc::Sprite(128, 128), olc::Sprite(128, 128) };

	// Changed To for API breaking subsequent PGE Update
	olc::Sprite* sprScreen;
	olc::Sprite* sprNameTable[2];
	olc::Sprite* sprPatternTable[2];

public:
	// Debugging Utilities
	olc::Sprite& GetScreen();
	olc::Sprite& GetNameTable(uint8_t i);
	olc::Sprite& GetPatternTable(uint8_t i, uint8_t palette);

	olc::Pixel& GetColourFromPaletteRam(uint8_t palette, uint8_t pixel);

	bool frame_complete = false;

private:

	union
	{
		struct
		{
			uint8_t unused : 5;
			uint8_t sprite_overflow : 1;
			uint8_t sprite_zero_hit : 1;
			uint8_t vertical_blank : 1;
		};

		uint8_t reg;
	} status;


	union
	{
		struct
		{
			uint8_t grayscale : 1;
			uint8_t render_background_left : 1;
			uint8_t render_sprites_left : 1;
			uint8_t render_background : 1;
			uint8_t render_sprites : 1;
			uint8_t enhance_red : 1;
			uint8_t enhance_green : 1;
			uint8_t enhance_blue : 1;
		};

		uint8_t reg;
	} mask;

	union PPUCTRL
	{
		struct
		{
			uint8_t nametable_x : 1;
			uint8_t nametable_y : 1;
			uint8_t increment_mode : 1;
			uint8_t pattern_sprite : 1;
			uint8_t pattern_background : 1;
			uint8_t sprite_size : 1;
			uint8_t slave_mode : 1; // unused
			uint8_t enable_nmi : 1;
		};

		uint8_t reg;
	} control;

	union loopy_register
	{
		// Credit to Loopy for working this out :D
		struct
		{

			uint16_t coarse_x : 5;
			uint16_t coarse_y : 5;
			uint16_t nametable_x : 1;
			uint16_t nametable_y : 1;
			uint16_t fine_y : 3;
			uint16_t unused : 1;
		};

		uint16_t reg = 0x0000;
	};
	
	
	loopy_register vram_addr; // Active "pointer" address into nametable to extract background tile info
	loopy_register tram_addr; // Temporary store of information to be "transferred" into "pointer" at various times

	// Pixel offset horizontally
	uint8_t fine_x = 0x00;

	// Internal communications
	uint8_t address_latch = 0x00;
	uint8_t ppu_data_buffer = 0x00;

	// Pixel "dot" position information
	int16_t scanline = 0;
	int16_t cycle = 0;

	// Background rendering =========================================
	uint8_t bg_next_tile_id     = 0x00;
	uint8_t bg_next_tile_attrib = 0x00;
	uint8_t bg_next_tile_lsb    = 0x00;
	uint8_t bg_next_tile_msb    = 0x00;
	uint16_t bg_shifter_pattern_lo = 0x0000;
	uint16_t bg_shifter_pattern_hi = 0x0000;
	uint16_t bg_shifter_attrib_lo  = 0x0000;
	uint16_t bg_shifter_attrib_hi  = 0x0000;


	// Foreground "Sprite" rendering ================================
	// The OAM is an additional memory internal to the PPU. It is
	// not connected via the any bus. It stores the locations of
	// 64off 8x8 (or 8x16) tiles to be drawn on the next frame.
	struct sObjectAttributeEntry
	{
		uint8_t y;			// Y position of sprite
		uint8_t id;			// ID of tile from pattern memory
		uint8_t attribute;	// Flags define how sprite should be rendered
		uint8_t x;			// X position of sprite
	} OAM[64];

	// A register to store the address when the CPU manually communicates
	// with OAM via PPU registers. This is not commonly used because it 
	// is very slow, and instead a 256-Byte DMA transfer is used. See
	// the Bus header for a description of this.
	uint8_t oam_addr = 0x00;


	sObjectAttributeEntry spriteScanline[8];
	uint8_t sprite_count;
	uint8_t sprite_shifter_pattern_lo[8];
	uint8_t sprite_shifter_pattern_hi[8];

	// Sprite Zero Collision Flags
	bool bSpriteZeroHitPossible = false;
	bool bSpriteZeroBeingRendered = false;

	// The OAM is conveniently package above to work with, but the DMA
    // mechanism will need access to it for writing one byute at a time
public:
	uint8_t* pOAM = (uint8_t*)OAM;


public:
	// Communications with Main Bus
	uint8_t cpuRead(uint16_t addr, bool rdonly = false);
	void    cpuWrite(uint16_t addr, uint8_t  data);

	// Communications with PPU Bus
	uint8_t ppuRead(uint16_t addr, bool rdonly = false);
	void    ppuWrite(uint16_t addr, uint8_t data);

private:
	// The Cartridge or "GamePak"
	std::shared_ptr<Cartridge> cart;

public:
	// Interface
	void ConnectCartridge(const std::shared_ptr<Cartridge>& cartridge);
	void clock();
	void reset();
	bool nmi = false;
};

