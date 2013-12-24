#include "stdafx.h"
#include "CppUnitTest.h"
#include "operator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FourNumbersUnit
{
	TEST_CLASS(OpUnit)
	{
	public:
		
		TEST_METHOD(PrintOperators)
		{
			Operator op;
			char *pSym = nullptr;
			size_t cSym = 0;

			bool fContinue = true;
			do{
				fContinue = op.nextOps(&pSym, &cSym);
				for (size_t i = 0; i < cSym; ++i)
				{
					printf("%c", pSym[i]);
				}
				printf("\n");
			} while (fContinue);
		}

	};
}