#include <SFML/Window.hpp>
#include "config.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  cout << "Version " << myproject_VERSION_MAJOR << "." << myproject_VERSION_MINOR << endl;

  sf::Window screen(sf::VideoMode(800, 600), "myproject");
  bool running = true;
  while (running) {
    screen.Display();
  }
}