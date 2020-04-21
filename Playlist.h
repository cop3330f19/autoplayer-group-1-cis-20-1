/*
Playlist.cpp

*/

#ifndef PLAYLIST_H
#define PLAYLIST_
#include <cstdlib>
#include <string>
#include "Song.h"
#include <iostream>
#include <vector>
	
class Playlist
{
private:
static char mode;
int currentsong;
std::string Pname;
std::vector<Song> songs;
		
public:
static void mode(char);
void addSong(Song &);
void deleteSong(Song &);
void play();
void setPlaylistName(std::string);

std::vector<Song> getplaylistsongs();
std::string getPlaylistName();

Playlist();
Playlist(std::string);
Playlist intersect(Playlist &);

friend Playlist operator+(Playlist &, Song &);
friend Playlist operator+(Playlist &, Playlist &);
friend Playlist operator-(Playlist &, Song &);
friend std::ostream &operator<<(std::ostream &, const Playlist &);

bool linearsearch(std::vector<Song>, Song &);
};
#endif
