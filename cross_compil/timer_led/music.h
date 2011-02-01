#ifndef MUSIC_H
#define MUSIC_H

typedef struct {
  unsigned long pitch;
  unsigned long value;
} Note;

/*************************************************/
// Scores

extern Note const clair_lune[];
extern Note const fur_elise[];

/*************************************************/
#define STACCATO (unsigned long)50 
// Duration of the silence between notes,no Staccato if 0

/*************************************************/
// Notes

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
#define MI16  (unsigned long) RAPPORT/1329

#define SIL   (unsigned long) 1
#define END   (unsigned long) 0

/*************************************************/
// Value

#define TEMPO 8056/84

#define RONDE    (unsigned long)TEMPO*4
#define BLANCHEP (unsigned long)TEMPO*3
#define BLANCHE  (unsigned long)TEMPO*2
#define NOIREP   (unsigned long)TEMPO*1.5
#define NOIRE    (unsigned long)TEMPO
#define CROCHE   (unsigned long)TEMPO/2
#define DOUBLE   (unsigned long)TEMPO/4

/*************************************************/
// Tempo

#define LARGO    (unsigned long)84    //60
#define ADAGIO   (unsigned long)63    //80
#define MODERATO (unsigned long)50    //100
#define ALLEGRO  (unsigned long)42    //120
#define VIVACE   (unsigned long)36    //140

/*************************************************/

void musical_keyboard();
void play_score_init();
void play_score(Note const * score);

#endif
