#pragma once
#include "iostream"
using namespace std;
class Node
{
public:
	int vr;
	Node* next;
	Node() {
		vr = 0;
		next = nullptr;
	}
	Node(int e) {
		vr = e;
		next = nullptr;
	}
};