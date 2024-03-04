#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct drink {
    char id[50];
    char name[100];
    char type[50];
    char unit[50];
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
            printf("A drink with id: %s already exists, try another id.\n", id);
            return;
        }
    }
        
    struct drink new;
    strcpy(new.id, id);
    strcpy(new.name, name);
    strcpy(new.type, type);
    strcpy(new.unit, unit);
    new.price = price;

    data[drinks_count] = new;
    drinks_count++;
}

void print_a_drink(struct drink d) {
    printf("%-10s %-20s %-10s %-10s %lud\n", d.id, d.name, d.type, d.unit, d.price);
}

void print_list() {    
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

    strcpy(data[index].name, new_name);
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
    // ascending
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

    int userChoice;
    char idWater[50];
    char nameWater[50];
    char typeWater[50];
    char unitWater[50];
    unsigned long priceWater;
    do {
        printf("=============== MENU ==============\n");
        printf("1. Nhap thong tin do uong\n");
        printf("2. Sua thong tin Gia tien cua do uong\n");
        printf("3. Sua thong tin Ten do uong\n");
        printf("4. Xoa thong tin\n");
        printf("5. Sap xep theo danh sach giam dan theo Loai do uong\n");
        printf("6. Sap xep theo danh sach tang dan theo gia tien\n");
        printf("7. Xoat toan bo danh sach\n");
        printf("0. Thoat chuong trinh\n");
        printf("\nBan chon ? ");
        
        scanf("%d",&userChoice);
        getchar();

        switch (userChoice) {            
            case 1:
                printf("Nhap thong tin do uong:\n");
                printf("ID: ");
                gets(idWater);

                printf("Name: ");
                gets(nameWater);

                printf("Type: ");
                gets(typeWater);

                printf("Unit: ");
                gets(unitWater);

                printf("Price: ");
                scanf("%lu", &priceWater);
                getchar();

                idWater[strcspn(idWater, "\n")] = '\0'; // Remove the newline character
                nameWater[strcspn(nameWater, "\n")] = '\0';
                typeWater[strcspn(typeWater, "\n")] = '\0';
                unitWater[strcspn(unitWater, "\n")] = '\0';
                input_drink(idWater, nameWater, typeWater, unitWater, priceWater);

                break;
            case 2:
                break;
            case 3:
                break; 
            case 4:
                printf("Nhap ma do uong muon xoa:\n");
                printf("ID: ");
                scanf("%s", idWater);
                getchar();
                delete_a_drink(idWater);
                break;
            case 5:
                break;
            case 7:
                print_list();
                break;
            case 0:
                printf("Ban da thoat khoi chuong trinh");
                break;    
            default:
                printf("Sai chuc nang, vui long chon lai!\n");
                break;
        }
    } while (userChoice);
    
    getchar();
    getchar();
    return 0;
}

