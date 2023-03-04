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


	Relevant Video: https://youtu.be/xdzOvpYPmGE

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

#include "olc2C02.h"

olc2C02::olc2C02()
{
	palScreen[0x00] = olc::Pixel(84, 84, 84);
	palScreen[0x01] = olc::Pixel(0, 30, 116);
	palScreen[0x02] = olc::Pixel(8, 16, 144);
	palScreen[0x03] = olc::Pixel(48, 0, 136);
	palScreen[0x04] = olc::Pixel(68, 0, 100);
	palScreen[0x05] = olc::Pixel(92, 0, 48);
	palScreen[0x06] = olc::Pixel(84, 4, 0);
	palScreen[0x07] = olc::Pixel(60, 24, 0);
	palScreen[0x08] = olc::Pixel(32, 42, 0);
	palScreen[0x09] = olc::Pixel(8, 58, 0);
	palScreen[0x0A] = olc::Pixel(0, 64, 0);
	palScreen[0x0B] = olc::Pixel(0, 60, 0);
	palScreen[0x0C] = olc::Pixel(0, 50, 60);
	palScreen[0x0D] = olc::Pixel(0, 0, 0);
	palScreen[0x0E] = olc::Pixel(0, 0, 0);
	palScreen[0x0F] = olc::Pixel(0, 0, 0);

	palScreen[0x10] = olc::Pixel(152, 150, 152);
	palScreen[0x11] = olc::Pixel(8, 76, 196);
	palScreen[0x12] = olc::Pixel(48, 50, 236);
	palScreen[0x13] = olc::Pixel(92, 30, 228);
	palScreen[0x14] = olc::Pixel(136, 20, 176);
	palScreen[0x15] = olc::Pixel(160, 20, 100);
	palScreen[0x16] = olc::Pixel(152, 34, 32);
	palScreen[0x17] = olc::Pixel(120, 60, 0);
	palScreen[0x18] = olc::Pixel(84, 90, 0);
	palScreen[0x19] = olc::Pixel(40, 114, 0);
	palScreen[0x1A] = olc::Pixel(8, 124, 0);
	palScreen[0x1B] = olc::Pixel(0, 118, 40);
	palScreen[0x1C] = olc::Pixel(0, 102, 120);
	palScreen[0x1D] = olc::Pixel(0, 0, 0);
	palScreen[0x1E] = olc::Pixel(0, 0, 0);
	palScreen[0x1F] = olc::Pixel(0, 0, 0);

	palScreen[0x20] = olc::Pixel(236, 238, 236);
	palScreen[0x21] = olc::Pixel(76, 154, 236);
	palScreen[0x22] = olc::Pixel(120, 124, 236);
	palScreen[0x23] = olc::Pixel(176, 98, 236);
	palScreen[0x24] = olc::Pixel(228, 84, 236);
	palScreen[0x25] = olc::Pixel(236, 88, 180);
	palScreen[0x26] = olc::Pixel(236, 106, 100);
	palScreen[0x27] = olc::Pixel(212, 136, 32);
	palScreen[0x28] = olc::Pixel(160, 170, 0);
	palScreen[0x29] = olc::Pixel(116, 196, 0);
	palScreen[0x2A] = olc::Pixel(76, 208, 32);
	palScreen[0x2B] = olc::Pixel(56, 204, 108);
	palScreen[0x2C] = olc::Pixel(56, 180, 204);
	palScreen[0x2D] = olc::Pixel(60, 60, 60);
	palScreen[0x2E] = olc::Pixel(0, 0, 0);
	palScreen[0x2F] = olc::Pixel(0, 0, 0);

	palScreen[0x30] = olc::Pixel(236, 238, 236);
	palScreen[0x31] = olc::Pixel(168, 204, 236);
	palScreen[0x32] = olc::Pixel(188, 188, 236);
	palScreen[0x33] = olc::Pixel(212, 178, 236);
	palScreen[0x34] = olc::Pixel(236, 174, 236);
	palScreen[0x35] = olc::Pixel(236, 174, 212);
	palScreen[0x36] = olc::Pixel(236, 180, 176);
	palScreen[0x37] = olc::Pixel(228, 196, 144);
	palScreen[0x38] = olc::Pixel(204, 210, 120);
	palScreen[0x39] = olc::Pixel(180, 222, 120);
	palScreen[0x3A] = olc::Pixel(168, 226, 144);
	palScreen[0x3B] = olc::Pixel(152, 226, 180);
	palScreen[0x3C] = olc::Pixel(160, 214, 228);
	palScreen[0x3D] = olc::Pixel(160, 162, 160);
	palScreen[0x3E] = olc::Pixel(0, 0, 0);
	palScreen[0x3F] = olc::Pixel(0, 0, 0);

	sprScreen = new olc::Sprite(256, 240);
	sprNameTable[0] = new olc::Sprite(256, 240);
	sprNameTable[1] = new olc::Sprite(256, 240);
	sprPatternTable[0] = new olc::Sprite(128, 128);
	sprPatternTable[1] = new olc::Sprite(128, 128);
}


olc2C02::~olc2C02()
{
	delete sprScreen;
	delete sprNameTable[0];
	delete sprNameTable[1];
	delete sprPatternTable[0];
	delete sprPatternTable[1];
}

olc::Sprite& olc2C02::GetScreen()
{
	// Simply returns the current sprite holding the rendered screen
	return *sprScreen;
}



olc::Sprite& olc2C02::GetPatternTable(uint8_t i, uint8_t palette)
{
	// This function draw the CHR ROM for a given pattern table into
	// an olc::Sprite, using a specified palette. Pattern tables consist
	// of 16x16 "tiles or characters". It is independent of the running
	// emulation and using it does not change the systems state, though
	// it gets all the data it needs from the live system. Consequently,
	// if the game has not yet established palettes or mapped to relevant
	// CHR ROM banks, the sprite may look empty. This approach permits a 
	// "live" extraction of the pattern table exactly how the NES, and 
	// ultimately the player would see it.

	// A tile consists of 8x8 pixels. On the NES, pixels are 2 bits, which
	// gives an index into 4 different colours of a specific palette. There
	// are 8 palettes to choose from. Colour "0" in each palette is effectively
	// considered transparent, as those locations in memory "mirror" the global
	// background colour being used. This mechanics of this are shown in 
	// detail in ppuRead() & ppuWrite()

	// Characters on NES
	// ~~~~~~~~~~~~~~~~~
	// The NES stores characters using 2-bit pixels. These are not stored sequentially
	// but in singular bit planes. For example:
	//
 	// 2-Bit Pixels       LSB Bit Plane     MSB Bit Plane
	// 0 0 0 0 0 0 0 0	  0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0
	// 0 1 1 0 0 1 1 0	  0 1 1 0 0 1 1 0   0 0 0 0 0 0 0 0
	// 0 1 2 0 0 2 1 0	  0 1 1 0 0 1 1 0   0 0 1 0 0 1 0 0
	// 0 0 0 0 0 0 0 0 =  0 0 0 0 0 0 0 0 + 0 0 0 0 0 0 0 0
	// 0 1 1 0 0 1 1 0	  0 1 1 0 0 1 1 0   0 0 0 0 0 0 0 0
	// 0 0 1 1 1 1 0 0	  0 0 1 1 1 1 0 0   0 0 0 0 0 0 0 0
	// 0 0 0 2 2 0 0 0	  0 0 0 1 1 0 0 0   0 0 0 1 1 0 0 0
	// 0 0 0 0 0 0 0 0	  0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0
	//
	// The planes are stored as 8 bytes of LSB, followed by 8 bytes of MSB

	// Loop through all 16x16 tiles
	for (uint16_t nTileY = 0; nTileY < 16; nTileY++)
	{
		for (uint16_t nTileX = 0; nTileX < 16; nTileX++)
		{
			// Convert the 2D tile coordinate into a 1D offset into the pattern
			// table memory.
			uint16_t nOffset = nTileY * 256 + nTileX * 16;

			// Now loop through 8 rows of 8 pixels
			for (uint16_t row = 0; row < 8; row++)
			{
				// For each row, we need to read both bit planes of the character
				// in order to extract the least significant and most significant 
				// bits of the 2 bit pixel value. in the CHR ROM, each character
				// is stored as 64 bits of lsb, followed by 64 bits of msb. This
				// conveniently means that two corresponding rows are always 8
				// bytes apart in memory.
				uint8_t tile_lsb = ppuRead(i * 0x1000 + nOffset + row + 0x0000);
				uint8_t tile_msb = ppuRead(i * 0x1000 + nOffset + row + 0x0008);


				// Now we have a single row of the two bit planes for the character
				// we need to iterate through the 8-bit words, combining them to give
				// us the final pixel index
				for (uint16_t col = 0; col < 8; col++)
				{
					// We can get the index value by simply adding the bits together
					// but we're only interested in the lsb of the row words because...
					uint8_t pixel = (tile_lsb & 0x01) + (tile_msb & 0x01);

					// ...we will shift the row words 1 bit right for each column of
					// the character.
					tile_lsb >>= 1; tile_msb >>= 1;

					// Now we know the location and NES pixel value for a specific location
					// in the pattern table, we can translate that to a screen colour, and an
					// (x,y) location in the sprite
					sprPatternTable[i]->SetPixel
					(
						nTileX * 8 + (7 - col), // Because we are using the lsb of the row word first
												// we are effectively reading the row from right
												// to left, so we need to draw the row "backwards"
						nTileY * 8 + row, 
						GetColourFromPaletteRam(palette, pixel)
					);
				}
			}
		}
	}

	// Finally return the updated sprite representing the pattern table
	return *sprPatternTable[i];
}


olc::Pixel& olc2C02::GetColourFromPaletteRam(uint8_t palette, uint8_t pixel)
{
	// This is a convenience function that takes a specified palette and pixel
	// index and returns the appropriate screen colour.
	// "0x3F00"       - Offset into PPU addressable range where palettes are stored
	// "palette << 2" - Each palette is 4 bytes in size
	// "pixel"        - Each pixel index is either 0, 1, 2 or 3
	// "& 0x3F"       - Stops us reading beyond the bounds of the palScreen array
	return palScreen[ppuRead(0x3F00 + (palette << 2) + pixel) & 0x3F];

	// Note: We dont access tblPalette directly here, instead we know that ppuRead()
	// will map the address onto the seperate small RAM attached to the PPU bus.
}

olc::Sprite& olc2C02::GetNameTable(uint8_t i)
{
	// As of now unused, but a placeholder for nametable visualisation in teh future
	return *sprNameTable[i];
}


uint8_t olc2C02::cpuRead(uint16_t addr, bool rdonly)
{
	uint8_t data = 0x00;

	if (rdonly)
	{
		// Reading from PPU registers can affect their contents
		// so this read only option is used for examining the
		// state of the PPU without changing its state. This is
		// really only used in debug mode.
		switch (addr)
		{
		case 0x0000: // Control
			data = control.reg;
			break;
		case 0x0001: // Mask
			data = mask.reg;
			break;
		case 0x0002: // Status
			data = status.reg;
			break;
		case 0x0003: // OAM Address
			break;
		case 0x0004: // OAM Data
			break;
		case 0x0005: // Scroll
			break;
		case 0x0006: // PPU Address
			break;
		case 0x0007: // PPU Data
			break;
		}
	}
	else
	{
		// These are the live PPU registers that repsond
		// to being read from in various ways. Note that not
		// all the registers are capable of being read from
		// so they just return 0x00
		switch (addr)
		{
			// Control - Not readable
		case 0x0000: break;
		
			// Mask - Not Readable
		case 0x0001: break;
		
			// Status
		case 0x0002:
			// Reading from the status register has the effect of resetting
			// different parts of the circuit. Only the top three bits
			// contain status information, however it is possible that
			// some "noise" gets picked up on the bottom 5 bits which 
			// represent the last PPU bus transaction. Some games "may"
			// use this noise as valid data (even though they probably
			// shouldn't)
			data = (status.reg & 0xE0) | (ppu_data_buffer & 0x1F);

			// Clear the vertical blanking flag
			status.vertical_blank = 0;

			// Reset Loopy's Address latch flag
			address_latch = 0;
			break;

			// OAM Address
		case 0x0003: break;

			// OAM Data
		case 0x0004: break;

			// Scroll - Not Readable
		case 0x0005: break;

			// PPU Address - Not Readable
		case 0x0006: break;

			// PPU Data
		case 0x0007: 
			// Reads from the NameTable ram get delayed one cycle, 
			// so output buffer which contains the data from the 
			// previous read request
			data = ppu_data_buffer;
			// then update the buffer for next time
			ppu_data_buffer = ppuRead(vram_addr.reg);
			// However, if the address was in the palette range, the
			// data is not delayed, so it returns immediately
			if (vram_addr.reg >= 0x3F00) data = ppu_data_buffer;
			// All reads from PPU data automatically increment the nametable
			// address depending upon the mode set in the control register.
			// If set to vertical mode, the increment is 32, so it skips
			// one whole nametable row; in horizontal mode it just increments
			// by 1, moving to the next column
			vram_addr.reg += (control.increment_mode ? 32 : 1);
			break;
		}
	}

	return data;
}

void olc2C02::cpuWrite(uint16_t addr, uint8_t data)
{
	switch (addr)
	{
	case 0x0000: // Control
		control.reg = data;
		tram_addr.nametable_x = control.nametable_x;
		tram_addr.nametable_y = control.nametable_y;
		break;
	case 0x0001: // Mask
		mask.reg = data;
		break;
	case 0x0002: // Status
		break;
	case 0x0003: // OAM Address
		break;
	case 0x0004: // OAM Data
		break;
	case 0x0005: // Scroll
		if (address_latch == 0)
		{
			// First write to scroll register contains X offset in pixel space
			// which we split into coarse and fine x values
			fine_x = data & 0x07;
			tram_addr.coarse_x = data >> 3;
			address_latch = 1;
		}
		else
		{
			// First write to scroll register contains Y offset in pixel space
			// which we split into coarse and fine Y values
			tram_addr.fine_y = data & 0x07;
			tram_addr.coarse_y = data >> 3;
			address_latch = 0;
		}
		break;
	case 0x0006: // PPU Address
		if (address_latch == 0)
		{
			// PPU address bus can be accessed by CPU via the ADDR and DATA
			// registers. The fisrt write to this register latches the high byte
			// of the address, the second is the low byte. Note the writes
			// are stored in the tram register...
			tram_addr.reg = (uint16_t)((data & 0x3F) << 8) | (tram_addr.reg & 0x00FF);
			address_latch = 1;
		}
		else
		{
			// ...when a whole address has been written, the internal vram address
			// buffer is updated. Writing to the PPU is unwise during rendering
			// as the PPU will maintam the vram address automatically whilst
			// rendering the scanline position.
			tram_addr.reg = (tram_addr.reg & 0xFF00) | data;
			vram_addr = tram_addr;
			address_latch = 0;
		}
		break;
	case 0x0007: // PPU Data
		ppuWrite(vram_addr.reg, data);
		// All writes from PPU data automatically increment the nametable
		// address depending upon the mode set in the control register.
		// If set to vertical mode, the increment is 32, so it skips
		// one whole nametable row; in horizontal mode it just increments
		// by 1, moving to the next column
		vram_addr.reg += (control.increment_mode ? 32 : 1);
		break;
	}
}

uint8_t olc2C02::ppuRead(uint16_t addr, bool rdonly)
{
	uint8_t data = 0x00;
	addr &= 0x3FFF;

	if (cart->ppuRead(addr, data))
	{

	}
	else if (addr >= 0x0000 && addr <= 0x1FFF)
	{
		// If the cartridge cant map the address, have
		// a physical location ready here
		data = tblPattern[(addr & 0x1000) >> 12][addr & 0x0FFF];
	}
	else if (addr >= 0x2000 && addr <= 0x3EFF)
	{
		addr &= 0x0FFF;

		if (cart->mirror == Cartridge::MIRROR::VERTICAL)
		{
			// Vertical
			if (addr >= 0x0000 && addr <= 0x03FF)
				data = tblName[0][addr & 0x03FF];
			if (addr >= 0x0400 && addr <= 0x07FF)
				data = tblName[1][addr & 0x03FF];
			if (addr >= 0x0800 && addr <= 0x0BFF)
				data = tblName[0][addr & 0x03FF];
			if (addr >= 0x0C00 && addr <= 0x0FFF)
				data = tblName[1][addr & 0x03FF];
		}
		else if (cart->mirror == Cartridge::MIRROR::HORIZONTAL)
		{
			// Horizontal
			if (addr >= 0x0000 && addr <= 0x03FF)
				data = tblName[0][addr & 0x03FF];
			if (addr >= 0x0400 && addr <= 0x07FF)
				data = tblName[0][addr & 0x03FF];
			if (addr >= 0x0800 && addr <= 0x0BFF)
				data = tblName[1][addr & 0x03FF];
			if (addr >= 0x0C00 && addr <= 0x0FFF)
				data = tblName[1][addr & 0x03FF];
		}
	}
	else if (addr >= 0x3F00 && addr <= 0x3FFF)
	{
		addr &= 0x001F;
		if (addr == 0x0010) addr = 0x0000;
		if (addr == 0x0014) addr = 0x0004;
		if (addr == 0x0018) addr = 0x0008;
		if (addr == 0x001C) addr = 0x000C;
		data = tblPalette[addr] & (mask.grayscale ? 0x30 : 0x3F);
	}

	return data;
}

void olc2C02::ppuWrite(uint16_t addr, uint8_t data)
{
	addr &= 0x3FFF;

	if (cart->ppuWrite(addr, data))
	{

	}
	else if (addr >= 0x0000 && addr <= 0x1FFF)
	{
		tblPattern[(addr & 0x1000) >> 12][addr & 0x0FFF] = data;
	}
	else if (addr >= 0x2000 && addr <= 0x3EFF)
	{
		addr &= 0x0FFF;
		if (cart->mirror == Cartridge::MIRROR::VERTICAL)
		{
			// Vertical
			if (addr >= 0x0000 && addr <= 0x03FF)
				tblName[0][addr & 0x03FF] = data;
			if (addr >= 0x0400 && addr <= 0x07FF)
				tblName[1][addr & 0x03FF] = data;
			if (addr >= 0x0800 && addr <= 0x0BFF)
				tblName[0][addr & 0x03FF] = data;
			if (addr >= 0x0C00 && addr <= 0x0FFF)
				tblName[1][addr & 0x03FF] = data;
		}
		else if (cart->mirror == Cartridge::MIRROR::HORIZONTAL)
		{
			// Horizontal
			if (addr >= 0x0000 && addr <= 0x03FF)
				tblName[0][addr & 0x03FF] = data;
			if (addr >= 0x0400 && addr <= 0x07FF)
				tblName[0][addr & 0x03FF] = data;
			if (addr >= 0x0800 && addr <= 0x0BFF)
				tblName[1][addr & 0x03FF] = data;
			if (addr >= 0x0C00 && addr <= 0x0FFF)
				tblName[1][addr & 0x03FF] = data;
		}
	}
	else if (addr >= 0x3F00 && addr <= 0x3FFF)
	{
		addr &= 0x001F;
		if (addr == 0x0010) addr = 0x0000;
		if (addr == 0x0014) addr = 0x0004;
		if (addr == 0x0018) addr = 0x0008;
		if (addr == 0x001C) addr = 0x000C;
		tblPalette[addr] = data;
	}
}

void olc2C02::ConnectCartridge(const std::shared_ptr<Cartridge>& cartridge)
{
	this->cart = cartridge;
}

void olc2C02::reset()
{
	fine_x = 0x00;
	address_latch = 0x00;
	ppu_data_buffer = 0x00;
	scanline = 0;
	cycle = 0;
	bg_next_tile_id = 0x00;
	bg_next_tile_attrib = 0x00;
	bg_next_tile_lsb = 0x00;
	bg_next_tile_msb = 0x00;
	bg_shifter_pattern_lo = 0x0000;
	bg_shifter_pattern_hi = 0x0000;
	bg_shifter_attrib_lo = 0x0000;
	bg_shifter_attrib_hi = 0x0000;
	status.reg = 0x00;
	mask.reg = 0x00;
	control.reg = 0x00;
	vram_addr.reg = 0x0000;
	tram_addr.reg = 0x0000;
}

void olc2C02::clock()
{
	// As we progress through scanlines and cycles, the PPU is effectively
	// a state machine going through the motions of fetching background 
	// information and sprite information, compositing them into a pixel
	// to be output.

	// The lambda functions (functions inside functions) contain the various
	// actions to be performed depending upon the output of the state machine
	// for a given scanline/cycle combination

	// ==============================================================================
	// Increment the background tile "pointer" one tile/column horizontally
	auto IncrementScrollX = [&]()
	{
		// Note: pixel perfect scrolling horizontally is handled by the 
		// data shifters. Here we are operating in the spatial domain of 
		// tiles, 8x8 pixel blocks.
		
		// Ony if rendering is enabled
		if (mask.render_background || mask.render_sprites)
		{
			// A single name table is 32x30 tiles. As we increment horizontally
			// we may cross into a neighbouring nametable, or wrap around to
			// a neighbouring nametable
			if (vram_addr.coarse_x == 31)
			{
				// Leaving nametable so wrap address round
				vram_addr.coarse_x = 0;
				// Flip target nametable bit
				vram_addr.nametable_x = ~vram_addr.nametable_x;
			}
			else
			{
				// Staying in current nametable, so just increment
				vram_addr.coarse_x++;
			}
		}
	};

	// ==============================================================================
	// Increment the background tile "pointer" one scanline vertically
	auto IncrementScrollY = [&]()
	{
		// Incrementing vertically is more complicated. The visible nametable
		// is 32x30 tiles, but in memory there is enough room for 32x32 tiles.
		// The bottom two rows of tiles are in fact not tiles at all, they
		// contain the "attribute" information for the entire table. This is
		// information that describes which palettes are used for different 
		// regions of the nametable.
		
		// In addition, the NES doesnt scroll vertically in chunks of 8 pixels
		// i.e. the height of a tile, it can perform fine scrolling by using
		// the fine_y component of the register. This means an increment in Y
		// first adjusts the fine offset, but may need to adjust the whole
		// row offset, since fine_y is a value 0 to 7, and a row is 8 pixels high

		// Ony if rendering is enabled
		if (mask.render_background || mask.render_sprites)
		{
			// If possible, just increment the fine y offset
			if (vram_addr.fine_y < 7)
			{
				vram_addr.fine_y++;
			}
			else
			{
				// If we have gone beyond the height of a row, we need to
				// increment the row, potentially wrapping into neighbouring
				// vertical nametables. Dont forget however, the bottom two rows
				// do not contain tile information. The coarse y offset is used
				// to identify which row of the nametable we want, and the fine
				// y offset is the specific "scanline"

				// Reset fine y offset
				vram_addr.fine_y = 0;

				// Check if we need to swap vertical nametable targets
				if (vram_addr.coarse_y == 29)
				{
					// We do, so reset coarse y offset
					vram_addr.coarse_y = 0;
					// And flip the target nametable bit
					vram_addr.nametable_y = ~vram_addr.nametable_y;
				}
				else if (vram_addr.coarse_y == 31)
				{
					// In case the pointer is in the attribute memory, we
					// just wrap around the current nametable
					vram_addr.coarse_y = 0;
				}
				else
				{
					// None of the above boundary/wrapping conditions apply
					// so just increment the coarse y offset
					vram_addr.coarse_y++;
				}
			}
		}
	};

	// ==============================================================================
	// Transfer the temporarily stored horizontal nametable access information
	// into the "pointer". Note that fine x scrolling is not part of the "pointer"
	// addressing mechanism
	auto TransferAddressX = [&]()
	{
		// Ony if rendering is enabled
		if (mask.render_background || mask.render_sprites)
		{
			vram_addr.nametable_x = tram_addr.nametable_x;
			vram_addr.coarse_x    = tram_addr.coarse_x;
		}
	};

	// ==============================================================================
	// Transfer the temporarily stored vertical nametable access information
	// into the "pointer". Note that fine y scrolling is part of the "pointer"
	// addressing mechanism
	auto TransferAddressY = [&]()
	{
		// Ony if rendering is enabled
		if (mask.render_background || mask.render_sprites)
		{
			vram_addr.fine_y      = tram_addr.fine_y;
			vram_addr.nametable_y = tram_addr.nametable_y;
			vram_addr.coarse_y    = tram_addr.coarse_y;
		}
	};


	// ==============================================================================
	// Prime the "in-effect" background tile shifters ready for outputting next
	// 8 pixels in scanline.
	auto LoadBackgroundShifters = [&]()
	{	
		// Each PPU update we calculate one pixel. These shifters shift 1 bit along
		// feeding the pixel compositor with the binary information it needs. Its
		// 16 bits wide, because the top 8 bits are the current 8 pixels being drawn
		// and the bottom 8 bits are the next 8 pixels to be drawn. Naturally this means
		// the required bit is always the MSB of the shifter. However, "fine x" scrolling
		// plays a part in this too, whcih is seen later, so in fact we can choose
		// any one of the top 8 bits.
		bg_shifter_pattern_lo = (bg_shifter_pattern_lo & 0xFF00) | bg_next_tile_lsb;
		bg_shifter_pattern_hi = (bg_shifter_pattern_hi & 0xFF00) | bg_next_tile_msb;

		// Attribute bits do not change per pixel, rather they change every 8 pixels
		// but are synchronised with the pattern shifters for convenience, so here
		// we take the bottom 2 bits of the attribute word which represent which 
		// palette is being used for the current 8 pixels and the next 8 pixels, and 
		// "inflate" them to 8 bit words.
		bg_shifter_attrib_lo  = (bg_shifter_attrib_lo & 0xFF00) | ((bg_next_tile_attrib & 0b01) ? 0xFF : 0x00);
		bg_shifter_attrib_hi  = (bg_shifter_attrib_hi & 0xFF00) | ((bg_next_tile_attrib & 0b10) ? 0xFF : 0x00);
	};


	// ==============================================================================
	// Every cycle the shifters storing pattern and attribute information shift
	// their contents by 1 bit. This is because every cycle, the output progresses
	// by 1 pixel. This means relatively, the state of the shifter is in sync
	// with the pixels being drawn for that 8 pixel section of the scanline.
	auto UpdateShifters = [&]()
	{
		if (mask.render_background)
		{
			// Shifting background tile pattern row
			bg_shifter_pattern_lo <<= 1;
			bg_shifter_pattern_hi <<= 1;

			// Shifting palette attributes by 1
			bg_shifter_attrib_lo <<= 1;
			bg_shifter_attrib_hi <<= 1;
		}
	};

	// All but 1 of the secanlines is visible to the user. The pre-render scanline
	// at -1, is used to configure the "shifters" for the first visible scanline, 0.
	if (scanline >= -1 && scanline < 240)
	{		
		if (scanline == 0 && cycle == 0)
		{
			// "Odd Frame" cycle skip
			cycle = 1;
		}

		if (scanline == -1 && cycle == 1)
		{
			// Effectively start of new frame, so clear vertical blank flag
			status.vertical_blank = 0;
		}


		if ((cycle >= 2 && cycle < 258) || (cycle >= 321 && cycle < 338))
		{
			UpdateShifters();
			
			
			// In these cycles we are collecting and working with visible data
			// The "shifters" have been preloaded by the end of the previous
			// scanline with the data for the start of this scanline. Once we
			// leave the visible region, we go dormant until the shifters are
			// preloaded for the next scanline.

			// Fortunately, for background rendering, we go through a fairly
			// repeatable sequence of events, every 2 clock cycles.
			switch ((cycle - 1) % 8)
			{
			case 0:
				// Load the current background tile pattern and attributes into the "shifter"
				LoadBackgroundShifters();

				// Fetch the next background tile ID
				// "(vram_addr.reg & 0x0FFF)" : Mask to 12 bits that are relevant
				// "| 0x2000"                 : Offset into nametable space on PPU address bus
				bg_next_tile_id = ppuRead(0x2000 | (vram_addr.reg & 0x0FFF));

				// Explanation:
				// The bottom 12 bits of the loopy register provide an index into
				// the 4 nametables, regardless of nametable mirroring configuration.
				// nametable_y(1) nametable_x(1) coarse_y(5) coarse_x(5)
				//
				// Consider a single nametable is a 32x32 array, and we have four of them
				//   0                1
				// 0 +----------------+----------------+
				//   |                |                |
				//   |                |                |
				//   |    (32x32)     |    (32x32)     |
				//   |                |                |
				//   |                |                |
				// 1 +----------------+----------------+
				//   |                |                |
				//   |                |                |
				//   |    (32x32)     |    (32x32)     |
				//   |                |                |
				//   |                |                |
				//   +----------------+----------------+
				//
				// This means there are 4096 potential locations in this array, which 
				// just so happens to be 2^12!
				break;
			case 2:
				// Fetch the next background tile attribute. OK, so this one is a bit
				// more involved :P

				// Recall that each nametable has two rows of cells that are not tile 
				// information, instead they represent the attribute information that
				// indicates which palettes are applied to which area on the screen.
				// Importantly (and frustratingly) there is not a 1 to 1 correspondance
				// between background tile and palette. Two rows of tile data holds
				// 64 attributes. Therfore we can assume that the attributes affect
				// 8x8 zones on the screen for that nametable. Given a working resolution
				// of 256x240, we can further assume that each zone is 32x32 pixels
				// in screen space, or 4x4 tiles. Four system palettes are allocated
				// to background rendering, so a palette can be specified using just
				// 2 bits. The attribute byte therefore can specify 4 distinct palettes.
				// Therefore we can even further assume that a single palette is
				// applied to a 2x2 tile combination of the 4x4 tile zone. The very fact
				// that background tiles "share" a palette locally is the reason why
				// in some games you see distortion in the colours at screen edges.

				// As before when choosing the tile ID, we can use the bottom 12 bits of
				// the loopy register, but we need to make the implementation "coarser"
				// because instead of a specific tile, we want the attribute byte for a 
				// group of 4x4 tiles, or in other words, we divide our 32x32 address
				// by 4 to give us an equivalent 8x8 address, and we offset this address
				// into the attribute section of the target nametable.

				// Reconstruct the 12 bit loopy address into an offset into the
				// attribute memory

				// "(vram_addr.coarse_x >> 2)"        : integer divide coarse x by 4, 
				//                                      from 5 bits to 3 bits
				// "((vram_addr.coarse_y >> 2) << 3)" : integer divide coarse y by 4, 
				//                                      from 5 bits to 3 bits,
				//                                      shift to make room for coarse x

				// Result so far: YX00 00yy yxxx

				// All attribute memory begins at 0x03C0 within a nametable, so OR with
				// result to select target nametable, and attribute byte offset. Finally
				// OR with 0x2000 to offset into nametable address space on PPU bus.				
				bg_next_tile_attrib = ppuRead(0x23C0 | (vram_addr.nametable_y << 11) 
					                                 | (vram_addr.nametable_x << 10) 
					                                 | ((vram_addr.coarse_y >> 2) << 3) 
					                                 | (vram_addr.coarse_x >> 2));
				
				// Right we've read the correct attribute byte for a specified address,
				// but the byte itself is broken down further into the 2x2 tile groups
				// in the 4x4 attribute zone.

				// The attribute byte is assembled thus: BR(76) BL(54) TR(32) TL(10)
				//
				// +----+----+			    +----+----+
				// | TL | TR |			    | ID | ID |
				// +----+----+ where TL =   +----+----+
				// | BL | BR |			    | ID | ID |
				// +----+----+			    +----+----+
				//
				// Since we know we can access a tile directly from the 12 bit address, we
				// can analyse the bottom bits of the coarse coordinates to provide us with
				// the correct offset into the 8-bit word, to yield the 2 bits we are
				// actually interested in which specifies the palette for the 2x2 group of
				// tiles. We know if "coarse y % 4" < 2 we are in the top half else bottom half.
				// Likewise if "coarse x % 4" < 2 we are in the left half else right half.
				// Ultimately we want the bottom two bits of our attribute word to be the
				// palette selected. So shift as required...				
				if (vram_addr.coarse_y & 0x02) bg_next_tile_attrib >>= 4;
				if (vram_addr.coarse_x & 0x02) bg_next_tile_attrib >>= 2;
				bg_next_tile_attrib &= 0x03;
				break;

				// Compared to the last two, the next two are the easy ones... :P

			case 4: 
				// Fetch the next background tile LSB bit plane from the pattern memory
				// The Tile ID has been read from the nametable. We will use this id to 
				// index into the pattern memory to find the correct sprite (assuming
				// the sprites lie on 8x8 pixel boundaries in that memory, which they do
				// even though 8x16 sprites exist, as background tiles are always 8x8).
				//
				// Since the sprites are effectively 1 bit deep, but 8 pixels wide, we 
				// can represent a whole sprite row as a single byte, so offsetting
				// into the pattern memory is easy. In total there is 8KB so we need a 
				// 13 bit address.

				// "(control.pattern_background << 12)"  : the pattern memory selector 
				//                                         from control register, either 0K
				//                                         or 4K offset
				// "((uint16_t)bg_next_tile_id << 4)"    : the tile id multiplied by 16, as
				//                                         2 lots of 8 rows of 8 bit pixels
				// "(vram_addr.fine_y)"                  : Offset into which row based on
				//                                         vertical scroll offset
				// "+ 0"                                 : Mental clarity for plane offset
				// Note: No PPU address bus offset required as it starts at 0x0000
				bg_next_tile_lsb = ppuRead((control.pattern_background << 12) 
					                       + ((uint16_t)bg_next_tile_id << 4) 
					                       + (vram_addr.fine_y) + 0);

				break;
			case 6:
				// Fetch the next background tile MSB bit plane from the pattern memory
				// This is the same as above, but has a +8 offset to select the next bit plane
				bg_next_tile_msb = ppuRead((control.pattern_background << 12)
					                       + ((uint16_t)bg_next_tile_id << 4)
					                       + (vram_addr.fine_y) + 8);
				break;
			case 7:
				// Increment the background tile "pointer" to the next tile horizontally
				// in the nametable memory. Note this may cross nametable boundaries which
				// is a little complex, but essential to implement scrolling
				IncrementScrollX();
				break;
			}
		}

		// End of a visible scanline, so increment downwards...
		if (cycle == 256)
		{
			IncrementScrollY();
		}

		//...and reset the x position
		if (cycle == 257)
		{
			LoadBackgroundShifters();
			TransferAddressX();
		}

		// Superfluous reads of tile id at end of scanline
		if (cycle == 338 || cycle == 340)
		{
			bg_next_tile_id = ppuRead(0x2000 | (vram_addr.reg & 0x0FFF));
		}

		if (scanline == -1 && cycle >= 280 && cycle < 305)
		{
			// End of vertical blank period so reset the Y address ready for rendering
			TransferAddressY();
		}
	}

	if (scanline == 240)
	{
		// Post Render Scanline - Do Nothing!
	}

	if (scanline >= 241 && scanline < 261)
	{
		if (scanline == 241 && cycle == 1)
		{
			// Effectively end of frame, so set vertical blank flag
			status.vertical_blank = 1;

			// If the control register tells us to emit a NMI when
			// entering vertical blanking period, do it! The CPU
			// will be informed that rendering is complete so it can
			// perform operations with the PPU knowing it wont
			// produce visible artefacts
			if (control.enable_nmi) 
				nmi = true;
		}
	}



	// Composition - We now have background pixel information for this cycle
	// At this point we are only interested in background

	uint8_t bg_pixel = 0x00;   // The 2-bit pixel to be rendered
	uint8_t bg_palette = 0x00; // The 3-bit index of the palette the pixel indexes

	// We only render backgrounds if the PPU is enabled to do so. Note if 
	// background rendering is disabled, the pixel and palette combine
	// to form 0x00. This will fall through the colour tables to yield
	// the current background colour in effect
	if (mask.render_background)
	{
		// Handle Pixel Selection by selecting the relevant bit
		// depending upon fine x scolling. This has the effect of
		// offsetting ALL background rendering by a set number
		// of pixels, permitting smooth scrolling
		uint16_t bit_mux = 0x8000 >> fine_x;

		// Select Plane pixels by extracting from the shifter 
		// at the required location. 
		uint8_t p0_pixel = (bg_shifter_pattern_lo & bit_mux) > 0;
		uint8_t p1_pixel = (bg_shifter_pattern_hi & bit_mux) > 0;

		// Combine to form pixel index
		bg_pixel = (p1_pixel << 1) | p0_pixel;

		// Get palette
		uint8_t bg_pal0 = (bg_shifter_attrib_lo & bit_mux) > 0;
		uint8_t bg_pal1 = (bg_shifter_attrib_hi & bit_mux) > 0;
		bg_palette = (bg_pal1 << 1) | bg_pal0;
	}


	// Now we have a final pixel colour, and a palette for this cycle
	// of the current scanline. Let's at long last, draw that ^&%*er :P

	sprScreen->SetPixel(cycle - 1, scanline, GetColourFromPaletteRam(bg_palette, bg_pixel));

	// Fake some noise for now
	//sprScreen.SetPixel(cycle - 1, scanline, palScreen[(rand() % 2) ? 0x3F : 0x30]);

	// Advance renderer - it never stops, it's relentless
	cycle++;
	if (cycle >= 341)
	{
		cycle = 0;
		scanline++;
		if (scanline >= 261)
		{
			scanline = -1;
			frame_complete = true;
		}
	}
}
