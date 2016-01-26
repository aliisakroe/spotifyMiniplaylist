/**
 * Aliisa Roe
 * 12/7/15
 * Project 2
 * 
 * The Library class includes Songs.
 * 
 */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "Song.h"
#include "Library.h"
using namespace std;


Library::Library(string playlistFilename)
{
	readInPlaylist(playlistFilename);
}

void Library::readInPlaylist(string filename)
{
	ifstream infile;
	infile.open(filename.c_str());
	string line;
	int count = 0;
	
	if (infile.is_open())
	{
		cout << "Reading in music library from playlist file: " << filename << endl;
		while ( getline (infile, line) )
		{
			if ( count != 0 ) {
			int firstCommaPos = line.find(",");
			string URI = line.substr(1, firstCommaPos - 2);
					
			string titleStartStr = line.substr(firstCommaPos + 1);
			int secondCommaPos = titleStartStr.find(",");
			string title = titleStartStr.substr(0, secondCommaPos);
			
			string artistStartStr = titleStartStr.substr(secondCommaPos + 2); 
			int thirdCommaPos = artistStartStr.find("\"");
			string artist = artistStartStr.substr(0, thirdCommaPos);
			
			Song song(artist, title, URI);
			songList.push_back(song);
			
			//don't add artist multiple times
			if ( find( artistList.begin(), artistList.end(), artist ) == artistList.end() ){
				artistList.push_back(artist);
			}
		}
			count++;
		}
		cout << count << " songs read in. " << artistList.size() << " artists in in the library. Closing playlist file. \n"  << endl;
		infile.close();
	}
}

void Library::printSongs()
{
	for (int i=0; i<songList.size(); i++)
	{
		Song song = songList.at(i);
		cout << song.toString() << endl;
	}
}

bool Library::isArtistInLibrary(string artist) 
{
	if ( find( artistList.begin(), artistList.end(), artist ) != artistList.end() ){
		return true;
	} else {
		return false;
	}
}

void Library::printArtists()
{
	for (int i=0; i<artistList.size(); i++)
	{
		cout << artistList.at(i) << endl;
	}
}

Song Library::getSongForArtist(string artist) 
{
	string songArtist;
	Song song, songForArtist;
	
	for ( int i = 0; i < songList.size(); i++ ) {
		song = songList.at(i);
		songArtist = song.getArtist();
		if (songArtist == artist) {
			songForArtist = song;
		}
	}
	return songForArtist;
}

void Library::recommendPlaylist(string vibe)
{
	Song song;
	
	ofstream newFile (vibe);
	if ( vibe.find("Late Night") != -1 ) {
		song = getSongForArtist("Lotus");
		cout << song.toString() << endl;
		newFile << song.getURI() << endl;
		}
	if ( vibe.find("Inspirational") != -1 ) {
		song = getSongForArtist("Penguin Cafe Orchestra");
		cout << song.toString() << endl;
		newFile << song.getURI() << endl;
		}
	if ( vibe.find("Upbeat") != -1 ) {
		song = getSongForArtist("Unknown Mortal Orchestra");
		cout << song.toString() << endl;
		newFile << song.getURI() << endl;
		}
	if ( vibe.find("Creative") != -1 ) {
		song = getSongForArtist("Tonstartssbandht");
		cout << song.toString() << endl;
		newFile << song.getURI() << endl;
		}
	if ( vibe.find("Electro") != -1 ) {
		song = getSongForArtist("Ratatat");
		cout << song.toString() << endl;
		newFile << song.getURI() << endl;
		}
	if ( vibe.find("Jams") != -1 ) {
		song= getSongForArtist("Big Wild");
		cout << song.toString() << endl;
		newFile << song.getURI() << endl;
		}
	if ( vibe.find("Sounds") != -1 ) {
		song = getSongForArtist("Andrew Bird");
		cout << song.toString() << endl;
		newFile << song.getURI() << endl;
		}
	if ( vibe.find("Chill Vibes") != -1 ) {
		song = getSongForArtist("The Shanghai Restoration Project");
		cout << song.toString() << endl;
		newFile << song.getURI() << endl;
		}
	
}

