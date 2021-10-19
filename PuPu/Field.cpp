#include "StdAfx.h"
#include "Field.h"
#include "Sprite.h"
#include "Palette.h"
#include <algorithm>
#include <string>

Field::Field(File * fmim, File * fmap) :
fmap(NULL),
fmim(NULL),
type(0),
NumFISprites(0),
IDs(gcnew List<u32>())
{
	this->fmap = fmap;
	this->fmim = fmim;
	p = gcnew Palette(fmim, type);
	int mimsize = fmim->GetFileSize();
	if (mimsize >= 0x6B000)
	{
		type = 1;
	}
	else
	{
		type = 2;
	}
	std::string fName = fmim->GetFileName();
	std::string logo = "logo.mim";
	if (fName.substr(fName.length() - 8, fName.length()) ==  logo)
	{
		type = 3;
	}
	std::string test10 = "test10.mim";
	std::string test11 = "test11.mim";
	std::string test12 = "test12.mim";
	if ( fName.substr(fName.length() - 10, fName.length()) ==  test10 ||
		 fName.substr(fName.length() - 10, fName.length()) ==  test11 ||
		 fName.substr(fName.length() - 10, fName.length()) ==  test12 )
	{
		type = 4;
	}

	int mapsize = fmap->GetFileSize();
	NumFISprites = mapsize / 16 - 1;
	Sprites = gcnew array<Sprite^>(NumFISprites);
	for (int i = 0; i < NumFISprites; i++)	//Build sprites
	{
		Sprites[i] = gcnew Sprite(fmap, i, type);
	}
	for (int i = 0; i < NumFISprites; i++)	//Separate overlapping layers
	{
		for (int j = i + 1; j < NumFISprites; j++)
		{
			if ((Sprites[i]->X == Sprites[j]->X) && (Sprites[i]->Y == Sprites[j]->Y))
			{
				if ((Sprites[i]->ID & 0xFFFFFFF0) == (Sprites[j]->ID & 0xFFFFFFF0))
				{
					Sprites[j]->ID = Sprites[i]->ID + 1;
				}
			}
		}
	}
	for (int i = 0; i < NumFISprites; i++)	//Populate IDs
	{
		if (!IDs->Contains(Sprites[i]->ID))
		{
			IDs->Add(Sprites[i]->ID);
		}
	}
	IDs->Sort();
}

Field::~Field()
{
	if (fmim != nullptr) { delete fmim; }
	if (fmap != nullptr) { delete fmap; }
}