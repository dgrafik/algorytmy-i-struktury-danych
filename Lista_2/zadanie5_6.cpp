#include <iostream>

struct lnode {
	int key;
	lnode* next;
	lnode(int value, lnode* l = nullptr){
		key = value;
		next = l;
	}
};

lnode* merge(lnode* l1, lnode* l2) {
    lnode tmp(0);
    lnode *l3 = &tmp;
    tmp.next = NULL;

    while (l1 || l2) {
        if (!l2 || l1->key > l2->key) {
            l3->next = l1;
            l1 = l1->next;
        } else {
            l3->next = l2;
            l2 = l2->next;
        }
        l3 = l3->next;
    }

    return tmp.next;
}

void reverse(lnode*&  L) {
    lnode *prev = 0, *next = 0, *current = L;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    L = prev;
}

void show_list(lnode *l) {
    if (!l) return;
    std::cout << l->key << " ";
    return show_list(l->next);
}

int main(void)
{
	lnode* l = new lnode(0);
	for (int i=1; i<=10; i++) {
			l = new lnode(i, l);
	}

	lnode* l1 = new lnode(0);
	for (int i=1; i<=10; i+=2) {
			l1 = new lnode(i, l1);
	}
	lnode* l2 = new lnode(0);
	for (int i=2; i<=29; i+=3) {
			l2 = new lnode(i, l2);
	}

	std::cout<<"List l"<<std::endl;
	show_list(l);
	std::cout<<std::endl;
	reverse(l);
	std::cout<<"Reverse list"<<std::endl;
	show_list(l);
	std::cout<<std::endl;

	std::cout<<"List l1"<<std::endl;
	show_list(l1);
	std::cout<<std::endl;
	std::cout<<"List l2"<<std::endl;
	show_list(l2);
	std::cout<<std::endl;
	lnode* l3 = merge(l1, l2);
	std::cout<<"List l3"<<std::endl;
	show_list(l3);

	return 0;
}
