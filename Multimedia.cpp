// Multimedia.cpp

#include "Multimedia.h"

Multimedia::Multimedia() : name(""), fileName("") {}

Multimedia::Multimedia(const std::string& name, const std::string& fileName)
    : name(name), fileName(fileName) {}

Multimedia::~Multimedia() {}

std::string Multimedia::getName() const {
    return name;
}

void Multimedia::setName(const std::string& name) {
    this->name = name;
}

std::string Multimedia::getFileName() const {
    return fileName;
}

void Multimedia::setFileName(const std::string& fileName) {
    this->fileName = fileName;
}

void Multimedia::display(std::ostream& os) const {
    os << "Name: " << name << "\nFile Name: " << fileName << std::endl;
}
