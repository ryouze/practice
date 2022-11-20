/*
 * Print Japanese greeting (based on current time), username, and current time.
 */
#include <pwd.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

const char *greet(int *i) {
    switch (*i) {
    case 5 ... 11:
        return "おはよう";
    case 12 ... 16:
        return "こんにちは";
    case 17 ... 21:
        return "こんばんは";
    default:
        return "おやすみ";
    }
}

const char *get_username(void) {
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);
    if (!pw)
        return "ユーザ";  // fallback
    return pw->pw_name;
}

int main(void) {
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    int minute = tm_struct->tm_min;
    const char *username = get_username();
    printf("%s、%s！今の時間は%02d:%02dだ。\n", greet(&hour), username, hour,
           minute);
    return 0;
}
