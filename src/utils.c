#include "../include/utils.h"

// Computes time taken given the starting and ending times
double accum_time(struct timespec requestStart, struct timespec requestEnd) {
    
    return ((requestEnd.tv_sec - requestStart.tv_sec)) * 1000 +
            (( requestEnd.tv_nsec - requestStart.tv_nsec ) / MILLION);
}

void enter_data(Data* record, int id_num, char country[], char Grate[], int Score, int Rate) {
    
    record->key = id_num;
    strcpy(record->country, country);
    strcpy(record->Grate, Grate);
    record->Score = Score;
    record->Rate = Rate;
    
    return;
}

Data* get_data(char *filepath, int len) {
    
    Data *records = malloc(sizeof(Data)*len);
    char delim = ','; char line[256];
    int file_no = 0;
    int i;
    int key;
    char country[255];
    char Grate[255];
    int Score;
    int Rate;
    
    FILE *fin = fopen(filepath, "r");
    
    while(file_no < len && fscanf(fin, "%d,%[^,],%[^,],%d,%d", &key, country, Grate, &Score, &Rate)) {
        // printf("%d %s %s %d %d\n", id_num, country, Grate, Score, Rate);
        enter_data(&records[file_no], key, country, Grate, Score, Rate);
        // printf("%d %d\n", records[file_no]->key, records[file_no]->Rate);
        file_no++;
    }
    
    // for(i = 0; i < MILLION; i++) {
        // printf("%s\n", records[i]->country);
    // }
    
    return records;
}
void print_function(Data *record) {
    
    if(!record) {
        printf("Record Not Found!!\n\n");
        return;
    }
    
    printf("\nKey: %d\n", record->key);
    printf("Country: %s\n", record->country);
    printf("Grate: %s\n", record->Grate);
    printf("Score: %d\n", record->Score);
    printf("Rate: %d\n\n", record->Rate);
}