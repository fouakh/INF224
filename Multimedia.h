// Multimedia.h

#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>

class Multimedia {
private:
    std::string name;
    std::string fileName;

public:
    // Default constructor
    Multimedia();

    // Constructor with parameters
    Multimedia(const std::string& name, const std::string& fileName);

    // Destructor
    virtual ~Multimedia();

    // Getter for name
    std::string getName() const;

    // Setter for name
    void setName(const std::string& name);

    // Getter for filename
    std::string getFileName() const;

    // Setter for filename
    void setFileName(const std::string& fileName);

    // Display method
    virtual void display(std::ostream& os) const;

    // Play method
    virtual void play() const = 0;
};

#endif // MULTIMEDIA_H
