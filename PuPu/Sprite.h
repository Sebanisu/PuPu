#ifndef SPRITE_H
 #define SPRITE_H

#include "Q-Gears Filesystem\TypeDefine.h"
#include "Q-Gears Filesystem\LzsFile.h"
#include <stdio.h>

ref class Sprite
{
public:
	Sprite();
	Sprite(File * fmap, int i, int type);
	virtual ~Sprite();
	u32 ID;
	int type;
	//Offsets
	u32 o_sprite;
	u32 o_X;
	u32 o_Y;
	u32 o_Z;
	u32 o_page;
	u32 o_ZZ1;
	u32 o_depth;
	u32 o_ZZ2;
	u32 o_ZZ3;
	u32 o_pal;
	u32 o_ZZ4;
	u32 o_SrcX;
	u32 o_SrcY;
	u32 o_ZZ5;
	u32 o_layerid;
	u32 o_blendmode;
	u32 o_animid;
	u32 o_animstate;
	s16 X;
	s16 Y;
	u16 Z;
	u8 page;
	u8 ZZ1;
	u8 depth;
	u8 ZZ2;
	u8 ZZ3;
	u8 pal;
	u8 ZZ4;
	s16 SrcX;
	s16 SrcY;
	u8 ZZ5;
	u8 layerid;
	u8 blendmode;
	u8 animid;
	u8 animstate;
	u32 GetSource();
	u32 GetTarget(int LWidth, int LHeight, int Xmin, int Ymin);
};

#endif

