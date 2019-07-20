#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "future.h"
#include "deck.h"
#include "card.h"

void add_future_card(future_cards_t *fc, size_t index, card_t *ptr){
  deck_t * decks = fc->decks;
  if(index < fc->n_decks){
    decks[index].cards = realloc(decks[index].cards, (decks[index].n_cards+1)*sizeof(*decks[index].cards));
    decks[index].cards[decks.n_cards] = ptr;
    decks[index].n_cards++;
  }
  else{
    while(fc->n_decks <= index){
      decks = realloc(decks, (fc->n_decks+1)*sizeof(*decks));
      decks[fc->n_decks].cards = NULL;
      decks[fc->n_decks].n_cards=0;
      fc->n_decks++;
    }
    decks[index].cards = realloc(decks[index].cards,
				 (decks[index].n_cards+1)*sizeof(*decks[index].cards));
    decks[index].cards[decks[index].n_cards] = ptr;
    decks[index].n_cards++;
  }
  
}

void future_cards_from_deck(deck_t * deck, future_cards_t *fc){
  if(deck->n_cards < fc->n_decks){
    fprintf(stderr, "not enough cards in the deck");
    return EXIT_FAILURE;
  }

  for(int i=0; i<fc->n_decks; i++){
    if(fc->decks[i].n_cards==0) continue; //skipping null pointer
    for(int j=0; j<fc->decks[i].n_cards; j++){
      fc->decks[i].cards[j]->value = deck->cards[i]->value;
      fc->decks[i].cards[j]->suit = deck->cards[i]->suit;
    }
  }
}
