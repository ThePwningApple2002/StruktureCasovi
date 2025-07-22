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
	void AddToHead(Node* p);
	void AddToTail(Node* p);
	bool DeleteElem(int el);
	void InstertElem(int el, Node* p);
	bool Swap(int start, int end);
	bool MoveToHead(int start, int end);
	bool DeleteFromStartToHead(int start, int end);
	void Print();
};