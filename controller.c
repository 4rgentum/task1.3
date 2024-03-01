#include <stdio.h>
#include"controller.h"
#include "view.h"
#include "array.h"
#include <stdlib.h>

void controller() {
    int *array;
    array = (int*) malloc(1 * sizeof(int));
    int size = 0;
    int *answer;
    answer = (int*) malloc(1 * sizeof(int));
    int new_size = 0;
    int fl;
    printf("Do You Want To Start The Program?\n");
    printf("Enter 1 If Yes, Another Number If No\n");
    int fl_flag = scanf("%d", &fl);
    while (fl_flag != 1) {
        printf("Incorrectly Entered Flag\n");
        printf("Enter 1 If Yes, Another Number If No\n");
        scanf("%*[^\n]");
        scanf("%*c");
        fl_flag = scanf("%d", &fl);
    }
    while (fl == 1) {
        menu();
        int n;
        printf("Enter Direction From 0 To 5:\n");
        int n_flag = scanf("%d", &n);
        while (n_flag != 1) {
            printf("Incorrectly Entered Direction\n");
            printf("Enter Correct Direction:\n");
            scanf("%*[^\n]");
            scanf("%*c");
            n_flag = scanf("%d", &n);
        }
        if (n < 0 || n > 5) {
            printf("This Point Doesn't Exist\n");
      printf("Enter Correct Direction:\n");
        } else {
            switch (n) {
                case 0: {
                    free(array);
                    free(answer);
                    return;
                }
                case 1: {
                    printf("Enter Size Of Array:\n");
                    int size_flag = scanf("%d", &size);
                    while (size_flag != 1 || size == 0) {
                        printf("Incorrectly Entered Size Of Array\n");
                        printf("Enter Correct Size Of Array:\n");
                        scanf("%*[^\n]");
                        scanf("%*c");
                        size_flag = scanf("%d", &size);
                    }
                    if (size != 0) {
                        free(array);
                    }
                    array = (int*) malloc(size * sizeof(int));
                    for (int i = 0; i < size; i++) {
                        int value_flag = scanf("%d", &array[i]);
                        while (value_flag != 1) {
                            printf("Incorrectly Array Value\n");
                            printf("Enter Correct Array Value:\n");
                            scanf("%*[^\n]");
                            scanf("%*c");
                            value_flag = scanf("%d", &array[i]);
                        }
                    }
                    break;
                }
                case 2: {
                    int index;
                    printf("Enter Positive Integer Index Where Do You Want To Insert Element:\n");
                    int index_flag = scanf("%d", &index);
                    if (index >= 0) {
                        while (index_flag != 1) {
                            printf("Incorrectly Entered Index Where Do You Want To Insert Element\n");
                            printf("Enter Positive Correct Index Where Do You Want To Insert Element:\n");
                            scanf("%*[^\n]");
                            scanf("%*c");
                            index_flag = scanf("%d", &index);
                        }
                        int element;
                        printf("Enter Integer Element Which Do You Want To Insert:\n");
                        int size_flag = scanf("%d", &element);
                        while (size_flag != 1) {
                            printf("Incorrectly Entered Element Which Do You Want To Insert\n");
                            printf("Enter Correct Integer Element Which Do You Want To Insert:\n");
                            scanf("%*[^\n]");
                            scanf("%*c");
                            size_flag = scanf("%d", &element);
                        }
                        if (index >= size) {
                            index = size;
                            insert_element(&array, &size, element, index);
                        } else {
          insert_element(&array, &size, element, index);
      }

} else {
                        while (index_flag != 1 || index < 0) {
                            printf("Incorrectly Entered Index Where Do You Want To Insert Element\n");
                            printf("Enter Positive Correct Index Where Do You Want To Insert Element:\n");
                            scanf("%*[^\n]");
                            scanf("%*c");
                            index_flag = scanf("%d", &index);
                        }
                        int element;
                        printf("Enter Integer Element Which Do You Want To Insert:\n");
                        int size_flag = scanf("%d", &element);
                        while (size_flag != 1) {
                            printf("Incorrectly Entered Element Which Do You Want To Insert\n");
                            printf("Enter Correct Integer Element Which Do You Want To Insert:\n");
                            scanf("%*[^\n]");
                            scanf("%*c");
                            size_flag = scanf("%d", &element);
                        }
                        if (index >= size) {
                            index = size;
                            insert_element(&array, &size, element, index);
                        } else {
                            insert_element(&array, &size, element, index);
                        }
                    }
                    break;
                }
                case 3: {
                    int index_delete;
                    printf("Enter Positive Integer Index Which Element Do You Want To Delete:\n");
                    int size_flag = scanf("%d", &index_delete);
                    if (index_delete >= 0) {
                        while (size_flag != 1) {
                            printf("Incorrectly Entered Index Which Element Do You Want To Delete\n");
                            printf("Enter Positive Integer Correct Index Which Element Do You Want To Delete:\n");
                            scanf("%*[^\n]");
                            scanf("%*c");
                            size_flag = scanf("%d", &index_delete);
                        }
                        delete_element(&array, &size, index_delete);
                    } else {
                        while (size_flag != 1 || index_delete < 0) {
                            printf("Incorrectly Entered Index Which Element Do You Want To Delete\n");
                            printf("Enter Positive Integer Correct Index Which Element Do You Want To Delete:\n");
                            scanf("%*[^\n]");
                            scanf("%*c");
                            size_flag = scanf("%d", &index_delete);
                        }
                        delete_element(&array, &size, index_delete);
                    }
                    break;
                }
                case 4: {
                    free(answer);
                    answer = simple_numbers(array, size, &new_size);
                    rewrite_array(&array, &size);
                    break;
                }
                case 5: {
                    int flag;
                    printf("What Array Do You Want To Print?\n");
                    printf("Enter 1 If You Want Simple Numbers Array, 0 If You Want Begin Array:\n");
                    int flag_flag = scanf("%d", &flag);
                    while (flag_flag != 1) {
                        printf("Incorrectly Entered Flag\n");
                        printf("Enter 1 If You Want Simple Numbers Array, 0 If You Want Begin Array:\n");
                        scanf("%*[^\n]");
                        scanf("%*c");
                        flag_flag = scanf("%d", &flag);
                    }
                    if (flag == 1) {
                        print_array(answer, new_size);
                    } else if (flag == 0) {
                        print_array(array, size);
                    } else {
                        printf("Wrong Flag\n");
                    }
                }

default: {
                    break;
                }
            }
        }
    }
    free(array);
    free(answer);
}
