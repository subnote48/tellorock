//
//
//

#ifndef TELLOROCK_FONTHELPER_H
#define TELLOROCK_FONTHELPER_H

#include "../AppInit/AppInit.h"

struct ImFont;

class FontHelper
{
public:
	FontHelper(HWND hWnd);

	FontHelper& Get();

	ImFont* MonoFont{ nullptr };
	ImFont* RegFont{ nullptr };

	HWND GetMainHwnd() const;

private:
	FontHelper* _font;
	HWND _hwnd;
};

#endif //TELLOROCK_FONTHELPER_H