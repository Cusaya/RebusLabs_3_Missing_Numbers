#include <stdio.h>
#include <stdlib.h>

struct linked_list {
	int value;
	int counter;
	struct linked_list * next;
};


void linked_printer(struct linked_list * ptr) {
		while (ptr->next != NULL) {   //son elemana gelmedikçe
			printf("Eleman: %d   Adet: %d\n", ptr->value, ptr->counter);
			ptr = ptr->next;
		}
		printf("Eleman: %d   Adet: %d\n", ptr->value, ptr->counter); //son eleman
}


void linked_list_comparator(struct linked_list * b, struct linked_list * a, struct linked_list * a_ref , int * final_array_pointer){

	int flag = 0;

	while (b != NULL) {
		flag = 0;
		while (a != NULL) {
			if (b->value == a->value) {
				flag++;
				if (b->counter == a->counter)
					;
				else {
					*final_array_pointer = b->value;
					final_array_pointer = final_array_pointer + 1;
				}
			}
			a = a->next;
		}
		a = a_ref;
			if (flag == 0) {
				*final_array_pointer = b->value;
				final_array_pointer = final_array_pointer + 1;
			}
		b = b->next;
	}

}


void final_array_printer(int * final_array_ptr, int final_array_boyut) {

	//bubble sort the final array!
	int temp = 0;

	for (int i = 0; i < final_array_boyut - 1; i++)
		for (int k = 0; k < final_array_boyut - 1 - i; k++)
			if (final_array_ptr[k] > final_array_ptr[k + 1]) {
				temp = final_array_ptr[k + 1];
				final_array_ptr[k + 1] = final_array_ptr[k];
				final_array_ptr[k] = temp;
			}

	for (int i = 0; i < final_array_boyut; i++) {
		printf("%d ", *final_array_ptr);
		final_array_ptr = final_array_ptr + 1 ;
	}

}



void array_to_linked(int * array_pointer , int array_size, struct linked_list * linked_iterator, struct linked_list * linked_first){

	for (int i = 1; i < array_size; i++){
		int flag = 0;
		for (int k = 0; k < i; k++)
			if (array_pointer[i] == array_pointer[k])
				flag++;
		if (flag == 0) {
			linked_iterator = linked_first;
			//root'tan next->NULL'a kadar tara, listeye sondan nesne ekle
			while (linked_iterator->next != NULL) {
				linked_iterator = linked_iterator->next;
			}
			linked_iterator->next = (struct linked_list *) malloc(sizeof(struct linked_list));
			linked_iterator->next->value = array_pointer[i];
			linked_iterator->next->counter = 1;
			linked_iterator->next->next = NULL;
		}
		else {
			linked_iterator = linked_first;
			//muhakkak listededir
			//root'tan Null'a kadar dolaş her nesnede value kontrol yap
			//tutmazsa bir şey yapma, tutarsa counter +1
			//else demek bir'den fazla nesne var linked'da demek!
			while (linked_iterator->next != NULL) {
				if (linked_iterator->value == array_pointer[i])
					linked_iterator->counter++;
				linked_iterator = linked_iterator->next;
			}
			if(linked_iterator->value == array_pointer[i])
				linked_iterator->counter++;
		}
		
	}

}


int main() {

	//// brr dizisini linked list'e cevir !
	printf("brr dizisinde \n");

	int b_boyut = 8;
	int b[8] = { 7,2,5,4,6,3,5,3};

	struct linked_list * b_root = (struct linked_list *)malloc(sizeof(struct linked_list));
	b_root->next = NULL;
	b_root->value = b[0];
	b_root->counter = 1;
	
	struct linked_list * b_iter = b_root;

	array_to_linked(b,b_boyut,b_iter,b_root);
	linked_printer(b_root);


	printf("***************************************************\n");

	//// arr dizisini linked list'e cevir !
	printf("arr dizisinde\n");

	int a_boyut = 6;
	int a[6] = {7,2,5,3,5,3};

	struct linked_list * a_root = (struct linked_list *)malloc(sizeof(struct linked_list));
	a_root->next = NULL;
	a_root->value = a[0];
	a_root->counter = 1;

	struct linked_list * a_iter = a_root;

	array_to_linked(a, a_boyut,a_iter, a_root);
	linked_printer(a_root);

	printf("***************************************************\n");

	// final fark dizisini icin !

	int final_boyut = b_boyut - a_boyut;
	int * final_array = (int *)malloc((final_boyut * sizeof(int)));
	if (final_array == NULL) {
		printf("No space allocated.");
	}

	b_iter = b_root;
	a_iter = a_root;

	linked_list_comparator(b_iter, a_iter, a_root, final_array);
	final_array_printer(final_array,final_boyut);




}
