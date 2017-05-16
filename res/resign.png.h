#ifndef RESIGN_PNG_H
#define RESIGN_PNG_H

#include <wx/mstream.h>
#include <wx/image.h>
#include <wx/bitmap.h>

static const unsigned char resign_png[] = 
{
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 
	0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x10, 
	0x00, 0x00, 0x00, 0x0F, 0x08, 0x06, 0x00, 0x00, 0x00, 0xED, 
	0x73, 0x4F, 0x2F, 0x00, 0x00, 0x00, 0x01, 0x73, 0x52, 0x47, 
	0x42, 0x00, 0xAE, 0xCE, 0x1C, 0xE9, 0x00, 0x00, 0x00, 0x04, 
	0x67, 0x41, 0x4D, 0x41, 0x00, 0x00, 0xB1, 0x8F, 0x0B, 0xFC, 
	0x61, 0x05, 0x00, 0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 
	0x00, 0x00, 0x0E, 0xC2, 0x00, 0x00, 0x0E, 0xC2, 0x01, 0x15, 
	0x28, 0x4A, 0x80, 0x00, 0x00, 0x00, 0x19, 0x74, 0x45, 0x58, 
	0x74, 0x53, 0x6F, 0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x00, 
	0x70, 0x61, 0x69, 0x6E, 0x74, 0x2E, 0x6E, 0x65, 0x74, 0x20, 
	0x34, 0x2E, 0x30, 0x2E, 0x31, 0x36, 0x44, 0x69, 0xAF, 0xF5, 
	0x00, 0x00, 0x00, 0x36, 0x49, 0x44, 0x41, 0x54, 0x38, 0x4F, 
	0x63, 0xF8, 0xFF, 0xFF, 0x3F, 0x45, 0x18, 0xAB, 0x20, 0x06, 
	0x76, 0x70, 0xF8, 0x8F, 0x81, 0xA1, 0x72, 0x98, 0x8A, 0xB1, 
	0xE1, 0x51, 0x03, 0x46, 0x0D, 0x00, 0xE1, 0xC1, 0x63, 0x00, 
	0x3A, 0x1B, 0x88, 0x31, 0x15, 0x63, 0xC3, 0x48, 0x1A, 0xD0, 
	0xF9, 0x08, 0x41, 0xB2, 0xF0, 0x7F, 0x06, 0x00, 0x3A, 0x39, 
	0xAF, 0x0C, 0x08, 0xE6, 0x05, 0x6C, 0x00, 0x00, 0x00, 0x00, 
	0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82, 
};

wxBitmap& resign_png_to_wx_bitmap()
{
	static wxMemoryInputStream memIStream( resign_png, sizeof( resign_png ) );
	static wxImage image( memIStream, wxBITMAP_TYPE_PNG );
	static wxBitmap bmp( image );
	return bmp;
};


#endif //RESIGN_PNG_H