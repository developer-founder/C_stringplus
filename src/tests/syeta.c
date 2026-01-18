#include "s21_tests.h"

START_TEST(test_strtok_basic) {
    char str[] = "Hello,world,test";
    char delimiters[] = ",";

    char* s21_tokens[10];
    char* std_tokens[10];

    // Копируем строки для каждой версии функции
    char s21_str[100];
    char std_str[100];
    strcpy(s21_str, str);
    strcpy(std_str, str);

    // Разделяем с помощью s21_strtok
    s21_tokens[0] = s21_strtok(s21_str, delimiters);
    s21_tokens[1] = s21_strtok(NULL, delimiters);
    s21_tokens[2] = s21_strtok(NULL, delimiters);
    s21_tokens[3] = s21_strtok(NULL, delimiters);  // Должен быть NULL

    // Разделяем с помощью стандартного strtok
    std_tokens[0] = strtok(std_str, delimiters);
    std_tokens[1] = strtok(NULL, delimiters);
    std_tokens[2] = strtok(NULL, delimiters);
    std_tokens[3] = strtok(NULL, delimiters);

    ck_assert_str_eq(s21_tokens[0], "Hello");
    ck_assert_str_eq(s21_tokens[1], "world");
    ck_assert_str_eq(s21_tokens[2], "test");
    ck_assert_ptr_null(s21_tokens[3]);

    // Сравниваем с стандартной функцией
    for (int i = 0; i < 4; i++) {
        if (s21_tokens[i] == NULL || std_tokens[i] == NULL) {
            ck_assert_ptr_eq(s21_tokens[i], std_tokens[i]);
        } else {
            ck_assert_str_eq(s21_tokens[i], std_tokens[i]);
        }
    }
}
END_TEST

// Тест 2: Несколько разделителей подряд
START_TEST(test_strtok_multiple_delimiters) {
    char str[] = "Hello,,world,,test";
    char delimiters[] = ",";

    char s21_str[100];
    char std_str[100];
    strcpy(s21_str, str);
    strcpy(std_str, str);

    char* s21_result = s21_strtok(s21_str, delimiters);
    char* std_result = strtok(std_str, delimiters);

    ck_assert_str_eq(s21_result, "Hello");
    ck_assert_str_eq(s21_result, std_result);

    s21_result = s21_strtok(NULL, delimiters);
    std_result = strtok(NULL, delimiters);

    ck_assert_str_eq(s21_result, "world");
    ck_assert_str_eq(s21_result, std_result);

    s21_result = s21_strtok(NULL, delimiters);
    std_result = strtok(NULL, delimiters);

    ck_assert_str_eq(s21_result, "test");
    ck_assert_str_eq(s21_result, std_result);

    s21_result = s21_strtok(NULL, delimiters);
    std_result = strtok(NULL, delimiters);

    ck_assert_ptr_null(s21_result);
    ck_assert_ptr_null(std_result);
}
END_TEST

// Тест 3: Разные разделители
START_TEST(test_strtok_various_delimiters) {
    char str[] = "Hello world;test,again";
    char delimiters[] = " ;,";

    char s21_str[100];
    char std_str[100];
    strcpy(s21_str, str);
    strcpy(std_str, str);

    char* tokens[5];
    char* std_tokens[5];

    tokens[0] = s21_strtok(s21_str, delimiters);
    std_tokens[0] = strtok(std_str, delimiters);

    tokens[1] = s21_strtok(NULL, delimiters);
    std_tokens[1] = strtok(NULL, delimiters);

    tokens[2] = s21_strtok(NULL, delimiters);
    std_tokens[2] = strtok(NULL, delimiters);

    tokens[3] = s21_strtok(NULL, delimiters);
    std_tokens[3] = strtok(NULL, delimiters);

    tokens[4] = s21_strtok(NULL, delimiters);
    std_tokens[4] = strtok(NULL, delimiters);

    ck_assert_str_eq(tokens[0], "Hello");
    ck_assert_str_eq(tokens[1], "world");
    ck_assert_str_eq(tokens[2], "test");
    ck_assert_str_eq(tokens[3], "again");
    ck_assert_ptr_null(tokens[4]);

    for (int i = 0; i < 5; i++) {
        if (tokens[i] == NULL || std_tokens[i] == NULL) {
            ck_assert_ptr_eq(tokens[i], std_tokens[i]);
        } else {
            ck_assert_str_eq(tokens[i], std_tokens[i]);
        }
    }
}
END_TEST

// Тест 4: Разделители в начале и конце строки
START_TEST(test_strtok_delimiters_at_edges) {
    char str[] = ",,Hello,world,test,,";
    char delimiters[] = ",";

    char s21_str[100];
    char std_str[100];
    strcpy(s21_str, str);
    strcpy(std_str, str);

    char* tokens[5];
    char* std_tokens[5];

    tokens[0] = s21_strtok(s21_str, delimiters);
    std_tokens[0] = strtok(std_str, delimiters);

    tokens[1] = s21_strtok(NULL, delimiters);
    std_tokens[1] = strtok(NULL, delimiters);

    tokens[2] = s21_strtok(NULL, delimiters);
    std_tokens[2] = strtok(NULL, delimiters);

    tokens[3] = s21_strtok(NULL, delimiters);
    std_tokens[3] = strtok(NULL, delimiters);

    tokens[4] = s21_strtok(NULL, delimiters);
    std_tokens[4] = strtok(NULL, delimiters);

    ck_assert_str_eq(tokens[0], "Hello");
    ck_assert_str_eq(tokens[1], "world");
    ck_assert_str_eq(tokens[2], "test");
    ck_assert_ptr_null(tokens[3]);  // Пустые токены игнорируются
    ck_assert_ptr_null(tokens[4]);

    for (int i = 0; i < 5; i++) {
        if (tokens[i] == NULL || std_tokens[i] == NULL) {
            ck_assert_ptr_eq(tokens[i], std_tokens[i]);
        } else {
            ck_assert_str_eq(tokens[i], std_tokens[i]);
        }
    }
}
END_TEST

// Тест 5: Только разделители
START_TEST(test_strtok_only_delimiters) {
    char str[] = ",,,,";
    char delimiters[] = ",";

    char s21_str[100];
    char std_str[100];
    strcpy(s21_str, str);
    strcpy(std_str, str);

    char* s21_result = s21_strtok(s21_str, delimiters);
    char* std_result = strtok(std_str, delimiters);

    ck_assert_ptr_null(s21_result);
    ck_assert_ptr_null(std_result);
    ck_assert_ptr_eq(s21_result, std_result);
}
END_TEST

// Тест 6: Пустая строка
START_TEST(test_strtok_empty_string) {
    char str[] = "";
    char delimiters[] = ",";

    char s21_str[100];
    char std_str[100];
    strcpy(s21_str, str);
    strcpy(std_str, str);

    char* s21_result = s21_strtok(s21_str, delimiters);
    char* std_result = strtok(std_str, delimiters);

    ck_assert_ptr_null(s21_result);
    ck_assert_ptr_null(std_result);
    ck_assert_ptr_eq(s21_result, std_result);
}
END_TEST

// Тест 7: Один токен без разделителей
START_TEST(test_strtok_single_token) {
    char str[] = "Hello";
    char delimiters[] = ",";

    char s21_str[100];
    char std_str[100];
    strcpy(s21_str, str);
    strcpy(std_str, str);

    char* s21_result = s21_strtok(s21_str, delimiters);
    char* std_result = strtok(std_str, delimiters);

    ck_assert_str_eq(s21_result, "Hello");
    ck_assert_str_eq(s21_result, std_result);

    s21_result = s21_strtok(NULL, delimiters);
    std_result = strtok(NULL, delimiters);

    ck_assert_ptr_null(s21_result);
    ck_assert_ptr_null(std_result);
}
END_TEST

// ==================== ТЕСТЫ ИЗМЕНЕНИЯ РАЗДЕЛИТЕЛЕЙ ====================

// Тест 8: Изменение разделителей между вызовами
START_TEST(test_strtok_changing_delimiters) {
    char str[] = "Hello world;test,again";

    char s21_str[100];
    char std_str[100];
    strcpy(s21_str, str);
    strcpy(std_str, str);

    // Первый разделитель - пробел
    char* s21_result = s21_strtok(s21_str, " ");
    char* std_result = strtok(std_str, " ");

    ck_assert_str_eq(s21_result, "Hello");
    ck_assert_str_eq(s21_result, std_result);

    // Меняем разделитель на точку с запятой
    s21_result = s21_strtok(NULL, ";");
    std_result = strtok(NULL, ";");

    ck_assert_str_eq(s21_result, "world");
    ck_assert_str_eq(s21_result, std_result);

    // Меняем разделитель на запятую
    s21_result = s21_strtok(NULL, ",");
    std_result = strtok(NULL, ",");

    ck_assert_str_eq(s21_result, "test");
    ck_assert_str_eq(s21_result, std_result);

    // Последний токен
    s21_result = s21_strtok(NULL, " ");
    std_result = strtok(NULL, " ");

    ck_assert_str_eq(s21_result, "again");
    ck_assert_str_eq(s21_result, std_result);

    // Конец
    s21_result = s21_strtok(NULL, " ");
    std_result = strtok(NULL, " ");

    ck_assert_ptr_null(s21_result);
    ck_assert_ptr_null(std_result);
}
END_TEST

// ==================== ТЕСТЫ СО СПЕЦИАЛЬНЫМИ СИМВОЛАМИ ====================

// Тест 9: Табуляции и переводы строк как разделители
START_TEST(test_strtok_whitespace_delimiters) {
    char str[] = "Hello\tworld\n test \r\nend";
    char delimiters[] = " \t\n\r";

    char s21_str[100];
    char std_str[100];
    strcpy(s21_str, str);
    strcpy(std_str, str);

    char* tokens[5];
    char* std_tokens[5];

    tokens[0] = s21_strtok(s21_str, delimiters);
    std_tokens[0] = strtok(std_str, delimiters);

    tokens[1] = s21_strtok(NULL, delimiters);
    std_tokens[1] = strtok(NULL, delimiters);

    tokens[2] = s21_strtok(NULL, delimiters);
    std_tokens[2] = strtok(NULL, delimiters);

    tokens[3] = s21_strtok(NULL, delimiters);
    std_tokens[3] = strtok(NULL, delimiters);

    tokens[4] = s21_strtok(NULL, delimiters);
    std_tokens[4] = strtok(NULL, delimiters);

    ck_assert_str_eq(tokens[0], "Hello");
    ck_assert_str_eq(tokens[1], "world");
    ck_assert_str_eq(tokens[2], "test");
    ck_assert_str_eq(tokens[3], "end");
    ck_assert_ptr_null(tokens[4]);

    for (int i = 0; i < 5; i++) {
        if (tokens[i] == NULL || std_tokens[i] == NULL) {
            ck_assert_ptr_eq(tokens[i], std_tokens[i]);
        } else {
            ck_assert_str_eq(tokens[i], std_tokens[i]);
        }
    }
}
END_TEST

// Тест 10: Специальные символы как разделители
START_TEST(test_strtok_special_char_delimiters) {
    char str[] = "Hello|world#test@again";
    char delimiters[] = "|#@";

    char s21_str[100];
    char std_str[100];
    strcpy(s21_str, str);
    strcpy(std_str, str);

    char* tokens[5];
    char* std_tokens[5];

    tokens[0] = s21_strtok(s21_str, delimiters);
    std_tokens[0] = strtok(std_str, delimiters);

    for (int i = 1; i < 5; i++) {
        tokens[i] = s21_strtok(NULL, delimiters);
        std_tokens[i] = strtok(NULL, delimiters);
    }

    ck_assert_str_eq(tokens[0], "Hello");
    ck_assert_str_eq(tokens[1], "world");
    ck_assert_str_eq(tokens[2], "test");
    ck_assert_str_eq(tokens[3], "again");
    ck_assert_ptr_null(tokens[4]);

    for (int i = 0; i < 5; i++) {
        if (tokens[i] == NULL || std_tokens[i] == NULL) {
            ck_assert_ptr_eq(tokens[i], std_tokens[i]);
        } else {
            ck_assert_str_eq(tokens[i], std_tokens[i]);
        }
    }
}
END_TEST

// ==================== ТЕСТЫ ПАРАЛЛЕЛЬНОЙ ОБРАБОТКИ ====================

// Тест 11: Параллельная обработка нескольких строк
START_TEST(test_strtok_parallel_processing) {
    char str1[] = "one,two,three";
    char str2[] = "four-five-six";

    char s21_str1[100], s21_str2[100];
    char std_str1[100], std_str2[100];

    strcpy(s21_str1, str1);
    strcpy(s21_str2, str2);
    strcpy(std_str1, str1);
    strcpy(std_str2, str2);

    // Начинаем обработку первой строки
    char* s21_token1 = s21_strtok(s21_str1, ",");
    char* std_token1 = strtok(std_str1, ",");

    ck_assert_str_eq(s21_token1, "one");
    ck_assert_str_eq(s21_token1, std_token1);

    // Переключаемся на вторую строку
    char* s21_token2 = s21_strtok(s21_str2, "-");
    char* std_token2 = strtok(std_str2, "-");

    ck_assert_str_eq(s21_token2, "four");
    ck_assert_str_eq(s21_token2, std_token2);

    // Возвращаемся к первой строке
    s21_token1 = s21_strtok(NULL, ",");
    std_token1 = strtok(NULL, ",");

    ck_assert_str_eq(s21_token1, "two");
    ck_assert_str_eq(s21_token1, std_token1);

    // Продолжаем вторую строку
    s21_token2 = s21_strtok(NULL, "-");
    std_token2 = strtok(NULL, "-");

    ck_assert_str_eq(s21_token2, "five");
    ck_assert_str_eq(s21_token2, std_token2);

    // Завершаем обе строки
    s21_token1 = s21_strtok(NULL, ",");
    std_token1 = strtok(NULL, ",");

    ck_assert_str_eq(s21_token1, "three");
    ck_assert_str_eq(s21_token1, std_token1);

    s21_token2 = s21_strtok(NULL, "-");
    std_token2 = strtok(NULL, "-");

    ck_assert_str_eq(s21_token2, "six");
    ck_assert_str_eq(s21_token2, std_token2);

    // Проверяем концы
    ck_assert_ptr_null(s21_strtok(NULL, ","));
    ck_assert_ptr_null(s21_strtok(NULL, "-"));
}
END_TEST

// ==================== ТЕСТЫ С МОДИФИКАЦИЕЙ СТРОКИ ====================

// Тест 12: Проверка что функция модифицирует строку
START_TEST(test_strtok_modifies_string) {
    char str[] = "Hello,world,test";
    char delimiters[] = ",";

    char s21_str[100];
    strcpy(s21_str, str);

    char* token1 = s21_strtok(s21_str, delimiters);

    // После первого вызова в позиции разделителя должен быть '\0'
    ck_assert_int_eq(s21_str[5], '\0');
    ck_assert_str_eq(token1, "Hello");

    char* token2 = s21_strtok(NULL, delimiters);
    ck_assert_int_eq(s21_str[11], '\0');  // world\0test
    ck_assert_str_eq(token2, "world");

    char* token3 = s21_strtok(NULL, delimiters);
    ck_assert_str_eq(token3, "test");
}
END_TEST

// ==================== ТЕСТЫ С ДЛИННЫМИ СТРОКАМИ ====================

// Тест 13: Длинная строка с множеством токенов
START_TEST(test_strtok_long_string) {
    char long_str[1000];
    char delimiters[] = " ";

    // Создаем длинную строку: "word0 word1 ... word99"
    for (int i = 0; i < 100; i++) {
        sprintf(long_str + i * 6, "word%d ", i);
    }
    long_str[599] = '\0';  // 100 слов * 6 символов

    char s21_str[1000];
    char std_str[1000];
    strcpy(s21_str, long_str);
    strcpy(std_str, long_str);

    char* s21_tokens[101];
    char* std_tokens[101];

    // Извлекаем все токены
    s21_tokens[0] = s21_strtok(s21_str, delimiters);
    std_tokens[0] = strtok(std_str, delimiters);

    for (int i = 1; i <= 100; i++) {
        s21_tokens[i] = s21_strtok(NULL, delimiters);
        std_tokens[i] = strtok(NULL, delimiters);
    }

    // Проверяем первые 5 и последние 5 токенов
    ck_assert_str_eq(s21_tokens[0], "word0");
    ck_assert_str_eq(s21_tokens[1], "word1");
    ck_assert_str_eq(s21_tokens[2], "word2");
    ck_assert_str_eq(s21_tokens[3], "word3");
    ck_assert_str_eq(s21_tokens[4], "word4");

    ck_assert_str_eq(s21_tokens[95], "word95");
    ck_assert_str_eq(s21_tokens[96], "word96");
    ck_assert_str_eq(s21_tokens[97], "word97");
    ck_assert_str_eq(s21_tokens[98], "word98");
    ck_assert_str_eq(s21_tokens[99], "word99");

    ck_assert_ptr_null(s21_tokens[100]);

    // Сравниваем со стандартной функцией
    for (int i = 0; i <= 100; i++) {
        if (s21_tokens[i] == NULL || std_tokens[i] == NULL) {
            ck_assert_ptr_eq(s21_tokens[i], std_tokens[i]);
        } else {
            ck_assert_str_eq(s21_tokens[i], std_tokens[i]);
        }
    }
}
END_TEST

// ==================== ТЕСТЫ С НЕПЕЧАТАЕМЫМИ СИМВОЛАМИ ====================

// Тест 14: Разделители как непечатаемые символы
START_TEST(test_strtok_non_printable_delimiters) {
    char str[] = "Hello\x01world\x02test";
    char delimiters[] = "\x01\x02";  // SOH и STX

    char s21_str[100];
    char std_str[100];
    memcpy(s21_str, str, sizeof(str));
    memcpy(std_str, str, sizeof(str));

    char* tokens[4];
    char* std_tokens[4];

    tokens[0] = s21_strtok(s21_str, delimiters);
    std_tokens[0] = strtok(std_str, delimiters);

    for (int i = 1; i < 4; i++) {
        tokens[i] = s21_strtok(NULL, delimiters);
        std_tokens[i] = strtok(NULL, delimiters);
    }

    ck_assert_str_eq(tokens[0], "Hello");
    ck_assert_str_eq(tokens[1], "world");
    ck_assert_str_eq(tokens[2], "test");
    ck_assert_ptr_null(tokens[3]);

    for (int i = 0; i < 4; i++) {
        if (tokens[i] == NULL || std_tokens[i] == NULL) {
            ck_assert_ptr_eq(tokens[i], std_tokens[i]);
        } else {
            ck_assert_str_eq(tokens[i], std_tokens[i]);
        }
    }
}
END_TEST

// ==================== ТЕСТЫ ПОВТОРНОГО ИСПОЛЬЗОВАНИЯ ====================

// Тест 15: Повторное использование после NULL
START_TEST(test_strtok_reuse_after_null) {
    char str[] = "first,second";
    char delimiters[] = ",";

    char s21_str[100];
    char std_str[100];
    strcpy(s21_str, str);
    strcpy(std_str, str);

    // Первое использование
    char* s21_token = s21_strtok(s21_str, delimiters);
    char* std_token = strtok(std_str, delimiters);
    ck_assert_str_eq(s21_token, "first");
    ck_assert_str_eq(s21_token, std_token);

    s21_token = s21_strtok(NULL, delimiters);
    std_token = strtok(NULL, delimiters);
    ck_assert_str_eq(s21_token, "second");
    ck_assert_str_eq(s21_token, std_token);

    s21_token = s21_strtok(NULL, delimiters);
    std_token = strtok(NULL, delimiters);
    ck_assert_ptr_null(s21_token);
    ck_assert_ptr_null(std_token);

    // Повторное использование с новой строкой
    char str2[] = "another,test";
    strcpy(s21_str, str2);
    strcpy(std_str, str2);

    s21_token = s21_strtok(s21_str, delimiters);
    std_token = strtok(std_str, delimiters);
    ck_assert_str_eq(s21_token, "another");
    ck_assert_str_eq(s21_token, std_token);

    s21_token = s21_strtok(NULL, delimiters);
    std_token = strtok(NULL, delimiters);
    ck_assert_str_eq(s21_token, "test");
    ck_assert_str_eq(s21_token, std_token);
}
END_TEST

// ==================== ТЕСТЫ ДЛЯ СРАВНЕНИЯ С ОРИГИНАЛОМ ====================

// Тест 16: Комплексный тест для сравнения
START_TEST(test_strtok_comprehensive_comparison) {
    struct test_case {
        char* str;
        char* delimiters;
        char* expected[10];
    } test_cases[] = {
        {"a,b,c", ",", {"a", "b", "c", NULL}},
        {"hello world", " ", {"hello", "world", NULL}},
        {",a,,b,", ",", {"a", "b", NULL}},
        {"one\ttwo\nthree", " \t\n", {"one", "two", "three", NULL}},
        {"", ",", {NULL}},
        {",,,", ",", {NULL}},
        {"no_delimiters", ";", {"no_delimiters", NULL}},
        {"a.b.c", ".", {"a", "b", "c", NULL}},
        {"test", "", {"test", NULL}},  // Пустые разделители
    };

    for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
        char s21_str[100];
        char std_str[100];
        strcpy(s21_str, test_cases[i].str);
        strcpy(std_str, test_cases[i].str);

        char* s21_tokens[10];
        char* std_tokens[10];
        int token_count = 0;

        // Извлекаем токены
        s21_tokens[0] = s21_strtok(s21_str, test_cases[i].delimiters);
        std_tokens[0] = strtok(std_str, test_cases[i].delimiters);
        token_count++;

        while (s21_tokens[token_count - 1] != NULL && token_count < 10) {
            s21_tokens[token_count] = s21_strtok(NULL, test_cases[i].delimiters);
            std_tokens[token_count] = strtok(NULL, test_cases[i].delimiters);
            token_count++;
        }

        // Проверяем ожидаемые значения
        for (int j = 0; j < token_count; j++) {
            if (test_cases[i].expected[j] == NULL) {
                ck_assert_ptr_null(s21_tokens[j]);
                ck_assert_ptr_null(std_tokens[j]);
            } else {
                ck_assert_str_eq(s21_tokens[j], test_cases[i].expected[j]);
                ck_assert_str_eq(std_tokens[j], test_cases[i].expected[j]);
            }
        }
    }
}
END_TEST

// ==================== СОЗДАНИЕ ТЕСТОВОГО НАБОРА ====================

Suite* strtok_suite(void) {
    Suite* s = suite_create("strtok");

    TCase* tc_core = tcase_create("Core");
    TCase* tc_edge = tcase_create("Edge Cases");
    TCase* tc_special = tcase_create("Special Cases");
    TCase* tc_parallel = tcase_create("Parallel Processing");

    // Основные тесты
    tcase_add_test(tc_core, test_strtok_basic);
    tcase_add_test(tc_core, test_strtok_multiple_delimiters);
    tcase_add_test(tc_core, test_strtok_various_delimiters);
    tcase_add_test(tc_core, test_strtok_delimiters_at_edges);
    tcase_add_test(tc_core, test_strtok_single_token);
    tcase_add_test(tc_core, test_strtok_changing_delimiters);

    // Граничные случаи
    tcase_add_test(tc_edge, test_strtok_only_delimiters);
    tcase_add_test(tc_edge, test_strtok_empty_string);
    tcase_add_test(tc_edge, test_strtok_modifies_string);
    tcase_add_test(tc_edge, test_strtok_reuse_after_null);

    // Специальные случаи
    tcase_add_test(tc_special, test_strtok_whitespace_delimiters);
    tcase_add_test(tc_special, test_strtok_special_char_delimiters);
    tcase_add_test(tc_special, test_strtok_non_printable_delimiters);
    tcase_add_test(tc_special, test_strtok_long_string);

    // Параллельная обработка
    tcase_add_test(tc_parallel, test_strtok_parallel_processing);

    // Комплексный тест
    tcase_add_test(tc_core, test_strtok_comprehensive_comparison);

    suite_add_tcase(s, tc_core);
    suite_add_tcase(s, tc_edge);
    suite_add_tcase(s, tc_special);
    suite_add_tcase(s, tc_parallel);

    return s;
}

// Сокращенная версия (основные 10 тестов)
Suite* strtok_short_suite(void) {
    Suite* s = suite_create("strtok_short");
    TCase* tc = tcase_create("Core");

    tcase_add_test(tc, test_strtok_basic);
    tcase_add_test(tc, test_strtok_multiple_delimiters);
    tcase_add_test(tc, test_strtok_delimiters_at_edges);
    tcase_add_test(tc, test_strtok_only_delimiters);
    tcase_add_test(tc, test_strtok_empty_string);
    tcase_add_test(tc, test_strtok_changing_delimiters);
    tcase_add_test(tc, test_strtok_whitespace_delimiters);
    tcase_add_test(tc, test_strtok_modifies_string);
    tcase_add_test(tc, test_strtok_parallel_processing);
    tcase_add_test(tc, test_strtok_comprehensive_comparison);

    suite_add_tcase(s, tc);
    return s;
}