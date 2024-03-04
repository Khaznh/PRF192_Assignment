#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct drink {
    unsigned int id;
    char *name;
    char *type;
    char *unit;
    unsigned int price;
};

struct drink data[50];
int drinks_count = 0;


// ---------------------------------------------
//  Input, Output, Modify
// ---------------------------------------------


void input_drink(unsigned int id, char *name, char *type, char *unit, unsigned int price) {
    int i;
    for (i = 0; i < drinks_count; i++)
    {
        if (data[i].id == id) {
            printf("A drink with id: %d already exists, try another id.", id);
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
    printf("[%d] %s (%s) - %dd\n", d.id, d.name, d.type, d.price);
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

void delete_a_drink(unsigned int id) {
    int i, j;
    for (i = 0; i < drinks_count; i++)
    {
        if (data[i].id == id) {
            for (j=i; j<drinks_count-1; j++) {
                data[j] = data[j+1];
            }
            drinks_count--;

        }
    }
    
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
            if (data[i].id > data[j].id) {
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

void search_by_price_range(unsigned int min, unsigned int max) {
    sort_by_price();
    int i;
    for (i = 0; i < drinks_count; i++)
    {
        if (data[i].price > min && data[i].price < max) {
            print_a_drink(data[i]);
        }
    }
}

unsigned int get_average_price() {
    int i;
    int sum = 0;
    for (i = 0; i < drinks_count; i++)
    {
        sum += data[i].price;
    }
    return sum / drinks_count;
    
}

unsigned int get_highest_price() {
    int i;
    int max = 0;
    for (i = 0; i < drinks_count; i++)
    {
        if (data[i].price > max) max = data[i].price;
    }
    return max;
}

unsigned int get_lowest_price() {
    int i;
    int min = 99999999;
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
    input_drink(12, "nuoc suoi", "water", "ml", 9000);
    input_drink(13, "tra sua tran chau", "boba", "ml", 30000);
    input_drink(11, "den da khong duong", "coffee", "ml", 20000);
    input_drink(14, "ca phe sua", "coffee", "ml", 25000);
    print_list();
    delete_a_drink(11);
    print_list();
}