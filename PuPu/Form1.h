/*PuPu by Omzy*/
/*FF8 Field Importer/Exporter*/

#pragma once

#include <sstream>
#include <iostream>
#include <stdio.h>
#include "Q-Gears Filesystem\LzsFile.h"
#include "Q-Gears Filesystem\FileSystem.h"
#include "Q-Gears Filesystem\File.h"
#include "Palette.h"
#include "Field.h"
#include "Sprite.h"
#include <msclr\marshal_cppstd.h>
#include <assert.h>

namespace PuPu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^  DisplayPort;
	private: System::Windows::Forms::ListBox^  IDBox;
	private: System::Windows::Forms::Button^  ExportButton;
	private: System::Windows::Forms::Button^  ImportButton;
	private: System::Windows::Forms::ListBox^  FieldBox;
	private: System::Windows::Forms::Button^  AboutButton;
	private: System::Windows::Forms::LinkLabel^  HelpLabel;
	private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->DisplayPort = (gcnew System::Windows::Forms::PictureBox());
			this->IDBox = (gcnew System::Windows::Forms::ListBox());
			this->ExportButton = (gcnew System::Windows::Forms::Button());
			this->ImportButton = (gcnew System::Windows::Forms::Button());
			this->FieldBox = (gcnew System::Windows::Forms::ListBox());
			this->AboutButton = (gcnew System::Windows::Forms::Button());
			this->HelpLabel = (gcnew System::Windows::Forms::LinkLabel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DisplayPort))->BeginInit();
			this->SuspendLayout();
			// 
			// DisplayPort
			// 
			this->DisplayPort->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"DisplayPort.Image")));
			this->DisplayPort->Location = System::Drawing::Point(105, 0);
			this->DisplayPort->MaximumSize = System::Drawing::Size(640, 480);
			this->DisplayPort->MinimumSize = System::Drawing::Size(640, 480);
			this->DisplayPort->Name = L"DisplayPort";
			this->DisplayPort->Size = System::Drawing::Size(640, 480);
			this->DisplayPort->TabIndex = 9;
			this->DisplayPort->TabStop = false;
			// 
			// IDBox
			// 
			this->IDBox->BackColor = System::Drawing::Color::Black;
			this->IDBox->ForeColor = System::Drawing::Color::Cyan;
			this->IDBox->FormattingEnabled = true;
			this->IDBox->IntegralHeight = false;
			this->IDBox->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"Elixir please!"});
			this->IDBox->Location = System::Drawing::Point(747, 2);
			this->IDBox->Name = L"IDBox";
			this->IDBox->Size = System::Drawing::Size(101, 419);
			this->IDBox->TabIndex = 14;
			this->IDBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::IDBox_SelectedIndexChanged);
			// 
			// ExportButton
			// 
			this->ExportButton->Location = System::Drawing::Point(2, 422);
			this->ExportButton->Name = L"ExportButton";
			this->ExportButton->Size = System::Drawing::Size(101, 28);
			this->ExportButton->TabIndex = 12;
			this->ExportButton->Text = L"Export";
			this->ExportButton->UseVisualStyleBackColor = true;
			this->ExportButton->Click += gcnew System::EventHandler(this, &Form1::ExportButton_Click);
			// 
			// ImportButton
			// 
			this->ImportButton->Location = System::Drawing::Point(2, 451);
			this->ImportButton->Name = L"ImportButton";
			this->ImportButton->Size = System::Drawing::Size(101, 28);
			this->ImportButton->TabIndex = 13;
			this->ImportButton->Text = L"Import";
			this->ImportButton->UseVisualStyleBackColor = true;
			this->ImportButton->Click += gcnew System::EventHandler(this, &Form1::ImportButton_Click);
			// 
			// FieldBox
			// 
			this->FieldBox->BackColor = System::Drawing::Color::Black;
			this->FieldBox->ForeColor = System::Drawing::Color::Cyan;
			this->FieldBox->FormattingEnabled = true;
			this->FieldBox->IntegralHeight = false;
			this->FieldBox->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"More Elixir please!"});
			this->FieldBox->Location = System::Drawing::Point(2, 2);
			this->FieldBox->Name = L"FieldBox";
			this->FieldBox->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->FieldBox->Size = System::Drawing::Size(101, 419);
			this->FieldBox->TabIndex = 14;
			this->FieldBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::FieldBox_SelectedIndexChanged);
			// 
			// AboutButton
			// 
			this->AboutButton->Location = System::Drawing::Point(747, 451);
			this->AboutButton->Name = L"AboutButton";
			this->AboutButton->Size = System::Drawing::Size(101, 28);
			this->AboutButton->TabIndex = 16;
			this->AboutButton->Text = L"About";
			this->AboutButton->UseVisualStyleBackColor = true;
			this->AboutButton->Click += gcnew System::EventHandler(this, &Form1::AboutButton_Click);
			// 
			// HelpLabel
			// 
			this->HelpLabel->BackColor = System::Drawing::Color::Black;
			this->HelpLabel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->HelpLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->HelpLabel->ForeColor = System::Drawing::Color::Cyan;
			this->HelpLabel->LinkArea = System::Windows::Forms::LinkArea(0, 4);
			this->HelpLabel->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->HelpLabel->LinkColor = System::Drawing::Color::Cyan;
			this->HelpLabel->Location = System::Drawing::Point(747, 422);
			this->HelpLabel->Name = L"HelpLabel";
			this->HelpLabel->Size = System::Drawing::Size(101, 28);
			this->HelpLabel->TabIndex = 17;
			this->HelpLabel->TabStop = true;
			this->HelpLabel->Text = L"Help";
			this->HelpLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->HelpLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Form1::HelpLabel_LinkClicked);
			// 
			// Form1
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(851, 480);
			this->Controls->Add(this->HelpLabel);
			this->Controls->Add(this->AboutButton);
			this->Controls->Add(this->FieldBox);
			this->Controls->Add(this->ImportButton);
			this->Controls->Add(this->ExportButton);
			this->Controls->Add(this->IDBox);
			this->Controls->Add(this->DisplayPort);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(867, 518);
			this->MinimumSize = System::Drawing::Size(867, 518);
			this->Name = L"Form1";
			this->Text = L"PuPu v2.0 (FF8 Field Importer/Exporter)";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DisplayPort))->EndInit();
			this->ResumeLayout(false);

		}

#pragma endregion
	property System::String ^ FileName;
	property System::String ^ CurrentDir;
	property System::String ^ Path;
	property System::String ^ ExportDir;
	property System::String ^ ImportFromDir;
	property System::String ^ ImportToDir;
	property System::String ^ DebugDir;
	private: Field ^ field;
	private: Graphics ^ g;
	private: Image ^ img;
	private: u32 DefaultID;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
			 {
				 g = this->DisplayPort->CreateGraphics();
				 try
				 {
					 array<String^>^ files = System::IO::Directory::GetFiles("mapdata\\", "*.map", System::IO::SearchOption::AllDirectories);
					 for (int i = 0; i < files->Length; i++)
					 {
						 files[i] = files[i]->Substring(11, (files[i]->Length - 15) / 2);
					 }
					 FieldBox->Items->Clear();
					 FieldBox->Items->AddRange(files);
					 FieldBox->Items->Remove("bchtr1a\\");
					 FieldBox->Items->Remove("ecenter");
				 }
				 catch( System::Exception^ /*e*/)
				 {
					 MessageBox::Show("Error: Is PuPu.exe in the same directory as the extracted 'mapdata' folder?", L"Error", MessageBoxButtons::OK);
					 Application::Exit();
				 }
			 }

	private: System::Void FieldBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
			 {
				 if (FieldBox->Items[0] != "More Elixir please!") OpenFile();
			 }

			 System::Void OpenFile ()
			 {
				 if (FieldBox->SelectedItems->Count == 0) //Maki 2019.05.22 - null reference crashed software
					 return;
				 FileName = (String^)FieldBox->SelectedItems[0];
				 CurrentDir = System::IO::Directory::GetCurrentDirectory();
			     Path = "\\mapdata\\" + FileName->Substring(0, 2) + "\\" + FileName + "\\";
				 if (!String::IsNullOrEmpty(FileName))
				 {
					 using namespace msclr::interop;
					 std::string fName(marshal_as<std::string>(FileName));
					 std::string fmapName(fName + ".map");
					 std::string fmimName(fName + ".mim");
					 std::string cDir(marshal_as<std::string>(CurrentDir));
					 std::string fPath(marshal_as<std::string>(Path));
					 File* mimfile = new File(cDir + fPath + fmimName);
					 File* mapfile = new File(cDir + fPath + fmapName);
					 field = gcnew Field(mimfile, mapfile);
					 FillIDBox();
					 DisplayImage(DefaultID);
				 }
			 }

			 System::Void OpenFile (int file)	//Open for export/import (no display)
			 {
				 FileName = (String^)FieldBox->SelectedItems[file];
				 CurrentDir = System::IO::Directory::GetCurrentDirectory();
			     Path = "\\mapdata\\" + FileName->Substring(0, 2) + "\\" + FileName + "\\";
				 if (!String::IsNullOrEmpty(FileName))
				 {
					 using namespace msclr::interop;
					 std::string fName(marshal_as<std::string>(FileName));
					 std::string fmapName(fName + ".map");
					 std::string fmimName(fName + ".mim");
					 std::string cDir(marshal_as<std::string>(CurrentDir));
					 std::string fPath(marshal_as<std::string>(Path));
					 File* mimfile = new File(cDir + fPath + fmimName);
					 File* mapfile = new File(cDir + fPath + fmapName);
					 field = gcnew Field(mimfile, mapfile);
					 FillIDBox();
				 }
			 }

			 System::Void DisplayImage (u32 ID)
			 {
				 int Xmin(0), Xmax(0), Ymin(0), Ymax(0);
				 for (int i = 0; i < field->NumFISprites; i++)
				 {
					 if ((field->Sprites[i]->ID & 0xFF000000) == (ID & 0xFF000000))
					 {
						 Xmin = min(Xmin, field->Sprites[i]->X);
						 Xmax = max(Xmax, field->Sprites[i]->X);
						 Ymin = min(Ymin, field->Sprites[i]->Y);
						 Ymax = max(Ymax, field->Sprites[i]->Y);
					 }
				 }
				 int LWidth = Xmax - Xmin + 16;
				 int LHeight = Ymax - Ymin + 16;

				 //MessageBox::Show( "out_length" + (LWidth * LHeight * 3) + ", last" + ((((Ymax - Ymin) * LWidth) + (Xmax - Xmin)) + ((15 * LWidth) + 15)) * 3 + ", W" + LWidth + ", H" + LHeight + ", Xmin" + Xmin + ", Xmax" + Xmax + ", Ymin" + Ymin + ", Ymax" + Ymax, L"TestApp", System::Windows::Forms::MessageBoxButtons::OK);
				 g->Clear(Color::Black);
				 img = GetImage(LoadID(ID, LWidth, LHeight, Xmin, Ymin), LWidth, LHeight, 0); //Maki 20190522
				 g->DrawImage(img, 320 + Xmin, 240 + Ymin);
			 }

			 Image ^ GetImageForExport (u32 ID)
			 {
				 int Xmin(0), Xmax(0), Ymin(0), Ymax(0);
				 for (int i = 0; i < field->NumFISprites; i++)
				 {
					 if ((field->Sprites[i]->ID & 0xFF000000) == (ID & 0xFF000000))
					 {
						 Xmin = min(Xmin, field->Sprites[i]->X);
						 Xmax = max(Xmax, field->Sprites[i]->X);
						 Ymin = min(Ymin, field->Sprites[i]->Y);
						 Ymax = max(Ymax, field->Sprites[i]->Y);
					 }
				 }
				 int LWidth = Xmax - Xmin + 16;
				 int LHeight = Ymax - Ymin + 16;
				 return img = GetImage(LoadID(ID, LWidth, LHeight, Xmin, Ymin), LWidth, LHeight, 0); //Maki 20190522
			 }

			 //Returns Bitmap object from RGB image buffer
			 Bitmap^ GetImage (u8 * imageBuffer, int LWidth, int LHeight, int mode) //Maki 20190522
			 {
				 System::Drawing::Imaging::PixelFormat pixel;
				 if (mode == 0) //+Maki 20190522
					 pixel = System::Drawing::Imaging::PixelFormat::Format16bppArgb1555; //-Maki
				 else pixel = System::Drawing::Imaging::PixelFormat::Format32bppArgb;
				 Bitmap^ bmp = gcnew Bitmap(LWidth, LHeight, LWidth*(mode==0?2:4), pixel, (System::IntPtr)imageBuffer); //Maki 20190522
				 //if (imageBuffer != nullptr) { delete imageBuffer; }
				 return bmp;
			 }

			 u8 * LoadID (u32 ID, int LWidth, int LHeight, int Xmin, int Ymin)
			 {
				 u32 out_length = LWidth * LHeight * 2; //W * H * Pixel Depth (RGB=3)
				 u8 * out_buffer = new u8 [out_length];
				 for (int i = 0; i < (Int32)out_length; i++)
				 {
					 out_buffer[i] = 0;
				 }
				 for (int i = 0; i < field->NumFISprites; i++)
				 {
					 if (field->Sprites[i]->ID == ID)
					 {
						 u32 target = field->Sprites[i]->GetTarget(LWidth, LHeight, Xmin, Ymin);
						 for (int j = 0; j < 16; j++)
						 {
							 for (int k = 0; k < 16; k++)
							 {
								 u16 * pixel = field->p->GetPixel(field->Sprites[i], j, k);
								 memcpy(&out_buffer[(target + ((j * LWidth) + k)) * 2], pixel, 2);
								 if (pixel != nullptr) { delete pixel; }
							 }
						 }
					 }
				 }
				 return out_buffer;
			 }

			 System::Void FillIDBox ()
			 {
				 IDBox->Items->Clear();
				 for (int i = 0; i < field->IDs->Count; i ++)
				 {
					 u32 ID = field->IDs[i];
					 IDBox->Items->Add(((UInt32)ID).ToString("X8"));
				 }
				 if (IDBox->Items->Contains("004FF000"))
				 {
					 DefaultID = 0x004FF000;
				 }
				 else if (IDBox->Items->Contains("00400000"))
				 {
					 DefaultID = 0x00400000;
				 }
				 else
				 {
					 DefaultID = (u32)(Convert::ToUInt32((String^)IDBox->Items[0], 16));
				 }
				 for (int i = 0; i < field->IDs->Count; i ++)
				 {
					 u32 ID = field->IDs[i];
					 if (ID == DefaultID) IDBox->SelectedItem = IDBox->Items[i];
				 }

			 }

	private: System::Void ImportButton_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 if (field != nullptr)
				 {
					 FolderBrowserDialog ^ importFromDialog = gcnew FolderBrowserDialog();
					 importFromDialog->Description = "Select the Folder that contains your Hi-Res 'mapdata' Folder";
					 if (importFromDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					 {
						 ImportFromDir = importFromDialog->SelectedPath;
					 }
					 FolderBrowserDialog ^ importToDialog = gcnew FolderBrowserDialog();
					 importToDialog->Description = "Select Destination Folder";
					 if (importToDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					 {
						 ImportToDir = importToDialog->SelectedPath;
					 }

					 for (int i = 0; i < FieldBox->SelectedItems->Count; i++)
					 {
						 OpenFile(i);
						 try
						 {
							 int numpages = 12; //types 2,3
							 if (field->type == 1 || field->type == 4) numpages = 13; //types 1, 4
							 int * depths = new int[numpages];
							 for (int i = 0; i < numpages; i++) //one image per page
							 {
								 int fourflag = 0;
								 int eightflag = 0;
								 for (int j = 0; j < field->NumFISprites; j++) 
								 {
									 if (field->Sprites[j]->page == i) //find depth for each page
									 {
										 if (field->Sprites[j]->depth < 4)
										 {
											 fourflag = 2;
										 } else {
											 eightflag = 1;
										 }
									 }
								 }
								 depths[i] = fourflag + eightflag;
							 } //only depths that have values that are non-negative are the pages to write

							 int Xmin(0), Xmax(0), Ymin(0), Ymax(0);
							 for (int i = 0; i < field->NumFISprites; i++)
							 {
								 if ((field->Sprites[i]->ID & 0xFF000000) == (field->Sprites[0]->ID & 0xFF000000))
								 {
									 Xmin = min(Xmin, field->Sprites[i]->X);
									 Xmax = max(Xmax, field->Sprites[i]->X);
									 Ymin = min(Ymin, field->Sprites[i]->Y);
									 Ymax = max(Ymax, field->Sprites[i]->Y);
								 }
							 }

							 int LWidth = Xmax - Xmin + 16;
							 int LHeight = Ymax - Ymin + 16;
							 String ^ checkPath = ImportFromDir + Path + FileName + "_" + ((UInt32)field->Sprites[0]->ID).ToString("X8") + ".png";
							 Image ^ checkImg = Image::FromFile(checkPath);
							 int checkWidth = checkImg->Width;
							 int checkHeight = checkImg->Height;
							 int mult = checkWidth / LWidth;	//Don't need height

							 u8 ** out_buffers = new u8 * [numpages]; //8 bit indexed pages
							 u8 ** out_buffers4 = new u8 * [numpages]; //4 bit indexed pages
							 for (int i = 0; i < numpages; i++)
							 {
								 if (depths[i] == 1 || depths[i] == 3)
								 {
									 u32 out_length = (128 * 2 * mult) * (256 * mult) * 4; //W * depth * H * Pixel Depth (ARGB1555=2) //Maki 20190522 - now it's argb32
									 out_buffers[i] = new u8 [out_length];
									 for (int j = 0; j < (Int32)out_length; j++)
									 {
										 out_buffers[i][j] = 0;
									 }
								 }
								 if (depths[i] == 2 || depths[i] == 3)
								 {
									 u32 out_length = (128 * 2 * mult) * (256 * mult) * 4; //W * depth * H * Pixel Depth (ARGB1555=2) //Maki 20190522 same as above change
									 out_buffers4[i] = new u8 [out_length];
									 for (int j = 0; j < (Int32)out_length; j++)
									 {
										out_buffers4[i][j] = 0;
									 }
								 } //only instantiates out_buffers that are written to by sprites
							 }
							 for (int j = 0; j < IDBox->Items->Count; j++)
							 {
								 //Get buffer for import
								 u32 imgID = (u32)(Convert::ToUInt32((String^)IDBox->Items[j], 16));
								 String ^ imgPath = ImportFromDir + Path + FileName + "_" + (String^)IDBox->Items[j] + ".png";
								 //Image ^ inImg = Image::FromFile(imgPath);
								 Bitmap ^ inBmp = gcnew Bitmap(Image::FromFile(imgPath));
								 BitmapData ^ bmpData = inBmp->LockBits(System::Drawing::Rectangle(0,0,inBmp->Width, inBmp->Height), ImageLockMode::ReadOnly, System::Drawing::Imaging::PixelFormat::Format32bppArgb); //Maki 20190522
								 u32 in_length = inBmp->Width * inBmp->Height * 4; //Maki 20190522
								 u8 * in_buffer = nullptr;//new u8[in_length];
								 in_buffer = (u8*)(reinterpret_cast<char*>(bmpData->Scan0.ToPointer()));	
								 MapImportBuffers(imgID, in_buffer, out_buffers, out_buffers4, mult, depths);
								 inBmp->UnlockBits(bmpData);
								 if (j%10 == 9) { System::GC::Collect(); } //prevents memory from collapsing under all these BMPs on large fields
							 }
							 //Save buffers
							 for (int i = 0; i < numpages; i++)
							 {
								 if ((depths[i] == 1 || depths[i] == 3) && out_buffers[i] != nullptr) //8-bit indexed
								 {
									 String ^ outPath = ImportToDir + Path + FileName + "_" + i + ".png"; //filename with page suffix
									 //Create dir if it doesn't exist
									 System::IO::FileInfo ^ tempInfo = gcnew System::IO::FileInfo(outPath);
									 tempInfo->Directory->Create();
									 //Save image
									 Image ^ tempImg = GetImage(out_buffers[i], 128 * 2 * mult, 256 * mult,1); //Maki 20190522
									 tempImg->Save(outPath, Imaging::ImageFormat::Png);
								 }
								 if ((depths[i] == 2 || depths[i] == 3) && out_buffers4[i] != nullptr) //4-bit indexed
								 {
									 String ^ outPath = ImportToDir + Path + FileName + "_" + (i+13) + ".png"; //filename with page suffix, note *10 for 4-bit indexed
									 //Create dir if it doesn't exist
									 System::IO::FileInfo ^ tempInfo = gcnew System::IO::FileInfo(outPath);
									 tempInfo->Directory->Create();
									 //Save image
									 Image ^ tempImg = GetImage(out_buffers4[i], 128 * 2 * mult, 256 * mult,1); //Maki 20190522
									 tempImg->Save(outPath, Imaging::ImageFormat::Png);
								 }
							 }
							 for (int i = 0; i < numpages; i++)
							 {
								 //if (out_buffers[i] != nullptr) { delete[] out_buffers[i]; }
								 //if (out_buffers4[i] != nullptr) { delete[] out_buffers4[i]; }
							 }
							 //if (out_buffers != nullptr) { delete[] out_buffers; }
							 //if (out_buffers4 != nullptr) { delete[] out_buffers4; }
							 if (depths != nullptr) { delete depths; }

							 /*int outwidth = numpages * 128;
							 int outheight = 256;

							 int Xmin(0), Xmax(0), Ymin(0), Ymax(0);
							 for (int i = 0; i < field->NumFISprites; i++)
							 {
								 if ((field->Sprites[i]->ID & 0xFF000000) == (field->Sprites[0]->ID & 0xFF000000))
								 {
									 Xmin = min(Xmin, field->Sprites[i]->X);
									 Xmax = max(Xmax, field->Sprites[i]->X);
									 Ymin = min(Ymin, field->Sprites[i]->Y);
									 Ymax = max(Ymax, field->Sprites[i]->Y);
								 }
							 }
							 int LWidth = Xmax - Xmin + 16;
							 int LHeight = Ymax - Ymin + 16;
							 String ^ checkPath = ImportFromDir + Path + FileName + "_" + ((UInt32)field->Sprites[0]->ID).ToString("X8") + ".png";
							 Image ^ checkImg = Image::FromFile(checkPath);
							 int checkWidth = checkImg->Width;
							 int checkHeight = checkImg->Height;
							 int mult = checkWidth / LWidth;	//Don't need height
							 delete checkPath;
							 delete checkImg;

							 u32 out_length = (outWidth * mult) * (outHeight * mult) * 2; //W * H * Pixel Depth (ARGB1555=2)
							 u8 * out_buffer = new u8 [out_length];
							 for (int i = 0; i < (Int32)out_length; i++)
							 {
								 out_buffer[i] = 0;
							 }
							 for (int j = 0; j < IDBox->Items->Count; j++)
							 {
								 //Get buffer for import
								 u32 imgID = (u32)(Convert::ToUInt32((String^)IDBox->Items[j], 16));
								 String ^ imgPath = ImportFromDir + Path + FileName + "_" + (String^)IDBox->Items[j] + ".png";
								 //Image ^ inImg = Image::FromFile(imgPath);
								 Bitmap ^ inBmp = gcnew Bitmap(Image::FromFile(imgPath));
								 delete imgPath;
								 BitmapData ^ bmpData = inBmp->LockBits(System::Drawing::Rectangle(0,0,inBmp->Width, inBmp->Height), ImageLockMode::ReadOnly, System::Drawing::Imaging::PixelFormat::Format16bppArgb1555);
								 u32 in_length = inBmp->Width * inBmp->Height * 2;
								 u8 * in_buffer = new u8[in_length];
								 in_buffer = (u8*)(reinterpret_cast<char*>(bmpData->Scan0.ToPointer()));	
								 MapImportBuffers(imgID, in_buffer, out_buffer, mult, outWidth);
								 inBmp->UnlockBits(bmpData);
								 //delete inBmp;
								 //delete bmpData;
								 //delete in_buffer;
							 }
							 //Save buffer
							 String ^ outPath = ImportToDir + Path + FileName + ".png";
							 //Create dir if it doesn't exist
							 System::IO::FileInfo ^ tempInfo = gcnew System::IO::FileInfo(outPath);
							 tempInfo->Directory->Create();
							 delete tempInfo;
							 //Save image
							 Image ^ tempImg = GetImage(out_buffer, outWidth * mult, outHeight * mult);
							 tempImg->Save(outPath, Imaging::ImageFormat::Png);
							 //delete tempImg;
							 //delete out_buffer;
							 delete outPath;*/
						 }
						 catch (System::Exception^ /*e*/)
						 {
							MessageBox::Show("Error: Missing import files for " + FieldBox->SelectedItems[i] + "!", L"Error", MessageBoxButtons::OK);
						 }
						 //System::GC::Collect();
					 }
				 }
			 }

			 System::Void MapImportBuffers(u32 ID, u8 * in_buffer, u8 ** out_buffers, u8 ** out_buffers4, int mult, int * depths)
			 {
				 int Xmin(0), Xmax(0), Ymin(0), Ymax(0);
				 for (int i = 0; i < field->NumFISprites; i++)
				 {
					 if ((field->Sprites[i]->ID & 0xFF000000) == (ID & 0xFF000000))
					 {
						 Xmin = min(Xmin, field->Sprites[i]->X);
						 Xmax = max(Xmax, field->Sprites[i]->X);
						 Ymin = min(Ymin, field->Sprites[i]->Y);
						 Ymax = max(Ymax, field->Sprites[i]->Y);
					 }
				 }
				 int tester = 16;
				 int LWidth = Xmax - Xmin + 16;
				 int LHeight = Ymax - Ymin + 16;

				 for (int i = 0; i < field->NumFISprites; i++)
				 {
					 if (field->Sprites[i]->ID == ID)
					 {
						 if (depths[field->Sprites[i]->page] == 1 || depths[field->Sprites[i]->page] == 3)
						 {
							 int source = (((field->Sprites[i]->Y - Ymin) * mult) * (LWidth * mult)) + ((field->Sprites[i]->X - Xmin) * mult);
							 int target = ((field->Sprites[i]->SrcY * mult) * (128 * 2 * mult)) + /*(field->Sprites[i]->page * (128 * mult)) +*/ (field->Sprites[i]->SrcX * mult);
							 for (int j = 0; j < (16 * mult); j++)
							 {
								 for (int k = 0; k < (16 * mult); k++)
								 {				
									memcpy(&out_buffers[field->Sprites[i]->page][(target + ((j * (128 * 2 * mult)) + k)) * 4], &in_buffer[(source + ((j * (LWidth * mult)) + k)) * 4], 4); //Maki 20190522

								}
							 }
						 }
						 if (depths[field->Sprites[i]->page] == 2 || depths[field->Sprites[i]->page] == 3)
						 {
							 int source = (((field->Sprites[i]->Y - Ymin) * mult) * (LWidth * mult)) + ((field->Sprites[i]->X - Xmin) * mult);
							 int target = ((field->Sprites[i]->SrcY * mult) * (128 * 2 * mult)) + /*(field->Sprites[i]->page * (128 * mult)) +*/ (field->Sprites[i]->SrcX * mult);
							 for (int j = 0; j < (16 * mult); j++)
							 {
								 for (int k = 0; k < (16 * mult); k++)
								 {							 
									 memcpy(&out_buffers4[field->Sprites[i]->page][(target + ((j * (128 * 2 * mult)) + k)) * 4], &in_buffer[(source + ((j * (LWidth * mult)) + k)) * 4], 4); //Maki 20190522
								 }
							 }
						 }
					 }
				 }
			 }

	private: System::Void ExportButton_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 if (field != nullptr)
				 {
					 FolderBrowserDialog ^ exportDialog = gcnew FolderBrowserDialog();
					 exportDialog->Description = "Select Destination Folder";
					 if (exportDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					 {
						 ExportDir = exportDialog->SelectedPath;
					 }
					 for (int i = 0; i < FieldBox->SelectedItems->Count; i++)
					 {
						 OpenFile(i);
						 for (int j = 0; j < IDBox->Items->Count; j++)
						 {
							u32 imgID = (u32)(Convert::ToUInt32((String^)IDBox->Items[j], 16));
							String ^ imgPath = ExportDir + Path + FileName + "_" + (String^)IDBox->Items[j] + ".png";
							//Create dir if it doesn't exist
							System::IO::FileInfo ^ tempInfo = gcnew System::IO::FileInfo(imgPath);
							tempInfo->Directory->Create();
							Image ^ tempImg = GetImageForExport(imgID);
							tempImg->Save(imgPath, Imaging::ImageFormat::Png);
						 }
					 }
				 }
			 }

	private: System::Void IDBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
			 {
				 if (field != nullptr)
				 {
					 DisplayImage((u32)(Convert::ToUInt32((String^)IDBox->SelectedItem, 16)));
				 }
			 }

	private: System::Void AboutButton_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				MessageBox::Show("PuPu FF8 Field Importer/Exporter\n\n                     by Omzy\n\nDeveloped for the purpose of\nimproving the field backgrounds\nof one of the greatest games\nof all time.\n\nContribute at forums.Qhimm.com", L"About", MessageBoxButtons::OK);
			 }

	private: System::Void HelpLabel_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e)
			 {
				  String^ target = dynamic_cast<String^>(e->Link->LinkData);
				  if ( nullptr != target && target->StartsWith( "http" ) )
				  {
					 System::Diagnostics::Process::Start( target );
				  }
			 }

};
}

