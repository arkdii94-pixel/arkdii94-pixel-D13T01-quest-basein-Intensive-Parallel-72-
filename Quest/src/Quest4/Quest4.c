#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SECRET_KEY 0x5A

const char *success_message =
    "ПЕРВЫЙ УРОВЕНЬ ПРОЙДЕН. ИДИТЕ НА ВТОРОЙ СТЕКА.ИЩИТЕ ОБРАЗЫ ТЕХ, КТО ДЕРЖИТ НА СЕБЕ СИСТЕМУ И ЛОГИСТИКУ.ОНИ ВСЕГДА "
    "В СЕТИ И РАБОТАЮТ НА КАЖДОЙ НОДЕ.ЗА ИХ ЗАМОРОЖЕННЫМИ СЛЕДАМИ СИСТЕМНОГО ВРЕМЕНИ СПРЯТАН КОД.";


unsigned char secret_code_encrypted[] = { '.', '(', '1', '9', '\0' };

int main() {
    unsigned char input[10];
    printf("Введите код доступа: ");

    if (fgets((char*)input, sizeof(input), stdin) != NULL) {
        size_t len = strlen((char*)input);

        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
            len--;
        }

        if (len != 4) {
            printf("Неверная длина кода.\n");
            return 1;
        }

        char decrypted_secret[sizeof(secret_code_encrypted)];

        for (int i = 0; i < sizeof(secret_code_encrypted); i++) {
            decrypted_secret[i] = secret_code_encrypted[i] ^ SECRET_KEY;
        }

        int is_correct = 1;
        for (int i = 0; i < 4; i++) {
            if (toupper(input[i]) != toupper(decrypted_secret[i])) {
                is_correct = 0;
                break;
            }
        }

        if (is_correct) {
            printf("\n%s\n", success_message);
        } else {
            printf("Код неверен. Доступ запрещен.\n");
        }
    }

    return 0;
}
