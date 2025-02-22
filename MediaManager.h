#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H

#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

#include <map>
#include <memory>
#include <iostream>

class MediaManager {
private:
    using MultimediaPtr = std::shared_ptr<Multimedia>;
    using PhotoPtr = std::shared_ptr<Photo>; 
    using VideoPtr = std::shared_ptr<Video>;
    using FilmPtr = std::shared_ptr<Film>;

    using GroupPtr = std::shared_ptr<Group>;

    // Tables associatives pour les objets multimédias et les groupes
    std::map<std::string, MultimediaPtr> multimediaTable;
    std::map<std::string, GroupPtr> groupTable;

public:
    // Method to create and add a Photo
    PhotoPtr createPhoto(const std::string& name, const std::string& fileName, 
                            double latitude, double longitude) {
        auto photo = std::make_shared<Photo>(name, fileName, latitude, longitude);
        multimediaTable[name] = photo;
        return photo;
    }

    // Method to create and add a Video
    VideoPtr createVideo(const std::string& name, const std::string& fileName, int duration) {
        auto video = std::make_shared<Video>(name, fileName, duration);
        multimediaTable[name] = video;
        return video;
    }

    // Method to create and add a Film
    FilmPtr createFilm(const std::string& name, const std::string& fileName, int duration, 
                            int* chapters, size_t numChapters) {
        auto film = std::make_shared<Film>(name, fileName, duration, chapters, numChapters);
        multimediaTable[name] = film;
        return film;
    }

    // Method to create and add a Group
    GroupPtr createGroup(const std::string& groupName) {
        auto group = std::make_shared<Group>(groupName);
        groupTable[groupName] = group;
        return group;
    }

    // Method to find and display a Multimedia object by name
    std::string displayMultimedia(const std::string& name) const {
        auto it = multimediaTable.find(name);
        if (it != multimediaTable.end()) {
            std::stringstream ss;
            it->second->display(ss);
            return ss.str();
        }
        return "Error: Multimedia object '" + name + "' not found.";
    }

    // Method to find and display a Group by name
    std::string displayGroup(const std::string& groupName) const {
        auto it = groupTable.find(groupName);
        if (it != groupTable.end()) {
            std::stringstream ss;
            it->second->display(ss);
            return ss.str();
        } 
        return "Group '" + groupName + "' not found.";
        
    }

    // Method to play a Multimedia object by name
    std::string playMultimedia(const std::string& name) const {
        auto it = multimediaTable.find(name);
        if (it != multimediaTable.end()) {
            it->second->play();
            return "Playing: " + name;
        }
        return "Error: Multimedia object '" + name + "' not found.";
    }

    // Method to delete a Multimedia object by name
    void deleteMultimedia(const std::string& name) {
        auto it = multimediaTable.find(name);
        if (it != multimediaTable.end()) {
            auto multimedia = it->second;

            // Remove multimedia from all groups
            for (auto groupIt = groupTable.begin(); groupIt != groupTable.end(); ++groupIt) {
                groupIt->second->remove(multimedia);
            }

            // Erase from multimedia table
            multimediaTable.erase(it);
            std::cout << "Multimedia object '" << name << "' deleted.\n";
        } else {
            std::cout << "Multimedia object '" << name << "' not found.\n";
        }
    }

    // Method to delete a Group by name
    void deleteGroup(const std::string& groupName) {
        auto it = groupTable.find(groupName);
        if (it != groupTable.end()) {
            groupTable.erase(it);
            std::cout << "Group '" << groupName << "' deleted.\n";
        } else {
            std::cout << "Group '" << groupName << "' not found.\n";
        }
    }
};

#endif // MEDIAMANAGER_H
