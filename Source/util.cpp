#include <stdio.h>
#include <stdlib.h>
#include "util.h"
//=============================================================================

int nextCommand(int *i, int *v, int *f) {
	char c;
	while(1){
		scanf("%c", &c);
		if (c == ' ' || c == '\t' || c == '\n'){
			continue;
		}
		if (c == 'S' || c == 'R' || c == 'W'){
			break;
		}
		if (c == 's' || c == 'r' || c == 'w'){
			
			break;
		}
		if (c == 'K' || c == 'k'){
			scanf("%d", i); scanf("%d", v); scanf("%d", v);
			break;
		}
		if (c == 'i' || c == 'I') {
			break;
		}
		if(c == 'd' || c == 'D') {
			break;
		}
		printf("Invalid Command\n");
	}
	return c;
}