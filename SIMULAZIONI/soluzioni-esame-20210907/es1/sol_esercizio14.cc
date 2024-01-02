#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

// Lunghezza massima delle stringhe
const int MAX_LUNGHEZZA=101;

int main(int argc, char * argv [])
{

  // Controllo se il numero degli argomenti è corretto
  if (argc != 3)
  {
    cout << "Usage: esercizio1 <input_file> <output_file>" << endl;
    exit(1);
  }

  // Creo i miei stream
  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  // Controllo se riesco ad aprire il file di input
  if (input.fail() || output.fail())
  {
    cout << "Non sono riuscito ad aprire uno dei file "
         << argv[1]  << " " << argv[2] << endl;
    input.close();
    output.close();
    exit(1);
  }

  char buffer[MAX_LUNGHEZZA];

  // Controllo la prima parola
  input >> buffer;
  if (!(buffer[0] >= 'A' && buffer[0] <= 'Z'))
  {
    buffer[0] += 'A'-'a';
  }

  // Leggo il resto del file
  while(!input.eof())
  {

    output << buffer << " ";

    if (!(buffer[strlen(buffer)-1] == ',' || buffer[strlen(buffer)-1] == ';' || buffer[strlen(buffer)-1] == ':'))
    {
      input >> buffer;
      if (!(buffer[0] >= 'A' && buffer[0] <= 'Z'))
      {
        buffer[0] += 'A'-'a';
      }
    } else {
      input >> buffer;
    }
  }

  output << endl;

  // Chiudo gli stream
  input.close();
  output.close();

  return 0;
}
