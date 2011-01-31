#ifndef MUSIC_H
#define MUSIC_H

#define	RAPPORT 206250 //66000000/DIV_VAL/(PRESC+1)

#define SOL0  (unsigned long) RAPPORT/196
#define SOLd0 (unsigned long) RAPPORT/208
#define LA0   (unsigned long) RAPPORT/220
#define LAd0  (unsigned long) RAPPORT/233
#define SI0   (unsigned long) RAPPORT/247
#define DO    (unsigned long) RAPPORT/262
#define DOd   (unsigned long) RAPPORT/277
#define RE    (unsigned long) RAPPORT/294
#define REd   (unsigned long) RAPPORT/311
#define MI    (unsigned long) RAPPORT/330
#define FA    (unsigned long) RAPPORT/350
#define FAd   (unsigned long) RAPPORT/370
#define SOL   (unsigned long) RAPPORT/392
#define SOLd  (unsigned long) RAPPORT/415
#define LA    (unsigned long) RAPPORT/440
#define LAd   (unsigned long) RAPPORT/466
#define SI    (unsigned long) RAPPORT/494
#define DO8   (unsigned long) RAPPORT/523
#define DOd8  (unsigned long) RAPPORT/554
#define RE8   (unsigned long) RAPPORT/587
#define REd8  (unsigned long) RAPPORT/622
#define MI8   (unsigned long) RAPPORT/659
#define FA8   (unsigned long) RAPPORT/698
#define FAd8  (unsigned long) RAPPORT/740
#define SOL8  (unsigned long) RAPPORT/784

#define SIL   (unsigned long) 1
#define END   (unsigned long) 0

void music();
void play_score(unsigned long const * score, unsigned long noire);

#endif
