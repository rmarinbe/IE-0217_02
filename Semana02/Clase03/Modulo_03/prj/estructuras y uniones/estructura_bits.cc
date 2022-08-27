//===============================================
//Archivo: estructura_bits.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
// Example using a bit field
//============================
#include <iostream>
using namespace std;

#include "../../utilitarios/utilitarios.h"
typedef struct S_bitCard {
   unsigned int face  : 4;
   unsigned int suit  : 2;
   unsigned int color : 1;
}T_bitsCard;

static void fillDeck(T_bitsCard []);
static void deal(T_bitsCard []);

void estructuras_bits(void)
{
  T_bitsCard deck[52];
  cout << "Un T_bitsCard mide " << sizeof(T_bitsCard) << "bytes" << endl;
  fillDeck(deck);
  deal(deck);
}//______________________________________

static void fillDeck(T_bitsCard wDeck[])
{
  for (int i = 0; i <= 51; i++)
  {
    wDeck[i].face = i % 13;
    wDeck[i].suit = i / 13;
    wDeck[i].color = i / 26;
  }
}//_______________________________________________________________

/* Function deal prints the cards in two column format */
/* Column 1 contains cards 0-25 subscripted with k1 */
/* Column 2 contains cards 26-51 subscripted with k2 */

static void deal(T_bitsCard wDeck[])
{
  for (int k1 = 0, k2 = k1 + 26; k1 <= 25; k1++, k2++)
  {
    printf("Card:%3d  Suit:%2d  Color:%2d   ",
           wDeck[k1].face, wDeck[k1].suit, wDeck[k1].color);

    printf("Card:%3d  Suit:%2d  Color:%2d\n",
            wDeck[k2].face, wDeck[k2].suit, wDeck[k2].color);
  }
  end_function();
}//________________________________________________________________

