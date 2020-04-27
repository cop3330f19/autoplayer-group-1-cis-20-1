/*
Group 1: Mario Brown, Chris Williams, Rhiana Long, Elijah Devilme
Playlist.cpp
*/
  #include <iostream>
	#include <iomanip>
	#include <vector>
	#include <fstream>
  #include <string>
	#include "Playlist.h"
	#include "Song.h"
	#include "StringHelper.h"
	
  using namespace std;
	
	char Playlist::mode = 'N'; 
	
	
	void Playlist::addSong(Song &s)
	{
        songs.push_back(s); 
	}
	

	void Playlist::deleteSong(Song &s)
	{
        bool song=false;
	
        for (int i = 0; i < songs.size(); i++)
         {
            if (songs[i] == s)
              {
                song=true;
                songs.erase(songs.begin() + i);
              }
         }
	}

	vector<Song> Playlist::getplaylistsongs()
	{
        return songs;
	}

	
	Playlist Playlist::intersect(Playlist &p)
	{
        Playlist result;
        bool valid=false;
        vector<Song> temp = p.getplaylistsongs();

        for (int i = 0; i < songs.size(); i++) 
        { 
            for (int j = 0; j < temp.size(); j++)
                {
                    if (songs[i] == temp[j] && linearsearch(result.getplaylistsongs(), songs[i]))
                    valid = true;
                    result.addSong(songs[i]);
                }
        }
        return result;
	}

	void Playlist::play() 
	{
        if (mode == 'N')
        {
            currentsong++;
            if (currentsong < songs.size())
                cout << "Now Playing: " <<songs[currentsong] << endl;
            else
                cout << "No more songs in playlist" << endl;
        }
        
        else if (mode == 'R')
        {
            cout << songs[currentsong] << endl;
        }
        
        else if (mode == 'L')
        {
            currentsong++;
            if (currentsong > songs.size())
            currentsong = 0;
            cout << "Now Playing: "  <<songs[currentsong] << endl;
        }
	}
	

	void Playlist::mode(char mode)
	{
        Playlist::mode = mode;
	}
	
	bool Playlist::linearsearch(vector<Song> b, Song &g)
	{
        bool valid;

        valid = false;
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i] == g)
            valid = true;
        }
        return valid;
	}


  Playlist operator+(Playlist &p1, Song &s1)
	{
        Playlist p;
        p = p1;
        p.addSong(s1);
        return Playlist(p);
	}
	

	Playlist operator+(Playlist &p, Playlist &p1)
	{
        Playlist add;
        add = p;
        bool valid;
        vector<Song> temp = p1.getplaylistsongs();

        valid = false;

        for (int i = 0; i < temp.size(); i++)
        {
            valid = true;
            add.addSong(temp[i]);
        }
        return Playlist(add);
	}
	
 
	Playlist operator-(Playlist &p1, Song &s1)
	{
        Playlist p;
        p = p1;
        p.deleteSong(s1);
        return p;
	}
	

	ostream &operator<<(ostream &o, const Playlist &p)
	{
        for (int i = 0; i < p1.songs.size(); i++)
        {
            o << p.songs[i];
        }
        return os;
	}

	
	void Playlist::setPlaylistName(string pname)
	{
        Pname = pname;
	}

 
	string Playlist::getPlaylistName()
	{
        return Pname;
	}
	
	//Constructors
	Playlist::Playlist()
	{
        Pname = "";
	}
	Playlist::Playlist(string name)
	{
        setPlaylistName(name);
        string play_listname = name + ".playlist";
        play_listname = StringHelper::stou(play_listname);

        fstream infile;
        infile.open(play_listname.c_str(), ios::in);
        Song s;
        int k = 0;
        
        while (in >> s)
        {
            songs.push_back(s);
        }
        in.close();
	}
