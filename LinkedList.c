#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE	45

struct film{
	char title[TSIZE];
	int rating;
	struct film * next;
	struct film * prev;
};

char * s_gets(char * st, int n);

int main(void){
	
	struct film * head = NULL;
	struct film * prev = NULL, * current, * previous = NULL;
	struct film * last = NULL;
	char input[TSIZE];
	
	/* Gather and Store information */
	puts("Enter first Movie title:");
	while(s_gets(input, TSIZE) != NULL && input[0] != '\0'){
		previous = prev;	// Added
		
		current = (struct film *) malloc(sizeof(struct film));
		if(head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		current->prev = previous;
		last = current;		// Always set the last Pointer
		strcpy(current->title, input);
		puts("Enter your rating <0-10>:");
		scanf("%d", &current->rating);
		while(getchar() != '\n')
			continue;
		puts("Enter next movie title (empty line to stop):");
		prev = current;
	}
	
	/* Show list of movies */
	if(head == NULL)
		printf("No data entered.  ");
	else {
		printf("========================================= \n");
		printf("Here is the movie list in original order:\n");
		printf("---------------------------------------- \n");
	}
	
	current = head;
	while(current != NULL){
		printf("Movie: %s  Rating: %d\n", current->title, current->rating);
		current = current->next;
	}
	
	/* Show list of Movies in reverse */
	printf("========================================= \n");
	printf("Here is the movie list in reverse order: \n");
	printf("---------------------------------------- \n");
	current = last;
	while(current != NULL){
		printf("Movie: %s  Rating: %d\n", current->title, current->rating);
		current = current->prev;
	}
	
	/* Program done, so free allocated memory */
	current = head;
	while(current != NULL)
	{
		free(current);
		current = current->next;
	}
	
	
	printf("Bye!\n");
	getchar();
	
	return 0;
}

char * s_gets(char * st, int n){
	
	char * ret_val;
	char * find;
	
	ret_val = fgets(st, n, stdin);
	if(ret_val){
		
		find = strchr(st, '\n');  	// look for newline
		if(find){					// if the address is not NULL
			*find = '\0';			// place a null character there
		} else {
			while(getchar() != '\n')
				continue;			// dispose of rest of line
		}
	}
	return ret_val;
}
