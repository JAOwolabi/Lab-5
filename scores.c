#include <stdio.h>

#define TOUCHDOWN 6
#define FIELD_GOAL 3
#define SAFETY 2
#define TOUCHDOWN_2PT 8
#define TOUCHDOWN_1PT 7

void printScoringPlays(int td, int fg, int safety, int td_2pt, int td_1pt) {
    if (td > 0) printf("%d TD ", td);
    if (td_2pt > 0) printf("%d TD + 2pt ", td_2pt);
    if (td_1pt > 0) printf("%d TD + 1pt FG ", td_1pt);
    if (fg > 0) printf("%d FG ", fg);
    if (safety > 0) printf("%d Safety ", safety);
    printf("\n");
}

void findScoringCombos(int score, int td, int fg, int safety, int td_2pt, int td_1pt) {
    if (score == 0) {
        printScoringPlays(td, fg, safety, td_2pt, td_1pt);
        return;
    }

    if (score >= TOUCHDOWN) findScoringCombos(score - TOUCHDOWN, td + 1, fg, safety, td_2pt, td_1pt);
    if (score >= FIELD_GOAL) findScoringCombos(score - FIELD_GOAL, td, fg + 1, safety, td_2pt, td_1pt);
    if (score >= SAFETY) findScoringCombos(score - SAFETY, td, fg, safety + 1, td_2pt, td_1pt);
    if (score >= TOUCHDOWN_2PT) findScoringCombos(score - TOUCHDOWN_2PT, td, fg, safety, td_2pt + 1, td_1pt);
    if (score >= TOUCHDOWN_1PT) findScoringCombos(score - TOUCHDOWN_1PT, td, fg, safety, td_2pt, td_1pt + 1);
}

int main() {
    int score;

    printf("Enter 0 or 1 to STOP\n");
    do {
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score > 1) {
            printf("Possible combinations of scoring plays:\n");
            findScoringCombos(score, 0, 0, 0, 0, 0);
        }
    } while (score > 1);

    return 0;
}
