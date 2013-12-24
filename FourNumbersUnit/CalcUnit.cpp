// Copyright 2013 Alan Ludwig
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http ://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "stdafx.h"
#include "CppUnitTest.h"
#include "Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnit
{		
	TEST_CLASS(CUnit)
	{
	public:
		
		TEST_METHOD(pushPop)
		{
			Calculator calc;
			calc.push(1.0);
			calc.push(2.0);
			Assert::AreEqual(calc.pop(), 2.0);
			Assert::AreEqual(calc.pop(), 1.0);
		}

		TEST_METHOD(add)
		{
			Calculator calc;
			calc.push(5.0);
			calc.push(7.0);
			calc.op('+');
			double ans = calc.pop();
			Assert::AreEqual(12.0, ans, 1.0E-3, L"add() did not return the expected results!");
		}

		TEST_METHOD(subtract)
		{
			Calculator calc;
			calc.push(5.0);
			calc.push(7.0);
			calc.op('-');
			double ans = calc.pop();
			Assert::AreEqual(-2.0, ans, 1.0E-3, L"subtract() did not return the expected results!");
		}

		TEST_METHOD(multiply)
		{
			Calculator calc;
			calc.push(5.0);
			calc.push(7.0);
			calc.op('*');
			double ans = calc.pop();
			Assert::AreEqual(35.0, ans, 1.0E-3, L"multiply() did not return the expected results!");
		}

		TEST_METHOD(divide)
		{
			Calculator calc;
			calc.push(15.0);
			calc.push(5.0);
			calc.op('/');
			double ans = calc.pop();
			Assert::AreEqual(3.0, ans, 1.0E-3, L"Divide() did not return the expected results!");
		}

		TEST_METHOD(power)
		{
			Calculator calc;
			calc.push(2.0);
			calc.push(8.0);
			calc.op('^');
			double ans = calc.pop();
			Assert::AreEqual(256.0, ans, 1.0E-3, L"add() did not return the expected results!");
		}

	};
}