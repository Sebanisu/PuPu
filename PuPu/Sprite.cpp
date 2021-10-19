#include "StdAfx.h"
#include "Sprite.h"


Sprite::Sprite()
{
	//Default constructor
}

Sprite::Sprite(File * fmap, int i, int type) :	//type 1 or 2
ID(0),
type(0),
o_sprite(0),
o_X(0),
o_Y(0),
o_Z(0),
o_page(0),
o_ZZ1(0),
o_depth(0),
o_ZZ2(0),
o_ZZ3(0),
o_pal(0),
o_ZZ4(0),
o_SrcX(0),
o_SrcY(0),
o_ZZ5(0),
o_layerid(0),
o_blendmode(0),
o_animid(0),
o_animstate(0),
X(0),
Y(0),
Z(0),
page(0),
ZZ1(0),
depth(0),
ZZ2(0),
ZZ3(0),
pal(0),
ZZ4(0),
SrcX(0),
SrcY(0),
ZZ5(0),
layerid(0),
blendmode(0),
animid(0),
animstate(0)
{
	this->type = type;
	if (type == 1)
	{
		o_sprite = i * 16;//Each sprite is 16 bytes long (128 bits)
		//Offsets
		o_X = o_sprite;//s16, Target X
		o_Y = o_X + 2;//s16, Target Y
		o_Z = o_Y + 2;//u16, Z-coord (/4096->float)
		o_page = o_Z + 2;//u4, Texture page #, x128 + SrcX
		o_ZZ1 = o_page;//u1, Unknown, always 1?
		o_depth = o_page;//u3, <4 = 4-bit color, else 8-bit
		o_ZZ2 = o_page + 1;//u8, Unknown, always 0?
		o_ZZ3 = o_page + 2;//u6, Unknown, always 15? (backwards from wiki)
		o_pal = o_page + 2;//u4, Palette, +8
		o_ZZ4 = o_pal;//u6, Unknown, always 0?
		o_SrcX = o_pal + 2;//u8, Source X
		o_SrcY = o_SrcX + 1;//u8, Source Y
		o_ZZ5 = o_SrcY + 1;//u1, Unknown, always 0?
		o_layerid = o_SrcY + 1;//u7, Layer id	(backwards from wiki)
		o_blendmode = o_layerid + 1;//u8, Blend mode, 1=add, 2=sub, 3=+25%, 4=none(default), 0=unknown
		o_animid = o_blendmode + 1;//u8, Anim id
		o_animstate = o_animid + 1;//u8, Anim state
		//Values
		X = fmap->GetU16LE(o_X);
		Y = fmap->GetU16LE(o_Y);
		Z = fmap->GetU16LE(o_Z);
		page = fmap->GetU8(o_page) & 0x0F;
		ZZ1 = (fmap->GetU8(o_ZZ1) & 0x10) >> 4;
		depth = fmap->GetU8(o_depth) >> 5;
		ZZ2 = fmap->GetU8(o_ZZ2);
		ZZ3 = (fmap->GetU16LE(o_ZZ3) & 0xFC00) >> 10;
		pal = (fmap->GetU16LE(o_pal) & 0x03C0) >> 6;
		pal += 8;	//Must add 8 if type 1
		ZZ4 = fmap->GetU16LE(o_ZZ4) & 0x003C;
		SrcX = fmap->GetU8(o_SrcX);
		SrcY = fmap->GetU8(o_SrcY);
		ZZ5 = fmap->GetU8(o_ZZ5) & 0x01;
		layerid = fmap->GetU8(o_layerid) >> 1;
		blendmode = fmap->GetU8(o_blendmode);
		animid = fmap->GetU8(o_animid);
		animstate = fmap->GetU8(o_animstate);
	}
	else if (type == 2 || type == 4)
	{
		o_sprite = i * 16;//Each sprite is 16 bytes long (128 bits)
		//Offsets
		o_X = o_sprite;//s16, Target X
		o_Y = o_X + 2;//s16, Target Y
		o_SrcX = o_Y + 2;//s16, Source X
		o_SrcY = o_SrcX + 2;//s16, Source Y
		o_Z = o_SrcY + 2;//u16, Z-coord (/4096->float)
		o_page = o_Z + 2;//u4, Texture page #, x128 + SrcX
		o_ZZ1 = o_page;//u1, Unknown, always 1?
		o_depth = o_page;//u3, <4 = 4-bit color, else 8-bit
		o_ZZ2 = o_page + 1;//u8, Unknown, always 0?
		o_ZZ3 = o_page + 2;//u6, Unknown, always 15?
		o_pal = o_page + 2;//u4, Palette, +8
		o_ZZ4 = o_pal;//u6, Unknown, always 0?
		o_animid = o_pal + 2;//u8, Anim id
		o_animstate = o_animid + 1;//u8, Anim state
		//Values
		X = fmap->GetU16LE(o_X);
		Y = fmap->GetU16LE(o_Y);
		SrcX = fmap->GetU16LE(o_SrcX);
		SrcY = fmap->GetU16LE(o_SrcY);
		Z = fmap->GetU16LE(o_Z);
		page = fmap->GetU8(o_page) & 0x0F;
		ZZ1 = (fmap->GetU8(o_ZZ1) & 0x10) >> 4;
		depth = fmap->GetU8(o_depth) >> 5;
		ZZ2 = fmap->GetU8(o_ZZ2);
		ZZ3 = (fmap->GetU16LE(o_ZZ3) & 0xFC00) >> 10;
		pal = (fmap->GetU16LE(o_pal) & 0x03C0) >> 6;
		if (type == 4) pal += 8;	//Must add 8 if type 4
		ZZ4 = fmap->GetU16LE(o_ZZ4) & 0x003C;
		animid = fmap->GetU8(o_animid);
		animstate = fmap->GetU8(o_animstate);

		ZZ5 = 0;
		layerid = 0;
		blendmode = 4;
	}
	else if (type == 3)
	{
		o_sprite = i * 14;//Each sprite is 14 bytes long (112 bits)
		//Offsets
		o_X = o_sprite;//s16, Target X
		o_Y = o_X + 2;//s16, Target Y
		o_SrcX = o_Y + 2;//s16, Source X
		o_SrcY = o_SrcX + 2;//s16, Source Y
		o_Z = o_SrcY + 2;//u16, Z-coord (/4096->float)
		o_page = o_Z + 2;//u4, Texture page #, x128 + SrcX
		o_ZZ1 = o_page;//u1, Unknown, always 1?
		o_depth = o_page;//u3, <4 = 4-bit color, else 8-bit
		o_ZZ2 = o_page + 1;//u8, Unknown, always 0?
		o_ZZ3 = o_page + 2;//u6, Unknown, always 15?
		o_pal = o_page + 2;//u4, Palette, +8
		o_ZZ4 = o_pal;//u6, Unknown, always 0?
		//Values
		X = fmap->GetU16LE(o_X);
		Y = fmap->GetU16LE(o_Y);
		SrcX = fmap->GetU16LE(o_SrcX);
		SrcY = fmap->GetU16LE(o_SrcY);
		Z = fmap->GetU16LE(o_Z);
		page = fmap->GetU8(o_page) & 0x0F;
		ZZ1 = (fmap->GetU8(o_ZZ1) & 0x10) >> 4;
		depth = fmap->GetU8(o_depth) >> 5;
		ZZ2 = fmap->GetU8(o_ZZ2);
		ZZ3 = (fmap->GetU16LE(o_ZZ3) & 0xFC00) >> 10;
		pal = (fmap->GetU16LE(o_pal) & 0x03C0) >> 6;
		ZZ4 = fmap->GetU16LE(o_ZZ4) & 0x003C;

		animid = 0xFF;
		animstate = 0x00;
		ZZ5 = 0;
		layerid = 0;
		blendmode = 4;
	}
	ID = 0x00000000;	//ID identifies the sprites composing an output file, an ID is 1:1 with a PNG
	ID += (layerid << 24);
	ID += (blendmode << 20);
	ID += (animid << 12);
	ID += (animstate << 4);	//Bottom 3 bits store overlapping sprites
}

Sprite::~Sprite()
{

}

u32 Sprite::GetSource()
{
	int offset = 0;
	if (type == 1 || type == 4)
	{
		offset = 0x3000;
		offset +=  (SrcY * 1664) + (page * 128) + SrcX;
	}
	else if (type == 2 || type == 3)
	{
		offset = 0x2000;
		offset += (SrcY * 1536) + (page * 128) + SrcX;
	}
	return offset;
}

u32 Sprite::GetTarget(int LWidth, int LHeight, int Xmin, int Ymin)
{

	return ((Y - Ymin) * LWidth) + (X - Xmin);	
}
