#ifndef AUDIOPLAYER_H_INCLUDED
#define AUDIOPLAYER_H_INCLUDED
#include "list.h"
#include <stdlib.h>

typedef struct audioplayer_s audioplayer_t;
typedef struct composition_s composition_t;

typedef enum {
    TrackNotChosen,
    STOPPED,
    PLAY,
    PAUSE
} player_state_t;


 audioplayer_t * audioplayer_new();
 composition_t * composition_new(char * name, char * artist);
 char * composition_getName(composition_t * self);
 char * composition_getArtist(composition_t * self);
 void audioplayer_addComposition(audioplayer_t *player,composition_t * composition);
 composition_t * audioplayer_deleteComposition(audioplayer_t *player,composition_t * composition);
  composition_t * audioplayer_playByIndex(audioplayer_t *player,int index);
  composition_t * audioplayer_playPrev(audioplayer_t *player);
  composition_t * audioplayer_playNext(audioplayer_t *player);
  composition_t * audioplayer_getCurrentCompos(audioplayer_t * player);
 int audioplayer_getVolume(audioplayer_t *player);
 void audioplayer_setVolume(audioplayer_t *player, int volume);
 void audioplayer_stop(audioplayer_t *player);
 void audioplayer_pause(audioplayer_t *player);
player_state_t audioplayer_getState(audioplayer_t *player);


 typedef struct change_event_args_s {
    composition_t * prevCompos;
    composition_t * nextCompos;
} change_event_args_t;



 typedef void (*change_fn)(
    void * listener,
    audioplayer_t * sender,
    change_event_args_t * args);

void player_subscribeStart(audioplayer_t * self, void * listener, change_fn callback);
void player_unsubscribeStart(audioplayer_t * self, void * listener, change_fn callback);





#endif // AUDIOPLAYER_H_INCLUDED
