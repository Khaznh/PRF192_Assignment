#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct drink {
    char *id;
    char *name;
    char *type;
    char *unit;
    unsigned long price;
};

struct drink data[50];
int drinks_count = 0;


// ---------------------------------------------
//  Input, Output, Modify
// ---------------------------------------------


void input_drink(char *id, char *name, char *type, char *unit, unsigned long price) {
    int i;
    for (i = 0; i < drinks_count; i++)
    {
        if (strcmp(data[i].id, id) == 0) {
            printf("A drink with id: %s already exists, try another id.", id);
            return;
        }
    }
    
    
    struct drink new = {
        id,
        name,
        type,
        unit,
        price
    };
    data[drinks_count] = new;
    drinks_count++;
}

void print_a_drink(struct drink d) {
    printf("[%s] %s (%s) - %ldd\n", d.id, d.name, d.type, d.price);
}

void print_list() {
    printf("\n");
    int i;
    for (i = 0; i < drinks_count; i++)
    {
        struct drink d = data[i];
        print_a_drink(d);
    }
    printf("\n");
}

void delete_a_drink(char *id) {
    int i, j;
    for (i = 0; i < drinks_count; i++)
    {
        if (strcmp(data[i].id, id) == 0) {
            for (j=i; j<drinks_count-1; j++) {
                data[j] = data[j+1];
            }
            drinks_count--;

        }
    }    
}

void modify_name(char *id, char *new_name) {
    int i;
    int ok = 0;
    int index;
    for (i = 0; i < drinks_count; i++)
    {
        if (strcmp(data[i].id, id) == 0) {
            ok = 1;
            index = i;
        }
    }

    if (!ok) {
        printf("Drink with ID: %s not found.\n", id);
        return;
    }

    data[index].name = new_name;
}


void modify_price(char *id, unsigned long new_price) {
    int i;
    int ok = 0;
    int index;
    for (i = 0; i < drinks_count; i++)
    {
        if (strcmp(data[i].id, id) == 0) {
            ok = 1;
            index = i;
        }
    }

    if (!ok) {
        printf("Drink with ID: %s not found.\n", id);
        return;
    }

    data[index].price = new_price;
}




// ---------------------------------------------
// sorts
// ---------------------------------------------
void sort_by_name() {
    int i, j;
    struct drink t;
    for (i = 0; i < drinks_count; i++)
    {
        for (j = i+1; j<drinks_count; j++) {
            if (strcmp(data[i].name, data[j].name) > 0) {
                t = data[i];
                data[i] = data[j];
                data[j] = t;
            }
        }
    }
}

void sort_by_type() {
    // descending sort (giam? dan`)
    int i, j;
    struct drink t;
    for (i = 0; i < drinks_count; i++)
    {
        for (j = i+1; j<drinks_count; j++) {
            if (strcmp(data[i].type, data[j].type) < 0) {
                t = data[i];
                data[i] = data[j];
                data[j] = t;
            }
        }
    }
}

void sort_by_price() {
    // ascending sort (tang dan`)
    int i, j;
    struct drink t;
    for (i = 0; i < drinks_count; i++)
    {
        for (j = i+1; j<drinks_count; j++) {
            if (data[i].price > data[j].price) {
                t = data[i];
                data[i] = data[j];
                data[j] = t;
            }
        }
    }
}

void sort_by_id() {
    // ascending sort
    int i, j;
    struct drink t;
    for (i = 0; i < drinks_count; i++)
    {
        for (j = i+1; j<drinks_count; j++) {
            if (strcmp(data[i].id, data[j].id) > 0) {
                t = data[i];
                data[i] = data[j];
                data[j] = t;
            }
        }
    }
}


// ---------------------------------------------
// searches
// ---------------------------------------------

void search_by_price_range(unsigned long min, unsigned long max) {
    sort_by_price();
    int i;
    for (i = 0; i < drinks_count; i++)
    {
        if (data[i].price > min && data[i].price < max) {
            print_a_drink(data[i]);
        }
    }
}

unsigned long get_average_price() {
    int i;
    unsigned long sum = 0;
    for (i = 0; i < drinks_count; i++)
    {
        sum += data[i].price;
    }
    return sum / drinks_count;
    
}

unsigned long get_highest_price() {
    int i;
    long max = 0;
    for (i = 0; i < drinks_count; i++)
    {
        if (data[i].price > max) max = data[i].price;
    }
    return max;
}

unsigned long get_lowest_price() {
    int i;
    long min = 99999999;
    for (i = 0; i < drinks_count; i++)
    {
        if (data[i].price < min) min = data[i].price;
    }
    return min;
}





// ---------------------------------------------
//
// ---------------------------------------------
int main() {
    input_drink("WT0001", "nuoc suoi", "water", "ml", 9000);
    input_drink("BB0001", "tra sua tran chau", "boba", "ml", 3000000);
    input_drink("CF0001", "den da khong duong", "coffee", "ml", 20000);
    input_drink("CF0002", "ca phe sua", "coffee", "ml", 25000);
    print_list();
    modify_name("WT0001", "nuoc loc");
    modify_price("BB0001", 30000);
    print_list();
}
