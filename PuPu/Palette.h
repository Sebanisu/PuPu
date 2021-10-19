#ifndef PALETTE_H
 #define PALETTE_H

#include "Q-Gears Filesystem\TypeDefine.h"
#include "Q-Gears Filesystem\LzsFile.h"
#include "Sprite.h"

ref class Palette
{
public:
	Palette(File * fmim, int type);
	virtual ~Palette();
	File * fmim;
	//Values
	u16 NumColors;
	u16 NumPalettes;
	u16 * GetPixel(Sprite ^ s, int j, int k);
};

#endif
