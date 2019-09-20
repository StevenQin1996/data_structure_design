#include <iostream>
#include <cassert>
using namespace std;
#include "p2set2.h"

int main()
{
 	Set<int> A;
	Set<int> B;
	
	initialize(A);
	initialize(B);

	insert(A,1);
	insert(A,2);
	insert(A,3);
	insert(A,4);
	insert(A,5);
	
	insert(B,2);
	insert(B,4);
	insert(B,6);
	insert(B,8);
	insert(B,10);

	Set<int> C = A && B;
	// What assertions can you make?
	Set<int> D = A || A;
	// What assertions can you make?
	//cout<<3;

	Set<int> E = A - B;
	// What assertions can you make?
	//cout<<3;	
	
	Set<int> F = B - A;
	// What assertions can you make?
	//cout<<4;
	destroy(A);
	destroy(B);
	destroy(C);
	destroy(D);
	destroy(E);
	destroy(F);
}