Modules:

1. main.c
The main module to combines all the features together

General variables:
playlist_t example_playlist - an example platlist
playlist_t playlist - a playlist, created by the user


Subprogramms:

playlist_t create_playlist_from_user()

	Description: lets user enter all the necessary information to create a playlist, and creates it
	Who did: Salman Salmanzada
	Time spent: 5 min

	List of variables:
	char name[256] - the name of the playlist
	int songs_number - number of songs in the playlist
	playlist_t playlist - the playlist to create
	song_t* new_song - each of the created and added to the playlist songs


song_t* create_song_from_user()

	Description: lets user enter all the necessary information to create a song, and creates it
	Who did: Salman Salmanzada
	Time spent: 5 min

	List of variables:
	char name[256] - the name of the song
	char artist[256] - the artist of the song
	char genre[256] - the genre of the song
	int duration - duration of the song in seconds

int main()

	Description: main function
	Who did: Salman Salmanzada
	Time spent: 15 min

	List of variables:
	playlist_t example_playlist - an example platlist
	playlist_t playlist - a playlist, created by the user


2. statPlot.c & statPlot.h
The module to plot statistics of songs in a playlist by genre

General variables:
double width - width of the image
double height - the height of the image
double* songs_numbers - the list of numbers of songs by genre
char** genres - the list of genres
int genres_number - the number of genres
char playlist_name[] - the name of the playlist
BarPlotSettings *settings - settings for the barplot
RGBABitmapImageReference *canvasReference - image reference for the barplot
size_t length - the length of png
double* png - the png image reference


Subprogramms:

void plot_by_genre(args)

	Description: plots statistics of songs in a playlist by genre

	List of variables:
	double width - width of the image
	double height - the height of the image
	double* songs_numbers - the list of numbers of songs by genre
	char** genres - the list of genres
	int genres_number - the number of genres
	char playlist_name[] - the name of the playlist
	BarPlotSettings *settings - settings for the barplot
	RGBABitmapImageReference *canvasReference - image reference for the barplot
	size_t length - the length of png
	double* png - the png image reference


3. songs.c & songs.h
The module for manipulations with songs


Subprogramms:

song_t* create_song(char name[], char artist[], char genre[], int duration)
	
	Description: creates a song

	List of variables:
	char name[] - the name of the song
	char artist[] - the name of artist
	char genre[] -  the genre of song
	int duration - the duration of song in seconds
	song_t* new_song - the new created song


void print_song(song_t* song)
	
	Description: displays the song onto the console

	List of variables:
	song_t* song - the song to display


bool same_songs(song_t* song1, song_t* song2)

	Description: checks if 2 songs are same

	List of variables:
	song_t* song1, song2 - two songs to compare


void copy_song(song_t** destination, song_t* source)

	Description: copies the data of source song into the destination song

	List of variables:
	song_t** destination - the adress of the song to copy data in
	song_t* source - the song to copy data from
	char* name = the copied name of the song
	char* artist = the copied name of the artist
	char* genre = the copied name of the genre


void song_to_file(song_t* song, FILE* file)

	Description: saves the song data into the file

	List of variables:
	song_t* song - the song to save
	FILE* file - the file to save the song into


4. playlist.c & playlist .h
The module for manipulations with playlists


Subprogramms:

playlist_t new_playlist(char name[])

	Description: creates a new empty playlist
	List of variables:
	char name[] - the name of the playlist
	playlist_t playlist - a new created playlist

song_t* append_songs_list(song_t* list, song_t* song, song_t* displacement)

	Description: adds a song into a particular place in the linked list

	List of variables:
	song_t* list - a linked list of the songs
	song_t* song - the song to add into the list
	song_t* displacement - the song to insert a new song after

void add_song(playlist_t* playlist, song_t* song)

	Description: adds a song in the end of the playlist

	List of variables:
	playlist_t* playlist - the playist to add the song in
	song_t* song - the song to add to the playlist

void add_after(playlist_t* playlist, song_t* song, song_t* displacement)

	Description: adds the song after a particular song of the playlist

	List of variables:
	playlist_t* playlist - the playist to add the song in
	song_t* song - the song to add into the playlist
	song_t* displacement - the song to insert a new song after

void delete_by_name(playlist_t* playlist, char song_name[])

	Description: deletes the song from the playlist by name

	List of variables:
	playlist_t* playlist - the playlist
	char song_name[] - the name of the song to delete
	playlist_t new - the new playlist to assert instead of the initial

void delete_by_id(playlist_t* playlist, int id)
	
	Description: deletes the song from the playlist by name

	List of variables:
	playlist_t* playlist - the playlist
	int id - the id of the song to delete
	playlist_t new - the new playlist to assert instead of the initial

void sort_by_name(playlist_t* playlist)

	Description: sorts the playlist in alphabetic order by song name
	List of variables:
	playlist_t* playlist - the playlist to sort
	int i - counter
	song_t* current - current song while searching along the playlist
	song_t* copy - the copied song to change places with the other one

void sort_by_id(playlist_t* playlist)

	Description: sorts the playlist by song id

	List of variables:
	playlist_t* playlist - the playlist to sort
	int i - counter
	song_t* current - current song while searching along the playlist
	song_t* copy - the copied song to change places with the other one

void print_playlist(playlist_t playlist)

	Description: displays the playlist onto the console

	List of variables:
	playlist_t* playlist - the playlist to display
	int hours = number of hours of the duration
	int minutes = number of minutes of the duration(hours substracted)
	int seconds = number of seconds of the duration(minutes substracted)
	song_t* current - current song while going along the playlist

void playlist_to_file(playlist_t playlist, char filename[])

	Description: saves the playlist into the newly created file
	List of variables:
	playlist_t* playlist - the playlist to save
	char filename[] - the name of the file to write the playlist in
	FILE* file - the file to write the playlist in
	int hours = number of hours of the duration
	int minutes = number of minutes of the duration(hours substracted)
	int seconds = number of seconds of the duration(minutes substracted)
	song_t* current - current song while going along the playlist
