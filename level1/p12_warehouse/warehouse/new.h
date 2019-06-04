#include"head.h"
list creatnode(list L, char *mod) {
	list l_ = L;
	while (l_->next != NULL)l_ = l_->next;
	l_->next = (list)malloc(sizeof(linkedlist));
	strcpy(l_->next->model, mod);
	l_->next->data = 0;
	l_->next->next = NULL;
	return l_->next;
}
