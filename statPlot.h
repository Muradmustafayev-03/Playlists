#include "pbPlots.h"
#include "supportLib.h"
#include "song.h"

// Creating a plot of songs y genre and saving the plot as png-image
void plot_by_genre(double width, double height, double* songs_numbers, 
	char** genres, int genres_number, char playlist_name[]);
