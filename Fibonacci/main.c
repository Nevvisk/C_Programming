#include <stdio.h>
#include <assert.h>
#include <strings.h>
#include <stdlib.h>

char * getALine();
char ** str_split(char * a_str, const char a_delim);
int* split_numbers(char** tokens);
int get_number_of_elements(char** elements);

int main () {
	char * line = getALine();
	char ** tokens = str_split(line, ' ');
    int* nums = split_numbers(tokens);
    int size_of_nums = get_number_of_elements(tokens);
    for (int i = 0; i < size_of_nums; i++) {
        printf("%d", nums[i]);
    }
	for (char **temp = tokens; *temp != NULL; temp++) {
		free(*temp);
	}
    free(nums);
	free(tokens);
	free(line);
}

char * getALine(void) {
	char * line = malloc(100 * sizeof(char)), *linep = line;
	size_t lenmax = 100, len = lenmax;
	int c;

	if (line == NULL) {
		return NULL;
	}

	for (;;) {
		c = fgetc(stdin);
		if (c == EOF) {
			break;
		}

		if (--len == 0) {
			len = lenmax;
			char * linen = realloc(linep, lenmax *=2);
			if (linen == NULL) {
				free(linep);
				return NULL;
			}
			line = linen + (line - linep);
			linep = linen;
		}

		if ((*line++ = c) == '\n') {
			break;
		}
	}
	*line = '\0';
	return linep;
}

char** str_split(char * a_str, const char a_delim) {
	char** result = 0;
	size_t count = 0;
	char * tmp = a_str;
	char * last_white_space = 0;

	while (*tmp) {
		if (a_delim == *tmp) {
			count++;
			last_white_space = tmp;
		}
		tmp++;
	}
	count += last_white_space < (a_str + strlen(a_str) -1);
	count++;
	result = malloc(sizeof(char*) * count);
	
	if (result) {
		size_t idx = 0;
		char * token = strtok(a_str, &a_delim);

		while (token) {
			assert(idx < count);
			*(result + idx++) = strdup(token);
			token = strtok(0, &a_delim);
		}
		assert(idx == count - 1);
		*(result + idx) = NULL;
		}
	return result;
}

int get_number_of_elements(char** elements) {
    if (elements == NULL) {
        return 0;
    }
    int count = 0;
    while (elements[count] != NULL) {
        count++;
    }
    return count;
}

int* split_numbers(char** tokens) {
    if (tokens == NULL) {
        return 0;
    }
    int size_of_char_array = get_number_of_elements(tokens);
    int* numbers_array = calloc(size_of_char_array, sizeof(int)); 
    if (numbers_array == NULL) {
        return NULL;
    }
    for (int i = 0; i < size_of_char_array; i++) {
        numbers_array[i] = atoi(tokens[i]);
    }           
    return numbers_array;
}
