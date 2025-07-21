#pragma once
#include "Node.h"
class LancanaLista
{
public:
	Node* head;
	LancanaLista() {
		head = nullptr;
	}
	LancanaLista(Node* p) {
		head = p;
	}
	int Sum();
	void Add(Node* p);

	void Print();
};