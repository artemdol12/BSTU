#pragma once
#include <cstdarg>
using namespace std;

namespace Varparm
{
	int ivarparm(int a, ...);
	int svarparm(short a, ...);
	double fvarparm(float a, ...);
	double dvarparm(double a, ...);
};
