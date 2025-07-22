#include "LancanaLista.h"
#include <iostream>
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

void LancanaLista::AddToHead(Node* p)
{
	p->next = head;
	head = p;
}

void LancanaLista::AddToTail(Node* p){
	
	if(this->head == nullptr)
		head = p;
	
	if(head->next == nullptr)
		head->next = p;
	
	Node* tmp = head;

	while(tmp->next != nullptr){
		tmp = tmp->next;
	}

	tmp->next=p;

}

bool LancanaLista::DeleteElem(int el){

	if(head == nullptr){
		throw "Prazna";
	}

	if(head->vr == el){
		Node* tmp = head;
		delete tmp;
		return true;
	}

	Node* tmp = head;
	while(tmp->next != nullptr){



		if(tmp->next->vr == el){

			Node* del = tmp->next;
			tmp->next = tmp->next->next;
			delete del;
			std::cout << "\nBrisemo " << el << endl;
			return true;
		}
		tmp = tmp->next;
	}
	return false;

}

void LancanaLista::InstertElem(int a, Node* p){

	if(head == nullptr)
		throw "Prazna";
	
	if(head->vr == a){
		head->next = p;

	}

	Node* tmp = head;
	while(tmp->next != nullptr){

		if(tmp->vr == a){
			p->next = tmp->next;
			tmp->next = p;
			break;
		}
		tmp = tmp->next;
	}



}

bool LancanaLista::Swap(int start, int end){

	if(head == nullptr){
		throw "Prazna";
	}

	if(head->next == nullptr){
		throw "Samo jedan element";
	}

	if(start == end){
		throw "Nista";
	}

	Node* tmp = head;
	Node* prevst, *curst, *prevend, *curend;

	while(tmp->next != nullptr){
		if(tmp->next->vr == start){
			prevst = tmp;
			curst = tmp->next;
		}
		if(tmp->next->vr == end && curst != nullptr){
			prevend = tmp;
			curend = tmp->next;
		}


		tmp = tmp->next;
	}
	if(curst != nullptr && curend != nullptr){
		tmp = curend->next;
		prevst->next = curend;
		prevend->next = curst;
		curend->next = curst->next;
		curst->next = tmp; 
		return true;
	}
	return false;



}

bool LancanaLista::MoveToHead(int start, int end){
	if(head == nullptr){
		throw "Prazna";
	}
	if(head->next == nullptr){
		throw "jedan element";

	}

	if(start == end){
		throw "Isti su start i end";
	}

	Node* tmp = head;
	Node* prevst, *curst, *prevend, *curend;
	while(tmp->next != nullptr){
		if(tmp->next->vr == start){
			prevst = tmp;
			curst = tmp->next;
		}
		if(tmp->next-> vr == end && curst != nullptr){
			prevend = tmp;
			curend = tmp->next;
		}
		tmp = tmp->next;
	}
	if(curst != nullptr && curend != nullptr){
		prevst->next = curend->next;
		curend->next = head;
		head = curst;
		return true;
	}
	return false;



}

bool LancanaLista::DeleteFromStartToHead(int start, int end){
	if(head == nullptr){
		throw "Prazna";
	}

	if(head->next == nullptr){
		throw "Jedan element";

	}

	if(start == end){
		throw "Isti elementi";
	}

	Node* tmp = head;
	Node* prevst, *curst, *curend;
	while(tmp->next != nullptr){
	
		if(tmp->next->vr == start){
			prevst = tmp;
			curst = tmp->next;
		}
		if(tmp->next->vr == end && curst != nullptr){
			curend = tmp->next;
		}
		tmp = tmp->next;
	}
	if(curst != nullptr && curend != nullptr){
		
		prevst->next = curend->next;
		tmp = curst;
		while(tmp->vr != end){
			Node* del = tmp;
			tmp = tmp->next;
			delete del;
		}

		return true;
	}
	return false;

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