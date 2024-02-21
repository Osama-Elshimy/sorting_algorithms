#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * value_to_int - converts card value to integer
 *
 * @value: value of card
 *
 * Return: integer value of card
 */

int value_to_int(const char *value)
{
	int i;

	if (strcmp(value, "Ace") == 0)
		i = 0;
	if (strcmp(value, "1") == 0)
		i = 1;
	if (strcmp(value, "2") == 0)
		i = 2;
	if (strcmp(value, "3") == 0)
		i = 3;
	if (strcmp(value, "4") == 0)
		i = 4;
	if (strcmp(value, "5") == 0)
		i = 5;
	if (strcmp(value, "6") == 0)
		i = 6;
	if (strcmp(value, "7") == 0)
		i = 7;
	if (strcmp(value, "8") == 0)
		i = 8;
	if (strcmp(value, "9") == 0)
		i = 9;
	if (strcmp(value, "10") == 0)
		i = 10;
	if (strcmp(value, "Jack") == 0)
		i = 11;
	if (strcmp(value, "Queen") == 0)
		i = 12;
	if (strcmp(value, "King") == 0)
		i = 13;

	return (i);
}

/**
 * compare_cards - compares cards
 *
 * @a: first card
 * @b: second card
 *
 * Return: 0 if equal, 1 if not
 */

int compare_cards(const void *a, const void *b)
{
	deck_node_t *node_a = *(deck_node_t **)a;
	deck_node_t *node_b = *(deck_node_t **)b;

	if (node_a->card->kind != node_b->card->kind)
		return ((int)node_a->card->kind > (int)node_b->card->kind);

	return (value_to_int(node_a->card->value) >
			value_to_int(node_b->card->value));
}

/**
 * sort_deck - sorts deck
 *
 * @deck: deck to sort
 */

void sort_deck(deck_node_t **deck)
{
	deck_node_t *current = *deck;
	deck_node_t *nodes[52];
	int i = 0;

	for (i = 0; i < 52; i++)
	{
		nodes[i] = current;
		current = current->next;
	}

	qsort(nodes, 52, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < 52; i++)
	{
		nodes[i]->prev = nodes[i - 1];
		nodes[i]->next = nodes[i + 1];
	}

	nodes[0]->prev = NULL;
	nodes[51]->next = NULL;
	*deck = nodes[0];
}
