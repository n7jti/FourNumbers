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

// FourNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FourNumbers.h"
#include "Operator.h"
#include "Calculator.h"
#include <algorithm>
#include <iostream>
#include <vector>

int wmain(int argc, wchar_t* argv[])
{
	std::vector<double> numbers(4);
	double ans;

	// Load the input
	for (int i = 0; i < 4; ++i)
	{
		numbers[i] = _wtof(argv[i + 1]);
	}

	ans = _wtof(argv[5]);

    // Sort the inputs so we can calculate the permutations
	std::sort(numbers.begin(), numbers.end());
	Operator ops;

	do{
		ops.reset();
		char* pOpsSymbol = nullptr; 
		size_t cOpsSymbol = 0;

		Calculator calc;

		bool fNotDone = true;
		do{
			fNotDone = ops.nextOps(&pOpsSymbol, &cOpsSymbol);
			calc.clear();
		
			// Run the calculation through the RPN calculator
			calc.push(numbers[0]);
			calc.push(numbers[1]);
			calc.op(pOpsSymbol[0]);
			calc.push(numbers[2]);
			calc.op(pOpsSymbol[1]);
			calc.push(numbers[3]);
			calc.op(pOpsSymbol[2]);
			
			double calcAns = calc.pop();
			if (calcAns == ans){
				printf("(((%f %c %f) %c %f) %c %f) = %f\n"
					, numbers[0]
					, pOpsSymbol[0]
					, numbers[1]
					, pOpsSymbol[1]
					, numbers[2]
					, pOpsSymbol[2]
					, numbers[3]
					, calcAns);
			}

		} while (fNotDone);

	} while (std::next_permutation(numbers.begin(), numbers.end()));

	return 0;
}


