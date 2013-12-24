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

// This implements a simple RPN calculator.  (Think HP Calculators from the 80's)
// It has a stack, operands are pushed onto the stack, then operators are executed 
// against the stack.  with the answers being pushed back onto the stack

#include <stack>

class Calculator{

public:
	Calculator();
	~Calculator();

	void push(double);
	double pop();
	void op(char operand);
	void clear();

private:
	void add();
	void subtract();
	void multiply();
	void divide();
	void power();

	std::stack<double> _stack;
};