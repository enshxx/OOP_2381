#include "Input.h"
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <termios.h>
#include <set>
#include <vector>

char Input::_read(){
    char sym;
    initscr();
    timeout(0);
    sym = _getch();
    endwin();
    return sym;
}

char Input::_getch(){
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}
std::map<std::string, char> Input::read_dictionary(const std::string& filename){
  std::map<std::string, char> dictionary;
  std::ifstream input_file(filename);

  for (std::string line; getline(input_file, line);) {
    size_t space_pos = line.find(" ");
    if (space_pos == std::string::npos) {
      std::cout << "Неправильно сформированная строка: " << line << std::endl;
      return {};
    }
    std::string key = line.substr(0, space_pos);
    char value = line.substr(space_pos + 1)[0];
    value = tolower(value);

    dictionary[key] = value;
  }
  std::vector<char> values;
  for (auto entry : dictionary) {
    values.push_back(entry.second);
  }
  for (auto entry : dictionary) {
    if (count(cbegin(values),cend(values),entry.second) > 1) {
      std::cout << "Значение " << entry.second << " не уникально" << std::endl;
      return {};
    }
  }

  return dictionary;
}