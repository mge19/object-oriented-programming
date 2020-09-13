#pragma once
#include "animal.h"
#include <string>
class dog:public animal{
	public:
		void outputvoice() const;
		dog();
		dog(string name);
};
