/**
 * Aliisa Roe
 * 12/7/15
 * Project 2
 * 
 * This is the main driver 
 * 
 */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Song.h"
#include "Library.h"
using namespace std;

int main (int argc, char* argv[])
{
	
	string playlistFilename(argv[1]);
	Library library(playlistFilename);

	string timeOfDay, vibe, homework, mood, time, activity, needing, goToUrl;
	
	cout << "Hello, I have a small music library for studying music." << endl;
	cout << "What time of day is it? (m)morning, (a)afternoon, (n)night" << endl;
	cin >> timeOfDay;
	while (timeOfDay != "n" && timeOfDay != "m" && timeOfDay != "a") {
		cout << "Please type that again --(m)morning, (a)afternoon, (n)night"<< endl;
		cin >> timeOfDay;
	}
	if ( timeOfDay == "n" ){
		vibe = "Late Night ";
		time = "late night";
	} else if ( timeOfDay == "m" ){
		vibe = "Inspirational ";
		time = "the morning";
	} else if ( timeOfDay == "a" ){
		vibe = "Upbeat ";
		time = "the afternoon";
	}
	
	
	cout << "What type of homework are you doing? (p)paper writing or reading, (m)math/science or coding, " << endl;
	cin >> homework;
	while (homework != "p" && homework != "m" ) {
		cout << "Please type that again --(p)paper writing or reading, (m)math/science or coding"<< endl;
		cin >> homework;
	}
	if ( homework == "p" ){
		vibe += "Creative ";
		activity = "to write this paper";
	} else if ( homework == "m" ){
		vibe += "Electro ";
		activity = "to solve these problems";
	}
	
	
	cout << "Do you need? (m)motivation, (c)creativity, (k)to keep on chugging" << endl;
	cin >> mood;
	while (mood != "m" && mood != "c" && mood != "k" ) {
		cout << "Please type that again --(m)motivation, (c)creativity, (k)to keep on chugging"<< endl;
		cin >> mood;
	}
	if ( mood == "m" ){
		vibe += "Jams";
		needing = "motivation";
	} else if ( mood == "c" ){
		vibe += " Sounds ";
		needing = "creativity";
	}  else if ( mood == "k" ){
		vibe += " Chill Vibes ";
		needing = "to keep on chugging";
	}

	string userFeeling = timeOfDay + homework + mood;
	cout << "\nAlright, it sounds like you're feeling ready to study." << endl;
	cout << "Since it's " << time << " and you need " << needing << " in order to " << activity;
	cout << "... I mixed you this study playlist." << endl;
	cout << "You can find your \"" << vibe << "\" playlist in the current folder. \n" << endl; 
	
	library.recommendPlaylist(vibe);
	cout << "\nDo you want to check em out by copying the URI into the spotify search? (y)yes or (n)no." << endl;
	cin >> goToUrl;
	if ( goToUrl == "y" ) {
		system("xdg-open https://play.spotify.com/browse");
	}
}
	
