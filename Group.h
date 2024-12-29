
#include "Multimedia.h"

#include <string>
#include <list>

class Group : public std::list<Multimedia*> {
private:
    std::string groupName;
    
public:
    Group(const std::string& name) : groupName(name) {}

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
