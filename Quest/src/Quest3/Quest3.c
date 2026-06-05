#include <stdio.h>
#include <string.h>

#define SECRET_CODE "I_yks_18_250526"
#define MAX_INPUT_LENGTH 100

int main() {
    char input_code[MAX_INPUT_LENGTH];

    printf("Введите код: ");

    if (fgets(input_code, sizeof(input_code), stdin) != NULL) {
        size_t len = strlen(input_code);

        if (len > 0 && input_code[len - 1] == '\n') {
            input_code[len - 1] = '\0';
        }


        if (strcmp(input_code, SECRET_CODE) == 0) {
            printf("\nДоступ разрешен!\n");
            printf("\n");
            printf("Загадка! Ключ к пути дальнейшему\n");
            printf("\n");
            printf("Позади первый шаг, но опасен исчерпанный срок,\n");
            printf("Турнир запускает финальный, безумный виток.\n");
            printf("Тот, кто держит ключи от грядущих великих побед,\n");
            printf("Облачён в триумфальный, магический, избранный цвет.\n");
            printf("Не ищите гербов, не ищите корону во мгле —\n");
            printf("Цвет искры из Кубка и судей царит на земле.\n");
            printf("Подойдите к Стражу без страха, смятенья и рва,\n");
            printf("Но забудьте про прежние, старые ваши слова.\n");
            printf("\n");
            printf("Вспомните место, где магия знаний кипит,\n");
            printf("Где каждый из вас свои лучшие билды творит.\n");
            printf("Назовите тот номер, под коим стоит эта твердыня —\n");
            printf("И пламя укажет, куда вам двигаться отныне.\n");
            // --------------------------------------------------
        } else {
            printf("Ошибка: Неверный код. Доступ запрещен.\n");
        }
    }

    return 0;
}
