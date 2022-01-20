#include "song.h"


song_t* create_song(char name[], char artist[], char genre[], int duration)
{
	song_t* new_song = malloc(sizeof(song_t));

	new_song->id = 0;
	strcpy(new_song->name, name);
	strcpy(new_song->artist, artist);
	strcpy(new_song->genre, genre);
	new_song->duration = duration;
	new_song->next = NULL;

	return new_song;
}


void print_song(song_t* song)
{
	printf("Name: %s\n", song->name);
	printf("Artist: %s\n", song->artist);
	printf("Duration: %i:%i\n", song->duration / 60, song->duration % 60);
	printf("Genre: %s\n", song->genre);
	printf("ID in the playlist: %i\n", song->id);
}


bool same_songs(song_t* song1, song_t* song2)
{
	if (song1 == NULL && song2 == NULL)
	{
		return true;
	}
	else if (song1 == NULL || song2 == NULL)
	{
		return false;
	}
	else if (song1->name == song2->name && 
		song1->artist == song2->artist &&
		song1->genre == song2->genre)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void copy_song(song_t** destination, song_t* source)
{
	(*destination)->id = source->id;

	char* name = source->name;
	char* artist = source->artist;
	char* genre = source->genre;
	

	strcpy((*destination)->name, name);
	strcpy((*destination)->artist, artist);
	strcpy((*destination)->genre, genre);
	(*destination)->duration = source->duration;
}


void song_to_file(song_t* song, FILE* file)
{
	fprintf(file, "Name: %s\n", song->name);
	fprintf(file, "Artist: %s\n", song->artist);
	fprintf(file, "Duration: %i:%i\n", song->duration / 60, song->duration % 60);
	fprintf(file, "Genre: %s\n", song->genre);
	fprintf(file, "ID in the playlist: %i\n", song->id);

}
