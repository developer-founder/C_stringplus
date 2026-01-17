#include <errno.h>

#include "s21_tests.h"

START_TEST(test_strerror_all_codes) {
    int error_codes[] = {
        E2BIG,       EACCES,       EADDRINUSE,   EADDRNOTAVAIL, EAFNOSUPPORT,    EAGAIN,       EALREADY,
        EBADF,       EBADMSG,      EBUSY,        ECANCELED,     ECHILD,          ECONNABORTED, ECONNREFUSED,
        ECONNRESET,  EDEADLK,      EDESTADDRREQ, EDOM,          EDQUOT,          EEXIST,       EFAULT,
        EFBIG,       EHOSTUNREACH, EIDRM,        EILSEQ,        EINPROGRESS,     EINTR,        EINVAL,
        EIO,         EISCONN,      EISDIR,       ELOOP,         EMFILE,          EMLINK,       EMSGSIZE,
        EMULTIHOP,   ENAMETOOLONG, ENETDOWN,     ENETRESET,     ENETUNREACH,     ENFILE,       ENOBUFS,
        ENODATA,     ENODEV,       ENOENT,       ENOEXEC,       ENOLCK,          ENOLINK,      ENOMEM,
        ENOMSG,      ENOPROTOOPT,  ENOSPC,       ENOSR,         ENOSTR,          ENOSYS,       ENOTCONN,
        ENOTDIR,     ENOTEMPTY,    ENOTSOCK,     ENOTSUP,       ENOTTY,          ENXIO,        EOPNOTSUPP,
        EOVERFLOW,   EPERM,        EPIPE,        EPROTO,        EPROTONOSUPPORT, EPROTOTYPE,   ERANGE,
        EROFS,       ESPIPE,       ESRCH,        ESTALE,        ETIME,           ETIMEDOUT,    ETXTBSY,
        EWOULDBLOCK, EXDEV};

    for (size_t i = 0; i < sizeof(error_codes) / sizeof(error_codes[0]); i++) {
        ck_assert_str_eq(s21_strerror(error_codes[i]), strerror(error_codes[i]));
    }
}
END_TEST

START_TEST(test_strerror_boundaries) {
    // минимальный и максимальный валидные коды
    ck_assert_str_eq(s21_strerror(0), strerror(0));

    for (int i = 1; i < 50; i += 3) {
        ck_assert_str_eq(s21_strerror(i), strerror(i));
    }
}
END_TEST

START_TEST(test_strerror_negative) {
    // Отрицательные коды ошибок
    ck_assert_str_eq(s21_strerror(-1), strerror(-1));
    ck_assert_str_eq(s21_strerror(-100), strerror(-100));
    ck_assert_str_eq(s21_strerror(INT_MIN), strerror(INT_MIN));
}
END_TEST

START_TEST(test_strerror_large_positive) {
    // не валидные коды ошибок
    ck_assert_str_eq(s21_strerror(9999), strerror(9999));
    ck_assert_str_eq(s21_strerror(1000000), strerror(1000000));
    ck_assert_str_eq(s21_strerror(INT_MAX), strerror(INT_MAX));
}
END_TEST

Suite* strerror_suites(void) {
    Suite* strerror_suite = suite_create("strerror_tests");

    TCase* all_strerror = tcase_create("strerror");
    tcase_add_test(all_strerror, test_strerror_all_codes);
    tcase_add_test(all_strerror, test_strerror_boundaries);
    tcase_add_test(all_strerror, test_strerror_negative);
    tcase_add_test(all_strerror, test_strerror_large_positive);

    suite_add_tcase(strerror_suite, all_strerror);

    return strerror_suite;
}