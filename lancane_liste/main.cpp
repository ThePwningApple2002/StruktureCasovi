#include "Node.h"
#include "LancanaLista.h"
int main()
{
	Node* s1 = new Node(1);
	Node* s2 = new Node(2);
	Node* s3 = new Node(3);
	Node* s4 = new Node(4);
	LancanaLista* L = new LancanaLista(s1);

	L->AddToHead(s2);
	L->AddToHead(s3);
	L->AddToHead(s4);

	// L->Print();
	// int sum = L->Sum();
	// cout << "Sum of even numbers: " << sum << endl;
	
	// Node* k = new Node(10);
	// L->AddToTail(k);
	// L->Print();

	// L->DeleteElem(2);
	// L->Print();

	// Node* j = new Node(14);

	// L->InstertElem(1, j);
	// L->Print();
	Node* s11 = new Node(1);
	Node* s22 = new Node(1);
	Node* s33 = new Node(2);
	Node* s44 = new Node(3);
	Node* s55 = new Node(5);
	L->AddToHead(s11);
	L->AddToHead(s22);
	L->AddToHead(s33);
	L->AddToHead(s44);
	L->AddToTail(s55);
	// L->Print();
	// L->Swap(22, 1);
	// L->Print();
	// L->DeleteFromStartToHead(22, 3);
	L->Print();
	L->groupSegment(3);
	L->Print();
	return 0;
}
