#ifndef __MOVIES_H__
#define __MOVIES_H__
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Movie.hpp"

class Movies {
    private:
        static Movies* instance;
        std::vector<Movie*>* movies;
        std::vector<Movie*>* temp_movies;
        Movies();
        void display_movie(Movie* movie);
        void display_movies_from_search();
        bool compute_search(std::string& search_string);
        //enum search_type {type_name, type_genre, type_rating, type_watched_count};
    public:
        ~Movies();
        static Movies* get_movies_instance();

        void display_all_movies();
        void search_movie(std::string& movie_name);

        bool add_movie(const std::string& name,const std::string& genre, const unsigned int& rating,const unsigned int& watched_count);
        bool add_movie(std::string& name, std::string& genre, unsigned int& rating);
        bool add_movie(std::string& name, std::string& genre);

        std::vector<Movie*>* get_movies();
        

        bool update_rating(std::string& movie_name, unsigned int count);
        bool update_watched(std::string& movie_name, unsigned int count);

        bool delete_movie(std::string& movie_name);
};

#endif