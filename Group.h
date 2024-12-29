// Group.h

#include "Multimedia.h"

#include <string>
#include <list>
#include <memory> 

// Define a type alias for a shared pointer to Multimedia
using MultimediaPtr = std::shared_ptr<Multimedia>;

class Group : public std::list<MultimediaPtr> {
private:
    std::string groupName;

public:
    // Constructor
    Group(const std::string& groupName) : groupName(groupName) {
}

    // Accessor for the group's name
    const std::string& getName() const {
        return groupName;
    }

    // Method to display all items in the group
    void display(std::ostream& os) const {
        std::cout << "Group: " << groupName << std::endl;
        for (const auto& multimedia : *this) {
            multimedia->display(os);
        }
    }
};

