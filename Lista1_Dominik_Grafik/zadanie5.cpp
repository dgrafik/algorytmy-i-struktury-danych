#include <iostream>

struct lnode {
	int key;
	lnode* next;
	lnode(int value, lnode* l = nullptr){
		key = value;
		next = l;
	}
};

int nty(int n, lnode * l){
	int tmp = 1;
	int search;
	while (l != nullptr){
		if (tmp == n) {
			search = l->key;
			break;
		}else {
			++tmp;
			l = l->next;
		}
	}
	if (l == nullptr){search = 0;}
	return search;
}


int main(void)
{

	lnode st(1);
	lnode sec(2, &st);
	lnode thf(4, &sec);
	lnode th(3, &thf);

	std::cout << nty(1, &th) << std::endl;
	std::cout << nty(2, &th) << std::endl;
	std::cout << nty(3, &th) << std::endl;
	std::cout << nty(4, &th) << std::endl;
	std::cout << nty(5, &th) << std::endl;

	// std::cin.get();
	return 0;
}
