#include<iostream>
#include "CreateGameObject.hh"
#include "CreateGameObjectCC.hh"

int main(int argc, char** argv)
{
  std::string action{argv[1]};

  switch (argc)
  {
  case 3:
    if(action == "Create")
    {
      CreateGameObject(argv[2]);
      CreateGameObjectCC(argv[2]);
    }
    break;
  default:
    break;
  }

  return 0;
}

