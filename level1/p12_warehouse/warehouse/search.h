#include"head.h"
list search(list L, char *mod) {
	list l_ = L;
	bool b = 0;
	while (l_->next != NULL) {
		if (strcmp(l_->model, mod) == 0){
			b = 1;
			break;
		}
		l_ = l_->next;
	}
	if (b == 1)return l_;
	else return NULL;
}
