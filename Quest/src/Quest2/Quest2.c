#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256


void trim_whitespace(char *str) {
    if (str == NULL || *str == '\0') return;

    char *end;

    while(isspace((unsigned char)*str)) str++;

    if(*str == 0) {
        *str = '\0';
        return;
    }

    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    *(end+1) = '\0';
}

int main(int argc, char *argv[]) {
    const int EXPECTED_LINES = 3;
    if (argc != 2) {
        printf("Использование: %s <имя_файла>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Ошибка при открытии файла");
        return 1;
    }

    bool success = true;
    char line[MAX_LINE_LENGTH];
    char team_name[MAX_LINE_LENGTH] = "";

    for (int current_line = 0; current_line < EXPECTED_LINES; current_line++) {
        if (fgets(line, sizeof(line), file) == NULL) {
            printf("Ошибка: В файле недостаточно строк.\n");
            success = false;
            break;
        }

        char buffer[MAX_LINE_LENGTH];
        strcpy(buffer, line);
        trim_whitespace(buffer);

        char *separator = strpbrk(buffer, ": ");

        char keyword[50], value[50];
        if (separator) {
            size_t kw_len = separator - buffer;
            strncpy(keyword, buffer, kw_len);
            keyword[kw_len] = '\0';
            strcpy(value, separator + 1);
            trim_whitespace(value);
        } else {
            strcpy(keyword, buffer);
            value[0] = '\0';
        }

        switch(current_line) {
            case 0:
                if (strcmp(keyword, "team") != 0 || value[0] == '\0') {
                    printf("Ошибка: Первая строка должна начинаться с 'team' и содержать название.\n");
                    success = false;
                } else {
                    strcpy(team_name, value);
                }
                break;

            case 1:
                if (strcmp(keyword, "leader") != 0) {
                    printf("Ошибка: Вторая строка должна начинаться с 'leader'.\n");
                    success = false;
                }
                break;

            case 2:
                if (strcmp(keyword, "participant") != 0) {
                    printf("Ошибка: Третья строка должна начинаться с 'participant'.\n");
                    success = false;
                }
                break;
        }

        if (!success) {
            break;
        }
    }

    fclose(file);

    if (success) {
        printf("Приветствую команду %s!\n", team_name);
        printf("I_yks_18_250526\n");
        printf ("Это твой код для активации Quest3.c\n");
        printf("но давай играть честно и не открывать сам файл\n");
    }

    return success ? 0 : 1;
}
