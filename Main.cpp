#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "List.hpp"
#include <string.h>
#include <climits>
#include <time.h>
#include <fstream>

using namespace std;

int getSeed()
{
  int rnd = 0;
  size_t size = sizeof(rnd);
  ifstream urandom("/dev/urandom", ios::in|ios::binary);
  if (urandom)
  {
    urandom.read(reinterpret_cast<char *>(&rnd), size);
    if (!urandom)
    {
      cerr << "Lecture de urandom échouée (" << errno << "): " << strerror(errno) << endl;
      exit(EXIT_FAILURE);
    }
    urandom.close();
  }
  else
  {
    cerr << "Ouverture de urandom échouée (" << errno << "): " << strerror(errno) << endl;
    exit(EXIT_FAILURE);
  }

  return rnd;
}

/**
 * Usage
 */
void usage(char* argv[])
{
  cerr << "Usage: " << argv[0] << " <lng>" << endl
       << "    lng est un nombre entier > 1 et < " << UINT64_MAX << endl;
  exit(EXIT_FAILURE);
}

/**
 * trySort: Tente de trier de manière aléatoire la liste donnée en paramètre.
 */
List *trySort(List *l)
{
  List *l2 = new List();

  while (l->Count() > 0)
  {
    unsigned long random = rand() % l->Count();
    ListItem *li = l->Get(random);
    if (li == nullptr)
    {
      throw invalid_argument("Impossible de charger l'item");
    }
    unsigned long value = li->Value();
    l2->Add(new ListItem(value));
    l->Remove(random);
  }

  return l2;
}

/**
 * Point d'entrée principal.
 */
int main(int argc, char *argv[])
{
  // Initialisation des nombres aléatoires.
  srand(getSeed());

  // A besoin d'un paramètre exactement.
  if (argc != 2)
  {
    usage(argv);
  }

  // Vérification du paramètre
  for (size_t i = 0; i < strlen(argv[1]); ++i)
  {
    char data = argv[1][i];
    // Vérifie que tout les carachères sont des nombres
    if (data < 48 || data > 57) 
    {
      usage(argv);
    }
  }

  unsigned long max;
  
  // Vérifie que le nombre n'est pas trop grand
  try
  {
    max = stoul(argv[1]);
  }
  catch(const std::exception& e)
  {
    usage(argv);
  }
   
  cout << "Max: " << max << endl;

  List *l = new List();

  // Création d'une liste ordonnée avec chaque entier de 0 à max - 1
  for (unsigned long i = 0; i < max; ++i)
  {
    l->Add(new ListItem(i));
  }
  
  cout << "Liste initiale (triée): ";
  l->Show();

  l = trySort(l);
  bool isSorted = l->IsSorted();

  unsigned long tried = 1;

  cout << "Liste randomisée: ";
  l->Show();

  while (isSorted == false)
  {
    l = trySort(l);
    tried++;
    cout << "Liste courante: ";
    l->Show();
    isSorted = l->IsSorted();
  }

  cout << "Triée en " << tried << " étapes" <<endl;

  return EXIT_SUCCESS;
}