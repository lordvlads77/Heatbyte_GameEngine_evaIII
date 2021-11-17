#include<fstream>
#include<iostream>
#include<string>

void CreateGameObjectCC(std::string assetNamecc)
{
  std::string replaceWord{"TemplateName"};
  

  std::ifstream* reader{new std::ifstream()};
  std::ofstream* writer{new std::ofstream()};

  reader->open("cli/templates/GameObjectCC.template");
  writer->open("src/" + assetNamecc + ".cc");

  std::string currentLine{};

  while(std::getline(*reader, currentLine))
  {
    size_t pos{currentLine.find(replaceWord)};

    if(pos != std::string::npos)
    {
      currentLine.replace(pos, replaceWord.length(), assetNamecc);
    }
    *writer << currentLine << '\n';
  }


  reader->close();
  writer->close();

  delete reader;
  delete writer;

}
