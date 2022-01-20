#include "song.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct playlist_t
{
	char name[256];
	song_t* first_song;
	song_t* last_song;
	int songs_number;
	int total_duration;
}playlist_t;

// creatinf=g a new playlist
playlist_t new_playlist(char name[]);

// appends a song list with a new song inserted after the given displacement
song_t* append_songs_list(song_t* list, song_t* song, song_t* displacement);

// appends a new song to the end of the playlist
void add_song(playlist_t* playlist, song_t* song);

// inserts a new song after the given displacement
void add_after(playlist_t* playlist, song_t* song, song_t* displacement);

// removes the song from the playlist by name
void delete_by_name(playlist_t* playlist, char song_name[]);

// removes the song from the playlist by id
void delete_by_id(playlist_t* playlist, int id);

// sorts the playlist by song name
void sort_by_name(playlist_t* playlist);

// sorts the playlist by song id
void sort_by_id(playlist_t* playlist);

// displays the playlist to the console
void print_playlist(playlist_t playlist);

// saves the playlist into the new file
void playlist_to_file(playlist_t playlist, char filepath[]);

#endif
