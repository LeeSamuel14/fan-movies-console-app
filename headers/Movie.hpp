#ifndef __MOVIE_H__
#define __MOVIE_H__

#include <string>
#include <iostream>

class Movie{
    private:
        std::string name;
        std::string genre;
        unsigned int rating;
        unsigned int watched_count;
    public:
        Movie(std::string n, std::string g = "none", unsigned int r = 0, unsigned w = 0);
        //Movie(const Movie& source);
        //Movie(Movie&& source);
        //~Movie();
        std::string get_name();
        std::string get_genre();
        unsigned int get_rating();
        unsigned int get_watched_count();
        bool set_rating(unsigned int r);
        bool set_watched_count(unsigned int w);
};

#endif