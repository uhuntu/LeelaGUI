#ifndef FILEOPEN_PNG_H
#define FILEOPEN_PNG_H

#include <wx/mstream.h>
#include <wx/image.h>
#include <wx/bitmap.h>

static const unsigned char fileopen_png[] = 
{
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 
	0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x10, 
	0x00, 0x00, 0x00, 0x0F, 0x08, 0x06, 0x00, 0x00, 0x00, 0xED, 
	0x73, 0x4F, 0x2F, 0x00, 0x00, 0x00, 0x01, 0x73, 0x52, 0x47, 
	0x42, 0x00, 0xAE, 0xCE, 0x1C, 0xE9, 0x00, 0x00, 0x00, 0x04, 
	0x67, 0x41, 0x4D, 0x41, 0x00, 0x00, 0xB1, 0x8F, 0x0B, 0xFC, 
	0x61, 0x05, 0x00, 0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 
	0x00, 0x00, 0x0B, 0x11, 0x00, 0x00, 0x0B, 0x11, 0x01, 0x7F, 
	0x64, 0x5F, 0x91, 0x00, 0x00, 0x00, 0x19, 0x74, 0x45, 0x58, 
	0x74, 0x53, 0x6F, 0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x00, 
	0x70, 0x61, 0x69, 0x6E, 0x74, 0x2E, 0x6E, 0x65, 0x74, 0x20, 
	0x34, 0x2E, 0x30, 0x2E, 0x31, 0x36, 0x44, 0x69, 0xAF, 0xF5, 
	0x00, 0x00, 0x00, 0xE0, 0x49, 0x44, 0x41, 0x54, 0x38, 0x4F, 
	0xA5, 0x91, 0xB1, 0x0A, 0xC2, 0x30, 0x10, 0x86, 0xFB, 0x2A, 
	0x3E, 0x85, 0x8F, 0xE1, 0x20, 0xBE, 0x81, 0xAB, 0xAB, 0xE0, 
	0x28, 0x22, 0xB8, 0x74, 0x13, 0x51, 0x27, 0x41, 0x07, 0x1D, 
	0x5C, 0xC5, 0x6E, 0x05, 0x27, 0x9D, 0x44, 0x9C, 0x1C, 0x74, 
	0x2F, 0x88, 0xE0, 0x0B, 0x9C, 0x7C, 0x81, 0x2B, 0x49, 0xDA, 
	0x06, 0xD4, 0xE1, 0x23, 0x4D, 0x7A, 0xFF, 0xC7, 0x5D, 0x12, 
	0x89, 0xC8, 0x5F, 0x94, 0x1E, 0xF6, 0x27, 0x2B, 0xB1, 0xF1, 
	0xFF, 0xDB, 0x14, 0x8A, 0x21, 0x4D, 0x53, 0xA9, 0xB7, 0x87, 
	0x72, 0x7F, 0x9D, 0x0D, 0x9C, 0xF9, 0x41, 0x25, 0xAA, 0xB5, 
	0x7A, 0x12, 0x2F, 0x12, 0x87, 0x46, 0x77, 0x2C, 0xC7, 0xCB, 
	0xC3, 0x48, 0x92, 0x5B, 0x1C, 0x94, 0x94, 0x0A, 0x06, 0xB3, 
	0xAD, 0x74, 0x46, 0x4B, 0x83, 0x2F, 0x51, 0x82, 0x02, 0x1B, 
	0x5B, 0x40, 0xED, 0xFE, 0x70, 0x2D, 0x17, 0xB0, 0xDA, 0x10, 
	0x54, 0xE6, 0x59, 0x33, 0x17, 0x80, 0x76, 0x41, 0xA7, 0x8E, 
	0x00, 0x3B, 0xE8, 0xFC, 0x04, 0x7D, 0x54, 0x94, 0x3D, 0xDF, 
	0xE6, 0xAE, 0x8C, 0x00, 0x13, 0xEB, 0x7A, 0x77, 0x0A, 0x4A, 
	0xEC, 0x30, 0x35, 0x79, 0x07, 0x2A, 0x99, 0x6E, 0x52, 0x47, 
	0x02, 0xFE, 0x08, 0x84, 0x81, 0xFA, 0xFC, 0x0E, 0x80, 0x31, 
	0x10, 0x54, 0x49, 0xEC, 0x70, 0x41, 0xC0, 0x2C, 0x1C, 0x84, 
	0x24, 0x8C, 0x04, 0x84, 0xD9, 0x3B, 0x02, 0xDE, 0x5B, 0x6F, 
	0xB5, 0x4A, 0xA2, 0x02, 0xD0, 0xB0, 0x11, 0xE8, 0x93, 0x7C, 
	0x83, 0x23, 0xD0, 0x8F, 0xDF, 0x90, 0xE8, 0x03, 0x14, 0x71, 
	0xAF, 0x3E, 0xB8, 0xED, 0x5E, 0x1C, 0x00, 0x00, 0x00, 0x00, 
	0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82, 
};

wxBitmap& fileopen_png_to_wx_bitmap()
{
	static wxMemoryInputStream memIStream( fileopen_png, sizeof( fileopen_png ) );
	static wxImage image( memIStream, wxBITMAP_TYPE_PNG );
	static wxBitmap bmp( image );
	return bmp;
};


#endif //FILEOPEN_PNG_H
