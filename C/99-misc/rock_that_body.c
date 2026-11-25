#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
static void sleep_ms(int ms) { Sleep(ms); }
#else
#include <unistd.h>
static void sleep_ms(int ms) { usleep(ms * 1000); }
#endif

int main(void)
{
    const char *lines[] = {
        "I wanna da-",
        "I wanna dance in the lights",
        "I wanna ro-",
        "I wanna rock your body",
        "I wanna go",
        "I wanna go for a ride",
        "Hop in the music and",
        "Rock your body",
        "Rock that body",
        "come on, come on",
        "Rock that body",
        "(Rock your body)",
        "Rock that body",
        "come on, come on",
        "Rock that body"};

    double delays[] = {
        1, 1.1, 1.2, 1.2, 1.1,
        1.1, 1.0, 0.9, 0.7, 0.9,
        0.6, 0.8, 0.6, 1.0, 0.08};

    int n = (int)(sizeof(lines) / sizeof(lines[0]));

    // Désactiver le buffering
    setvbuf(stdout, NULL, _IONBF, 0);

    // Délai entre chaque caractère (en ms)
    int charDelayMs = 20; // ← affichage plus lent

    for (int i = 0; i < n; ++i)
    {
        const char *s = lines[i];
        size_t len = strlen(s);

        // Afficher caractère par caractère
        for (size_t j = 0; j < len; ++j)
        {
            putchar(s[j]);
            fflush(stdout);
            sleep_ms(charDelayMs);
        }

        putchar('\n');
        fflush(stdout);

        // Pause entre les lignes
        int pauseMs = (int)(delays[i] * 1000.0);
        if (pauseMs > 0)
            sleep_ms(pauseMs);
    }

    return 0;
}
