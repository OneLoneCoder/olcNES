/*
	olc::NES - Mapper 4
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

#include "Mapper_004.h"

Mapper_004::Mapper_004(uint8_t prgBanks, uint8_t chrBanks) : Mapper(prgBanks, chrBanks)
{
	vRAMStatic.resize(32 * 1024);
}


Mapper_004::~Mapper_004()
{
}

bool Mapper_004::cpuMapRead(uint16_t addr, uint32_t &mapped_addr, uint8_t &data)
{
	if (addr >= 0x6000 && addr <= 0x7FFF)
	{
		// Write is to static ram on cartridge
		mapped_addr = 0xFFFFFFFF;

		// Write data to RAM
		data = vRAMStatic[addr & 0x1FFF];

		// Signal mapper has handled request
		return true;
	}


	if (addr >= 0x8000 && addr <= 0x9FFF)
	{
		mapped_addr = pPRGBank[0] + (addr & 0x1FFF);
		return true;
	}

	if (addr >= 0xA000 && addr <= 0xBFFF)
	{
		mapped_addr = pPRGBank[1] + (addr & 0x1FFF);
		return true;
	}

	if (addr >= 0xC000 && addr <= 0xDFFF)
	{
		mapped_addr = pPRGBank[2] + (addr & 0x1FFF);
		return true;
	}

	if (addr >= 0xE000 && addr <= 0xFFFF)
	{
		mapped_addr = pPRGBank[3] + (addr & 0x1FFF);
		return true;
	}

	return false;
}

bool Mapper_004::cpuMapWrite(uint16_t addr, uint32_t &mapped_addr, uint8_t data)
{
	if (addr >= 0x6000 && addr <= 0x7FFF)
	{
		// Write is to static ram on cartridge
		mapped_addr = 0xFFFFFFFF;

		// Write data to RAM
		vRAMStatic[addr & 0x1FFF] = data;

		// Signal mapper has handled request
		return true;
	}

	if (addr >= 0x8000 && addr <= 0x9FFF)
	{
		// Bank Select
		if (!(addr & 0x0001))
		{
			nTargetRegister = data & 0x07;
			bPRGBankMode = (data & 0x40);
			bCHRInversion = (data & 0x80);
		}
		else
		{
			// Update target register
			pRegister[nTargetRegister] = data;

			// Update Pointer Table
			if (bCHRInversion)
			{
				pCHRBank[0] = pRegister[2] * 0x0400;
				pCHRBank[1] = pRegister[3] * 0x0400;
				pCHRBank[2] = pRegister[4] * 0x0400;
				pCHRBank[3] = pRegister[5] * 0x0400;
				pCHRBank[4] = (pRegister[0] & 0xFE) * 0x0400;
				pCHRBank[5] = pRegister[0] * 0x0400 + 0x0400;
				pCHRBank[6] = (pRegister[1] & 0xFE) * 0x0400;
				pCHRBank[7] = pRegister[1] * 0x0400 + 0x0400;
			}
			else
			{
				pCHRBank[0] = (pRegister[0] & 0xFE) * 0x0400;
				pCHRBank[1] = pRegister[0] * 0x0400 + 0x0400;
				pCHRBank[2] = (pRegister[1] & 0xFE) * 0x0400;
				pCHRBank[3] = pRegister[1] * 0x0400 + 0x0400;
				pCHRBank[4] = pRegister[2] * 0x0400;
				pCHRBank[5] = pRegister[3] * 0x0400;
				pCHRBank[6] = pRegister[4] * 0x0400;
				pCHRBank[7] = pRegister[5] * 0x0400;
			}

			if (bPRGBankMode)
			{
				pPRGBank[2] = (pRegister[6] & 0x3F) * 0x2000;
				pPRGBank[0] = (nPRGBanks * 2 - 2) * 0x2000;
			}
			else
			{
				pPRGBank[0] = (pRegister[6] & 0x3F) * 0x2000;
				pPRGBank[2] = (nPRGBanks * 2 - 2) * 0x2000;
			}

			pPRGBank[1] = (pRegister[7] & 0x3F) * 0x2000;
			pPRGBank[3] = (nPRGBanks * 2 - 1) * 0x2000;

		}

		return false;
	}

	if (addr >= 0xA000 && addr <= 0xBFFF)
	{
		if (!(addr & 0x0001))
		{
			// Mirroring
			if (data & 0x01)
				mirrormode = MIRROR::HORIZONTAL;
			else
				mirrormode = MIRROR::VERTICAL;
		}
		else
		{
			// PRG Ram Protect
			// TODO:
		}
		return false;
	}

	if (addr >= 0xC000 && addr <= 0xDFFF)
	{
		if (!(addr & 0x0001))
		{
			nIRQReload = data;
		}
		else
		{
			nIRQCounter = 0x0000;
		}
		return false;
	}

	if (addr >= 0xE000 && addr <= 0xFFFF)
	{
		if (!(addr & 0x0001))
		{
			bIRQEnable = false;
			bIRQActive = false;
		}
		else
		{
			bIRQEnable = true;
		}
		return false;
	}



	return false;
}

bool Mapper_004::ppuMapRead(uint16_t addr, uint32_t &mapped_addr)
{
	if (addr >= 0x0000 && addr <= 0x03FF)
	{
		mapped_addr = pCHRBank[0] + (addr & 0x03FF);
		return true;
	}

	if (addr >= 0x0400 && addr <= 0x07FF)
	{
		mapped_addr = pCHRBank[1] + (addr & 0x03FF);
		return true;
	}

	if (addr >= 0x0800 && addr <= 0x0BFF)
	{
		mapped_addr = pCHRBank[2] + (addr & 0x03FF);
		return true;
	}

	if (addr >= 0x0C00 && addr <= 0x0FFF)
	{
		mapped_addr = pCHRBank[3] + (addr & 0x03FF);
		return true;
	}

	if (addr >= 0x1000 && addr <= 0x13FF)
	{
		mapped_addr = pCHRBank[4] + (addr & 0x03FF);
		return true;
	}

	if (addr >= 0x1400 && addr <= 0x17FF)
	{
		mapped_addr = pCHRBank[5] + (addr & 0x03FF);
		return true;
	}

	if (addr >= 0x1800 && addr <= 0x1BFF)
	{
		mapped_addr = pCHRBank[6] + (addr & 0x03FF);
		return true;
	}

	if (addr >= 0x1C00 && addr <= 0x1FFF)
	{
		mapped_addr = pCHRBank[7] + (addr & 0x03FF);
		return true;
	}

	return false;
}

bool Mapper_004::ppuMapWrite(uint16_t addr, uint32_t &mapped_addr)
{
	
	
	return false;
}

void Mapper_004::reset()
{
	nTargetRegister = 0x00;
	bPRGBankMode = false;
	bCHRInversion = false;
	mirrormode = MIRROR::HORIZONTAL;

	bIRQActive = false;
	bIRQEnable = false;
	bIRQUpdate = false;
	nIRQCounter = 0x0000;
	nIRQReload = 0x0000;

	for (int i = 0; i < 4; i++)	pPRGBank[i] = 0;
	for (int i = 0; i < 8; i++) { pCHRBank[i] = 0; pRegister[i] = 0; }

	pPRGBank[0] = 0 * 0x2000;
	pPRGBank[1] = 1 * 0x2000;
	pPRGBank[2] = (nPRGBanks * 2 - 2) * 0x2000;
	pPRGBank[3] = (nPRGBanks * 2 - 1) * 0x2000;
}


bool Mapper_004::irqState()
{
	return bIRQActive;
}

void Mapper_004::irqClear()
{
	bIRQActive = false;
}

void Mapper_004::scanline()
{
	if (nIRQCounter == 0)
	{		
		nIRQCounter = nIRQReload;
	}
	else
		nIRQCounter--;

	if (nIRQCounter == 0 && bIRQEnable)
	{
		bIRQActive = true;
	}
	
}

MIRROR Mapper_004::mirror()
{
	return mirrormode;
}
