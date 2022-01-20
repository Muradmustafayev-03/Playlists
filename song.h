#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SONG_H
#define SONG_H

typedef struct song_t
{
	int id;
	char name[256];
	char artist[256];
	char genre[256];
	int duration;
	struct song_t* next;
}song_t;

// Creating a new song
song_t* create_song(char name[], char artist[], char genre[], int duration);

// displays the song to the console
void print_song(song_t* song);

// checking if songs are the same
bool same_songs(song_t* song1, song_t* song2);

// copyin a source song into the destination reference
void copy_song(song_t** destination, song_t* source);

// printing song into the file
void song_to_file(song_t* song, FILE* file);

#endif
