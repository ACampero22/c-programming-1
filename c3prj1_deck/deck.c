#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
#include "cards.h"

void print_hand(deck_t * hand){
  for(size_t i=0; i<hand->n_cards; i++){
    card_t card = **((hand->cards)+i);
    char value = value_letter(card);
    char suit = suit_letter(card);
    printf("%c%c ", value, suit);
  }
}

int deck_contains(deck_t * d, card_t c) {
  for(size_t i=0; i<d->n_cards; i++){
    card_t card = **((d->cards)+i);
    if(card.value==c.value && card.suit==c.suit){
      return 1;
    }
  }
  
  return 0;
}

void shuffle(deck_t * d){
  card_t ** cards = d->cards;
  card_t *temp;
  size_t n = d->n_cards;
  int rand;
  for(size_t i=0; i<n/2; i++){
    rand = random()%(n);
    temp = cards[i];
    cards[i] = cards[rand];
    cards[rand] = temp;
  }
}

void assert_full_deck(deck_t * d) {
  card_t ** card = d->cards;
  for(size_t i=0; i<d->n_cards; i++){
    card_t c = **(card+i);
    int cnt = 0;
    if(deck_contains(d, c)) {cnt++;}
    if(cnt>1){
      assert(cnt==52&&"contain duplicate cards in the deck");
    }
  }
}
