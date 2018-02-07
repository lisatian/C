#include <stdio.h>
#include "llist.h"

#define DEBUG 1

int main(void) {
    setbuf(stdout, NULL);
    
    node_type *start = NULL;
    node_type *np;
    
    insert_beg(&start, 1);
    insert_beg(&start, 2);
    insert_end(&start, 3);
    insert_end(&start, 4);
    display(start);
    
#if DEBUG
    printf("\n");
    display_reverse(start);
#endif
    
    np = search(start, 4);
    printf("Value found %d\n", get_data(np));
    
    printf("Delete node of value %d\n", 4);
    delete(&start, 4);
    display(start);
    
    int num = 0;
    int input = 1;
    
    while (input != 6) {
        printf("\n-- Menu Selection --\n");
        printf("0) Insert front\n");
        printf("1) Insert end\n");
        printf("2) Search\n");
        printf("3) Delete\n");
        printf("4) Display Forward\n");
        printf("5) Display Reverse\n");
        printf("6) Quit\n");
        
        scanf("%d", &input);
        
        switch (input) {
            case 0:
                printf("Your choice: `Insertion front'\n");
                printf("Enter the value to be inserted: ");
                scanf("%d", &num);
                insert_beg(&start, num);
                break;
                
            case 1:
                printf("Your choice: `Insertion end'\n");
                printf("Enter the value to be inserted: ");
                scanf("%d", &num);
                insert_end(&start, num);
                break;
                
            case 2:
                printf("Your choice: `Search'\n");
                printf("Enter the value you want to find: ");
                scanf("%d", &num);
                np = search(start, num);
                
                if (np == NULL)
                    printf("not found\n");
                else
                    printf("Value found %d\n", get_data(np));
                break;
                
            case 3:
                printf("Your choice: `Deletion'\n");
                printf("Enter the value which should be deleted: ");
                scanf("%d", &num);
                delete(&start, num);
                break;
                
            case 4:
                printf("You choice: `Display Forward'\n");
                display(start);
                break;
                
            case 5:
                printf("You choice: `Display Reverse'\n");
                display_reverse(start);
                break;
                
            case 6:
            default:
                printf("Goodbye ...\n");
                break;
                
        }
    }
    clean(start);
    
    return (0);
}
