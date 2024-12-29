#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

#include <iostream>
#include <memory> 

using MultimediaPtr = std::shared_ptr<Multimedia>;

int main() {
    // Creating multimedia objects using std::shared_ptr for automatic memory management
    MultimediaPtr photo1 = std::make_shared<Photo>("Beach Vacation", "beach_vacation.jpg", 200.00, 500.00);
    MultimediaPtr photo2 = std::make_shared<Photo>("Winter Mountain", "winter_mountain.jpg", 150.00, 400.00);
    MultimediaPtr video1 = std::make_shared<Video>("Nature Documentary", "nature_doc.mp4", 25);

    int chaptersFilm1[] = {120, 55, 105, 40};
    MultimediaPtr film1 = std::make_shared<Film>("The Lord of the Rings", "lotr.mkv", 320, chaptersFilm1, 4);

    // Creating groups to hold multimedia objects, using std::shared_ptr for automatic memory management
    Group photoGroup("Photos");
    Group videoGroup("Videos");
    Group vacationGroup("Vacations");

    // Adding multimedia objects to the groups
    photoGroup.push_back(photo1);
    photoGroup.push_back(photo2);
    videoGroup.push_back(video1);
    vacationGroup.push_back(photo1);
    vacationGroup.push_back(photo2);
    vacationGroup.push_back(video1);
    vacationGroup.push_back(film1);

    // Displaying the groups
    std::cout << "Displaying 'Photos' group:" << std::endl;
    photoGroup.display(std::cout);

    std::cout << "\nDisplaying 'Videos' group:" << std::endl;
    videoGroup.display(std::cout);

    std::cout << "\nDisplaying 'Vacations' group:" << std::endl;
    vacationGroup.display(std::cout);

    return 0;
}
