#include "song.h"
#include "playlist.h"
#include "statPlot.h"
#include <stdio.h>


playlist_t create_playlist_from_user();

song_t* create_song_from_user();

int main()
{
	// Creating and filling an example playlist
	playlist_t example_playlist = new_playlist("Example playlist");

	add_song(&example_playlist, create_song("Devil Town", "Cavetown", "Indie", 270));
	add_song(&example_playlist, create_song("Paranoid", "Black Sabbath", "Rock", 168));
	add_song(&example_playlist, create_song("Instant Crush", "Daft Punk", "EDM", 338));
	add_song(&example_playlist, create_song("Future Never Dies", "Scorpions", "Rock", 242));
	add_song(&example_playlist, create_song("Toxisity", "System Of A Down", "Rock", 218));
	add_song(&example_playlist, create_song("Sunset Lover", "Petit Biscuit", "EDM", 238));
	add_song(&example_playlist, create_song("Rolling Stone", "Hurts", "Pop", 221));

	
	printf("Choose one of the options:\n");
	printf("1) Show an example playlist\n");
	printf("2) Create a new playlist\n");

	int choice;
	scanf("%i", choice);

	switch (choice)
	{
		case 1: 
			// Displaying the ec=xample playlist
			print_playlist(example_playlist);
		case 2:
			// Asking user to create their own playlist
			playlist_t playlist = create_playlist_from_user();
			// Displaying the platlist to the console
			print_playlist(playlist);
			// Saving the playlist into the file
			playlist_to_file(playlist, "saved_playlist");
		default:
			printf("Wrong input\n");
	}
	
	return 0;
}


playlist_t create_playlist_from_user()
{
	char name[256];
	int songs_number;

	printf("Give a name to the playlist: ");
	scanf("%s", name);

	playlist_t playlist = new_playlist(name);

	printf("Enter the number of songs in the playlist: ");
	scanf("%i", &songs_number);

	int i;
	for(i =0; i < songs_number; i++)
	{
		song_t* new_song = create_song_from_user();
		add_song(&playlist, new_song);
	}

	return playlist;
}


song_t* create_song_from_user()
{
	char name[256];
	char artist[256];
	char genre[256];
	int duration;

	printf("\n");

	printf("Enter the name of the song: ");
	scanf("%s", name);

	printf("Enter the name of the artist: ");
	scanf("%s", artist);

	printf("Enter the genre: ");
	scanf("%s", genre);

	printf("Enter the duration of the song in seconds: ");
	scanf("%i", &duration);

	printf("\n");

	return create_song(name, artist, genre, duration);
}
