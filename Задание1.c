#include <stdio.h>
#include <string.h>

#define MAX_ABONENTS 100
#define NAME_LEN 10

struct abonent {
    char name[NAME_LEN];
    char second_name[NAME_LEN];
    char tel[NAME_LEN];
};

void add_abonent(struct abonent phonebook[], int *count);
void delete_abonent(struct abonent phonebook[], int *count);
void search_by_name(struct abonent phonebook[], int count);
void print_all(struct abonent phonebook[], int count);

int main() {
    struct abonent phonebook[MAX_ABONENTS];
    int count = 0;
    int choice;

    do {
        printf("\n--- Абонентский справочник ---\n");
        printf("1) Добавить абонента\n");
        printf("2) Удалить абонента\n");
        printf("3) Поиск абонентов по имени\n");
        printf("4) Вывод всех записей\n");
        printf("5) Выход\n");
        printf("Выберите пункт меню: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_abonent(phonebook, &count);
                break;
            case 2:
                delete_abonent(phonebook, &count);
                break;
            case 3:
                search_by_name(phonebook, count);
                break;
            case 4:
                print_all(phonebook, count);
                break;
            case 5:
                printf("Выход из программы.\n");
                break;
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }

    } while (choice != 5);

    return 0;
}

void add_abonent(struct abonent phonebook[], int *count) {
    if (*count >= MAX_ABONENTS) {
        printf("Справочник переполнен! Нельзя добавить больше абонентов.\n");
        return;
    }

    printf("Введите имя: ");
    scanf("%s", phonebook[*count].name);
    printf("Введите фамилию: ");
    scanf("%s", phonebook[*count].second_name);
    printf("Введите телефон: ");
    scanf("%s", phonebook[*count].tel);

    (*count)++;
    printf("Абонент добавлен.\n");
}

void delete_abonent(struct abonent phonebook[], int *count) {
    char name[NAME_LEN];
    printf("Введите имя для удаления: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            // Обнуляем структуру
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].second_name, "");
            strcpy(phonebook[i].tel, "");

            printf("Абонент %s удален.\n", name);
            found = 1;
        }
    }

    if (!found)
        printf("Абонент не найден.\n");
}

void search_by_name(struct abonent phonebook[], int count) {
    char name[NAME_LEN];
    printf("Введите имя для поиска: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(phonebook[i].name, name) == 0 && phonebook[i].name[0] != '\0') {
            printf("Имя: %s, Фамилия: %s, Телефон: %s\n",
                   phonebook[i].name,
                   phonebook[i].second_name,
                   phonebook[i].tel);
            found = 1;
        }
    }

    if (!found)
        printf("Абоненты с таким именем не найдены.\n");
}

void print_all(struct abonent phonebook[], int count) {
    if (count == 0) {
        printf("Справочник пуст.\n");
        return;
    }

    printf("Список всех абонентов:\n");
    for (int i = 0; i < count; i++) {
        if (phonebook[i].name[0] != '\0') {
            printf("[%d] Имя: %s, Фамилия: %s, Телефон: %s\n",
                   i + 1,
                   phonebook[i].name,
                   phonebook[i].second_name,
                   phonebook[i].tel);
        }
    }
}