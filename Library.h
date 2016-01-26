/**
 * Aliisa Roe
 * 12/7/15
 * Project 2
 * 
 * This Library class has songs with functions to 
 * access and manipulate these.
 * 
 */
 
#ifndef LIBRARY_H
#define LIBRARY_H

#include "Song.h"
//#include "User.h"

class Library 
{
  public:
	Library(std::string filename); 
	void readInPlaylist(std::string filename);  
	void printSongs(); 
	void printArtists(); 
	void recommendPlaylist(std::string vibe);
	bool isArtistInLibrary(std::string artist);
	Song getSongForArtist(std::string artist);
  private: 
	std::vector<Song> songList; 
	std::vector<std::string> artistList;
};
#endif
