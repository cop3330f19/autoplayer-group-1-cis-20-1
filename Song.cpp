/*
Group 1: Mario Brown, Chris Williams, Rhiana Long, Elijah Devilme
Song.cpp
*/
#include "Song.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


     Song::Song()
     {
         title="";
         artist="";
         album="";
         length=0;
         year=0;
     }

     Song::Song(string title, string artist, string album, int year, int length)
     {
       this->title=title;
       this->artist=artist;
       this->album=album;
       this->year=year;
       this->length=length;

     }

     void Song::set(string title, string artist, string album, int year, int length)
     {
       this->title=title;
       this->artist=artist;
       this->album=album;
       this->length=length;
       this->year=year;
     }


		ostream& operator<<(ostream& os, const Song& song)     
        {
            int p1=song.length/60;
            int p2=(song.length%60);
            os <<song.title <<endl;
            os <<song.artist <<endl;
            os <<song.album <<"(" << p1 <<":"<< p2 <<")" << endl;
            os <<song.year;
            return os;
        }

	
		ofstream& operator<<(ofstream& os, const Song& song)
        {
            int p1=song.length/60;
            int p2=(song.length%60);
            
            os <<song.title << ',';
            os <<song.artist << ',';
            os <<song.album << ',';
            os <<song.year << ',';
            os <<song.length;
         
            
            return os;
        }

	
		istream& operator>>(istream& is, Song& song)
        {
            cout << "Title: ";
            is >> song.title;
            cout << "Artist: ";
            is >>song.artist;
            cout << "Album: ";
            is >> song.album;
            cout << "Year: ";
            is >> song.year;
            cout << "Length (in seconds): ";
            is >> song.length;
            return is;
        }

		fstream& operator>>(fstream& is, Song& song)
        {
            string y, l; 
            
            getline(is ,song.title,',');
            getline(is ,song.artist,',');
            getline(is ,song.album,',');
            getline(is ,l,',');
            getline(is ,y);
            
            return is;
        }

		bool operator==(const Song& lhs, const Song& rhs)
        {
            bool c=false;
            
            if ((lhs.title==rhs.title) && (lhs.artist==rhs.artist) 
                && (lhs.album==rhs.album) && (lhs.length==rhs.length) && (lhs.year==rhs.year))
            {
                c=true;
            }
            return c;
        }
