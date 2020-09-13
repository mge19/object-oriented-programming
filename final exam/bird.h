#pragma once
#include "animal.h"
class bird:public animal{
	public:
		void outputvoice() const;
		bird();
		bird(string name);
};

