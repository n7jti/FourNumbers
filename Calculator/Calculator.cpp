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
#include "Calculator.h"

Calculator::Calculator()
{

}

Calculator::~Calculator()
{

}

void Calculator::push(double dbl)
{
	_stack.push(dbl);
}

double Calculator::pop()
{
	if (_stack.empty()){
		throw new std::logic_error("Stack is empty!");
	}
	double dbl = _stack.top();
	_stack.pop();
	return dbl;
}

void Calculator::clear()
{
	while (!_stack.empty())
	{
		_stack.pop();
	}
}

void Calculator::op(char operand)
{
	switch (operand)
	{
	case '+':
		add();
		break;
	case '-':
		subtract();
		break;
	case '*':
		multiply();
		break;
	case '/':
		divide();
		break;
	case '^':
		power();
		break;
	default:
		throw new std::invalid_argument("Operand Not Recognized!");
	}
}

void Calculator::add()
{
	double operand2 = pop();
	double operand1 = pop();
	push(operand1 + operand2);
}

void Calculator::subtract()
{
	double operand2 = pop();
	double operand1 = pop();
	push(operand1 - operand2);
}

void Calculator::multiply()
{
	double operand2 = pop();
	double operand1 = pop();
	push(operand1 * operand2);
}

void Calculator::divide()
{
	double operand2 = pop();
	double operand1 = pop();
	push(operand1 / operand2);
}

void Calculator::power()
{
	double operand2 = pop();
	double operand1 = pop();
	push(pow(operand1, operand2));
}