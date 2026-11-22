#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
    char file;
    int rank;
} ChessSquare;
ChessSquare input_square() {
    ChessSquare sq;
    printf("Enter chessboard square (e.g., a5): ");
    scanf(" %c%d", &sq.file, &sq.rank);
    return sq;
}
void print_square(ChessSquare sq) {
    printf("%c%d", sq.file, sq.rank);
}
bool can_queen_move(ChessSquare from, ChessSquare to) {
    int f1 = tolower(from.file) - 'a' + 1;
    int f2 = tolower(to.file) - 'a' + 1;
    int r1 = from.rank;
    int r2 = to.rank;
    if (f1 < 1 || f1 > 8 || f2 < 1 || f2 > 8 ||
        r1 < 1 || r1 > 8 || r2 < 1 || r2 > 8) {
        return false;
    }
    int df = abs(f1 - f2);
    int dr = abs(r1 - r2);
    if (df == 0 && dr == 0) {
        return false;
    }
    return (df == 0 || dr == 0 || df == dr);
}

int main() {
    printf("=== Built-in Examples ===\n");
    ChessSquare tests[][2] = {
        {{'d', 1}, {'h', 5}},
        {{'a', 1}, {'a', 8}},
        {{'c', 3}, {'e', 4}}
    };

    for (int i = 0; i < 3; i++) {
        printf("Move ");
        print_square(tests[i][0]);
        printf(" -> ");
        print_square(tests[i][1]);
        printf(": %s\n", can_queen_move(tests[i][0], tests[i][1]) ? "POSSIBLE" : "IMPOSSIBLE");
    }
    printf("\n");

    printf("=== Interactive Input ===\n");
    printf("Start position:\n");
    ChessSquare sq1 = input_square();

    printf("Target position:\n");
    ChessSquare sq2 = input_square();

    printf("Queen move from ");
    print_square(sq1);
    printf(" to ");
    print_square(sq2);
    printf(": %s\n", can_queen_move(sq1, sq2) ? "POSSIBLE" : "IMPOSSIBLE");

    return 0;
}