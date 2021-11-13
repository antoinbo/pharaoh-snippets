#include "stdio.h"

typedef unsigned int uint32_t;

typedef enum {
	veryeasy = 0,
	easy = 1,
	normal = 2,
	hard = 3,
	impossible = 4//,
	//unknown = 0xffffffff
} difficulty_t;

typedef struct highscore {
	uint32_t score;
	uint32_t id;
	char name[40];
	uint32_t percent; // to check
	uint32_t population; // to check
	uint32_t money; // to check
	uint32_t year; // to check
	difficulty_t difficulty;
	uint32_t unknown; // to find
	uint32_t active; // to check
} highscore_t;

int main(void) {
	int i;
	FILE *fp = NULL;
	size_t r = NULL;
	highscore_t record;
	//highscore_t records[100];

	fp = fopen("highscore.jas", "rb");
	if (!fp) {
		puts("file not found!");
		return 0;
	}

	//r = fread(records, sizeof(highscore_t), 100, fp);

	puts("id, name                                    , score , per., difficulty, pop.  ,  money, years, ?");
	for (i = 0; i < 100; i++) {
		r = fread(&record, sizeof(highscore_t), 1, fp);
		if (!record.active) continue;
		printf("%2d, %-40s, %6d, %3d%, %10d, %6d, %6d, %5d, %1d\n", 
			record.id, record.name, record.score, record.percent, record.difficulty, record.population, record.money, record.year, record.unknown);
	}

	if (fp) {
		fclose(fp);
	}

	puts("done.");

	return 0;
}
