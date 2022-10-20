#include <iostream>
#include <stdlib.h>
#include "song.hpp"

using namespace std;

Song::Song() : author(), singer(), song(""), nameMp3(""), ranking(0) { }

string Song::getNameSong() const {
  return song;
  }

string Song::getNameMp3() const {
  return nameMp3;
  }

Name Song::getNameAuthor() const {
  return author;
  }

Name Song::getNameSinger() const {
  return singer;
  }

int Song::getRanking() const {
  return ranking;
  }

string Song::toString() const {
  string result;
  result+= "Song: ";
  result+= song;
  result.resize(28, ' ');
  result+= "| ";
  result+= nameMp3;
  result.resize(52, ' ');
  result+= "| Author: ";
  result+= author.toString();
  result.resize(86, ' ');
  result+= "| Singer: ";
  result+= singer.toString();
  result.resize(117, ' ');
  result+= "| Ranking: ";
  result+= to_string(ranking);

  return result;
  }

void Song::setNameSong(const string& ns) {
  song = ns;
  }

void Song::setNameMp3(const string& nm) {
  nameMp3 = nm;
  }

void Song::setNameAuthor(const Name& na) {
  author = na;
  }

void Song::setNameSinger(const Name& ns) {
  singer = ns;
  }

void Song::setRanking(const int& r) {
  ranking = r;
  }

bool Song::operator == (const Song& s) const {
  return song == s.song;
  }

bool Song::operator != (const Song& s) const {
  return !(*this == s);
  }

bool Song::operator > (const Song& s) const {
  return !(*this <= s);
  }

bool Song::operator >= (const Song& s) const {
  return !(*this < s);
  }

bool Song::operator < (const Song& s) const {
  return song < s.song;
  }

bool Song::operator <= (const Song& s) const {
  return *this < s or *this == s;
  }

int Song::compareByAuthor(const Song& a, const Song& b) {
  return a.author.toString().compare(b.author.toString());
  }

int Song::compareBySinger(const Song& a, const Song& b) {
  return a.singer.toString().compare(b.singer.toString());
  }

int Song::compareBySong(const Song& a, const Song& b) {
  return a.song.compare(b.song);
  }

int Song::compareByRanking(const Song& a, const Song& b) {
  return to_string(a.ranking).compare(to_string(b.ranking));
  }
