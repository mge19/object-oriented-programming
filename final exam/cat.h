#pragma once
#include "animal.h"
#include <string>
class cat:public animal{
	public:
		void outputvoice() const;
		cat();
		cat(string name);
};
