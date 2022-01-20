#include "statPlot.h"


void plot_by_genre(double width, double height, double* songs_numbers, 
	char** genres, int genres_number, char playlist_name[])
{
    BarPlotSettings *settings;  // settings for the barplot
    RGBABitmapImageReference *canvasReference;  // image reference for the barplot

    settings = GetDefaultBarPlotSettings();

    // changing necessary settings
    settings->barPlotSeries = (BarPlotSeries**)malloc(sizeof(BarPlotSeries) * 1.0);
  	settings->barPlotSeriesLength = 1.0;
  	settings->barPlotSeries[0] = GetDefaultBarPlotSeriesSettings();
  	free(settings->barPlotSeries[0]->ys);
  	settings->barPlotSeries[0]->ys = songs_numbers;
  	settings->barPlotSeries[0]->ysLength = genres_number;
  	canvasReference = (RGBABitmapImageReference *)malloc(sizeof(RGBABitmapImageReference));
  	
  	settings->width = width;
  	settings->height = height;


  	// The commented part below is meant to change x-Labels from numbers(1, 2, 3...) to the
  	// genre names(Pop, Rock...), but when active it causes Segmentation faults
  	
  	// settings->autoLabels = false;
  	// settings->xLabels = (StringReference**)malloc(sizeof(StringReference) * genres_number);
  	// settings->xLabelsLength = genres_number;

  	// int i;
  	// for (i = 0; i < genres_number; i++)
  	// {
  	// 	settings->xLabels[i] = CreateStringReference(genres[i], 10);
  	// }

  	DrawBarPlotFromSettings(canvasReference, settings);
  	

  	size_t length;
	double* png = ConvertToPNG(&length, canvasReference->image);

	char filename[256];
	strcpy(filename, playlist_name);

	WriteToFile(png, length, filename);
	DeleteImage(canvasReference->image);
}