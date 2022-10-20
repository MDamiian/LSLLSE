#include <string>
#include <iostream>
#include "menu.hpp"
#include "list.hpp"
#include "name.hpp"
#include "song.hpp"

using namespace std;

void Menu::mainMenu(List<Song>& myList) {
  string myString;
  int myInt;
  char myOption;
  Name myName;
  Song mySong;

  List<Song>::Position pos;

  do {
    system("cls");

    if(myList.isEmpty()) {
      cout << "La lista esta vacia\n";
      }
    cout << myList.toString();
    cout << "***Menu de opciones***" << endl << endl
         << "a)Insertar cancion" << endl
         << "b)Eliminar cancion" << endl
         << "c)Buscar cancion" << endl
         << "d)Recuperar cancion" << endl
         << "e)Anular lista" << endl
         << "f)Mas opciones" << endl
         << "g)Salir" << endl
         << "Seleccione una opcion: ";

    cin >> myOption;
    cin.ignore();

    switch(myOption) {
      case 'a':
        cout << "\nIntroduce los siguientes datos de la cancion a agregar\n";

        cout << "Cancion: ";
        getline(cin, myString);
        mySong.setNameSong(myString);

        cout << "Autor\n";
        cout << "Nombre: ";
        getline(cin, myString);
        myName.setFirst(myString);
        cout << "Apellido: ";
        getline(cin, myString);
        myName.setLast(myString);
        mySong.setNameAuthor(myName);

        cout << "Cantante\n";
        cout << "Nombre: ";
        getline(cin, myString);
        myName.setFirst(myString);
        cout << "Apellido: ";
        getline(cin, myString);
        myName.setLast(myString);
        mySong.setNameSinger(myName);

        cout << "Ranking: ";
        cin >> myInt;
        mySong.setRanking(myInt);
        cin.ignore();

        cout << "Nombre del archivo: ";
        getline(cin, myString);
        mySong.setNameMp3(myString);

        myList.insertData(myList.getLastPos(), mySong);

        break;

      case 'b':
        cout << "Introduce la cancion a eliminar: ";
        getline(cin, myString);
        mySong.setNameSong(myString);
        myList.deleteData(myList.findData(Song::compareBySong, mySong));
        break;

      case 'c':
        cout << "\n**Busqueda lineal**" << endl
             << "1)Buscar por nombre de la cancion" << endl
             << "2)Buscar por nombre del cantante" << endl
             << "3)Salir" << endl
             << "Selecciona una opcion: ";
        cin >> myOption;
        cin.ignore();

        switch(myOption) {
          case '1':
            cout << "\nIntroduce el nombre de la cancion: ";
            getline(cin, myString);
            mySong.setNameSong(myString);
            pos = myList.findData(Song::compareBySong, mySong);

            cout << "La cancion " << myString << " ";

            if(pos == nullptr) {
              cout << "NO SE ENCUENTRA EN LA LISTA" << endl;
              }

            else {
              cout << "se encuentra en la posicion " << pos << " de la lista" << endl;
              cout << endl;
              cout << "Registro encontrado: " << endl;
              cout << myList.retrieve(pos).toString() << endl;
              }
            break;

          case '2':
            cout << "\nIntroduce los datos del cantante" << endl;
            cout << "Nombre: ";
            getline(cin, myString);
            myName.setFirst(myString);
            cout << "Apellido: ";
            getline(cin, myString);
            myName.setLast(myString);
            mySong.setNameSinger(myName);

            pos = myList.findData(Song::compareBySinger, mySong);

            cout << "El cantante " << mySong.getNameSinger().toString() << " ";

            if(pos == nullptr) {
              cout << "NO SE ENCUENTRA EN LA LISTA" << endl;
              }

            else {
              cout << "se encuentra en la posicion " << pos << " de la lista" << endl;
              cout << endl;
              cout << "Registro encontrado: " << endl;
              cout << myList.retrieve(pos).toString() << endl << endl;
              }
            break;

          case '3':
            break;
          }
        system("pause");
        break;

      case 'd':
        cout << "Introduce el nombre de la cancion: ";
        getline(cin, myString);
        mySong.setNameSong(myString);
        pos = myList.findData(Song::compareBySong, mySong);
        cout << myList.retrieve(pos).toString();
        cout << endl;
        system("pause");
        break;

      case 'e':
        myList.deleteAll();
        break;

      case 'f':
        system("cls");
        cout << "1)Vacia" << endl
             << "2)Primera posicion" << endl
             << "3)Ultima posicion" << endl
             << "4)Anterior posicion" << endl
             << "5)Siguiente posicion" << endl
             << "6)Salir" << endl
             << "Selecciona una opcion: ";
        cin >> myOption;
        cin.ignore();

        switch(myOption) {
          case '1':
            if(myList.isEmpty() == 1) {
              cout << "La lista esta vacia"
                   << endl << endl;
              }

            else {
              cout << "La lista no esta vacia"
                   << endl << endl;
              }
            system("pause");
            break;

          case '2':
            cout << "\nPrimera posicion:" << endl
                 << myList.retrieve(myList.getFirstPos()).toString()
                 << endl;
            system("pause");
            break;

          case '3':
            cout << "\nUltima posicion:" << endl
                 << myList.retrieve(myList.getLastPos()).toString()
                 << endl;
            system("pause");
            break;

          case '4':
            cout << "\nIntroduce el nombre de una cancion: ";
            getline(cin, myString);
            mySong.setNameSong(myString);
            pos = myList.findData(Song::compareBySong, mySong);
            cout << "La posicion anterior es:" << endl
                 << myList.retrieve(myList.getPrevPos(pos)).toString()
                 << endl;
            system("pause");
            break;

          case '5':
            cout << "\nIntroduce el nombre de una cancion: ";
            getline(cin, myString);
            mySong.setNameSong(myString);
            pos = myList.findData(Song::compareBySong, mySong);
            cout << "La posicion siguiente es:" << endl
                 << myList.retrieve(myList.getNextPos(pos)).toString()
                 << endl;
            system("pause");
            break;

          case '6':
            break;
        }
        break;

      case 'g':
        break;
      }
    }
  while(myOption != 'g');
  }
