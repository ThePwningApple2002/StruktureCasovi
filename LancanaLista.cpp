#include "LancanaLista.h"

int LancanaLista::Sum()
{
	int s = 0;
	Node* tmp = head;
	while (tmp->next != nullptr) {
		if (tmp->vr % 2 == 0) {
			s = s + tmp->vr;
		}
		
		tmp = tmp->next;
	}
	return s;
}

void LancanaLista::Add(Node* p)
{
	p->next = head;
	head = p;
}

void LancanaLista::Print()
{
	Node* tmp = head;
	while (tmp != nullptr) {
		printf("%d ", tmp->vr);
		tmp = tmp->next;
	}
	printf("\n");
}