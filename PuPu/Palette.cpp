#include "StdAfx.h"
#include "Palette.h"
#include "Sprite.h"

Palette::Palette(File * fmim, int type) :
fmim(NULL),
NumColors(0),
NumPalettes(0)
{
	this->fmim = fmim;
	NumColors = 256;
	if (type == 1 || type == 4)
	{
		NumPalettes = 24;
	}
	else if (type == 2 || type == 3)
	{
		NumPalettes = 16;
	}
}

Palette::~Palette()
{

}

u16 * Palette::GetPixel(Sprite ^ s, int j, int k)
{
	int add = 0;
	if (s->type == 1 || s->type == 4)
	{
		add = 128;
	}
	u8 color_index = 0;
	u32 o_mimsprite = s->GetSource();
	int pixel_offset = 0;
	if (s->depth < 4) //4-bit indexed
	{
		o_mimsprite -= (s->SrcX / 2);
		pixel_offset = (j * (1536 + add)) + (k / 2); //1536 for type 2 and 3, 1664 for type 1 and 4
		if (k % 2 == 1)
		{
			color_index = (fmim->GetU8(o_mimsprite + pixel_offset) & 0xF0) >> 4;
		}
		else
		{
			color_index = fmim->GetU8(o_mimsprite + pixel_offset) & 0x0F;
		}
	}
	else //8-bit indexed
	{
		pixel_offset = (j * (1536 + add)) + k;
		color_index = fmim->GetU8(o_mimsprite + pixel_offset);
	}
	u16 pal_color = fmim->GetU16LE((s->pal * NumColors * 2) + (color_index * 2));
	u16 * pixel = new u16; //Alpha is 0, everything black transparent by default
	//*pixel = pal_color;
	*pixel = 0x0000;
	*pixel = *pixel + ((pal_color & 0x001F) << 10); //R
	*pixel = *pixel + ((pal_color & 0x03E0) << 0); //G
	*pixel = *pixel + ((pal_color & 0x7C00) >> 10); //B
	if (pal_color != 0) *pixel += 0x8000;	//A

	return pixel;
}
