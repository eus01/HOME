#include "Assert_.h"
#include <assert.h>


namespace Lesha {



//-----------------------------------------------------------------------------
#ifdef WIN32

	void Assert_(bool expression, const char* message)
	{
		assert(expression && message);
	}

	void Assert_(bool expression)
	{
		assert(expression);
	}



//-----------------------------------------------------------------------------
#else // Linux



	void Assert_(bool expression, const char* message)
	{
		assert(expression&&message);
	}

	void Assert_(bool expression)
	{
		assert(expression);
	}



#endif



}


