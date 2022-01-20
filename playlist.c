#include "playlist.h"


playlist_t new_playlist(char name[])
{
	playlist_t playlist;

	strcpy(playlist.name, name);
	playlist.first_song = NULL;
	playlist.last_song = NULL;
	playlist.songs_number = 0;
	playlist.total_duration = 0;

	return playlist;
}


song_t* append_songs_list(song_t* list, song_t* song, song_t* displacement)
{
	if (list == NULL)
	{
		list = song;
	}
	else if (same_songs(list, displacement) || list->next == NULL)
	{
		// adding the new song into the right place
		song_t* next = list->next;
		song->next = next;
		list->next = song;
	}
	else
	{
		// going through the songs list recursively
		list->next = append_songs_list(list->next, song, displacement);
	}
	return list;
}


void add_song(playlist_t* playlist, song_t* song)
{
	song->id = playlist->songs_number;
	playlist->first_song = append_songs_list(playlist->first_song, song, playlist->last_song);
	playlist->last_song = song;
	playlist->songs_number += 1;
	playlist->total_duration += song->duration;
}


void add_after(playlist_t* playlist, song_t* song, song_t* displacement)
{
	song->id = playlist->songs_number;
	playlist->first_song = append_songs_list(playlist->first_song, song, displacement);
	playlist->songs_number += 1;
	playlist->total_duration += song->duration;

	// searching for the last song
	song_t* current = playlist->first_song;
	while (current->next != NULL)
	{
		current = current->next;
	}
	playlist->last_song = current;
}


void delete_by_name(playlist_t* playlist, char song_name[])
{
	// creatingg a new playlist
	playlist_t new = new_playlist(playlist->name);

	song_t* curent = playlist->first_song;

	while (curent != NULL)
	{
		// adding there eachsong except the one we want to delete
		if (curent->name != song_name)
		{
			add_song(&new, curent);
		}
		curent = curent->next;
	}

	*playlist = new;
}


void delete_by_id(playlist_t* playlist, int id)
{
	// creatingg a new playlist
	playlist_t new = new_playlist(playlist->name);

	song_t* curent = playlist->first_song;

	while (curent != NULL)
	{
		// adding there eachsong except the one we want to delete
		if (curent->id != id)
		{
			add_song(&new, curent);
		}
		curent = curent->next;
	}

	*playlist = new;
}


void sort_by_name(playlist_t* playlist)
{
	// using bubble-sort algorithm

	int i;
	for (i = 0; i < playlist->songs_number; i++)
	{
		song_t* current;

		for (current = playlist->first_song; current->next != NULL; current = current->next)
		{
			if (strcmp(current->name, current->next->name) > 0)
			{

				song_t* copy = create_song("", "", "", 0);

				// changing places
				copy_song(&copy, current);
				copy_song(&current, current->next);
				copy_song(&current->next, copy);
			}
		}
	}
}


void sort_by_id(playlist_t* playlist)
{
	// using bubble-sort algorithm

	int i;
	for (i = 0; i < playlist->songs_number; i++)
	{
		song_t* current;

		for (current = playlist->first_song; current->next != NULL; current = current->next)
		{
			if (current->id > current->next->id)
			{

				song_t* copy = create_song("", "", "", 0);

				// changing places
				copy_song(&copy, current);
				copy_song(&current, current->next);
				copy_song(&current->next, copy);
			}
		}
	}
}


void print_playlist(playlist_t playlist)
{
	printf("Name: %s\n", playlist.name);
	printf("\n");
	printf("First song: %s\n", playlist.first_song->name);
	printf("Last song: %s\n", playlist.last_song->name);
	printf("\n");
	printf("Songs number: %i\n", playlist.songs_number);

	int hours = playlist.total_duration / 3600;
	int minutes = (playlist.total_duration % 3600) / 60;
	int seconds =playlist.total_duration % 60;

	printf("Total duration: %i:%i:%i\n", hours, minutes, seconds);
	printf("\n");

	printf("Songs list: \n");

	song_t* current = playlist.first_song;

	while (current != NULL)
	{
		printf("\n");
		print_song(current);
		current = current->next;
	}
}


void playlist_to_file(playlist_t playlist, char filename[])
{
	FILE* file;

	file = fopen(filename, "w");

	fprintf(file, "Name: %s\n", playlist.name);
	fprintf(file, "\n");
	fprintf(file, "First song: %s\n", playlist.first_song->name);
	fprintf(file, "Last song: %s\n", playlist.last_song->name);
	fprintf(file, "\n");
	fprintf(file, "Songs number: %i\n", playlist.songs_number);

	int hours = playlist.total_duration / 3600;
	int minutes = (playlist.total_duration % 3600) / 60;
	int seconds =playlist.total_duration % 60;

	fprintf(file, "Total duration: %i:%i:%i\n", hours, minutes, seconds);
	fprintf(file, "\n");

	fprintf(file, "Songs list: \n");

	song_t* current = playlist.first_song;

	while (current != NULL)
	{
		fprintf(file, "\n");
		song_to_file(current, file);
		current = current->next;
	}

	fclose(file);
}
