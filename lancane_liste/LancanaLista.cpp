#include "LancanaLista.h"
#include <iostream>
using namespace std;
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



LancanaLista* LancanaLista::SplitOrMove() {
    LancanaLista* novaLista = new LancanaLista();
    if (this->head == nullptr) {
        return novaLista;
    }

    Node* novaListaTail = nullptr;
    Node* prev = nullptr;
    Node* current = this->head;

    while (current != nullptr) {
        bool duplicateFound = false;
        Node* runner_prev = current;
        Node* runner = current->next;

        while (runner != nullptr) {
            if (runner->vr == current->vr) {
                duplicateFound = true;
                
                runner_prev->next = runner->next;
                Node* nodeToMove = runner;

                nodeToMove->next = nullptr;
                if (novaLista->head == nullptr) {
                    novaLista->head = nodeToMove;
                    novaListaTail = nodeToMove;
                } else {
                    novaListaTail->next = nodeToMove;
                    novaListaTail = nodeToMove;
                }
                
                break;
            }
            runner_prev = runner;
            runner = runner->next;
        }

        if (duplicateFound) {
            prev = current;
            current = current->next;
        } else {
            Node* nodeToMove = current;
            current = current->next;

            if (prev == nullptr) {
                this->head = current;
            } else {
                prev->next = current;
            }

            nodeToMove->next = nullptr;
            if (novaLista->head == nullptr) {
                novaLista->head = nodeToMove;
                novaListaTail = nodeToMove;
            } else {
                novaListaTail->next = nodeToMove;
                novaListaTail = nodeToMove;
            }
        }
    }

    return novaLista;
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

void LancanaLista::min()
{
	if(head==nullptr){
		return;
	}
	Node* tmp=head;
	Node* min=head;
	Node* prev=nullptr;
	while(tmp->next!=nullptr)
	{
		if(min->vr>tmp->next->vr){
			prev=tmp;
			min=tmp->next;
		}
		tmp=tmp->next;
	}
	prev->next=min->next;
	min->next=head;
	head=min;

}
void LancanaLista::InjectorRemove(int br){
	if(head==nullptr)
		return;
	if(head->vr==br){
		Node* pom=head;
		head=head->next;
		delete pom;
	}
	Node* tmp=head;
	Node* prev;
	while(tmp!=nullptr){
		if(tmp->vr==br){
			prev->next=tmp->next;
			delete tmp;
			return ;
		}
		else if(tmp->vr>br){
			cout<<tmp->vr;
			Node* tmp2=new Node(br);
			tmp2->next=tmp;
			prev->next=tmp2;
			return ;
		}
		prev=tmp;
		tmp=tmp->next;
	}
	
	
}

void LancanaLista::fillmissingitems()
{
	if(head==nullptr){
		Node* tmp1=new Node(0);
		head=tmp1;
	}
	if(head->next==nullptr)
	{
		Node* tmp1=new Node(1);
		head->next=tmp1;
	}
	Node* prev;
	Node* cur=head;
	for(int i=1;i<101;i++){
		if(cur->vr==i){
			cout<<i<<" prvi if"<<endl;
			prev=cur;
			cur=cur->next;
			continue;
		}
		if(cur->vr>i ){
			cout<<endl;
			cout<<cur->vr;
			cout<<endl;
			cout<<i;
			cout<<endl;
			Node* tmp2=new Node(i);
			tmp2->next=cur;
			prev->next=tmp2;
			cur=tmp2->next;
			prev=tmp2;
		}
		else if(cur->next==nullptr)
		{
			cout<<i<<" treci if"<<endl;
			cur->next=new Node(i);
			prev=cur;

			cur=cur->next;
		}
		else{
			prev=cur;
			cur=cur->next;
		}
	}
	prev->next=nullptr;//posle 100 null
	while(cur!=nullptr){
		Node* pom=cur;
		cur=cur->next;
		delete pom;
	}



}

