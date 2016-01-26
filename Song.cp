/**
 * Aliisa Roe
 * 12/7/15
 * Project 2
 * 
 * This is the song class.
 * 
 */


#include <string>
#include "Song.h"

using namespace std;

Song::Song()
{
	artist = "Unknown";
	title = "Unknown";
	URI = "Unknown";
}

Song::Song( string a, string t, string u )
{
	artist = a;
	title = t;
	URI = u;
}

string Song::getArtist() 
{
	return artist;
}

string Song::getTitle()
{
	return title;
}

string Song::getURI()
{
	return URI;
}

void Song::setArtist( string a )
{
	artist = a;
}

void Song::setTitle( string t )
{
	title = t;
}

void Song::setURI( string u )
{
	URI = u;
}

string Song::toString()
{
	return title + " by " + artist;
}
