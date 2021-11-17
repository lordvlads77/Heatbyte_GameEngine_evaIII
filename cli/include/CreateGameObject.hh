#include<fstream>
#include<iostream>
#include<string>

void CreateGameObject(std::string assetName)
{
  std::string replaceWord{"TemplateName"};

  std::ifstream* reader{new std::ifstream()};
  std::ofstream* writer{new std::ofstream()};

  reader->open("cli/templates/GameObjectHH.template");
  writer->open("include/" + assetName + ".hh");

  std::string currentLine{};

  while(std::getline(*reader, currentLine))
  {
    size_t pos{currentLine.find(replaceWord)};

    if(pos != std::string::npos)
    {
      currentLine.replace(pos, replaceWord.length(), assetName);
    }
    *writer << currentLine << '\n';
  }

  reader->close();
  writer->close();

  delete reader;
  delete writer;
}

