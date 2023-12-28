//
//
//

#ifndef TELLOROCK_UTILTELLO_H
#define TELLOROCK_UTILTELLO_H

#include "../AppInit/AppInit.h"



class UtilTello
{
public:
	std::string exec(const char* cmd);

	void AppendToBuffer(const char* str, char* inputBuffer);
	void AppendToBufferW(const wchar_t* str, wchar_t* inputBuffer);
};

#endif //TELLOROCK_UTILTELLO_H