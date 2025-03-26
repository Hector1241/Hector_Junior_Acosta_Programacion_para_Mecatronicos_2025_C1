#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "data.bin"

typedef struct {
    int id;
    char name[50];
    float value;
} Record;

void writeToFile(Record *records, int count) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fwrite(records, sizeof(Record), count, file);
    fclose(file);
    printf("Data saved to disk successfully!\n");
}

void readFromFile() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Record temp;
    printf("\nReading from disk:\n");
    while (fread(&temp, sizeof(Record), 1, file)) {
        printf("ID: %d, Name: %s, Value: %.2f\n", temp.id, temp.name, temp.value);
    }

    fclose(file);
}

int main() {
    Record *records = NULL;
    int count = 0, option;

    do {
        printf("\nMenu:\n");
        printf("1. Add Records\n");
        printf("2. Save to Disk\n");
        printf("3. Read from Disk\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                int newCount;
                printf("How many records do you want to add? ");
                scanf("%d", &newCount);

                records = realloc(records, (count + newCount) * sizeof(Record));
                if (!records) {
                    perror("Memory allocation failed");
                    return 1;
                }

                for (int i = count; i < count + newCount; i++) {
                    printf("Enter ID: ");
                    scanf("%d", &records[i].id);
                    printf("Enter Name: ");
                    scanf("%s", records[i].name);
                    printf("Enter Value: ");
                    scanf("%f", &records[i].value);
                }
                count += newCount;
                break;
            }
            case 2:
                if (count > 0) {
                    writeToFile(records, count);
                } else {
                    printf("No data to save!\n");
                }
                break;
            case 3:
                readFromFile();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (option != 4);

    free(records);
    return 0;
}
