#ifndef SONG_HPP_INCLUDED
#define SONG_HPP_INCLUDED

#include <string>
#include <iostream>

#include "name.hpp"

class Song {

  private:
    Name author;
    Name singer;
    std::string song;
    std::string nameMp3;
    int ranking;

  public:
    Song();

    std::string getNameSong() const;
    std::string getNameMp3() const;
    Name getNameAuthor() const;
    Name getNameSinger() const;
    int getRanking() const;

    std::string toString() const;

    void setNameSong(const std::string&);
    void setNameMp3(const std::string&);
    void setNameAuthor(const Name&);
    void setNameSinger(const Name&);
    void setRanking(const int&);

    bool operator == (const Song&) const;
    bool operator != (const Song&) const;
    bool operator > (const Song&) const;
    bool operator >= (const Song&) const;
    bool operator < (const Song&) const;
    bool operator <= (const Song&) const;

    static int compareByAuthor(const Song&, const Song&);
    static int compareBySinger(const Song&, const Song&);
    static int compareBySong(const Song&, const Song&);
    static int compareByRanking(const Song&, const Song&);
  };

#endif // SONG_HPP_INCLUDED
