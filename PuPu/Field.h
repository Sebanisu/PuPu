#ifndef FIELD_H
 #define FIELD_H

#include "Q-Gears Filesystem\TypeDefine.h"
#include "Q-Gears Filesystem\LzsFile.h"
#include "Sprite.h"
#include "Palette.h"

using namespace System::Collections::Generic;

ref class Field
{
public:
	Field(File * fmim, File * fmap);
	virtual ~Field();
	File * fmim;
	File * fmap;
	int type;
	int NumFISprites;
	array<Sprite^> ^ Sprites;
	Palette ^ p;
	List<u32> ^ IDs;
};

#endif

