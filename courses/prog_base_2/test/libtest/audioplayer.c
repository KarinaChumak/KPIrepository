
#include "audioplayer.h"
#include "list.h"

struct audioplayer_s{
    player_state_t state;
    list_t * subscribers;
    list_t * compositions;
    int   volume;
    int indexOfCurrent;
};


struct composition_s{
  char * name;
  char * artist;
};


typedef struct subscriber_s {
    void * listener;
    change_fn callback;
} subscriber_t;



 audioplayer_t * audioplayer_new() {
    audioplayer_t * self = malloc(sizeof(audioplayer_t));
    self->subscribers = list_new();
    self->compositions = list_new();
    self->volume = 20;
   self->state = TrackNotChosen;
   self->indexOfCurrent = -1;
    return self;
}


composition_t * composition_new(char * name, char * artist){
      composition_t * self = malloc(sizeof(composition_t));
    self->artist = artist;
    self->name =  name;
    return self;
}


void audioplayer_addComposition(audioplayer_t *player,composition_t * composition){
    list_push_back(player->compositions, composition);
}

composition_t * audioplayer_playByIndex(audioplayer_t *player,int index){
  player->state = PLAY;
  player->indexOfCurrent = index;
return (composition_t *)list_get(player->compositions, player->indexOfCurrent);
}


char * composition_getName(composition_t * self){
return self->name;
}

char * composition_getArtist(composition_t * self){
return self->artist;
}

composition_t * audioplayer_getCurrentCompos(audioplayer_t * player){
   return (composition_t *)list_get(player->compositions, player->indexOfCurrent);
}

 void audioplayer_stop(audioplayer_t *player){
   player->state = STOPPED;
  player->indexOfCurrent = -1;
 }

  void audioplayer_pause(audioplayer_t *player){
   player->state = PAUSE;
 }


int audioplayer_getIndex(audioplayer_t *player){
        return player->indexOfCurrent;
}

composition_t * audioplayer_playNext(audioplayer_t *player){
    player->state = PLAY;
  player->indexOfCurrent ++;
       /* change_event_args_t args;
      args.prevCompos = (composition_t * )list_get(player, player->indexOfCurrent);
        args.nextCompos = (composition_t * )list_get(player, player->indexOfCurrent+2);

        for (int i = 0; i < list_getSize(player->subscribers); i++) {
            subscriber_t * sub = (subscriber_t *)list_get(player->subscribers, i);
            sub->callback(sub->listener, player, &args);}
*/
return (composition_t *)list_get(player->compositions, player->indexOfCurrent);
}



composition_t * audioplayer_playPrev(audioplayer_t *player){
    player->state = PLAY;
  player->indexOfCurrent--;
return (composition_t *)list_get(player->compositions, player->indexOfCurrent);
}

composition_t * audioplayer_deleteComposition(audioplayer_t *player,composition_t * composition){


}

player_state_t audioplayer_getState(audioplayer_t *player){
return player->state;
}


 int audioplayer_getVolume(audioplayer_t *player){
 return player->volume;
}

void player_subscribeStart(audioplayer_t * self, void * listener, change_fn callback)
{
    subscriber_t * sub = malloc(sizeof(subscriber_t));
    sub->listener = listener;
    sub->callback = callback;
    list_push_back(self->subscribers, sub);
}

void player_unsubscribeStart(audioplayer_t * self, void * listener, change_fn callback) {
    for (int i = 0; i < list_getSize(self->subscribers); i++) {
        subscriber_t * subs = (subscriber_t *)list_get(self->subscribers, i);
        if ((subs->listener == listener) && (subs->callback == callback)) {
            list_remove(self->subscribers, i);
            break;
        }
    }
}


 void audioplayer_setVolume(audioplayer_t *player, int volume){
 player->volume = volume;
}
