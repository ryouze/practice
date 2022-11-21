/*
Print a list of randomly generated romaji female Japanese name pairs (name + surname).

Todo: load names from an external txt file instead of storing them as char.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *arr_first[] = {
    "Ai",
    "Aiko",
    "Aimi",
    "Aina",
    "Airi",
    "Akane",
    "Akari",
    "Akemi",
    "Aki",
    "Akiko",
    "Akira",
    "Ami",
    "Aoi",
    "Asami",
    "Asuka",
    "Atsuko",
    "Aya",
    "Ayaka",
    "Ayako",
    "Ayame",
    "Ayane",
    "Chiaki",
    "Chie",
    "Chihiro",
    "Chika",
    "Chikako",
    "Chinatsu",
    "Chiyo",
    "Chiyoko",
    "Chou",
    "Ema",
    "Emi",
    "Etsuko",
    "Fumiko",
    "Fusae",
    "Fuyuko",
    "Hana",
    "Hanae",
    "Hanako",
    "Haru",
    "Haruka",
    "Haruko",
    "Hibiki",
    "Hikari",
    "Himiko",
    "Hina",
    "Hinata",
    "Hiroko",
    "Hisako",
    "Hitomi",
    "Homare",
    "Honoka",
    "Hoshi",
    "Hoshiko",
    "Hotaru",
    "Ichiyo",
    "Izumi",
    "Jakuchou",
    "Jun",
    "Junko",
    "Kaede",
    "Kana",
    "Kanako",
    "Kanna",
    "Kaori",
    "Karen",
    "Kasumi",
    "Kazue",
    "Kazuko",
    "Kei",
    "Keiko",
    "Kiyo",
    "Koyuki",
    "Kumiko",
    "Kyouko",
    "Mai",
    "Mami",
    "Masako",
    "Mayumi",
    "Megumi",
    "Mei",
    "Michi",
    "Midori",
    "Mika",
    "Misaki",
    "Miyoko",
    "Moe",
    "Moriko",
    "Murasaki",
    "Nanami",
    "Natsuki",
    "Renho",
    "Rio",
    "Sachie",
    "Sachiko",
    "Sadako",
    "Sakiko",
    "Sakura",
    "Setsuko",
    "Shinju",
    "Shizuko",
    "Shun",
    "Suzume",
    "Takako",
    "Takara",
    "Tamiko",
    "Tomoe",
    "Tomoko",
    "Toshiko",
    "Ume",
    "Yasu",
    "Yayoi",
    "Yoshiko",
    "Youko",
    "Yui",
    "Yumiko",
    "Yuuka",
    "Yuuko",
};

const char *arr_second[] = {
    "Abe",
    "Adachi",
    "Akiyama",
    "Ando",
    "Aoki",
    "Arai",
    "Araki",
    "Asano",
    "Baba",
    "Chiba",
    "Doi",
    "Endo",
    "Fujii",
    "Fujimoto",
    "Fujita",
    "Fujiwara",
    "Fukuda",
    "Fukushima",
    "Furukawa",
    "Goto",
    "Hagihara",
    "Hamada",
    "Hara",
    "Harada",
    "Hasegawa",
    "Hashimoto",
    "Hattori",
    "Hayakawa",
    "Hayashi",
    "Higashi",
    "Higuchi",
    "Hino",
    "Hirai",
    "Hirano",
    "Hirata",
    "Hirose",
    "Honda",
    "Hori",
    "Hoshino",
    "Ichikawa",
    "Ida",
    "Igarashi",
    "Ikeda",
    "Imai",
    "Inoue",
    "Ishibashi",
    "Ishida",
    "Ishihara",
    "Ishii",
    "Ishikawa",
    "Ito",
    "Iwamoto",
    "Iwasaki",
    "Iwata",
    "Kamata",
    "Kaneko",
    "Katayama",
    "Kato",
    "Kawaguchi",
    "Kawai",
    "Kawakami",
    "Kawamura",
    "Kawasaki",
    "Kawashima",
    "Kikuchi",
    "Kimura",
    "Kinoshita",
    "Kitamura",
    "Kobayashi",
    "Kodama",
    "Koga",
    "Koike",
    "Kojima",
    "Komatsu",
    "Kondo",
    "Konishi",
    "Konno",
    "Kono",
    "Koyama",
    "Kubo",
    "Kubota",
    "Kudo",
    "Kumagai",
    "Kurihara",
    "Kuroda",
    "Maeda",
    "Maruyama",
    "Masuda",
    "Matsuda",
    "Matsui",
    "Matsumoto",
    "Matsumura",
    "Matsuo",
    "Matsuoka",
    "Matsushita",
    "Matsuura",
    "Minami",
    "Miura",
    "Miyamoto",
    "Miyata",
    "Miyazaki",
    "Mizuno",
    "Mochizuki",
    "Mori",
    "Morimoto",
    "Morita",
    "Murakami",
    "Murata",
    "Nagai",
    "Nagata",
    "Naito",
    "Nakagawa",
    "Nakajima",
    "Nakamura",
    "Nakanishi",
    "Nakano",
    "Nakata",
    "Nakayama",
    "Nishida",
    "Nishikawa",
    "Nishimura",
    "Nishiyama",
    "Noda",
    "Noguchi",
    "Nomura",
    "Oda",
    "Ogawa",
    "Ogura",
    "Ohara",
    "Ohashi",
    "Oishi",
    "Okada",
    "Okamoto",
    "Okubo",
    "Onishi",
    "Ono",
    "Osawa",
    "Oshima",
    "Ota",
    "Otsuka",
    "Oya",
    "Ozaki",
    "Ozawa",
    "Saito",
    "Sakaguchi",
    "Sakai",
    "Sakamoto",
    "Sakurai",
    "Sano",
    "Sasaki",
    "Sato",
    "Sawada",
    "Seki",
    "Sekiguchi",
    "Shibata",
    "Shimada",
    "Shimizu",
    "Shoji",
    "Sudo",
    "Sugawara",
    "Sugimoto",
    "Sugiyama",
    "Suzuki",
    "Taguchi",
    "Takada",
    "Takagi",
    "Takahashi",
    "Takano",
    "Takeda",
    "Takeuchi",
    "Tamura",
    "Tanabe",
    "Tanaka",
    "Taniguchi",
    "Tomita",
    "Tsuchiya",
    "Tsuji",
    "Uchida",
    "Ueda",
    "Uehara",
    "Uemura",
    "Ueno",
    "Wada",
    "Watanabe",
    "Yamada",
    "Yamaguchi",
    "Yamamoto",
    "Yamanaka",
    "Yamashita",
    "Yamauchi",
    "Yamazaki",
    "Yano",
    "Yasuda",
    "Yokota",
    "Yokoyama",
    "Yoshida",
    "Yoshikawa",
    "Yoshimura",
    "Yoshino",
    "Yoshioka",
};

int main(int argc, char *argv[]) {
    size_t arr_first_size = sizeof(arr_first) / sizeof(arr_first[0]);
    size_t arr_second_size = sizeof(arr_second) / sizeof(arr_second[0]);
    printf("INFO: available names: %lu; available surnames: %lu\n", arr_first_size, arr_second_size);
    int amount_to_generate;
    if (argc != 2) {
        amount_to_generate = 10;  // 1 names by default
        puts("OK: no amount provided, using default: 10.");
    } else {
        amount_to_generate = abs(atoi(argv[1]));  // convert to positive int
        printf("OK: amount to generate: %d.\n", amount_to_generate);
    }
    const char *result1, *result2;
    srand(time(NULL));
    while (amount_to_generate > 0) {
        result1 = arr_first[rand() % arr_first_size];
        result2 = arr_second[rand() % arr_second_size];
        printf("%s %s\n", result1, result2);
        amount_to_generate--;
    }
    return 0;
}
