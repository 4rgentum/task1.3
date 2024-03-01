#include <stdlib.h>
#include "array.h"

int insert_element(int **array, int *size, int element, int index) {
    if (index < 0 || index > *size) {
        return 1;
    }
    *size += 1;
    *array = (int*) realloc(*array, (*size) * sizeof(int));
    for (int i = *size - 1; i > index; i--) {
        (*array)[i] = (*array)[i - 1];
    }
    (*array)[index] = element;
    return 0;
}

int delete_element(int **array, int *size, int index) {
    if (index < 0 ||  index >= *size) {
        return 1;
    }
    for (int i = index; i < (*size) - 1; i++) {
        (*array) [i] = (*array) [i + 1];
    }
    (*size)--;
    *array = (int*) realloc(*array, (*size) * sizeof (int));
    if (array == NULL) {
        return 1;
    }
    return 0;
}

int simple_checker(int n) {
    int flag = 0;
    if (n > 1) {
        if (n == 2) {
      flag = 1;
            return flag;
        }
        for (int j = 2; j < n; j++) {
            if (n % j == 0) {
    flag = 0;
                return flag;
            } else {
    flag = 1;
      }
        }
  return flag;
    }
    return flag;
}

int number_of_simple(const int *array, int size) {
    int new_size = 0;
    int flag = 0;
    for (int i = 0; i < size; i++) {
        flag = simple_checker(array[i]);
        if (flag == 1) {
            new_size += 1;
            flag = 0;
        }
    }
    return new_size;
}

int *simple_numbers(int *array, int size, int *answer_size) {
    int new_size = number_of_simple(array, size);
    *answer_size = number_of_simple(array, size);
    int *answer = (int*) malloc(new_size * sizeof(int));
        int k = 0;
        int flag = 0;
        for (int i = 0; i < size; i++) {
            flag = simple_checker(array[i]);
            if (flag == 1) {
                answer[k] = array[i];
                k += 1;
                flag = 0;
            }
        }
        return answer;
}

int *rewrite_array(int **array, int *size) {
    for (int i = 0; i < *size; i++) {
        if (simple_checker((*array)[i]) == 1) {
            delete_element(array, size, i);
      i--;
        }
    }
    return (*array);
}
