#ifndef __AboutDialog__
#define __AboutDialog__

#include "stdafx.h"

/**
@file
Subclass of TAboutDialog, which is generated by wxFormBuilder.
*/

#include "GUI.h"

/** Implementing TAboutDialog */
class AboutDialog : public TAboutDialog
{
protected:	
        void doInit( wxInitDialogEvent& event );	
public:
	/** Constructor */
	AboutDialog( wxWindow* parent );
};

#endif // __AboutDialog__
