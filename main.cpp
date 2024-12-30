// main.cpp

#include "MediaManager.h"

int main() {
    MediaManager manager;

    // Creating multimedia objects
    auto photo1 = manager.createPhoto("Beach Vacation", "beach_vacation.jpg", 200.00, 500.00);
    auto video1 = manager.createVideo("Nature Documentary", "nature_doc.mp4", 25);
    int chapters[] = {120, 55, 105, 40};
    auto film1 = manager.createFilm("The Lord of the Rings", "lotr.mkv", 320, chapters, 4);

    // Creating groups
    auto photoGroup = manager.createGroup("Photos");
    auto vacationGroup = manager.createGroup("Vacations");

    // Adding objects to groups
    photoGroup->push_back(photo1);
    vacationGroup->push_back(photo1);
    vacationGroup->push_back(video1);
    vacationGroup->push_back(film1);

    // Displaying groups
    manager.displayGroup("Photos");
    manager.displayGroup("Vacations");

    // Playing multimedia
    // manager.playMultimedia("Nature Documentary");

    // Deleting a multimedia object
    manager.deleteMultimedia("Beach Vacation");

    // Deleting a group
    manager.deleteGroup("Photos");

    return 0;
}
