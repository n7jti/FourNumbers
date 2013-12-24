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
#include "Operator.h"
#include <math.h>
#include <cstring>

#define COUT_OF_OPERATORS 3

char* Operator::pOpList = "+-*/^";
size_t Operator::cOpList = strlen(pOpList);

Operator::Operator()
	: pOps(nullptr)
	, aOpIndexes(nullptr)
	, cOps(COUT_OF_OPERATORS)
{
	pOps = new char[cOps];
	ZeroMemory(pOps, cOps * sizeof(pOps[0]));

	aOpIndexes = new size_t[cOps];
	reset();
}

Operator::~Operator(){
	delete[] pOps;
	pOps = nullptr; 

	delete[] aOpIndexes;
	aOpIndexes = nullptr;

	cOps = 0;
}

void Operator::reset(){
	
	for (size_t index = 0; index < cOps; ++index){
		aOpIndexes[index] = cOpList - 1;
	}
	
	//ZeroMemory(aOpIndexes, cOps * sizeof(aOpIndexes[0]));
}

bool Operator::nextOps(char** ppOps, size_t* cOps){
	*ppOps = nullptr;

	aOpIndexes[0] += 1;
	size_t i = 0;
	for (i = 0; i < this->cOps - 1; i++)
	{
		aOpIndexes[i + 1] += aOpIndexes[i] / this->cOpList;
		aOpIndexes[i] = aOpIndexes[i] % this->cOpList;
		pOps[i] = pOpList[aOpIndexes[i]];
	}
	aOpIndexes[i] %= this->cOpList;
	pOps[i] = pOpList[aOpIndexes[i]];
	
	bool fDone = true;
	for (i = 0; i < this->cOps; i++)
	{
		fDone = fDone && (aOpIndexes[i] == (this->cOpList - 1));
	}

	*ppOps = this->pOps;
	*cOps = this->cOps;

	return !fDone;
}