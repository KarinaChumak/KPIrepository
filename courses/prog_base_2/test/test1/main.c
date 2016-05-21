#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "audioplayer.h"

typedef struct user_s {
    const char * name;

} user_t;

user_t * user_new(const char * name) {
    user_t * self = malloc(sizeof(user_t));
    self->name = name;
    return self;
}

void user_free(user_t * self) {
    free(self);
}

const char * user_getName(user_t * self) {
    return self->name;
}


void onCompositionChanged(
    user_t * listener,
    audioplayer_t * sender,
    change_event_args_t * args) {

    printf("In method %s() of user %s:\n", __func__, user_getName(listener));
    printf("Composition changed! Prev :%s %s, Next :%s %s", composition_getName(args->prevCompos),composition_getArtist(args->prevCompos),composition_getName(args->nextCompos),composition_getArtist(args->nextCompos));
}




int main()
{

       audioplayer_t * player = audioplayer_new();
        composition_t * c1 = composition_new ("Lorelei", "Scorpions");
        audioplayer_addComposition(player, c1);
        composition_t * c2= composition_new ("Humanity", "Scorpions");
        audioplayer_addComposition(player, c2);
        composition_t * c3= composition_new ("Wind of change", "Scorpions");
        audioplayer_addComposition(player, c2);
        composition_t * c4= composition_new ("Hotel california", "Eagles");
        audioplayer_addComposition(player, c2);


   /* user_t * user1 = user_new("Ivan");
    user_t * user2 = user_new("Petro");
    player_subscribeStart(player, user1, (change_fn)onCompositionChanged);
    player_subscribeStart(player, user2, (change_fn)onCompositionChanged);
    audioplayer_playNext(player);
*/

      composition_t * tmp = composition_new (" ", " ");
       tmp = audioplayer_playByIndex(player,0);
       printf("current :\n name:%s\n   artist:%s\n  volume :%i\n",composition_getName(audioplayer_getCurrentCompos(player)), composition_getArtist(audioplayer_getCurrentCompos(player)), audioplayer_getVolume(player));
        tmp = audioplayer_playNext(player);
        audioplayer_setVolume(player,30);
       printf("current :\n name:%s\n   artist:%s\n  volume :%i\n",composition_getName(audioplayer_getCurrentCompos(player)), composition_getArtist(audioplayer_getCurrentCompos(player)), audioplayer_getVolume(player));

       // audioplayer_stop(player);
        if(audioplayer_getIndex(player)== -1)
            printf("\nSTOPPED");






    return 0;

}
