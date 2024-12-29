// Photo.h

#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"

class Photo : public Multimedia {
private:
    double latitude;
    double longitude;

public:
    Photo(const std::string& name = "", const std::string& fileName = "",
        double latitude = 0.0, double longitude = 0.0)
        : Multimedia(name, fileName) {
            this->latitude = latitude; 
            this->longitude = longitude;
        }

    // Getters
    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }

    // Setters
    void setLatitude(double lat) { latitude = lat; }
    void setLongitude(double lon) { longitude = lon; }

    // Overridden display method
    void display(std::ostream& os) const override {
        Multimedia::display(os);
        os << "Latitude: " << latitude << "\nLongitude: " << longitude << "\n";
        std::cout << std::endl; 
    }

    // Method to play the image
    void play() const override {
        std::string command = "imagej " + getFileName() + " &";
        system(command.data());
    }
};

#endif
