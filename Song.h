/**
 * Aliisa Roe
 * 12/7/15
 * Project 2
 * 
 * This is the song class header file.
 * 
 */

#ifndef SONG_H
#define SONG_H

class Song 
{
	
	private:
		std::string artist;
		std::string title;
		std::string URI;
	public:
		Song();
		Song( std::string, std::string, std::string );
		std::string getArtist();
		std::string getTitle();
		std::string getURI();
		void setArtist( std::string );
		void setTitle( std::string );
		void setURI( std::string );
		std::string toString();
		
};

#endif
