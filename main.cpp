// main.cpp

#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

#include <iostream>

int main() {
    // Création d'objets multimédia
    Multimedia* photo1 = new Photo("Beach Vacation", "beach_vacation.jpg", 200.00, 500.00);
    Multimedia* photo2 = new Photo("Winter Mountain", "winter_mountain.jpg", 150.00, 400.00);
    Multimedia* video1 = new Video("Nature Documentary", "nature_doc.mp4", 25);

    int chaptersFilm1[] = {120, 55, 105, 40} ;
    Multimedia* film1 = new Film("The Lord of the Rings", "lotr.mkv", 320, chaptersFilm1, 4);

    // Création des groupes
    Group* photoGroup = new Group("Photos");
    Group* videoGroup = new Group("Videos");
    Group* vacationGroup = new Group("Vacations");

    // Ajout d'objets dans les groupes
    photoGroup->push_back(photo1);
    photoGroup->push_back(photo2);
    videoGroup->push_back(video1);
    vacationGroup->push_back(photo1);
    vacationGroup->push_back(photo2);
    vacationGroup->push_back(video1);
    vacationGroup->push_back(film1);

    // Affichage des groupes
    std::cout << "Displaying 'Photos' group:" << std::endl;
    photoGroup->display(std::cout);

    std::cout << "\nDisplaying 'Videos' group:" << std::endl;
    videoGroup->display(std::cout);

    std::cout << "\nDisplaying 'Vacations' group:" << std::endl;
    vacationGroup->display(std::cout);

    delete photoGroup; // Détruit uniquement le groupe, pas les objets

    // Vérification que les objets existent encore
    std::cout << "\nAfter deleting 'Photos' group, checking individual elements:" << std::endl;
    std::cout << "Displaying photo1:" << std::endl;
    photo1->display(std::cout);

    std::cout << "Displaying photo2:" << std::endl;
    photo2->display(std::cout);

    // Libération de la mémoire
    delete photo1;
    delete photo2;
    delete video1;
    delete film1;

    return 0;
}



