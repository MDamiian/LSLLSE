#include "list.hpp"
#include "menu.hpp"
#include "song.hpp"

int main() {
  Menu myMenu;
  List<Song> myList;

  myMenu.mainMenu(myList);
  return 0;
  }
