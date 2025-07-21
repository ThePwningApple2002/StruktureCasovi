#include "Node.h"
#include "LancanaLista.h"
int main()
{
	Node* s1 = new Node(1);
	Node* s2 = new Node(2);
	Node* s3 = new Node(3);
	Node* s4 = new Node(4);
	LancanaLista* L = new LancanaLista(s1);
	L->Add(s2);
	L->Add(s3);
	L->Add(s4);
	L->Print();
	int sum = L->Sum();
	cout << "Sum of even numbers: " << sum << endl;
	return 0;
}